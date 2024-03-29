#pragma once
#include <ConsoleEngine/ConsoleObject.h>

enum class BlockState
{
	None,
	Control,
	Landed,
};

class Block : public ConsoleObject
{
public:
	// constructor destructor
	Block();
	~Block();

	// delete Function
	Block(const Block& _Other) = delete;
	Block(Block&& _Other) noexcept = delete;
	Block& operator=(const Block& _Other) = delete;
	Block& operator=(Block&& _Other) = delete;

	void SetState(BlockState _State)
	{
		CurState = _State;
	}

	BlockState GetState()
	{
		return CurState;
	}

protected:
	void Update() override;

private:
	BlockState CurState = BlockState::None;
};

