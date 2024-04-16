#include "PreCompile.h"
#include "FireBottle.h"

AFireBottle::AFireBottle() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Collider = CreateDefaultSubObject<UCollision>("Collider");

	Renderer->SetupAttachment(Root);
	Collider->SetupAttachment(Root);
}

AFireBottle::~AFireBottle() 
{
}

void AFireBottle::BeginPlay()
{
	Super::BeginPlay();

	CurItem = EItemType::FireBottle;
	SetActorScale3D(FVector(30.f, 30.f, 10.f));
	Renderer->SetSprite("FireBottle_0.png");
}

void AFireBottle::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

