#include "PreCompile.h"
#include "PlayerJumpFX.h"

PlayerJumpFX::PlayerJumpFX() 
{
}

PlayerJumpFX::~PlayerJumpFX() 
{
}

void PlayerJumpFX::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("JumpFX","JumpFX",0.05f);
	Renderer->ChangeAnimation("JumpFX");

	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::FX);
}

void PlayerJumpFX::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

