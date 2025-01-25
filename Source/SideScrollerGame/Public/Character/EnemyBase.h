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

	/* Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/* End Combat Interface */

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
};
