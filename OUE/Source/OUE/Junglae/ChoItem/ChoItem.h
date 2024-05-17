// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Junglae/Controller/RPGPlayerController.h"
#include "ChoItem.generated.h"

UCLASS()
class UChoItem : public UObject
{
	GENERATED_BODY()

	friend class UInventorySubsystem;

protected:
	virtual void UseChoItem(ARPGPlayerController* Controller)
	{
		int a = 0;
	}
};

UCLASS()
class UChoItem_Potion : public UChoItem
{
	GENERATED_BODY()
	friend class UInventorySubsystem;
protected:
	virtual void UseItem(ARPGPlayerController* Controller)
	{
		
	}
};