#pragma once

class UConstValue
{
public:
	static std::shared_ptr<class UEngineTexture> MapTex;
	static std::shared_ptr<class APlayer> Player;
	static std::shared_ptr<class ACameraManager> MainCameraManager;
	static std::shared_ptr<class ABackGroundMap> BackMap;
	static std::shared_ptr<class ACursor> MainCursor;
	static float4 MapTexScale;
	static float Ratio;
};


enum class ERenderOrder
{
	Back,
	Enemy,
	Player,
	FX,
	Cursor,
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
