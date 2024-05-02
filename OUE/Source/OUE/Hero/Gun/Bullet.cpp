// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Gun/Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Hero/GameMode/HeroGameModeBase.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetCollisionProfileName("HeroBullet");
	SetRootComponent(SphereComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SphereComponent);

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));

	//ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = InitialSpeed;
	ProjectileMovement->MaxSpeed = MaxSpeed;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	//프로젝타일 무브먼트 컴포넌트에 발사체를 자체로 딜리트 하는가?

	// Die after 3 seconds by default
	//InitialLifeSpan = 0;

	//OnActorHit.AddDynamic(this, &ThisClass::OnActorHitFunction);
}

void ABullet::SetBullet(FBulletTableRow* InTableRow)
{
	GetWorld()->GetTimerManager().ClearTimer(InitialLifeSpanTimer);

	if (InTableRow->InitialLifeSpan == 0.f)
	{
		ensure(false);
		return;
	}
	auto TimerDelegate = [this]()
		{
			GetWorld()->GetTimerManager().ClearTimer(InitialLifeSpanTimer);

			AHeroGameModeBase* GameMode = Cast<AHeroGameModeBase>(GetWorld()->GetAuthGameMode());
			ensure(GameMode);
			GameMode->GetBulletPool().Delete(this);
		};

	GetWorld()->GetTimerManager().SetTimer(InitialLifeSpanTimer, TimerDelegate, InTableRow->InitialLifeSpan, false);

	StaticMeshComponent->SetStaticMesh(InTableRow->StaticMesh);

	ProjectileMovement->Velocity = FVector(1.f, 0.f, 0.f);
	ProjectileMovement->MaxSpeed = InTableRow->BulletSpeed;
	ProjectileMovement->InitialSpeed = InTableRow->BulletSpeed;
	ProjectileMovement->ProjectileGravityScale = InTableRow->BulletGravityScale;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

