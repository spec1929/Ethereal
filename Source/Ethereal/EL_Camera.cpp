// Fill out your copyright notice in the Description page of Project Settings.


#include "EL_Camera.h"
#include "Camera/CameraComponent.h"
#include "Components/PostProcessComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AEL_Camera::AEL_Camera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//创建弹簧臂
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = ArmLength;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	//创建相机
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);  //附加
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//开启景深	
	DepthOfField();	
}

// Called when the game starts or when spawned
void AEL_Camera::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerPtr = GetWorld()->GetFirstPlayerController();
	
}

// Called every frame
void AEL_Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorOffset();

}

FVector2D AEL_Camera::GetMouseOffset()
{
	float MouseLocaX = 0.f;
	float MouseLocaY = 0.f;
	int32 ViewSizeX = INDEX_NONE;
	int32 ViewSizeY = INDEX_NONE;

	PlayerControllerPtr->GetMousePosition(MouseLocaX,MouseLocaY);	//赋值鼠标位置
	PlayerControllerPtr->GetViewportSize(ViewSizeX,ViewSizeY);	//赋值视口大小

	double m,n;
	m=(2*MouseLocaX)/ViewSizeX-1;
	n=(2*MouseLocaY)/ViewSizeY-1;

	float OffsetX = 0.f,OffsetY = 0.f;
	if (m < -0.95)
	{
		OffsetX = m * movespeed;
	}
	else if (m > 0.95)
	{
		OffsetX = m * movespeed;
	}
	if (n < -0.95)
	{
		OffsetY = n * -1 * movespeed;
	}
	else if (n > 0.95)
	{
		OffsetY = n * -1 * movespeed;
	}

	return FVector2D(OffsetX,OffsetY);
}

void AEL_Camera::SetActorOffset()
{
	float x = GetMouseOffset().X;
	float y = GetMouseOffset().Y;

	if (x != 0.f || y != 0.f)
	{
		FVector OffsetV;
		OffsetV.X = y;
		OffsetV.Y = x;
		OffsetV.Z = 0.f;

		AddActorWorldOffset(OffsetV);	//偏移
	}
}

//设置Actor世界位置以达到跟随效果(需要tick调用)，跟随目标设置为被选中状态
void AEL_Camera::CameraFollow(AEtherealCharacter* FollowTargetPtr)
{
	SetActorLocation(FollowTargetPtr->GetActorLocation());	//设置位置
	FollowTargetPtr->SetSelected();	//设置被选中
	
}

//景深
//AddPostProcessComponent Aperture(Fstop)0.1 SensorWidth(Mm)70 FocalDistance弹簧臂长度
void AEL_Camera::DepthOfField()
{
	PostProcessComPtr = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcess"));
	PostProcessComPtr->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	PostProcessComPtr->Settings.DepthOfFieldFstop = 0.1f;
	PostProcessComPtr->Settings.DepthOfFieldSensorWidth = 70.f;
	PostProcessComPtr->Settings.DepthOfFieldFocalDistance = ArmLength;
	
}