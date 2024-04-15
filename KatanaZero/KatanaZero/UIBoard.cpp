#include "PreCompile.h"
#include "UIBoard.h"

AUIBoard::AUIBoard() 
{
}

AUIBoard::~AUIBoard() 
{
}

void AUIBoard::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("UIBorad.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::UIBoard);
}

void AUIBoard::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
	CameraPos.Z = 300.f;
	SetActorLocation(CameraPos + FVector(0.f, 337.f, 0.f));
}

