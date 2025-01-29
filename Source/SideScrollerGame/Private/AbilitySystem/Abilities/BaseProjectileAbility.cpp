// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BaseProjectileAbility.h"
#include "Actor/BaseProjectile.h"
#include "Interaction/CombatInterface.h"

void UBaseProjectileAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UBaseProjectileAbility::SpawnProjectile()
{
	const bool bIsServer = (GetAvatarActorFromActorInfo()->HasAuthority());
	if (!bIsServer) return;

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (CombatInterface)
	{
		//const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
		const FVector SocketLocation = CombatInterface->GetHandSocketLocation();
		const FRotator ActorRotation = GetAvatarActorFromActorInfo()->GetActorRotation();

		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		SpawnTransform.SetRotation(ActorRotation.Quaternion());

		ABaseProjectile* Projectile = GetWorld()->SpawnActorDeferred<ABaseProjectile>(
			ProjectileClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			Cast<APawn>(GetOwningActorFromActorInfo()),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		//TODO: Give the projectile a Gameplay Effect Spec for causing Damage.

		Projectile->FinishSpawning(SpawnTransform);
	}
}
