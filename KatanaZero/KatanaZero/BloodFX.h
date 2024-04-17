#pragma once
#include "FXBase.h"

// Ό³Έν :
class ABloodFX : public AFXBase
{
	GENERATED_BODY(AFXBase)
public:
	// constructor destructor
	ABloodFX();
	~ABloodFX();

	// delete Function
	ABloodFX(const ABloodFX& _Other) = delete;
	ABloodFX(ABloodFX&& _Other) noexcept = delete;
	ABloodFX& operator=(const ABloodFX& _Other) = delete;
	ABloodFX& operator=(ABloodFX&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

