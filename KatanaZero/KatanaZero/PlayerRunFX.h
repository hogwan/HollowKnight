#pragma once
#include "FXBase.h"

// Ό³Έν :
class PlayerRunFX : public FXBase
{
	GENERATED_BODY(FXBase)
public:
	// constructor destructor
	PlayerRunFX();
	~PlayerRunFX();

	// delete Function
	PlayerRunFX(const PlayerRunFX& _Other) = delete;
	PlayerRunFX(PlayerRunFX&& _Other) noexcept = delete;
	PlayerRunFX& operator=(const PlayerRunFX& _Other) = delete;
	PlayerRunFX& operator=(PlayerRunFX&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	bool Reverse = false;
};

