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
	Renderer->ChangeAnimation("Idle");
	
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
	State.CreateState("Jump");
	State.CreateState("Fall");
	State.CreateState("Run");
	State.CreateState("Attack");

	State.SetUpdateFunction("Idle", std::bind(&Player::Idle, this, std::placeholders::_1));
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

void Player::GravityCheck(float _DeltaTime)
{
	JumpForce -= Gravity * _DeltaTime;
}

void Player::CrouchStart()
{
}

void Player::CrouchEndStart()
{
}

void Player::Crouch(float _DeltaTime)
{
}

void Player::CrouchEnd(float _DeltaTime)
{
}

