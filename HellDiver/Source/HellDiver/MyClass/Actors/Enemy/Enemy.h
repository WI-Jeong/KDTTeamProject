// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Enemy.generated.h"

UCLASS()
class HELLDIVER_API AEnemy : public APawn
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* SkeletalMeshComponent = nullptr;

	UPROPERTY(EditAnywhere)
	UCapsuleComponent* CapsuleComponent = nullptr;

	UPROPERTY(EditAnywhere)
	float HP = 3.f;

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
};
