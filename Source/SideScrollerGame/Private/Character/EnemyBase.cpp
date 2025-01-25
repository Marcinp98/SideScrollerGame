// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyBase.h"

#include "AbilitySystem/MainAbilitySystemComponent.h"
#include "AbilitySystem/MainAttributeSet.h"

AEnemyBase::AEnemyBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UMainAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UMainAttributeSet>("AttributeSet");
}

int32 AEnemyBase::GetPlayerLevel()
{
	return Level;
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	check(AbilitySystemComponent);

	InitAbilityActorInfo();
}

void AEnemyBase::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UMainAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
