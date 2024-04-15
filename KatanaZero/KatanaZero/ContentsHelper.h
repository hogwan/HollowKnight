#pragma once

class UConstValue
{
public:
	static std::shared_ptr<class UEngineTexture> MapTex;
	static std::shared_ptr<class APlayer> Player;
	static std::shared_ptr<class ACameraManager> MainCameraManager;
	static std::shared_ptr<class ABackGroundMap> BackMap;
	static std::shared_ptr<class ACursor> MainCursor;
	static std::vector<FVector> EnemyLayerChangeCols;
	static float4 MapTexScale;
	static float Ratio;
};


enum class ERenderOrder
{
	Back,
	Enemy,
	EnemyArms,
	Player,
	Bullet,
	Item,
	FX,
	UIBoard,
	UI,
	Cursor,
};

enum class ECollisionOrder
{
	Player,
	Enemy,
	PlayerLayerChange,
	EnemyLayerChange,
	PlayerSlash,
	Item,
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

enum class ItemState
{
	Idle,
	Throw,
};

enum class ItemType
{
	None,
	Knife,
	Smoke,
	FireBottle,
	Bottle,

};
