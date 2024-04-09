#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

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
	void StateInit();

	void None(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Run(float _DeltaTime);
	void RunToIdle(float _DeltaTime);
	void Roll(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Crouch(float _DeltaTime);
	void CrouchEnd(float _DeltaTime);
	void Jump(float _DeltaTime);
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
	void JumpStart();
	void FallStart();
	void AttackStart();

	bool LongJump = false;
	float LongJumpTime = 0.1f;
	float AccPush = 0.f;

	float JumpForce = 0.f;
	float LongJumpForce = 300.0f;
	float ShortJumpForce = 200.0f;

	bool IsColDown = false;
};

