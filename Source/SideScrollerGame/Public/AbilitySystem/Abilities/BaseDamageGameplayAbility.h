// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BaseGameplayAbility.h"
#include "BaseDamageGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class SIDESCROLLERGAME_API UBaseDamageGameplayAbility : public UBaseGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Damage")
	FScalableFloat Damage;
};
