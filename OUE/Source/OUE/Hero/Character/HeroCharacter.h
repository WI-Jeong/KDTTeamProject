// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "../../UI/MainWidget.h"
#include "../../UI/DiedWidget.h"
#include "../../Junglae/Controller/RPGPlayerController.h"
#include "Components/TimelineComponent.h"
#include "HeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UHeroAnimInstance;
class AGun;
//struct FTimeline;

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

	UPROPERTY(EditAnywhere)
	UAnimMontage* RecoilMontage;

	UPROPERTY(EditAnywhere)
	UAnimMontage* ReloadingMontage;
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

	/** Aim Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AimAction;

	/** Trigger Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* TriggerAction;

	/** ChangeFireMode Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ChangeFireModeAction;

	/** Reload Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ReloadModeAction;

	/** GetItem Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* GetItemAction;

	/** Roll Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RollAction;

public:
	AHeroCharacter();

private:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget>	mDiedUIClass;

	UPROPERTY()
	TObjectPtr<class UDiedWidget>	mDiedWidget;

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

	bool IsRotateBodyToAim = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AimSpeed = 10.f;

	bool IsZoomIn = false;

	float TargetArmLengthDefault = 200.f;
	float TargetArmLengthAim = 100.f;

	float CloseUpSpeed = 7.f;

	bool IsReloading = false;

	class AItem* OverlapItem = nullptr; friend AItem;

	float HP = 10.f;

	//float MaxHP = 100.f;
	float MaxHP = 10.f;

	bool bIsRolling = false;

	UPROPERTY(EditAnywhere)
	UAnimMontage* RollingMontage;

	UPROPERTY(EditAnywhere)
	UCurveFloat* RollCurve;

	FTimeline Timeline;

public:
	void SetIsRolling(bool InIsRolling) { bIsRolling = InIsRolling; }

	bool GetIsRolling() { return bIsRolling; }

	void SetIsReloading(bool InIsReloading) { IsReloading = InIsReloading; }

	bool GetIsCrouch() { return IsCrouch; }

	bool GetIsRotateBodyToAim() { return IsRotateBodyToAim; }

	FWeaponDataTableRow* GetWeaponDataTableRow() { return WeaponDataTableRow; }

	AGun* GetSpawnedGun() { return SpawnedGun; }

	void PlayRecoilMontage();

	void PlayReloadingMontage();

	UFUNCTION(BlueprintCallable)
	float GetHP() { return HP; }
	
	UFUNCTION(BlueprintCallable)
	float GetMaxHP() { return MaxHP; }

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void StartCrouch();
	void StopCrouch();

	void StartRun();
	void StopRun();

	void ZoomInOut();

	void StartAim();
	void StopAim();

	void PullTrigger();
	void ReleaseTrigger();

	void ChangeFireMode();

	void GetItem();

	void Roll();

	UFUNCTION()
	void RollMove(float InRollCurve);

public:
	void SetWeaponData(FName InRowName = FName("NoWeapon"));

	void SpawnGun(TSubclassOf<AGun> InGun);
protected:
	void RotateBodyToAim(float DeltaSeconds);

	virtual void Jump() override;

	void CloseUpAim(float DeltaSeconds);

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

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

private:
	void ShowDiedUI();
	void SetGameInputMode();
};
