// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DT_RecipeData.h"
#include "A_ItemStashActor.generated.h"

UCLASS()
class PROJ_COOKINGMULTI_API AA_ItemStashActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_ItemStashActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int32 RecipeID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
	UDataTable* RecipeDataTable;

	const FDT_RecipeData* GetRecipeData() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* InteractionBox;

	UFUNCTION()
	void OnInteract(class APlayerController* InteractingController);

	UPROPERTY(EditAnywhere, Category = "UI")
	class UBillboardComponent* ItemIcon;

};
