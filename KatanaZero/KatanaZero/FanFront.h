#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AFanFront : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	AFanFront();
	~AFanFront();

	// delete Function
	AFanFront(const AFanFront& _Other) = delete;
	AFanFront(AFanFront&& _Other) noexcept = delete;
	AFanFront& operator=(const AFanFront& _Other) = delete;
	AFanFront& operator=(AFanFront&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
};

