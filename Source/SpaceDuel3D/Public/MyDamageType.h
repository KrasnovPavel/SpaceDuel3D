// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/DamageType.h"
#include "MyDamageType.generated.h"

UCLASS()
class SPACEDUEL3D_API USpaceShipDamage : public UDamageType
{
	GENERATED_BODY()
};

UCLASS()
class SPACEDUEL3D_API USolarPanel1Damage : public UDamageType
{
	GENERATED_BODY()
};

UCLASS()
class SPACEDUEL3D_API USolarPanel2Damage : public UDamageType
{
	GENERATED_BODY()
};

UCLASS()
class SPACEDUEL3D_API UEnergy : public UDamageType
{
	GENERATED_BODY()
};
