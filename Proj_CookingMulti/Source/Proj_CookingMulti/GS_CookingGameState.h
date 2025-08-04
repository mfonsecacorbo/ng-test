// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DT_RecipeData.h"
#include "GS_CookingGameState.generated.h"

UCLASS()
class PROJ_COOKINGMULTI_API AGS_CookingGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    AGS_CookingGameState();

    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Orders")
    UDataTable* RecipeTable;


    UPROPERTY(ReplicatedUsing = OnRep_RemainingTime, BlueprintReadOnly, Category = "Timer")
    int32 RemainingTime;

    UPROPERTY(ReplicatedUsing = OnRep_InitialCountdown, BlueprintReadOnly, Category = "Timer")
    int32 InitialCountdown;


    void Countdown();

protected:

    FTimerHandle OrderSpawnTimer;


    void GenerateRandomOrder();

    void ScheduleNextOrder();

    FTimerHandle CountdownTimerHandle;

    UFUNCTION()
    void OnRep_RemainingTime();

    void HandleTimerFinished();

    void StartCountdown();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_InitialCountdown();

    void StartInitialCountdown();

    void InitialCountdownTick();

    bool bHasStartedMainCountdown = false;

};
