// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Enemy/Enemy.h"
#include "AIController.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEnemy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	UE_LOG(LogTemp, Warning, TEXT("Hit Enemy!: %f"), Damage);

	HP -= Damage;

	if (HP <= 0 || FMath::IsNearlyZero(HP))
	{
		//SetActorEnableCollision(false);
		if (GetController() != nullptr)
		{
			GetController()->StopMovement();
			Controller = nullptr;
		}

		APawn* Pawn = Cast<APawn>(this);
		Pawn->UnPossessed();
		Pawn->AIControllerClass = nullptr;
		/*AAIController* AIController = Cast<AAIController>(Pawn->AIControllerClass);
		AIController->BrainComponent = nullptr;*/
		
		GetMesh()->SetSimulatePhysics(true);
		//PrimitiveComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

		bIsDead = true;

		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		GetWorldTimerManager().SetTimer(DestroyTimerHandle, this, &AEnemy::DelayDestroy, 1.0f, true, 3.0f);
	}
	return Damage;
}

void AEnemy::DelayDestroy()
{
	Destroy();
}

