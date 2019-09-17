// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) 
{
	// Clamp the incoming RelativeSpeed to between -1 and 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	
	// Calculate how much to move this tick
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	// Calculate and set new relative rotation based on above 
	// and make sure it falls between limits
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
