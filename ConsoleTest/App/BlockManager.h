#pragma once
#include <ConsoleEngine/ConsoleUpdater.h>
#include <vector>
#include <list>
class BlockManager : public ConsoleUpdater
{
public:
	// constructor destructor
	BlockManager();
	~BlockManager();

	// delete Function
	BlockManager(const BlockManager& _Other) = delete;
	BlockManager(BlockManager&& _Other) noexcept = delete;
	BlockManager& operator=(const BlockManager& _Other) = delete;
	BlockManager& operator=(BlockManager&& _Other) = delete;

	void BeginPlay();

protected:
	void Update() override;
	
private:
	std::vector<std::vector<class Block*>> Board;
	std::list<class Block*> ControledBlock;

	void Move();
	void SpawnControledBlock();
	void LandCheck();
	void Land();

	int Bottom = 19;
};

