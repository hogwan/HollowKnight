#include "PreCompile.h"
#include "CameraManager.h"
#include "ContentsHelper.h"
#include "Player.h"
#include "BackGroundMap.h"
#include <EngineCore/Camera.h>

ACameraManager::ACameraManager()
{
}

ACameraManager::~ACameraManager()
{
}

void ACameraManager::BeginPlay()
{
	Super::BeginPlay();

	Camera = GetWorld()->GetMainCamera();
}

void ACameraManager::Tick(float _DeltaTime)
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
		FVector PlayerPos = UConstValue::Player->GetActorLocation();

		float XGap = 0.f;
		float YGap = 0.f;

		XGap = PlayerPos.X - CameraPos.X;
		YGap = PlayerPos.Y - CameraPos.Y;

		Camera->AddActorLocation(FVector(XGap, YGap, 0.f) * 1.5f * _DeltaTime);
		break;
	}
}

bool ACameraManager::XEndCheck()
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
		Camera->SetActorLocation({ BackMapLeft + WindowScale.hX(),Camera->GetActorLocation().Y, Camera->GetActorLocation().Z });
		return false;
	}

	if (CameraRight > BackMapRight)
	{
		Camera->SetActorLocation({ BackMapRight - WindowScale.hX(),Camera->GetActorLocation().Y, Camera->GetActorLocation().Z });
		return false;
	}

	return true;


}

bool ACameraManager::YEndCheck()
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
		Camera->SetActorLocation({ Camera->GetActorLocation().X,BackMapBottom + WindowScale.hY(), Camera->GetActorLocation().Z});
		return false;
	}

	if (CameraTop > BackMapTop)
	{
		Camera->SetActorLocation({ Camera->GetActorLocation().X,BackMapTop - WindowScale.hY(), Camera->GetActorLocation().Z });
		return false;
	}

	return true;
}
