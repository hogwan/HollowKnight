#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

enum class EKnightState
{
	None,
	Idle,

	LookUp,
	LookUpToIdle,

	LookDown,
	LookDownToIdle,

	Run,
	Walk,
	RunToIdle,

	Turn,

	Airborne,
	Fall,

	Land,
	HardLand,

	Slash,
	SlashAlt,
	
	UpSlash,
	DownSlash,

	Dash,
	DashToIdle,

	WallSlide,
	WallJump,

	Sit,
	SitOff,

	MapOpen,
	MapIdle,
	MapWalk,
	MapAway,
	MapTurn,

	SitMapOpen,
	SitMapClose,
	MapUpdate,

	Focus,
	FocusGet,
	FocusEnd,

	CollectMagical1,
	CollectMagical2,
	CollectMagical3,

	CollectNormal1,
	CollectNormal2,
	CollectNormal3,

	Enter,

	Prostrate,
	ProstrateRise,

	FireballAntic,
	FireballCast,

	Recoil,
	Death,
};

class AKnight : public AActor
{
	GENERATED_BODY(AActor)
public:
	//constructer destructer
	AKnight();
	~AKnight();

	//delete Function
	AKnight(const AKnight& _Other) = delete;
	AKnight(AKnight&& _Other) noexcept = delete;
	AKnight& operator=(const AKnight& _Other) = delete;
	AKnight& operator=(AKnight&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void StateChange(EKnightState _State);
	void StateUpdate(float _DeltaTime);

	void None(float _DeltaTime);
	void Idle(float _DeltaTime);
	void LookUp(float _DeltaTime);
	void LookUpToIdle(float _DeltaTime);
	void LookDown(float _DeltaTime);
	void LookDownToIdle(float _DeltaTime);
	void Run(float _DeltaTime);
	void Walk(float _DeltaTime);
	void RunToIdle(float _DeltaTime);
	void Turn(float _DeltaTime);
	void Airborne(float _DeltaTime);
	void Fall(float _DeltaTime);
	void Land(float _DeltaTime);
	void HardLand(float _DeltaTime);
	void Slash(float _DeltaTime);
	void SlashAlt(float _DeltaTime);
	void UpSlash(float _DeltaTime);
	void DownSlash(float _DeltaTime);
	void Dash(float _DeltaTime);
	void DashToIdle(float _DeltaTime);
	void WallSlide(float _DeltaTime);
	void WallJump(float _DeltaTime);
	void Sit(float _DeltaTime);
	void SitOff(float _DeltaTime);
	void MapOpen(float _DeltaTime);
	void MapIdle(float _DeltaTime);
	void MapWalk(float _DeltaTime);
	void MapAway(float _DeltaTime);
	void MapTurn(float _DeltaTime);
	void SitMapOpen(float _DeltaTime);
	void SitMapClose(float _DeltaTime);
	void MapUpdate(float _DeltaTime);
	void Focus(float _DeltaTime);
	void FocusGet(float _DeltaTime);
	void FocusEnd(float _DeltaTime);
	void CollectMagical1(float _DeltaTime);
	void CollectMagical2(float _DeltaTime);
	void CollectMagical3(float _DeltaTime);
	void CollectNormal1(float _DeltaTime);
	void CollectNormal2(float _DeltaTime);
	void CollectNormal3(float _DeltaTime);
	void Enter(float _DeltaTime);
	void Prostrate(float _DeltaTime);
	void ProstrateRise(float _DeltaTime);
	void FireballAntic(float _DeltaTime);
	void FireballCast(float _DeltaTime);
	void Recoil(float _DeltaTime);
	void Death(float _DeltaTime);

	void NoneStart();
	void IdleStart();
	void LookUpStart();
	void LookUpToIdleStart();
	void LookDownStart();
	void LookDownToIdleStart();
	void RunStart();
	void WalkStart();
	void RunToIdleStart();
	void TurnStart();
	void AirborneStart();
	void FallStart();
	void LandStart();
	void HardLandStart();
	void SlashStart();
	void SlashAltStart();
	void UpSlashStart();
	void DownSlashStart();
	void DashStart();
	void DashToIdleStart();
	void WallSlideStart();
	void WallJumpStart();
	void SitStart();
	void SitOffStart();
	void MapOpenStart();
	void MapIdleStart();
	void MapWalkStart();
	void MapAwayStart();
	void MapTurnStart();
	void SitMapOpenStart();
	void SitMapCloseStart();
	void MapUpdateStart();
	void FocusStart();
	void FocusGetStart();
	void FocusEndStart();
	void CollectMagical1Start();
	void CollectMagical2Start();
	void CollectMagical3Start();
	void CollectNormal1Start();
	void CollectNormal2Start();
	void CollectNormal3Start();
	void EnterStart();
	void ProstrateStart();
	void ProstrateRiseStart();
	void FireballAnticStart();
	void FireballCastStart();
	void RecoilStart();
	void DeathStart();
private:
	USpriteRenderer* Renderer = nullptr;

	FVector Dir = FVector::Left;
	EKnightState CurState = EKnightState::None;

	float PressTime = 0.f;
	float FocusTime = 0.3f;

	float AirborneTime = 0.f;
	float AirborneLimit = 0.5f;

	float MoveSpeed = 300.f;
	float AirborneSpeed = 300.f;
	float DashSpeed = 600.f;

	float DashCoolTime = 1.f;
	float DashTime = 0.2f;
	float AccDash = 0.f;

	bool IsLanded = false;
	bool IsAirborneStart = false;

	bool Manupulate = true;
	void ManupulateUpdate(float _DeltaTime);
	void LandCheck();


	inline void ManupulateOff()
	{
		Manupulate = false;
	}

	inline void ManupulateOn()
	{
		Manupulate = true;
	}
};