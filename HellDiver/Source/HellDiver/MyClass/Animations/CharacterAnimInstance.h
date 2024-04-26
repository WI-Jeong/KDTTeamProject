// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

/**
 * 
 */

class UPawnMovementComponent;
UCLASS()
class HELLDIVER_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPawnMovementComponent* MovementComponent;

	APawn* Pawn;

	UPROPERTY(BlueprintReadOnly)
	float Speed;

	UPROPERTY(BlueprintReadWrite)
	float Pitch = 0.f;

	UPROPERTY(BlueprintReadWrite)
	float Yaw = 0.f;
};
