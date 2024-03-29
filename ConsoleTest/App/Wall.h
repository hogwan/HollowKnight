#pragma once
#include <ConsoleEngine/ConsoleObject.h>
class Wall : public ConsoleObject
{
public:
	// constructor destructor
	Wall();
	~Wall();

	// delete Function
	Wall(const Wall& _Other) = delete;
	Wall(Wall&& _Other) noexcept = delete;
	Wall& operator=(const Wall& _Other) = delete;
	Wall& operator=(Wall&& _Other) = delete;

protected:
	void Update() override;

};

