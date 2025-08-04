// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Menu.h"
#include "Proj_CookingMultiPlayerController.h"
#include "Proj_CookingMultiCharacter.h"

AGM_Menu::AGM_Menu()
{
    PlayerControllerClass = AProj_CookingMultiPlayerController::StaticClass();
    DefaultPawnClass = nullptr;
}