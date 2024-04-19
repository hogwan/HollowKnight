#include "PreCompile.h"
#include "KZGameMode.h"
#include <EngineCore/Camera.h>
#include "UIBoard.h"
#include "TimerBoard.h"
#include "BatteryBody.h"
#include "WeaponSlot.h"
#include "ItemIcon.h"
#include "KatanaIcon.h"
#include "Cursor.h"

KZGameMode::KZGameMode() 
{
}

KZGameMode::~KZGameMode() 
{
}

void KZGameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

void KZGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	PlayerPos.Z = -1000;
	Camera->SetActorLocation(PlayerPos);
}

void KZGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	UConstValue::Player = GetWorld()->SpawnActor<APlayer>("Player");
	UConstValue::Player->SetActorLocation({ 200.0f, -660.0f, 200.0f });

	UConstValue::MainCursor = GetWorld()->SpawnActor<ACursor>("Cursor");

	UIBoard = GetWorld()->SpawnActor<AUIBoard>("UIBoard");
	BatteryBody = GetWorld()->SpawnActor<ABatteryBody>("BatteryBody");
	TimerBoard = GetWorld()->SpawnActor<ATimerBoard>("TimerBoard");
	WS = GetWorld()->SpawnActor<AWeaponSlot>("WS");
	ItemIcon = GetWorld()->SpawnActor<AItemIcon>("ItemIcon");
	KatanaIcon = GetWorld()->SpawnActor<AKatanaIcon>("KatanaIcon");

	Start = true;
}

void KZGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	Camera->Destroy();
	UConstValue::Player->Destroy();
	UConstValue::MainCursor->Destroy();
	UIBoard->Destroy();
	BatteryBody->Destroy();
	TimerBoard->Destroy();
	WS->Destroy();
	ItemIcon->Destroy();
	KatanaIcon->Destroy();
}

void KZGameMode::MoveNextLevel(std::string_view _NextLevel)
{
	if (EnemyAllDeathCheck())
	{
		if (UConstValue::Player->NextLevel)
		{
			GEngine->ChangeLevel(_NextLevel);
			return;
		}

		if (UConstValue::Player->State.GetCurStateName() == "Replay")
		{
			UEngineInput::IsDown(VK_RBUTTON);
			GEngine->ChangeLevel(_NextLevel);
			return;
		}
	}
}

void KZGameMode::RestartLevel(std::string_view _RestartLevel)
{
	if (UConstValue::Player->Restart)
	{
		GEngine->ChangeLevel(_RestartLevel);
		return;
	}

	if (UConstValue::Player->State.GetCurStateName() == "Revert")
	{
		UEngineInput::IsDown(VK_RBUTTON);
		GEngine->ChangeLevel(_RestartLevel);
		return;
	}
}

bool KZGameMode::EnemyAllDeathCheck()
{
	for (std::shared_ptr<AEnemy> Enemy : EnemyVec)
	{
		if (Enemy->IsDeath == false)
		{
			return false;
		}
	}
	return true;
}

