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
	LeftTankTrack = LeftTrack;
	RightTankTrack = RightTrack;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool ForceMaxSpeed)
{
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s vector to %s"), *TankName, *MoveVelocityString);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTankTrack || !RightTankTrack) { return; }
	if (Throw != 0.0f)
	{
		//UE_LOG(LogTemp, Warning, TEXT("IntendMoveForward(%f)"), Throw);
		LeftTankTrack->SetThrottle(Throw);
		RightTankTrack->SetThrottle(Throw);
	}
}