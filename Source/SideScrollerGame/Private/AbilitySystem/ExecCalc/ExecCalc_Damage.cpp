// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ExecCalc/ExecCalc_Damage.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/MainAttributeSet.h"
#include "MainGameplayTags.h"
#include "MainAbilityTypes.h"
#include "AbilitySystem/MainAbilitySystemLibrary.h"

struct MainDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(FireResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(LightningResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(ColdResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(ArcaneResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(HolyResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DarknessResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(SlashResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(PierceResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(BluntResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Luck);

	MainDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, FireResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, LightningResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, ColdResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, ArcaneResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, HolyResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, DarknessResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, SlashResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, PierceResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributeSet, BluntResistance, Target, false);
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
	RelevantAttributesToCapture.Add(DamageStatics().LuckDef);

	RelevantAttributesToCapture.Add(DamageStatics().FireResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().LightningResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().ColdResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().ArcaneResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().HolyResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().DarknessResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().SlashResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().PierceResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().BluntResistanceDef);
}

void UExecCalc_Damage::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& outExecutionOutput) const
{
	TMap<FGameplayTag, FGameplayEffectAttributeCaptureDefinition> TagsToCaptureDefs;
	const FMainGameplayTags& Tags = FMainGameplayTags::Get();

	TagsToCaptureDefs.Add(Tags.Attributes_Primary_Luck, DamageStatics().LuckDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Fire, DamageStatics().FireResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Lightning, DamageStatics().LightningResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Cold, DamageStatics().ColdResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Arcane, DamageStatics().ArcaneResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Holy, DamageStatics().HolyResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Darkness, DamageStatics().DarknessResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Slash, DamageStatics().SlashResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Pierce, DamageStatics().PierceResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Blunt, DamageStatics().BluntResistanceDef);


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
		const FGameplayTag DamageTypeTag = Pair.Key;
		const FGameplayTag ResistanceTag = Pair.Value;

		checkf(TagsToCaptureDefs.Contains(ResistanceTag), TEXT("TagsToCaptureDefs doesn't contain Tag: [%s] in ExecCalc_Damage"), *ResistanceTag.ToString());
		const FGameplayEffectAttributeCaptureDefinition CaptureDef = TagsToCaptureDefs[ResistanceTag];
		
		float DamageTypeValue = Spec.GetSetByCallerMagnitude(Pair.Key);

		float Resistance = 0.f;
		ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(CaptureDef, EvaluationParameters, Resistance);
		Resistance = FMath::Clamp(Resistance, 0.f, 100.f);

		DamageTypeValue *= (100.f - Resistance) / 100.f;
		Damage += DamageTypeValue;
	}

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
