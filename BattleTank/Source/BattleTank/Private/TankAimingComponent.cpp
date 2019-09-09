// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work out difference between current barrel rotation and AimDirection

	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsRotator.ToString())

	// Every tick, move the barrel at a set rotation speed in all 3 axes towards the coordinates
	// if we're at the coordinates do nothing
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) {return;} // pointer protection

	FVector OUT OutLaunchVelocity(0.f);
	FVector StartLocation = Barrel->GetSocketLocation(FName ("BarrelEnd"));
	
	// Calculate the OutLaunchVelocity using an OUT parameter
	bool bHAveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OUT OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHAveAimSolution) 
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		// UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *GetOwner()->GetName(), *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);

	}
}


