#include "PreCompile.h"
#include "PlayGameMode.h"
#include <EngineCore/Camera.h>
#include "Knight.h"
#include "MapObject.h"

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	GetWorld()->SpawnActor<AKnight>("Player");
	std::shared_ptr<MapObject> Map1 = GetWorld()->SpawnActor<MapObject>("MapObject");
	Map1->Renderer->SetSprite("tut_BG_set_02_0004_02.png");
	Map1->SetActorScale3D(FVector(200.f,200.f,200.f));
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
