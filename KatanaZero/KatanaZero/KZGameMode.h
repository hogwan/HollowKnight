#pragma once
#include <EngineCore/GameMode.h>
#include "Player.h"
#include "Enemy.h"

// Ό³Έν :
class KZGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constructor destructor
	KZGameMode();
	~KZGameMode();

	// delete Function
	KZGameMode(const KZGameMode& _Other) = delete;
	KZGameMode(KZGameMode&& _Other) noexcept = delete;
	KZGameMode& operator=(const KZGameMode& _Other) = delete;
	KZGameMode& operator=(KZGameMode&& _Other) noexcept = delete;
	bool EnemyAllDeathCheck();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

	void MoveNextLevel(std::string_view _NextLevel);
	void RestartLevel(std::string_view _RestartLevel);
	bool Start = false;
	std::vector<std::shared_ptr<AEnemy>> EnemyVec;
	std::vector<std::shared_ptr<AActor>> AllActors;

	void LevelRestart();

private:
	std::shared_ptr<UCamera> Camera;
	std::shared_ptr<class AUIBoard> UIBoard;
	std::shared_ptr<class ABatteryBody> BatteryBody;
	std::shared_ptr<class ATimerBoard> TimerBoard;
	std::shared_ptr<class AWeaponSlot> WS;
	std::shared_ptr<class AItemIcon> ItemIcon;
	std::shared_ptr<class AKatanaIcon> KatanaIcon;
};

