#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ALaser
	: public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ALaser();
	~ALaser();

	// delete Function
	ALaser(const ALaser& _Other) = delete;
	ALaser(ALaser&& _Other) noexcept = delete;
	ALaser& operator=(const ALaser& _Other) = delete;
	ALaser& operator=(ALaser&& _Other) noexcept = delete;

	void SetOwner(class ALaserLauncher* _LaserLauncher);
	void SetY(float Y);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Renderer = nullptr;
	UCollision* Collider = nullptr;
	class ALaserLauncher* Owner = nullptr;

};

