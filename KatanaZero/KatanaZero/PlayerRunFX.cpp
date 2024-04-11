#include "PreCompile.h"
#include "PlayerRunFX.h"
#include <EngineCore/SpriteRenderer.h>
#include "Player.h"

PlayerRunFX::PlayerRunFX() 
{
}

PlayerRunFX::~PlayerRunFX() 
{
}

void PlayerRunFX::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("RunFX", "RunFX", 0.05f);
	Renderer->ChangeAnimation("RunFX");

	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::FX);

	if (UConstValue::MainCharacter->GetCurDir() == EActorDir::Right)
	{
		Reverse = true;
	}
}

void PlayerRunFX::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	if (Reverse)
	{
		FVector Scale = GetActorScale3D();
		Scale.X = -Scale.X;
		SetActorScale3D(Scale);
	}
}

