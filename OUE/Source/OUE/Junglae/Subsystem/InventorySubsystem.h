// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Junglae/ChoItem/ChoItemData.h"
#include "Junglae/ChoItem/ChoItem.h"
#include "InventorySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API UInventorySubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
	friend class ARPGPlayerController;
	friend class UInventoryUserWidget;

public:

protected:
	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection);

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize();

	void MakeInventory();

	bool AddChoItem(const FName& InKey);

protected:
	TArray<FChoItemData*> Inventory;
	class UChoDataSubsystem* ChoDataSubsystem;
};
