#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GI_CookingMulti.generated.h"

UCLASS()
class PROJ_COOKINGMULTI_API UGI_CookingMulti : public UGameInstance
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, Category = "Multiplayer")
    FString PlayerNickname;

    UFUNCTION(BlueprintCallable, Category = "Multiplayer")
    void HostGame(const FString& PlayerName);

    UFUNCTION(BlueprintCallable, Category = "Multiplayer")
    void JoinGame(const FString& IPAddress, const FString& PlayerName);

};