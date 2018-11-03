// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
}

void ATankAIController::BeginPlay()
{
	/*ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController failed to possess tank!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing [%s] @ (%s)"), *ControlledTank->GetName(), *ControlledTank->GetActorLocation().ToString());
	}*/

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController failed to find player tank!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found [%s] @ (%s)"), *PlayerTank->GetName(), *PlayerTank->GetActorLocation().ToString());
	}
}


