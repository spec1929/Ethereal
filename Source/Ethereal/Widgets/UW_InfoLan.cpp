// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_InfoLan.h"
#include "UW_HealthLan.h"
#include "Blueprint/UserWidget.h"
#include "Components/Overlay.h"

//构建全部
void UUW_InfoLan::ConstructTotal(AEtherealCharacter* GoalToDisplay)
{
	OwnerPtr = GoalToDisplay;
	if (HealthLanPtr == nullptr)	//无效创建控件，有效进行更新
	{
		CreateHealthWidget();
	}
	HealthLanPtr->ConstructWidget(OwnerPtr);
}

//更新全部
void UUW_InfoLan::RenewTotal()
{
	HealthLanPtr->RenewWidget();	//更新血蓝栏
		//更新技能栏
		//更新buff栏
		//更新装备栏
}

//创建血蓝栏，添加进覆层
void UUW_InfoLan::CreateHealthWidget()	
{
	if (HealthLanClass)
	{
		HealthLanPtr = CreateWidget<UUW_HealthLan>(GetWorld()->GetFirstPlayerController(),HealthLanClass);
		check(HealthLanPtr);
		Overlay_Health->AddChildToOverlay(HealthLanPtr);
	}
}
