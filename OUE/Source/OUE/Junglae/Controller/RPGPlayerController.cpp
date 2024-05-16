// Fill out your copyright notice in the Description page of Project Settings.


// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/Controller/RPGPlayerController.h"
#include "Junglae/Subsystem/ChoSubsystem.h"

ARPGPlayerController::ARPGPlayerController()
{
    // 블루프린트 클래스를 받아온다
    static ConstructorHelpers::FClassFinder<UMainWidget> MainHUDWidgetAsset(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/JWI/UI/UI_Main.UI_Main_C'"));

    // TSubclassOf 템플릿 클래스 객체에 블루프린트 클래스를 넣어준다
    if (MainHUDWidgetAsset.Succeeded())
        MainHUDWidgetClass = MainHUDWidgetAsset.Class;
}

void ARPGPlayerController::OnPossess(APawn* PawnToPossess)
{
    UInventorySubsystem* InventorySubsystem =
        ULocalPlayer::GetSubsystem<UInventorySubsystem>(GetLocalPlayer());
    InventorySubsystem->MakeInventory();

    Super::OnPossess(PawnToPossess);  // 기본 동작 유지

    if (PawnToPossess)
    {
        // 인벤토리 관련 로직 추가
        UE_LOG(LogTemp, Log, TEXT("RPGPlayerController now possesses: %s"), *PawnToPossess->GetName());

        // 예: 인벤토리 초기화, 기타 필요한 작업
    }
}

void ARPGPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (IsValid(MainHUDWidgetClass))
    {
        MainWidget = Cast<UMainWidget>(CreateWidget(GetWorld(), MainHUDWidgetClass));

        if (IsValid(MainWidget))
        {
            // 위젯을 뷰포트에 띄우는 함수
            MainWidget->AddToViewport();
        }
    }
}
