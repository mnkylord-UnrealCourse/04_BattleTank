// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;


// Tank class
UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Input)
	bool Fire();

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float FiringSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTime = 3;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> Projectile_BP;

	UTankBarrel* Barrel;

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	//UPROPERTY(BlueprintReadOnly)
	//UTankMovementComponent* TankMovementComponent = nullptr;

private:
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	double LastFireTime = 0;
};
