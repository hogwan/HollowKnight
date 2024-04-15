#pragma once
#include "UIBase.h"

// Ό³Έν :
class ABatteryBody : public AUIBase
{
	GENERATED_BODY(AUIBase)
public:
	// constructor destructor
	ABatteryBody();
	~ABatteryBody();

	// delete Function
	ABatteryBody(const ABatteryBody& _Other) = delete;
	ABatteryBody(ABatteryBody&& _Other) noexcept = delete;
	ABatteryBody& operator=(const ABatteryBody& _Other) = delete;
	ABatteryBody& operator=(ABatteryBody&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

