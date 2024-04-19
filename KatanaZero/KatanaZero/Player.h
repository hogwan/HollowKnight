#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>
#include "RecordingObject.h"
#include "ContentsHelper.h"

// Ό³Έν :
class USpriteRenderer;

class APlayer : public AActor, public URecordingObject
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	UStateManager State;

	FVector GetAttackDir()
	{
		return AttackDir;
	}

	EEngineDir GetCurDir()
	{
		return CurDir;
	}

	EItemType GetPossessItem()
	{
		return PossessItem;
	}

	int GetLayerLevel()
	{
		return LayerLevel;
	}

	bool NextLevel = false;
	bool Restart = false;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	USpriteRenderer* Renderer = nullptr;
	UCollision* Collider = nullptr;
	UCollision* BottomCol = nullptr;
	UCollision* FrontCol = nullptr;
	UCollision* BackCol = nullptr;
	UCollision* TopCol = nullptr;

	float4 Color;
	EEngineDir CurDir = EEngineDir::MAX;
	FVector MoveVector = FVector::Zero;
	int LayerLevel = 0;

	void StateInit();
	void RendererInit();
	void ColliderInit();
	void CheckPosInit();
	void DebugMessageFunction();
	void DirCheck();
	void DirUpdate();
	bool FallCheck();
	void LayerCheck();
	void ObjectInteract();
	void ThrowItem();
	void DeathCheck();

	void None(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Run(float _DeltaTime);
	void RunToIdle(float _DeltaTime);
	void Roll(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Crouch(float _DeltaTime);
	void CrouchEnd(float _DeltaTime);
	void Fall(float _DeltaTime);
	void Attack(float _DeltaTime);
	void WallSlide(float _DeltaTime);
	void Flip(float _DeltaTime);
	void DeathInAir(float _DeltaTime);
	void Death(float _DeltaTime);
	void Replay(float _DeltaTime);
	void Revert(float _DeltaTime);

	void NoneStart();
	void IdleStart();
	void RunStart();
	void RunToIdleStart();
	void RollStart();
	void JumpStart();
	void CrouchStart();
	void CrouchEndStart();
	void FallStart();
	void AttackStart();
	void WallSlideStart();
	void FlipStart();
	void DeathInAirStart();
	void DeathStart();
	void ReplayStart();
	void RevertStart();

	void FallEnd();

	void GravityCheck(float _DeltaTime);
	bool LandCheck();
	bool RightWallCheck();
	bool LeftWallCheck();
	bool TopWallCheck();

	bool LongJump = false;
	bool IsLanded = false;

	float LongJumpTime = 0.15f;
	float AccLongJump = 0.f;

	float AccDrop = 0.f;
	float DropTime = 0.15f;

	float RunAccel = 1000.0f;
	float AirAccel = 300.f;
	float BreakAccel = 1500.f;
	float MaxRunSpeed = 400.0f;
	float MaxAirSpeed = 350.0f;

	float FlipSpeed = 1000.f;
	float FlipBreakAccel = 1800.f;
	float FlipBreakStartTime = 0.05f;
	float AccFlip = 0.f;

	float JumpForce = 0.f;
	FVector LongJumpForce = FVector(0.f, 400.f, 0.f);
	FVector ShortJumpForce = FVector(0.f, 300.f, 0.f);

	float RollSpeed = 500.0f;
	FVector AttackDir = FVector::Zero;
	float AttackSpeed = 800.f;
	float AttackBreakAccel = 2000.f;
	float AttackBreakStartTime = 0.05f;
	float AccAttack = 0.f;

	FVector Gravity = FVector(0.f, -800.f, 0.f);

	bool OnLeftUpStep = false;
	bool OnRightUpStep = false;
	bool OnProjectionWall = false;

	bool Check = false;

	float4 BottomCheckPos = FVector::Zero;
	float4 RightCheckPos = FVector::Zero;
	float4 LeftCheckPos = FVector::Zero;
	float4 TopCheckPos = FVector::Zero;
	float4 FallCheckPos = FVector::Zero;


	float DustFXRespawnTime = 0.05f;
	float AccDustFXRespawn = 0.f;
	FVector JumpFXOffset = FVector(0.f, 50.f, 0.f); 
	FVector RightFlipFXOffset = FVector(20.f, 10.f, 0.f);
	FVector LeftFlipFXOffset = FVector(-20.f, 10.f, 0.f);
	FVector LandFXOffset = FVector(0.f, 10.f, 0.f);
	FVector DustFXOffset = FVector(0.f, 0.f, 0.f);
	FVector RightWallSlideFXOffset = FVector(20.f, 0.f, 0.f);
	FVector LeftWallSlideFXOffset = FVector(-20.f, 0.f, 0.f);

	EItemType PossessItem = EItemType::None;
};

