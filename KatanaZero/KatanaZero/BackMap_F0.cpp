#include "PreCompile.h"
#include "BackMap_F0.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

BackMap_F0::BackMap_F0() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	SetRoot(Root);
}

BackMap_F0::~BackMap_F0() 
{
}

void BackMap_F0::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("room_factory_0.png");

	Renderer->SetAutoSize(UConstValue::Ratio, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void BackMap_F0::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

