// Fill out your copyright notice in the Description page of Project Settings.


#include "A_CookingSpectatorCam.h"

AA_CookingSpectatorCam::AA_CookingSpectatorCam()
{
	PrimaryActorTick.bCanEverTick = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	RootComponent = CameraComponent;
}

// Called when the game starts or when spawned
void AA_CookingSpectatorCam::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AA_CookingSpectatorCam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

