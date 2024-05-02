// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Effect.generated.h"

class UParticleSystemComponent;
class ParticleSystem;

UCLASS()
class OUE_API AEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere)
	UParticleSystemComponent* ParticleSystemComponent;

	UPROPERTY(EditAnywhere)
	UParticleSystem* ParticleSystem;

protected:
	FTimerHandle InitialLifeSpanTimer;

	UPROPERTY(EditAnywhere)
	float EffectInitialLifeSpan = 3.f;

public:
	void SetEffect();

};
