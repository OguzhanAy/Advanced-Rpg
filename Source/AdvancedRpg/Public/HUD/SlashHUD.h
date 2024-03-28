// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlashHUD.generated.h"

/**
 * 
 */

class USlashOverlay;
class UNotification;

UCLASS()
class ADVANCEDRPG_API ASlashHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditDefaultsOnly, Category = Slash )
	TSubclassOf<USlashOverlay> SlashOverlayClass;	
	USlashOverlay* SlashOverlay;

	UPROPERTY(EditDefaultsOnly, Category = Slash)
	TSubclassOf<UNotification> NotificationClass;
	UNotification* Notification;

	void RemoveWidget();
public:
	FORCEINLINE USlashOverlay* GetSlashOverlay() const { return SlashOverlay; }
	void CreateNotification(int32 Increment, int32 ChosenCount);

};
