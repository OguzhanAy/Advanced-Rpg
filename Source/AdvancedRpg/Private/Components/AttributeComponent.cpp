// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AttributeComponent.h"


UAttributeComponent::UAttributeComponent()
{	
	PrimaryComponentTick.bCanEverTick = false;	
}
// Called when the game starts
void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();	
}
void UAttributeComponent::ReceiveDamage(float Damage)
{
	Health = FMath::Clamp(Health-Damage, 0.f, MaxHealth);
}
void UAttributeComponent::UseStamina(float StaminaCost)
{
	Stamina = FMath::Clamp(Stamina - StaminaCost, 0.f, MaxHealth);
}
float UAttributeComponent::GetHealthPercent()
{
	return Health / MaxHealth;
}
float UAttributeComponent::GetStaminaPercent()
{
	return Stamina / MaxStamina;
}
bool UAttributeComponent::IsAlive()
{
	return Health > 0.f;
}
void UAttributeComponent::AddSouls(int32 NumberOfSouls)
{
	Souls += NumberOfSouls;
}
void UAttributeComponent::AddGold(int32 AmountOfGold)
{
	Gold += AmountOfGold;
}
void UAttributeComponent::AddHealth(int32 AmountOfHealth)
{
	Health = FMath::Clamp(Health + AmountOfHealth, 0.f, MaxHealth);
}
// Called every frame
void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
void UAttributeComponent::RegenStamina(float DeltaTime)
{
	Stamina = FMath::Clamp(Stamina + StaminaRegenRate * DeltaTime, 0.f, MaxStamina);
}

