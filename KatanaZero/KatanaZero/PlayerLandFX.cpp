#include "PreCompile.h"
#include "PlayerLandFX.h"

PlayerLandFX::PlayerLandFX() 
{
}

PlayerLandFX::~PlayerLandFX() 
{
}

void PlayerLandFX::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("LandFX", "LandFX", 0.05f);
	Renderer->ChangeAnimation("LandFX");

	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::FX);
}

void PlayerLandFX::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

