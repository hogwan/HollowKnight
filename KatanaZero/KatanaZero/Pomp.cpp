#include "PreCompile.h"
#include "Pomp.h"

APomp::APomp()
{
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
}

void APomp::Turn(float _DeltaTime)
{
	Super::Turn(_DeltaTime);
}

void APomp::Attack(float _DeltaTime)
{
	Super::Attack(_DeltaTime);
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
