// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChoItemData.generated.h"

class UChoItem;

USTRUCT()
struct OUE_API FChoItemData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UTexture2D* ItemImage;

	UPROPERTY(EditAnywhere)
	FText ItemDesc;

	UPROPERTY(EditAnywhere)
	uint32 BundleCount = 1;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UChoItem> ItemFunctionClass;
};
