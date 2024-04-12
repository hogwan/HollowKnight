#include "PreCompile.h"
#include "Grunt.h"

AGrunt::AGrunt() 
{

}

AGrunt::~AGrunt() 
{
}

void AGrunt::BeginPlay()
{
	Super::BeginPlay();
	StateInit();
	RendererInit();
}

void AGrunt::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AGrunt::StateInit()
{
	State.CreateState("None");
	State.CreateState("Idle");
	State.CreateState("Walk");
	State.CreateState("Run");
	State.CreateState("Turn");
	State.CreateState("Attack");
	State.CreateState("Death");
	State.CreateState("DeathInAir");

	State.SetUpdateFunction("None", std::bind(&AGrunt::None, this, std::placeholders::_1));
	State.SetStartFunction("None", std::bind(&AGrunt::NoneStart, this));

	State.SetUpdateFunction("Idle", std::bind(&AGrunt::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Idle", std::bind(&AGrunt::IdleStart, this));

	State.SetUpdateFunction("Walk", std::bind(&AGrunt::Walk, this, std::placeholders::_1));
	State.SetStartFunction("Walk", std::bind(&AGrunt::WalkStart, this));

	State.SetUpdateFunction("Run", std::bind(&AGrunt::Run, this, std::placeholders::_1));
	State.SetStartFunction("Run", std::bind(&AGrunt::RunStart, this));

	State.SetUpdateFunction("Turn", std::bind(&AGrunt::Turn, this, std::placeholders::_1));
	State.SetStartFunction("Turn", std::bind(&AGrunt::TurnStart, this));

	State.SetUpdateFunction("Attack", std::bind(&AGrunt::Attack, this, std::placeholders::_1));
	State.SetStartFunction("Attack", std::bind(&AGrunt::AttackStart, this));

	State.SetUpdateFunction("Death", std::bind(&AGrunt::Death, this, std::placeholders::_1));
	State.SetStartFunction("Death", std::bind(&AGrunt::DeathStart, this));

	State.SetUpdateFunction("DeathInAir", std::bind(&AGrunt::DeathInAir, this, std::placeholders::_1));
	State.SetStartFunction("DeathInAir", std::bind(&AGrunt::DeathInAirStart, this));

	State.ChangeState("None");
}

void AGrunt::RendererInit()
{
	State.CreateState("None");
	State.CreateState("Idle");
	State.CreateState("Walk");
	State.CreateState("Run");
	State.CreateState("Turn");
	State.CreateState("Attack");
	State.CreateState("Death");
	State.CreateState("DeathInAir");

	Renderer->CreateAnimation("Idle", "Grunt_Idle", 0.05f, true);
	Renderer->CreateAnimation("Walk", "Grunt_Walk", 0.05f, true);
	Renderer->CreateAnimation("Run", "Grunt_Run", 0.05f, false);
	Renderer->CreateAnimation("Turn", "Grunt_Turn", 0.08f, false);
	Renderer->CreateAnimation("Attack", "Grunt_Attack", 0.05f, false);
	Renderer->CreateAnimation("Death", "grunt_hurtground", 0.05f, true);
	Renderer->CreateAnimation("DeathInAir", "grunt_hurtfly", 0.05f, true);

	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::Enemy);
}

void AGrunt::None(float _DeltaTime)
{
	State.ChangeState("Idle");
	return;
}

void AGrunt::Idle(float _DeltaTime)
{
	FVector PlayerPos = UConstValue::Player->GetActorLocation();

}

void AGrunt::Walk(float _DeltaTime)
{
}

void AGrunt::Run(float _DeltaTime)
{
}

void AGrunt::Turn(float _DeltaTime)
{
}

void AGrunt::Attack(float _DeltaTime)
{
}

void AGrunt::Death(float _DeltaTime)
{
}

void AGrunt::DeathInAir(float _DeltaTime)
{
}

void AGrunt::NoneStart()
{
}

void AGrunt::IdleStart()
{
}

void AGrunt::WalkStart()
{
}

void AGrunt::RunStart()
{
}

void AGrunt::TurnStart()
{
}

void AGrunt::AttackStart()
{
}

void AGrunt::DeathStart()
{
}

void AGrunt::DeathInAirStart()
{
}
