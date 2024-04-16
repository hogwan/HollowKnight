#include "PreCompile.h"
#include "Knife.h"

AKnife::AKnife() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Collider = CreateDefaultSubObject<UCollision>("Collider");

	Renderer->SetupAttachment(Root);
	Collider->SetupAttachment(Root);
}

AKnife::~AKnife() 
{
}

void AKnife::BeginPlay()
{
	Super::BeginPlay();

	CurItem = EItemType::Knife;
	SetActorScale3D(FVector(30.f, 30.f, 10.f));
	Renderer->SetSprite("Knife_0.png");
}

void AKnife::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

