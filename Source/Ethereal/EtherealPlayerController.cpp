// Copyright Epic Games, Inc. All Rights Reserved.

#include "EtherealPlayerController.h"

#include "EL_Camera.h"
#include "Widgets/UW_HUD.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "EtherealCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AEtherealPlayerController::AEtherealPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;

	//UWHUD
	UWHudClass = nullptr;
	UWHudPtr = nullptr;
}

void AEtherealPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	HudPtr = Cast<AEL_HUD>(GetHUD());

	//添加输入IMC	Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(EtherealMappingContext, 0);	//添加输入操作
	}

	//定义角色参数
	ELCharacterPtr = Cast<AEtherealCharacter>(GetCharacter());
	//调用生成相机函数
	OpenCamera();

	//创建HUD控件并添加到视口
	if (UWHudClass)
	{
		UWHudPtr = CreateWidget<UUW_HUD>(this,UWHudClass);	//创建控件
		check(UWHudPtr);
		UWHudPtr->AddToViewport();	//添加到视口
		UWHudPtr->Construct_InfoLanWidget(true,ELCharacterPtr);
	}
	
}

void AEtherealPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// 设置鼠标右键输入事件
		EnhancedInputComponent->BindAction(RightMouseClick, ETriggerEvent::Started, this, &AEtherealPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(RightMouseClick, ETriggerEvent::Triggered, this, &AEtherealPlayerController::OnRClickTriggered);
		EnhancedInputComponent->BindAction(RightMouseClick, ETriggerEvent::Completed, this, &AEtherealPlayerController::OnRClickReleased);
		EnhancedInputComponent->BindAction(RightMouseClick, ETriggerEvent::Canceled, this, &AEtherealPlayerController::OnRClickReleased);

		// 设置鼠标左键输入事件
		EnhancedInputComponent->BindAction(LeftMouseClick, ETriggerEvent::Started, this, &AEtherealPlayerController::OnLClickStarted);
		EnhancedInputComponent->BindAction(LeftMouseClick, ETriggerEvent::Triggered, this, &AEtherealPlayerController::OnLClickTriggered);
		EnhancedInputComponent->BindAction(LeftMouseClick, ETriggerEvent::Completed, this, &AEtherealPlayerController::OnLClickReleased);
		EnhancedInputComponent->BindAction(LeftMouseClick, ETriggerEvent::Canceled, this, &AEtherealPlayerController::OnLClickReleased);
	}
}

void AEtherealPlayerController::OnInputStarted()
{
	//StopMovement();
	ResetInfoLanWidget();
	
	
	
}

// Triggered every frame when the input is held down
void AEtherealPlayerController::OnRClickTriggered()
{
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AEtherealPlayerController::OnRClickReleased()
{
	// If it was a short press 如果是短按
	if (FollowTime <= ShortPressThreshold)	//按压时长≤短按数值
	{
		// We move there and spawn some particles 移动并且有按压特效
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}

	FollowTime = 0.f;
}

void AEtherealPlayerController::OnLClickStarted()
{
	HudPtr->InitialPoint = HudPtr->GetMousePos2D();	//左键点击时设置HUD中的起始点
	HudPtr->bStartSelecting = true;	//开始选择布尔true
}
// Triggered every frame when the input is held down
void AEtherealPlayerController::OnLClickTriggered()
{
	
}

void AEtherealPlayerController::OnLClickReleased()
{
	HudPtr->bStartSelecting = false;	//开始选择布尔false
	HudPtr->Compare();
	SelectedPlayers = HudPtr->SelectedPlayers;	//将HUD里被选中的角色数组传进
	
	if (UWHudPtr && SelectedPlayers.Num()>0)
	{
		UWHudPtr->Construct_InfoLanWidget(false,SelectedPlayers[0]);		//UWHUD新增目标信息栏
	}
	
}

//生成并开启相机
void AEtherealPlayerController::OpenCamera()
{
	//生成Actor TSubclassOf<AEl_Camera>
	const FVector Location = ELCharacterPtr->GetActorLocation();
	const FRotator Rotation(0.f);
	SightCameraPtr = GetWorld()->SpawnActor<AEL_Camera>(Location,Rotation);	//生成Actor
	if (SightCameraPtr !=nullptr)
	{
		SightCameraPtr->ELCharacterPtr = ELCharacterPtr;	//传进参数
	}
	//使用混合设置视图目标
	SetViewTargetWithBlend(SightCameraPtr,0.f,VTBlend_Linear,0.f,false);
}

//UWHud中的信息栏归位
void AEtherealPlayerController::ResetInfoLanWidget()
{
	if (UWHudPtr)
	{
		UWHudPtr->ResetInfoLanWidget();	
	}
}
