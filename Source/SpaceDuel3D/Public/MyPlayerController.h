// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

UCLASS()
class SPACEDUEL3D_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
	FTransform StartCameraTransform;

private:
	void SetCameraRotation();
	float AndleBetweenVectors(FVector First, FVector Second);

	void CameraHorizontal(float AxisValue);
	void CameraVertical(float AxisValue);
	void CameraZoom(float AxisValue);

	ACameraActor* Camera;
	UPROPERTY(VisibleAnywhere, Config, Category = Camera)
	float DeltaAngle;
	UPROPERTY(VisibleAnywhere, Config, Category = Camera)
	float DeltaDistance;
	UPROPERTY(VisibleAnywhere, Config, Category = Camera)
	float MaxPitch;
	UPROPERTY(VisibleAnywhere, Config, Category = Camera)
	float MinDistance;
	UPROPERTY(VisibleAnywhere, Config, Category = Camera)
	float MaxDistance;
};
