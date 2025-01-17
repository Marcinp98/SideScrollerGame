// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MainPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AMainPlayerController::AMainPlayerController()
{
	bReplicates = true;
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(MainContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(MainContext, 0);
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainPlayerController::Move);
}

void AMainPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const float InputValue = InputActionValue.Get<float>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		// Sta³y kierunek dla SideScrollera
		const FVector MoveDirection = FVector(1.f, 0.f, 0.f); // Ruch wzd³u¿ osi X
		ControlledPawn->AddMovementInput(MoveDirection, InputValue);
	}
}
