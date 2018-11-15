// Fill out your copyright notice in the Description page of Project Settings.

// class header ===============================================================
#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("%s elevate at speed %f"), *GetOwner()->GetName(), DegreesPerSecond);
}
