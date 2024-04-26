// Fill out your copyright notice in the Description page of Project Settings.


#include "MyClass/Animations/CharacterAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Pawn = TryGetPawnOwner();
	if (!Pawn) { return; }

	MovementComponent = Pawn->GetMovementComponent();
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	//걷기 속도
	if (!Pawn) { return; }

	Speed = MovementComponent->Velocity.Length();

	UE_LOG(LogTemp, Warning, TEXT("Speed: '%f'"), Speed);

	//에임 오프셋

	FRotator ControlRotation = Pawn->GetControlRotation();
	FRotator ActorRotation = Pawn->GetActorRotation();
	FRotator TargetRotator = UKismetMathLibrary::NormalizedDeltaRotator(ControlRotation, ActorRotation);

	FRotator CurrentRotator = FRotator(Pitch, Yaw, 0);

	FRotator NewRotator = FMath::RInterpTo(CurrentRotator, TargetRotator, DeltaSeconds, 15.f);

	Pitch = FMath::ClampAngle(NewRotator.Pitch, -90, 90);
	Yaw = FMath::ClampAngle(NewRotator.Yaw, -90, 90);

}
