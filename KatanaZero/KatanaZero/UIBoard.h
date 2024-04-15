#pragma once
#include "UIBase.h"

// Ό³Έν :
class AUIBoard : public AUIBase
{
	GENERATED_BODY(AUIBase)
public:
	// constructor destructor
	AUIBoard();
	~AUIBoard();

	// delete Function
	AUIBoard(const AUIBoard& _Other) = delete;
	AUIBoard(AUIBoard&& _Other) noexcept = delete;
	AUIBoard& operator=(const AUIBoard& _Other) = delete;
	AUIBoard& operator=(AUIBoard&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

