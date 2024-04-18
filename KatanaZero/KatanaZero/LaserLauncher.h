#pragma once
#include <EngineCore/Actor.h>
#include "Laser.h"


// Ό³Έν :
class ALaserLauncher : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ALaserLauncher();
	~ALaserLauncher();

	// delete Function
	ALaserLauncher(const ALaserLauncher& _Other) = delete;
	ALaserLauncher(ALaserLauncher&& _Other) noexcept = delete;
	ALaserLauncher& operator=(const ALaserLauncher& _Other) = delete;
	ALaserLauncher& operator=(ALaserLauncher&& _Other) noexcept = delete;

	inline void LaserOn()
	{
		IsLaserOn = true;
		Laser->On();
	}

	inline void LaserOff()
	{
		IsLaserOn = false;
		Laser->Off();
	}
	void SetLaserSize(float Y)
	{
		Laser->SetY(Y);
	}

	void SetDir(FVector _Dir)
	{
		MoveVector = _Dir;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	std::shared_ptr<class ALaser> Laser = nullptr;

	FVector MoveVector = FVector::Zero;

	float MoveDistant = 500.f;
	float MoveAcc = 0.f;
	float MoveSpeed = 200.f;

	bool IsLaserOn = true;
	float LaserY = 0.f;
};

