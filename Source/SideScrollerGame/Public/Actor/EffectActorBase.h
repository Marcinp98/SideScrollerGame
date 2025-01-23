#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "GameplayEffect.h"
#include "EffectActorBase.generated.h"


class UAbilitySystemComponent;

UENUM(BlueprintType)
enum class EApplyPolicy : uint8
{
	DoNotApply,
	ApplyOnBeginOverlap,
	ApplyOnEndOverlap
};

UENUM(BlueprintType)
enum class ERemovalPolicy : uint8
{
	DoNotRemove,
	RemoveOnEndOverlap
};

USTRUCT(BlueprintType)
struct FAppliesGameplayEffect
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AppliesEffect")
	TSubclassOf<UGameplayEffect> FXClass = UGameplayEffect::StaticClass();

	UPROPERTY(EditAnywhere, Category = "AppliesEffect")
	EApplyPolicy ApplyPolicy = EApplyPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, Category = "AppliesEffect")
	ERemovalPolicy RemovalPolicy = ERemovalPolicy::DoNotRemove;

	bool operator==(const FAppliesGameplayEffect& Other) const
	{
		return FXClass == Other.FXClass && ApplyPolicy == Other.ApplyPolicy && RemovalPolicy == Other.RemovalPolicy;
	}
};

struct FActiveEffectHandle
{
	FActiveEffectHandle(const FAppliesGameplayEffect& InEffect, FActiveGameplayEffectHandle InHandle)
		: AppliedEffect(InEffect), Handle(InHandle) {}

	const FAppliesGameplayEffect AppliedEffect;
	FActiveGameplayEffectHandle Handle;

	bool operator==(const FActiveEffectHandle& Other) const
	{
		return Handle == Other.Handle && AppliedEffect == Other.AppliedEffect;
	}
};

UCLASS()
class SIDESCROLLERGAME_API AEffectActorBase : public AActor
{
	GENERATED_BODY()

public:
	AEffectActorBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameplayEffect")
	bool bDestroyAfterApplyingEffect = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameplayEffect")
	TArray<FAppliesGameplayEffect> AppliesGameplayEffects;

	TMultiMap<UAbilitySystemComponent*, FActiveEffectHandle> ActiveEffectHandles;

	void ApplyGameplayEffect(UAbilitySystemComponent* TargetAbility, const FAppliesGameplayEffect& Effect, bool& bApplied);

	UFUNCTION(BlueprintCallable)
	void OnEffectBeginOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEffectEndOverlap(AActor* TargetActor);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameplayEffect")
	float ActorLevel = 1.f;
};
