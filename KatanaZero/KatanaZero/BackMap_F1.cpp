#include "PreCompile.h"
#include "BackMap_F1.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

ABackMap_F1::ABackMap_F1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	SetRoot(Root);
}

ABackMap_F1::~ABackMap_F1()
{
}

void ABackMap_F1::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("room_factory_1.png");

	Renderer->SetAutoSize(UConstValue::Ratio, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void ABackMap_F1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

