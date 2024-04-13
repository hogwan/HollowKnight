#pragma once
#include "Enemy.h"

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void StateInit() override;
	void RendererInit() override;

	void None(float _DeltaTime) override;
	void Idle(float _DeltaTime) override;
	void Walk(float _DeltaTime) override;
	void Run(float _DeltaTime) override;
	void Turn(float _DeltaTime) override;
	void Attack(float _DeltaTime) override;
	void Death(float _DeltaTime) override;
	void DeathInAir(float _DeltaTime) override;
	void ChangeLayerLevel(float _DeltaTime) override;
	void NoneStart() override;
	void IdleStart() override;
	void WalkStart() override;
	void RunStart() override;
	void TurnStart() override;
	void AttackStart() override;
	void DeathStart() override;
	void DeathInAirStart() override;
	void ChangeLayerLevelStart() override;

};

