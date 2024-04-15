#include "PreCompile.h"
#include "UIBase.h"

AUIBase::AUIBase() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

AUIBase::~AUIBase() 
{
}

void AUIBase::BeginPlay()
{
	Super::BeginPlay();
}

void AUIBase::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

