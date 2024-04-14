#include "PreCompile.h"
#include "PompSlashFX.h"
#include "Player.h"

APompSlashFX::APompSlashFX()
{

}

APompSlashFX::~APompSlashFX()
{
}

void APompSlashFX::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("Slash", "PompSlashFX", 0.05f);
	Renderer->ChangeAnimation("Slash");


	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::FX);
	Dir = UConstValue::Player->GetAttackDir();


	if (Dir.X < 0.f)
	{
		SetActorRotation(FVector(0.f, 0.f, -Dir.Y * 90.f));
	}
	else
	{
		SetActorRotation(FVector(0.f, 0.f, Dir.Y * 90.f));
	}

}

void APompSlashFX::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector PlayerPos = UConstValue::Player->GetActorLocation();

	SetActorLocation(PlayerPos + FVector(0.f, 20.f, 0.f) + Dir * 50.f);

	if (Dir.X < 0.f)
	{
		FVector Scale = GetActorScale3D();
		SetActorScale3D(FVector(-Scale.X, Scale.Y, Scale.Z));
	}
}

