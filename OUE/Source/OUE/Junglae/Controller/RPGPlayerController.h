// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../UI/MainWidget.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ARPGPlayerController();
	
public:
	virtual void OnPossess(APawn* PawnToPossess) override;
	virtual void BeginPlay() override;

protected:
	TSubclassOf<UUserWidget> MainHUDWidgetClass;
	UMainWidget* MainWidget;
};
