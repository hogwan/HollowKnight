#include "PreCompile.h"
#include "Board.h"

ABoard::ABoard() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

ABoard::~ABoard() 
{
}

void ABoard::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(300.0f, 300.0f, 100.0f));

	Renderer->SetSprite("PC Computer - Puyo Puyo Tetris - Amite.png", 0);

	Renderer->CreateAnimation("Idle", "PC Computer - Puyo Puyo Tetris - Amite.png", 0.1f);

	Renderer->ChangeAnimation("Idle");
}

void ABoard::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

