// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_InfoLan.generated.h"

UCLASS()
class ETHEREAL_API UUW_InfoLan : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AEtherealCharacter* OwnerPtr;
	UFUNCTION(BlueprintCallable)
	void ConstructTotal(AEtherealCharacter* GoalToDisplay);	//构建全部
	UFUNCTION(BlueprintCallable)
	void RenewTotal();	//更新全部
	void CreateHealthWidget();	//创建血蓝栏，添加进覆层
	
protected:
	UPROPERTY(meta = (BindWidget))
	class UWrapBox* WrapBox_Buff;
	UPROPERTY(meta = (BindWidget))
	class UOverlay* Overlay_Health;
	UPROPERTY(meta = (BindWidget))
	class UOverlay* Overlay_Skill;
	UPROPERTY(meta = (BindWidget))
	class UUniformGridPanel* UGP_Equipment;

	//声明UW_HealthLan类的子类，声明UW_HealthLan的指针
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUW_HealthLan> HealthLanClass;
	UPROPERTY()
	class UUW_HealthLan* HealthLanPtr;	
};
