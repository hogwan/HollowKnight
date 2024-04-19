#include "PreCompile.h"
#include "Gangster.h"
#include "Bullet.h"

AGangster::AGangster()
{
	Arms = CreateDefaultSubObject<USpriteRenderer>("Arms");
	Arms->SetupAttachment(Root);
	Arms->SetPivot(EPivot::RIGHT);

	USpriteRenderer* Test = CreateDefaultSubObject<USpriteRenderer>("Test");
	Test->SetupAttachment(Root);
	Test->SetScale(FVector(36.f, 72.f, 100.f));
	Test->SetPosition(FVector(0.f, 36.f, 0.f));
}

AGangster::~AGangster()
{
}

void AGangster::BeginPlay()
{
	Super::BeginPlay();
}

void AGangster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (CurDir == EEngineDir::Left)
	{
		Arms->SetPosition(FVector(-50.f, 50.f, 0.f));
	}
	else
	{
		Arms->SetPosition(FVector(50.f, 50.f, 0.f));
	}

}

void AGangster::StateInit()
{
	Super::StateInit();
}

void AGangster::RendererInit()
{
	Super::RendererInit();
	Renderer->CreateAnimation("Idle", "gangster_idle", 0.05f, true);
	Renderer->CreateAnimation("Walk", "gangster_walk", 0.05f, true);
	Renderer->CreateAnimation("Run", "gangster_run", 0.05f, true);
	Renderer->CreateAnimation("Turn", "gangster_turn", 0.05f, false);
	Renderer->CreateAnimation("Attack", "Gangster_Attack", 0.05f, false);
	Renderer->CreateAnimation("Death", "gangster_Death", 0.05f, false);
	Renderer->CreateAnimation("DeathInAir", "gangster_DeathInAir", 0.05f, false);
	Renderer->CreateAnimation("ChangeLayerLevel", "gangster_turn", 0.05f, false);

	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::Enemy);

	Arms->SetSprite("spr_gangstergun.png");
	Arms->SetActive(false);
	Arms->SetAutoSize(2.f, true);
	Arms->SetOrder(ERenderOrder::EnemyArms);

	Collider->SetScale(FVector(36.f, 72.f, 100.f));
	Collider->SetPosition(FVector(0.f, 36.f, 0.f));
}

void AGangster::None(float _DeltaTime)
{
	Super::None(_DeltaTime);
}

void AGangster::Idle(float _DeltaTime)
{
	Super::Idle(_DeltaTime);
}

void AGangster::Walk(float _DeltaTime)
{
	Super::Walk(_DeltaTime);
}

void AGangster::Run(float _DeltaTime)
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

void AGangster::Turn(float _DeltaTime)
{
	Super::Turn(_DeltaTime);
}

void AGangster::Attack(float _DeltaTime)
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
		CurDir = EEngineDir::Right;
	}
	else
	{
		CurDir = EEngineDir::Left;
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

void AGangster::Death(float _DeltaTime)
{
	Super::Death(_DeltaTime);
}

void AGangster::DeathInAir(float _DeltaTime)
{
	Super::DeathInAir(_DeltaTime);
}

void AGangster::ChangeLayerLevel(float _DeltaTime)
{
	Super::ChangeLayerLevel(_DeltaTime);
}

void AGangster::NoneStart()
{
	Super::NoneStart();
}

void AGangster::IdleStart()
{
	Super::IdleStart();
}

void AGangster::WalkStart()
{
	Super::WalkStart();
}

void AGangster::RunStart()
{
	Super::RunStart();
}

void AGangster::TurnStart()
{
	Super::TurnStart();
}

void AGangster::AttackStart()
{
	Super::AttackStart();
	Arms->SetActive(true);
}

void AGangster::DeathStart()
{
	Super::DeathStart();
}

void AGangster::DeathInAirStart()
{
	Super::DeathInAirStart();
}

void AGangster::ChangeLayerLevelStart()
{
	Super::ChangeLayerLevelStart();
}

void AGangster::AttackEnd()
{
	Super::AttackEnd();
	Arms->SetActive(false);
}
