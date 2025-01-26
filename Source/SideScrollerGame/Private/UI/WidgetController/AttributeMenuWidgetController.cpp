// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/MainAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "MainGameplayTags.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{

}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UMainAttributeSet* AS = CastChecked<UMainAttributeSet>(AttributeSet);
	
	check(AttributeInfo);

	FMainAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FMainGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
}
