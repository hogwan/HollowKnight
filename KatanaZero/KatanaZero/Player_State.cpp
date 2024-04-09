#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/SpriteRenderer.h>

void Player::StateInit()
{
	State.CreateState("None");
	State.CreateState("Idle");
	State.CreateState("Run");
	State.CreateState("RunToIdle");
	State.CreateState("Roll");
	State.CreateState("Jump");
	State.CreateState("Crouch");
	State.CreateState("CrouchEnd");
	State.CreateState("Fall");
	State.CreateState("Attack");

	State.SetUpdateFunction("None", std::bind(&Player::None, this, std::placeholders::_1));
	State.SetStartFunction("None", std::bind(&Player::NoneStart, this));

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

	State.ChangeState("None");
}

void Player::DirCheck()
{
	if ((true == IsPress('A') || true == IsPress('a')) &&
		(false == IsPress('D') && false == IsPress('d')))
	{
		CurDir = EActorDir::Left;
		FVector Scale = GetActorScale3D();
		if (Scale.X > 0.f)
		{
			Scale.X = -Scale.X;
			SetActorScale3D(Scale);
		}
	}

	if ((true == IsPress('D') || true == IsPress('d')) &&
		(false == IsPress('A') && false == IsPress('a')))
	{
		CurDir = EActorDir::Right;
		FVector Scale = GetActorScale3D();
		if (Scale.X < 0.f)
		{
			Scale.X = -Scale.X;
			SetActorScale3D(Scale);
		}
	}
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
		AccLongJump += _DeltaTime;
		if (AccLongJump > LongJumpTime)
		{
			AccLongJump = 0.f;
			MoveVector += LongJumpForce;
			State.ChangeState("Jump");
			return;
		}

	}
	if (true == IsUp('W') || true == IsUp('w'))
	{
		AccLongJump = 0.f;
		MoveVector += ShortJumpForce;
		State.ChangeState("Jump");
		return;
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
	DirCheck();

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

	if (IsPress('D') || IsPress('d'))
	{
		if (abs(MoveVector.X) < MaxRunSpeed)
		{
			MoveVector.X += RunAccel * _DeltaTime;
		}
		else
		{
			MoveVector.X = MaxRunSpeed;
		}
	}

	if (IsPress('A') || IsPress('a'))
	{
		if (abs(MoveVector.X) < MaxRunSpeed)
		{
			MoveVector.X -= RunAccel * _DeltaTime;
		}
		else
		{
			MoveVector.X = -MaxRunSpeed;
		}
	}

	if (true == IsPress('W') || true == IsPress('w'))
	{
		AccLongJump += _DeltaTime;
		if (AccLongJump > LongJumpTime)
		{
			AccLongJump = 0.f;
			MoveVector += LongJumpForce;
			State.ChangeState("Jump");
			return;
		}

	}
	if (true == IsUp('W') || true == IsUp('w'))
	{
		AccLongJump = 0.f;
		MoveVector += ShortJumpForce;
		State.ChangeState("Jump");
		return;
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
}

void Player::RunToIdle(float _DeltaTime)
{
	Renderer->SetFrameCallback("RunToIdle", 5, [=]
		{
			CurDir;
			FVector CurScale = GetActorScale3D();

			State.ChangeState("Idle");
			return;
		});

	FVector BreakDir = FVector::Zero;
	if (MoveVector.X > 0.f)
	{
		BreakDir = FVector::Left;
	}
	else
	{
		BreakDir = FVector::Right;
	}

	MoveVector += BreakDir * BreakAccel * _DeltaTime;
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
	MoveVector = MoveDir * RollSpeed;

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

	Renderer->SetFrameCallback("Roll", 7, [=]
		{
			State.ChangeState("RunToIdle");
			return;
		});
}

void Player::Jump(float _DeltaTime)
{
	DirCheck();


	if (MoveVector.Y < 0.f)
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
		State.ChangeState("RunToIdle");
		return;
	}

	if (IsPress('D') || IsPress('d'))
	{
		if (MoveVector.X >= MaxAirSpeed)
		{
			MoveVector.X = MaxAirSpeed;
		}
		else
		{
			MoveVector.X += AirAccel * _DeltaTime;
		}
	}

	if (IsPress('A') || IsPress('a'))
	{
		if (MoveVector.X <= -MaxAirSpeed)
		{
			MoveVector.X = -MaxAirSpeed;
		}
		else
		{
			MoveVector.X -= AirAccel * _DeltaTime;
		}
	}
}

void Player::Fall(float _DeltaTime)
{
	DirCheck();

	if (true == IsDown(VK_LBUTTON))
	{
		State.ChangeState("Attack");
		return;
	}


	if (IsLanded)
	{
		State.ChangeState("RunToIdle");
		return;
	}

	if (IsPress('D') || IsPress('d'))
	{
		if (MoveVector.X >= MaxAirSpeed)
		{
			MoveVector.X = MaxAirSpeed;
		}
		else
		{
			MoveVector.X += AirAccel * _DeltaTime;
		}
	}

	if (IsPress('A') || IsPress('a'))
	{
		if (MoveVector.X <= -MaxAirSpeed)
		{
			MoveVector.X = -MaxAirSpeed;
		}
		else
		{
			MoveVector.X -= AirAccel * _DeltaTime;
		}
	}
}

void Player::Attack(float _DeltaTime)
{
	Renderer->SetFrameCallback("Attack", 7, [=]
		{
			State.ChangeState("Idle");
			return;
		});
}

void Player::Crouch(float _DeltaTime)
{
	DirCheck();
	if (true == IsFree('S') && true == IsFree('s'))
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
	MoveVector = FVector::Zero;
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
	return;
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
	AttackDir.Normalize2D();

	MoveVector = AttackDir * AttackSpeed;
	Renderer->ChangeAnimation("Attack");
	return;
}

void Player::CrouchStart()
{
	Renderer->ChangeAnimation("Crouch");
	return;
}

void Player::CrouchEndStart()
{
	Renderer->ChangeAnimation("CrouchEnd");
	return;
}
void Player::GravityCheck(float _DeltaTime)
{
	MoveVector += Gravity * _DeltaTime;
}