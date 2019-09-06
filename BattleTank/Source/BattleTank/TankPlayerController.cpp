// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No possessed tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessed pawn %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { // pointer protection
		return;
	}

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(OUT HitLocation)) // will linetrace
	{
		UE_LOG(LogTemp, Warning, TEXT("OutParameter HitLocation reporting: %s"), *HitLocation.ToString());
	}


	// Get world location through crosshair by linetrace
	// If it hits something, then
		// TODO Tell controlled tank to aim at this point

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation (float (ViewportSizeX * CrosshairXLocation), float (ViewportSizeY * CrosshairYLocation));

	// UE_LOG(LogTemp, Warning, TEXT("Crosshair 2D Locarion: %s"), *ScreenLocation.ToString());

	// Get 3D vector from 2D location of crosshair
	// LineTrace through crosshair
	// Do we hit the world?
		// if yes return true
	// else
		// if no return false
		
	return true;
}


