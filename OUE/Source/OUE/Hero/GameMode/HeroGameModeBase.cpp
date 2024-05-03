// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/GameMode/HeroGameModeBase.h"
#include "Hero/Gun/Bullet.h"
#include "Hero/Effect/Effect.h"

void AHeroGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	ensure(Bullet);
	BulletPool.Create(GetWorld(), Bullet, 30);

	ensure(Effect);
	EffectPool.Create(GetWorld(), Effect, 30);
}

void AHeroGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	BulletPool.Destroy();
	EffectPool.Destroy();
}
