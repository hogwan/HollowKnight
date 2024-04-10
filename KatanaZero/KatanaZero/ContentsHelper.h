#pragma once

class UConstValue
{
public:
	static std::shared_ptr<class UEngineTexture> MapTex;
	static std::shared_ptr<class Player> MainCharacter;
	static std::shared_ptr<class CameraManager> MainCameraManager;
	static std::shared_ptr<class BackGroundMap> BackMap;
	static float4 MapTexScale;
};


enum class ERenderOrder
{
	Back,
	Player,
};

enum class EActorDir
{
	None,
	Left,
	Right,
};

enum class ECameraMode
{
	None,
	ChasePlayer,
};
