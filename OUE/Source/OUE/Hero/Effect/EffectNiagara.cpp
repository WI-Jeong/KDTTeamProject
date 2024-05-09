// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/Effect/EffectNiagara.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

// Sets default values
AEffectNiagara::AEffectNiagara()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	SetRootComponent(NiagaraComponent);
}

// Called when the game starts or when spawned
void AEffectNiagara::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEffectNiagara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

