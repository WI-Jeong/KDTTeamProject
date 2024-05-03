// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/AnimNotify/ReloadAnimNotify.h"
#include "ReloadAnimNotify.h"
#include "Hero/Character/HeroCharacter.h"
#include "Hero/Gun/Gun.h"

void UReloadAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	AActor* Actor = MeshComp->GetOwner();
	ensure(Actor);

	AHeroCharacter* HeroCharacter = Cast<AHeroCharacter>(Actor);
	ensure(HeroCharacter);
	if (HeroCharacter)
	{
		HeroCharacter->GetSpawnedGun()->Reload();
		HeroCharacter->SetIsReloading(false);
	}
}
