#include "Junglae/ChoItem/ChoItem.h"
#include "Hero/Character/HeroCharacter.h"

void UChoItem_Potion::UseItem(ARPGPlayerController* Controller)
{
	Cast<AHeroCharacter>(Controller->GetPawn())->Heal(20.f);
}