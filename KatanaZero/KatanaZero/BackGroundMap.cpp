#include "PreCompile.h"
#include "BackGroundMap.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsHelper.h"

ABackGroundMap::ABackGroundMap() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	SetRoot(Root);
	InputOn();
}

ABackGroundMap::~ABackGroundMap() 
{
}

void ABackGroundMap::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("TestColMap.png");

	Renderer->SetAutoSize(UConstValue::Ratio, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void ABackGroundMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

