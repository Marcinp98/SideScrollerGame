// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *  MainGameplayTags
 * 
 * Singleton containing native Gameplay Tags
 */

struct FMainGameplayTags
{
public:
	static const FMainGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	/* Primary Attributes */

	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Dexterity;
	FGameplayTag Attributes_Primary_Vitality;
	FGameplayTag Attributes_Primary_Wisdom;
	FGameplayTag Attributes_Primary_Agility;
	FGameplayTag Attributes_Primary_Luck;

	/* Secondary Attributes */

	FGameplayTag Attributes_Secondary_PhysicalDamage;
	FGameplayTag Attributes_Secondary_MagicDamage;
	FGameplayTag Attributes_Secondary_AttackSpeed;
	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_Health;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_Mana;
	FGameplayTag Attributes_Secondary_MaxMana;
	FGameplayTag Attributes_Secondary_Stamina;
	FGameplayTag Attributes_Secondary_MaxStamina;

	/* Resistances */

	FGameplayTag Attributes_Resistance_Fire;
	FGameplayTag Attributes_Resistance_Lightning;
	FGameplayTag Attributes_Resistance_Cold;
	FGameplayTag Attributes_Resistance_Arcane;
	FGameplayTag Attributes_Resistance_Darkness;
	FGameplayTag Attributes_Resistance_Holy;
	FGameplayTag Attributes_Resistance_Slash;
	FGameplayTag Attributes_Resistance_Pierce;
	FGameplayTag Attributes_Resistance_Blunt;

	/* Input Attributes */

	FGameplayTag InputTag_Move_Left;
	FGameplayTag InputTag_Move_Right;
	FGameplayTag InputTag_Up;
	FGameplayTag InputTag_Down;
	FGameplayTag InputTag_Jump;
	FGameplayTag InputTag_Attack;
	FGameplayTag InputTag_Interaction;
	FGameplayTag InputTag_Spell1;
	FGameplayTag InputTag_Spell2;

	/* Damage Types */

	FGameplayTag Damage;
	FGameplayTag Damage_Element_Fire;
	FGameplayTag Damage_Element_Lightning;
	FGameplayTag Damage_Element_Cold;
	FGameplayTag Damage_Element_Arcane;
	FGameplayTag Damage_Element_Holy;
	FGameplayTag Damage_Element_Darkness;
	FGameplayTag Damage_Physical_Slash;
	FGameplayTag Damage_Physical_Pierce;
	FGameplayTag Damage_Physical_Blunt;

	FGameplayTag Abilities_Attack;
	FGameplayTag Abilities_Summon;

	FGameplayTag CombatSocket_Weapon;
	FGameplayTag CombatSocket_RightHand;
	FGameplayTag CombatSocket_LeftHand;
	FGameplayTag CombatSocket_Tail;

	FGameplayTag Montage_Attack_1;
	FGameplayTag Montage_Attack_2;
	FGameplayTag Montage_Attack_3;
	FGameplayTag Montage_Attack_4;

	TMap<FGameplayTag, FGameplayTag> DamageTypesToResistances;

	FGameplayTag Effects_HitReact;

private:
	static FMainGameplayTags GameplayTags;
};