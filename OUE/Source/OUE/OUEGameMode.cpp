// Copyright Epic Games, Inc. All Rights Reserved.

#include "OUEGameMode.h"
#include "OUECharacter.h"
#include "UI/MainWidget.h"
#include "UObject/ConstructorHelpers.h"

AOUEGameMode::AOUEGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget>	MainUIClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/JWI/UI/UI_Main.UI_Main_C'"));

	if (MainUIClass.Succeeded())
	mMainUIClass = MainUIClass.Class;

}

void AOUEGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(mMainUIClass))
	{
		mMainWidget = CreateWidget<UMainWidget>(GetWorld(), mMainUIClass);

		if (IsValid(mMainWidget))
			mMainWidget->AddToViewport();
	}
}
