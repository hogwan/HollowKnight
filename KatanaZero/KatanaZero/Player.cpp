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

	Renderer->CreateAnimation("Idle", "Idle", 0.05f, true);
	Renderer->CreateAnimation("Run", "Run", 0.05f, true);
	Renderer->CreateAnimation("RunToIdle", "RunToIdle", 0.05f, true);
	Renderer->CreateAnimation("Roll", "Roll", 0.05f, false);
	Renderer->CreateAnimation("Jump", "Jump", 0.08f, false);
	Renderer->CreateAnimation("Crouch", "Crouch", 0.05f, false);
	Renderer->CreateAnimation("CrouchEnd", "CrouchEnd", 0.05f, true);
	Renderer->CreateAnimation("Fall", "Fall", 0.05f, true);
	Renderer->CreateAnimation("Attack", "Attack", 0.05f, false);
	Renderer->CreateAnimation("WallSlide", "WallSlide", 0.08f, false);
	Renderer->CreateAnimation("Flip", "Flip", 0.05f, false);

	StateInit();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->SetOrder(ERenderOrder::Player);
	
}

void Player::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	float4 Pos = GetActorLocation();
	BottomCheckPos = Pos + FVector(0.f, -20.f, 0.f);
	RightCheckPos = Pos + FVector(20.f, 0.f, 0.f);
	LeftCheckPos = Pos + FVector(-20.f, 0.f, 0.f);
	TopCheckPos = Pos + FVector(0.f, 20.f, 0.f);

	BottomCheckPos /= UConstValue::Ratio;
	BottomCheckPos.Y = -BottomCheckPos.Y;
	RightCheckPos /= UConstValue::Ratio;
	RightCheckPos.Y = -RightCheckPos.Y;
	LeftCheckPos /= UConstValue::Ratio;
	LeftCheckPos.Y = -LeftCheckPos.Y;
	TopCheckPos /= UConstValue::Ratio;
	TopCheckPos.Y = -TopCheckPos.Y;

	if (LandCheck() == false)
	{
		GravityCheck(_DeltaTime);
	}
	//GroundUp();
	

	State.Update(_DeltaTime);
	DirUpdate();

	AddActorLocation(MoveVector * _DeltaTime);
}






