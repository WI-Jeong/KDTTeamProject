// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Junglae/ChoItem/ChoItem.h"
#include "InventoryUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API UInventoryUserWidget : public UUserWidget
{
	GENERATED_BODY()

	friend class UInventorySubsystem;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void FlushInven();

	void SetItemDesc(const uint32 InIndex);
	UFUNCTION()
	void OnItemBtnClicked(UInventoryItemUserWidget* InWidget);

protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UUniformGridPanel* InventoryPanel;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* ItemDesc;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UInventoryItemUserWidget* Weapon; friend UChoItem_Gun;

	int32 InvenSize = 0;
	uint32 LastHoveredIndex = (uint32) - 1;

	UPROPERTY()
	TArray<class UInventoryItemUserWidget*> Items;


	UInventorySubsystem* InventorySubsystem;
};
