#include "PreCompile.h"
#include "BackGroundMap.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include "EnumHelper.h"

BackGroundMap::BackGroundMap() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

BackGroundMap::~BackGroundMap() 
{
}

void BackGroundMap::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("room_factory_4_colmap.png");

	Renderer->SetAutoSize(1.f, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void BackGroundMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

