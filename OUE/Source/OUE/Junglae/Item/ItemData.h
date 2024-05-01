// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemData.generated.h"

class UItem;

USTRUCT()
struct OUE_API FItemData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UTexture2D* ItemImage;

	UPROPERTY(EditAnywhere)
	FText ItemDesc;

	UPROPERTY(EditAnywhere)
	uint32 BundleCount = 1;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UItem> ItemFunctionClass;
};
