#pragma once
#include "FXBase.h"

// Ό³Έν :
class PlayerDustFX : public AFXBase
{
	GENERATED_BODY(AFXBase)
public:
	// constructor destructor
	PlayerDustFX();
	~PlayerDustFX();

	// delete Function
	PlayerDustFX(const PlayerDustFX& _Other) = delete;
	PlayerDustFX(PlayerDustFX&& _Other) noexcept = delete;
	PlayerDustFX& operator=(const PlayerDustFX& _Other) = delete;
	PlayerDustFX& operator=(PlayerDustFX&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	FVector MoveVector = FVector::Zero;
	float Speed = 200.f;
	bool Reverse = false;

};

