// Fill out your copyright notice in the Description page of Project Settings.


#include "CSPlayerController.h"

ACSPlayerController::ACSPlayerController()
{
	PrimaryActorTick.bCanEverTick = true; 

	bShowMouseCursor = true;
}

void ACSPlayerController::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	FInputModeGameAndUI InputMode; 

	SetInputMode(InputMode);
}

void ACSPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ACSPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ACSPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void ACSPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
}

void ACSPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult	result;

	bool Collision = GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECollisionChannel::ECC_GameTraceChannel5,
		false, result);

	if (Collision)
	{
		USkeletalMeshComponent* MeshCom = nullptr;

		if (IsValid(mCursorPickActor) && mCursorPickActor != result.GetActor())
		{

			MeshCom = mCursorPickActor->GetComponentByClass<USkeletalMeshComponent>();


			if (IsValid(MeshCom))
			{
				MeshCom->SetRenderCustomDepth(false);
			}
		}

		mCursorPickActor = result.GetActor();

		MeshCom = mCursorPickActor->GetComponentByClass<USkeletalMeshComponent>();

		if (IsValid(MeshCom))
		{
			MeshCom->SetRenderCustomDepth(true);
		}
	}

	else if (IsValid(mCursorPickActor))
	{

		USkeletalMeshComponent* MeshCom = mCursorPickActor->GetComponentByClass<USkeletalMeshComponent>();


		if (IsValid(MeshCom))
		{
			MeshCom->SetRenderCustomDepth(false);
		}
 
		mCursorPickActor = nullptr;
	}

}

void ACSPlayerController::ChangePickOutLine(int32 StencilValue)
{
    UStaticMeshComponent* StaticMesh =
        mCursorPickActor->GetComponentByClass<UStaticMeshComponent>();

    if (IsValid(StaticMesh))
    {
        StaticMesh->SetCustomDepthStencilValue(StencilValue);
    }

    USkeletalMeshComponent* SkeletalMesh =
        mCursorPickActor->GetComponentByClass<USkeletalMeshComponent>();

    if (IsValid(SkeletalMesh))
    {
        SkeletalMesh->SetCustomDepthStencilValue(StencilValue);
    }
}
