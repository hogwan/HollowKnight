#include "PreCompile.h"
#include "PlayerDustFX.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include "Player.h"

PlayerDustFX::PlayerDustFX() 
{
}

PlayerDustFX::~PlayerDustFX() 
{
}

void PlayerDustFX::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("RunFX", "RunFX", 0.05f);
	Renderer->ChangeAnimation("RunFX");

	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::FX);

	if (UConstValue::Player->GetCurDir() == EEngineDir::Right)
	{
		Reverse = true;
		MoveVector.X = -5.f;
	}
	else
	{
		MoveVector.X = 5.f;
	}

	MoveVector.Y = UEngineRandom::MainRandom.RandomFloat(-3.f, 3.f);
	MoveVector.Z = 0.f;
}

void PlayerDustFX::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	if (Reverse)
	{
		FVector Scale = GetActorScale3D();
		Scale.X = -Scale.X;
		SetActorScale3D(Scale);
	}

	MoveVector.Normalize3D();
	AddActorLocation(MoveVector * Speed * _DeltaTime);
}

