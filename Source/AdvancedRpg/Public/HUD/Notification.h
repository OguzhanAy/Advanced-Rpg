// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Notification.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDRPG_API UNotification : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetIncrement(int32 Increment);
	void RemoveWidget();

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* IncrementText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Chosen;
};

