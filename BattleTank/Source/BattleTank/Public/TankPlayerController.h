// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"


class ATank;

// player controller
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float CrossHairYLocation = 1.0f / 3.0f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float RayTraceRange = 1000000.0f;
	
	virtual void BeginPlay() override;
	virtual void Tick(float) override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation);
	
};
