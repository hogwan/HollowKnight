#include "PreCompile.h"
#include "Smoke.h"

ASmoke::ASmoke() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Collider = CreateDefaultSubObject<UCollision>("Collider");

	Renderer->SetupAttachment(Root);
	Collider->SetupAttachment(Root);
}

ASmoke::~ASmoke() 
{
}

void ASmoke::BeginPlay()
{
	Super::BeginPlay();

	CurItem = ItemType::Smoke;
	SetActorScale3D(FVector(30.f, 30.f, 10.f));
	Renderer->SetSprite("Smoke_0.png");
}

void ASmoke::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

