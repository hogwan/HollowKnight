#pragma once
#include "KZGameMode.h"

// Ό³Έν :
class AFactory_0 : public KZGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constructor destructor
	AFactory_0();
	~AFactory_0();

	// delete Function
	AFactory_0(const AFactory_0& _Other) = delete;
	AFactory_0(AFactory_0&& _Other) noexcept = delete;
	AFactory_0& operator=(const AFactory_0& _Other) = delete;
	AFactory_0& operator=(AFactory_0&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<UCamera> Camera;
};

