// Copyright Epic Games, Inc. All Rights Reserved.

#include "EtherealCharacter.h"

//#include "ActiveSocket.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Widgets/UW_HealthBar.h"
#include "Engine/World.h"

AEtherealCharacter::AEtherealCharacter()
{
	// 设置胶囊体大小	Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// 禁止旋转玩家朝向相机方向	Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// 配置角色移动Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// 激活Tick以每帧更新光标	Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	//创建贴纸
	Decal=CreateDefaultSubobject<UDecalComponent>(TEXT("HaloDecal"));	//创建
	Decal->SetupAttachment(RootComponent);	//附加
	Decal->DecalSize = FVector(16.f, 64.f, 64.f);	//尺寸
	Decal->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));	//旋转
	Decal->SetRelativeLocation(FVector(0.f, 0.f, -90.f));	//位置
	//给延迟贴花附加材质
	UMaterial* Material = LoadObject<UMaterial>(NULL, TEXT("/Game/DontMove/Materials/M_HaloRing.M_HaloRing"));
	if (Material)
	{
		Decal->SetDecalMaterial(Material);
		Decal->SetVisibility(false);
	}

	//创建血条组件
	HealthWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBar"));	//创建
	HealthWidgetComp->SetupAttachment(RootComponent);	//附加
	
}
void AEtherealCharacter::BeginPlay()
{
	Super::BeginPlay();
	ConstructHealthBarWidget();
	
}

void AEtherealCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

//选中状态
void AEtherealCharacter::SetSelected()
{
	Decal->SetVisibility(true);
	
}
//不被选中状态
void AEtherealCharacter::SetDeselected()
{
	Decal->SetVisibility(false);
}

//构建血条组件
void AEtherealCharacter::ConstructHealthBarWidget()
{
	UUW_HealthBar* HealthBarPtr = Cast<UUW_HealthBar>(HealthWidgetComp->GetUserWidgetObject());
	HealthBarPtr->ConstructWidget(this);
}
//更新血条组件
void AEtherealCharacter::RenewHealthBarWidget()
{
	UUW_HealthBar* HealthBarPtr = Cast<UUW_HealthBar>(HealthWidgetComp->GetUserWidgetObject());
	HealthBarPtr->RenewWidget();
}

