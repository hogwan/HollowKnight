#pragma once

// Ό³Έν :
class PlayerLandFX
{
public:
	// constructor destructor
	PlayerLandFX();
	~PlayerLandFX();

	// delete Function
	PlayerLandFX(const PlayerLandFX& _Other) = delete;
	PlayerLandFX(PlayerLandFX&& _Other) noexcept = delete;
	PlayerLandFX& operator=(const PlayerLandFX& _Other) = delete;
	PlayerLandFX& operator=(PlayerLandFX&& _Other) noexcept = delete;

protected:

private:

};

