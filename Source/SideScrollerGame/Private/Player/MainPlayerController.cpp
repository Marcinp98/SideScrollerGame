// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MainPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Input/MainInputComponent.h"
#include "AbilitySystem/MainAbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/MainCharacter.h"
#include "UI/HUD/MainHUD.h"

AMainPlayerController::AMainPlayerController()
{
	bReplicates = true;
}

void AMainPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
    
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
    MainInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainPlayerController::Move);
    MainInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMainPlayerController::Jump);
    MainInputComponent->BindAction(ToggleInventoryAction, ETriggerEvent::Triggered, this, &AMainPlayerController::ToggleInventory);
    MainInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void AMainPlayerController::Move(const FInputActionValue& InputActionValue)
{
    const float InputValue = InputActionValue.Get<float>();

    if (InputValue != 0.f) // Poruszamy siê
    {
        if (APawn* ControlledPawn = GetPawn<APawn>())
        {
            const FVector MoveDirection = FVector(1.f, 0.f, 0.f); // Ruch wzd³u¿ osi X
            ControlledPawn->AddMovementInput(MoveDirection, InputValue);

            // Obrót postaci w kierunku ruchu
            FRotator NewRotation = FRotator(0.f, InputValue > 0.f ? 0.f : 180.f, 0.f);
            ControlledPawn->SetActorRotation(NewRotation);
        }
    }
}

void AMainPlayerController::Jump(const FInputActionValue& InputActionValue)
{
    APawn* ControlledPawn = GetPawn();

    if (AMainCharacter* ControlledCharacter = Cast<AMainCharacter>(ControlledPawn))
    {
        ControlledCharacter->Jump();
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

