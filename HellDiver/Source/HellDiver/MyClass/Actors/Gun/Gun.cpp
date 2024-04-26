// Fill out your copyright notice in the Description page of Project Settings.


#include "MyClass/Actors/Gun/Gun.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ChildActorComponent.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	SkeletalMeshComponent->SetupAttachment(RootComponent);

	ChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActorComponent"));
	ChildActorComponent->SetupAttachment(SkeletalMeshComponent);
	//SetCameraLocation();
}
AActor* AGun::GetCameraActor()
{
	return ChildActorComponent->GetChildActor();
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsAutoFire)
	{
		if (bIsTriggered)
		{
			Fire();
		}
	}
	else if (bIsAutoFire == false)
	{
		if (bIsTriggered)
		{
			Fire();
			bIsTriggered = false;
		}
	}
}

void AGun::ChangeFireMode()
{
	SetAutoFireOnOff();
}

void AGun::SetAutoFireOnOff()
{
	if (bIsAutoFire == true)
	{
		bIsAutoFire = false;
	}
	else
	{
		bIsAutoFire = true;
	}
}

bool AGun::GetAutoFireOnOff()
{
	return bIsAutoFire;
}

void AGun::Fire()
{
	bool bTimer = GetWorld()->GetTimerManager().IsTimerActive(FireTimerHandle);
	if (bTimer) { return; }

	ensure(FireDelay > 0.f);
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, FireDelay, false);


	//GetWorld()->SpawnActor<ABullet>(Bullet, GetActorLocation(), GetActorRotation());
	SpawnBullet(Bullet);
	
	if (FireSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}
}

void AGun::StartTrigger()
{
	bIsTriggered = true;
}

void AGun::StopTrigger()
{
	bIsTriggered = false;
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

