// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/AnimNotify/FootSoundAnimNotify.h"
#include "Hero/Character/HeroCharacter.h"
#include "Components/AudioComponent.h"

void UFootSoundAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	AActor* Actor = MeshComp->GetOwner();
	ensure(Actor);

	AHeroCharacter* HeroCharacter = Cast<AHeroCharacter>(Actor);
	ensure(HeroCharacter);
	if (HeroCharacter)
	{
		HeroCharacter->AudioComponent->Play();
	}
}
