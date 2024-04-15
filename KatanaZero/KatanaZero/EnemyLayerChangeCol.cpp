#include "PreCompile.h"
#include "EnemyLayerChangeCol.h"

AEnemyLayerChangeCol::AEnemyLayerChangeCol() 
{
	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

AEnemyLayerChangeCol::~AEnemyLayerChangeCol() 
{
}

void AEnemyLayerChangeCol::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(10.f, 10.f, 0.f));
	Collider->SetCollisionGroup(ECollisionOrder::EnemyLayerChange);
	Collider->SetCollisionType(ECollisionType::Rect);
}

void AEnemyLayerChangeCol::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

