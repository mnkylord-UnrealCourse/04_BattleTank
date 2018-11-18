// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"



// holds barrel elevation control methods
UCLASS( meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float SpeedMultiplier);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevation = 40;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevation = 0;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float DegreesPerSecond = 10;
};
