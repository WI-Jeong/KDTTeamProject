// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "MyClass/Actors/Gun/Gun.h"
#include "HellDiverCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AHellDiverCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Run Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RunAction;

	/** Trigger Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* TriggerAction;

	///** AutoFire Input Action */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* AutoFireAction;

	/** Aim Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AimAction;

	/** Ironsight Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* IronsightAction;

	/**  ChangeFireMode Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ChangeFireModeAction;

protected:
	UPROPERTY(EditAnyWhere, Category = "Gun", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGun> Gun;

	UPROPERTY(EditAnyWhere, Category = "Gun", meta = (AllowPrivateAccess = "true"))
	AGun* SpawnedGun = nullptr;

	UPROPERTY(EditAnyWhere, Category = "Gun", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* GunCameraComponent;

public:
	AHellDiverCharacter();

protected:
	bool bIsRun = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunSpeed = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WalkSpeed = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AimSpeed = 10.f;

	AActor* GunCameraActor = nullptr;

	AActor* MainCameraActor = nullptr;

	bool bIsIronsight = false;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void Run(const FInputActionValue& Value);
			
	void StopRun(const FInputActionValue& Value);

	void StartTrigger(const FInputActionValue& Value);

	void StopTrigger(const FInputActionValue& Value);

	void StartAim(const FInputActionValue& Value);

	void Aim(const FInputActionValue& Value);

	void StopAim(const FInputActionValue& Value);

	void IronsightOnOff(const FInputActionValue& Value);

	void ChangeFireMode(const FInputActionValue& Value);
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaSeconds) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:
	void AttachGun(TSubclassOf<AGun> InGun);

	bool bIsRotateBodyToAim = false;

	void RotateBodyToAim();
};

