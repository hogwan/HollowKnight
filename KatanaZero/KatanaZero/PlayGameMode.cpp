#include "PreCompile.h"
#include "PlayGameMode.h"
#include "BackGroundMap.h"
#include <EngineCore/Camera.h>
#include "ConstValueHelper.h"
#include "Player.h"

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
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_4_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale();

	float4 ImageScale = UConstValue::MapTexScale;

	std::shared_ptr<BackGroundMap> BackMap = GetWorld()->SpawnActor<BackGroundMap>("BackMap");
	BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	std::shared_ptr<Player> Actor = GetWorld()->SpawnActor<Player>("Player");
		Actor->SetActorLocation({ 640.0f, -360.0f, 200.0f });
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

