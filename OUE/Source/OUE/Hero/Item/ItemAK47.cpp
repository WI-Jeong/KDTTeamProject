// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Item/ItemAK47.h"
#include "ItemAK47.h"
#include "Hero/Character/HeroCharacter.h"

void AItemAK47::OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnCollisionBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	UE_LOG(LogTemp, Warning, TEXT("ItemAK47"));

	AHeroCharacter* HeroCharacter = Cast<AHeroCharacter>(OtherActor);
	ensure(HeroCharacter);
	if (HeroCharacter == nullptr) { return; }

	HeroCharacter->SetWeaponData(TEXT("AK47"));
	HeroCharacter->SpawnGun(HeroCharacter->GetWeaponDataTableRow()->Gun);
}
