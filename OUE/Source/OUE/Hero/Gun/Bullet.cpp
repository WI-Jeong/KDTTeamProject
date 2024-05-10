// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Gun/Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Hero/GameMode/HeroGameModeBase.h"
#include "OUECharacter.h" //나중에 enemy로 이름 수정하자
#include "Kismet/GameplayStatics.h"
#include "Hero/Effect/Effect.h"
#include "Particles/ParticleSystemComponent.h"

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
	StaticMeshComponent->SetCollisionProfileName("HeroBullet");

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	ParticleSystemComponent->SetupAttachment(RootComponent);

	//ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = InitialSpeed;
	ProjectileMovement->MaxSpeed = MaxSpeed;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;

	OnActorHit.AddDynamic(this, &ThisClass::OnActorHitFunction);
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

	//StaticMeshComponent->SetStaticMesh(InTableRow->StaticMesh);
	//StaticMeshComponent->SetMaterial(0, InTableRow->Material);

	ProjectileMovement->Velocity = FVector(1.f, 0.f, 0.f);
	ProjectileMovement->MaxSpeed = InTableRow->BulletSpeed;
	ProjectileMovement->InitialSpeed = InTableRow->BulletSpeed;
	ProjectileMovement->ProjectileGravityScale = InTableRow->BulletGravityScale;

	ParticleSystemComponent->Activate();
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

void ABullet::OnActorHitFunction(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	SetActorEnableCollision(false); //<< 이걸 하면 왜 풀이 망가질까 //맵 문제 였음 삼인칭맵 액터 떨어지면 삭제하는것때문에	

	AOUECharacter* Enemy = Cast<AOUECharacter>(OtherActor);
	if (IsValid(Enemy))
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, nullptr);

		SetActorHiddenInGame(true);

		/*FTransform NewTransform = FTransform(Hit.Location);
		SpawnHitEffect(NewTransform);*/
	}

	UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, nullptr); //나중에 하나없애야함
}

void ABullet::SpawnHitEffect(FTransform InTransform)
{
	/*AHeroGameModeBase* GameMode = Cast<AHeroGameModeBase>(GetWorld()->GetAuthGameMode());
	ensure(GameMode);
	AEffect* NewEffect = GameMode->GetEffectPool().New<AEffect>(InTransform,
		[this](AEffect* NewActor)
		{
			NewActor->SetEffect(GunDataTableRow);
		}
	, true, nullptr, nullptr);*/
}

