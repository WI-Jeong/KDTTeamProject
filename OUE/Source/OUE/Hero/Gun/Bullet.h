// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

USTRUCT()
struct FBulletTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere)
	//UStaticMesh* StaticMesh;

	//UPROPERTY(EditAnywhere)
	//UMaterial* Material;

	UPROPERTY(EditAnywhere)
	float BulletSpeed = 1000.f;

	UPROPERTY(EditAnywhere)
	float BulletGravityScale = 1.f;

	UPROPERTY(EditAnywhere)
	float InitialLifeSpan = 1.f;
};

UCLASS()
class OUE_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	void SetBullet(FBulletTableRow* InTableRow);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere)
	float MaxSpeed = 1000.f;

	UPROPERTY(EditAnywhere)
	float InitialSpeed = 1000.f;

	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	class USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere)
	float Damage = 1.f;

	FTimerHandle InitialLifeSpanTimer;

	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* ParticleSystemComponent;

	//UPROPERTY(EditAnywhere)
	//class UNiagaraComponent* NiagaraComponent;

protected:
	UFUNCTION()
	void OnActorHitFunction(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	
	void SpawnHitEffect(FTransform InTransform);
};
