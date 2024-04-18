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

	TopCol = CreateDefaultSubObject<UCollision>("Collider");
	TopCol->SetupAttachment(Root);

	BottomCol = CreateDefaultSubObject<UCollision>("Collider");
	BottomCol->SetupAttachment(Root);

	FrontCol = CreateDefaultSubObject<UCollision>("Collider");
	FrontCol->SetupAttachment(Root);

	BackCol = CreateDefaultSubObject<UCollision>("Collider");
	BackCol->SetupAttachment(Root);

	SetRoot(Root);
	InputOn();
}

APlayer::~APlayer() 
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

	ColliderInit();
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
	ObjectInteract();

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
void APlayer::ColliderInit()
{
	Collider->SetScale(FVector(36.f, 72.f, 100.f));
	Collider->SetPosition(FVector(0.f, 36.f, 0.f));
	Collider->SetCollisionGroup(ECollisionOrder::Player);
	Collider->SetCollisionType(ECollisionType::RotRect);

	TopCol->SetScale(FVector(5.f, 1.f, 100.f));
	TopCol->SetPosition(FVector(0.f, 72.f, 0.f));
	TopCol->SetCollisionGroup(ECollisionOrder::ColCheck);
	TopCol->SetCollisionType(ECollisionType::RotRect);

	BottomCol->SetScale(FVector(5.f, 1.f, 100.f));
	BottomCol->SetPosition(FVector(0.f, 0.f, 0.f));
	BottomCol->SetCollisionGroup(ECollisionOrder::ColCheck);
	BottomCol->SetCollisionType(ECollisionType::RotRect);

	FrontCol->SetScale(FVector(1.f, 5.f, 100.f));
	FrontCol->SetPosition(FVector(20.f, 30.f, 0.f));
	FrontCol->SetCollisionGroup(ECollisionOrder::ColCheck);
	FrontCol->SetCollisionType(ECollisionType::RotRect);

	BackCol->SetScale(FVector(1.f, 5.f, 100.f));
	BackCol->SetPosition(FVector(-20.f, 30.f, 0.f));
	BackCol->SetCollisionGroup(ECollisionOrder::ColCheck);
	BackCol->SetCollisionType(ECollisionType::RotRect);
}
void APlayer::CheckPosInit()
{
	FVector Pos = GetActorLocation();
	BottomCheckPos = Pos;
	RightCheckPos = Pos + FVector(20.f, 30.f, 0.f);
	LeftCheckPos = Pos + FVector(-20.f, 30.f, 0.f);
	TopCheckPos = Pos + FVector(0.f, 40.f, 0.f);
	FallCheckPos = Pos + FVector(0.f, -0.0f, 0.f);

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






