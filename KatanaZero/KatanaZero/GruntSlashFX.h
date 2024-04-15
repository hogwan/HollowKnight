#pragma once
#include "FXBase.h"

// Ό³Έν :
class AGruntSlashFX
	: public AFXBase
{
	GENERATED_BODY(AFXBase)
public:
	// constructor destructor
	AGruntSlashFX();
	~AGruntSlashFX();

	// delete Function
	AGruntSlashFX(const AGruntSlashFX& _Other) = delete;
	AGruntSlashFX(AGruntSlashFX&& _Other) noexcept = delete;
	AGruntSlashFX& operator=(const AGruntSlashFX& _Other) = delete;
	AGruntSlashFX& operator=(AGruntSlashFX&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

