// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/GameMode/HeroGameModeBase.h"
#include "Hero/Gun/Bullet.h"

void AHeroGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	BulletPool.Create(GetWorld(), ABullet::StaticClass(), 2);
	//EffectPool.Create(GetWorld(), AEffect::StaticClass(), 5);
}

void AHeroGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	BulletPool.Destroy();
	//EffectPool.Destroy();
}
