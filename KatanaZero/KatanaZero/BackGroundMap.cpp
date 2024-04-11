#include "PreCompile.h"
#include "BackGroundMap.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsHelper.h"

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

	Renderer->SetSprite("room_factory_2.png");

	Renderer->SetAutoSize(UConstValue::Ratio, true);
	Renderer->SetOrder(ERenderOrder::Back);

}

void BackGroundMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

