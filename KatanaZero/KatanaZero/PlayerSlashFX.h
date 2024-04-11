#pragma once
#include "FXBase.h"

// ���� :
class PlayerSlashFX : public FXBase
{
	GENERATED_BODY(FXBase)
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

private:
	float4 Color;
	FVector Dir = FVector::Zero;
};

