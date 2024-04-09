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
	Renderer->CreateAnimation("Jump", "Jump", 0.08f, false);
	Renderer->CreateAnimation("Fall", "Fall", 0.08f, true);
	Renderer->CreateAnimation("Attack", "Attack", 0.08f, false);

	StateInit();

	Renderer->SetAutoSize(10.0f, true);
	Renderer->SetOrder(ERenderOrder::Player);
	
}

void Player::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	std::shared_ptr<UEngineTexture> Tex = UConstValue::MapTex;

	float4 Pos = GetActorLocation();
	Pos.Y = -Pos.Y;

	Color8Bit Color = Tex->GetColor(Pos, Color8Bit::Black);

	if (Color != Color8Bit::Black)
	{
		AddActorLocation(float4::Down * _DeltaTime * 100.0f);
	}

	if (Color == Color8Bit::Black)
	{
		int a = 0;
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
}

void Player::Run(float _DeltaTime)
{
	if(IsUp())
}

void Player::RunToIdle(float _DeltaTime)
{
}

void Player::Roll(float _DeltaTime)
{
}

void Player::Jump(float _DeltaTime)
{
}

void Player::Fall(float _DeltaTime)
{
}

void Player::Attack(float _DeltaTime)
{
}

void Player::NoneStart()
{
}

void Player::IdleStart()
{
}

void Player::RunStart()
{
}

void Player::RunToIdleStart()
{
}

void Player::RollStart()
{
}

void Player::JumpStart()
{
}

void Player::FallStart()
{
}

void Player::AttackStart()
{
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

