#pragma once
#include <EngineCore/EngineCore.h>
class UHollowKnightCore : public UserCore
{
public:
	//constructer destructer
	UHollowKnightCore();
	~UHollowKnightCore();

	//delete Function
	UHollowKnightCore(const UHollowKnightCore& _Other) = delete;
	UHollowKnightCore(UHollowKnightCore&& _Other) noexcept = delete;
	UHollowKnightCore& operator=(const UHollowKnightCore& _Other) = delete;
	UHollowKnightCore& operator=(UHollowKnightCore&& _Other) noexcept = delete;
protected:
	void Initialize() override;
private:

};