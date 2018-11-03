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