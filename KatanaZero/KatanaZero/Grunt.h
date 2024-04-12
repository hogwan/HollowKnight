#pragma once
#include "Enemy.h"

enum class GruntPattern
{
	Patrol,
	ChasePlayer,
};

// Ό³Έν :
class AGrunt : public AActor
{
	GENERATED_BODY(AActor)
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
	USpriteRenderer* Renderer = nullptr;

	void None(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Walk(float _DeltaTime);
	void Run(float _DeltaTime);
	void Turn(float _DeltaTime);
	void Attack(float _DeltaTime);
	void Death(float _DeltaTime);
	void DeathInAir(float _DeltaTime);

	void NoneStart();
	void IdleStart();
	void WalkStart();
	void RunStart();
	void TurnStart();
	void AttackStart();
	void DeathStart();
	void DeathInAirStart();

	void StateInit();
	void RendererInit();
};

