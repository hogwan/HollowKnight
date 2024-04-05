#pragma once
#include "Board.h"

// Ό³Έν :
class PuyoBoard : public ABoard
{
	GENERATED_BODY(ABoard)
public:
	// constructor destructor
	PuyoBoard();
	~PuyoBoard();

	// delete Function
	PuyoBoard(const PuyoBoard& _Other) = delete;
	PuyoBoard(PuyoBoard&& _Other) noexcept = delete;
	PuyoBoard& operator=(const PuyoBoard& _Other) = delete;
	PuyoBoard& operator=(PuyoBoard&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

