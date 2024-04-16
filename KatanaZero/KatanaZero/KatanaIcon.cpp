#include "PreCompile.h"
#include "KatanaIcon.h"

AKatanaIcon::AKatanaIcon() 
{
}

AKatanaIcon::~AKatanaIcon() 
{
}

void AKatanaIcon::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("KatanaIcon.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::UIFront);
}

void AKatanaIcon::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
	CameraPos.Z = 300.f;
	SetActorLocation(CameraPos + FVector(530.f, 337.f, 0.f));
}

