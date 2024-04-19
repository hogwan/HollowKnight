#pragma once

class UConstValue
{
public:
	static std::shared_ptr<class UEngineTexture> MapTex;
	static std::shared_ptr<class APlayer> Player;
	static std::shared_ptr<class ACameraManager> MainCameraManager;
	static std::shared_ptr<class ACursor> MainCursor;
	static std::vector<FVector> LayerChangePos;
	static float4 MapTexScale;
	static float Ratio;
	static float recording_delay;
	static bool EnemyAllDie;
};


enum class ERenderOrder
{
	Back,
	Enemy,
	EnemyArms,
	Object,
	Player,
	Bullet,
	Item,
	FX,
	ObjectFront,
	UIBoard,
	UI,
	UIFront,
	Cursor,
};

enum class ECollisionOrder
{
	Player,
	Enemy,
	EnemyAttack,
	Bullet,
	PlayerLayerChange,
	EnemyLayerChange,
	PlayerSlash,
	FanBlade,
	Door,
	Laser,
	Item,
	Switch,
	WallObject,
	ColCheck,
};

enum class ECameraMode
{
	None,
	ChasePlayer,
};

enum class EItemState
{
	Idle,
	Throw,
};

enum class EItemType
{
	None,
	Knife,
	Smoke,
	FireBottle,
	Bottle,
};
