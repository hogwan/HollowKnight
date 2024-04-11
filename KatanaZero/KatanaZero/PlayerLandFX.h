#pragma once
#include "FXBase.h"

// Ό³Έν :
class PlayerLandFX : public FXBase
{
	GENERATED_BODY(FXBase)
public:
	// constructor destructor
	PlayerLandFX();
	~PlayerLandFX();

	// delete Function
	PlayerLandFX(const PlayerLandFX& _Other) = delete;
	PlayerLandFX(PlayerLandFX&& _Other) noexcept = delete;
	PlayerLandFX& operator=(const PlayerLandFX& _Other) = delete;
	PlayerLandFX& operator=(PlayerLandFX&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	
};

