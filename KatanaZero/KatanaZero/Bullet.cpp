#include "PreCompile.h"
#include "Bullet.h"
#include <EngineCore/DefaultSceneComponent.h>

ABullet::ABullet()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Bullet");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

ABullet::~ABullet()
{
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("Bullet.png");
	Renderer->SetAutoSize(1.f, true);
	Renderer->SetOrder(ERenderOrder::Bullet);
}

void ABullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AddActorLocation(MoveVector * _DeltaTime);
}
