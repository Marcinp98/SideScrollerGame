// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MainAIController.generated.h"

class UBlackBoardComponent;
class UBehaviorTreeComponent;

/**
 * 
 */
UCLASS()
class SIDESCROLLERGAME_API AMainAIController : public AAIController
{
	GENERATED_BODY()
public:
	AMainAIController();

protected:
	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;
};
