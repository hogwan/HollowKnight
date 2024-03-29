#pragma once
#include <EngineCore/EngineCore.h>
class UPuyoPuyoTetrisCore : public UserCore
{
public:
	// constructor destructor
	UPuyoPuyoTetrisCore();
	~UPuyoPuyoTetrisCore();

	// delete Function
	UPuyoPuyoTetrisCore(const UPuyoPuyoTetrisCore& _Other) = delete;
	UPuyoPuyoTetrisCore(UPuyoPuyoTetrisCore&& _Other) noexcept = delete;
	UPuyoPuyoTetrisCore& operator=(const UPuyoPuyoTetrisCore& _Other) = delete;
	UPuyoPuyoTetrisCore& operator=(UPuyoPuyoTetrisCore&& _Other) = delete;

protected:
	void Initialize() override;

private:

};

