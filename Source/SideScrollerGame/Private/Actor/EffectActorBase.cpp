// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EffectActorBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/MainAttributeSet.h"
#include "Components/SphereComponent.h"

AEffectActorBase::AEffectActorBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());

}

void AEffectActorBase::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UMainAttributeSet* MainAttributeSet = Cast<UMainAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UMainAttributeSet::StaticClass()));
		UMainAttributeSet* MutableMainAttributeSet = const_cast<UMainAttributeSet*>(MainAttributeSet);
		MutableMainAttributeSet->SetHealth(MainAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AEffectActorBase::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AEffectActorBase::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AEffectActorBase::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AEffectActorBase::EndOverlap);
	
}

