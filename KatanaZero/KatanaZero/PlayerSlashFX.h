#pragma once
#include "FXBase.h"

// Ό³Έν :
class PlayerSlashFX : public AFXBase
{
	GENERATED_BODY(AFXBase)
public:
	// constructor destructor
	PlayerSlashFX();
	~PlayerSlashFX();

	// delete Function
	PlayerSlashFX(const PlayerSlashFX& _Other) = delete;
	PlayerSlashFX(PlayerSlashFX&& _Other) noexcept = delete;
	PlayerSlashFX& operator=(const PlayerSlashFX& _Other) = delete;
	PlayerSlashFX& operator=(PlayerSlashFX&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UCollision* Collider = nullptr;

private:
	float4 Color;
	FVector Dir = FVector::Zero;
};

