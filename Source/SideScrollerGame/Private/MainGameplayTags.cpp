// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameplayTags.h"
#include "GameplayTagsManager.h"

FMainGameplayTags FMainGameplayTags::GameplayTags;

void FMainGameplayTags::InitializeNativeGameplayTags()
{
	/* Primary Attributes */

	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("PhysicalDmg, heavierEq"));
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("MagicDmg, moreSpells"));
	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Dexterity"), FString("Fastatk, Precision, critDmg"));
	GameplayTags.Attributes_Primary_Vitality = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vitality"), FString("stamina,health"));
	GameplayTags.Attributes_Primary_Wisdom = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Wisdom"), FString("mana,etc"));
	GameplayTags.Attributes_Primary_Agility = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Agility"), FString("jumps, mobility"));
	GameplayTags.Attributes_Primary_Luck = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Luck"), FString("crit chance, drop"));

	/* Secondary Attributes */

	GameplayTags.Attributes_Secondary_PhysicalDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.PhysicalDamage"), FString("PhysicDamage"));
	GameplayTags.Attributes_Secondary_MagicDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MagicDamage"), FString("MagicDamage"));
	GameplayTags.Attributes_Secondary_AttackSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.AttackSpeed"), FString("AttackSpeed"));
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Defense"));
	GameplayTags.Attributes_Secondary_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Health"), FString("Health"));
	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), FString("MaxHealth"));
	GameplayTags.Attributes_Secondary_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Mana"), FString("Mana"));
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"), FString("MaxMana"));
	GameplayTags.Attributes_Secondary_Stamina = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Stamina"), FString("Stamina"));
	GameplayTags.Attributes_Secondary_MaxStamina = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxStamina"), FString("MaxStamina"));

	/* Input Attributes */

	GameplayTags.InputTag_Move_Left = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Move.Left"), FString("Input Tag for Move Left"));
	GameplayTags.InputTag_Move_Right = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Move.Right"), FString("Input Tag for Move Right"));
	GameplayTags.InputTag_Up = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Up"), FString("Input Tag for Move Up"));
	GameplayTags.InputTag_Down = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Down"), FString("Input Tag for Move Down"));
	GameplayTags.InputTag_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Attack"), FString("Input Tag for Attack"));
	GameplayTags.InputTag_Jump = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Jump"), FString("Input Tag for Jump"));
	GameplayTags.InputTag_Interaction = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Interaction"), FString("Input Tag for Interaction"));
	GameplayTags.InputTag_Spell1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Spell1"), FString("Input Tag for Spellslot1"));
	GameplayTags.InputTag_Spell2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Spell2"), FString("Input Tag for Spellslot2"));

	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage"), FString("Damage"));
	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Effects.HitReact"), FString("Tag granted when Hit Reacting"));
}
