// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/ProgressBar.h"
#include "Components/SizeBox.h"
#include "Ethereal/EtherealCharacter.h"
#include "UW_HealthBar.generated.h"

UCLASS(Abstract)
class ETHEREAL_API UUW_HealthBar : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void ConstructWidget(AEtherealCharacter* InputOwner);
	UFUNCTION(BlueprintCallable)
	void RenewWidget() ;
	void WhiteBarDelay(){
		float i = 1 - WhiteBar->GetPercent();
		float j = 1 - HealthBar->GetPercent();
		PlayAnimationTimeRange(WhiteBarAni,i,j,1,EUMGSequencePlayMode::Forward,1.f);
	};
	void SetStyle();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TWeakObjectPtr<AEtherealCharacter> Owner;	//弱对象变量
	
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;	//血条
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* MagicBar;	//蓝条
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* WhiteBar;	//白条
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Level;	//等级
	UPROPERTY(meta = (BindWidget))
	class UBorder* BaseColor;	//底色
	UPROPERTY(Transient,meta = (BindWidgetAnim))
	class UWidgetAnimation* WhiteBarAni;	//白条动画
	UPROPERTY(meta = (BindWidget))
	class USizeBox* HealthSizeBox;
	UPROPERTY(meta = (BindWidget))
	class USizeBox* MagicSizeBox;
	UPROPERTY(meta = (BindWidget))
	class UBorder* LevelBorder;
	
};
