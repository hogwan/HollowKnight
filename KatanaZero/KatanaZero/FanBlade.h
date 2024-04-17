#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AFanBlade : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	AFanBlade();
	~AFanBlade();

	// delete Function
	AFanBlade(const AFanBlade& _Other) = delete;
	AFanBlade(AFanBlade&& _Other) noexcept = delete;
	AFanBlade& operator=(const AFanBlade& _Other) = delete;
	AFanBlade& operator=(AFanBlade&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Renderer = nullptr;
	UCollision* Collider = nullptr;
};

