// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameModeBase.h"
#include "StartWidget.h"

AStartGameModeBase::AStartGameModeBase()
{
	//DefaultPawn nullptr
	DefaultPawnClass = nullptr;

	//UI 가져오기
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
	Super::PostLogin(NewPlayer);

	//마우스 커서 보이게
	NewPlayer->SetShowMouseCursor(true);

	FInputModeUIOnly	input;
	NewPlayer->SetInputMode(input);
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
	}
}

void AStartGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
