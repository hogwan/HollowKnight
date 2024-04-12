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
	DirUpdate();

	GravityCheck(_DeltaTime);

	State.Update(_DeltaTime);

	FVector PlayerPos = UConstValue::Player->GetActorLocation();
	if (abs(PlayerPos.X - GetActorLocation().X))
	{
		CurPattern = EGruntPattern::ChasePlayer;
	}

	AddActorLocation(MoveVector * _DeltaTime);

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
	State.CreateState("ChangeLayerLevel");

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

	State.SetUpdateFunction("ChangeLayerLevel", std::bind(&AGrunt::ChangeLayerLevel, this, std::placeholders::_1));
	State.SetStartFunction("ChangeLayerLevel", std::bind(&AGrunt::ChangeLayerLevelStart, this));

	State.ChangeState("None");
}

void AGrunt::RendererInit()
{
	Renderer->CreateAnimation("Idle", "grunt_idle", 0.05f, true);
	Renderer->CreateAnimation("Walk", "grunt_walk", 0.05f, true);
	Renderer->CreateAnimation("Run", "Grunt_Run", 0.05f, true);
	Renderer->CreateAnimation("Turn", "Grunt_Turn", 0.05f, false);
	Renderer->CreateAnimation("Attack", "Grunt_Attack", 0.05f, false); 
	Renderer->CreateAnimation("Death", "grunt_hurtground", 0.05f, false);
	Renderer->CreateAnimation("DeathInAir", "grunt_hurtfly", 0.05f, false);
	Renderer->CreateAnimation("ChangeLayerLevel", "grunt_ChangeLayerLevel", 0.05f, false);

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
	if (CurPattern == EGruntPattern::Patrol)
	{
		AccTime += _DeltaTime;
		if (AccTime > IdleTime)
		{
			AccTime = 0.f;
			State.ChangeState("Turn");
			return;
		}
	}
	else if(CurPattern == EGruntPattern::ChasePlayer)
	{
		AccTime = 0.f;
		State.ChangeState("Run");
		return;
	}
}

void AGrunt::Walk(float _DeltaTime)
{
	if (CurPattern == EGruntPattern::Patrol)
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
	else if (CurPattern == EGruntPattern::ChasePlayer)
	{
		AccTime = 0.f;
		State.ChangeState("Run");
		return;
	}
}

void AGrunt::Run(float _DeltaTime)
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
		if(Gap.X < 0.f)
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
void AGrunt::Turn(float _DeltaTime)
{
	Renderer->SetFrameCallback("Turn", 8, [=]
		{
			State.ChangeState("Walk");
			return;
		});
}

void AGrunt::Attack(float _DeltaTime)
{
	Renderer->SetFrameCallback("Attack", 8, [=]
		{
			State.ChangeState("Idle");
			return;
		});
}

void AGrunt::Death(float _DeltaTime)
{
	Renderer->SetFrameCallback("Death", 16, [=]
		{
			Destroy();
			return;
		});
}

void AGrunt::DeathInAir(float _DeltaTime)
{
	Renderer->SetFrameCallback("DeathInAir", 2, [=]
		{
			Destroy();
			return;
		});
}

void AGrunt::ChangeLayerLevel(float _DeltaTime)
{
	Renderer->SetFrameCallback("ChangeLayerLevel", 8, [=] {
		if (UConstValue::Player->GetLayerLevel() > LayerLevel)
		{
			LayerLevel++;
			AddActorLocation(FVector::Up * 5.f);
			State.ChangeState("Run");
			if (CurDir == EActorDir::Left)
			{
				CurDir = EActorDir::Right;
			}
			else
			{
				CurDir = EActorDir::Left;
			}
			return;
		}
		else if (UConstValue::Player->GetLayerLevel() < LayerLevel)
		{
			LayerLevel--;
			AddActorLocation(FVector::Down * 5.f);
			State.ChangeState("Run");
			if (CurDir == EActorDir::Left)
			{
				CurDir = EActorDir::Right;
			}
			else
			{
				CurDir = EActorDir::Left;
			}
			return;
		}
		});
}

void AGrunt::NoneStart()
{
}

void AGrunt::IdleStart()
{
	MoveVector = FVector::Zero;
	Renderer->ChangeAnimation("Idle");
	return;
}

void AGrunt::WalkStart()
{
	Renderer->ChangeAnimation("Walk");
	return;
}

void AGrunt::RunStart()
{
	Renderer->ChangeAnimation("Run");
	return;
}

void AGrunt::TurnStart()
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

void AGrunt::AttackStart()
{
	Renderer->ChangeAnimation("Attack");
	return;
}

void AGrunt::DeathStart()
{
	Renderer->ChangeAnimation("Death");
	return;
}

void AGrunt::DeathInAirStart()
{
	Renderer->ChangeAnimation("DeathInAir");
	return;
}

void AGrunt::ChangeLayerLevelStart()
{
	Renderer->ChangeAnimation("ChangeLayerLevel");
	return;
}

void AGrunt::DirUpdate()
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

bool AGrunt::LandCheck()
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

void AGrunt::GravityCheck(float _DeltaTime)
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
