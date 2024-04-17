#include "PreCompile.h"
#include "BackMap_F3.h"

ABackMap_F3::ABackMap_F3() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	SetRoot(Root);
}

ABackMap_F3::~ABackMap_F3() 
{
}

void ABackMap_F3::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("room_factory_4.png");

	Renderer->SetAutoSize(UConstValue::Ratio, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void ABackMap_F3::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

