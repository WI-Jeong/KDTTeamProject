// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Character/HeroCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Hero/Character/AnimInstance/HeroAnimInstance.h"
#include "Hero/Gun/Gun.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Components/ChildActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

//DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AHeroCharacter

AHeroCharacter::AHeroCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AHeroCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	SetWeaponData();

	if (WeaponDataTableRow)
	{
		SpawnGun(WeaponDataTableRow->Gun);
	}
}

void AHeroCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (IsRotateBodyToAim)
	{
		RotateBodyToAim(DeltaSeconds);
	}

	CloseUpAim(DeltaSeconds);
}

//////////////////////////////////////////////////////////////////////////
// Input

void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHeroCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AHeroCharacter::Look);

		// Crouch
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &AHeroCharacter::StartCrouch);
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AHeroCharacter::StopCrouch);

		// Run
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Started, this, &AHeroCharacter::StartRun);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &AHeroCharacter::StopRun);

		// Zoom
		EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Completed, this, &AHeroCharacter::ZoomInOut);

		// Aim
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Started, this, &AHeroCharacter::StartAim);
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &AHeroCharacter::StopAim);

		// Trigger
		EnhancedInputComponent->BindAction(TriggerAction, ETriggerEvent::Started, this, &AHeroCharacter::PullTrigger);
		EnhancedInputComponent->BindAction(TriggerAction, ETriggerEvent::Completed, this, &AHeroCharacter::ReleaseTrigger);

		// ChangeFireMode
		EnhancedInputComponent->BindAction(ChangeFireModeAction, ETriggerEvent::Completed, this, &AHeroCharacter::ChangeFireMode);

		// Reload
		EnhancedInputComponent->BindAction(ReloadModeAction, ETriggerEvent::Completed, this, &AHeroCharacter::PlayReloadingMontage);
	}
	else
	{
		//UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AHeroCharacter::PlayRecoilMontage()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	AnimInstance->Montage_Play(WeaponDataTableRow->RecoilMontage);
}

void AHeroCharacter::PlayReloadingMontage()
{
	if (IsZoomIn)
	{
		ZoomInOut();
	}

	IsReloading = true;

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	AnimInstance->Montage_Play(WeaponDataTableRow->ReloadingMontage);
}

void AHeroCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AHeroCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AHeroCharacter::StartCrouch()
{
	IsCrouch = true;
	GetCharacterMovement()->MaxWalkSpeed = CrouchSpeed;
}

void AHeroCharacter::StopCrouch()
{
	IsCrouch = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AHeroCharacter::StartRun()
{
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	//UE_LOG(LogTemp, Warning, TEXT("StartRun"));
}

void AHeroCharacter::StopRun()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	//UE_LOG(LogTemp, Warning, TEXT("StopRun"));
}

void AHeroCharacter::ZoomInOut()
{
	if (IsReloading) { return; }

	if (SpawnedGun == nullptr) { return; }

	if (CanJump() == false) { return; }

	AActor* ZoomCamera = SpawnedGun->GetChildActorComponent()->GetChildActor();
	if (ZoomCamera == nullptr) { return; }

	if (IsZoomIn)
	{
		IsZoomIn = false;

		FollowCamera->SetActive(true);

		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		PlayerController->SetViewTarget(MainCameraActor);

		GetCharacterMovement()->bOrientRotationToMovement = true;

		IsRotateBodyToAim = false;
	}
	else
	{
		IsZoomIn = true;

		FollowCamera->SetActive(false);

		if (ZoomCamera)
		{
			FollowCamera->SetActive(false);

			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
			MainCameraActor = PlayerController->GetViewTarget();
			PlayerController->SetViewTarget(ZoomCamera);

			GetCharacterMovement()->bOrientRotationToMovement = false;

			IsRotateBodyToAim = true;
		}
	}
}

void AHeroCharacter::StartAim()
{
	GetCharacterMovement()->bOrientRotationToMovement = false;

	IsRotateBodyToAim = true;
}

void AHeroCharacter::StopAim()
{
	//if (IsZoomIn) { return; }

	GetCharacterMovement()->bOrientRotationToMovement = true;

	IsRotateBodyToAim = false;
}

void AHeroCharacter::PullTrigger()
{
	//UE_LOG(LogTemp, Warning, TEXT("PullTrigger"));
	if (SpawnedGun == nullptr) { return; }

	SpawnedGun->PullTrigger();
}

void AHeroCharacter::ReleaseTrigger()
{
	//UE_LOG(LogTemp, Warning, TEXT("ReleaseTrigger"));
	if (SpawnedGun == nullptr) { return; }

	SpawnedGun->ReleaseTrigger();
}

void AHeroCharacter::ChangeFireMode()
{
	if (SpawnedGun == nullptr) { return; }

	SpawnedGun->ChangeFireMode();
}

void AHeroCharacter::SetWeaponData(FName InRowName)
{
	if (WeaponDataTableRowHandle.IsNull()) { return; }
	if (WeaponDataTableRowHandle.RowName == NAME_None) { return; }

	WeaponDataTableRowHandle.RowName = InRowName;
	WeaponDataTableRow = WeaponDataTableRowHandle.GetRow<FWeaponDataTableRow>(TEXT(""));
	if (WeaponDataTableRow)
	{
		GetMesh()->SetAnimClass(WeaponDataTableRow->AnimBP);
	}
}

void AHeroCharacter::SpawnGun(TSubclassOf<AGun> InGun)
{
	if(InGun == nullptr) { return; }

	// SpawnActor�� ���� weapon �����͸� ������� �� ���� ����
	SpawnedGun = GetWorld()->SpawnActor<AGun>(InGun);

	// ���� �̸��� ���� ���� �޽ÿ��� ������ ����
	const USkeletalMeshSocket* GunSocket = GetMesh()->GetSocketByName("GunSocket");

	if (SpawnedGun && GunSocket)
	{
		// ���Ͽ� ���͸� �Ҵ�
		GunSocket->AttachActor(SpawnedGun, GetMesh());
	}

	SpawnedGun->SetActorRelativeLocation(WeaponDataTableRow->GunLocation);

	SpawnedGun->SetActorRelativeRotation(WeaponDataTableRow->GunRotation);
}

void AHeroCharacter::RotateBodyToAim(float DeltaSeconds)
{
	FRotator ControlRotation = GetControlRotation();
	FRotator ActorRotation = GetActorRotation();
	FRotator NewRotation = FRotator(ActorRotation.Pitch, ControlRotation.Yaw, ActorRotation.Roll);

	if (IsZoomIn == false)
	{
		NewRotation = UKismetMathLibrary::RLerp(ActorRotation, NewRotation, DeltaSeconds * AimSpeed, true);
	}

	SetActorRotation(NewRotation);
}

void AHeroCharacter::Jump()
{
	Super::Jump();

	if (IsZoomIn)
	{
		ZoomInOut();
	}
}

void AHeroCharacter::CloseUpAim(float DeltaSeconds)
{
	if (IsRotateBodyToAim)
	{
		CameraBoom->TargetArmLength = FMath::Lerp(CameraBoom->TargetArmLength, TargetArmLengthAim, DeltaSeconds * CloseUpSpeed);
	}
	else
	{
		CameraBoom->TargetArmLength = FMath::Lerp(CameraBoom->TargetArmLength, TargetArmLengthDefault, DeltaSeconds * CloseUpSpeed);
	}
}

void AHeroCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetWeaponData();
}

