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

			for (int i = 0; i < BulletCount; ++i)
			{
				FTransform NewTransfrom = Muzzle->GetSocketTransform(SkeletalMeshComponent);

				float RandomPitch = FMath::FRandRange(-SpreadRange, SpreadRange);
				float RandomYaw = FMath::FRandRange(-SpreadRange, SpreadRange);

				FQuat  NewQuat = NewTransfrom.GetRotation();
				FRotator NewRotator = NewQuat.Rotator();
				NewRotator = FRotator(NewRotator.Pitch + RandomPitch, NewRotator.Yaw + RandomYaw, NewRotator.Roll);
				
				NewTransfrom = FTransform(NewRotator, NewTransfrom.GetLocation());

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
}

