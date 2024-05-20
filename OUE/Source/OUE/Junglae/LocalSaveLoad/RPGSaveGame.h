// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Junglae/ChoItem/ChoItemData.h"
#include "RPGSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API URPGSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public: // Player
	UPROPERTY()
	FVector PlayerLocation;

	UPROPERTY()
	FRotator PlayerRotation;

public: // Controller
	UPROPERTY()
	FRotator ControllerRotation;

	UPROPERTY()
	float TargetArmLength;

public: // Inventory
	UPROPERTY()
	TArray<FChoItemData> InventoryItems;

	UPROPERTY()
	FChoItemData Weapon;
};
