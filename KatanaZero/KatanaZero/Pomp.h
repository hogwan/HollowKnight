#pragma once
#include "Enemy.h"
class APomp : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	//constructer destructer
	APomp();
	~APomp();

	//delete Function
	APomp(const APomp& _Other) = delete;
	APomp(APomp&& _Other) noexcept = delete;
	APomp& operator=(const APomp& _Other) = delete;
	APomp& operator=(APomp&& _Other) noexcept = delete;
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

	void Stun(float _DeltaTime);
	void StunStart();
private:

};