// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/EnemySpawner/EnemySpawner.h"
#include "OUECharacter.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
	// TestFunction 을 초당 1 회, 10 초간 호출합니다.
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEnemySpawner::SpawnEnemy, SpawnDelayTime, true);
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::SpawnEnemy()
{
	GetWorld()->SpawnActor(Enemy, &GetTransform());
}

