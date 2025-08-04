// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "A_SpectatorCameraPawn.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJ_COOKINGMULTI_API AA_SpectatorCameraPawn : public ASpectatorPawn
{
    GENERATED_BODY()

public:
    AA_SpectatorCameraPawn();

protected:
    UPROPERTY(VisibleAnywhere)
    class UCameraComponent* FixedCamera;
};