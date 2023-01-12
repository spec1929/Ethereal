// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_HUD.h"
#include "UW_InfoLan.h"
#include "Blueprint/UserWidget.h"
#include "Components/Overlay.h"

void UUW_HUD::NativeConstruct()		//事件构建
{
	Super::NativeConstruct();
	//Construct_InfoLanWidget(true,OwnerPtr);
}


//创建信息栏控件
void UUW_HUD::Construct_InfoLanWidget(bool bDisplay,AEtherealCharacter* Goal)
{
	OwnerPtr = Goal;
	if (InfoLanClass)
	{
		switch (bDisplay)
		{
		case true:	//构建默认角色信息
			if (InfoLanPtr == nullptr)
			{
				InfoLanPtr =  CreateWidget<UUW_InfoLan>(GetWorld()->GetFirstPlayerController(),InfoLanClass);
				check(InfoLanPtr);
				InfoLanOverlay->AddChildToOverlay(InfoLanPtr);	//添加子项到覆层
			}
			InfoLanPtr->ConstructTotal(Goal);
			break;
		case false:	//构建新角色信息
			if (InfoLanPtr_New == nullptr)
			{
				InfoLanPtr_New = CreateWidget<UUW_InfoLan>(GetWorld()->GetFirstPlayerController(),InfoLanClass);
				check(InfoLanPtr_New);
				InfoLanOverlay->AddChildToOverlay(InfoLanPtr_New); //添加子项到覆层
			}
			InfoLanPtr_New->ConstructTotal(Goal);
			if (InfoLanPtr)
			{
				InfoLanPtr->SetVisibility(ESlateVisibility::Hidden);	//创建新的就将默认的隐藏
			}
			break;
		}
	}
	
	
}

//更新信息栏
void UUW_HUD::Renew_InfoLanWidget()
{
	if (InfoLanPtr)
	{
		InfoLanPtr->RenewTotal();
	}
	if (InfoLanPtr_New)
	{
		InfoLanPtr_New->RenewTotal();
	}
}


//WB_Info控件默认归位
void UUW_HUD::ResetInfoLanWidget()
{
	if (InfoLanPtr->GetVisibility() != ESlateVisibility::Visible)
	{
		InfoLanPtr->SetVisibility(ESlateVisibility::Visible);
		if (InfoLanPtr_New)
		{
			InfoLanPtr_New->RemoveFromParent();
			InfoLanPtr_New = nullptr;
		}
	}
}

