// Fill out your copyright notice in the Description page of Project Settings.

// class header ===============================================================
#include "TankMovementComponent.h"

// custom includes ============================================================
#include "TankTrack.h"


void UTankMovementComponent::IntendTurn(float Throw)
{
	if (Throw) { LeftTankTrack->SetThrottle(Throw); }
	else if (Throw < 0.0f) { RightTankTrack->SetThrottle(Throw); }
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTrack, UTankTrack* RightTrack)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTankTrack = LeftTrack;
	RightTankTrack = RightTrack;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (Throw != 0.0f)
	{
		//UE_LOG(LogTemp, Warning, TEXT("IntendMoveForward(%f)"), Throw);
		LeftTankTrack->SetThrottle(Throw);
		RightTankTrack->SetThrottle(Throw);
	}
}