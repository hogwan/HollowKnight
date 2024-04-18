#pragma once

// Ό³Έν :
class Factory_1
{
public:
	// constructor destructor
	Factory_1();
	~Factory_1();

	// delete Function
	Factory_1(const Factory_1& _Other) = delete;
	Factory_1(Factory_1&& _Other) noexcept = delete;
	Factory_1& operator=(const Factory_1& _Other) = delete;
	Factory_1& operator=(Factory_1&& _Other) noexcept = delete;

protected:

private:

};

