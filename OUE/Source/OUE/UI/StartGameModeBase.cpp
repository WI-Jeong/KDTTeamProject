// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameModeBase.h"
#include "../Junglae/Controller/RPGPlayerController.h"
#include "StartWidget.h"

AStartGameModeBase::AStartGameModeBase()
{
	//DefaultPawn nullptr
	DefaultPawnClass = nullptr;

	static ConstructorHelpers::FClassFinder<UUserWidget>	StartUIClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/JWI/UI/UI_Start.UI_Start_C'"));

	if (StartUIClass.Succeeded())
		mStartUIClass = StartUIClass.Class;
}

void AStartGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void AStartGameModeBase::InitGameState()
{
	Super::InitGameState();
}

void AStartGameModeBase::PostLogin(APlayerController* NewPlayer)
{
}


void AStartGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//UI 로드
	if (IsValid(mStartUIClass))
	{
		mStartWidget = CreateWidget<UStartWidget>(GetWorld(), mStartUIClass);

		if (IsValid(mStartWidget))
			mStartWidget->AddToViewport();

		APlayerController* RPGPlayerController = GetWorld()->GetFirstPlayerController();

		RPGPlayerController->SetShowMouseCursor(true);

		FInputModeUIOnly	input;
		RPGPlayerController->SetInputMode(input);

	}
}

void AStartGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
