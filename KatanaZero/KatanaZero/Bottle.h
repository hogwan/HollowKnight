#pragma once
#include "Item.h"
// Ό³Έν :
class ABottle : public AItem
{
	GENERATED_BODY(AItem)
public:
	// constructor destructor
	ABottle();
	~ABottle();

	// delete Function
	ABottle(const ABottle& _Other) = delete;
	ABottle(ABottle&& _Other) noexcept = delete;
	ABottle& operator=(const ABottle& _Other) = delete;
	ABottle& operator=(ABottle&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

