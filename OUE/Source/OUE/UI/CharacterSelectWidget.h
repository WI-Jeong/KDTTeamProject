// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectWidget.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API UCharacterSelectWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct();
	
};