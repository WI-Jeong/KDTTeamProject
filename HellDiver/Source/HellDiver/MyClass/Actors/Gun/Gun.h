// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyClass/Actors/Gun/Bullet.h"
#include "Math/Vector.h"
#include "Gun.generated.h"

class UChildActorComponent;

UCLASS()
class HELLDIVER_API AGun : public AActor
{
	GENERATED_BODY()
	
	/** Gun */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ABullet> Bullet;

	//총 스켈레탈 메쉬가져와서 총구 소켓 찾은다음 거기서 소환하도록
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditAnywhere)
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere)
	UChildActorComponent* ChildActorComponent;
	//FVector CameraLocation;

public:	
	// Sets default values for this actor's properties
	AGun();

	AActor* GetCameraActor();
	//FVector GetCameraLocation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	FTimerHandle FireTimerHandle;

	UPROPERTY(EditAnywhere)
	float FireDelay = 0.1f;

	bool bIsAutoFire = false;

	bool bIsTriggered = false;
public:

	void ChangeFireMode();//인터페이스로 하면 좋을듯

	void SetAutoFireOnOff();
	bool GetAutoFireOnOff();

	void Fire();

	void StartTrigger();
	void StopTrigger();

protected:
	void SpawnBullet(TSubclassOf<ABullet> InBullet);

	//void SetCameraLocation();
};
