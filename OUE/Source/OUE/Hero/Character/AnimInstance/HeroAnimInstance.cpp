// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Character/AnimInstance/HeroAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Hero/Character/HeroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Pawn = TryGetPawnOwner();
	if (!Pawn) { return; }

	MovementComponent = Pawn->GetMovementComponent();
}

void UHeroAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!Pawn) { return; }

	Speed = MovementComponent->Velocity.Length();

	IsFalling = MovementComponent->IsFalling();

	Velocity = MovementComponent->Velocity;


	//IsShouldMove//
	AHeroCharacter* HeroCharacter = Cast<AHeroCharacter>(Pawn);
	FVector Acceleration;
	if (HeroCharacter)
	{
		Acceleration = HeroCharacter->GetCharacterMovement()->GetCurrentAcceleration();
	}

	FVector ZeroVector = FVector::ZeroVector;

	if (Acceleration != ZeroVector && Speed > 3.0f)
	{
		IsShouldMove = true;
	}
	else
	{
		IsShouldMove = false;
	}

	//IsCrouch//
	if (HeroCharacter)
	{
		IsCrouch = HeroCharacter->GetIsCrouch();
	}

	//에임 오프셋

	FRotator ControlRotation = Pawn->GetControlRotation();
	FRotator ActorRotation = Pawn->GetActorRotation();
	FRotator TargetRotator = UKismetMathLibrary::NormalizedDeltaRotator(ControlRotation, ActorRotation);

	FRotator CurrentRotator = FRotator(Pitch, Yaw, 0);

	FRotator NewRotator = FMath::RInterpTo(CurrentRotator, TargetRotator, DeltaSeconds, 15.f);

	Pitch = FMath::ClampAngle(NewRotator.Pitch, -90, 90);
	Yaw = FMath::ClampAngle(NewRotator.Yaw, -90, 90);
}
