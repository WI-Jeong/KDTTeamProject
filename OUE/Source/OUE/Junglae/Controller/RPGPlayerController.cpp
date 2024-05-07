// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/Controller/RPGPlayerController.h"
#include "Junglae/Subsystem/ChoSubsystem.h"

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