#include "PreCompile.h"
#include "Factory_1.h"
#include "BackMap_F1.h"
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
#include "LaserLauncher.h"
#include "LaserSwitch.h"

AFactory_1::AFactory_1()
{
}

AFactory_1::~AFactory_1()
{
}

void AFactory_1::BeginPlay()
{
	Super::BeginPlay();

}

void AFactory_1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	PlayerPos.Z = -1000;
	Camera->SetActorLocation(PlayerPos);

	if (UConstValue::Player->NextLevel)
	{
		GEngine->ChangeLevel("Factory_2");
	}
}

void AFactory_1::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_1_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale() * UConstValue::Ratio;

	float4 ImageScale = UConstValue::MapTexScale;

	std::shared_ptr<ABackMap_F1> BackMap = GetWorld()->SpawnActor<ABackMap_F1>("BackMap");
	BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	UConstValue::Player = GetWorld()->SpawnActor<APlayer>("Player");
	UConstValue::Player->SetActorLocation({ 200.0f, -300.0f, 200.0f });

	UConstValue::LayerChangePos.push_back(FVector(1100.f, -400.f, 200.f));

	std::shared_ptr<AUIBoard> UIBoard = GetWorld()->SpawnActor<AUIBoard>("UIBoard");
	std::shared_ptr<ABatteryBody> BatteryBody = GetWorld()->SpawnActor<ABatteryBody>("BatteryBody");
	std::shared_ptr<ATimerBoard> TimerBoard = GetWorld()->SpawnActor<ATimerBoard>("TimerBoard");
	std::shared_ptr<AWeaponSlot> WS = GetWorld()->SpawnActor<AWeaponSlot>("WS");
	std::shared_ptr<AItemIcon> ItemIcon = GetWorld()->SpawnActor<AItemIcon>("ItemIcon");
	std::shared_ptr<AKatanaIcon> KatanaIcon = GetWorld()->SpawnActor<AKatanaIcon>("KatanaIcon");

	UConstValue::MainCursor = GetWorld()->SpawnActor<ACursor>("Cursor");

	std::shared_ptr<ALaserSwitch> LaserSwitch = GetWorld()->SpawnActor<ALaserSwitch>("LaserSwitch");
	LaserSwitch->SetActorLocation(FVector(1760.f, -410.f, 0.f));
	LaserSwitch->On();

	std::shared_ptr<ALaserLauncher> Laser1 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser1->SetLaserSize(230.f);
	Laser1->SetActorLocation(FVector(510.f, -250.f, 0.f));

	std::shared_ptr<ALaserLauncher> Laser2 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser2->SetLaserSize(230.f);
	Laser2->SetActorLocation(FVector(560.f, -250.f, 0.f));

	std::shared_ptr<ALaserLauncher> Laser3 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser3->SetLaserSize(230.f);
	Laser3->SetActorLocation(FVector(1100.f, -250.f, 0.f));
	Laser3->SetDir(FVector::Left);

	std::shared_ptr<ALaserLauncher> Laser4 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser4->SetLaserSize(230.f);
	Laser4->SetActorLocation(FVector(1150.f, -250.f, 0.f));
	Laser4->SetDir(FVector::Right);

	std::shared_ptr<ALaserLauncher> Laser5 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser5->SetLaserSize(230.f);
	Laser5->SetActorLocation(FVector(1900.f, -250.f, 0.f));

	std::shared_ptr<ALaserLauncher> Laser6 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser6->SetLaserSize(230.f);
	Laser6->SetActorLocation(FVector(1950.f, -250.f, 0.f));

	std::shared_ptr<ALaserLauncher> Laser7 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser7->SetLaserSize(230.f);
	Laser7->SetActorLocation(FVector(2000.f, -250.f, 0.f));

	std::shared_ptr<ALaserLauncher> Laser8 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser8->SetLaserSize(230.f);
	Laser8->SetActorLocation(FVector(2050.f, -250.f, 0.f));

	std::shared_ptr<ALaserLauncher> Laser9 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser9->SetLaserSize(230.f);
	Laser9->SetActorLocation(FVector(2100.f, -250.f, 0.f));

	LaserSwitch->PushLaser(Laser1);
	LaserSwitch->PushLaser(Laser2);
	LaserSwitch->PushLaser(Laser3);
	LaserSwitch->PushLaser(Laser4);
	LaserSwitch->PushLaser(Laser5);
	LaserSwitch->PushLaser(Laser6);
	LaserSwitch->PushLaser(Laser7);
	LaserSwitch->PushLaser(Laser8);
	LaserSwitch->PushLaser(Laser9);

}

