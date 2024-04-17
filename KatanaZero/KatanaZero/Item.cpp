#include "PreCompile.h"
#include "Item.h"

AItem::AItem() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	SetRoot(Root);
}

AItem::~AItem() 
{
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	Collider->SetCollisionGroup(ECollisionOrder::Item);
	Collider->SetCollisionType(ECollisionType::Rect);
}

void AItem::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AddActorLocation(MoveVector * _DeltaTime);
}

