#pragma once
#include "Enemy.h"

enum class EGruntPattern
{
	Patrol,
	ChasePlayer,
};

// Ό³Έν :
class AGrunt : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AGrunt();
	~AGrunt();

	// delete Function
	AGrunt(const AGrunt& _Other) = delete;
	AGrunt(AGrunt&& _Other) noexcept = delete;
	AGrunt& operator=(const AGrunt& _Other) = delete;
	AGrunt& operator=(AGrunt&& _Other) noexcept = delete;

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	EActorDir CurDir = EActorDir::Right;
	EGruntPattern CurPattern = EGruntPattern::Patrol;
	FVector MoveVector = FVector::Zero;
	FVector GravityVector = FVector(0.f,-500.f,0.f);
	void DirUpdate();

	void None(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Walk(float _DeltaTime);
	void Run(float _DeltaTime);
	void Turn(float _DeltaTime);
	void Attack(float _DeltaTime);
	void Death(float _DeltaTime);
	void DeathInAir(float _DeltaTime);
	void ChangeLayerLevel(float _DeltaTime);

	void NoneStart();
	void IdleStart();
	void WalkStart();
	void RunStart();
	void TurnStart();
	void AttackStart();
	void DeathStart();
	void DeathInAirStart();
	void ChangeLayerLevelStart();

	void StateInit();
	void RendererInit();

	bool LandCheck();
	void GravityCheck(float _DeltaTime);


	float AccTime = 0.f;
	float IdleTime = 1.f;
	float WalkTime = 4.f;
	float WalkSpeed = 100.f;
	float MoveSpeed = 300.f;

	bool OnLeftUpStep = false;
	bool OnRightUpStep = false;

};

