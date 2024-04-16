#include "PreCompile.h"
#include "Factory_2.h"
#include "BackMap_F2.h"
#include <EngineCore/Camera.h>
#include "ContentsHelper.h"
#include "Player.h"
#include "Cursor.h"
#include "Grunt.h"
#include "UIBoard.h"
#include "BatteryBody.h"
#include "TimerBoard.h"
#include "WeaponSlot.h"
#include "ItemIcon.h"
#include "KatanaIcon.h"

AFactory_2::AFactory_2()
{
}

AFactory_2::~AFactory_2()
{
}

void AFactory_2::BeginPlay()
{
	Super::BeginPlay();

}

void AFactory_2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	PlayerPos.Z = -1000;
	Camera->SetActorLocation(PlayerPos);

	if (UConstValue::Player->NextLevel)
	{
		GEngine->ChangeLevel("Factory_3");
	}
}

void AFactory_2::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_3_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale() * UConstValue::Ratio;

	float4 ImageScale = UConstValue::MapTexScale;

	std::shared_ptr<ABackMap_F2> BackMap = GetWorld()->SpawnActor<ABackMap_F2>("BackMap");
	BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	UConstValue::Player = GetWorld()->SpawnActor<APlayer>("Player");
	UConstValue::Player->SetActorLocation({ 200.0f, -1180.0f, 200.0f });

	UConstValue::LayerChangePos.push_back(FVector(1100.f, -400.f, 200.f));

	std::shared_ptr<AUIBoard> UIBoard = GetWorld()->SpawnActor<AUIBoard>("UIBoard");
	std::shared_ptr<ABatteryBody> BatteryBody = GetWorld()->SpawnActor<ABatteryBody>("BatteryBody");
	std::shared_ptr<ATimerBoard> TimerBoard = GetWorld()->SpawnActor<ATimerBoard>("TimerBoard");
	std::shared_ptr<AWeaponSlot> WS = GetWorld()->SpawnActor<AWeaponSlot>("WS");
	std::shared_ptr<AItemIcon> ItemIcon = GetWorld()->SpawnActor<AItemIcon>("ItemIcon");
	std::shared_ptr<AKatanaIcon> KatanaIcon = GetWorld()->SpawnActor<AKatanaIcon>("KatanaIcon");

	UConstValue::MainCursor = GetWorld()->SpawnActor<ACursor>("Cursor");

	std::shared_ptr<AGrunt> Grunt1 = GetWorld()->SpawnActor<AGrunt>("Grunt1");
	Grunt1->SetActorLocation(FVector(300.f, -300.f, 200.f));
	Grunt1->SetLayerLevel(1);

	std::shared_ptr<AGrunt> Grunt2 = GetWorld()->SpawnActor<AGrunt>("Grunt1");
	Grunt2->SetActorLocation(FVector(1400.f, -300.f, 200.f));
	Grunt2->SetLayerLevel(1);
}

