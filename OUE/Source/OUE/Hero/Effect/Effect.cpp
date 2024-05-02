// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Effect/Effect.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "Hero/GameMode/HeroGameModeBase.h"

// Sets default values
AEffect::AEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));

	{
		ConstructorHelpers::FObjectFinder<UParticleSystem> Finder(TEXT("/Script/Engine.ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
		ensure(Finder.Object);
		ParticleSystem = Finder.Object;
	}
}

// Called when the game starts or when spawned
void AEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEffect::SetEffect()
{
	GetWorld()->GetTimerManager().ClearTimer(InitialLifeSpanTimer);

	if (EffectInitialLifeSpan == 0.f)
	{
		ensure(false);
		return;
	}
	auto TimerDelegate = [this]()
		{
			GetWorld()->GetTimerManager().ClearTimer(InitialLifeSpanTimer);

			AHeroGameModeBase* GameMode = Cast<AHeroGameModeBase>(GetWorld()->GetAuthGameMode());
			ensure(GameMode);
			GameMode->GetEffectPool().Delete(this);
		};

	GetWorld()->GetTimerManager().SetTimer(InitialLifeSpanTimer, TimerDelegate, EffectInitialLifeSpan, false);

	ParticleSystemComponent->SetTemplate(ParticleSystem);
}

