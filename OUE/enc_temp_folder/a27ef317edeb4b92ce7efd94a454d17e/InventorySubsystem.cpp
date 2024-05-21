// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/Subsystem/InventorySubsystem.h"
#include "ChoDataSubsystem.h"
#include "Hero/Character/HeroCharacter.h"

void UInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
}

void UInventorySubsystem::Deinitialize()
{
}

void UInventorySubsystem::MakeInventory()
{
	ChoDataSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UChoDataSubsystem>();
	Inventory.SetNum(MaxInvenSize, false);

	for (int32 i = 0; i < 10; ++i)
	{
		AddChoItem(TEXT("Potion_HP"));
	}
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

	for (uint32 i = 0; i < MaxInvenSize; ++i)
	{
		TSharedPtr<FChoItemData> ItemData = Inventory[i];
		if (ItemData == nullptr) { continue; }

		if (ItemData->ItemName != NewItemData->ItemName) { continue; }

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
		{	//복사생성자를 통해 SharedPtr이 만들어짐. *ChoData는 FChoItemData의 복사본을 만든다.
			++NewItemData->CurrentBundleCount;
			Inventory[i] = NewItemData;

			bAdded = true;
			break;
		}
	}

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
	// 아이템을 아이템포션 타입으로 캐스팅하면 다이나믹 캐스트가 기본적으로 동작함. 관련성 있는 타입일때만 변환한다.
	UChoItem_Potion* Potion = Cast<UChoItem_Potion>(Item);
	if (Potion)
	{

		--ItemData.Pin()->CurrentBundleCount;
		//AHeroCharacter::Heal(HealAmount)
		Potion->UseItem(Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0)));
	
	}

	//if (Gun)
	//{

	//}

	Item->UseChoItem(RPGPlayerController);

	if (ItemData.Pin()->CurrentBundleCount == 0)
	{
		Inventory[InIndex] = nullptr;
	}

	Widget->FlushInven();
}
