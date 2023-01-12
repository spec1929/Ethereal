// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_HealthLan.generated.h"

UCLASS()
class ETHEREAL_API UUW_HealthLan : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AEtherealCharacter* OwnerPtr;	

	UFUNCTION(BlueprintCallable)
	void ConstructWidget(AEtherealCharacter* GoalToDisplay);
	UFUNCTION(BlueprintCallable)
	void RenewWidget();
	void SetStyle();
	
protected:
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* ProgressBar_Health;
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* ProgressBar_Magic;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CHealth;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MHealth;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CMagic;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MMagic;
	
};
