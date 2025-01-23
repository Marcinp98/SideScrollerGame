// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "EnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class SIDESCROLLERGAME_API AEnemyBase : public ACharacterBase
{
	GENERATED_BODY()
public:
	AEnemyBase();

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
};
