// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Gun/Shotgun.h"
#include "Hero/GameMode/HeroGameModeBase.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Hero/Gun/Bullet.h"

AShotgun::AShotgun()
{
	IsAutoFire = false;
}

void AShotgun::SpawnBullet(TSubclassOf<ABullet> InBullet)
{
	if (InBullet)
	{
		// 소켓 이름을 통해 현재 메시에서 소켓을 참조
		const USkeletalMeshSocket* Muzzle = SkeletalMeshComponent->GetSocketByName("Muzzle");
		ensure(Muzzle);
		if (Muzzle)
		{
			/*ABullet* SpawnBullet = GetWorld()->SpawnActor<ABullet>(InBullet, Muzzle->GetSocketTransform(SkeletalMeshComponent));*/
			AHeroGameModeBase* GameMode = Cast<AHeroGameModeBase>(GetWorld()->GetAuthGameMode());
			ensure(GameMode);
			ABullet* NewBullet = GameMode->GetBulletPool().New<ABullet>(Muzzle->GetSocketTransform(SkeletalMeshComponent),
				[this](ABullet* NewActor)
				{
					/*NewActor->SetProjectileData(ProjectileRow);*/
					NewActor->SetBullet(BulletTableRow);
				}
			, true, nullptr, nullptr);

			FTransform NewTransfrom = Muzzle->GetSocketTransform(SkeletalMeshComponent);
			FVector NewVector = NewTransfrom.GetLocation();
			NewTransfrom.SetLocation(NewVector);

			ABullet* NewBullet2 = GameMode->GetBulletPool().New<ABullet>(NewTransfrom,
				[this](ABullet* NewActor)
				{
					/*NewActor->SetProjectileData(ProjectileRow);*/
					NewActor->SetBullet(BulletTableRow);
				}
			, true, nullptr, nullptr);
		}
	}
}

