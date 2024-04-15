#pragma once
#include "FXBase.h"

// Ό³Έν :
class APompSlashFX : public AFXBase
{
	GENERATED_BODY(AFXBase)
public:
	// constructor destructor
	APompSlashFX();
	~APompSlashFX();

	// delete Function
	APompSlashFX(const APompSlashFX& _Other) = delete;
	APompSlashFX(APompSlashFX&& _Other) noexcept = delete;
	APompSlashFX& operator=(const APompSlashFX& _Other) = delete;
	APompSlashFX& operator=(APompSlashFX&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
};

