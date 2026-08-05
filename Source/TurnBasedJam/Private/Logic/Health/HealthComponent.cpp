// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Health/HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UHealthComponent::InitHealthComponent()
{
	Health = MaxHealth;
}


void UHealthComponent::TakeDamage(float Damage)
{
	if (!IsAlive()) return;
	if (Health <= 0) return;
	
	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
	
	Damaged.Broadcast();
	HealthChanged.Broadcast(Health, MaxHealth);
	
	if (Health <= 0) Die();
}

void UHealthComponent::Heal(float Heal)
{
	if (!IsAlive()) return;
	if (Health >= MaxHealth) return;
	
	Health = FMath::Clamp(Health + Heal, 0.0f, MaxHealth);
	
	Healed.Broadcast();
	HealthChanged.Broadcast(Health, MaxHealth);
}

void UHealthComponent::Die()
{
	if (!IsAlive()) return;
	Died.Broadcast();
}

bool UHealthComponent::IsAlive() const
{
	return Health > 0;
}

float UHealthComponent::GetMaxHealth() const
{
	return MaxHealth;
}

float UHealthComponent::GetHealth() const
{
	return Health;
}

void UHealthComponent::SetHealthToZero()
{
	Health = 0;
}
