// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DT_RecipeData.h"
#include "H_CookingHUD.generated.h"

UCLASS()
class PROJ_COOKINGMULTI_API AH_CookingHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

    UFUNCTION(BlueprintImplementableEvent, Category = "UI")
    void UpdateTimerWidgetOrders(const TArray<FDT_RecipeData>& Orders);

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UUserWidget> TimerWidgetClass;


    UPROPERTY(BlueprintReadOnly, Category = "UI")
    UUserWidget* TimerWidget;
};
