// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/UI/InventoryUserWidget.h"
#include "Junglae/Subsystem/ChoSubsystem.h"
#include "Junglae/UI/InventoryItemUserWidget.h"

void UInventoryUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (InvenSize > 0)
	{
		FlushInven();
		return;
	}

	ULocalPlayer* LocalPlayer = GetOwningLocalPlayer();
	InventorySubsystem = ULocalPlayer::GetSubsystem<UInventorySubsystem>(LocalPlayer);
	InvenSize = InventorySubsystem->Inventory.Num();
	Items.Reserve(InvenSize);
	
	//게임에서 참조된 적이 없어서 로드가 안됨.
	LoadClass<UClass>(ANY_PACKAGE, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Junglae/UI_InventoryItem.UI_InventoryItem_C'"),
		nullptr, LOAD_None, nullptr);
	UClass* InventoryItemWidgetClass = FindObject<UClass>
		(ANY_PACKAGE, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Junglae/UI_InventoryItem.UI_InventoryItem_C'"));

	int32 Col = 6;
	int32 Row = InvenSize / Col;

	for (int32 i = 0; i < Row; ++i)
	{
		for (int32 k = 0; k < Col; ++k)
		{
			UInventoryItemUserWidget* Widget = Cast<UInventoryItemUserWidget>(CreateWidget(this, InventoryItemWidgetClass));
			ensure(Widget);

			Widget->ItemIndex = k + i * Col;
			// 마우스가 아이템 위로 올라갔을 때 텍스트가 뜨게함.
			Widget->ItemBtnHovered.BindLambda(
				[this](UInventoryItemUserWidget* ItemWidget)
				{
					const uint32 Index = ItemWidget->ItemIndex;
					LastHoveredIndex = Index;
					SetItemDesc(Index);
				}
			);

			Widget->ItemBtnClicked.BindUFunction(this, TEXT("OnItemBtnClicked"));

			Items.Add(Widget);
			InventoryPanel->AddChildToUniformGrid(Widget, i, k);
		}
	}

	FlushInven();
}

void UInventoryUserWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

//인벤토리 비우는 함수
void UInventoryUserWidget::FlushInven()
{   // 인벤토리 크기만큼 실행
	for (int32 i = 0; i < InvenSize; ++i)
	{
		if (InventorySubsystem->Inventory[i] == nullptr)
		{
			Items[i]->ItemImage->SetBrushFromTexture(nullptr, false);
			continue;
		}

		UTexture2D* Texture = InventorySubsystem->Inventory[i]->ItemImage;
		if (Texture)
		{
			Items[i]->ItemImage->SetBrushFromTexture(Texture, false);
		}
		else
		{
			Items[i]->ItemImage->SetBrushFromTexture(nullptr, false);
		}
	}

	SetItemDesc(LastHoveredIndex);
}

void UInventoryUserWidget::SetItemDesc(const uint32 InIndex)
{
	if (InIndex == (uint32)-1) { return; }

	TWeakPtr<FChoItemData> ItemData = InventorySubsystem->Inventory[InIndex];
	if (ItemData.IsValid())
	{
		ItemDesc->SetText(ItemData.Pin()->ItemDesc);
	}
	else
	{
		ItemDesc->SetText(FText());
	}
}

void UInventoryUserWidget::OnItemBtnClicked(UInventoryItemUserWidget* InWidget)
{
	const uint32 Index = InWidget->ItemIndex;
	
	TWeakPtr<FChoItemData> ItemData = InventorySubsystem->Inventory[Index];
	if (ItemData.IsValid())
	{
		InventorySubsystem->UseChoItem(this, Index);
	}
}
