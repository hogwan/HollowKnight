#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/StateManager.h>
#include "Player.h"

// Ό³Έν :
class AEnemy : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	AEnemy();
	~AEnemy();

	// delete Function
	AEnemy(const AEnemy& _Other) = delete;
	AEnemy(AEnemy&& _Other) noexcept = delete;
	AEnemy& operator=(const AEnemy& _Other) = delete;
	AEnemy& operator=(AEnemy&& _Other) noexcept = delete;

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	USpriteRenderer* Renderer = nullptr;

private:

};

