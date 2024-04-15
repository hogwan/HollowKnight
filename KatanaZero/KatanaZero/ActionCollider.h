#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include <EngineCore/DefaultSceneComponent.h>

// Ό³Έν :
class AActionCollider : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	AActionCollider();
	~AActionCollider();

	// delete Function
	AActionCollider(const AActionCollider& _Other) = delete;
	AActionCollider(AActionCollider&& _Other) noexcept = delete;
	AActionCollider& operator=(const AActionCollider& _Other) = delete;
	AActionCollider& operator=(AActionCollider&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UCollision* Collider = nullptr;
	UDefaultSceneComponent* Root = nullptr;
private:

};

