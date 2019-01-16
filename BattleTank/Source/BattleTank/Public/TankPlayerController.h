// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"



class ATank;
class UTankAimingComponent;



// player controller
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = Setup)
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimingComponent *AimingComponent);
	
private:
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
