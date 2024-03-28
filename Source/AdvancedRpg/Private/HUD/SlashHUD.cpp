// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashHUD.h"
#include "HUD/SlashOverlay.h"
#include "HUD/Notification.h"
#include "Blueprint/WidgetLayoutLibrary.h"

void ASlashHUD::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller && SlashOverlayClass)
		{
			SlashOverlay = CreateWidget<USlashOverlay>(Controller, SlashOverlayClass);
			SlashOverlay->AddToViewport();
		}
	}
}

void ASlashHUD::RemoveWidget()
{
	Notification->RemoveFromParent();
}

void ASlashHUD::CreateNotification(int32 Increment, int32 ChosenCount)
{
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller && NotificationClass)
		{
			Notification = CreateWidget<UNotification>(Controller, NotificationClass);
			Notification->SetIncrement(Increment);
			Notification->Chosen = ChosenCount;
			Notification->AddToViewport();
			FTimerHandle TimerHandle;
			//GetWorld()->GetTimerManager().SetTimer(TimerHandle, RemoveWidget(), 3, false);
			GetWorldTimerManager().SetTimer(TimerHandle, this, &ASlashHUD::RemoveWidget, 3.f);
		}
	}
}
