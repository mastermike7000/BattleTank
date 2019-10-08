// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw)

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO Prevent double speed
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), -Throw)

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);

	//TODO Prevent double speed
}

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	// pointer protection with useful errors
	if (!LeftTrackToSet) {UE_LOG(LogTemp, Error, TEXT("No left track pointer on %s!"), *GetName())}
	if (!RightTrackToSet) {UE_LOG(LogTemp, Error, TEXT("No right track pointer on %s!"), *GetName())}
	if (!LeftTrackToSet || !RightTrackToSet) {return;}

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;


}
