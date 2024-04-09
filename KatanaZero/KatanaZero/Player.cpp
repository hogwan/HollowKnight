#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include "EnumHelper.h"
#include "ConstValueHelper.h"

Player::Player() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

Player::~Player() 
{
}

void Player::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(36.f, 35.f, 10.f));

	Renderer->CreateAnimation("Idle", "Idle", 0.08f, true);
	Renderer->CreateAnimation("Run", "Run", 0.08f, true);
	Renderer->CreateAnimation("RunToIdle", "RunToIdle", 0.08f, true);
	Renderer->CreateAnimation("Roll", "Roll", 0.08f, false);
	Renderer->CreateAnimation("Jump", "Jump", 0.08f, false);
	Renderer->CreateAnimation("Crouch", "Crouch", 0.08f, false);
	Renderer->CreateAnimation("CrouchEnd", "CrouchEnd", 0.08f, true);
	Renderer->CreateAnimation("Fall", "Fall", 0.08f, true);
	Renderer->CreateAnimation("Attack", "Attack", 0.08f, false);

	StateInit();

	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Player);
	
}

void Player::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	std::shared_ptr<UEngineTexture> Tex = UConstValue::MapTex;

	float4 Pos = GetActorLocation();
	Pos.Y = -Pos.Y;
	Color8Bit Color = Tex->GetColor(Pos, Color8Bit::Black);

	if (Color == Color8Bit::Black)
	{
		IsLanded = true;
		JumpForce = 0.0f;
	}

	State.Update(_DeltaTime);
}

void Player::StateInit()
{
	State.CreateState("Idle");
	State.CreateState("Run");
	State.CreateState("RunToIdle");
	State.CreateState("Roll");
	State.CreateState("Jump");
	State.CreateState("Crouch");
	State.CreateState("CrouchEnd");
	State.CreateState("Fall");
	State.CreateState("Attack");

	State.SetUpdateFunction("Idle", std::bind(&Player::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Idle", std::bind(&Player::IdleStart, this));

	State.SetUpdateFunction("Run", std::bind(&Player::Run, this, std::placeholders::_1));
	State.SetStartFunction("Run", std::bind(&Player::RunStart, this));

	State.SetUpdateFunction("RunToIdle", std::bind(&Player::RunToIdle, this, std::placeholders::_1));
	State.SetStartFunction("RunToIdle", std::bind(&Player::RunToIdleStart, this));

	State.SetUpdateFunction("Roll", std::bind(&Player::Roll, this, std::placeholders::_1));
	State.SetStartFunction("Roll", std::bind(&Player::RollStart, this));

	State.SetUpdateFunction("Jump", std::bind(&Player::Jump, this, std::placeholders::_1));
	State.SetStartFunction("Jump", std::bind(&Player::JumpStart, this));

	State.SetUpdateFunction("Crouch", std::bind(&Player::Crouch, this, std::placeholders::_1));
	State.SetStartFunction("Crouch", std::bind(&Player::CrouchStart, this));

	State.SetUpdateFunction("CrouchEnd", std::bind(&Player::CrouchEnd, this, std::placeholders::_1));
	State.SetStartFunction("CrouchEnd", std::bind(&Player::CrouchEndStart, this));

	State.SetUpdateFunction("Fall", std::bind(&Player::Fall, this, std::placeholders::_1));
	State.SetStartFunction("Fall", std::bind(&Player::FallStart, this));

	State.SetUpdateFunction("Attack", std::bind(&Player::Attack, this, std::placeholders::_1));
	State.SetStartFunction("Attack", std::bind(&Player::AttackStart, this));
}

void Player::None(float _DeltaTime)
{
	State.ChangeState("Idle");
}

void Player::Idle(float _DeltaTime)
{
	if (true == IsPress('A') || true == IsPress('a') ||
		true == IsPress('D') || true == IsPress('d'))
	{
		if ((IsPress('D') || IsPress('d')) &&
			(IsPress('A') || IsPress('a')))
		{
			return;
		}
		State.ChangeState("Run");
		return;
	}

	if (true == IsPress('W') || true == IsPress('w'))
	{
		AccPush += _DeltaTime;
		if (AccPush > LongJumpTime)
		{
			AccPush = 0.f;
			JumpForce = LongJumpForce;
			State.ChangeState("Jump");
			return;
		}

		if (true == IsUp('W') || true == IsUp('w'))
		{
			AccPush = 0.f;
			JumpForce = ShortJumpForce;
			State.ChangeState("Jump");
			return;
		}
	}

	if (true == IsPress('S') || true == IsPress('s'))
	{
		if (IsColDown)
		{
			//내려가는로직
			return;
		}

		State.ChangeState("Crouch");
		return;
	}

	if (true == IsDown(VK_LBUTTON))
	{
		State.ChangeState("Attack");
		return;
	}

	if (false == IsLanded)
	{
		State.ChangeState("Fall");
		return;
	}
}

void Player::Run(float _DeltaTime)
{
	AccRunStart += _DeltaTime;

	if ((IsPress('D') || IsPress('d')) &&
		(IsPress('A') || IsPress('a')))
	{
		State.ChangeState("RunToIdle");
		return;
	}

	if ((IsFree('D') && IsFree('d')) &&
		(IsFree('A') && IsFree('a')))
	{
		State.ChangeState("RunToIdle");
		return;
	}

	if (true == IsPress('W') || true == IsPress('w'))
	{
		AccPush += _DeltaTime;
		if (AccPush > LongJumpTime)
		{
			AccPush = 0.f;
			JumpForce = LongJumpForce;
			State.ChangeState("Jump");
			return;
		}

		if (true == IsUp('W') || true == IsUp('w'))
		{
			AccPush = 0.f;
			JumpForce = ShortJumpForce;
			State.ChangeState("Jump");
			return;
		}
	}

	if (true == IsPress('S') || true == IsPress('s'))
	{
		if (IsColDown)
		{
			//내려가는로직
			return;
		}

		State.ChangeState("Roll");
		return;
	}

	if (true == IsDown(VK_LBUTTON))
	{
		State.ChangeState("Attack");
		return;
	}

	if (false == IsLanded)
	{
		State.ChangeState("Fall");
		return;
	}


	if (AccRunStart > RunStartTime)
	{
		FVector MoveDir = FVector::Zero;
		if (CurDir == EActorDir::Left)
		{
			MoveDir = FVector::Left;
		}
		else
		{
			MoveDir = FVector::Right;
		}
		AddActorLocation(MoveDir * RunSpeed * _DeltaTime);
	}
}

void Player::RunToIdle(float _DeltaTime)
{
	Renderer->SetFrameCallback("RunToIdle", 5, [=]
		{
			State.ChangeState("Idle");
			return;
		});
}

void Player::Roll(float _DeltaTime)
{
	FVector MoveDir = FVector::Zero;
	if (CurDir == EActorDir::Left)
	{
		MoveDir = FVector::Left;
	}
	else
	{
		MoveDir = FVector::Right;
	}
	AddActorLocation(MoveDir * RollSpeed * _DeltaTime);

	if (true == IsDown(VK_LBUTTON))
	{
		State.ChangeState("Attack");
		return;
	}

	if (false == IsLanded)
	{
		State.ChangeState("Fall");
		return;
	}
}

void Player::Jump(float _DeltaTime)
{
	GravityCheck(_DeltaTime);
	AddActorLocation(FVector::Up * JumpForce * _DeltaTime);

	if (JumpForce < 0.f)
	{
		State.ChangeState("Fall");
		return;
	}

	if (true == IsDown(VK_LBUTTON))
	{
		State.ChangeState("Attack");
		return;
	}

	if (IsLanded)
	{
		State.ChangeState("Idle");
		return;
	}
}

void Player::Fall(float _DeltaTime)
{
	GravityCheck(_DeltaTime);
	AddActorLocation(FVector::Up * JumpForce * _DeltaTime);

	if (true == IsDown(VK_LBUTTON))
	{
		State.ChangeState("Attack");
		return;
	}


	if (IsLanded)
	{
		State.ChangeState("Idle");
		return;
	}
}

void Player::Attack(float _DeltaTime)
{
	AddActorLocation(AttackDir * AttackSpeed * _DeltaTime);
	Renderer->SetFrameCallback("Attack", 7, [=]
		{
			State.ChangeState("Idle");
			return;
		});
}

void Player::Crouch(float _DeltaTime)
{
	if (true == IsFree('W') || true == IsFree('w'))
	{
		State.ChangeState("CrouchEnd");
		return;
	}


	if (true == IsPress('A') || true == IsPress('a') ||
		true == IsPress('D') || true == IsPress('d'))
	{
		if ((IsPress('D') || IsPress('d')) &&
			(IsPress('A') || IsPress('a')))
		{
			return;
		}
		State.ChangeState("Roll");
		return;
	}

	if (true == IsDown(VK_LBUTTON))
	{
		State.ChangeState("Attack");
		return;
	}
}

void Player::CrouchEnd(float _DeltaTime)
{
	Renderer->SetFrameCallback("CrouchEnd", 2, [=]
		{
			State.ChangeState("Idle");
			return;
		});
}

void Player::NoneStart()
{
}

void Player::IdleStart()
{
	Renderer->ChangeAnimation("Idle");
	return;
}

void Player::RunStart()
{
	Renderer->ChangeAnimation("Run");
	return;
}

void Player::RunToIdleStart()
{
	Renderer->ChangeAnimation("RunToIdle");
	return;
}

void Player::RollStart()
{
	Renderer->ChangeAnimation("Roll");
}

void Player::JumpStart()
{
	AddActorLocation(FVector::Up * 10.f);
	Renderer->ChangeAnimation("Jump");
	return;
}

void Player::FallStart()
{
	Renderer->ChangeAnimation("Fall");
	return;
}

void Player::AttackStart()
{
	Renderer->ChangeAnimation("Attack");
	return;
}

void Player::CrouchStart()
{
}

void Player::CrouchEndStart()
{
}
void Player::GravityCheck(float _DeltaTime)
{
	JumpForce -= Gravity * _DeltaTime;
}




