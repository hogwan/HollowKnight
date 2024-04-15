#include "PreCompile.h"
#include "Pomp.h"
#include "PompSlashFX.h"

APomp::APomp()
{
	USpriteRenderer* Test = CreateDefaultSubObject<USpriteRenderer>("Test");
	Test->SetupAttachment(Root);
	Test->SetScale(FVector(36.f, 72.f, 100.f));
	Test->SetPosition(FVector(0.f, 36.f, 0.f));
}

APomp::~APomp()
{
}

void APomp::BeginPlay()
{
	Super::BeginPlay();
}

void APomp::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void APomp::StateInit()
{
	Super::StateInit();

	State.CreateState("Stun");

	State.SetUpdateFunction("Stun", std::bind(&APomp::Stun, this, std::placeholders::_1));
	State.SetStartFunction("Stun", std::bind(&APomp::StunStart, this));
}

void APomp::RendererInit()
{
	Super::RendererInit();
	Renderer->CreateAnimation("Idle", "pomp_idle", 0.05f, true);
	Renderer->CreateAnimation("Walk", "pomp_walk", 0.05f, true);
	Renderer->CreateAnimation("Run", "pomp_run", 0.05f, true);
	Renderer->CreateAnimation("Turn", "pomp_turn", 0.05f, false);
	Renderer->CreateAnimation("Attack", "pomp_attack", 0.05f, false);
	Renderer->CreateAnimation("Death", "pomp_hurtground", 0.05f, false);
	Renderer->CreateAnimation("DeathInAir", "pomp_hurtfly", 0.05f, false);
	Renderer->CreateAnimation("Stun", "pomp_knockdown", 0.05f, false);

	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::Enemy);

	Collider->SetScale(FVector(36.f, 72.f, 100.f));
	Collider->SetPosition(FVector(0.f, 36.f, 0.f));
}

void APomp::None(float _DeltaTime)
{
	Super::None(_DeltaTime);
}

void APomp::Idle(float _DeltaTime)
{
	Super::Idle(_DeltaTime);
}

void APomp::Walk(float _DeltaTime)
{
	Super::Walk(_DeltaTime);
}

void APomp::Run(float _DeltaTime)
{
	Super::Run(_DeltaTime);
	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	if (abs(PlayerPos.X - GetActorLocation().X) < 100.f
		&& abs(PlayerPos.Y - GetActorLocation().Y) < 100.f)
	{
		State.ChangeState("Attack");
		return;
	}
}

void APomp::Turn(float _DeltaTime)
{
	Super::Turn(_DeltaTime);
}

void APomp::Attack(float _DeltaTime)
{
	Super::Attack(_DeltaTime);
	if (Renderer->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}
}

void APomp::Death(float _DeltaTime)
{
	Super::Death(_DeltaTime);
}

void APomp::DeathInAir(float _DeltaTime)
{
	Super::DeathInAir(_DeltaTime);
}

void APomp::ChangeLayerLevel(float _DeltaTime)
{
	Super::ChangeLayerLevel(_DeltaTime);
}

void APomp::NoneStart()
{
	Super::NoneStart();
}

void APomp::IdleStart()
{
	Super::IdleStart();
}

void APomp::WalkStart()
{
	Super::WalkStart();
}

void APomp::RunStart()
{
	Super::RunStart();
}

void APomp::TurnStart()
{
	Super::TurnStart();
}

void APomp::AttackStart()
{
	Super::AttackStart();
	std::shared_ptr<APompSlashFX> PompSlashFX = GetWorld()->SpawnActor<APompSlashFX>("PompSlashFX");
	if (CurDir == EActorDir::Left)
	{
		PompSlashFX->SetActorLocation(GetActorLocation() + FVector(-30.f,50.f,0.f));
		PompSlashFX->ReverseX();
	}
	else
	{
		PompSlashFX->SetActorLocation(GetActorLocation() + FVector(30.f, 50.f, 0.f));
	}

}

void APomp::DeathStart()
{
	Super::DeathStart();
}

void APomp::DeathInAirStart()
{
	Super::DeathInAirStart();
}

void APomp::ChangeLayerLevelStart()
{
	Super::ChangeLayerLevelStart();
}

void APomp::Stun(float _DeltaTime)
{
	if (Renderer->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
	}
}

void APomp::StunStart()
{
	Renderer->ChangeAnimation("Stun");
}
