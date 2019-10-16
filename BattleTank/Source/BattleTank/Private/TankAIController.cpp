// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank) 
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// TODO Make AI move towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		// TODO Decide if it wants to fire
		// ControlledTank->Fire();
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
