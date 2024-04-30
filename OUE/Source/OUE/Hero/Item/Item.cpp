// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Item/Item.h"
#include "Components/SphereComponent.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));

	SetRootComponent(SphereComponent);
	SkeletalMeshComponent->SetupAttachment(SphereComponent);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	SetItemData();
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MeshRotate();
}

void AItem::MeshRotate()
{
	const FRotator NewRotator = FRotator(0.f, ItemDataTableRow->RotateSpeed, 0.f);
	const FQuat NewQuat = NewRotator.Quaternion();
	SkeletalMeshComponent->AddRelativeRotation(NewQuat);
}

void AItem::SetItemData()
{
	if (FItemDataTableRowHandle.IsNull()) { return; }
	if (FItemDataTableRowHandle.RowName == NAME_None) { return; }

	ItemDataTableRow = FItemDataTableRowHandle.GetRow<FItemDataTableRow>(TEXT(""));
	if (ItemDataTableRow)
	{
		SkeletalMeshComponent->SetSkeletalMesh(ItemDataTableRow->USkeletalMesh);
	}
}

