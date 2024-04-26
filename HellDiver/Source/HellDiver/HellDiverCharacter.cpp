// Copyright Epic Games, Inc. All Rights Reserved.

#include "HellDiverCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AHellDiverCharacter

AHellDiverCharacter::AHellDiverCharacter()
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
	GetCharacterMovement()->JumpZVelocity = 700.f;
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


	GunCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("GunCamera"));
	GunCameraComponent->SetupAttachment(GetMesh());
}

void AHellDiverCharacter::BeginPlay()
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

	AttachGun(Gun);
}

void AHellDiverCharacter::Tick(float DeltaSeconds)
{
	if (bIsRotateBodyToAim)
	{
		RotateBodyToAim();
	}
}

void AHellDiverCharacter::AttachGun(TSubclassOf<AGun> InGun)
{
	if (InGun)
	{
		// SpawnActor를 통해 weapon 데이터를 기반으로 한 액터 생성
		SpawnedGun = GetWorld()->SpawnActor<AGun>(InGun);

		// 소켓 이름을 통해 현재 메시에서 소켓을 참조
		const USkeletalMeshSocket* GunSocket = GetMesh()->GetSocketByName("GunSocket");

		if (SpawnedGun && GunSocket)
		{
			// 소켓에 액터를 할당
			GunSocket->AttachActor(SpawnedGun, GetMesh());
		}
	}
}

void AHellDiverCharacter::RotateBodyToAim()
{
	FRotator ControlRotation = GetControlRotation();
	FRotator ActorRotation = GetActorRotation();
	FRotator NewRotation = FRotator(ActorRotation.Pitch, ControlRotation.Yaw, ActorRotation.Roll);

	NewRotation = UKismetMathLibrary::RLerp(ActorRotation, NewRotation, GetWorld()->GetDeltaSeconds() * AimSpeed, true);

	SetActorRotation(NewRotation);
}

//////////////////////////////////////////////////////////////////////////
// Input

void AHellDiverCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHellDiverCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AHellDiverCharacter::Look);

		// Run
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Started, this, &AHellDiverCharacter::Run);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &AHellDiverCharacter::StopRun);

		//Fire
		EnhancedInputComponent->BindAction(TriggerAction, ETriggerEvent::Started, this, &AHellDiverCharacter::StartTrigger);
		EnhancedInputComponent->BindAction(TriggerAction, ETriggerEvent::Completed, this, &AHellDiverCharacter::StopTrigger);

		//AutoFire
		//EnhancedInputComponent->BindAction(AutoFireAction, ETriggerEvent::Triggered, this, &AHellDiverCharacter::Fire);

		//Aim
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Started, this, &AHellDiverCharacter::StartAim);
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &AHellDiverCharacter::Aim);
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &AHellDiverCharacter::StopAim);

		EnhancedInputComponent->BindAction(IronsightAction, ETriggerEvent::Completed, this, &AHellDiverCharacter::IronsightOnOff);

		EnhancedInputComponent->BindAction(ChangeFireModeAction, ETriggerEvent::Completed, this, &AHellDiverCharacter::ChangeFireMode);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AHellDiverCharacter::Move(const FInputActionValue& Value)
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

void AHellDiverCharacter::Look(const FInputActionValue& Value)
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

void AHellDiverCharacter::Run(const FInputActionValue& Value)
{
	bIsRun = true;
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void AHellDiverCharacter::StopRun(const FInputActionValue& Value)
{
	bIsRun = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AHellDiverCharacter::StartTrigger(const FInputActionValue& Value)
{
	if (SpawnedGun)
	{
		SpawnedGun->StartTrigger();
	}
}

void AHellDiverCharacter::StopTrigger(const FInputActionValue& Value)
{
	ensure(SpawnedGun);
	if (SpawnedGun)
	{
		SpawnedGun->StopTrigger();
	}
}

void AHellDiverCharacter::StartAim(const FInputActionValue& Value)
{
	GetCharacterMovement()->bOrientRotationToMovement = false;

	bIsRotateBodyToAim = true;
}

void AHellDiverCharacter::Aim(const FInputActionValue& Value)
{

}

void AHellDiverCharacter::StopAim(const FInputActionValue& Value)
{
	GetCharacterMovement()->bOrientRotationToMovement = true;

	bIsRotateBodyToAim = false;
}

void AHellDiverCharacter::IronsightOnOff(const FInputActionValue& Value)
{
	if (bIsIronsight == false)
	{
		bIsIronsight = true;
		UE_LOG(LogTemp, Warning, TEXT("Ironsight On"));

		GunCameraActor = Cast<AGun>(SpawnedGun)->GetCameraActor();
		ensure(GunCameraActor);
		if (GunCameraActor)
		{
			FollowCamera->SetActive(false);

			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
			MainCameraActor = PlayerController->GetViewTarget();
			PlayerController->SetViewTarget(GunCameraActor);

			GetCharacterMovement()->bOrientRotationToMovement = false;

			bIsRotateBodyToAim = true;
		}
	}
	else
	{
		bIsIronsight = false;
		UE_LOG(LogTemp, Warning, TEXT("Ironsight Off"));

		FollowCamera->SetActive(true);

		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		PlayerController->SetViewTarget(MainCameraActor);

		GetCharacterMovement()->bOrientRotationToMovement = true;

		bIsRotateBodyToAim = false;
	}
}

void AHellDiverCharacter::ChangeFireMode(const FInputActionValue& Value)
{
	ensure(SpawnedGun);
	if (SpawnedGun)
	{
		SpawnedGun->ChangeFireMode();
	}
}
