#pragma once
#include "UIBase.h"

// Ό³Έν :
class ATimerBoard : public AUIBase
{
	GENERATED_BODY(AUIBase)
public:
	// constructor destructor
	ATimerBoard();
	~ATimerBoard();

	// delete Function
	ATimerBoard(const ATimerBoard& _Other) = delete;
	ATimerBoard(ATimerBoard&& _Other) noexcept = delete;
	ATimerBoard& operator=(const ATimerBoard& _Other) = delete;
	ATimerBoard& operator=(ATimerBoard&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

