#include "PreCompile.h"
#include "Grunt.h"
#include "GruntSlashFX.h"

AGrunt::AGrunt() 
{
	USpriteRenderer* Test = CreateDefaultSubObject<USpriteRenderer>("Test");
	Test->SetupAttachment(Root);
	Test->SetScale(FVector(36.f, 72.f, 100.f));
	Test->SetPosition(FVector(0.f, 36.f, 0.f));
}

AGrunt::~AGrunt() 
{
}

void AGrunt::BeginPlay()
{
	Super::BeginPlay();
}

void AGrunt::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AGrunt::StateInit()
{
	Super::StateInit();
}

void AGrunt::RendererInit()
{
	Super::RendererInit();
	Renderer->CreateAnimation("Idle", "grunt_idle", 0.05f, true);
	Renderer->CreateAnimation("Walk", "grunt_walk", 0.05f, true);
	Renderer->CreateAnimation("Run", "Grunt_Run", 0.05f, true);
	Renderer->CreateAnimation("Turn", "Grunt_Turn", 0.05f, false);
	Renderer->CreateAnimation("Attack", "Grunt_Attack", 0.05f, false);
	Renderer->CreateAnimation("Death", "grunt_hurtground", 0.05f, false);
	Renderer->CreateAnimation("DeathInAir", "grunt_hurtfly", 0.05f, false);

	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::Enemy);
	
	Collider->SetScale(FVector(36.f, 72.f, 100.f));
	Collider->SetPosition(FVector(0.f, 36.f, 0.f));

}

void AGrunt::None(float _DeltaTime)
{
	Super::None(_DeltaTime);
}

void AGrunt::Idle(float _DeltaTime)
{
	Super::Idle(_DeltaTime);
}

void AGrunt::Walk(float _DeltaTime)
{
	Super::Walk(_DeltaTime);
}

void AGrunt::Run(float _DeltaTime)
{
	Super::Run(_DeltaTime);
	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	if (abs(PlayerPos.X - GetActorLocation().X) < 100.f
		&& abs(PlayerPos.Y - GetActorLocation().Y) <100.f)
	{
		State.ChangeState("Attack");
		return;
	}

}

void AGrunt::Turn(float _DeltaTime)
{
	Super::Turn(_DeltaTime);
}

void AGrunt::Attack(float _DeltaTime)
{
	Super::Attack(_DeltaTime);
	if (Renderer->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}
}

void AGrunt::Death(float _DeltaTime)
{
	Super::Death(_DeltaTime);
}

void AGrunt::DeathInAir(float _DeltaTime)
{
	Super::DeathInAir(_DeltaTime);
}

void AGrunt::ChangeLayerLevel(float _DeltaTime)
{
	Super::ChangeLayerLevel(_DeltaTime);
}

void AGrunt::NoneStart()
{
	Super::NoneStart();
}

void AGrunt::IdleStart()
{
	Super::IdleStart();
}

void AGrunt::WalkStart()
{
	Super::WalkStart();
}

void AGrunt::RunStart()
{
	Super::RunStart();
}

void AGrunt::TurnStart()
{
	Super::TurnStart();
}

void AGrunt::AttackStart()
{
	Super::AttackStart();
	std::shared_ptr<AGruntSlashFX> GruntSlashFX = GetWorld()->SpawnActor<AGruntSlashFX>("PompSlashFX");
	if (CurDir == EActorDir::Left)
	{
		GruntSlashFX->SetActorLocation(GetActorLocation() + FVector(-30.f, 50.f, 0.f));
		GruntSlashFX->ReverseX();
	}
	else
	{
		GruntSlashFX->SetActorLocation(GetActorLocation() + FVector(30.f, 50.f, 0.f));
	}
}

void AGrunt::DeathStart()
{
	Super::DeathStart();
}

void AGrunt::DeathInAirStart()
{
	Super::DeathInAirStart();
}

void AGrunt::ChangeLayerLevelStart()
{
	Super::ChangeLayerLevelStart();
}



