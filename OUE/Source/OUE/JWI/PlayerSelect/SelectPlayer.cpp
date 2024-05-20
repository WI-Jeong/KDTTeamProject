// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectPlayer.h"
#include "../../CharacterSelectGameMode.h"

// Sets default values
ASelectPlayer::ASelectPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASelectPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASelectPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASelectPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASelectPlayer::Pick()
{
	// 먼저 GameMode를 얻어온다.
	ACharacterSelectGameMode* GameMode = GetWorld()->GetAuthGameMode<ACharacterSelectGameMode>();

	if (IsValid(mCursorPickActor))
	{
		mSelectActor = mCursorPickActor;

		//캐릭터가 선택되면 버튼 활성화
		GameMode->EnableStartButton(true);
	}

	else
	{
		//캐릭터가 선택안되면 버튼 비활성화 
		GameMode->EnableStartButton(false);
	}

}

