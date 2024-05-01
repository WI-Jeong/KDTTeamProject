// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Item/ItemNoWeapon.h"
#include "Hero/Character/HeroCharacter.h"

void AItemNoWeapon::OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnCollisionBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	UE_LOG(LogTemp, Warning, TEXT("NoWeapon"));

	AHeroCharacter* HeroCharacter = Cast<AHeroCharacter>(OtherActor);
	ensure(HeroCharacter);
	if (HeroCharacter == nullptr) { return; }

	HeroCharacter->SetWeaponData(TEXT("NoWeapon"));
	//HeroCharacter->SpawnGun(HeroCharacter->GetWeaponDataTableRow()->Gun);
}
