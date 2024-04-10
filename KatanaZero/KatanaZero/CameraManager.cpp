#include "PreCompile.h"
#include "CameraManager.h"
#include "ContentsHelper.h"
#include "Player.h"
#include "BackGroundMap.h"
#include <EngineCore/Camera.h>

CameraManager::CameraManager()
{
}

CameraManager::~CameraManager()
{
}

void CameraManager::BeginPlay()
{
	Super::BeginPlay();

	Camera = GetWorld()->GetMainCamera();
}

void CameraManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CameraPos = Camera->GetActorLocation();

	XEndCheck();
	YEndCheck();

	switch (CurMode)
	{
	case ECameraMode::None:
		break;
	case ECameraMode::ChasePlayer:
		FVector PlayerPos = UConstValue::MainCharacter->GetActorLocation();

		float XGap = PlayerPos.X - CameraPos.X;
		float YGap = PlayerPos.Y - CameraPos.Y;

		Camera->AddActorLocation(FVector(XGap, YGap, 0.f) * 1.5f * _DeltaTime);
		break;
	}
}

void CameraManager::XEndCheck()
{
	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	float CameraLeft = Camera->GetActorLocation().X - WindowScale.X / 2.f;
	float CameraRight = Camera->GetActorLocation().X + WindowScale.X / 2.f;

	FVector BackMapPos = UConstValue::BackMap->GetActorLocation();
	FVector BackMapScale = UConstValue::BackMap->GetActorScale3D();

	float BackMapLeft = BackMapPos.X - BackMapScale.X/2.f;
	float BackMapRight = BackMapPos.X + BackMapScale.X/2.f;

	
	if (CameraLeft < BackMapLeft)
	{
		Camera->AddActorLocation(FVector::Right);
	}

	if (CameraRight > BackMapRight)
	{
		Camera->AddActorLocation(FVector::Left);
	}


}

void CameraManager::YEndCheck()
{
	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	float CameraBottom = Camera->GetActorLocation().Y - WindowScale.Y / 2.f;
	float CameraTop = Camera->GetActorLocation().Y + WindowScale.Y / 2.f;

	FVector BackMapPos = UConstValue::BackMap->GetActorLocation();
	FVector BackMapScale = UConstValue::BackMap->GetActorScale3D();

	float BackMapBottom = BackMapPos.Y - BackMapScale.Y/2.f;
	float BackMapTop = BackMapPos.Y + BackMapScale.Y/2.f;

	if (CameraBottom < BackMapBottom)
	{
		Camera->AddActorLocation(FVector::Up);
	}

	if (CameraTop > BackMapTop)
	{
		Camera->AddActorLocation(FVector::Down);
	}
}
