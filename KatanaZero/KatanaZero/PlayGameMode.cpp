#include "PreCompile.h"
#include "PlayGameMode.h"
#include "BackGroundMap.h"
#include <EngineCore/Camera.h>
#include "ContentsHelper.h"
#include "Player.h"
#include "CameraManager.h"
#include "Cursor.h"
#include "Grunt.h"
#include "Cop.h"
#include "Pomp.h"
#include "PlayerLayerChangeCollider.h"
#include "EnemyLayerChangeCol.h"
#include "Knife.h"
#include "UIBoard.h"
#include "BatteryBody.h"

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	/*UConstValue::MainCameraManager = GetWorld()->SpawnActor<ACameraManager>("CameraManager");
	UConstValue::MainCameraManager->SetCameraMode(ECameraMode::ChasePlayer);*/

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	UConstValue::MapTex = UEngineTexture::FindRes("room_factory_2_colmap.png");
	UConstValue::MapTexScale = UConstValue::MapTex->GetScale() * UConstValue::Ratio;

	float4 ImageScale = UConstValue::MapTexScale;

	UConstValue::BackMap = GetWorld()->SpawnActor<ABackGroundMap>("BackMap");
	UConstValue::BackMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	UConstValue::Player = GetWorld()->SpawnActor<APlayer>("Player");
	UConstValue::Player->SetActorLocation({ 200.0f, -500.0f, 200.0f });

	std::shared_ptr<AUIBoard> UIBoard = GetWorld()->SpawnActor<AUIBoard>("UIBoard");
	std::shared_ptr<ABatteryBody> BatteryBody = GetWorld()->SpawnActor<ABatteryBody>("BatteryBody");

	std::shared_ptr<APlayerLayerChangeCollider> LayerChangeCol = GetWorld()->SpawnActor<APlayerLayerChangeCollider>("LCC");
	LayerChangeCol->SetActorLocation(FVector(680.f, -315.f, 200.f));

	UConstValue::EnemyLayerChangeCols.push_back(FVector(900.f, -300.f, 200.f));

	std::shared_ptr<AGrunt> Grunt = GetWorld()->SpawnActor<AGrunt>("Grunt");
	Grunt->SetActorLocation({ 500.f,-500.f,200.f });

	std::shared_ptr<ACop> Cop = GetWorld()->SpawnActor<ACop>("Cop");
	Cop->SetActorLocation({ 600.f,-500.f,200.f });

	std::shared_ptr<APomp> Pomp = GetWorld()->SpawnActor<APomp>("Pomp");
	Pomp->SetActorLocation({ 700.f,-400.f,200.f });

	std::shared_ptr<AKnife> Knife = GetWorld()->SpawnActor<AKnife>("Knife");
	Knife->SetActorLocation({ 200.0f, -500.0f, 200.0f });

	UConstValue::MainCursor = GetWorld()->SpawnActor<ACursor>("Cursor");
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	PlayerPos.Z -= 1000;
	Camera->SetActorLocation(PlayerPos);
}

