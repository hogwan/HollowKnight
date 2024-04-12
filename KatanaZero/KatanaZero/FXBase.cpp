#include "PreCompile.h"
#include "FXBase.h"

AFXBase::AFXBase()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

AFXBase::~AFXBase()
{
}

void AFXBase::BeginPlay()
{
	Super::BeginPlay();
}

void AFXBase::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (Renderer->IsCurAnimationEnd())
	{
		Destroy();
	}

}
