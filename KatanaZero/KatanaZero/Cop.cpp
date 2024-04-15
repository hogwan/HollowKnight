#include "PreCompile.h"
#include "Cop.h"
#include "Bullet.h"

ACop::ACop()
{
	Arms = CreateDefaultSubObject<USpriteRenderer>("Arms");
	Arms->SetupAttachment(Root);
	Arms->SetPivot(EPivot::RIGHT);

	USpriteRenderer* Test = CreateDefaultSubObject<USpriteRenderer>("Test");
	Test->SetupAttachment(Root);
	Test->SetScale(FVector(36.f, 72.f, 100.f));
	Test->SetPosition(FVector(0.f, 36.f, 0.f));
}

ACop::~ACop()
{
}

void ACop::BeginPlay()
{
	Super::BeginPlay();
}

void ACop::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (CurDir == EActorDir::Left)
	{
		Arms->SetPosition(FVector(-50.f, 50.f, 0.f));
	}
	else
	{
		Arms->SetPosition(FVector(50.f, 50.f, 0.f));
	}

}

void ACop::StateInit()
{
	Super::StateInit();
}

void ACop::RendererInit()
{
	Super::RendererInit();
	Renderer->CreateAnimation("Idle", "cop_idle", 0.05f, true);
	Renderer->CreateAnimation("Walk", "cop_walk", 0.05f, true);
	Renderer->CreateAnimation("Run", "cop_run", 0.05f, true);
	Renderer->CreateAnimation("Turn", "cop_turn", 0.05f, false);
	Renderer->CreateAnimation("Attack", "cop_attack", 0.05f, false);
	Renderer->CreateAnimation("Death", "cop_hurtground", 0.05f, false);
	Renderer->CreateAnimation("DeathInAir", "cop_hurtfly", 0.05f, false);
	Renderer->CreateAnimation("ChangeLayerLevel", "cop_turn", 0.05f, false);

	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::Enemy);

	Arms->SetSprite("Cop_AimArms.png");
	Arms->SetActive(false);
	Arms->SetAutoSize(2.f, true);
	Arms->SetOrder(ERenderOrder::EnemyArms);

	Collider->SetScale(FVector(36.f, 72.f, 100.f));
	Collider->SetPosition(FVector(0.f, 36.f, 0.f));
}

void ACop::None(float _DeltaTime)
{
	Super::None(_DeltaTime);
}

void ACop::Idle(float _DeltaTime)
{
	Super::Idle(_DeltaTime);
}

void ACop::Walk(float _DeltaTime)
{
	Super::Walk(_DeltaTime);
}

void ACop::Run(float _DeltaTime)
{
	Super::Run(_DeltaTime);

	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	FVector Gap = PlayerPos - GetActorLocation();

	if (abs(Gap.X) < Range
		&& abs(PlayerPos.Y - GetActorLocation().Y) < 100.f)
	{
		State.ChangeState("Attack");
		return;
	}
}

void ACop::Turn(float _DeltaTime)
{
	Super::Turn(_DeltaTime);
}

void ACop::Attack(float _DeltaTime)
{
	Super::Attack(_DeltaTime);

	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	PlayerPos.Y += 40.f;
	PlayerPos.Z = 0.f;

	FVector CopPos = GetActorLocation();
	CopPos.Y += 50.f;
	CopPos.Z = 0.f;

	FVector AimVector = PlayerPos - CopPos;
	AimVector.Normalize3D();

	if (AimVector.X > 0.f)
	{
		CurDir = EActorDir::Right;
	}
	else
	{
		CurDir = EActorDir::Left;
	}

	Arms->SetRotationDeg(FVector({ 0.f,0.f,AimVector.Y * 90.f }));

	AccAim += _DeltaTime;
	if (AccAim > AimTime)
	{
		std::shared_ptr<ABullet> Bullet = GetWorld()->SpawnActor<ABullet>("Bullet");
		Bullet->SetActorLocation(CopPos + AimVector * 50.f);
		Bullet->SetDir(AimVector);
		Bullet->SetActorRotation(FVector({ 0.f,0.f,AimVector.Y * 90.f }));
		AccAim = 0.f;
		State.ChangeState("Idle");
	}
}

void ACop::Death(float _DeltaTime)
{
	Super::Death(_DeltaTime);
}

void ACop::DeathInAir(float _DeltaTime)
{
	Super::DeathInAir(_DeltaTime);
}

void ACop::ChangeLayerLevel(float _DeltaTime)
{
	Super::ChangeLayerLevel(_DeltaTime);
}

void ACop::NoneStart()
{
	Super::NoneStart();
}

void ACop::IdleStart()
{
	Super::IdleStart();
}

void ACop::WalkStart()
{
	Super::WalkStart();
}

void ACop::RunStart()
{
	Super::RunStart();
}

void ACop::TurnStart()
{
	Super::TurnStart();
}

void ACop::AttackStart()
{
	Super::AttackStart();
	Arms->SetActive(true);
}

void ACop::DeathStart()
{
	Super::DeathStart();
}

void ACop::DeathInAirStart()
{
	Super::DeathInAirStart();
}

void ACop::ChangeLayerLevelStart()
{
	Super::ChangeLayerLevelStart();
}

void ACop::AttackEnd()
{
	Super::AttackEnd();
	Arms->SetActive(false);
}
