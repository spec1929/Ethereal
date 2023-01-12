// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "EL_STFunctionLib.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ETHEREAL_API UEL_STFunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable)	//1-∑(1-x)
		static float Cumulation(TArray<float>InputCahce);
	UFUNCTION(BlueprintCallable)	//计算攻击力
		static void CalcAttackPower(AEtherealCharacter* Goal);
	UFUNCTION(BlueprintCallable)
		static void ChangeBaseAttack(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeExAttack(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangePercentAttack(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)	//计算冷却缩减
		static void CalcCooldownReduction(AEtherealCharacter* Goal);
	UFUNCTION(BlueprintCallable)
		static void ChangeCooldownReduction(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)	//计算耗蓝缩减
		static void CalcManaReduction(AEtherealCharacter* Goal);
	UFUNCTION(BlueprintCallable)
		static void ChangeManaReduction(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)	//计算魔抗
		static void CalcMoKang(AEtherealCharacter* Goal);
	UFUNCTION(BlueprintCallable)
		static void ChangeMoKang(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)	//计算暴击几率
		static void CalcCritProbability(AEtherealCharacter* Goal);
	UFUNCTION(BlueprintCallable)
		static void ChangeCritProbability(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)	//计算必中几率
		static void CalcHitProbability(AEtherealCharacter* Goal);
	UFUNCTION(BlueprintCallable)
		static void ChangeHitProbability(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)	//计算闪避几率
		static void CalcMissProbability(AEtherealCharacter* Goal);
	UFUNCTION(BlueprintCallable)
		static void ChangeMissProbability(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)	//计算法术加成
		static void CalcSkillBonus(AEtherealCharacter* Goal);
	UFUNCTION(BlueprintCallable)
		static void ChangeSkillBonus(AEtherealCharacter* Goal,float Val,bool pd);
	/*改变类*/
	UFUNCTION(BlueprintCallable)
		static void ChangeCHealth(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeMHealth(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeCMagic(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeMMagic(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeHealthRecovery(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeMagicRecovery(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeCurrentExp(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeAttackSpeed(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeForging(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeArmor(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeCastingRangBonus(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeSkillRangBonus(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeAttackLifesteal(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeSkillLifesteal(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeCritFactor(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeWeak(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeParryCount(AEtherealCharacter* Goal,int Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeParryValue(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeAllDamageIncrease(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeForce(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeSight(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeSpeed(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeAttackDistance(AEtherealCharacter* Goal,float Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeDetectionDistance(AEtherealCharacter* Goal,float Val,bool pd);
	/*属性更改*/
	UFUNCTION(BlueprintCallable)
		static void ChangeAttribute_S(AEtherealCharacter* Goal,int Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeAttribute_F(AEtherealCharacter* Goal,int Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void ChangeAttribute_Soul(AEtherealCharacter* Goal,int Val,bool pd);

	UFUNCTION(BlueprintCallable)
		static void ChangeLevel(AEtherealCharacter* Goal,int Val,bool pd);
	UFUNCTION(BlueprintCallable)
		static void CalcAllCalc(AEtherealCharacter* Goal);

	/*设置布尔状态*/
	UFUNCTION(BlueprintCallable)
		static void SetWuDi(AEtherealCharacter* Goal,bool pd);
	UFUNCTION(BlueprintCallable)
		static void SetWuMian(AEtherealCharacter* Goal,bool pd);
	UFUNCTION(BlueprintCallable)
		static void SetMoMian(AEtherealCharacter* Goal,bool pd);
	UFUNCTION(BlueprintCallable)
		static void SetSlience(AEtherealCharacter* Goal,bool pd);
	UFUNCTION(BlueprintCallable)
		static void SetJiaoXie(AEtherealCharacter* Goal,bool pd);
	UFUNCTION(BlueprintCallable)
		static void SetJingJie(AEtherealCharacter* Goal,bool pd);
	UFUNCTION(BlueprintCallable)
		static void SetYinShen(AEtherealCharacter* Goal,bool pd);
	UFUNCTION(BlueprintCallable)
		static void SetBaoLuZhenShi(AEtherealCharacter* Goal,bool pd);
	UFUNCTION(BlueprintCallable)
		static void SetBaoLuShiYe(AEtherealCharacter* Goal,bool pd);
	

	
};


//阵营枚举
UENUM(BlueprintType)
enum class E_Camp:uint8
{
	Randiant,Dire,Neutral,
};
//强度枚举
UENUM(BlueprintType)
enum class E_Strength:uint8
{
	Elite,Normal
};

USTRUCT(BlueprintType)
struct FST_NumericalInfos :public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		int Level = 1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float CHealth = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MHealth = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CMagic = 120.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MMagic = 120.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HealthRecovery = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MagicRecovery = 1.2f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CExpe = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackPower = 5.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackSpeed = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Forging;	//锻体
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Armor;	//护甲
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CastingRangeBonus;	//施法范围加成
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SkillRangeBonus;	//技能范围加成
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackLifesteal;	//攻击吸血
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SkillLifesteal;	//技能吸血
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CritFactor;	//暴击系数
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Weak;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ParryCount;	//格挡次数
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ParryValue;	//格挡数值
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AllDamageIncrease;	//所有伤害提高
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Force;	//力量
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MagicResistance;	//魔抗
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CooldownReduction;	//冷却缩减
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ManaReduction;	//耗蓝缩减
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CritProbability;		//暴击几率
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HitProbability;		//必中率
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MissProbability;		//闪避率
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SkillBonus;			//法术加成
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Attribute_S = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Attribute_F =10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Attribute_Soul =10.f;
};

//默认信息
USTRUCT(BlueprintType)
struct FST_DefaultInfos
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Sight = 800.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed = 300.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BAT = 1.7f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TurnRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 AttackDistance = 150.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 DetectionDistance = 800.f;
};

//属性计算
USTRUCT(BlueprintType)
struct FST_CalcAttributes //:public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseAttackPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ExValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> ExPercent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> MagicResistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> CritProbability;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> HitProbability;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> MissProbability;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> SkillBonus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> CooldownReduction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> ManaReduction;
};

//状态
USTRUCT(BlueprintType)
struct FST_PlayerState //:public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bWuDi;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bMoMian;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bWuMian;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSlience;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bJiaoXie;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bJingjie;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bYinShen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bBaoLuZhenShi;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bBaoLuShiYe;
};

//攻击状态
USTRUCT(BlueprintType)
struct FST_DamageState //:public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAttacking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMiss;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCrit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHuShen;
};
//角色信息
USTRUCT()
struct FST_PlayersInfo:public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FST_NumericalInfos NumInfo;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FST_PlayerState State;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FST_DefaultInfos DefInfo;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		E_Camp Camp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		E_Strength Strength;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		bool Dead;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FName Name;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FST_CalcAttributes CalcAtt;
};
