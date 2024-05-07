// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "InventoryItemUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API UInventoryItemUserWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* ItemBtn;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage* ItemImage;
};
