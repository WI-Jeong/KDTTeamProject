// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Junglae/Controller/RPGPlayerController.h"
#include "Hero/Character/HeroCharacter.h"
#include "ChoItem.generated.h"

UCLASS()
class UChoItem : public UObject
{
	GENERATED_BODY()

	friend class UInventorySubsystem;

protected:
	virtual void UseChoItem(ARPGPlayerController* Controller, FChoItemData& ItemData)
	{
		int a = 0;
	}
	virtual void UnEquipItem(ARPGPlayerController* Controller, FChoItemData& ItemData) {}

};

UCLASS()
class UChoItem_Potion : public UChoItem
{
	GENERATED_BODY()
	friend class UInventorySubsystem;
protected:
	virtual void UseItem(ARPGPlayerController* Controller);
};

UCLASS()
class UChoItem_Gun : public UChoItem
{
	GENERATED_BODY()
	friend class UInventorySubsystem;
protected:
	virtual void UseItem(ARPGPlayerController* Controller, class UInventoryUserWidget* InInventoryUserWidget, UTexture2D* Texture);
	virtual void UnEquipItem(ARPGPlayerController* Controller, FChoItemData& ItemData);

};