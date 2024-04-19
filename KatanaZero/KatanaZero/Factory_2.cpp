#include "PreCompile.h"
#include "Factory_2.h"
#include "BackMap_F2.h"
#include <EngineCore/Camera.h>
#include "ContentsHelper.h"
#include "Grunt.h"
#include "FanBlade.h"
#include "FanFront.h"
#include "LaserLauncher.h"

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
	MoveNextLevel("Factory_3");
	RestartLevel("Factory_2");
}

void AFactory_2::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_2_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale() * UConstValue::Ratio;

	float4 ImageScale = UConstValue::MapTexScale;

	std::shared_ptr<ABackMap_F2> BackMap = GetWorld()->SpawnActor<ABackMap_F2>("BackMap");
	BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });
	AllActors.push_back(BackMap);

	UConstValue::LayerChangePos.push_back(FVector(1100.f, -400.f, 200.f));

	UConstValue::Player = GetWorld()->SpawnActor<APlayer>("Player");
	UConstValue::Player->SetActorLocation({ 200.0f, -1170.0f, 200.0f });
	AllActors.push_back(UConstValue::Player);

	std::shared_ptr<AGrunt> Grunt1 = GetWorld()->SpawnActor<AGrunt>("Grunt1");
	Grunt1->SetActorLocation(FVector(300.f, -300.f, 200.f));
	AllActors.push_back(Grunt1);
	EnemyVec.push_back(Grunt1);

	std::shared_ptr<AGrunt> Grunt2 = GetWorld()->SpawnActor<AGrunt>("Grunt1");
	Grunt2->SetActorLocation(FVector(1400.f, -300.f, 200.f));
	AllActors.push_back(Grunt2);
	EnemyVec.push_back(Grunt2);

	std::shared_ptr<AFanBlade> Fan = GetWorld()->SpawnActor<AFanBlade>("Fan");
	Fan->SetActorLocation({ 1422.0f, -367.0f, 200.0f });
	AllActors.push_back(Fan);

	std::shared_ptr<AFanFront> FanFront = GetWorld()->SpawnActor<AFanFront>("FanFront");
	FanFront->SetActorLocation({ 1422.0f, -367.0f, 200.0f });
	AllActors.push_back(FanFront);

	std::shared_ptr<ALaserLauncher> Laser2 = GetWorld()->SpawnActor<ALaserLauncher>("Laser");
	Laser2->SetActorLocation({ 940.f, -255.f, 200.0f });
	Laser2->SetLaserSize(510.f);
	AllActors.push_back(Laser2);
}

