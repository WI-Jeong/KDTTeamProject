// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StartGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class OUE_API AStartGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AStartGameModeBase();

private:
	TSubclassOf<UUserWidget>	mStartUIClass;
	TObjectPtr<class UStartWidget>	mStartWidget;

public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
	virtual void InitGameState();
	virtual void PostLogin(APlayerController* NewPlayer);
	virtual void BeginPlay()	override;
	virtual void Tick(float DeltaTime)	override;
	
};
