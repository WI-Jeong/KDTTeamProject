// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HeroAnimInstance.generated.h"

class UPawnMovementComponent;
UCLASS()
class OUE_API UHeroAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	APawn* Pawn;

	UPawnMovementComponent* MovementComponent;

	UPROPERTY(BlueprintReadOnly)
	FRotator Rotator;

	UPROPERTY(BlueprintReadOnly)
	FVector Velocity;

	UPROPERTY(BlueprintReadOnly)
	float Speed;

	UPROPERTY(BlueprintReadOnly)
	bool IsFalling = false;

	UPROPERTY(BlueprintReadOnly)
	bool IsShouldMove;

	UPROPERTY(BlueprintReadOnly)
	bool IsCrouch;

	UPROPERTY(BlueprintReadWrite)
	float Pitch = 0.f;

	UPROPERTY(BlueprintReadWrite)
	float Yaw = 0.f;

	UPROPERTY(BlueprintReadWrite)
	bool IsRotateBodyToAim = false;

	UPROPERTY(BlueprintReadWrite)
	bool bIsRolling = false;

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
