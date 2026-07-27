// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurnBased.h"
#include "GameFramework/Actor.h"
#include "TurnBasedActor.generated.h"

UCLASS()
class TURNBASEDJAM_API ATurnBasedActor : public AActor, public ITurnBased
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurnBasedActor();

	virtual void PrepareTurn_Implementation() override;
	virtual void FinalizeTurnPreparation_Implementation() override;
	virtual void ChooseNextAction_Implementation() override;
	virtual void StartTurn_Implementation() override;
	virtual void EndTurn_Implementation() override;	
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNextActionChosenSignature);
	UPROPERTY(BlueprintAssignable)
	FNextActionChosenSignature NextActionChosen;
	
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
	
private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> ActorMesh;
};
