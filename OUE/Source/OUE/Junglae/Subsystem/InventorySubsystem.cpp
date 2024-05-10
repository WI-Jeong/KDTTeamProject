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
	Inventory.Reserve(MaxInvenSize);
	Inventory.SetNum(MaxInvenSize, false);

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
	
	if (InventoryMap.Find(InKey))
	{
		if (InventoryMap[InKey].IsValid())
		{
			++InventoryMap[InKey].Pin()->CurrentBundleCount;
		}
		return true;
	}

	bool bAdded = false;
	const uint32 InvenSize = Inventory.Num();
	for (uint32 i = 0; i < InvenSize; ++i)
	{
		if (Inventory[i] == nullptr)
		{
			TSharedPtr<FChoItemData> NewChoItemData = MakeShared<FChoItemData>(*ChoData);
			NewChoItemData->ItemName = InKey;
			++NewChoItemData->CurrentBundleCount;
			Inventory[i] = NewChoItemData;
			InventoryMap.Add(InKey, NewChoItemData);

			bAdded = true;
			break;
		}
	}

	return bAdded;
}
#include "Junglae/UI/InventoryUserWidget.h"
#include "Junglae/Controller/RPGPlayerController.h"

void UInventorySubsystem::UseChoItem(UInventoryUserWidget* Widget, uint32 InIndex)
{
	TWeakPtr<FChoItemData> ItemData = Inventory[InIndex];
	if (!ItemData.IsValid()) { return; }

	ARPGPlayerController* RPGPlayerController = Cast<ARPGPlayerController>(Widget->GetOwningPlayer());
	ensure(RPGPlayerController);

	UChoItem* Item = ItemData.Pin()->ItemFunctionClass->GetDefaultObject<UChoItem>();

	UChoItem_Potion* Potion = Cast<UChoItem_Potion>(Item);
	if (Potion)
	{
		--ItemData.Pin()->CurrentBundleCount;
	}

	Item->UseChoItem(RPGPlayerController);

	if (ItemData.Pin()->CurrentBundleCount == 0)
	{
		InventoryMap.Remove(Inventory[InIndex]->ItemName);
		Inventory[InIndex] = nullptr;

	}

	Widget->FlushInven();
}
