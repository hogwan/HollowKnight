#include "PreCompile.h"
#include "Enemy.h"

AEnemy::AEnemy() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	SetRoot(Root);
}

AEnemy::~AEnemy() 
{
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

