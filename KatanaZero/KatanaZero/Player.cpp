#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsHelper.h"

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

	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::Player);
	
}

void Player::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	std::shared_ptr<UEngineTexture> Tex = UConstValue::MapTex;

	float4 Pos = GetActorLocation();
	Pos /= 2.f;
	Pos.Y = -Pos.Y;
	Color8Bit Color = Tex->GetColor(Pos, Color8Bit::Black);

	if (Color == Color8Bit::Black)
	{
		IsLanded = true;
		MoveVector.Y = 0.f;
	}
	else
	{
		IsLanded = false;
		GravityCheck(_DeltaTime);
	}

	State.Update(_DeltaTime);
	DirUpdate();
	AddActorLocation(MoveVector * _DeltaTime);
}






