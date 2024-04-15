#pragma once
#include "Item.h"

// Ό³Έν :
class AFireBottle : public AItem
{
	GENERATED_BODY(AItem)
public:
	// constructor destructor
	AFireBottle();
	~AFireBottle();

	// delete Function
	AFireBottle(const AFireBottle& _Other) = delete;
	AFireBottle(AFireBottle&& _Other) noexcept = delete;
	AFireBottle& operator=(const AFireBottle& _Other) = delete;
	AFireBottle& operator=(AFireBottle&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:

};

