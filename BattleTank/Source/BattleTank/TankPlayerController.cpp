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
		// UE_LOG(LogTemp, Warning, TEXT("OutParameter HitLocation reporting: %s"), *HitLocation.ToString());
		GetControlledTank()->AimAt(HitLocation);
	}


	// Get world location through crosshair by linetrace
	// If it hits something, then
		// TODO Tell controlled tank to aim at this point

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, HitLocation);
	};

	return true;
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel
		(
			OUT HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility
		))
	{
		// set hit location OUT parameter from channel line trace
		OUT OutHitLocation = HitResult.Location;
		return true;
	}
	else 
	{
		// unsuccesful - return false and set OutHitLocation to 0,0,0
		OUT OutHitLocation = FVector(0.f);
		return false;
	}

}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const
{
	FVector CameraWorldLocation; // Needed to call the deproject method but not for what we're doing
		return (DeprojectScreenPositionToWorld
		(
			ScreenLocation.X,
			ScreenLocation.Y,
			CameraWorldLocation,
			OUT OutLookDirection)
		);
}