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
#include "Hero/Item/Item.h"
#include "Components/AudioComponent.h"
#include "Blueprint/UserWidget.h"

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

	static ConstructorHelpers::FClassFinder<UUserWidget> DiedUIClassFinder(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/JWI/UI/UI_Defeated.UI_Defeated_C'"));
	if (DiedUIClassFinder.Succeeded())
	{
		mDiedUIClass = DiedUIClassFinder.Class;
	}

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
}

void AHeroCharacter::Heal(float HealAmount)
{
	HP += HealAmount;

	if (HP > MaxHP)
	{
		HP = MaxHP;
	}
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

	HP = MaxHP;


	CurrentWidget = CreateWidget(GetWorld(), AmmoWidget);
	if (CurrentWidget)
	{
		CurrentWidget->AddToViewport();
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

	Timeline.TickTimeline(DeltaSeconds);
}



void AHeroCharacter::ShowDiedUI()
{
	if (IsValid(mDiedUIClass))
	{
		mDiedWidget = CreateWidget<UDiedWidget>(GetWorld(), mDiedUIClass);

		if (IsValid(mDiedWidget))
		{
			mDiedWidget->AddToViewport();

			ARPGPlayerController* RPGPlayerController = Cast<ARPGPlayerController>(GetController());

			RPGPlayerController->SetShowMouseCursor(true);

			FInputModeUIOnly	input;
			RPGPlayerController->SetInputMode(input);
		}
	}

}

void AHeroCharacter::SetGameInputMode()
{
	ARPGPlayerController* RPGPlayerController = Cast<ARPGPlayerController>(GetController());

	RPGPlayerController->SetShowMouseCursor(false);

	FInputModeGameOnly inputmode;
	RPGPlayerController->SetInputMode(inputmode);

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
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &AHeroCharacter::StartAim);
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &AHeroCharacter::StopAim);

		// Trigger
		EnhancedInputComponent->BindAction(TriggerAction, ETriggerEvent::Triggered, this, &AHeroCharacter::PullTrigger);
		EnhancedInputComponent->BindAction(TriggerAction, ETriggerEvent::Completed, this, &AHeroCharacter::ReleaseTrigger);

		// ChangeFireMode
		EnhancedInputComponent->BindAction(ChangeFireModeAction, ETriggerEvent::Completed, this, &AHeroCharacter::ChangeFireMode);

		// Reload
		EnhancedInputComponent->BindAction(ReloadModeAction, ETriggerEvent::Completed, this, &AHeroCharacter::PlayReloadingMontage);

		// GetItem
		EnhancedInputComponent->BindAction(GetItemAction, ETriggerEvent::Completed, this, &AHeroCharacter::GetItem);

		// Roll
		EnhancedInputComponent->BindAction(RollAction, ETriggerEvent::Started, this, &AHeroCharacter::Roll);
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
	if (bIsRolling) { return; }

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
	if (bIsRolling) { return; }

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
	if (bIsRolling) { return; }

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
	if (bIsRolling) { return; }

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

#include "Junglae/Subsystem/InventorySubsystem.h"
#include "Junglae/Subsystem/ChoSubsystem.h"
#include "HeroCharacter.h"
void AHeroCharacter::GetItem()
{
	if (OverlapItem == nullptr) { return; }

	OverlapItem->ChangeGun(this);
	
	UGameInstanceSubsystem* GameInstanceSubsystem2 = GetGameInstance()->GetSubsystemBase(UChoDataSubsystem::StaticClass());
	UChoDataSubsystem* ChoDataSubsystem = Cast<UChoDataSubsystem>(GameInstanceSubsystem2);
	
	//UGameInstanceSubsystem* GameInstanceSubsystem = GetGameInstance()->GetSubsystemBase(UInventorySubsystem::StaticClass());
	//Cast<UInventorySubsystem>(GameInstanceSubsystem)->AddChoItem(TEXT("Gun"), ChoDataSubsystem);

	UInventorySubsystem* GameInstanceSubsystem = ULocalPlayer::GetSubsystem<UInventorySubsystem>(
		Cast<APlayerController>(GetController())->GetLocalPlayer());
	GameInstanceSubsystem->AddChoItem(TEXT("Gun"));

	// 
	//UGameInstance* GameInstance = GetGameInstance();
	//UInventorySubsystem* MySubsystem = GameInstance->GetSubsystem<UInventorySubsystem>();
	//MySubsystem->AddChoItem(TEXT("Gun"));
}

void AHeroCharacter::Roll()
{


	if (IsZoomIn) { return; }

	if (bIsRolling) { return; }

	if (CanJump() == false) { return; }

	bIsRolling = true;

	ReleaseTrigger();

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	AnimInstance->Montage_Stop(0);
	AnimInstance->Montage_Play(RollingMontage);

	if (RollCurve)
	{
		FOnTimelineFloat CurveCallback;
		CurveCallback.BindUFunction(this, FName("RollMove"));

		Timeline.AddInterpFloat(RollCurve, CurveCallback);
		Timeline.SetTimelineLength(1.f);
		Timeline.PlayFromStart();
	}
}

void AHeroCharacter::RollMove(float InRollCurve)
{
	GetCharacterMovement()->Velocity = GetActorForwardVector() * 1000.f * InRollCurve;
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
	if (bIsRolling) { return; }

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

float AHeroCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	UE_LOG(LogTemp, Warning, TEXT("Hit Player!: %f"), Damage);

	HP -= Damage;

	if (HP <= 0 || FMath::IsNearlyZero(HP))
	{
		//SetActorEnableCollision(false);
		GetController()->StopMovement();

		//UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(GetMesh());
		//PrimitiveComponent->SetSimulatePhysics(true);
		//PrimitiveComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

		GetMesh()->SetSimulatePhysics(true);

		// Show Died UI if not already shown
		if (mDiedWidget == nullptr)
		{
			ShowDiedUI();
		}
	}

	return Damage;

}

void AHeroCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetWeaponData();
}

