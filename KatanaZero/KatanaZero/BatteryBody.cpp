#include "PreCompile.h"
#include "BatteryBody.h"

ABatteryBody::ABatteryBody() 
{
}

ABatteryBody::~ABatteryBody() 
{
}

void ABatteryBody::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("BatteryBody.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::UI);
}

void ABatteryBody::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
	CameraPos.Z = 300.f;
	SetActorLocation(CameraPos + FVector(-500.f, 337.f, 0.f));
}

