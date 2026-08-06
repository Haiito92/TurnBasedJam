// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logic/Actions/ActionContext.h"
#include "Logic/Health/HealthComponent.h"
#include "Logic/Status/StatusEnum.h"
#include "TurnBasedActor.generated.h"

enum class EActionType : uint8;
class UStatusComponent;
class UHealthComponent;
class UActionData;

UCLASS()
class TURNBASEDJAM_API ATurnBasedActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurnBasedActor();

	
	UFUNCTION(BlueprintCallable)
	void InitTurnBasedActor();
	
	UFUNCTION(BlueprintCallable)
	virtual void PrepareTurn(ATurnBasedActor* Enemy);
	UFUNCTION(BlueprintCallable)
	virtual void SetNextAction(UAction* InAction);
	UFUNCTION(BlueprintCallable)
	virtual void SetNextActionCaster(ATurnBasedActor* Caster);
	UFUNCTION(BlueprintCallable)
	virtual void SetNextActionTarget(ATurnBasedActor* Target);
	UFUNCTION(BlueprintCallable)
	virtual void ValidateNextAction();
	UFUNCTION(BlueprintCallable)
	virtual void FinalizeTurnPreparation();
	
	UFUNCTION()
	virtual void PlayNextActionAnim();
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Receive Play Next Action Anim")
	void ReceivePlayNextActionAnim(const EActionType& InActionType);
	
	UFUNCTION()
	void OnFirstStatusCopyApplied(const EStatusEnum& StatusEnum);
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Receive On First Status Copy Applied")
	void ReceiveOnFirstStatusCopyApplied(const EStatusEnum& StatusEnum);
	UFUNCTION()
	void OnLastStatusCopyRemoved(const EStatusEnum& StatusEnum);
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Receive On Last Status Copy Removed")
	void ReceiveOnLastStatusCopyRemoved(const EStatusEnum& StatusEnum);
	
	UFUNCTION(BlueprintCallable)
	virtual void StartTurn();
	UFUNCTION(BlueprintCallable)
	virtual void EndTurn();	
	
	UFUNCTION(BlueprintCallable)
	const TArray<UAction*>& GetActions() const;
	
	UFUNCTION(BlueprintCallable)
	FActionContext GetNextAction() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UHealthComponent* GetHealthComponent();
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UStatusComponent* GetStatusComponent();
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNextActionValidatedSignature, UAction*, Action);
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
	TArray<TSubclassOf<UAction>> ActionClasses;
	
	UPROPERTY()
	TArray<TObjectPtr<UAction>> Actions;
	
	UPROPERTY()
	FActionContext NextAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> ActorMesh;
	
private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UHealthComponent> HealthComponent;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStatusComponent> StatusComponent;
};
