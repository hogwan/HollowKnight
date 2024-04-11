#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>
#include "ContentsHelper.h"

// Ό³Έν :
class USpriteRenderer;
class Player : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	USpriteRenderer* Renderer = nullptr;
	float4 Color;
	EActorDir CurDir = EActorDir::None;
	FVector MoveVector = FVector::Zero;


	void StateInit();
	void DirCheck();
	void DirUpdate();

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

	void FallEnd();

	void GravityCheck(float _DeltaTime);
	void GroundUp();
	bool LandCheck();
	bool RightWallCheck();
	bool LeftWallCheck();

	bool LongJump = false;
	bool IsLanded = false;

	float LongJumpTime = 0.15f;
	float AccLongJump = 0.f;

	float AccDrop = 0.f;
	float DropTime = 0.15f;

	float RunAccel = 1000.0f;
	float AirAccel = 300.f;
	float BreakAccel = 600.f;
	float MaxRunSpeed = 300.0f;
	float MaxAirSpeed = 350.0f;

	float FlipSpeed = 500.f;
	float FlipBreakAccel = 600.f;
	float FlipBreakStartTime = 0.1f;
	float AccFlip = 0.f;

	float JumpForce = 0.f;
	FVector LongJumpForce = FVector(0.f, 300.f, 0.f);
	FVector ShortJumpForce = FVector(0.f, 200.f, 0.f);

	float RollSpeed = 300.0f;
	FVector AttackDir = FVector::Zero;
	float AttackSpeed = 800.f;
	float AttackBreakAccel = 2000.f;
	float AttackBreakStartTime = 0.05f;
	float AccAttack = 0.f;

	FVector Gravity = FVector(0.f, -500.f, 0.f);

	bool OnLeftUpStep = false;
	bool OnRightUpStep = false;
	bool OnProjectionWall = false;

	float4 BottomCheckPos = FVector::Zero;
	float4 RightCheckPos = FVector::Zero;
	float4 LeftCheckPos = FVector::Zero;
	float4 TopCheckPos = FVector::Zero;
};

