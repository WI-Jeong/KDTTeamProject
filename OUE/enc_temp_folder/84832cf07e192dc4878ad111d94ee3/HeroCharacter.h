// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "HeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UHeroAnimInstance;
class AGun;

USTRUCT()
struct OUE_API FWeaponDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UHeroAnimInstance> AnimBP;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGun> Gun;

	UPROPERTY(EditAnywhere)
	FVector GunLocation;

	UPROPERTY(EditAnywhere)
	FRotator GunRotation;
};

UCLASS()
class OUE_API AHeroCharacter : public ACharacter
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

	/** Crouch Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CrouchAction;

	/** Run Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RunAction;

	/** Zoom Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ZoomAction;

public:
	AHeroCharacter();

protected:
	UPROPERTY(BlueprintReadOnly)
	bool IsCrouch = false;

	float WalkSpeed = 200.f;

	float CrouchSpeed = 200.f;

	float RunSpeed = 500.f;

	UPROPERTY(EditAnywhere, meta = (RowType = "/Script/OUE.WeaponDataTableRow"))
	FDataTableRowHandle WeaponDataTableRowHandle;
	FWeaponDataTableRow* WeaponDataTableRow;

	AGun* SpawnedGun;

	AActor* MainCameraActor;

	bool bIsRotateBodyToAim = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AimSpeed = 10.f;

public:
	bool GetIsCrouch() { return IsCrouch; }

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void StartCrouch(const FInputActionValue& Value);
	void StopCrouch(const FInputActionValue& Value);

	void StartRun(const FInputActionValue& Value);
	void StopRun(const FInputActionValue& Value);

	void ZoomInOut();
	bool IsZoomIn = false;

protected:
	void SetWeaponData();

	void SpawnGun(TSubclassOf<AGun> InGun);

	void RotateBodyToAim();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;

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
};
