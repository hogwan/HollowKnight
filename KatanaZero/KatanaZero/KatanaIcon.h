#pragma once
#include "UIBase.h"

// Ό³Έν :
class AKatanaIcon : public AUIBase
{
	GENERATED_BODY(AUIBase)
public:
	// constructor destructor
	AKatanaIcon();
	~AKatanaIcon();

	// delete Function
	AKatanaIcon(const AKatanaIcon& _Other) = delete;
	AKatanaIcon(AKatanaIcon&& _Other) noexcept = delete;
	AKatanaIcon& operator=(const AKatanaIcon& _Other) = delete;
	AKatanaIcon& operator=(AKatanaIcon&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

