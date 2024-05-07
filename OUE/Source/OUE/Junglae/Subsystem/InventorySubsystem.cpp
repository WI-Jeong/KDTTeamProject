// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/Subsystem/InventorySubsystem.h"
#include "ChoDataSubsystem.h"

void UInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
}

void UInventorySubsystem::Deinitialize()
{
}

void UInventorySubsystem::MakeInventory()
{
	ChoDataSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UChoDataSubsystem>();
	Inventory.SetNum(20, false);

	AddChoItem(TEXT("Potion_HP"));
}

bool UInventorySubsystem::AddChoItem(const FName& InKey)
{
	const FChoItemData* ChoData = ChoDataSubsystem->FindChoItem(InKey);
	if (!ChoData)
	{
		check(false);
		return false;
	}
	
	bool bAdded = false;
	const uint32 InvenSize = Inventory.Num();
	for (uint32 i = 0; i < InvenSize; ++i)
	{
		if (Inventory[i] == nullptr)
		{
			FChoItemData* NewChoItemData = new FChoItemData(*ChoData);
			Inventory[i] = NewChoItemData;

			Inventory[i]->ItemFunctionClass->GetDefaultObject<UChoItem>()->UseChoItem();

			bAdded = true;
			break;
		}
	}

	return bAdded;
}
