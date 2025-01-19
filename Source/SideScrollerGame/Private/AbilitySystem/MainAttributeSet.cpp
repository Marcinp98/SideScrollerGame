// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MainAttributeSet.h"
#include "Net/UnrealNetwork.h"

UMainAttributeSet::UMainAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(50.f);
	InitMana(20.f);
	InitMaxMana(20.f);
	InitStamina(100.f);
	InitMaxStamina(100.f);
}

void UMainAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
}

void UMainAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributeSet, Health, OldHealth);
}

void UMainAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributeSet, MaxHealth, OldMaxHealth);
}

void UMainAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributeSet, Mana, OldMana);
}

void UMainAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributeSet, MaxMana, OldMaxMana);
}

void UMainAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributeSet, Stamina, OldStamina);
}

void UMainAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributeSet, MaxStamina, OldMaxStamina);
}


