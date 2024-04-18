#pragma once
#include <EngineCore/Actor.h>
#include "LaserLauncher.h"

// Ό³Έν :
class ALaserSwitch : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ALaserSwitch();
	~ALaserSwitch();

	// delete Function
	ALaserSwitch(const ALaserSwitch& _Other) = delete;
	ALaserSwitch(ALaserSwitch&& _Other) noexcept = delete;
	ALaserSwitch& operator=(const ALaserSwitch& _Other) = delete;
	ALaserSwitch& operator=(ALaserSwitch&& _Other) noexcept = delete;

	void On();
	void Off();
	bool GetState()
	{
		return IsOn;
	}

	void PushLaser(std::shared_ptr<ALaserLauncher> _LaserLauncher)
	{
		Lasers.push_back(_LaserLauncher);
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Renderer = nullptr;
	UCollision* Collider = nullptr;
	std::vector<std::shared_ptr<ALaserLauncher>> Lasers;

	bool IsOn = false;

};

