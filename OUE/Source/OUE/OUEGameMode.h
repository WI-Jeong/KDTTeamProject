// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OUEGameMode.generated.h"

UCLASS(minimalapi)
class AOUEGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOUEGameMode();

private:
	TSubclassOf<UUserWidget>	mMainUIClass;
	TObjectPtr<class UMainWidget>	mMainWidget;

protected:
	virtual void BeginPlay();
};



