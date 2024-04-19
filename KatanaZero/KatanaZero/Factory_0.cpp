#include "PreCompile.h"
#include "Factory_0.h"
#include "BackMap_F0.h"
#include <EngineCore/Camera.h>
#include "ContentsHelper.h"
#include "Grunt.h"
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

	if (Start)
	{
		MoveNextLevel("Factory_1");
		RestartLevel("Factory_0");
	}
}

void AFactory_0::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_0_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale() * UConstValue::Ratio;

	float4 ImageScale = UConstValue::MapTexScale;

	std::shared_ptr<BackMap_F0> BackMap = GetWorld()->SpawnActor<BackMap_F0>("BackMap");
	BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	UConstValue::LayerChangePos.push_back(FVector(1100.f, -400.f, 200.f));
	std::shared_ptr<AGrunt> Grunt1 = GetWorld()->SpawnActor<AGrunt>("Grunt1");
	Grunt1->SetActorLocation(FVector(300.f, -300.f, 200.f));
	Grunt1->SetLayerLevel(1);
	EnemyVec.push_back(Grunt1);

	std::shared_ptr<AGrunt> Grunt2 = GetWorld()->SpawnActor<AGrunt>("Grunt1");
	Grunt2->SetActorLocation(FVector(1400.f, -300.f, 200.f));
	Grunt2->SetLayerLevel(1);
	EnemyVec.push_back(Grunt2);

	std::shared_ptr<ACop> Gangster = GetWorld()->SpawnActor<ACop>("Gangster");
	Gangster->SetActorLocation(FVector(500.f, -300.f, 200.f));
	Gangster->SetLayerLevel(1);
	EnemyVec.push_back(Gangster);

	std::shared_ptr<AKnife> Knife = GetWorld()->SpawnActor<AKnife>("Gangster");
	Knife->SetActorLocation({ 200.0f, -660.0f, 200.0f });

	std::shared_ptr<AFireBottle> FireBottle = GetWorld()->SpawnActor<AFireBottle>("Gangster");
	FireBottle->SetActorLocation({ 300.0f, -660.0f, 200.0f });

	std::shared_ptr<ADoor> Door = GetWorld()->SpawnActor<ADoor>("Gangster");
	Door->SetActorLocation({ 570.0f, -320.0f, 200.0f });
	Door->SetDir(EEngineDir::Left);
}

void AFactory_0::LevelEnd(ULevel* _NextLevel)
{
}
