#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ABackMap_F1 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ABackMap_F1();
	~ABackMap_F1();

	// delete Function
	ABackMap_F1(const ABackMap_F1& _Other) = delete;
	ABackMap_F1(ABackMap_F1&& _Other) noexcept = delete;
	ABackMap_F1& operator=(const ABackMap_F1& _Other) = delete;
	ABackMap_F1& operator=(ABackMap_F1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	float4 Color;
};

