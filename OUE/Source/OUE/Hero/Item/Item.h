// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;

USTRUCT()
struct OUE_API FItemDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	USkeletalMesh* USkeletalMesh;

	UPROPERTY(EditAnywhere)
	float RotateSpeed = 10.f;
};

UCLASS()
class OUE_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* SkeletalMeshComponent;

protected:
	UPROPERTY(EditAnywhere)
	FDataTableRowHandle FItemDataTableRowHandle;
	FItemDataTableRow* ItemDataTableRow;

protected:
	void MeshRotate();

	void SetItemData();
};
