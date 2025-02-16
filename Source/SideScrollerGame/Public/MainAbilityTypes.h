#pragma once

#include "GameplayEffectTypes.h"
#include "MainAbilityTypes.generated.h"

USTRUCT(BlueprintType)
struct FMainGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()
public:

	bool IsCriticalHit() const { return bIsCriticalHit; }

	void SetIsCriticalHit(bool bInIsCriticalHit) { bIsCriticalHit = bInIsCriticalHit; }

	/** Returns the actual struct used for serialization, subclasses must override this! */
	virtual UScriptStruct* GetScriptStruct() const
	{
		return StaticStruct();
	}

	/** Creates a copy of this context, used to duplicate for later modifications */
	virtual FMainGameplayEffectContext* Duplicate() const
	{
		FMainGameplayEffectContext* NewContext = new FMainGameplayEffectContext();
		*NewContext = *this;
		if (GetHitResult())
		{
			// Does a deep copy of the hit result
			NewContext->AddHitResult(*GetHitResult(), true);
		}
		return NewContext;
	}


	/** Custom serialization, subclasses must override this */
	virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess) override;

protected:

	UPROPERTY()
	bool bIsCriticalHit = false;
};

template<>
struct TStructOpsTypeTraits<FMainGameplayEffectContext> : TStructOpsTypeTraitsBase2<FMainGameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true
	};
};