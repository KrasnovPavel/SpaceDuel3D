// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceDuel3D.h"
#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
	bAutoManageActiveCameraTarget = false;
	StartCameraTransform.SetLocation(FVector(-2000.0f, 0.0f, 0.0f));
	StartCameraTransform.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
	StartCameraTransform.SetScale3D(FVector(1.0f, 1.0f, 1.0f));
	DeltaAngle = 3.0f;
	MaxPitch = 80.0f;
	DeltaDistance = 100.0f;
	MinDistance = 1000.0f;
	MaxDistance = 10000.0f;
}

void AMyPlayerController::BeginPlay()
{
	Camera = GetWorld()->SpawnActor<ACameraActor>();
	Camera->SetActorTransform(StartCameraTransform);
	SetViewTarget(Camera);
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("CameraHorizontal", this, &AMyPlayerController::CameraHorizontal);
	InputComponent->BindAxis("CameraVertical", this, &AMyPlayerController::CameraVertical);
	InputComponent->BindAxis("CameraZoom", this, &AMyPlayerController::CameraZoom);
}

void AMyPlayerController::CameraHorizontal(float AxisValue)
{
	Camera->SetActorLocation(
			Camera->GetActorLocation().RotateAngleAxis(DeltaAngle * AxisValue, FVector(0.0f, 0.0f, 1.0f)));
	SetCameraRotation();
}

void AMyPlayerController::CameraVertical(float AxisValue)
{
	FRotator Rotation = Camera->GetActorLocation().Rotation();
	bool bInRange = Rotation.Pitch >= -MaxPitch && Rotation.Pitch <= MaxPitch;
	if (bInRange || Rotation.Pitch < -MaxPitch && AxisValue < 0
				 || Rotation.Pitch > MaxPitch && AxisValue > 0)
	{
		Camera->SetActorLocation(
				Camera->GetActorLocation().RotateAngleAxis(-DeltaAngle * AxisValue, Camera->GetActorRightVector()));
		SetCameraRotation();
	}
}

void AMyPlayerController::CameraZoom(float AxisValue)
{
	float Distance = Camera->GetActorLocation().Size();
	bool bInRange = Distance >= MinDistance && Distance <= MaxDistance;
	if (bInRange || Distance < MinDistance && AxisValue < 0
				 || Distance > MaxDistance && AxisValue > 0)
	{
		FVector NewLocation = Camera->GetActorLocation()
								+ Camera->GetActorLocation().GetSafeNormal() * -DeltaDistance * AxisValue;
		Camera->SetActorLocation(NewLocation);
	}
}

void AMyPlayerController::SetCameraRotation()
{
	Camera->SetActorRotation(Camera->GetActorLocation().Rotation());
	Camera->AddActorLocalRotation(FRotator(0.0f, 180.0f, 0.0f));
}
