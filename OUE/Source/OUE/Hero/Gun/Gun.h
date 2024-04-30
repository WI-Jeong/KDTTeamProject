// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

class UChildActorComponent;
struct FBulletTableRow;
class ABullet;

UCLASS()
class OUE_API AGun : public AActor
{
	GENERATED_BODY()

	//�� ���̷�Ż �޽������ͼ� �ѱ� ���� ã������ �ű⼭ ��ȯ�ϵ���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SkeletalMeshComponent;
	
	UPROPERTY(EditAnywhere)
	UChildActorComponent* ChildActorComponent;

public:	
	// Sets default values for this actor's properties
	AGun();

	UChildActorComponent* GetChildActorComponent() { return ChildActorComponent; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	FTimerHandle FireTimerHandle;
	float FireDelay = 0.2f;
	bool IsTriggered = false;
	bool IsAutoFire = true;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun, meta = (AllowPrivateAccess = "true"))
	//TSubclassOf<class ABullet> Bullet;

	void Fire();

public:
	void PullTrigger();
	void ReleaseTrigger();
	void SpawnBullet(TSubclassOf<ABullet> InBullet);
	void ChangeFireMode();

protected:
	UPROPERTY(EditAnywhere)
	FDataTableRowHandle BulletDataTableRowHandle;

	FBulletTableRow* BulletTableRow;

};
