#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class USpriteRenderer;
class BackMap_F0 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	BackMap_F0();
	~BackMap_F0();

	// delete Function
	BackMap_F0(const BackMap_F0& _Other) = delete;
	BackMap_F0(BackMap_F0&& _Other) noexcept = delete;
	BackMap_F0& operator=(const BackMap_F0& _Other) = delete;
	BackMap_F0& operator=(BackMap_F0&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	float4 Color;
};

