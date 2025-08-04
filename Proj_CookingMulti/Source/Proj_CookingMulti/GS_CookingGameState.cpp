// Fill out your copyright notice in the Description page of Project Settings.


#include "GS_CookingGameState.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"
#include "PC_CookingGameplay.h"

AGS_CookingGameState::AGS_CookingGameState()
{
    RemainingTime = 90; // 1 minuto e 30 segundos
    bReplicates = true;
    InitialCountdown = 3;
}

void AGS_CookingGameState::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority())
    {
        StartInitialCountdown();
    }
}

void AGS_CookingGameState::StartInitialCountdown()
{
    GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AGS_CookingGameState::InitialCountdownTick, 1.0f, true);
}

void AGS_CookingGameState::StartCountdown()
{
    GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AGS_CookingGameState::Countdown, 1.0f, true);
}

void AGS_CookingGameState::ScheduleNextOrder()
{
    float Delay = FMath::RandRange(3.f, 10.f);
    GetWorldTimerManager().SetTimer(OrderSpawnTimer, this, &AGS_CookingGameState::GenerateRandomOrder, Delay, false);
}

void AGS_CookingGameState::GenerateRandomOrder()
{
    if (!RecipeTable) return;

    TArray<FName> RowNames = RecipeTable->GetRowNames();
    if (RowNames.Num() == 0) return;

    int32 Index = FMath::RandRange(0, RowNames.Num() - 1);
    FName SelectedRow = RowNames[Index];
    const FDT_RecipeData* FoundRecipe = RecipeTable->FindRow<FDT_RecipeData>(SelectedRow, TEXT("Random Order"));

    if (FoundRecipe)
    {
        for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
        {
            APlayerController* PC = It->Get();
            if (APC_CookingGameplay* CookingPC = Cast<APC_CookingGameplay>(PC))
            {
                CookingPC->Client_ReceiveNewOrder(*FoundRecipe);
            }
        }
    }

    ScheduleNextOrder();
}


void AGS_CookingGameState::InitialCountdownTick()
{
    if (InitialCountdown > 0)
    {
        InitialCountdown--;
        if (InitialCountdown <= 0)
        {

            GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
            bHasStartedMainCountdown = true;
            StartCountdown();
            ScheduleNextOrder();
        }
    }
}

void AGS_CookingGameState::OnRep_InitialCountdown()
{

}

void AGS_CookingGameState::Countdown()
{
    if (RemainingTime > 0)
    {
        RemainingTime--;
        if (RemainingTime <= 0)
        {
            HandleTimerFinished();
        }
    }
}

void AGS_CookingGameState::HandleTimerFinished()
{
    GetWorldTimerManager().ClearTimer(CountdownTimerHandle);


    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        APlayerController* PC = It->Get();
        if (PC)
        {
            PC->ClientTravel("/Game/Maps/Lvl_Menu", ETravelType::TRAVEL_Absolute);
        }
    }
}

void AGS_CookingGameState::OnRep_RemainingTime()
{

}

void AGS_CookingGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(AGS_CookingGameState, InitialCountdown);
}

