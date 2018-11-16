// Fill out your copyright notice in the Description page of Project Settings.

// class header ===============================================================
#include "TankBarrel.h"

// UE4 includes ===============================================================
#include "Engine/World.h"


void UTankBarrel::Elevate(float SpeedMultiplier)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s elevate at speed %f"), *GetOwner()->GetName(), DegreesPerSecond);
	SpeedMultiplier = FMath::Clamp<float>(SpeedMultiplier, -1.0f, 1.0f);
	float DeltaElevation = DegreesPerSecond * SpeedMultiplier * GetWorld()->DeltaTimeSeconds;
	float Elevation = FMath::Clamp<float>(RelativeRotation.Pitch + DeltaElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
