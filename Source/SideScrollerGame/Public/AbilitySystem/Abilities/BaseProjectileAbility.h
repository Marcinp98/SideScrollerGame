// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BaseDamageGameplayAbility.h"
#include "BaseProjectileAbility.generated.h"

class ABaseProjectile;
class UGameplayEffect;

/**
 * 
 */
UCLASS()
class SIDESCROLLERGAME_API UBaseProjectileAbility : public UBaseDamageGameplayAbility
{
	GENERATED_BODY()
	
protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectile(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ABaseProjectile> ProjectileClass;
};
