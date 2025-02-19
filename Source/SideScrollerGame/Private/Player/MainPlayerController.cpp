// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MainPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Input/MainInputComponent.h"
#include "AbilitySystem/MainAbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/MainCharacter.h"
#include "UI/HUD/MainHUD.h"
#include "GameFramework/Character.h"
#include "UI/Widget/DamageTextComponent.h"

AMainPlayerController::AMainPlayerController()
{
	bReplicates = true;
}

void AMainPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
    if (GetASC() == nullptr) return;
    GetASC()->AbilityInputTagPressed(InputTag);
}

void AMainPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
    if (GetASC() == nullptr) return;
    GetASC()->AbilityInputTagReleased(InputTag);
}

void AMainPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
    if (GetASC() == nullptr) return;
    GetASC()->AbilityInputTagHeld(InputTag);
}

UMainAbilitySystemComponent* AMainPlayerController::GetASC()
{
    if (MainAbilitySystemComponent == nullptr)
    {
        MainAbilitySystemComponent = Cast<UMainAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
    }
    return MainAbilitySystemComponent;
}


void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(MainContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    if (Subsystem)
    {
        Subsystem->AddMappingContext(MainContext, 0);
    }
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UMainInputComponent* MainInputComponent = CastChecked<UMainInputComponent>(InputComponent);
    MainInputComponent->BindAction(ToggleInventoryAction, ETriggerEvent::Triggered, this, &AMainPlayerController::ToggleInventory);
    MainInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void AMainPlayerController::ShowDamageNumber_Implementation(float DamageAmount, ACharacter* TargetCharacter, bool bCriticalHit)
{
    if (IsValid(TargetCharacter) && DamageTextComponentClass)
    {
        UDamageTextComponent* DamageText = NewObject<UDamageTextComponent>(TargetCharacter, DamageTextComponentClass);
        DamageText->RegisterComponent();
        DamageText->AttachToComponent(TargetCharacter->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
        DamageText->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
        DamageText->SetDamageText(DamageAmount, bCriticalHit);
    }
}


void AMainPlayerController::ToggleInventory(const FInputActionValue& InputActionValue)
{
    if (IsLocalController())
    {
        if (AMainHUD* MainHUD = Cast<AMainHUD>(GetHUD()))
        {
            MainHUD->OnToggleAttributeMenu();
        }
    }
}

