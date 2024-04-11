#pragma once

// Ό³Έν :
class PlayerJumpFX
{
public:
	// constructor destructor
	PlayerJumpFX();
	~PlayerJumpFX();

	// delete Function
	PlayerJumpFX(const PlayerJumpFX& _Other) = delete;
	PlayerJumpFX(PlayerJumpFX&& _Other) noexcept = delete;
	PlayerJumpFX& operator=(const PlayerJumpFX& _Other) = delete;
	PlayerJumpFX& operator=(PlayerJumpFX&& _Other) noexcept = delete;

protected:

private:

};

