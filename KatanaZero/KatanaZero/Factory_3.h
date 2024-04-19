#pragma once
#include "KZGameMode.h"

// Ό³Έν :
class AFactory_3 : public KZGameMode
{
	GENERATED_BODY(KZGameMode)
public:
	// constructor destructor
	AFactory_3();
	~AFactory_3();

	// delete Function
	AFactory_3(const AFactory_3& _Other) = delete;
	AFactory_3(AFactory_3&& _Other) noexcept = delete;
	AFactory_3& operator=(const AFactory_3& _Other) = delete;
	AFactory_3& operator=(AFactory_3&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
private:
};

