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
<<<<<<< HEAD

=======
	virtual void BeginPlay() override;

protected:
	TSubclassOf<UUserWidget> MainHUDWidgetClass;
	UMainWidget* MainWidget;
>>>>>>> 6bbe29829c7adb2d0b8aed12c12bb400114b9ef7
};
