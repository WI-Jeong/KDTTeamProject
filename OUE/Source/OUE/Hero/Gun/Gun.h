// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

class UChildActorComponent;
struct FBulletTableRow;
class ABullet;
class AEffect;

USTRUCT()
struct FGunDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float FireDelay = 0.2f;

	UPROPERTY(EditAnywhere)
	int MaxAmmo = 30;

	UPROPERTY(EditAnywhere)
	UParticleSystem* FireEffect;

	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* FireEffectNiagara;
};

UCLASS()
class OUE_API AGun : public AActor
{
	GENERATED_BODY()

protected:
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
	
	int MaxAmmo = 30;
	int CurrentAmmo = MaxAmmo;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun, meta = (AllowPrivateAccess = "true"))
	//TSubclassOf<class ABullet> Bullet;

	virtual void Fire();

public:
	void PullTrigger();
	void ReleaseTrigger();

	virtual void ChangeFireMode();

	void Reload();

protected:
	void SetGunData();

	virtual void SpawnBullet(TSubclassOf<ABullet> InBullet);

	void SpawnEffect();

protected:
	UPROPERTY(EditAnywhere)
	FDataTableRowHandle BulletDataTableRowHandle;

	FBulletTableRow* BulletTableRow;

	UPROPERTY(EditAnywhere)
	FDataTableRowHandle GunDataTableRowHandle;

	FGunDataTableRow* GunDataTableRow;
};
