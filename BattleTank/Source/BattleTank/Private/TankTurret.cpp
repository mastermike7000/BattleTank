// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Clamp the incoming RelativeSpeed to between -1 and 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);

	// UE_LOG (LogTemp, Warning, TEXT("Clamped value RelativeSpeed: %f"), RelativeSpeed)

	// Calculate how much to move this tick and set rotation
    auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));
}