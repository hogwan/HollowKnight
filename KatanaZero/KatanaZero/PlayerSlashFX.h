#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class PlayerSlashFX : public AActor
{
	GENERATED_BODY(AActor)
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
	USpriteRenderer* Renderer = nullptr;
	float4 Color;
	FVector Dir = FVector::Zero;
};

