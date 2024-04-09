#pragma once
#include <EngineCore/Actor.h>
// ���� :
class USpriteRenderer;
class BackGroundMap : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	BackGroundMap();
	~BackGroundMap();

	// delete Function
	BackGroundMap(const BackGroundMap& _Other) = delete;
	BackGroundMap(BackGroundMap&& _Other) noexcept = delete;
	BackGroundMap& operator=(const BackGroundMap& _Other) = delete;
	BackGroundMap& operator=(BackGroundMap&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer;
	float4 Color;
};
