// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/Subsystem/InventorySubsystem.h"
#include "ChoDataSubsystem.h"
#include "Hero/Character/HeroCharacter.h"
#include "Junglae/LocalSaveLoad/RPGSaveGame.h"

void UInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UInventorySubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UInventorySubsystem::Save(URPGSaveGame* SaveGame)
{
	SaveGame->InventoryItems.Empty();
	SaveGame->Weapon = FChoItemData();

	for (TSharedPtr<FChoItemData> It : Inventory)
	{
		if (It)
		{
			SaveGame->InventoryItems.Add(*It);
		}
	}

	if (Weapon)
	{
		SaveGame->Weapon = *Weapon;
	}
}

void UInventorySubsystem::Load(ARPGPlayerController* Controller, URPGSaveGame* SaveGame)
{
	for (FChoItemData& It : SaveGame->InventoryItems)
	{
		TSharedPtr<FChoItemData> NewItemData = MakeShared<FChoItemData>(It);
		MoveItemToInventory(NewItemData);
	}

	if (SaveGame->Weapon.ItemName != NAME_None)
	{
		TSharedPtr<FChoItemData> NewItemData = MakeShared<FChoItemData>(SaveGame->Weapon);
		Weapon = NewItemData;
		UChoItem* Item = SaveGame->Weapon.ItemFunctionClass->GetDefaultObject<UChoItem>();
		Item->UseChoItem(Controller, *Weapon);
	}
}

void UInventorySubsystem::MakeInventory()
{
	ChoDataSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UChoDataSubsystem>();
	Inventory.SetNum(MaxInvenSize, false);

	//for (int32 i = 0; i < 10; ++i)
	//{
	//	AddChoItem(TEXT("Potion_HP"));
	//}
}

void UInventorySubsystem::ClearInventory()
{
	Inventory.Empty();
	Weapon = nullptr;
}

void UInventorySubsystem::UnEquipWeapon(UInventoryUserWidget* Widget)
{
	UChoItem* Item = Weapon->ItemFunctionClass->GetDefaultObject<UChoItem>();
	Item->UnEquipItem(Cast<ARPGPlayerController>(Widget->GetOwningPlayer()), *Weapon);
	MoveItemToInventory(Weapon);
	Widget->FlushInven();
}


#include "Junglae/UI/InventoryUserWidget.h"
#include "Junglae/Controller/RPGPlayerController.h"


bool UInventorySubsystem::AddChoItem(const FName& InKey)
{
	const FChoItemData* ChoData;

	ChoData = ChoDataSubsystem->FindChoItem(InKey);

	if (!ChoData)
	{
		check(false);
		return false;
	}
	TSharedPtr<FChoItemData>NewItemData = MakeShared<FChoItemData>(*ChoData);
	NewItemData->ItemName = InKey;
	NewItemData->CurrentBundleCount = 1;

	return MoveItemToInventory(NewItemData);
}

bool UInventorySubsystem::MoveItemToInventory(TSharedPtr<FChoItemData>& InItem)
{
	for (uint32 i = 0; i < MaxInvenSize; ++i)
	{
		TSharedPtr<FChoItemData> ItemData = Inventory[i];
		if (ItemData == nullptr) { continue; }

		if (ItemData->ItemName != InItem->ItemName) { continue; }

		if (ItemData->MaxBundleCount > ItemData->CurrentBundleCount)
		{
			++ItemData->CurrentBundleCount;
			return true;
		}
	}

	bool bAdded = false;
	// 인벤토리 사이즈 가져옴.
	for (uint32 i = 0; i < MaxInvenSize; ++i)
	{
		if (Inventory[i] == nullptr)
		{
			Inventory[i] = InItem;
			bAdded = true;
			break;
		}
	}
	InItem = nullptr;

	return bAdded;
}

void UInventorySubsystem::UseChoItem(UInventoryUserWidget* Widget, uint32 InIndex)
{
	TWeakPtr<FChoItemData> ItemData = Inventory[InIndex];
	if (!ItemData.IsValid()) { return; }

	ARPGPlayerController* RPGPlayerController = Cast<ARPGPlayerController>(Widget->GetOwningPlayer());
	//캐스트한 결과가 유효한지 확인.
	ensure(RPGPlayerController);

	//아이템 꺼내오기
	UChoItem* Item = ItemData.Pin()->ItemFunctionClass->GetDefaultObject<UChoItem>();

	UChoItem_Gun* Gun = Cast<UChoItem_Gun>(Item);
	if (Gun)
	{
		--ItemData.Pin()->CurrentBundleCount;
		//AHeroCharacter::Heal(HealAmount)
		Gun->UseItem(Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)), Widget, Inventory[InIndex]->ItemImage);
	}
	else
	{
		Gun->UseItem(Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)), Widget, Inventory[InIndex]->ItemImage);
		--ItemData.Pin()->CurrentBundleCount;
	}
	if (ItemData.Pin()->CurrentBundleCount == 0)
	{
		Inventory[InIndex] = nullptr;
	}

	Widget->FlushInven();
}
