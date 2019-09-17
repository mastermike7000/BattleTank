// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) 
	{
		// TODO Make AI move towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// TODO Make AI fire if ready
	}
	
}

void ATankAIController::AimTowardsPlayer()
{
	if (!GetControlledTank()) { // pointer protection
		return;
	}

	FVector AimLocation = GetPlayerTank()->GetActorLocation();
	

}
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AIController on %s"), *GetControlledTank()->GetName());
	UE_LOG(LogTemp, Warning, TEXT("AIController on %s finds player pawn %s"), *GetControlledTank()->GetName(), *GetPlayerTank()->GetName());
}
