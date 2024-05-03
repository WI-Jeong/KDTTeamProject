// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Junglae/ChoItem/ChoItemData.h"
#include "ChoDataSubsystem.generated.h"

struct FChoItemData;
/**
 * 
 */
UCLASS()
class OUE_API UChoDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UChoDataSubsystem();

	const FChoItemData* FindChoItem(const FName& Inkey);

protected:
	UPROPERTY()
	UDataTable* ProjectileDataTable;

	UPROPERTY()
	UDataTable* CharacterDataTable;

	UPROPERTY()
	UDataTable* ItemDataTable;
	
};
