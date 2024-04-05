#include "PreCompile.h"
#include "TetrisBoard.h"
#include "TetrisElement.h"

ATetrisBoard::ATetrisBoard() 
{
}

ATetrisBoard::~ATetrisBoard() 
{
}

void ATetrisBoard::BeginPlay()
{
	Super::BeginPlay();

	Board.resize(25);
	for (int i = 0; i < Board.size(); i++)
	{
		Board[i].resize(10);
		for (int j = 0; j < Board[i].size(); j++)
		{
			Board[i][j] = nullptr;
		}
	}
}

void ATetrisBoard::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

