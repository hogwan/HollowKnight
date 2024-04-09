#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>
#include "EnumHelper.h"

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

	void GravityCheck(float _DeltaTime);

	bool LongJump = false;
	bool IsLanded = false;

	float LongJumpTime = 0.15f;
	float AccLongJump = 0.f;

	float RunAccel = 600.0f;
	float AirAccel = 300.f;
	float BreakAccel = 600.f;
	float MaxRunSpeed = 200.0f;
	float MaxAirSpeed = 250.0f;

	float JumpForce = 0.f;
	FVector LongJumpForce = FVector(0.f, 300.f, 0.f);
	FVector ShortJumpForce = FVector(0.f, 200.f, 0.f);

	float RollSpeed = 300.0f;
	FVector AttackDir = FVector::Zero;
	float AttackSpeed = 500.f;

	FVector Gravity = FVector(0.f, -500.f, 0.f);

	bool IsColDown = false;
};

