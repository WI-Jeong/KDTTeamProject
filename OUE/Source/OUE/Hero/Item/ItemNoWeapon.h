// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hero/Item/Item.h"
#include "ItemNoWeapon.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API AItemNoWeapon : public AItem
{
	GENERATED_BODY()
	
	virtual void OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
