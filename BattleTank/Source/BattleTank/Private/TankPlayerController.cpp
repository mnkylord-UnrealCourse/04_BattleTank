// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController failed to possess tank!!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possessing [%s] @ (%s)"), *ControlledTank->GetName(), *ControlledTank->GetActorLocation().ToString());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation)
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);

	FVector CamLocation, AimDirection;
	bool DeprojectReturn = DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CamLocation, AimDirection);
	if (DeprojectReturn)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Cam (%s) aiming @ (%s)"), *CamLocation.ToCompactString(), *AimDirection.ToCompactString());
		FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetPawn());
		FVector End = PlayerCameraManager->GetCameraLocation() + AimDirection * RayTraceRange;
		FHitResult Hit;
		bool bRayHit = GetWorld()->LineTraceSingleByChannel(
			Hit,
			PlayerCameraManager->GetCameraLocation(),
			End,
			ECollisionChannel::ECC_Visibility
		);

		if (bRayHit)
		{
			HitLocation = Hit.Location;
			return true;
		}
		else
		{
			HitLocation = FVector(0);
			return false;
		}
	}

	return false;
}

