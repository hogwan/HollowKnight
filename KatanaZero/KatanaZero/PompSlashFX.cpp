#include "PreCompile.h"
#include "PompSlashFX.h"
#include "Player.h"

APompSlashFX::APompSlashFX()
{

}

APompSlashFX::~APompSlashFX()
{
}

void APompSlashFX::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("Slash", "PompSlashFX", 0.05f);
	Renderer->ChangeAnimation("Slash");


	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::FX);


}

void APompSlashFX::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

