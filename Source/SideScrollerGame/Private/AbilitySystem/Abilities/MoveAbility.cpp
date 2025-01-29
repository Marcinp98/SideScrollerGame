// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/MoveAbility.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


void UMoveAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    // Pobranie referencji do postaci
    OwnerCharacter = Cast<ACharacter>(GetAvatarActorFromActorInfo());
    if (!OwnerCharacter || !OwnerCharacter->GetCharacterMovement())
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    // Pobranie wartoœci wejœcia (np. -1 dla lewo, 1 dla prawo)
    const float InputValue = 1.f; // Domyœlnie prawo

    if (StartupInputTag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("InputTag.Move.Left"))))
    {
        MoveDirection = -1.f;
    }
    else if (StartupInputTag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("InputTag.Move.Right"))))
    {
        MoveDirection = 1.f;
    }
    else
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    // U¿ycie MovementSpeed do kontrolowania ruchu
    const FVector MoveVector = FVector(1.f, 0.f, 0.f) * MovementSpeed;
    OwnerCharacter->AddMovementInput(MoveVector, MoveDirection);

    // Obrót postaci w stronê ruchu
    FRotator NewRotation = FRotator(0.f, MoveDirection > 0.f ? 0.f : 180.f, 0.f);
    OwnerCharacter->SetActorRotation(NewRotation);
}

void UMoveAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

    if (OwnerCharacter && OwnerCharacter->GetCharacterMovement())
    {
        // Zatrzymanie tylko ruchu poziomego, ale nie zatrzymujemy grawitacji
        FVector Velocity = OwnerCharacter->GetCharacterMovement()->Velocity;
        Velocity.X = 0.f;  
        OwnerCharacter->GetCharacterMovement()->Velocity = Velocity;
    }
}
