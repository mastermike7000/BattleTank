// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "TankBarrel.generated.h"

/**
 * Controls elevation of tank barrel
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 max downward speed, +1 is max upwards
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10; // default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 40; // default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0; // default

	
};
