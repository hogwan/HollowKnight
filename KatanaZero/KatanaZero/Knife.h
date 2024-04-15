#pragma once
#include "Item.h"

// Ό³Έν :
class AKnife : public AItem
{
	GENERATED_BODY(AItem)
public:
	// constructor destructor
	AKnife();
	~AKnife();

	// delete Function
	AKnife(const AKnife& _Other) = delete;
	AKnife(AKnife&& _Other) noexcept = delete;
	AKnife& operator=(const AKnife& _Other) = delete;
	AKnife& operator=(AKnife&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

