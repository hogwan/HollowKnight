#include "PreCompile.h"
#include "MapObject.h"

MapObject::MapObject() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

MapObject::~MapObject() 
{
}

void MapObject::BeginPlay()
{
	Super::BeginPlay();
}

void MapObject::Tick(float _DeltaTime)
{
}

