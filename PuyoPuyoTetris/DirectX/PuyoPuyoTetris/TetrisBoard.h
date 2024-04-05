#pragma once
#include "Board.h"

// Ό³Έν :
class ATetrisBoard : public ABoard
{
	GENERATED_BODY(ABoard)
public:
	// constructor destructor
	ATetrisBoard();
	~ATetrisBoard();

	// delete Function
	ATetrisBoard(const ATetrisBoard& _Other) = delete;
	ATetrisBoard(ATetrisBoard&& _Other) noexcept = delete;
	ATetrisBoard& operator=(const ATetrisBoard& _Other) = delete;
	ATetrisBoard& operator=(ATetrisBoard&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

