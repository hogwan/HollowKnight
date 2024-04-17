#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Camera.h>


APlayer::APlayer() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	Collider = CreateDefaultSubObject<UCollision>("Collider");
	Collider->SetupAttachment(Root);

	SetRoot(Root);
	InputOn();
}

APlayer::~APlayer() 
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

	Collider->SetScale(FVector(36.f, 72.f, 100.f));
	Collider->SetPosition(FVector(0.f, 36.f, 0.f));
	Collider->SetCollisionGroup(ECollisionOrder::Player);
	Collider->SetCollisionType(ECollisionType::Rect);

	RendererInit();
	StateInit();
}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	LayerCheck();
	CheckPosInit();
	if (LandCheck() == false)
	{
		GravityCheck(_DeltaTime);
	}
	
	State.Update(_DeltaTime);
	DirUpdate();

	if (TopWallCheck())
	{
		MoveVector.Y = -MoveVector.Y;
	}
	AddActorLocation(MoveVector * _DeltaTime);

	if (IsDown(VK_RBUTTON))
	{
		ThrowItem();
	}
	PickUpItem();

	DebugMessageFunction();
	
	Color8Bit Color = UConstValue::MapTex->GetColor(RightCheckPos, Color8Bit::Black);
	if (Color == Color8Bit::Green)
	{
		NextLevel = true;
	}
}

void APlayer::RendererInit()
{
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

	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::Player);
	
}
void APlayer::CheckPosInit()
{
	FVector Pos = GetActorLocation();
	BottomCheckPos = Pos;
	RightCheckPos = Pos + FVector(20.f, 30.f, 0.f);
	LeftCheckPos = Pos + FVector(-20.f, 30.f, 0.f);
	TopCheckPos = Pos + FVector(0.f, 40.f, 0.f);
	FallCheckPos = Pos + FVector(0.f, -1.f, 0.f);

	BottomCheckPos /= UConstValue::Ratio;
	BottomCheckPos.Y = -BottomCheckPos.Y;
	RightCheckPos /= UConstValue::Ratio;
	RightCheckPos.Y = -RightCheckPos.Y;
	LeftCheckPos /= UConstValue::Ratio;
	LeftCheckPos.Y = -LeftCheckPos.Y;
	TopCheckPos /= UConstValue::Ratio;
	TopCheckPos.Y = -TopCheckPos.Y;
	FallCheckPos /= UConstValue::Ratio;
	FallCheckPos.Y = -FallCheckPos.Y;
}

void APlayer::DebugMessageFunction()
{

	{
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string temp;
		if (CurDir == EActorDir::Left)
		{
			temp = "Left";
		}
		else if (CurDir == EActorDir::Right)
		{
			temp = "Right";
		}
		else
		{
			temp = "None";
		}

		std::string Msg = std::format("CurDir : {}\n", temp);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MoveVector : {}\n", MoveVector.ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
		FVector MousePos = GEngine->EngineWindow.GetScreenMousePos();
		FVector PlayerPos = UConstValue::Player->GetActorLocation();

		FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
		FVector TargetPos =
			FVector(CameraPos.X, CameraPos.Y, 0.f) +
			FVector(MousePos.X - WindowScale.hX(), -(MousePos.Y - WindowScale.hY()), 200.f);

		std::string Msg = std::format("MousePos : {}\n", TargetPos.ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("LayerLevel : {}\n", LayerLevel);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("CurItem : {}\n", static_cast<int>(PossessItem));
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}






