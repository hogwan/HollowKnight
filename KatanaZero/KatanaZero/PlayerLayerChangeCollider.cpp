#include "PreCompile.h"
#include "PlayerLayerChangeCollider.h"
#include <EngineCore/SpriteRenderer.h>

APlayerLayerChangeCollider::APlayerLayerChangeCollider() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

APlayerLayerChangeCollider::~APlayerLayerChangeCollider() 
{
}

void APlayerLayerChangeCollider::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(400.f, 5.f, 0.f));

	Collider->SetCollisionGroup(ECollisionOrder::PlayerLayerChange);
	Collider->SetCollisionType(ECollisionType::Rect);
}

void APlayerLayerChangeCollider::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

