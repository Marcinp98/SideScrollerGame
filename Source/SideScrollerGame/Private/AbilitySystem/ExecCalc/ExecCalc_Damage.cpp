// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ExecCalc/ExecCalc_Damage.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/MainAttributeSet.h"
#include "MainGameplayTags.h"
#include "MainAbilityTypes.h"
#include "AbilitySystem/MainAbilitySystemLibrary.h"

struct MainDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Luck);

	MainDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, Armor, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, Luck, Source, false);
	}
};

static const MainDamageStatics& DamageStatics()
{
	static MainDamageStatics DStatics;
	return DStatics;
}

UExecCalc_Damage::UExecCalc_Damage()
{
	RelevantAttributesToCapture.Add(DamageStatics().ArmorDef);
	RelevantAttributesToCapture.Add(DamageStatics().LuckDef);
}

void UExecCalc_Damage::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& outExecutionOutput) const
{
	const UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();
	const UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();

	const AActor* SourceAvatar = SourceASC ? SourceASC->GetAvatarActor() : nullptr;
	const AActor* TargetAvatar = TargetASC ? TargetASC->GetAvatarActor() : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	// Get Damage Set by Caller Magnitude
	float Damage = 0.f;
	for (const TTuple<FGameplayTag, FGameplayTag>& Pair : FMainGameplayTags::Get().DamageTypesToResistances)
	{
		const float DamageTypeValue = Spec.GetSetByCallerMagnitude(Pair.Key);
		Damage += DamageTypeValue;
	}
	// Armor
	float TargetArmor = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorDef, EvaluationParameters, TargetArmor);
	TargetArmor = FMath::Max<float>(TargetArmor, 0.f);

	const float EffectiveArmor = TargetArmor;
	Damage /= (1 + EffectiveArmor / 100.f);

	//Critical hit chance (Luck)

	float SourceCriticalHitChance = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().LuckDef, EvaluationParameters, SourceCriticalHitChance);
	SourceCriticalHitChance = FMath::Max<float>(SourceCriticalHitChance, 0.f);

	const float EffectiveCriticalHitChance = SourceCriticalHitChance;
	const bool bCriticalHit = FMath::RandRange(1, 100) < EffectiveCriticalHitChance;

	FGameplayEffectContextHandle EffectContextHandle = Spec.GetContext();
	UMainAbilitySystemLibrary::SetIsCriticalHit(EffectContextHandle, bCriticalHit);

	Damage = bCriticalHit ? 2.f * Damage : Damage;

	const FGameplayModifierEvaluatedData EvaluatedData(UMainAttributeSet::GetIncomingDamageAttribute(), EGameplayModOp::Additive, Damage);
	outExecutionOutput.AddOutputModifier(EvaluatedData);
}
