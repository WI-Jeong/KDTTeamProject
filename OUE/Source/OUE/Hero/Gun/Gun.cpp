// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Gun/Gun.h"
#include "Hero/Gun/Bullet.h"
#include "Engine/SkeletalMeshSocket.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	SkeletalMeshComponent->SetupAttachment(RootComponent);

	//ī�޶� ���� ������ ���� �ڼ� �������۳�Ʈ
	ChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActorComponent"));
	ChildActorComponent->SetupAttachment(SkeletalMeshComponent);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGun::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsTriggered)
	{
		if (IsAutoFire)
		{
			Fire();
		}
		else
		{
			Fire();
			ReleaseTrigger();
		}
	}

}

void AGun::Fire()
{
	bool bTimer = GetWorld()->GetTimerManager().IsTimerActive(FireTimerHandle);
	if (bTimer) { return; }

	ensure(FireDelay > 0.f);
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, FireDelay, false);

	UE_LOG(LogTemp, Warning, TEXT("Fire"));

	SpawnBullet(Bullet);
}

void AGun::PullTrigger()
{
	if (IsTriggered == false)
	{
		IsTriggered = true;
	}
}

void AGun::ReleaseTrigger()
{
	IsTriggered = false;
}

void AGun::SpawnBullet(TSubclassOf<ABullet> InBullet)
{
	if (InBullet)
	{
		// 소켓 이름을 통해 현재 메시에서 소켓을 참조
		const USkeletalMeshSocket* Muzzle = SkeletalMeshComponent->GetSocketByName("Muzzle");

		if (Muzzle)
		{
			ABullet* SpawnBullet = GetWorld()->SpawnActor<ABullet>(InBullet, Muzzle->GetSocketTransform(SkeletalMeshComponent));
		}
	}
}

void AGun::ChangeFireMode()
{
	if (IsAutoFire)
	{
		IsAutoFire = false;
	}
	else
	{
		IsAutoFire = true;
	}
}

