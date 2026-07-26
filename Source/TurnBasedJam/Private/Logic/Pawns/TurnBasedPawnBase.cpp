// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/Pawns/TurnBasedPawnBase.h"


// Sets default values
ATurnBasedPawnBase::ATurnBasedPawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATurnBasedPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurnBasedPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATurnBasedPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

