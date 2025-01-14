// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "STreasureChest.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASTreasureChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	float TargetPitch;
	
	void Interact_Implementation(APawn* InstigatorPawn);
public:	
	// Sets default values for this actor's properties
	ASTreasureChest();

protected:

	UPROPERTY(ReplicatedUsing = "OnRep_LidOpened", BlueprintReadOnly) // RepNotify
	bool bLidOpened;

	UFUNCTION()
	void OnRep_LidOpened();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* LidMesh;

public:	


};
