// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EtherealCharacter.h"
#include "EL_HUD.generated.h"

/**
 * 
 */
UCLASS()
class ETHEREAL_API AEL_HUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual  void DrawHUD() override;
	FVector2D InitialPoint;	//起始点
	FVector2D CurrentPoint;	//当前点
	bool bStartSelecting = false;	//开始选择布尔
	FLinearColor LColor = {0,1,0,0.7f};
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<AEtherealCharacter*> SelectedPlayers;
	TArray<AEtherealCharacter*> SelectedPlayersCache;

	FVector2D GetMousePos2D();
	void MarkSelect();
	void CancelSelect();
	void MarkSelectCache();
	void CancelSelectCache();
	void Compare();

	
};
