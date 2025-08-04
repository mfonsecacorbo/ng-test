// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Cooking.h"
#include "CookingCharacter.h"
#include "PC_CookingGameplay.h"
#include "GS_CookingGameState.h"
#include "EngineUtils.h"

AGM_Cooking::AGM_Cooking()
{
    DefaultPawnClass = ACookingCharacter::StaticClass();
    PlayerControllerClass = APC_CookingGameplay::StaticClass();
    GameStateClass = AGS_CookingGameState::StaticClass();
}

void AGM_Cooking::BeginPlay()
{
    Super::BeginPlay();

}