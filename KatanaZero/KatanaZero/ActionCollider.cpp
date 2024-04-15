#include "PreCompile.h"
#include "ActionCollider.h"

AActionCollider::AActionCollider()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	Collider = CreateDefaultSubObject<UCollision>("Collider");
	Collider->SetupAttachment(Root);

	SetRoot(Root);
}

AActionCollider::~AActionCollider()
{
}

void AActionCollider::BeginPlay()
{
	Super::BeginPlay();
}

void AActionCollider::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

