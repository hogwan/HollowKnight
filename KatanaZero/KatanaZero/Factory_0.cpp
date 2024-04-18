#include "PreCompile.h"
#include "Factory_0.h"
#include "BackMap_F0.h"
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
#include "Gangster.h"
#include "Factory_2.h"
#include "Cop.h"
#include "Knife.h"
#include "FireBottle.h"
#include "Door.h"
#include "LaserLauncher.h"

AFactory_0::AFactory_0() 
{
}

AFactory_0::~AFactory_0() 
{
}

void AFactory_0::BeginPlay()
{
	Super::BeginPlay();

}

void AFactory_0::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	PlayerPos.Z = -1000;
	Camera->SetActorLocation(PlayerPos);

	if (UConstValue::Player->NextLevel)
	{
		GEngine->ChangeLevel("Factory_1");
	}
}

void AFactory_0::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_0_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale() * UConstValue::Ratio;

	float4 ImageScale = UConstValue::MapTexScale;

	std::shared_ptr<BackMap_F0> BackMap = GetWorld()->SpawnActor<BackMap_F0>("BackMap");
	BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	UConstValue::Player = GetWorld()->SpawnActor<APlayer>("Player");
	UConstValue::Player->SetActorLocation({ 200.0f, -660.0f, 200.0f });

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

	std::shared_ptr<ACop> Gangster = GetWorld()->SpawnActor<ACop>("Gangster");
	Gangster->SetActorLocation(FVector(500.f, -300.f, 200.f));
	Gangster->SetLayerLevel(1);

	std::shared_ptr<AKnife> Knife = GetWorld()->SpawnActor<AKnife>("Gangster");
	Knife->SetActorLocation({ 200.0f, -660.0f, 200.0f });

	std::shared_ptr<AFireBottle> FireBottle = GetWorld()->SpawnActor<AFireBottle>("Gangster");
	FireBottle->SetActorLocation({ 300.0f, -660.0f, 200.0f });

	std::shared_ptr<ADoor> Door = GetWorld()->SpawnActor<ADoor>("Gangster");
	Door->SetActorLocation({ 570.0f, -320.0f, 200.0f });
	Door->SetDir(EActorDir::Left);


}