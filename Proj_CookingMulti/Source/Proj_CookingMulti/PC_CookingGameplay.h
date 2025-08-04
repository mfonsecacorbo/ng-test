// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DT_RecipeData.h"
#include "PC_CookingGameplay.generated.h"


/**
 * 
 */
UCLASS()
class PROJ_COOKINGMULTI_API APC_CookingGameplay : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void TryInteract();

    UFUNCTION(Client, Reliable)
    void Client_ReceiveNewOrder(const FDT_RecipeData& NewOrder);

    UFUNCTION(Server, Reliable)
    void Server_InteractWithActor(AActor* TargetActor);

    UFUNCTION(BlueprintImplementableEvent)
    void ShowHeldItemIcon(UPaperSprite* Icon);

    void GiveHeldItem(const FDT_RecipeData& Recipe);

private:
    UPROPERTY(Replicated)
    int32 HeldItemID;

};
