#include "PreCompile.h"
#include "Cursor.h"
#include "ContentsHelper.h"
#include "Player.h"
#include <EngineCore/Camera.h>

ACursor::ACursor() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

ACursor::~ACursor() 
{
}

void ACursor::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("spr_cursor_0.png");
	Renderer->SetOrder(ERenderOrder::Cursor);
	Renderer->SetAutoSize(2.f, true);
	GEngine->EngineWindow.CursorOff();
}

void ACursor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
	FVector MousePos = GEngine->EngineWindow.GetScreenMousePos();
	FVector PlayerPos = UConstValue::Player->GetActorLocation();

	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	FVector TargetPos =
		FVector(CameraPos.X, CameraPos.Y, 0.f) +
		FVector(MousePos.X - WindowScale.hX(), -(MousePos.Y - WindowScale.hY()), 200.f);

	SetActorLocation(TargetPos);
}

