#include "PreCompile.h"
#include "ContentsHelper.h"
#include "BloodFX.h"

ABloodFX::ABloodFX() 
{
}

ABloodFX::~ABloodFX() 
{
}

void ABloodFX::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("SplattedBlood", "splattedblood", 0.05f, false);

	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::FX);

	Renderer->ChangeAnimation("SplattedBlood");
}

void ABloodFX::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

