#include "PreCompile.h"
#include "PlayGameMode.h"
#include "BackGroundMap.h"
#include <EngineCore/Camera.h>
#include "ContentsHelper.h"
#include "Player.h"
#include "CameraManager.h"

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	UConstValue::MainCameraManager = GetWorld()->SpawnActor<CameraManager>("CameraManager");
	UConstValue::MainCameraManager->SetCameraMode(ECameraMode::ChasePlayer);

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_4_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale()*2.f;

	float4 ImageScale = UConstValue::MapTexScale;

	UConstValue::BackMap = GetWorld()->SpawnActor<BackGroundMap>("BackMap");
	UConstValue::BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	UConstValue::MainCharacter = GetWorld()->SpawnActor<Player>("Player");
	UConstValue::MainCharacter->SetActorLocation({ 640.0f, -360.0f, 200.0f });
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

