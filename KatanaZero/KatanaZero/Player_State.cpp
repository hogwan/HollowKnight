#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Camera.h>
#include <EngineCore/SpriteRenderer.h>
#include "PlayerSlashFX.h"

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
	State.CreateState("WallSlide");
	State.CreateState("Flip");

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
	State.SetEndFunction("Fall", std::bind(&Player::FallEnd, this));

	State.SetUpdateFunction("Attack", std::bind(&Player::Attack, this, std::placeholders::_1));
	State.SetStartFunction("Attack", std::bind(&Player::AttackStart, this));

	State.SetUpdateFunction("WallSlide", std::bind(&Player::WallSlide, this, std::placeholders::_1));
	State.SetStartFunction("WallSlide", std::bind(&Player::WallSlideStart, this));

	State.SetUpdateFunction("Flip", std::bind(&Player::Flip, this, std::placeholders::_1));
	State.SetStartFunction("Flip", std::bind(&Player::FlipStart, this));

	State.ChangeState("None");
}


void Player::DirCheck()
{
	if ((true == IsPress('A') || true == IsPress('a')) &&
		(false == IsPress('D') && false == IsPress('d')))
	{
		CurDir = EActorDir::Left;
	}

	if ((true == IsPress('D') || true == IsPress('d')) &&
		(false == IsPress('A') && false == IsPress('a')))
	{
		CurDir = EActorDir::Right;
	}
}

void Player::DirUpdate()
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
	else if(CurDir == EActorDir::Right)
	{
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
	if ((IsPress('D') || IsPress('d')) &&
		(IsPress('A') || IsPress('a')))
	{
		return;
	}

	if (IsPress('D') || IsPress('d'))
	{
		if (true == RightWallCheck())
		{
			return;
		}

		State.ChangeState("Run");
		return;
	}

	if (IsPress('A') || IsPress('a'))
	{
		if (true == LeftWallCheck())
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
			MoveVector.Y = LongJumpForce.Y;
			State.ChangeState("Jump");
			return;
		}

	}
	if (true == IsUp('W') || true == IsUp('w'))
	{
		AccLongJump = 0.f;
		MoveVector.Y = ShortJumpForce.Y;
		State.ChangeState("Jump");
		return;
	}

	if (true == IsPress('S') || true == IsPress('s'))
	{
		if (OnProjectionWall)
		{
			AddActorLocation(FVector::Down * 10.f);
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
		if (true == RightWallCheck())
		{
			MoveVector.X = 0.f;
			State.ChangeState("RunToIdle");
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

		if (MoveVector.Size3D() < MaxRunSpeed)
		{
			MoveVector += Dir * RunAccel * _DeltaTime;
		}
		else
		{
			MoveVector = Dir * MaxRunSpeed;
		}
	}

	if (IsPress('A') || IsPress('a'))
	{
		if (true == LeftWallCheck())
		{
			MoveVector.X = 0.f;
			State.ChangeState("RunToIdle");
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

		if (MoveVector.Size3D() < MaxRunSpeed)
		{
			MoveVector += Dir * RunAccel * _DeltaTime;
		}
		else
		{
			MoveVector = Dir * MaxRunSpeed;
		}
	}

	if (true == IsPress('W') || true == IsPress('w'))
	{
		AccLongJump += _DeltaTime;
		if (AccLongJump > LongJumpTime)
		{
			AccLongJump = 0.f;
			MoveVector.Y = LongJumpForce.Y;
			State.ChangeState("Jump");
			return;
		}
	}
	if (true == IsUp('W') || true == IsUp('w'))
	{
		AccLongJump = 0.f;
		MoveVector.Y = ShortJumpForce.Y;
		State.ChangeState("Jump");
		return;
	}

	if (true == IsPress('S') || true == IsPress('s'))
	{
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
	if (LeftWallCheck() || RightWallCheck())
	{
		MoveVector = FVector::Zero;
		return;
	}

	Renderer->SetFrameCallback("RunToIdle", 5, [=]
		{
			State.ChangeState("Idle");
			return;
		});

	FVector BreakDir = -MoveVector;
	BreakDir.Normalize3D();

	MoveVector += BreakDir * BreakAccel * _DeltaTime;

}

void Player::Roll(float _DeltaTime)
{
	FVector MoveDir = FVector::Zero;
	if (CurDir == EActorDir::Left)
	{
		MoveDir = FVector::Left;
		if (OnLeftUpStep)
		{
			{
				MoveDir = FVector(-1.0f, 1.0f, 0.f);
				MoveDir.Normalize3D();
			}
		}
		else if (OnRightUpStep)
		{
			{
				MoveDir = FVector(-1.0f, -1.0f, 0.f);
				MoveDir.Normalize3D();
			}
		}

	}
	else
	{
		MoveDir = FVector::Right;

		if (OnLeftUpStep)
		{
			MoveDir = FVector(1.0f, -1.0f, 0.f);
			MoveDir.Normalize3D();
		}
		else if (OnRightUpStep)
		{
			MoveDir = FVector(1.0f, 1.0f, 0.f);
			MoveDir.Normalize3D();
		}
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

	if (LeftWallCheck() || RightWallCheck())
	{
		MoveVector.X = 0.f;
		State.ChangeState("RunToIdle");
		return;
	}
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

	if (CurDir == EActorDir::Right)
	{
		if (RightWallCheck())
		{
			MoveVector.X = 0.f;
			State.ChangeState("WallSlide");
			return;
		}

		if (LeftWallCheck())
		{
			MoveVector.X = 0.f;
			return;
		}

	}
	if (CurDir == EActorDir::Left)
	{
		if (LeftWallCheck())
		{
			MoveVector.X = 0.f;
			State.ChangeState("WallSlide");
			return;
		}

		if (RightWallCheck())
		{
			MoveVector.X = 0.f;
			return;
		}

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

	if (CurDir == EActorDir::Right)
	{
		if (RightWallCheck())
		{
			MoveVector.X = 0.f;
			MoveVector.Y = 0.f;
			State.ChangeState("WallSlide");
			return;
		}

		if (LeftWallCheck())
		{
			MoveVector.X = 0.f;
			return;
		}

	}
	if (CurDir == EActorDir::Left)
	{
		if (LeftWallCheck())
		{
			MoveVector.X = 0.f;
			MoveVector.Y = 0.f;
			State.ChangeState("WallSlide");
			return;
		}

		if (RightWallCheck())
		{
			MoveVector.X = 0.f;
			return;
		}

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
	AccAttack += _DeltaTime;
	if (AccAttack > AttackBreakStartTime)
	{
		MoveVector -= AttackDir * AttackBreakAccel * _DeltaTime;
	}
	else
	{
		MoveVector = AttackDir * AttackSpeed;
	}
	
	if (LeftWallCheck() || RightWallCheck())
	{
		MoveVector.X = 0.f;
	}
	
	Renderer->SetFrameCallback("Attack", 7, [=]
		{
			AccAttack = 0.f;
			State.ChangeState("Fall");
			return;
		});

	if (TopWallCheck() || LeftWallCheck() || RightWallCheck() || LandCheck())
	{
		State.ChangeState("Fall");
		return;
	}
}

void Player::WallSlide(float _DeltaTime)
{
	if (CurDir == EActorDir::Right)
	{
		if (IsPress('a') || IsPress('A'))
		{
			AccDrop += _DeltaTime;
			if (AccDrop > DropTime)
			{
				AccDrop = 0.f;
				AddActorLocation(FVector::Left * 5.f);
				State.ChangeState("Fall");
				return;
			}
		}
		if (IsUp('a') || IsUp('A'))
		{
			AccDrop = 0.f;
		}
	}

	if (CurDir == EActorDir::Left)
	{
		if (IsPress('d') || IsPress('D'))
		{
			AccDrop += _DeltaTime;
			if (AccDrop > DropTime)
			{
				AccDrop = 0.f;
				AddActorLocation(FVector::Right * 5.f);
				State.ChangeState("Fall");
				return;
			}
		}
		if (IsUp('d') || IsUp('D'))
		{
			AccDrop = 0.f;
		}
	}


	Color8Bit Color = UConstValue::MapTex->GetColor(BottomCheckPos, Color8Bit::Black);
	if (Color == Color8Bit::Black)
	{
		if (CurDir == EActorDir::Right)
		{
			CurDir = EActorDir::Left;
		}
		else
		{
			CurDir = EActorDir::Right;
		}

		State.ChangeState("RunToIdle");
		return;
	}

	if (!LeftWallCheck() && !RightWallCheck())
	{
		State.ChangeState("Fall");
		return;
	}

	if (IsDown('w') || IsDown('W'))
	{
		if (CurDir == EActorDir::Right)
		{
			AddActorLocation(FVector::Left * 10.f);
			CurDir = EActorDir::Left;
			State.ChangeState("Flip");
			return;
		}
		else
		{
			AddActorLocation(FVector::Right * 10.f);
			CurDir = EActorDir::Right;
			State.ChangeState("Flip");
			return;
		}
	}

	if (IsDown(VK_LBUTTON))
	{
		State.ChangeState("Attack");
		return;
	}
}

void Player::Flip(float _DeltaTime)
{
	FVector FlipDirVector = FVector::Zero;
	if (CurDir == EActorDir::Left)
	{
		FlipDirVector = { -1.f,1.f,0.f };
	}
	else
	{
		FlipDirVector = { 1.f,1.f,0.f };
	}

	FlipDirVector.Normalize3D();

	AccFlip += _DeltaTime;
	if (AccFlip > FlipBreakStartTime)
	{
		MoveVector -= FlipDirVector * FlipBreakAccel * _DeltaTime;
	}
	else
	{
		MoveVector = FlipDirVector * FlipSpeed;
	}

	if (IsDown(VK_LBUTTON))
	{
		AccFlip = 0.f;
		State.ChangeState("Attack");
		return;
	}
	
	if (LandCheck())
	{
		AccFlip = 0.f;
		State.ChangeState("RunToIdle");
		return;
	}

	if (RightWallCheck() || LeftWallCheck())
	{
		AccFlip = 0.f;
		MoveVector = FVector::Zero;
		State.ChangeState("WallSlide");
		return;
	}

	Renderer->SetFrameCallback("Flip", 11, [=] {
		AccFlip = 0.f;
		State.ChangeState("Fall");
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
	if (OnLeftUpStep)
	{
		if (MoveVector.X > 0.f)
		{
			FVector Dir = FVector(1.0f, -1.0f, 0.f);
			Dir.Normalize3D();
			MoveVector = Dir * MoveVector.Size3D();
		}
		else
		{
			FVector Dir = FVector(-1.0f, 1.0f, 0.f);
			Dir.Normalize3D();
			MoveVector = Dir * MoveVector.Size3D();
		}
	}
	else if (OnRightUpStep)
	{
		if (MoveVector.X > 0.f)
		{
			FVector Dir = FVector(1.0f, 1.0f, 0.f);
			MoveVector = Dir * MoveVector.Size3D();
		}
		else
		{
			FVector Dir = FVector(-1.0f, -1.0f, 0.f);
			MoveVector = Dir * MoveVector.Size3D();
		}
	}
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

void Player::FallEnd()
{
	MoveVector.Y = 0.f;
}

void Player::AttackStart()
{
	FVector MousePos = GEngine->EngineWindow.GetScreenMousePos();
	FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
	FVector PlayerPos = GetActorLocation();

	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	FVector TargetPos = 
		FVector(CameraPos.X,CameraPos.Y, 0.f) +
		FVector(MousePos.X - WindowScale.hX(), -(MousePos.Y - WindowScale.hY()),0.f);

	AttackDir = TargetPos - PlayerPos;
	AttackDir.Z = 0.f;
	AttackDir.Normalize3D();

	MoveVector = AttackDir * AttackSpeed;

	if (MoveVector.X > 0.f)
	{
		CurDir = EActorDir::Right;
	}

	else
	{
		CurDir = EActorDir::Left;
	}
	GetWorld()->SpawnActor<PlayerSlashFX>("Slash");

	Renderer->ChangeAnimation("Attack");
	return;
}

void Player::WallSlideStart()
{
	Renderer->ChangeAnimation("WallSlide");
	return;
}

void Player::FlipStart()
{
	Renderer->ChangeAnimation("Flip");
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

bool Player::LandCheck()
{
	Color8Bit Color = UConstValue::MapTex->GetColor(BottomCheckPos, Color8Bit::Black);

	if (Color == Color8Bit::Black)
	{
		MoveVector.Y = 0.f;
		IsLanded = true;
		OnProjectionWall = false;
		OnLeftUpStep = false;
		OnRightUpStep = false;
		return true;
	}
	else if (Color == Color8Bit::Red)
	{
		IsLanded = true;
		OnLeftUpStep = true;
		OnRightUpStep = false;
		OnProjectionWall = false;
		return true;
	}
	else if (Color == Color8Bit::Yellow)
	{
		IsLanded = true;
		OnRightUpStep = true;
		OnLeftUpStep = false;
		OnProjectionWall = false;
		return true;
	}
	else if (Color == Color8Bit::Blue)
	{
		if (MoveVector.Y > 0.f)
		{
			IsLanded = false;
			return false;
		}
		else
		{
			MoveVector.Y = 0.f;
			IsLanded = true;
			OnProjectionWall = true;
			return true;
		}

		OnLeftUpStep = false;
		OnRightUpStep = false;
	}
	else
	{
		IsLanded = false;
		OnLeftUpStep = false;
		OnRightUpStep = false;
		OnProjectionWall = false;
		return false;
	}

}

bool Player::RightWallCheck()
{
	Color8Bit Color = UConstValue::MapTex->GetColor(RightCheckPos, Color8Bit::Black);
	
	if (Color == Color8Bit::Black)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::LeftWallCheck()
{
	Color8Bit Color = UConstValue::MapTex->GetColor(LeftCheckPos, Color8Bit::Black);
	
	if (Color == Color8Bit::Black)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::TopWallCheck()
{
	Color8Bit Color = UConstValue::MapTex->GetColor(TopCheckPos, Color8Bit::Black);

	if (Color == Color8Bit::Black)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::GroundUp()
{
	while (true)
	{
		BottomCheckPos = GetActorLocation() + FVector(0.f, -20.f, 0.f);
		Color8Bit Color = UConstValue::MapTex->GetColor(BottomCheckPos + FVector::Up*2, Color8Bit::Magenta);
		if (Color == Color8Bit::Black)
		{
			AddActorLocation(FVector::Up);
		}
		else
		{
			break;
		}
	}
}
