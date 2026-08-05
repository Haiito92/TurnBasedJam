// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TURNBASEDJAM_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();
	
	UFUNCTION(BlueprintCallable)
	void InitHealthComponent();

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float Damage);
	UFUNCTION(BlueprintCallable)
	void Heal(float Heal);

	UFUNCTION(BlueprintCallable)
	void Die();
	
	UFUNCTION(BlueprintCallable)
	bool IsAlive() const;
	
	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() const;
	UFUNCTION(BlueprintCallable)
	float GetHealth() const;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDamagedSignature);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealedSignature);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthChangedSignature, float, Health, float, MaxHealth);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDiedSignature);
	
	UPROPERTY(BlueprintAssignable)
	FDamagedSignature Damaged;
	
	UPROPERTY(BlueprintAssignable)
	FHealedSignature Healed;
	
	UPROPERTY(BlueprintAssignable)
	FHealthChangedSignature HealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FDiedSignature Died;
	
private:
	
	UPROPERTY(EditAnywhere)
	float MaxHealth;
	
	UPROPERTY()
	float Health;
	
private:
	UFUNCTION(CallInEditor)
	void SetHealthToZero();
	
};
