#include "PreCompile.h"
#include "Factory_1.h"
#include "BackMap_F1.h"
#include <EngineCore/Camera.h>
#include "ContentsHelper.h"
#include "Grunt.h"
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

	if (Start)
	{
		MoveNextLevel("Factory_2");
		RestartLevel("Factory_1");
	}
}

void AFactory_1::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_1_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale() * UConstValue::Ratio;

	float4 ImageScale = UConstValue::MapTexScale;

	std::shared_ptr<ABackMap_F1> BackMap = GetWorld()->SpawnActor<ABackMap_F1>("BackMap");
	BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });
	AllActors.push_back(BackMap);

	UConstValue::Player = GetWorld()->SpawnActor<APlayer>("Player");
	UConstValue::Player->SetActorLocation({ 200.0f, -470.0f, 200.0f });
	AllActors.push_back(UConstValue::Player);

	std::shared_ptr<ALaserSwitch> LaserSwitch = GetWorld()->SpawnActor<ALaserSwitch>("LaserSwitch");
	LaserSwitch->SetActorLocation(FVector(1760.f, -410.f, 0.f));
	LaserSwitch->On();
	AllActors.push_back(LaserSwitch);

	std::shared_ptr<ALaserLauncher> Laser1 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser1->SetLaserSize(230.f);
	Laser1->SetActorLocation(FVector(510.f, -250.f, 0.f));
	AllActors.push_back(Laser1);

	std::shared_ptr<ALaserLauncher> Laser2 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser2->SetLaserSize(230.f);
	Laser2->SetActorLocation(FVector(560.f, -250.f, 0.f));
	AllActors.push_back(Laser2);

	std::shared_ptr<ALaserLauncher> Laser3 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser3->SetLaserSize(230.f);
	Laser3->SetActorLocation(FVector(1100.f, -250.f, 0.f));
	Laser3->SetDir(FVector::Left);
	AllActors.push_back(Laser3);

	std::shared_ptr<ALaserLauncher> Laser4 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser4->SetLaserSize(230.f);
	Laser4->SetActorLocation(FVector(1150.f, -250.f, 0.f));
	Laser4->SetDir(FVector::Right);
	AllActors.push_back(Laser4);

	std::shared_ptr<ALaserLauncher> Laser5 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser5->SetLaserSize(230.f);
	Laser5->SetActorLocation(FVector(1900.f, -250.f, 0.f));
	AllActors.push_back(Laser5);

	std::shared_ptr<ALaserLauncher> Laser6 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser6->SetLaserSize(230.f);
	Laser6->SetActorLocation(FVector(1950.f, -250.f, 0.f));
	AllActors.push_back(Laser6);

	std::shared_ptr<ALaserLauncher> Laser7 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser7->SetLaserSize(230.f);
	Laser7->SetActorLocation(FVector(2000.f, -250.f, 0.f));
	AllActors.push_back(Laser7);

	std::shared_ptr<ALaserLauncher> Laser8 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser8->SetLaserSize(230.f);
	Laser8->SetActorLocation(FVector(2050.f, -250.f, 0.f));
	AllActors.push_back(Laser8);

	std::shared_ptr<ALaserLauncher> Laser9 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser9->SetLaserSize(230.f);
	Laser9->SetActorLocation(FVector(2100.f, -250.f, 0.f));
	AllActors.push_back(Laser9);

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

