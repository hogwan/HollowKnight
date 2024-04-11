#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
class FXBase : public AActor
{
	GENERATED_BODY(AActor)
public:
	//constructer destructer
	FXBase();
	~FXBase();

	//delete Function
	FXBase(const FXBase& _Other) = delete;
	FXBase(FXBase&& _Other) noexcept = delete;
	FXBase& operator=(const FXBase& _Other) = delete;
	FXBase& operator=(FXBase&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer = nullptr;
private:
};