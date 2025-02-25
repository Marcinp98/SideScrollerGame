
#include "Actor/EffectActorBase.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffect.h"

AEffectActorBase::AEffectActorBase()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AEffectActorBase::BeginPlay()
{
	Super::BeginPlay();
}

void AEffectActorBase::ApplyGameplayEffect(UAbilitySystemComponent* TargetAbility, const FAppliesGameplayEffect& Effect, bool& bApplied)
{
	if (!TargetAbility || !Effect.FXClass) return;

	FGameplayEffectContextHandle CtxHandle = TargetAbility->MakeEffectContext();
	CtxHandle.AddSourceObject(this);

	FGameplayEffectSpecHandle EffectSpec = TargetAbility->MakeOutgoingSpec(Effect.FXClass, ActorLevel, CtxHandle);
	if (!EffectSpec.IsValid()) return;

	FActiveGameplayEffectHandle ActiveEffectHandle = TargetAbility->ApplyGameplayEffectSpecToSelf(*EffectSpec.Data.Get());

	const bool bIsInfinite = EffectSpec.Data->Def->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if (bIsInfinite && Effect.RemovalPolicy == ERemovalPolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandles.Add(TargetAbility, FActiveEffectHandle(Effect, ActiveEffectHandle));
	}

	bApplied = true;
}

void AEffectActorBase::OnEffectBeginOverlap(AActor* TargetActor)
{
	IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(TargetActor);
	if (!AbilityInterface) return;

	UAbilitySystemComponent* TargetAbility = AbilityInterface->GetAbilitySystemComponent();
	if (!TargetAbility) return;

	if (TargetActor->ActorHasTag(FName("Enemy")) && !bApplyEffectsToEnemies) return;

	bool bApplied = false;

	for (const auto& Effect : AppliesGameplayEffects)
	{
		if (Effect.ApplyPolicy != EApplyPolicy::ApplyOnBeginOverlap) continue;

		ApplyGameplayEffect(TargetAbility, Effect, bApplied);
	}

	if (bDestroyAfterApplyingEffect && bApplied)
	{
		Destroy();
	}
}

void AEffectActorBase::OnEffectEndOverlap(AActor* TargetActor)
{
	IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(TargetActor);
	if (!AbilityInterface) return;

	UAbilitySystemComponent* TargetAbility = AbilityInterface->GetAbilitySystemComponent();
	if (!TargetAbility) return;

	if (TargetActor->ActorHasTag(FName("Enemy")) && !bApplyEffectsToEnemies) return;

	TArray<FActiveEffectHandle> ToRemove;
	ActiveEffectHandles.MultiFind(TargetAbility, ToRemove);

	for (const auto& ActiveEffect : ToRemove)
	{
		if (ActiveEffect.AppliedEffect.RemovalPolicy != ERemovalPolicy::RemoveOnEndOverlap) continue;

		TargetAbility->RemoveActiveGameplayEffect(ActiveEffect.Handle, 1);
		ActiveEffectHandles.Remove(TargetAbility, ActiveEffect);
	}

	if (bDestroyAfterApplyingEffect && ToRemove.Num() > 0)
	{
		Destroy();
	}
}
