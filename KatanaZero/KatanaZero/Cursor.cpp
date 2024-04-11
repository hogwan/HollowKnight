#include "PreCompile.h"
#include "Cursor.h"
#include "ContentsHelper.h"
#include "Player.h"
#include <EngineCore/Camera.h>

Cursor::Cursor() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

Cursor::~Cursor() 
{
}

void Cursor::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorScale3D(FVector(25.f, 25.f, 10.f));

	Renderer->SetSprite("spr_cursor_0.png");
	Renderer->SetOrder(ERenderOrder::Cursor);
	Renderer->SetAutoSize(1.f, true);
}

void Cursor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
	FVector MousePos = GEngine->EngineWindow.GetScreenMousePos();
	FVector PlayerPos = UConstValue::MainCharacter->GetActorLocation();

	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	FVector TargetPos =
		FVector(CameraPos.X, CameraPos.Y, 0.f) +
		FVector(MousePos.X - WindowScale.hX(), -(MousePos.Y - WindowScale.hY()), 200.f);

	SetActorLocation(TargetPos);
}

