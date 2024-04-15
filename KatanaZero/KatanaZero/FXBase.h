#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
class AFXBase : public AActor
{
	GENERATED_BODY(AActor)
public:
	//constructer destructer
	AFXBase();
	~AFXBase();

	//delete Function
	AFXBase(const AFXBase& _Other) = delete;
	AFXBase(AFXBase&& _Other) noexcept = delete;
	AFXBase& operator=(const AFXBase& _Other) = delete;
	AFXBase& operator=(AFXBase&& _Other) noexcept = delete;
	void ReverseX();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer = nullptr;
	UDefaultSceneComponent* Root = nullptr;
private:
};