// Fill out your copyright notice in the Description page of Project Settings.

// class header
#include "TankTurret.h"

// UE4 includes ===============================================================
#include "Engine/World.h"

void UTankTurret::Turn(float SpeedMultiplier)
{
	SpeedMultiplier = FMath::Clamp<float>(SpeedMultiplier, -1.0f, 1.0f);
	float DeltaYaw = DegreesPerSecond * SpeedMultiplier * GetWorld()->DeltaTimeSeconds;
	UE_LOG(LogTemp, Warning, TEXT("%f + %f = %f"), RelativeRotation.Yaw, DeltaYaw, RelativeRotation.Yaw + DeltaYaw);
	SetRelativeRotation(FRotator(0, 0, RelativeRotation.Yaw + DeltaYaw));
}
