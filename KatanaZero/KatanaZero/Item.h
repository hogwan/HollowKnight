#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AItem : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	AItem();
	~AItem();

	// delete Function
	AItem(const AItem& _Other) = delete;
	AItem(AItem&& _Other) noexcept = delete;
	AItem& operator=(const AItem& _Other) = delete;
	AItem& operator=(AItem&& _Other) noexcept = delete;

	void SetThrow(FVector _Dir)
	{
		MoveVector = _Dir * MoveSpeed;
		CurState = EItemState::Throw;
	}

	EItemType GetItemType()
	{
		return CurItem;
	}

	EItemState GetCurState()
	{
		return CurState;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UDefaultSceneComponent* Root = nullptr;
	UCollision* Collider = nullptr;
	USpriteRenderer* Renderer = nullptr;

	EItemState CurState = EItemState::Idle;
	EItemType CurItem = EItemType::None;
	FVector MoveVector = FVector::Zero;
	float MoveSpeed = 2000.f;

private:

};

