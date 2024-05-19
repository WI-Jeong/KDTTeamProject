// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSelectWidget.h"

void UCharacterSelectWidget::NativeConstruct()
{
	Super::NativeConstruct();

	mGameStartButton = Cast<UButton>(GetWidgetFromName(TEXT("GameStartButton")));
	mGameStartButton->OnClicked.AddDynamic(this, &UCharacterSelectWidget::StartButtonClick);
}

void UCharacterSelectWidget::EnableStartButton(bool Enable)
{
	mGameStartButton->SetIsEnabled(Enable);
}

void UCharacterSelectWidget::StartButtonClick()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("BaseLevel"));
}
