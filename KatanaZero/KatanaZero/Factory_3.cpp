#include "PreCompile.h"
#include "Factory_3.h"
#include "BackMap_F3.h"
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

AFactory_3::AFactory_3() 
{
}

AFactory_3::~AFactory_3() 
{
}

void AFactory_3::BeginPlay()
{
	Super::BeginPlay();
}

void AFactory_3::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	PlayerPos.Z = -1000;
	Camera->SetActorLocation(PlayerPos);
}

void AFactory_3::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_4_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale() * UConstValue::Ratio;

	float4 ImageScale = UConstValue::MapTexScale;

	std::shared_ptr<ABackMap_F3> BackMap = GetWorld()->SpawnActor<ABackMap_F3>("BackMap");
	BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	UConstValue::Player = GetWorld()->SpawnActor<APlayer>("Player");
	UConstValue::Player->SetActorLocation({ 200.0f, -900.0f, 200.0f });

	UConstValue::LayerChangePos.push_back(FVector(1100.f, -400.f, 200.f));

	std::shared_ptr<AUIBoard> UIBoard = GetWorld()->SpawnActor<AUIBoard>("UIBoard");
	std::shared_ptr<ABatteryBody> BatteryBody = GetWorld()->SpawnActor<ABatteryBody>("BatteryBody");
	std::shared_ptr<ATimerBoard> TimerBoard = GetWorld()->SpawnActor<ATimerBoard>("TimerBoard");
	std::shared_ptr<AWeaponSlot> WS = GetWorld()->SpawnActor<AWeaponSlot>("WS");
	std::shared_ptr<AItemIcon> ItemIcon = GetWorld()->SpawnActor<AItemIcon>("ItemIcon");
	std::shared_ptr<AKatanaIcon> KatanaIcon = GetWorld()->SpawnActor<AKatanaIcon>("KatanaIcon");

	UConstValue::MainCursor = GetWorld()->SpawnActor<ACursor>("Cursor");
}
