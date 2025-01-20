// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MainPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Character/MainCharacter.h"

AMainPlayerController::AMainPlayerController()
{
	bReplicates = true;
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
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainPlayerController::Move);
    EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMainPlayerController::Jump);
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
