#pragma comment (lib, "ConsoleEngine.lib")

#include <iostream>
#include <ConsoleEngine/EngineCore.h>
#include "Wall.h"
#include "BlockManager.h"

int main()
{
	EngineCore EngineCore;
	EngineCore.Init({12,21});

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (i == 0 || i == 11 || j == 20)
			{
				Wall* wall = EngineCore.CreateObject<Wall>();
				wall->SetPos({ i,j });
				wall->SetRenderChar('#');
			}
		}
	}

	BlockManager* BM = EngineCore.CreateManager<BlockManager>(0);
	BM->BeginPlay();
	EngineCore.Start();

}