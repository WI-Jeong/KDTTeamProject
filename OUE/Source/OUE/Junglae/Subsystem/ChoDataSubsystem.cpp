// Fill out your copyright notice in the Description page of Project Settings.


#include "Junglae/Subsystem/ChoDataSubsystem.h"
#include "Junglae/ChoItem/ChoItemData.h"

UChoDataSubsystem::UChoDataSubsystem()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> Asset{ TEXT("/Script/Engine.DataTable'/Game/Junglae/ChoInventory/DT_ChoItem.DT_ChoItem'") };
	ensure(Asset.Object);
	ItemDataTable = Asset.Object;
}

const FChoItemData* UChoDataSubsystem::FindChoItem(const FName& Inkey)
{
	FChoItemData* Row = ItemDataTable->FindRow<FChoItemData>(Inkey, TEXT(""));
	ensure(Row);
	return Row;
}
