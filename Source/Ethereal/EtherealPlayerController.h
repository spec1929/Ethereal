// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EtherealCharacter.h"
#include "EtherealGameMode.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "EL_HUD.h"
#include "EtherealPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;

UCLASS()
class AEtherealPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AEtherealPlayerController();

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	// ReSharper disable once UnrealHeaderToolError
	class UInputMappingContext* EtherealMappingContext;
	
	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* RightMouseClick;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* LeftMouseClick;
	
	//指针
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	AEtherealCharacter* ELCharacterPtr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	class  AEL_Camera* SightCameraPtr;
	AEL_HUD* HudPtr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Input)
		TArray<AEtherealCharacter*> SelectedPlayers;

	//UWHud中的信息栏归位
	UFUNCTION(BlueprintCallable)
	void ResetInfoLanWidget();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	virtual void SetupInputComponent() override;
	
	virtual void BeginPlay();

	//输入操作对应事件
	void OnInputStarted();
	void OnLClickStarted();
	void OnLClickTriggered();
	void OnLClickReleased();
	void OnRClickTriggered();
	void OnRClickReleased();

	//开启镜头
	void OpenCamera();

	//声明UW_HUD的子类，声明UW_HUD的引用
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUW_HUD> UWHudClass;
	UPROPERTY()
		class UUW_HUD* UWHudPtr;
	

private:
	FVector CachedDestination;

	
	float FollowTime; // For how long it has been pressed
};


