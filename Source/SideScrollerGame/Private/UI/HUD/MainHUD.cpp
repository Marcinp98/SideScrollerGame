// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MainHUD.h"

#include "UI/Widget/MainUserWidget.h"

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UMainUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
