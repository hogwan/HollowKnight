#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/StateManager.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "Player.h"
#include "RecordingObject.h"

enum class EEnemyPattern
{
	Patrol,
	ChasePlayer,
};

// ���� :
class AEnemy : public AActor, public URecordingObject
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	AEnemy();
	~AEnemy();

	// delete Function
	AEnemy(const AEnemy& _Other) = delete;
	AEnemy(AEnemy&& _Other) noexcept = delete;
	AEnemy& operator=(const AEnemy& _Other) = delete;
	AEnemy& operator=(AEnemy&& _Other) noexcept = delete;
	
	UStateManager State;

	void SetLayerLevel(int _LayerLevel)
	{
		LayerLevel = _LayerLevel;
	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	USpriteRenderer* Renderer = nullptr;
	UDefaultSceneComponent* Root = nullptr;
	UCollision* Collider = nullptr;
	int LayerLevel = 0;

	EEngineDir CurDir = EEngineDir::Right;
	EEnemyPattern CurPattern = EEnemyPattern::Patrol;
	FVector MoveVector = FVector::Zero;
	FVector GravityVector = FVector(0.f, -1000.f, 0.f);
	void DirUpdate();
	void CheckPosInit();

	virtual void None(float _DeltaTime);
	virtual void Idle(float _DeltaTime);
	virtual void Walk(float _DeltaTime);
	virtual void Run(float _DeltaTime);
	virtual void Turn(float _DeltaTime);
	virtual void Attack(float _DeltaTime);
	virtual void Death(float _DeltaTime);
	virtual void DeathInAir(float _DeltaTime);
	virtual void ChangeLayerLevel(float _DeltaTime);

	virtual void NoneStart();
	virtual void IdleStart();
	virtual void WalkStart();
	virtual void RunStart();
	virtual void TurnStart();
	virtual void AttackStart();
	virtual void DeathStart();
	virtual void DeathInAirStart();
	virtual void ChangeLayerLevelStart();

	virtual void AttackEnd();

	virtual void StateInit();
	virtual void RendererInit();
	void DeathCheck();

	bool LandCheck();
	void GravityCheck(float _DeltaTime);
	bool RightWallCheck();
	bool LeftWallCheck();
	bool TopWallCheck();

	float AccTime = 0.f;
	float IdleTime = 1.f;
	float WalkTime = 4.f;
	float WalkSpeed = 100.f;
	float MoveSpeed = 300.f;

	bool OnLeftUpStep = false;
	bool OnRightUpStep = false;

	float FlyPower = 500.f;
	float DeathBreak = 1000.f;
	bool IsDeath = false;

	float4 BottomCheckPos = FVector::Zero;
	float4 RightCheckPos = FVector::Zero;
	float4 LeftCheckPos = FVector::Zero;
	float4 TopCheckPos = FVector::Zero;
	float4 FallCheckPos = FVector::Zero;

private:

};

