#include "PreCompile.h"
#include "Bottle.h"

ABottle::ABottle() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Collider = CreateDefaultSubObject<UCollision>("Collider");

	Renderer->SetupAttachment(Root);
	Collider->SetupAttachment(Root);
}

ABottle::~ABottle() 
{
}

void ABottle::BeginPlay()
{
	Super::BeginPlay();

	CurItem = EItemType::Bottle;
	SetActorScale3D(FVector(30.f, 30.f, 10.f));
	Renderer->SetSprite("Bottle.png");
}

void ABottle::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

