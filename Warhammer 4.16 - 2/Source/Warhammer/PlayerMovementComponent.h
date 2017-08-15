// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerMovementComponent.generated.h"

class APlayer_Char;
class ANPC;

/**
 * 
 */
UCLASS()
class WARHAMMER_API UPlayerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Settings")
	//TArray of npcs, used to check distance. If within distance will call event on that npc
	TArray<ANPC*> Enemies;

	//Function used to find all designated leaders at the start of the game.
	UFUNCTION(BlueprintCallable, Category = "Functions")
	void FilterEnemies(const TArray<AActor*> npcs, APlayer_Char* playerChar);
	
	//Function that will run during general player movement
	void MovementState();
};
