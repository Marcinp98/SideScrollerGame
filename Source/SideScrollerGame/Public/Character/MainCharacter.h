// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "MainCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SIDESCROLLERGAME_API AMainCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	AMainCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void Jump() override;
protected:
	virtual void BeginPlay() override;

private:
	void InitAbilityActorInfo() override;
};
