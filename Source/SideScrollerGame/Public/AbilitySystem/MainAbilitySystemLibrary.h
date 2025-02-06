// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/CharacterClassInfo.h"
#include "MainAbilitySystemLibrary.generated.h"

class UAbilitySystemComponent;
class UOverlayWidgetController;
class UAttributeMenuWidgetController;

/**
 * 
 */
UCLASS()
class SIDESCROLLERGAME_API UMainAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category ="MainAbilitySystemLibrary|WidgetController")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);
	
	UFUNCTION(BlueprintPure, Category = "MainAbilitySystemLibrary|WidgetController")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "MainAbilitySystemLibrary|CharacterClassDefaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC);
};
