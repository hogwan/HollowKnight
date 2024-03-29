#include "BlockManager.h"
#include "Block.h"
#include <ConsoleEngine/EngineCore.h>

BlockManager::BlockManager()
{
}

BlockManager::~BlockManager()
{
}

void BlockManager::BeginPlay()
{
	Board.resize(20);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Board[i].push_back(nullptr);
		}
	}
}

void BlockManager::Update()
{
	LandCheck();
	if (ControledBlock.size())
	{
		Move();
	}
	else
	{
		SpawnControledBlock();
	}
}

void BlockManager::Move()
{
	for (Block* b : ControledBlock)
	{
		Board[b->GetPos().Y][b->GetPos().X] = nullptr;
		b->AddPos(int2::Down);


		Board[b->GetPos().Y][b->GetPos().X] = b;
	}
}

void BlockManager::SpawnControledBlock()
{
	{
		Block* b = GetCore()->CreateObject<Block>();
		b->SetPos({ 5,0 });
		ControledBlock.push_back(b);
		Board[5][0] = b;
	}

	{
		Block* b = GetCore()->CreateObject<Block>();
		b->SetPos({ 5,1 });
		ControledBlock.push_back(b);
		Board[5][1] = b;
	}

	{
		Block* b = GetCore()->CreateObject<Block>();
		b->SetPos({ 4,1 });
		ControledBlock.push_back(b);
		Board[4][1] = b;
	}

	{
		Block* b = GetCore()->CreateObject<Block>();
		b->SetPos({ 6,1 });
		ControledBlock.push_back(b);
		Board[6][1] = b;
	}
}

void BlockManager::LandCheck()
{
	bool flag = false;
	for (Block* b : ControledBlock)
	{
		int X = b->GetPos().X;
		int Y = b->GetPos().Y;
		if (Y == Bottom)
		{
			flag = true;
			break;
		}

		if (Board[Y + 1][X] != nullptr && Board[Y+1][X]->GetState() == BlockState::Landed)
		{
			Y;
			X;
			flag = true;
			break;
		}
	}

	if (flag)
	{
		Land();
	}
}


void BlockManager::Land()
{
	for (Block* b : ControledBlock)
	{
		b->SetState(BlockState::Landed);
	}

	ControledBlock.clear();
}
