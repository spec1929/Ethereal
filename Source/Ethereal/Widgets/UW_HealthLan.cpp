// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_HealthLan.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Ethereal/EtherealCharacter.h"

//构建
void UUW_HealthLan::ConstructWidget(AEtherealCharacter* GoalToDisplay)
{
	OwnerPtr = GoalToDisplay;
	SetStyle();
	RenewWidget();
}

//更新
void UUW_HealthLan::RenewWidget()
{
	ProgressBar_Health->SetPercent(OwnerPtr->PlayerInfo.NumInfo.CHealth / OwnerPtr->PlayerInfo.NumInfo.MHealth);
	ProgressBar_Magic->SetPercent(OwnerPtr->PlayerInfo.NumInfo.CMagic / OwnerPtr->PlayerInfo.NumInfo.MMagic);
	CHealth->SetText(FText::AsNumber(OwnerPtr->PlayerInfo.NumInfo.CHealth));
	MHealth->SetText(FText::AsNumber(OwnerPtr->PlayerInfo.NumInfo.MHealth));
	CMagic->SetText(FText::AsNumber(OwnerPtr->PlayerInfo.NumInfo.CMagic));
	MMagic->SetText(FText::AsNumber(OwnerPtr->PlayerInfo.NumInfo.MMagic));
}

//根据阵营设置血条颜色
void UUW_HealthLan::SetStyle()
{
	switch (OwnerPtr->PlayerInfo.Camp)
	{
	case E_Camp::Randiant:
		ProgressBar_Health->SetFillColorAndOpacity(FLinearColor(0.158161,0.432292,0.214526,1));
		break;
	case E_Camp::Dire:
		ProgressBar_Health->SetFillColorAndOpacity(FLinearColor(1,0.05098,0.098039,1));
		break;
	case E_Camp::Neutral:
		ProgressBar_Health->SetFillColorAndOpacity(FLinearColor(0.269213,0.059408,0.760417,1));
		break;
	default:
		ProgressBar_Health->SetFillColorAndOpacity(FLinearColor(0.158161,0.432292,0.214526,1));
		break;
	}
	
}
