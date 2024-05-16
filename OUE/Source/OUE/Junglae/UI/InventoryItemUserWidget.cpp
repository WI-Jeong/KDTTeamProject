// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/UI/InventoryItemUserWidget.h"

void UInventoryItemUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ItemBtn->OnHovered.AddDynamic(this, &ThisClass::OnItemBtnHovered);
	ItemBtn->OnClicked.AddDynamic(this, &ThisClass::OnItemBtnClicked);
}
//아이템 마우스 올리면 동작.
void UInventoryItemUserWidget::OnItemBtnHovered()
{	//아이템이 바인딩 됐을때 실행되게 처리.
	if (ItemBtnHovered.IsBound())
	{
		ItemBtnHovered.Execute(this);

	}
}
// 아이템 클릭했을 때 동작.
void UInventoryItemUserWidget::OnItemBtnClicked()
{	//아이템이 바인딩 됐을때 실행되게 처리.
	if (ItemBtnClicked.IsBound())
	{
		ItemBtnClicked.Execute(this);
	}
}
