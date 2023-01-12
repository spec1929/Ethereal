// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_HealthBar.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UUW_HealthBar::ConstructWidget(AEtherealCharacter* InputOwner)	//构建Widget
{
	Owner = InputOwner;
	SetStyle();
	RenewWidget();
	
}

void UUW_HealthBar::RenewWidget()	//更新Widget
{
	
	HealthBar->SetPercent(Owner->PlayerInfo.NumInfo.CHealth / Owner->PlayerInfo.NumInfo.MHealth);
	MagicBar->SetPercent(Owner->PlayerInfo.NumInfo.CMagic / Owner->PlayerInfo.NumInfo.MMagic);
	//FNumberFormattingOptions Opts;
	//Opts.SetMaximumFractionalDigits(0);
	Level->SetText(FText::AsNumber(Owner->PlayerInfo.NumInfo.Level));
	WhiteBarDelay();
}

void UUW_HealthBar::SetStyle()
{
	switch (Owner->PlayerInfo.Strength)	//区分精英和小怪
	{
	case E_Strength::Elite:
		HealthSizeBox->SetWidthOverride(135);
		MagicSizeBox->SetVisibility(ESlateVisibility::Visible);
		LevelBorder->SetVisibility(ESlateVisibility::Visible);
		break;
	case E_Strength::Normal:
		HealthSizeBox->SetWidthOverride(100);
		MagicSizeBox->SetVisibility(ESlateVisibility::Hidden);
		LevelBorder->SetVisibility(ESlateVisibility::Hidden);
		break;
	default:
		HealthSizeBox->SetWidthOverride(135);
		MagicSizeBox->SetVisibility(ESlateVisibility::Hidden);
		LevelBorder->SetVisibility(ESlateVisibility::Hidden);
		break;
	}

	switch (Owner->PlayerInfo.Camp)
	{
	case E_Camp::Randiant:
		HealthBar->SetFillColorAndOpacity(FLinearColor(0.094856,0.536458,0.156093,1));	//血条绿
		BaseColor->SetBrushColor(FLinearColor(0.022103,0.067708,0.029212,1));	//底色暗绿
		break;
	case E_Camp::Dire:
		HealthBar->SetFillColorAndOpacity(FLinearColor(1,0.083333,0.083333,1));	//血条红
		BaseColor->SetBrushColor(FLinearColor(0.244792,0.014025,0.014025,1));	//底色暗绿
		break;
	case E_Camp::Neutral:
		HealthBar->SetFillColorAndOpacity(FLinearColor(0.217104,0.108173,1,1));	//血条紫
		BaseColor->SetBrushColor(FLinearColor(0.044099,0.021973,0.203125,1));	//底色暗紫
		break;
	default:
		HealthBar->SetFillColorAndOpacity(FLinearColor(0.094856,0.536458,0.156093,1));	//血条绿
		BaseColor->SetBrushColor(FLinearColor(0.022103,0.067708,0.029212,1));	//底色暗绿
		break;
	}
}
