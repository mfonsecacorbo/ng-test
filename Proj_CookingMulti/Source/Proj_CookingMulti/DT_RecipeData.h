// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PaperSprite.h"
#include "DT_RecipeData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FDT_RecipeData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UPaperSprite* Icon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DeliveryTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<int32> IngredientIDs;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 PointsReward;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TimeRemaining; // Em segundos
};