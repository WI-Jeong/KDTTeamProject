// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
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

protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UUniformGridPanel* InventoryPanel;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* ItemDesc;

	int32 InvenSize = 0;

	UPROPERTY()
	TArray<class UInventoryItemUserWidget*> Items;


	UInventorySubsystem* InventorySubsystem;
};
