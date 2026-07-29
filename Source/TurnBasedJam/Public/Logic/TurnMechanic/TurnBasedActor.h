// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logic/Actions/Action.h"
#include "TurnBasedActor.generated.h"

class UActionData;

UCLASS()
class TURNBASEDJAM_API ATurnBasedActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurnBasedActor();

	UFUNCTION(BlueprintCallable)
	virtual void PrepareTurn(ATurnBasedActor* Enemy);
	UFUNCTION(BlueprintCallable)
	virtual void SetNextActionData(UActionData* Data);
	UFUNCTION(BlueprintCallable)
	virtual void SetNextActionCaster(ATurnBasedActor* Caster);
	UFUNCTION(BlueprintCallable)
	virtual void SetNextActionTarget(ATurnBasedActor* Target);
	UFUNCTION(BlueprintCallable)
	virtual void ValidateNextAction();
	UFUNCTION(BlueprintCallable)
	virtual void FinalizeTurnPreparation();
	UFUNCTION(BlueprintCallable)
	virtual void StartTurn();
	UFUNCTION(BlueprintCallable)
	virtual void EndTurn();	
	
	UFUNCTION(BlueprintCallable)
	TArray<UActionData*> GetActionsData() const;
	
	UFUNCTION(BlueprintCallable)
	FAction GetNextAction() const;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNextActionValidatedSignature, UActionData*, ActionData);
	UPROPERTY(BlueprintAssignable)
	FNextActionValidatedSignature NextActionValidated;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTurnPreparationStartedSignature);
	UPROPERTY(BlueprintAssignable)
	FTurnPreparationStartedSignature TurnPreparationStarted;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTurnPreparationFinalizedSignature);
	UPROPERTY(BlueprintAssignable)
	FTurnPreparationFinalizedSignature TurnPreparationFinalized;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTurnStartedSignature);
	UPROPERTY(BlueprintAssignable)
	FTurnStartedSignature TurnStarted;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTurnEndedSignature);
	UPROPERTY(BlueprintAssignable)
	FTurnEndedSignature TurnEnded;
	
protected:
	UPROPERTY(EditAnywhere, Category="Turn Based Actor|Turn Actions")
	TArray<UActionData*> ActionsData;
	
	UPROPERTY()
	FAction NextAction;
	
private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> ActorMesh;
	
};
