// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "../../Junglae/Controller/RPGPlayerController.h"
#include "Hero/ActorPool/ActorPool.h"
#include "HeroGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API AHeroGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> Bullet;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEffect> Effect;

protected:
	FActorPool BulletPool;
	FActorPool EffectPool;

public:
	FActorPool& GetBulletPool() { return BulletPool; }
	FActorPool& GetEffectPool() { return EffectPool; }

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};
