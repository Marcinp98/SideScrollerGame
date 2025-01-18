// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


AMainCharacter::AMainCharacter()
{
}

void AMainCharacter::BeginPlay()
{
    Super::BeginPlay();

    // Orientacja rotacji do kierunku ruchu
    GetCharacterMovement()->bOrientRotationToMovement = true;

    // Wy��czenie rotacji w oparciu o kontroler
    bUseControllerRotationYaw = false;

    // Opcjonalne: Ustawienia pr�dko�ci rotacji
    GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);
}

void AMainCharacter::Jump()
{
    Super::Jump();
}
