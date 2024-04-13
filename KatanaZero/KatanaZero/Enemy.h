#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/StateManager.h>
#include "Player.h"

enum class EEnemyPattern
{
	Patrol,
	ChasePlayer,
};

// Ό³Έν :
class AEnemy : public AActor
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
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	USpriteRenderer* Renderer = nullptr;
	UDefaultSceneComponent* Root = nullptr;
	int LayerLevel = 0;

	EActorDir CurDir = EActorDir::Right;
	EEnemyPattern CurPattern = EEnemyPattern::Patrol;
	FVector MoveVector = FVector::Zero;
	FVector GravityVector = FVector(0.f, -500.f, 0.f);
	void DirUpdate();

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

	bool LandCheck();
	void GravityCheck(float _DeltaTime);

	float AccTime = 0.f;
	float IdleTime = 1.f;
	float WalkTime = 4.f;
	float WalkSpeed = 100.f;
	float MoveSpeed = 300.f;

	bool OnLeftUpStep = false;
	bool OnRightUpStep = false;
	
private:

};

