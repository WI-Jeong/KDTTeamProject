// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/UI/InventoryUserWidget.h"
#include "Junglae/Subsystem/ChoSubsystem.h"
#include "InventoryItemUserWidget.h"

void UInventoryUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ULocalPlayer* LocalPlayer = GetOwningLocalPlayer();
	UInventorySubsystem* InventorySubsystem = ULocalPlayer::GetSubsystem<UInventorySubsystem>(LocalPlayer);
	InvenSize = InventorySubsystem->Inventory.Num();
	
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
			UWidget* Widget = CreateWidget(this, InventoryItemWidgetClass);
			InventoryPanel->AddChildToUniformGrid(Widget, i, k);
		}
	}
}

void UInventoryUserWidget::NativeDestruct()
{
	Super::NativeDestruct();
}