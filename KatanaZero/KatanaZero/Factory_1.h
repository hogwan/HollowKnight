#pragma once
#include "KZGameMode.h"

// Ό³Έν :
class AFactory_1 : public KZGameMode
{
	GENERATED_BODY(KZGameMode)
public:
	// constructor destructor
	AFactory_1();
	~AFactory_1();

	// delete Function
	AFactory_1(const AFactory_1& _Other) = delete;
	AFactory_1(AFactory_1&& _Other) noexcept = delete;
	AFactory_1& operator=(const AFactory_1& _Other) = delete;
	AFactory_1& operator=(AFactory_1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
private:
	std::shared_ptr<UCamera> Camera;
};
