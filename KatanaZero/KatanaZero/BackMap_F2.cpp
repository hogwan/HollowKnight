#include "PreCompile.h"
#include "BackMap_F2.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

ABackMap_F2::ABackMap_F2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	SetRoot(Root);
}

ABackMap_F2::~ABackMap_F2()
{
}

void ABackMap_F2::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("room_factory_3.png");

	Renderer->SetAutoSize(UConstValue::Ratio, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void ABackMap_F2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

