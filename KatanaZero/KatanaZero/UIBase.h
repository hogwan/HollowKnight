#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Camera.h>

// Ό³Έν :
class AUIBase : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	AUIBase();
	~AUIBase();

	// delete Function
	AUIBase(const AUIBase& _Other) = delete;
	AUIBase(AUIBase&& _Other) noexcept = delete;
	AUIBase& operator=(const AUIBase& _Other) = delete;
	AUIBase& operator=(AUIBase&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UDefaultSceneComponent* Root = nullptr;
	USpriteRenderer* Renderer = nullptr;

private:

};

