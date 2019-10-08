// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set max driving force, and to apply forces to the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION (BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// Max for per track in newtons
	UPROPERTY(EditDefaultsOnly, Category = Arses)
	float TrackMaxDrivingForce = 500000; // assuming 40 tonne tank and 10m/s^2 acceleration
};
