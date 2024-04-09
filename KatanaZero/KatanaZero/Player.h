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

	void StateInit();

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

	FVector AttackDir = FVector::Zero;

	bool LongJump = false;
	bool IsLanded = false;

	float LongJumpTime = 0.1f;
	float AccPush = 0.f;

	float RunStartTime = 0.02f;
	float AccRunStart = 0.f;

	float JumpForce = 0.f;
	float LongJumpForce = 300.0f;
	float ShortJumpForce = 200.0f;

	float RunSpeed = 200.0f;
	float RollSpeed = 500.0f;
	float AttackSpeed = 700.f;

	float Gravity = 500.f;

	bool IsColDown = false;
};

