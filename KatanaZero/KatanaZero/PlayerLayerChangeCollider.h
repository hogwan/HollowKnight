#pragma once
#include "ActionCollider.h"

// Ό³Έν :
class APlayerLayerChangeCollider : public AActionCollider
{
	GENERATED_BODY(AActionCollider)
public:
	// constructor destructor
	APlayerLayerChangeCollider();
	~APlayerLayerChangeCollider();

	// delete Function
	APlayerLayerChangeCollider(const APlayerLayerChangeCollider& _Other) = delete;
	APlayerLayerChangeCollider(APlayerLayerChangeCollider&& _Other) noexcept = delete;
	APlayerLayerChangeCollider& operator=(const APlayerLayerChangeCollider& _Other) = delete;
	APlayerLayerChangeCollider& operator=(APlayerLayerChangeCollider&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	class USpriteRenderer* Renderer = nullptr;
private:

};

