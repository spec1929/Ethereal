// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EL_STFunctionLib.h"
#include "GameFramework/Character.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "EtherealCharacter.generated.h"

UCLASS(Blueprintable)
class AEtherealCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEtherealCharacter();

	// 每帧调用
	virtual void Tick(float DeltaSeconds) override;
	
	//延迟贴花组件
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UDecalComponent* Decal;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FName PlayerRowName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FST_PlayersInfo PlayerInfo;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FST_DamageState DamageState;
	
	UFUNCTION(BlueprintCallable)
		void SetSelected();
	UFUNCTION(BlueprintCallable)
		void SetDeselected();
	UFUNCTION(BlueprintCallable)
		void ConstructHealthBarWidget();
	UFUNCTION(BlueprintCallable)
		void RenewHealthBarWidget();


protected:
	// 开始时调用
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* HealthWidgetComp;
	
};

