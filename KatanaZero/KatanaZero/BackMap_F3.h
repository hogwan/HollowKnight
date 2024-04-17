#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ABackMap_F3 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ABackMap_F3();
	~ABackMap_F3();

	// delete Function
	ABackMap_F3(const ABackMap_F3& _Other) = delete;
	ABackMap_F3(ABackMap_F3&& _Other) noexcept = delete;
	ABackMap_F3& operator=(const ABackMap_F3& _Other) = delete;
	ABackMap_F3& operator=(ABackMap_F3&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Renderer = nullptr;
	float4 Color;
};

