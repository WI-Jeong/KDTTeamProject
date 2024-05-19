// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainWidget.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectWidget.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API UCharacterSelectWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UButton* mGameStartButton;

public:
	virtual void NativeConstruct();
	void EnableStartButton(bool Enable);

private:
	UFUNCTION()
	void StartButtonClick();
};
