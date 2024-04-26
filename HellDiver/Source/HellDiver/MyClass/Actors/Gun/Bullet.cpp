// Fill out your copyright notice in the Description page of Project Settings.


#include "MyClass/Actors/Gun/Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MyClass/Actors/Enemy/Enemy.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));

	//ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = InitialSpeed;
	ProjectileMovement->MaxSpeed = MaxSpeed;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

	OnActorHit.AddDynamic(this, &ThisClass::OnActorHitFunction);

}

void ABullet::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void ABullet::OnActorHitFunction(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	SetActorEnableCollision(false);

	AEnemy* Enemy = Cast<AEnemy>(OtherActor);
	if (IsValid(Enemy))
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, nullptr);
	}
}

