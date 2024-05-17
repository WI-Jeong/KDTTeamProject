// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSelectGameMode.h"
#include "UI/CharacterSelectWidget.h" 
#include "JWI/PlayerSelect/CSPlayerController.h" 

ACharacterSelectGameMode::ACharacterSelectGameMode()
{
	DefaultPawnClass = nullptr;

	static ConstructorHelpers::FClassFinder<UUserWidget>	SelectUIClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/JWI/UI/UI_CharacterSelect.UI_CharacterSelect_C'"));

	if (SelectUIClass.Succeeded())
		mSelectUIClass = SelectUIClass.Class;

	PlayerControllerClass = ACSPlayerController::StaticClass();
}

void ACharacterSelectGameMode::EnableStartButton(bool Enable)
{
}

void ACharacterSelectGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void ACharacterSelectGameMode::InitGameState()
{
	Super::InitGameState();
}

void ACharacterSelectGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	NewPlayer->SetShowMouseCursor(true);

	FInputModeGameAndUI	input; 
	NewPlayer->SetInputMode(input);
}

void ACharacterSelectGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(mSelectUIClass))
	{
		mSelectWidget = CreateWidget<UCharacterSelectWidget>(GetWorld(),
			mSelectUIClass);

		if (IsValid(mSelectWidget))
			mSelectWidget->AddToViewport();
	}
}

void ACharacterSelectGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
