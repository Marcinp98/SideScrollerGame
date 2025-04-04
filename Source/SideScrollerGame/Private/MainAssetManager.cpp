// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAssetManager.h"
#include "MainGameplayTags.h"

UMainAssetManager& UMainAssetManager::Get()
{
	check(GEngine);
	UMainAssetManager* MainAssetManager = Cast<UMainAssetManager>(GEngine->AssetManager);
	return *MainAssetManager;
}

void UMainAssetManager::StartInitialLoading()
{
	FMainGameplayTags::InitializeNativeGameplayTags();
}
