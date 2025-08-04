// Fill out your copyright notice in the Description page of Project Settings.


#include "A_SpectatorCameraPawn.h"
#include "Camera/CameraComponent.h"

AA_SpectatorCameraPawn::AA_SpectatorCameraPawn()
{
    FixedCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FixedCamera"));
    FixedCamera->SetupAttachment(RootComponent);

    // Posi��o e rota��o da c�mera
    SetActorLocation(FVector(-886.17f, 0.f, 2507.57f));
    SetActorRotation(FRotator(-70.f, 0.f, 0.f));
}