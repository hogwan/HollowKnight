#include "PreCompile.h"
#include "Factory_3.h"
#include "BackMap_F3.h"
#include "ContentsHelper.h"
#include "Player.h"
#include "Cursor.h"
#include "Grunt.h"
#include "Door.h"
#include "LaserLauncher.h"
#include "LaserSwitch.h"

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
}

void AFactory_3::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_3_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale() * UConstValue::Ratio;

	float4 ImageScale = UConstValue::MapTexScale;

	std::shared_ptr<ABackMap_F3> BackMap = GetWorld()->SpawnActor<ABackMap_F3>("BackMap");
	BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	std::shared_ptr<ALaserSwitch> LaserSwitch = GetWorld()->SpawnActor<ALaserSwitch>("LaserSwitch");
	LaserSwitch->SetActorLocation({ 1520.f, -300.f, 200.0f });

	std::shared_ptr<ADoor> Door1 = GetWorld()->SpawnActor<ADoor>("Gangster");
	Door1->SetActorLocation({ 1420.0f, -607.0f, 200.0f });
	Door1->SetDir(EEngineDir::Right);

	std::shared_ptr<ALaserLauncher> Laser1 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser1->SetActorLocation({ 650.f, -450.f, 200.0f });
	Laser1->SetLaserSize(220.f);

	std::shared_ptr<ALaserLauncher> Laser2 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser2->SetActorLocation({ 680.f, -450.f, 200.0f });
	Laser2->SetLaserSize(220.f);

	std::shared_ptr<ALaserLauncher> Laser3 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser3->SetActorLocation({ 750.f, -160.f, 200.0f });
	Laser3->SetLaserSize(220.f);

	std::shared_ptr<ALaserLauncher> Laser4 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser4->SetActorLocation({ 780.f, -160.f, 200.0f });
	Laser4->SetLaserSize(220.f);

	std::shared_ptr<ADoor> Door2 = GetWorld()->SpawnActor<ADoor>("Gangster");
	Door2->SetActorLocation({ 1070.0f, -320.0f, 200.0f });
	Door2->SetDir(EEngineDir::Right);

	std::shared_ptr<ALaserLauncher> Laser5 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser5->SetActorLocation({ 1715.f, -225.f, 200.0f });
	Laser5->SetLaserSize(155.f);

	std::shared_ptr<ALaserLauncher> Laser6 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser6->SetActorLocation({ 1745.f, -225.f, 200.0f });
	Laser6->SetLaserSize(155.f);

	LaserSwitch->PushLaser(Laser1);
	LaserSwitch->PushLaser(Laser2);
	LaserSwitch->PushLaser(Laser3);
	LaserSwitch->PushLaser(Laser4);
	LaserSwitch->PushLaser(Laser5);
	LaserSwitch->PushLaser(Laser6);
	LaserSwitch->On();
}
