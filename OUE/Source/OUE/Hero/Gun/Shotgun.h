// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hero/Gun/Gun.h"
#include "Shotgun.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API AShotgun : public AGun
{
	GENERATED_BODY()

	AShotgun();

	virtual void SpawnBullet(TSubclassOf<ABullet> InBullet) override;

protected:
	UPROPERTY(EditAnywhere)
	int BulletCount = 10;

	UPROPERTY(EditAnywhere)
	float SpreadRange = 10.f;
};
