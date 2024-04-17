#include "PreCompile.h"
#include "FanFront.h"

AFanFront::AFanFront() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

AFanFront::~AFanFront() 
{
}

void AFanFront::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetSprite("spr_fan_fg_0.png");
	Renderer->SetOrder(ERenderOrder::ObjectFront);
}

void AFanFront::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

