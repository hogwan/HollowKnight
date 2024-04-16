#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ABackMap_F2 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ABackMap_F2();
	~ABackMap_F2();

	// delete Function
	ABackMap_F2(const ABackMap_F2& _Other) = delete;
	ABackMap_F2(ABackMap_F2&& _Other) noexcept = delete;
	ABackMap_F2& operator=(const ABackMap_F2& _Other) = delete;
	ABackMap_F2& operator=(ABackMap_F2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	float4 Color;
};

