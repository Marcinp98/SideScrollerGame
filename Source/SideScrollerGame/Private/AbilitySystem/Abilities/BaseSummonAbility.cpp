// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BaseSummonAbility.h"

TArray<FVector> UBaseSummonAbility::GetSpawnLocations()
{
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();

	TArray<FVector> SpawnLocations;

	int HalfMinions = NumMinions / 2;

	for (int32 i = 0; i < NumMinions; i++)
	{
		// Kierunek w którym ma siê pojawiæ minion (-1 = za postaci¹, 1 = przed postaci¹)
		int32 DirectionMultiplier = (i < HalfMinions) ? 1 : -1;

		// Przesuniêcie wzd³u¿ osi X
		FVector SpawnOffset = FVector(DirectionMultiplier * FMath::FRandRange(MinSpawnDistance, MaxSpawnDistance), 0.f, 0.f);

		// Finalna pozycja spawnu
		FVector ChosenSpawnLocation = Location + SpawnOffset;

		FHitResult Hit;
		GetWorld()->LineTraceSingleByChannel(Hit, ChosenSpawnLocation + FVector(0.f, 0.f, 100.f), ChosenSpawnLocation - FVector(0.f, 0.f, 100.f), ECC_Visibility);
		if (Hit.bBlockingHit)
		{
			ChosenSpawnLocation = Hit.ImpactPoint;
		}
		SpawnLocations.Add(ChosenSpawnLocation);
	}
	return SpawnLocations;
}

TSubclassOf<APawn> UBaseSummonAbility::GetRandomMinionClass()
{
	const int32 Selection = FMath::RandRange(0, MinionClasses.Num() - 1);
	return MinionClasses[Selection];
}
