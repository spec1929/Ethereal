// Fill out your copyright notice in the Description page of Project Settings.


#include "EL_STFunctionLib.h"
#include "EtherealCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

//1-∑(1-x)
float UEL_STFunctionLib::Cumulation(TArray<float>InputCahce)
{
	float Cache = 1;
	for (int i = 0; i<InputCahce.Num();i++)
	{
		Cache = (1-InputCahce[i])*Cache;
	}
	Cache = 1-Cache;
	return Cache;
}
//计算总攻击力
void UEL_STFunctionLib::CalcAttackPower(AEtherealCharacter* Goal)
{
	float cache = 0.f;
	for (int i = 0;i < Goal->PlayerInfo.CalcAtt.ExPercent.Num();i++)
	{
		cache = Goal->PlayerInfo.CalcAtt.ExPercent[i] + cache;
	}
	//总攻击力=基础攻击力+额外定值+百分比叠加后
	Goal->PlayerInfo.NumInfo.AttackPower=Goal->PlayerInfo.CalcAtt.BaseAttackPower + Goal->PlayerInfo.CalcAtt.ExValue +cache;
}
//改变基础攻击力
void UEL_STFunctionLib::ChangeBaseAttack(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.CalcAtt.BaseAttackPower;
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.BaseAttackPower = i + Val;
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.BaseAttackPower = i - Val;
	}
	CalcAttackPower(Goal);
}
//改变定值额外
void UEL_STFunctionLib::ChangeExAttack(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.CalcAtt.ExValue;
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.ExValue = i + Val;
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.ExValue = i - Val;
	}
	CalcAttackPower(Goal);
}
//改变百分比额外
void UEL_STFunctionLib::ChangePercentAttack(AEtherealCharacter* Goal, float Val, bool pd)
{
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.ExPercent.Add(Val);
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.ExPercent.Remove(Val);
	}
	CalcAttackPower(Goal);
}

//计算冷却缩减
void UEL_STFunctionLib::CalcCooldownReduction(AEtherealCharacter* Goal)
{
	TArray<float> i = Goal->PlayerInfo.CalcAtt.CooldownReduction;
	Goal->PlayerInfo.NumInfo.CooldownReduction = Cumulation(i);
}
//改变冷却缩减
void UEL_STFunctionLib::ChangeCooldownReduction(AEtherealCharacter* Goal, float Val, bool pd)
{
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.CooldownReduction.Add(Val);
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.CooldownReduction.Remove(Val);
	}
	CalcCooldownReduction(Goal);
}

//计算耗蓝缩减
void UEL_STFunctionLib::CalcManaReduction(AEtherealCharacter* Goal)
{
	TArray<float> i = Goal->PlayerInfo.CalcAtt.ManaReduction;
	Goal->PlayerInfo.NumInfo.ManaReduction = Cumulation(i);
}
//改变耗蓝缩减
void UEL_STFunctionLib::ChangeManaReduction(AEtherealCharacter* Goal, float Val, bool pd)
{
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.ManaReduction.Add(Val);
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.ManaReduction.Remove(Val);
	}
	CalcManaReduction(Goal);
}

//计算魔抗
void UEL_STFunctionLib::CalcMoKang(AEtherealCharacter* Goal)
{
	TArray<float> i = Goal->PlayerInfo.CalcAtt.MagicResistance;
	Goal->PlayerInfo.NumInfo.MagicResistance = Cumulation(i);
}
//改变魔抗
void UEL_STFunctionLib::ChangeMoKang(AEtherealCharacter* Goal, float Val, bool pd)
{
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.MagicResistance.Add(Val);
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.MagicResistance.Remove(Val);
	}
	CalcMoKang(Goal);
}

//计算暴击几率
void UEL_STFunctionLib::CalcCritProbability(AEtherealCharacter* Goal)
{
	TArray<float> i = Goal->PlayerInfo.CalcAtt.CritProbability;
	Goal->PlayerInfo.NumInfo.CritProbability = Cumulation(i);
}
//改变暴击几率
void UEL_STFunctionLib::ChangeCritProbability(AEtherealCharacter* Goal, float Val, bool pd)
{
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.CritProbability.Add(Val);
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.CritProbability.Remove(Val);
	}
	CalcCritProbability(Goal);
}

//计算必中几率
void UEL_STFunctionLib::CalcHitProbability(AEtherealCharacter* Goal)
{
	TArray<float> i = Goal->PlayerInfo.CalcAtt.HitProbability;
	Goal->PlayerInfo.NumInfo.HitProbability = Cumulation(i);
}
//改变必中几率
void UEL_STFunctionLib::ChangeHitProbability(AEtherealCharacter* Goal, float Val, bool pd)
{
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.HitProbability.Add(Val);
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.HitProbability.Remove(Val);
	}
	CalcHitProbability(Goal);
}

//计算闪避几率
void UEL_STFunctionLib::CalcMissProbability(AEtherealCharacter* Goal)
{
	TArray<float> i = Goal->PlayerInfo.CalcAtt.MissProbability;
	Goal->PlayerInfo.NumInfo.MissProbability = Cumulation(i);
}
//改变闪避几率
void UEL_STFunctionLib::ChangeMissProbability(AEtherealCharacter* Goal, float Val, bool pd)
{
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.MissProbability.Add(Val);
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.MissProbability.Remove(Val);
	}
	CalcMissProbability(Goal);
}

//计算法术加成
void UEL_STFunctionLib::CalcSkillBonus(AEtherealCharacter* Goal)
{
	TArray<float> i = Goal->PlayerInfo.CalcAtt.SkillBonus;
	Goal->PlayerInfo.NumInfo.SkillBonus = Cumulation(i);
}
//改变法术加成
void UEL_STFunctionLib::ChangeSkillBonus(AEtherealCharacter* Goal, float Val, bool pd)
{
	if (pd)
	{
		Goal->PlayerInfo.CalcAtt.SkillBonus.Add(Val);
	}
	else
	{
		Goal->PlayerInfo.CalcAtt.SkillBonus.Remove(Val);
	}
	CalcSkillBonus(Goal);
}

//改变当前生命
void UEL_STFunctionLib::ChangeCHealth(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.CHealth;
	float j = Goal->PlayerInfo.NumInfo.MHealth;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.CHealth = FMath::Clamp(i + Val, 0.f, j);
	}
	else
	{
		Goal->PlayerInfo.NumInfo.CHealth = FMath::Clamp(i - Val,0.f,i);
	}
}

//改变最大生命值
void UEL_STFunctionLib::ChangeMHealth(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i =Goal->PlayerInfo.NumInfo.MHealth;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.MHealth = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.MHealth = i - Val;
	}
}

//改变当前魔法值
void UEL_STFunctionLib::ChangeCMagic(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.CMagic;
	float j = Goal->PlayerInfo.NumInfo.MMagic;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.CMagic = FMath::Clamp(i + Val, 0.f, j);
	}
	else
	{
		Goal->PlayerInfo.NumInfo.CMagic = FMath::Clamp(i - Val,0.f,i);
	}
}

//改变最大魔法值
void UEL_STFunctionLib::ChangeMMagic(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i =Goal->PlayerInfo.NumInfo.MMagic;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.MMagic = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.MMagic = i - Val;
	}
}

//改变生命恢复
void UEL_STFunctionLib::ChangeHealthRecovery(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.HealthRecovery;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.HealthRecovery = i	+ Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.HealthRecovery = fmax(i - Val,0.f);
	}
}

//改变法力恢复
void UEL_STFunctionLib::ChangeMagicRecovery(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.MagicRecovery;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.MagicRecovery = i +Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.MagicRecovery = fmax(i-Val,0.f);
	}
}

//改变当前经验
void UEL_STFunctionLib::ChangeCurrentExp(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.CExpe;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.CExpe = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.CExpe = fmax(i - Val,0.f);
	}
}

//改变攻击速度
void UEL_STFunctionLib::ChangeAttackSpeed(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.AttackSpeed;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.AttackSpeed = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.AttackSpeed = fmax(i - Val,0.f);
	}
}

//改变锻体
void UEL_STFunctionLib::ChangeForging(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.Forging;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.Forging = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.Forging = fmax(i - Val,0.f);
	}
}

//改变护甲
void UEL_STFunctionLib::ChangeArmor(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.Armor;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.Armor = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.Armor = fmax(i - Val,0.f);
	}
}

//改变施法距离加成
void UEL_STFunctionLib::ChangeCastingRangBonus(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.CastingRangeBonus;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.CastingRangeBonus = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.CastingRangeBonus = fmax(i - Val,0.f);
	}
}

//改变技能范围加成
void UEL_STFunctionLib::ChangeSkillRangBonus(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.SkillRangeBonus;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.SkillRangeBonus = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.SkillRangeBonus = fmax(i - Val,0.f);
	}
}

//改变攻击吸血
void UEL_STFunctionLib::ChangeAttackLifesteal(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.AttackLifesteal;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.AttackLifesteal = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.AttackLifesteal = fmax(i - Val,0.f);
	}
}

//改变技能吸血
void UEL_STFunctionLib::ChangeSkillLifesteal(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.SkillLifesteal;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.SkillLifesteal = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.SkillLifesteal = fmax(i - Val,0.f);
	}
}

//改变暴击系数
void UEL_STFunctionLib::ChangeCritFactor(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.CritFactor;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.CritFactor = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.CritFactor = fmax(i - Val,0.f);
	}
}

//改变虚弱
void UEL_STFunctionLib::ChangeWeak(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.Weak;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.Weak = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.Weak = fmax(i - Val,0.f);
	}
}

//改变格挡次数
void UEL_STFunctionLib::ChangeParryCount(AEtherealCharacter* Goal, int Val, bool pd)
{
	int i = Goal->PlayerInfo.NumInfo.ParryCount;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.ParryCount = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.ParryCount = fmax(i-Val,0);
	}
}

//改变格挡数值
void UEL_STFunctionLib::ChangeParryValue(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.ParryValue;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.ParryValue = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.ParryValue = fmax(i - Val,0.f);
	}
}

//改变所有伤害提高
void UEL_STFunctionLib::ChangeAllDamageIncrease(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.AllDamageIncrease;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.AllDamageIncrease = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.AllDamageIncrease = fmax(i - Val,0.f);
	}
}

//改变力量
void UEL_STFunctionLib::ChangeForce(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.NumInfo.Force;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.Force = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.Force = fmax(i - Val,0.f);
	}
}

//改变视野
void UEL_STFunctionLib::ChangeSight(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.DefInfo.Sight;
	if (pd)
	{
		Goal->PlayerInfo.DefInfo.Sight = i + Val;
	}
	else
	{
		Goal->PlayerInfo.DefInfo.Sight = fmax(i - Val,0.f);
	}
}

//改变移速
void UEL_STFunctionLib::ChangeSpeed(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.DefInfo.Speed;
	if (pd)
	{
		Goal->PlayerInfo.DefInfo.Speed = i + Val;
	}
	else
	{
		Goal->PlayerInfo.DefInfo.Speed = fmax(i - Val,0.f);
	}
	Goal->GetCharacterMovement()->MaxWalkSpeed = Goal->PlayerInfo.DefInfo.Speed;
}

//改变攻击距离
void UEL_STFunctionLib::ChangeAttackDistance(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.DefInfo.AttackDistance;
	if (pd)
	{
		Goal->PlayerInfo.DefInfo.AttackDistance = i + Val;
	}
	else
	{
		Goal->PlayerInfo.DefInfo.AttackDistance = fmax(i - Val,0.f);
	}
}

//改变敌人检测距离
void UEL_STFunctionLib::ChangeDetectionDistance(AEtherealCharacter* Goal, float Val, bool pd)
{
	float i = Goal->PlayerInfo.DefInfo.DetectionDistance;
	if (pd)
	{
		Goal->PlayerInfo.DefInfo.DetectionDistance = i + Val;
	}
	else
	{
		Goal->PlayerInfo.DefInfo.DetectionDistance = fmax(i - Val,0.f);
	}
}

//改变力量属性

void UEL_STFunctionLib::ChangeAttribute_S(AEtherealCharacter* Goal, int Val, bool pd)
{
	int i = Goal->PlayerInfo.NumInfo.Attribute_S;
	float baseattack = Val * 1;
	float speed = Val * 5;
	float attackspeed = Val * 1;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.Attribute_S = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.Attribute_S = fmax(i - Val,0);
	}
	ChangeBaseAttack(Goal,baseattack,pd);
	ChangeSpeed(Goal,speed,pd);
	ChangeAttackSpeed(Goal,attackspeed,pd);
}

//改变锻体属性
void UEL_STFunctionLib::ChangeAttribute_F(AEtherealCharacter* Goal, int Val, bool pd)
{
	int i = Goal->PlayerInfo.NumInfo.Attribute_F;
	float force = Val * 1;
	float health = Val * 20;
	float healthrecovery = Val * 0.1f;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.Attribute_F = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.Attribute_F = fmax(i - Val,0);
	}
	ChangeForce(Goal,force,pd);
	ChangeMHealth(Goal,health,pd);
	ChangeCHealth(Goal,health,pd);
	ChangeHealthRecovery(Goal,healthrecovery,pd);
}

//改变元神属性
void UEL_STFunctionLib::ChangeAttribute_Soul(AEtherealCharacter* Goal, int Val, bool pd)
{
	int i = Goal->PlayerInfo.NumInfo.Attribute_Soul;
	float sight = Val * 10;
	float missp = Val * 0.01f;
	float magic = Val * 20;
	float magicrecovery = Val * 0.2f;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.Attribute_Soul = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.Attribute_Soul = fmax(i - Val,0);
	}
	ChangeSight(Goal,sight,pd);
	ChangeMissProbability(Goal,missp,pd);
	ChangeMMagic(Goal,magic,pd);
	ChangeCMagic(Goal,magic,pd);
	ChangeMagicRecovery(Goal,magicrecovery,pd);
}

//变更等级
void UEL_STFunctionLib::ChangeLevel(AEtherealCharacter* Goal, int Val, bool pd)
{
	int i = Goal->PlayerInfo.NumInfo.Level;
	if (pd)
	{
		Goal->PlayerInfo.NumInfo.Level = i + Val;
	}
	else
	{
		Goal->PlayerInfo.NumInfo.Level = fmax(i-Val,0);
	}
	ChangeAttribute_S(Goal,Val,pd);
	ChangeAttribute_F(Goal,Val,pd);
	ChangeAttribute_Soul(Goal,Val,pd);
}

//计算所有
void UEL_STFunctionLib::CalcAllCalc(AEtherealCharacter* Goal)
{
	CalcAttackPower(Goal);
	CalcCooldownReduction(Goal);
	CalcManaReduction(Goal);
	CalcMoKang(Goal);
	CalcCritProbability(Goal);
	CalcHitProbability(Goal);
	CalcMissProbability(Goal);
	CalcSkillBonus(Goal);
}

//设置无敌状态
void UEL_STFunctionLib::SetWuDi(AEtherealCharacter* Goal, bool pd)
{
	Goal->PlayerInfo.State.bWuDi = pd;
}

//设置物免状态
void UEL_STFunctionLib::SetWuMian(AEtherealCharacter* Goal, bool pd)
{
	Goal->PlayerInfo.State.bWuMian = pd;
}

//设置魔免状态
void UEL_STFunctionLib::SetMoMian(AEtherealCharacter* Goal, bool pd)
{
	Goal->PlayerInfo.State.bMoMian = pd;
}

//设置沉默状态
void UEL_STFunctionLib::SetSlience(AEtherealCharacter* Goal, bool pd)
{
	Goal->PlayerInfo.State.bSlience = pd;
}

//设置缴械状态
void UEL_STFunctionLib::SetJiaoXie(AEtherealCharacter* Goal, bool pd)
{
	Goal->PlayerInfo.State.bJiaoXie = pd;
}

//设置警戒状态
void UEL_STFunctionLib::SetJingJie(AEtherealCharacter* Goal, bool pd)
{
	Goal->PlayerInfo.State.bJingjie = pd;
}

//设置隐身状态
void UEL_STFunctionLib::SetYinShen(AEtherealCharacter* Goal, bool pd)
{
	Goal->PlayerInfo.State.bYinShen = pd;
}

//设置真视暴露
void UEL_STFunctionLib::SetBaoLuZhenShi(AEtherealCharacter* Goal, bool pd)
{
	Goal->PlayerInfo.State.bBaoLuZhenShi = pd;
}

//设置视野暴露
void UEL_STFunctionLib::SetBaoLuShiYe(AEtherealCharacter* Goal, bool pd)
{
	Goal->PlayerInfo.State.bBaoLuShiYe = pd;
}

