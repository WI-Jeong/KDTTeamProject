#include "Junglae/ChoItem/ChoItem.h"
#include "Hero/Character/HeroCharacter.h"
#include "Junglae/UI/InventoryUserWidget.h"
#include "Junglae/UI/InventoryItemUserWidget.h"

void UChoItem_Potion::UseItem(ARPGPlayerController* Controller)
{
	Cast<AHeroCharacter>(Controller->GetPawn())->Heal(20.f);
}

void UChoItem_Gun::UseItem(ARPGPlayerController* Controller, UInventoryUserWidget* InInventoryUserWidget, UTexture2D* Texture)
{
	//웨폰 슬롯에 장착
	InInventoryUserWidget->Weapon->ItemImage->SetBrushFromTexture(Texture, false);
}
