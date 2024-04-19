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

	if (UEngineInput::IsDown('p') || UEngineInput::IsDown('P'))
	{
		LevelRestart();
	}

	UConstValue::EnemyAllDie = EnemyAllDeathCheck();
}

void KZGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	UConstValue::MainCursor = GetWorld()->SpawnActor<ACursor>("Cursor");
	AllActors.push_back(UConstValue::MainCursor);

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

	for (std::shared_ptr<AActor> Actor : AllActors)
	{
		Actor->Destroy();
	}

	AllActors.clear();
	EnemyVec.clear();
	UConstValue::LayerChangePos.clear();

	Camera->Destroy();
	UIBoard->Destroy();
	BatteryBody->Destroy();
	TimerBoard->Destroy();
	WS->Destroy();
	ItemIcon->Destroy();
	KatanaIcon->Destroy();
}

void KZGameMode::MoveNextLevel(std::string_view _NextLevel)
{
	if (UConstValue::EnemyAllDie)
	{
		if (UConstValue::Player->NextLevel)
		{
			GEngine->ChangeLevel(_NextLevel);
			return;
		}

		if (UConstValue::Player->State.GetCurStateName() == "Replay")
		{
			if(UEngineInput::IsDown(VK_RBUTTON))
			{
				GEngine->ChangeLevel(_NextLevel);
				return;
			}
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
		if(UEngineInput::IsDown(VK_RBUTTON))
		{
			GEngine->ChangeLevel(_RestartLevel);
			return;
		}
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

void KZGameMode::LevelRestart()
{
	LevelEnd(GetWorld());
	LevelStart(GetWorld());
}

