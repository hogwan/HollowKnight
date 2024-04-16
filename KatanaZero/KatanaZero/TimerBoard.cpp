#include "PreCompile.h"
#include "TimerBoard.h"

ATimerBoard::ATimerBoard() 
{
}

ATimerBoard::~ATimerBoard() 
{
}

void ATimerBoard::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("TimerBorad.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::UI);
}

void ATimerBoard::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
	CameraPos.Z = 300.f;
	SetActorLocation(CameraPos + FVector(0.f, 337.f, 0.f));
}

