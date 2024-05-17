// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Item/Item.h"
#include "Components/SphereComponent.h"
#include "Hero/Character/HeroCharacter.h"
#include "Hero/Gun/Gun.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));

	SetRootComponent(SphereComponent);
	SkeletalMeshComponent->SetupAttachment(SphereComponent);

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnCollisionBeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnComponentEndOverlap);

	//SphereComponent->SetSphereRadius(100.f);
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
		WeaponName = ItemDataTableRow->WeaponName;
	}
}

void AItem::OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnCollisionBeginOverlap"));

	AHeroCharacter* HeroCharacter = Cast<AHeroCharacter>(OtherActor);
	//ensure(HeroCharacter);
	if (HeroCharacter == nullptr) { return; }

	//ChangeGun(HeroCharacter);

	HeroCharacter->OverlapItem = this;
}

void AItem::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AHeroCharacter* HeroCharacter = Cast<AHeroCharacter>(OtherActor);
	if (HeroCharacter == nullptr) { return; }

	HeroCharacter->OverlapItem = nullptr;
}

void AItem::ChangeGun(AHeroCharacter* InHeroCharacter)
{
	if (InHeroCharacter == nullptr) { return; }

	if (InHeroCharacter->GetSpawnedGun())
	{
		InHeroCharacter->GetSpawnedGun()->Destroy();
	}

	InHeroCharacter->SetWeaponData(WeaponName);
	InHeroCharacter->SpawnGun(InHeroCharacter->GetWeaponDataTableRow()->Gun);
}

