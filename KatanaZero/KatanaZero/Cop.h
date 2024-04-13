#pragma once
#include "Enemy.h"
class Cop : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	//constructer destructer
	Cop();
	~Cop();

	//delete Function
	Cop(const Cop& _Other) = delete;
	Cop(Cop&& _Other) noexcept = delete;
	Cop& operator=(const Cop& _Other) = delete;
	Cop& operator=(Cop&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTIme) override;
private:

};