// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MainAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() {}

	FGameplayEffectContextHandle EffectContextHandle;
	
	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

// typedef is specific to the FgameplayAttribtue() signature, but TStaticFuncPtr is generic to any signature chosen
//typedef TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultDelegateUserPolicy>::FFuncPtr FAttributeFuncPtr;
//template<class T>
//using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

/**
 * 
 */
UCLASS()
class SIDESCROLLERGAME_API UMainAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UMainAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	//tags to function pointers
	//TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;

	/*
	* Primary Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Dexterity, Category = "Primary Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Dexterity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vitality, Category = "Primary Attributes")
	FGameplayAttributeData Vitality;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Vitality);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Agility, Category = "Primary Attributes")
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Agility);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Wisdom, Category = "Primary Attributes")
	FGameplayAttributeData Wisdom;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Wisdom);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Luck, Category = "Primary Attributes")
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Luck);



	/*
	* Secondary Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PhysicalDamage, Category = "Secondary Attributes")
	FGameplayAttributeData PhysicalDamage;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, PhysicalDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MagicDamage, Category = "Secondary Attributes")
	FGameplayAttributeData MagicDamage;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, MagicDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackSpeed, Category = "Secondary Attributes")
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, AttackSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Armor);

	/*
	* Resistance Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_FireResistance, Category = "Resistance Attributes")
	FGameplayAttributeData FireResistance;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, FireResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_LightningResistance, Category = "Resistance Attributes")
	FGameplayAttributeData LightningResistance;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, LightningResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ColdResistance, Category = "Resistance Attributes")
	FGameplayAttributeData ColdResistance;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, ColdResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArcaneResistance, Category = "Resistance Attributes")
	FGameplayAttributeData ArcaneResistance;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, ArcaneResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HolyResistance, Category = "Resistance Attributes")
	FGameplayAttributeData HolyResistance;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, HolyResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DarknessResistance, Category = "Resistance Attributes")
	FGameplayAttributeData DarknessResistance;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, DarknessResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SlashResistance, Category = "Resistance Attributes")
	FGameplayAttributeData SlashResistance;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, SlashResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PierceResistance, Category = "Resistance Attributes")
	FGameplayAttributeData PierceResistance;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, PierceResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BluntResistance, Category = "Resistance Attributes")
	FGameplayAttributeData BluntResistance;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, BluntResistance);

	/*
	* Vital Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Vital Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Vital Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, MaxStamina);

	/*
	* Meta Attributes
	*/

	UPROPERTY(BlueprintReadOnly, Category = "Meta Attributes")
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UMainAttributeSet, IncomingDamage);

	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Vitality(const FGameplayAttributeData& OldVitality) const;

	UFUNCTION()
	void OnRep_Agility(const FGameplayAttributeData& OldAgility) const;

	UFUNCTION()
	void OnRep_Wisdom(const FGameplayAttributeData& OldWisdom) const;

	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData& OldLuck) const;

	UFUNCTION()
	void OnRep_PhysicalDamage(const FGameplayAttributeData& OldPhysicalDamage) const;

	UFUNCTION()
	void OnRep_MagicDamage(const FGameplayAttributeData& OldMagicDamage) const;

	UFUNCTION()
	void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed) const;

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_FireResistance(const FGameplayAttributeData& OldFireResistance) const;

	UFUNCTION()
	void OnRep_LightningResistance(const FGameplayAttributeData& OldLightningResistance) const;

	UFUNCTION()
	void OnRep_ColdResistance(const FGameplayAttributeData& OldColdResistance) const;

	UFUNCTION()
	void OnRep_ArcaneResistance(const FGameplayAttributeData& OldArcaneResistance) const;

	UFUNCTION()
	void OnRep_HolyResistance(const FGameplayAttributeData& OldHolyResistance) const;

	UFUNCTION()
	void OnRep_DarknessResistance(const FGameplayAttributeData& OldDarknessResistance) const;

	UFUNCTION()
	void OnRep_SlashResistance(const FGameplayAttributeData& OldSlashResistance) const;

	UFUNCTION()
	void OnRep_PierceResistance(const FGameplayAttributeData& OldPierceResistance) const;

	UFUNCTION()
	void OnRep_BluntResistance(const FGameplayAttributeData& OldBluntResistance) const;

private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	void ShowFloatingText(const FEffectProperties& Props, float Damage, bool bCriticalHit) const;
};
