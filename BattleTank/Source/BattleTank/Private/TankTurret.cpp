// Fill out your copyright notice in the Description page of Project Settings.

// class header
#include "TankTurret.h"

// UE4 includes ===============================================================
#include "Engine/World.h"

void UTankTurret::Rotate(float SpeedMultiplier)
{
	SpeedMultiplier = FMath::Clamp<float>(SpeedMultiplier, -1.0f, 1.0f);
	float DeltaYaw = DegreesPerSecond * SpeedMultiplier * GetWorld()->DeltaTimeSeconds;
	float Yaw = RelativeRotation.Yaw + DeltaYaw;
	//UE_LOG(LogTemp, Warning, TEXT("%f + %f = %f"), RelativeRotation.Yaw, DeltaYaw, Yaw);
	SetRelativeRotation(FRotator(0, Yaw, 0));
}
