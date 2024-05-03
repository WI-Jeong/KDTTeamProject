// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChoItem.generated.h"

UCLASS()
class UChoItem : public UObject
{
	GENERATED_BODY()

	friend class UInventorySubsystem;

protected:
	virtual void UseChoItem()
	{
		int a = 0;
	}
};