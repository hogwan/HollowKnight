#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
class ABullet : public AActor
{
	GENERATED_BODY(AActor)
public:
	//constructer destructer
	ABullet();
	~ABullet();

	//delete Function
	ABullet(const ABullet& _Other) = delete;
	ABullet(ABullet&& _Other) noexcept = delete;
	ABullet& operator=(const ABullet& _Other) = delete;
	ABullet& operator=(ABullet&& _Other) noexcept = delete;

	void SetDir(FVector _ShootDir)
	{
		MoveVector = _ShootDir * Speed;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer = nullptr;
	FVector MoveVector = FVector::Zero;
	float Speed = 2000.f;
private:
	
};