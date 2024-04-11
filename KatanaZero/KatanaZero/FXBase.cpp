#include "PreCompile.h"
#include "FXBase.h"

FXBase::FXBase()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

FXBase::~FXBase()
{
}

void FXBase::BeginPlay()
{
	Super::BeginPlay();
}

void FXBase::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (Renderer->IsCurAnimationEnd())
	{
		Renderer->SetActive(false);
	}

}
