// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/MainAbilitySystemComponent.h"
#include "AbilitySystem/MainAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UMainAttributeSet* MainAttributeSet = CastChecked<UMainAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(MainAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(MainAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(MainAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(MainAttributeSet->GetMaxMana());
	OnStaminaChanged.Broadcast(MainAttributeSet->GetStamina());
	OnMaxStaminaChanged.Broadcast(MainAttributeSet->GetMaxStamina());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UMainAttributeSet* MainAttributeSet = CastChecked<UMainAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MainAttributeSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MainAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MainAttributeSet->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);
		}
	);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MainAttributeSet->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		}
	);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MainAttributeSet->GetStaminaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnStaminaChanged.Broadcast(Data.NewValue);
		}
	);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MainAttributeSet->GetMaxStaminaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxStaminaChanged.Broadcast(Data.NewValue);
		}
	);


	Cast<UMainAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}
