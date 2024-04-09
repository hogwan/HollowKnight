#pragma once
#include <EngineCore/EngineCore.h>

// Ό³Έν :
class KatanaZeroCore : public UserCore
{
public:
	// constructor destructor
	KatanaZeroCore();
	~KatanaZeroCore();

	// delete Function
	KatanaZeroCore(const KatanaZeroCore& _Other) = delete;
	KatanaZeroCore(KatanaZeroCore&& _Other) noexcept = delete;
	KatanaZeroCore& operator=(const KatanaZeroCore& _Other) = delete;
	KatanaZeroCore& operator=(KatanaZeroCore&& _Other) noexcept = delete;

protected:
	void Initialize() override;
private:

};

