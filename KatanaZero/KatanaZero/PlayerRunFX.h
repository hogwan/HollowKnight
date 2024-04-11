#pragma once

// Ό³Έν :
class PlayerRunFX
{
public:
	// constructor destructor
	PlayerRunFX();
	~PlayerRunFX();

	// delete Function
	PlayerRunFX(const PlayerRunFX& _Other) = delete;
	PlayerRunFX(PlayerRunFX&& _Other) noexcept = delete;
	PlayerRunFX& operator=(const PlayerRunFX& _Other) = delete;
	PlayerRunFX& operator=(PlayerRunFX&& _Other) noexcept = delete;

protected:

private:

};

