#include "PreCompile.h"
#include "Enemy.h"

AEnemy::AEnemy() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	SetRoot(Root);
}

AEnemy::~AEnemy() 
{
}


void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	StateInit();
	RendererInit();
}

void AEnemy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DirUpdate();

	GravityCheck(_DeltaTime);

	State.Update(_DeltaTime);

	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	if (abs(PlayerPos.X - GetActorLocation().X) < 500.f)
	{
		CurPattern = EEnemyPattern::ChasePlayer;
	}

	AddActorLocation(MoveVector * _DeltaTime);

}

void AEnemy::StateInit()
{
	State.CreateState("None");
	State.CreateState("Idle");
	State.CreateState("Walk");
	State.CreateState("Run");
	State.CreateState("Turn");
	State.CreateState("Attack");
	State.CreateState("Death");
	State.CreateState("DeathInAir");
	State.CreateState("ChangeLayerLevel");

	State.SetUpdateFunction("None", std::bind(&AEnemy::None, this, std::placeholders::_1));
	State.SetStartFunction("None", std::bind(&AEnemy::NoneStart, this));

	State.SetUpdateFunction("Idle", std::bind(&AEnemy::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Idle", std::bind(&AEnemy::IdleStart, this));

	State.SetUpdateFunction("Walk", std::bind(&AEnemy::Walk, this, std::placeholders::_1));
	State.SetStartFunction("Walk", std::bind(&AEnemy::WalkStart, this));

	State.SetUpdateFunction("Run", std::bind(&AEnemy::Run, this, std::placeholders::_1));
	State.SetStartFunction("Run", std::bind(&AEnemy::RunStart, this));

	State.SetUpdateFunction("Turn", std::bind(&AEnemy::Turn, this, std::placeholders::_1));
	State.SetStartFunction("Turn", std::bind(&AEnemy::TurnStart, this));

	State.SetUpdateFunction("Attack", std::bind(&AEnemy::Attack, this, std::placeholders::_1));
	State.SetStartFunction("Attack", std::bind(&AEnemy::AttackStart, this));
	State.SetEndFunction("Attack", std::bind(&AEnemy::AttackEnd, this));

	State.SetUpdateFunction("Death", std::bind(&AEnemy::Death, this, std::placeholders::_1));
	State.SetStartFunction("Death", std::bind(&AEnemy::DeathStart, this));

	State.SetUpdateFunction("DeathInAir", std::bind(&AEnemy::DeathInAir, this, std::placeholders::_1));
	State.SetStartFunction("DeathInAir", std::bind(&AEnemy::DeathInAirStart, this));

	State.SetUpdateFunction("ChangeLayerLevel", std::bind(&AEnemy::ChangeLayerLevel, this, std::placeholders::_1));
	State.SetStartFunction("ChangeLayerLevel", std::bind(&AEnemy::ChangeLayerLevelStart, this));

	State.ChangeState("None");
}

void AEnemy::RendererInit()
{
	
}

void AEnemy::None(float _DeltaTime)
{
	State.ChangeState("Idle");
	return;
}

void AEnemy::Idle(float _DeltaTime)
{
	if (CurPattern == EEnemyPattern::Patrol)
	{
		AccTime += _DeltaTime;
		if (AccTime > IdleTime)
		{
			AccTime = 0.f;
			State.ChangeState("Turn");
			return;
		}
	}
	else if (CurPattern == EEnemyPattern::ChasePlayer)
	{
		AccTime = 0.f;
		State.ChangeState("Run");
		return;
	}
}

void AEnemy::Walk(float _DeltaTime)
{
	if (CurPattern == EEnemyPattern::Patrol)
	{
		AccTime += _DeltaTime;
		if (AccTime > WalkTime)
		{
			AccTime = 0.f;
			State.ChangeState("Idle");
			return;
		}
		if (CurDir == EActorDir::Left)
		{

			FVector Dir = FVector::Zero;
			if (OnLeftUpStep)
			{
				Dir = { -1.f,1.f,0.f };
			}
			else if (OnRightUpStep)
			{
				Dir = { -1.f,-1.f,0.f };
			}
			else
			{
				Dir = { -1.f,0.f,0.f };
			}
			Dir.Normalize3D();

			MoveVector = Dir * WalkSpeed;
		}
		else if (CurDir == EActorDir::Right)
		{

			FVector Dir = FVector::Zero;
			if (OnLeftUpStep)
			{
				Dir = { 1.f,-1.f,0.f };
			}
			else if (OnRightUpStep)
			{
				Dir = { 1.f,1.f,0.f };
			}
			else
			{
				Dir = { 1.f,0.f,0.f };
			}
			Dir.Normalize3D();

			MoveVector = Dir * WalkSpeed;
		}

	}
	else if (CurPattern == EEnemyPattern::ChasePlayer)
	{
		AccTime = 0.f;
		State.ChangeState("Run");
		return;
	}
}

void AEnemy::Run(float _DeltaTime)
{
	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	FVector ChangeLayerPos = FVector(870.f, 0.f, 0.f);
	FVector Gap = PlayerPos - GetActorLocation();

	if (LayerLevel != UConstValue::Player->GetLayerLevel())
	{
		Gap = ChangeLayerPos - GetActorLocation();
		if (Gap.X < 0.f)
		{
			MoveVector = FVector::Zero;
			State.ChangeState("ChangeLayerLevel");
			return;
		}
	}


	if (CurDir == EActorDir::Left)
	{
		if (Gap.X > 0.f)
		{
			MoveVector = FVector::Zero;
			State.ChangeState("Turn");
			return;
		}

		FVector Dir = FVector::Zero;
		if (OnLeftUpStep)
		{
			Dir = { -1.f,1.f,0.f };
		}
		else if (OnRightUpStep)
		{
			Dir = { -1.f,-1.f,0.f };
		}
		else
		{
			Dir = { -1.f,0.f,0.f };
		}
		Dir.Normalize3D();

		MoveVector = Dir * MoveSpeed;
	}
	else if (CurDir == EActorDir::Right)
	{
		if (Gap.X < 0.f)
		{
			MoveVector = FVector::Zero;
			State.ChangeState("Turn");
			return;
		}

		FVector Dir = FVector::Zero;
		if (OnLeftUpStep)
		{
			Dir = { 1.f,-1.f,0.f };
		}
		else if (OnRightUpStep)
		{
			Dir = { 1.f,1.f,0.f };
		}
		else
		{
			Dir = { 1.f,0.f,0.f };
		}
		Dir.Normalize3D();

		MoveVector = Dir * MoveSpeed;
	}
}
void AEnemy::Turn(float _DeltaTime)
{
	if (Renderer->IsCurAnimationEnd())
	{
		State.ChangeState("Walk");
		return;
	}
}

void AEnemy::Attack(float _DeltaTime)
{

}

void AEnemy::Death(float _DeltaTime)
{
	
}

void AEnemy::DeathInAir(float _DeltaTime)
{
	
}

void AEnemy::ChangeLayerLevel(float _DeltaTime)
{
	if (Renderer->IsCurAnimationEnd()) {
		if (UConstValue::Player->GetLayerLevel() > LayerLevel)
		{
			LayerLevel++;
			AddActorLocation(FVector::Up * 5.f);
			State.ChangeState("Run");
			return;
		}
		else if (UConstValue::Player->GetLayerLevel() < LayerLevel)
		{
			LayerLevel--;
			AddActorLocation(FVector::Down * 5.f);
			State.ChangeState("Run");
			return;
		}
	}
}

void AEnemy::NoneStart()
{
}

void AEnemy::IdleStart()
{
	MoveVector = FVector::Zero;
	Renderer->ChangeAnimation("Idle");
	return;
}

void AEnemy::WalkStart()
{
	Renderer->ChangeAnimation("Walk");
	return;
}

void AEnemy::RunStart()
{
	Renderer->ChangeAnimation("Run");
	return;
}

void AEnemy::TurnStart()
{
	if (CurDir == EActorDir::Left)
	{
		CurDir = EActorDir::Right;
	}
	else
	{
		CurDir = EActorDir::Left;
	}

	Renderer->ChangeAnimation("Turn");
	return;
}

void AEnemy::AttackStart()
{
	MoveVector = FVector::Zero;
	Renderer->ChangeAnimation("Attack");
	return;
}

void AEnemy::DeathStart()
{
	Renderer->ChangeAnimation("Death");
	return;
}

void AEnemy::DeathInAirStart()
{
	Renderer->ChangeAnimation("DeathInAir");
	return;
}

void AEnemy::ChangeLayerLevelStart()
{
	if (CurDir == EActorDir::Left)
	{
		CurDir = EActorDir::Right;
	}
	else
	{
		CurDir = EActorDir::Left;
	}
	Renderer->ChangeAnimation("Turn");
	return;
}

void AEnemy::AttackEnd()
{
}

void AEnemy::DirUpdate()
{
	FVector Scale = GetActorScale3D();

	if (CurDir == EActorDir::Left)
	{
		if (Scale.X > 0.f)
		{
			Scale.X = -Scale.X;
			SetActorScale3D(Scale);
		}
	}
	else if (CurDir == EActorDir::Right)
	{
		if (Scale.X < 0.f)
		{
			Scale.X = -Scale.X;
			SetActorScale3D(Scale);
		}
	}
}

bool AEnemy::LandCheck()
{
	FVector GruntPos = GetActorLocation();
	GruntPos /= UConstValue::Ratio;
	GruntPos.Y = -GruntPos.Y;
	Color8Bit Color = UConstValue::MapTex->GetColor(GruntPos, Color8Bit::Black);


	if (Color == Color8Bit::Black || Color == Color8Bit::Blue)
	{
		OnLeftUpStep = false;
		OnRightUpStep = false;
		return true;
	}
	else if (Color == Color8Bit::Yellow)
	{
		OnRightUpStep = true;
		OnLeftUpStep = false;
		return true;
	}
	else if (Color == Color8Bit::Red)
	{
		OnLeftUpStep = true;
		OnRightUpStep = false;
		return true;
	}

	return false;
}

void AEnemy::GravityCheck(float _DeltaTime)
{
	if (!LandCheck())
	{
		MoveVector += GravityVector * _DeltaTime;
	}
	else
	{
		MoveVector.Y = 0.f;
	}
}

