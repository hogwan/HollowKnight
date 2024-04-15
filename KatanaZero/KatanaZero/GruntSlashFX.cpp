#include "PreCompile.h"
#include "GruntSlashFX.h"

AGruntSlashFX::AGruntSlashFX()
{

}

AGruntSlashFX::~AGruntSlashFX()
{
}

void AGruntSlashFX::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("Slash", "GruntSlashFX", 0.05f);
	Renderer->ChangeAnimation("Slash");


	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::FX);

}

void AGruntSlashFX::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
