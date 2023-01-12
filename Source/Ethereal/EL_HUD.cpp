// Fill out your copyright notice in the Description page of Project Settings.


#include "EL_HUD.h"

FVector2D AEL_HUD::GetMousePos2D()
{
	float PositionX;
	float PositionY;
	GetOwningPlayerController()->GetMousePosition(PositionX,PositionY);
	return FVector2D(PositionX,PositionY);
}

void AEL_HUD::DrawHUD()
{
	if (bStartSelecting)
	{
		CancelSelectCache();	//取消选中缓存
		SelectedPlayersCache.Empty();	//选中缓存数组清空
		CurrentPoint = GetMousePos2D();	//获取当前点
		
		//画矩形
		DrawRect(FLinearColor(0,1,0,0.1f),InitialPoint.X,InitialPoint.Y,CurrentPoint.X-InitialPoint.X,CurrentPoint.Y-InitialPoint.Y);
		//画线框
		DrawLine(InitialPoint.X,InitialPoint.Y,CurrentPoint.X,InitialPoint.Y,LColor,1.f);
		DrawLine(InitialPoint.X,InitialPoint.Y,InitialPoint.X,CurrentPoint.Y,LColor,1.f);
		DrawLine(CurrentPoint.X,InitialPoint.Y,CurrentPoint.X,CurrentPoint.Y,LColor,1.f);
		DrawLine(InitialPoint.X,CurrentPoint.Y,CurrentPoint.X,CurrentPoint.Y,LColor,1.f);

		//存入选中角色到SelectedPlayersCache
		GetActorsInSelectionRectangle<AEtherealCharacter>(InitialPoint,CurrentPoint,SelectedPlayersCache,false,false);
		MarkSelectCache();
		
	}
}
//标记选中
void AEL_HUD::MarkSelect()
{
	if (SelectedPlayers.Num()>0)
	{
		for(int i = 0; i < SelectedPlayers.Num();i++)
		{
			SelectedPlayers[i]->SetSelected();
		}
	}
}
//取消标记
void AEL_HUD::CancelSelect()
{
	if (SelectedPlayers.Num()>0)
	{
		for (int i =0;i<SelectedPlayers.Num();i++)
		{
			SelectedPlayers[i]->SetDeselected();
		}
	}
}

//标记选中缓存
void AEL_HUD::MarkSelectCache()
{
	if (SelectedPlayersCache.Num()>0)
	{
		for (int i=0;i<SelectedPlayersCache.Num();i++)
		{
			SelectedPlayersCache[i]->SetSelected();
		}
	}
}
//取消标记选中缓存
void AEL_HUD::CancelSelectCache()
{
	if (SelectedPlayersCache.Num()>0)
	{
		for (int i=0;i<SelectedPlayersCache.Num();i++)
		{
			SelectedPlayersCache[i]->SetDeselected();
		}
	}
}

void AEL_HUD::Compare()
{
	if(SelectedPlayersCache.Num()>0)
	{
		CancelSelect();
		SelectedPlayers = SelectedPlayersCache;
		MarkSelect();
	}
}


