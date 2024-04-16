#pragma once
#include <EngineCore/GameMode.h>
#include "Player.h"
#include "Cursor.h"

// Ό³Έν :
class KZGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constructor destructor
	KZGameMode();
	~KZGameMode();

	// delete Function
	KZGameMode(const KZGameMode& _Other) = delete;
	KZGameMode(KZGameMode&& _Other) noexcept = delete;
	KZGameMode& operator=(const KZGameMode& _Other) = delete;
	KZGameMode& operator=(KZGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

