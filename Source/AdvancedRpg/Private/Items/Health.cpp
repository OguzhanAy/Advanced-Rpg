// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Health.h"
#include "Interfaces/PickupInterface.h"
#include "Components/AttributeComponent.h"
#include "Characters/SlashCharacter.h"
void AHealth::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (PickupInterface)
	{
		if (SlashCharacter->Attributes->GetHealth() >= 100) return;
		if (!OtherComp->ComponentHasTag(TEXT("Char"))) return;
		PickupInterface->AddHealth(this);
		SpawnPickupSystem();
		SpawnPickupSound();
		Destroy();
	}
}
