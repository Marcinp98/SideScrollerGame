// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MainAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Player/MainPlayerState.h"
#include "UI/WidgetController/MainWidgetController.h"
#include "UI/HUD/MainHUD.h"
#include "Game/MainGameModeBase.h"
#include "AbilitySystemComponent.h"

UOverlayWidgetController* UMainAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
    if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
    {
        if (AMainHUD* MainHUD = Cast<AMainHUD>(PC->GetHUD()))
        {
            AMainPlayerState* PS = PC->GetPlayerState<AMainPlayerState>();
            UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
            UAttributeSet* AS = PS->GetAttributeSet();
            const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
            return MainHUD->GetOverlayWidgetController(WidgetControllerParams);
        }
    }
    return nullptr;
}

UAttributeMenuWidgetController* UMainAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
    if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
    {
        if (AMainHUD* MainHUD = Cast<AMainHUD>(PC->GetHUD()))
        {
            AMainPlayerState* PS = PC->GetPlayerState<AMainPlayerState>();
            UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
            UAttributeSet* AS = PS->GetAttributeSet();
            const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
            return MainHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
        }
    }
    return nullptr;
}

void UMainAbilitySystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC)
{
    AMainGameModeBase* MainGameMode = Cast<AMainGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));
    if (MainGameMode == nullptr) return;

    AActor* AvatarActor = ASC->GetAvatarActor();

    UCharacterClassInfo* CharacterClassInfo = MainGameMode->CharacterClassInfo;
    FCharacterClassDefaultInfo ClassDefaultInfo = CharacterClassInfo->GetClassDefaultInfo(CharacterClass);

    FGameplayEffectContextHandle PrimaryAttributeContextHandle = ASC->MakeEffectContext();
    PrimaryAttributeContextHandle.AddSourceObject(AvatarActor);
    const FGameplayEffectSpecHandle PrimaryAttributesSpecHandle = ASC->MakeOutgoingSpec(ClassDefaultInfo.PrimaryAttributes, Level, PrimaryAttributeContextHandle);
    ASC->ApplyGameplayEffectSpecToSelf(*PrimaryAttributesSpecHandle.Data.Get());

    FGameplayEffectContextHandle SecondaryAttributeContextHandle = ASC->MakeEffectContext();
    SecondaryAttributeContextHandle.AddSourceObject(AvatarActor);
    const FGameplayEffectSpecHandle SecondaryAttibutesSpecHandle = ASC->MakeOutgoingSpec(CharacterClassInfo->SecondaryAttributes, Level, SecondaryAttributeContextHandle);
    ASC->ApplyGameplayEffectSpecToSelf(*SecondaryAttibutesSpecHandle.Data.Get());

    FGameplayEffectContextHandle VitalAttributeContextHandle = ASC->MakeEffectContext();
    VitalAttributeContextHandle.AddSourceObject(AvatarActor);
    const FGameplayEffectSpecHandle VitalAttributesSpecHandle = ASC->MakeOutgoingSpec(CharacterClassInfo->VitalAttributes, Level, VitalAttributeContextHandle);
    ASC->ApplyGameplayEffectSpecToSelf(*VitalAttributesSpecHandle.Data.Get());
}

void UMainAbilitySystemLibrary::GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC)
{
    AMainGameModeBase* MainGameMode = Cast<AMainGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));
    if (MainGameMode == nullptr) return;

    UCharacterClassInfo* CharacterClassInfo = MainGameMode->CharacterClassInfo;
    for (TSubclassOf<UGameplayAbility> AbilityClass : CharacterClassInfo->CommonAbilities)
    {
        FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
        ASC->GiveAbility(AbilitySpec);
    }
}
