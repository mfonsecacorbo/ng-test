// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_CookingMulti.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_CookingMulti.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void UGI_CookingMulti::HostGame(const FString& PlayerName)
{
    PlayerNickname = PlayerName;

}


void UGI_CookingMulti::JoinGame(const FString& IPAddress, const FString& PlayerName)
{
    PlayerNickname = PlayerName;

    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (PC)
    {
        PC->ClientTravel(IPAddress, ETravelType::TRAVEL_Absolute);
    }
}
