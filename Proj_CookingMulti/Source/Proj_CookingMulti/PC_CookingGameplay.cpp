// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_CookingGameplay.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "DT_RecipeData.h"
#include "Actors/A_ItemStashActor.h"
#include "H_CookingHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

void APC_CookingGameplay::BeginPlay()
{
    Super::BeginPlay();

    SetShowMouseCursor(false);
    SetInputMode(FInputModeGameOnly());

    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        SetViewTargetWithBlend(ControlledPawn);
    }
}

void APC_CookingGameplay::Client_ReceiveNewOrder_Implementation(const FDT_RecipeData& NewOrder)
{
    if (AH_CookingHUD* CookingHUD = Cast<AH_CookingHUD>(GetHUD()))
    {
        TArray<FDT_RecipeData> Orders;
        Orders.Add(NewOrder);
        CookingHUD->UpdateTimerWidgetOrders(Orders);

    }
}

void APC_CookingGameplay::GiveHeldItem(const FDT_RecipeData& Recipe)
{
    HeldItemID = Recipe.ID;
    ShowHeldItemIcon(Recipe.Icon);
}

void APC_CookingGameplay::Server_InteractWithActor_Implementation(AActor* TargetActor)
{
    if (TargetActor)
    {
        if (AA_ItemStashActor* Stash = Cast<AA_ItemStashActor>(TargetActor))
        {
            Stash->OnInteract(this);
        }
    }
}

void APC_CookingGameplay::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(APC_CookingGameplay, HeldItemID);
}

void APC_CookingGameplay::TryInteract()
{
    FVector Start = PlayerCameraManager->GetCameraLocation();
    FVector End = Start + PlayerCameraManager->GetActorForwardVector() * 200.f;

    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(GetPawn());

    if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
    {
        if (AA_ItemStashActor* Stash = Cast<AA_ItemStashActor>(Hit.GetActor()))
        {
            Stash->OnInteract(this);
        }
    }
}
