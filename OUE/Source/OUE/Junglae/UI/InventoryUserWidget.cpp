// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/UI/InventoryUserWidget.h"
#include "Junglae/Subsystem/ChoSubsystem.h"
#include "InventoryItemUserWidget.h"

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

	int32 Col = 5;
	int32 Row = InvenSize / Col;

	for (int32 i = 0; i < Row; ++i)
	{
		for (int32 k = 0; k < Col; ++k)
		{
			UInventoryItemUserWidget* Widget = Cast<UInventoryItemUserWidget>(CreateWidget(this, InventoryItemWidgetClass));
			ensure(Widget);
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

void UInventoryUserWidget::FlushInven()
{
	for (int32 i = 0; i < InvenSize; ++i)
	{
		if (InventorySubsystem->Inventory[i] == nullptr) continue;

		UTexture2D* Texture = InventorySubsystem->Inventory[i]->ItemImage;
		if (Texture)
		{
			Items[i]->ItemImage->SetBrushFromTexture(Texture, true);
		}
		else
		{
			Items[i]->ItemImage->SetBrushFromTexture(nullptr, true);
		}
	}

}
