// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "EtherealPlayerController.h"
#include "EtherealCharacter.h"
#include "EL_Camera.generated.h"

UCLASS()
class ETHEREAL_API AEL_Camera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEL_Camera();
	
	//镜头移动速度
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float movespeed = 100.f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float ArmLength = 1800.f;
	//控制器指针
	APlayerController* PlayerControllerPtr;
	//角色指针
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta = (InstanceEditable = true,ExposeOnSpawn = true))
	AEtherealCharacter* ELCharacterPtr;
	
	//镜头移动计算函数
	UFUNCTION(BlueprintCallable,BlueprintPure)
		FVector2D GetMouseOffset();
	void SetActorOffset();

	//镜头定位到某个角色身上
	UFUNCTION(BlueprintCallable)
	void CameraFollow(AEtherealCharacter* FollowTargetPtr);

	//镜头景深
	UFUNCTION(BlueprintCallable)
	void DepthOfField();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent()const{return TopDownCameraComponent;}
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	//相机
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	//弹簧臂
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	//后期处理组件
	UPROPERTY()
	class UPostProcessComponent* PostProcessComPtr;
};
