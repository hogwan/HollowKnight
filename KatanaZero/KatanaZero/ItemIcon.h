#pragma once
#include "UIBase.h"

// Ό³Έν :
class AItemIcon : public AUIBase
{
	GENERATED_BODY(AUIBase)
public:
	// constructor destructor
	AItemIcon();
	~AItemIcon();

	// delete Function
	AItemIcon(const AItemIcon& _Other) = delete;
	AItemIcon(AItemIcon&& _Other) noexcept = delete;
	AItemIcon& operator=(const AItemIcon& _Other) = delete;
	AItemIcon& operator=(AItemIcon&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

