// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	LogTrackPointerErrors();
	if (!LeftTrack || !RightTrack) { return; }


	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendRotateClockwise(float Throw)
{
	LogTrackPointerErrors();
	if (!LeftTrack || !RightTrack) {return;}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::InitialiseMovement(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// Don't need to call super since parent class functionality is being replaced

	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto CrossProduct = FVector::CrossProduct(AIForwardIntention, TankForward);

	IntendRotateClockwise(CrossProduct.Z);

	IntendMoveForward(FVector::DotProduct(TankForward, AIForwardIntention));
	
}

// Track pointer protection (spits outs errors if tracks are not hooked up in blueprint)
void UTankMovementComponent::LogTrackPointerErrors()
{
	if (!LeftTrack) { UE_LOG(LogTemp, Error, TEXT("No left track pointer on %s!"), *GetOwner()->GetName()) }
	if (!RightTrack) { UE_LOG(LogTemp, Error, TEXT("No right track pointer on %s!"), *GetOwner()->GetName()) }
}
