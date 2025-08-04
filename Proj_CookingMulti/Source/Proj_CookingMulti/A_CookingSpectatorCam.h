// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "A_CookingSpectatorCam.generated.h"

UCLASS()
class PROJ_COOKINGMULTI_API AA_CookingSpectatorCam : public AActor
{
	GENERATED_BODY()
	
public:	
	AA_CookingSpectatorCam();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* CameraComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
