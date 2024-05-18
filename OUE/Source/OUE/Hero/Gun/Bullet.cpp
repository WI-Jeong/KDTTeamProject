// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Gun/Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Hero/GameMode/HeroGameModeBase.h"
#include "Hero/Enemy/Enemy.h" //나중에 enemy로 이름 수정하자
#include "Kismet/GameplayStatics.h"
#include "Hero/Effect/Effect.h"
#include "Particles/ParticleSystemComponent.h"
#include "NiagaraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/AudioComponent.h"

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

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	NiagaraComponent->SetupAttachment(RootComponent);
	NiagaraComponent->SetForceSolo(true);

	//ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = InitialSpeed;
	ProjectileMovement->MaxSpeed = MaxSpeed;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;

	OnActorHit.AddDynamic(this, &ThisClass::OnActorHitFunction);

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	AudioComponent->SetupAttachment(RootComponent);
}

void ABullet::SetBullet(FBulletTableRow* InTableRow)
{
	//UNiagaraSystem* temp = NiagaraComponent->GetAsset();
	//NiagaraComponent->SetAsset(nullptr);
	//NiagaraComponent->Activate(false);

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

	//ParticleSystemComponent->Activate();
	//NiagaraComponent->Activate();
	//NiagaraComponent->SetAsset(InTableRow->);
	NiagaraComponent->ReinitializeSystem();

	StaticMeshComponent->SetRelativeScale3D(InTableRow->StaticMeshSize);

	ProjectileMovement->bShouldBounce = InTableRow->bShouldBounce;

	Damage = InTableRow->Damage;

	bIsGrenade = InTableRow->bIsGrenade;

	ExplosionEffect = InTableRow->ExplosionEffect;

	AudioComponent->SetSound(InTableRow->FireSoundBase);
	AudioComponent->Play();
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
	ACharacter * Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		if (Character->GetCapsuleComponent()->GetCollisionObjectType() == ECollisionChannel::ECC_Pawn)
		{
			SetActorEnableCollision(false); //<< 이걸 하면 왜 풀이 망가질까 //맵 문제 였음 삼인칭맵 액터 떨어지면 삭제하는것때문에	
		}

		if (bIsGrenade)
		{
			const TArray<AActor*>& IgnoreActors = TArray<AActor*>();
			UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, Hit.ImpactPoint, 100.f, nullptr, IgnoreActors);
			DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 100.f, 32, FColor::Blue);

			FTransform NewTransform = FTransform(Hit.Location);
			SpawnHitEffect(NewTransform);

			AudioComponent->Play();
		}
	}
	
	UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, nullptr);


	//SetActorHiddenInGame(true);

	//AEnemy* Enemy = Cast<AEnemy>(OtherActor);
	//if (IsValid(Enemy))
	//{
	//	UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, nullptr);

	//	SetActorHiddenInGame(true);

	//	/*FTransform NewTransform = FTransform(Hit.Location);
	//	SpawnHitEffect(NewTransform);*/
	//}

	//UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, nullptr); //나중에 하나없애야함
}

void ABullet::SpawnHitEffect(FTransform InTransform)
{
	AHeroGameModeBase* GameMode = Cast<AHeroGameModeBase>(GetWorld()->GetAuthGameMode());
	ensure(GameMode);
	AEffect* NewEffect = GameMode->GetEffectPool().New<AEffect>(InTransform,
		[this](AEffect* NewActor)
		{
			//NewActor->SetEffectInitialLifeSpan(3.f);
			NewActor->SetEffect(ExplosionEffect);
		}
	, true, nullptr, nullptr);
}

