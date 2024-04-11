#pragma once
#include "FXBase.h"

// Ό³Έν :
class PlayerJumpFX : public FXBase
{
	GENERATED_BODY(FXBase)
public:
	// constructor destructor
	PlayerJumpFX();
	~PlayerJumpFX();

	// delete Function
	PlayerJumpFX(const PlayerJumpFX& _Other) = delete;
	PlayerJumpFX(PlayerJumpFX&& _Other) noexcept = delete;
	PlayerJumpFX& operator=(const PlayerJumpFX& _Other) = delete;
	PlayerJumpFX& operator=(PlayerJumpFX&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
private:

};

