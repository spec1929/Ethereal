// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_HUD.generated.h"


UCLASS(Abstract)
class ETHEREAL_API UUW_HUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AEtherealCharacter* OwnerPtr;	

	UFUNCTION(BlueprintCallable)
	void Construct_InfoLanWidget(bool bDisplay,AEtherealCharacter* Goal);	//构建信息栏
	UFUNCTION(BlueprintCallable)
	void Renew_InfoLanWidget();	//更新信息栏
	UFUNCTION(BlueprintCallable)
	void ResetInfoLanWidget();	//信息栏归位默认
	
protected:
	void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	class UOverlay* InfoLanOverlay; //信息栏覆层

	//声明UW_InfoLan类的子类，声明UW_InfoLan的指针(一个默认角色，一个新角色)
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUW_InfoLan> InfoLanClass;
	UPROPERTY()
	class UUW_InfoLan* InfoLanPtr;	//默认角色的
	UPROPERTY()
	class UUW_InfoLan* InfoLanPtr_New;	//新增角色的
	
};

