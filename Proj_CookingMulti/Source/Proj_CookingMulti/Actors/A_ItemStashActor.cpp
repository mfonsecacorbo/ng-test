// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/A_ItemStashActor.h"
#include "Components/BoxComponent.h"
#include "Components/BillboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PC_CookingGameplay.h"
#include "DT_RecipeData.h"

// Sets default values
AA_ItemStashActor::AA_ItemStashActor()
{
    PrimaryActorTick.bCanEverTick = false;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBox"));
    InteractionBox->SetupAttachment(RootComponent);
    InteractionBox->SetBoxExtent(FVector(100.f));
    InteractionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    InteractionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
    InteractionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    ItemIcon = CreateDefaultSubobject<UBillboardComponent>(TEXT("ItemIcon"));
    ItemIcon->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AA_ItemStashActor::BeginPlay()
{
	Super::BeginPlay();
	
}

const FDT_RecipeData* AA_ItemStashActor::GetRecipeData() const
{
    if (RecipeDataTable)
    {
        static const FString Context = TEXT("StashRecipeLookup");
        return RecipeDataTable->FindRow<FDT_RecipeData>(FName(*FString::FromInt(RecipeID)), Context);
    }
    return nullptr;
}


void AA_ItemStashActor::OnInteract(APlayerController* InteractingController)
{
    if (APC_CookingGameplay* PC = Cast<APC_CookingGameplay>(InteractingController))
    {
        if (const FDT_RecipeData* Recipe = GetRecipeData())
        {
            PC->GiveHeldItem(*Recipe);
        }
    }
}

// Called every frame
void AA_ItemStashActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

