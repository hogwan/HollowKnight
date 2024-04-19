#pragma once
#include "KZGameMode.h"

// Ό³Έν :
class AFactory_2 : public KZGameMode
{
	GENERATED_BODY(KZGameMode)
public:
	// constructor destructor
	AFactory_2();
	~AFactory_2();

	// delete Function
	AFactory_2(const AFactory_2& _Other) = delete;
	AFactory_2(AFactory_2&& _Other) noexcept = delete;
	AFactory_2& operator=(const AFactory_2& _Other) = delete;
	AFactory_2& operator=(AFactory_2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
private:
};
