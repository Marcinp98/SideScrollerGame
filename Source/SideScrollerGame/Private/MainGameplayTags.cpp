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

	/* Resistances */

	GameplayTags.Attributes_Resistance_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes_Resistance_Fire"), FString("Resistance to Fire damage"));
	GameplayTags.Attributes_Resistance_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes_Resistance_Lightning"), FString("Resistance to Lightning damage"));
	GameplayTags.Attributes_Resistance_Cold = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes_Resistance_Cold"), FString("Resistance to Cold damage"));
	GameplayTags.Attributes_Resistance_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes_Resistance_Arcane"), FString("Resistance to Arcane damage"));
	GameplayTags.Attributes_Resistance_Holy = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes_Resistance_Holy"), FString("Resistance to Holy damage"));
	GameplayTags.Attributes_Resistance_Darkness = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes_Resistance_Darkness"), FString("Resistance to Darkness damage"));
	GameplayTags.Attributes_Resistance_Slash = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes_Resistance_Slash"), FString("Resistance to Slash damage"));
	GameplayTags.Attributes_Resistance_Pierce = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes_Resistance_Pierce"), FString("Resistance to Pierce damage"));
	GameplayTags.Attributes_Resistance_Blunt = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes_Resistance_Blunt"), FString("Resistance to Blunt damage"));

	/* Input Attributes */

	GameplayTags.InputTag_Left = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Left"), FString("Input Tag for Left key"));
	GameplayTags.InputTag_Right = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Right"), FString("Input Tag for Right key"));
	GameplayTags.InputTag_Up = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Up"), FString("Input Tag for Up key"));
	GameplayTags.InputTag_Down = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Down"), FString("Input Tag for Down key"));
	GameplayTags.InputTag_Z = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Z"), FString("Input Tag for Z Key"));
	GameplayTags.InputTag_X = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.X"), FString("Input Tag for X Key"));
	GameplayTags.InputTag_C = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.C"), FString("Input Tag for C Key"));
	GameplayTags.InputTag_A = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.A"), FString("Input Tag for A Key"));
	GameplayTags.InputTag_S = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.S"), FString("Input Tag for S Key"));

	/* Damage Types */
	
	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage"), FString("Damage"));
	GameplayTags.Damage_Element_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Element.Fire"), FString("Fire Damage Type"));
	GameplayTags.Damage_Element_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Element.Lightning"), FString("Lightning Damage Type"));
	GameplayTags.Damage_Element_Cold = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Element.Cold"), FString("Cold Damage Type"));
	GameplayTags.Damage_Element_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Element.Arcane"), FString("Arcane Damage Type"));
	GameplayTags.Damage_Element_Holy = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Element.Holy"), FString("Holy Damage Type"));
	GameplayTags.Damage_Element_Darkness = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Element.Darkness"), FString("Dark Damage Type"));
	GameplayTags.Damage_Physical_Slash = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Physical.Slash"), FString("Slash Damage Type"));
	GameplayTags.Damage_Physical_Pierce = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Physical.Pierce"), FString("Pierce Damage Type"));
	GameplayTags.Damage_Physical_Blunt = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Physical.Blunt"), FString("Blunt Damage Type"));

	/* Map of Damage Types to Resistances */

	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Element_Arcane, GameplayTags.Attributes_Resistance_Arcane);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Element_Fire, GameplayTags.Attributes_Resistance_Fire);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Element_Lightning, GameplayTags.Attributes_Resistance_Lightning);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Element_Cold, GameplayTags.Attributes_Resistance_Cold);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Element_Holy, GameplayTags.Attributes_Resistance_Holy);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Element_Darkness, GameplayTags.Attributes_Resistance_Darkness);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Physical_Slash, GameplayTags.Attributes_Resistance_Slash);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Physical_Pierce, GameplayTags.Attributes_Resistance_Pierce);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Physical_Blunt, GameplayTags.Attributes_Resistance_Blunt);

	/* Meta Attributes */

	GameplayTags.Attributes_Meta_IncomingXP = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Meta.IncomingXP"),FString("Incoming XP Meta Attribute"));

	/* Effects */

	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Effects.HitReact"), FString("Tag granted when Hit Reacting"));

	/* Abilities */

	GameplayTags.Abilities_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Attack"), FString("Attack Ability Tag"));
	GameplayTags.Abilities_Summon = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Summon"), FString("Summon Ability Tag"));
	GameplayTags.Abilities_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Fire.FireBolt"), FString("FireBolt Ability Tag"));
	
	/* Cooldown */

	GameplayTags.Cooldown_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Cooldown.Fire.FireBolt"), FString("Firebolt Cooldown Tag"));

	/* CombatSockets */

	GameplayTags.CombatSocket_Weapon = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("CombatSocket.Weapon"), FString("Weapon"));
	GameplayTags.CombatSocket_RightHand = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("CombatSocket.RightHand"), FString("Right Hand"));
	GameplayTags.CombatSocket_LeftHand = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("CombatSocket.LeftHand"), FString("Left Hand"));
	GameplayTags.CombatSocket_Tail = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("CombatSocket.Tail"), FString("Tail"));

	/* Montage Tags */

	GameplayTags.Montage_Attack_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Montage.Attack.1"), FString("Attack 1"));
	GameplayTags.Montage_Attack_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Montage.Attack.2"), FString("Attack 2"));
	GameplayTags.Montage_Attack_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Montage.Attack.3"), FString("Attack 3"));
	GameplayTags.Montage_Attack_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Montage.Attack.4"), FString("Attack 4"));
}
