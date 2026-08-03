// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UIEventsHolder.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class UIEventsType : uint8
{
	None,
	PlayClicked,
	QuitClicked
};

UCLASS(BlueprintType, Blueprintable)
class TURNBASEDJAM_API UUIEventsHolder : public UObject
{
	GENERATED_BODY()
	
public:
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayClickedSignature);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FQuitClickedSignature);
	
	UPROPERTY(BlueprintAssignable)
	FPlayClickedSignature PlayClicked;
	
	UPROPERTY(BlueprintAssignable)
	FQuitClickedSignature QuitClicked;
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="UIEventType"))
	void LaunchEvent(const UIEventsType& UIEventType);
};
