// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero/AnimNotify/EnemyAttackAnimNotify.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void UEnemyAttackAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	AActor* Actor = MeshComp->GetOwner();
	const FVector ActorLocation = Actor->GetActorLocation();
	const FVector ForwardVector = Actor->GetActorForwardVector();
	const FVector End = ActorLocation + ForwardVector * 200.0;

	const float WeaponRadius = 200.f;
	const float Damage = 1.f;

	TArray<AActor*> IgnoreActors; IgnoreActors.Add(Actor);
	TArray<FHitResult> HitResults;

	ETraceTypeQuery TraceTypeQuery = ETraceTypeQuery::TraceTypeQuery1; // Trace HeroPlayer

	UKismetSystemLibrary::CapsuleTraceMulti(Actor, ActorLocation, End,
		WeaponRadius, 0.f, TraceTypeQuery, false, IgnoreActors,
		EDrawDebugTrace::ForDuration, HitResults, true);

	for (auto& It : HitResults)
	{
		AActor* HitActor = It.GetActor();

		UGameplayStatics::ApplyDamage(HitActor, Damage, nullptr, Actor, nullptr);
	}
}
