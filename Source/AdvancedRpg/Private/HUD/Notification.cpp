// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/Notification.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Components/TextBlock.h"
#include "GameFramework/Actor.h"
#include "Blueprint/WidgetLayoutLibrary.h"

void UNotification::SetIncrement(int32 Increment)
{
	if (IncrementText)
	{
		const FString String = FString::Printf(TEXT("%d"), Increment);
		const FText Text = FText::FromString(String);
		IncrementText->SetText(Text);
	}
}

void UNotification::NativeConstruct()
{
	Super::NativeConstruct();
	
	
}

void UNotification::RemoveWidget()
{
	UWidgetLayoutLibrary::RemoveAllWidgets(this);

}


