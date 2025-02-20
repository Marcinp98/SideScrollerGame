// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyBase.h"

#include "AbilitySystem/MainAbilitySystemLibrary.h"
#include "AbilitySystem/MainAbilitySystemComponent.h"
#include "AbilitySystem/MainAttributeSet.h"
#include "Components/WidgetComponent.h"
#include "UI/Widget/MainUserWidget.h"
#include "MainGameplayTags.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyBase::AEnemyBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UMainAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UMainAttributeSet>("AttributeSet");

	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(GetRootComponent());
}

int32 AEnemyBase::GetPlayerLevel()
{
	return Level;
}

void AEnemyBase::Die()
{
	SetLifeSpan(LifeSpan);
	Super::Die();
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
	InitAbilityActorInfo();
	if (HasAuthority())
	{
		UMainAbilitySystemLibrary::GiveStartupAbilities(this, AbilitySystemComponent);
	}

	if (UMainUserWidget* MainUserWidget = Cast<UMainUserWidget>(HealthBar->GetUserWidgetObject()))
	{
		MainUserWidget->SetWidgetController(this);
	}

	if (const UMainAttributeSet* MainAS = Cast<UMainAttributeSet>(AttributeSet))
	{ 	
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MainAS->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MainAS->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);
		AbilitySystemComponent->RegisterGameplayTagEvent(FMainGameplayTags::Get().Effects_HitReact, EGameplayTagEventType::NewOrRemoved).AddUObject(
			this,
			&AEnemyBase::HitReactTagChanged
		);

		OnHealthChanged.Broadcast(MainAS->GetHealth());
		OnMaxHealthChanged.Broadcast(MainAS->GetMaxHealth());

	}
}

void AEnemyBase::HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	bHitReacting = NewCount > 0;
	GetCharacterMovement()->MaxWalkSpeed = bHitReacting ? 0.f : BaseWalkSpeed;
}

void AEnemyBase::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UMainAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();

	if (HasAuthority())
	{
		InitializeDefaultAttributes();
	}
}

void AEnemyBase::InitializeDefaultAttributes() const
{
	UMainAbilitySystemLibrary::InitializeDefaultAttributes(this, CharacterClass, Level, AbilitySystemComponent);
}
