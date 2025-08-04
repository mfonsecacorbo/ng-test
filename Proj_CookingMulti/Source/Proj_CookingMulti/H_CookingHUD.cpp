// Fill out your copyright notice in the Description page of Project Settings.


#include "H_CookingHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GS_CookingGameState.h"

void AH_CookingHUD::BeginPlay()
{
    Super::BeginPlay();

    if (TimerWidgetClass)
    {
        TimerWidget = CreateWidget<UUserWidget>(GetWorld(), TimerWidgetClass);
        if (TimerWidget)
        {
            TimerWidget->AddToViewport();
        }
    }
}


