// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/MainPlayerState.h"
#include "Player/MainPlayerController.h"
#include "UI/HUD/MainHUD.h"


AMainCharacter::AMainCharacter()
{
}

void AMainCharacter::BeginPlay()
{
    Super::BeginPlay();

    // Orientacja rotacji do kierunku ruchu
    GetCharacterMovement()->bOrientRotationToMovement = true;

    // Wy³¹czenie rotacji w oparciu o kontroler
    bUseControllerRotationYaw = false;

    // Opcjonalne: Ustawienia prêdkoœci rotacji
    GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);
}

void AMainCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    // Init abilityActorInfo for the Server
    InitAbilityActorInfo();
}

void AMainCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();
    
    //Init abilityActorInfo for the Client
    InitAbilityActorInfo();
}

void AMainCharacter::Jump()
{
    Super::Jump();
}

void AMainCharacter::InitAbilityActorInfo()
{
    AMainPlayerState* MainPlayerState = GetPlayerState<AMainPlayerState>();
    check(MainPlayerState);
    MainPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(MainPlayerState, this);
    AbilitySystemComponent = MainPlayerState->GetAbilitySystemComponent();
    AttributeSet = MainPlayerState->GetAttributeSet();

    if (AMainPlayerController* MainPlayerController = Cast<AMainPlayerController>(GetController()))
    {
        if (AMainHUD* MainHUD = Cast<AMainHUD>(MainPlayerController->GetHUD()))
        {
            MainHUD->InitOverlay(MainPlayerController, MainPlayerState, AbilitySystemComponent, AttributeSet);
        }
    }
}