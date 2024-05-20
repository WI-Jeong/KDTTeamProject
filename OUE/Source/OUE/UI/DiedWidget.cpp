// Fill out your copyright notice in the Description page of Project Settings.


#include "DiedWidget.h"

void UDiedWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UDiedWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UDiedWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UDiedWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UDiedWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}



FReply UDiedWidget::NativeOnKeyChar(const FGeometry& InGeometry, const FCharacterEvent& InCharEvent)
{
	FReply Reply = Super::NativeOnKeyChar(InGeometry, InCharEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	FReply Reply = Super::NativeOnPreviewKeyDown(InGeometry, InKeyEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	FReply Reply = Super::NativeOnKeyDown(InGeometry, InKeyEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	FReply Reply = Super::NativeOnKeyUp(InGeometry, InKeyEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseMove(InGeometry, InMouseEvent);

	return Reply;
}

void UDiedWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
}

void UDiedWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
}

FReply UDiedWidget::NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseWheel(InGeometry, InMouseEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDoubleClick(InGeometry, InMouseEvent);

	return Reply;
}

void UDiedWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent,
		OutOperation);
}

void UDiedWidget::NativeOnDragEnter(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragEnter(InGeometry, InDragDropEvent,
		InOperation);
}

void UDiedWidget::NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragLeave(InDragDropEvent,
		InOperation);
}

bool UDiedWidget::NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	bool Reply = Super::NativeOnDragOver(InGeometry, InDragDropEvent,
		InOperation);

	return Reply;
}

bool UDiedWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	bool Reply = Super::NativeOnDrop(InGeometry, InDragDropEvent,
		InOperation);

	return Reply;
}

void UDiedWidget::NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragCancelled(InDragDropEvent,
		InOperation);
}

FReply UDiedWidget::NativeOnTouchGesture(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
	FReply Reply = Super::NativeOnTouchGesture(InGeometry,
		InGestureEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnTouchStarted(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
	FReply Reply = Super::NativeOnTouchStarted(InGeometry,
		InGestureEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnTouchMoved(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
	FReply Reply = Super::NativeOnTouchMoved(InGeometry,
		InGestureEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
	FReply Reply = Super::NativeOnTouchEnded(InGeometry,
		InGestureEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnMotionDetected(const FGeometry& InGeometry, const FMotionEvent& InMotionEvent)
{
	FReply Reply = Super::NativeOnMotionDetected(InGeometry,
		InMotionEvent);

	return Reply;
}

FReply UDiedWidget::NativeOnTouchForceChanged(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	FReply Reply = Super::NativeOnTouchForceChanged(MyGeometry,
		TouchEvent);

	return Reply;
}

void UDiedWidget::ReStartButtonClick()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("BaseLevel"));
}

void UDiedWidget::ReStartButtonHovered()
{
	PlayAnimation(ReStartButtonScaleAnim);
}

void UDiedWidget::ReStartButtonUnHovered()
{
	PlayAnimation(ReStartButtonScaleAnim, 0.f, 1, EUMGSequencePlayMode::Reverse);
}

void UDiedWidget::ExitButtonClick()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(),
		EQuitPreference::Quit, true);
}

void UDiedWidget::ExitButtonHovered()
{
	UWidgetBlueprintGeneratedClass* WidgetClass = GetWidgetTreeOwningClass();

	for (int32 i = 0; i < WidgetClass->Animations.Num(); ++i)
	{
		FString Name = WidgetClass->Animations[i]->GetName();

		if (Name == TEXT("ExitButtonScaleAnim_INST")) //이름은 로그 한번 찍어보면 _INST 붙는거 알 수 있
		{
			PlayAnimation(WidgetClass->Animations[i]);
			break;
		}
	}
}

void UDiedWidget::ExitButtonUnHovered()
{
	UWidgetBlueprintGeneratedClass* WidgetClass = GetWidgetTreeOwningClass();

	for (int32 i = 0; i < WidgetClass->Animations.Num(); ++i)
	{
		FString Name = WidgetClass->Animations[i]->GetName();

		if (Name == TEXT("ExitButtonScaleAnim_INST"))
		{
			PlayAnimation(WidgetClass->Animations[i], 0.f, 1, EUMGSequencePlayMode::Reverse);
			break;
		}
	}
}
