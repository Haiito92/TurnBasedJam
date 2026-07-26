// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/Pawns/TurnBasedPawn.h"


// Sets default values
ATurnBasedPawn::ATurnBasedPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATurnBasedPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurnBasedPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATurnBasedPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

