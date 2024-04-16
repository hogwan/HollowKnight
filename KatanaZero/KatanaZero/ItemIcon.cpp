#include "PreCompile.h"
#include "ItemIcon.h"
#include "Player.h"

AItemIcon::AItemIcon() 
{
}

AItemIcon::~AItemIcon() 
{
}

void AItemIcon::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("ItemIcon.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::UIFront);
}

void AItemIcon::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
	CameraPos.Z = 300.f;
	SetActorLocation(CameraPos + FVector(590.f, 337.f, 0.f));

	EItemType CurItem = UConstValue::Player->GetPossessItem();

	switch (CurItem)
	{
	case EItemType::Bottle:
		Renderer->SetSprite("Bottle.png");
		Renderer->SetAutoSize(1.f, true);
		break;
	case EItemType::FireBottle:
		Renderer->SetSprite("FireBottle_0.png");
		Renderer->SetAutoSize(1.f, true);
		break;
	case EItemType::Knife:
		Renderer->SetSprite("Knife_0.png");
		Renderer->SetAutoSize(1.f, true);
		break;
	case EItemType::Smoke:
		Renderer->SetSprite("Smoke_0.png");
		Renderer->SetAutoSize(1.f, true);
		break;
	case EItemType::None:
		Renderer->SetSprite("ItemIcon.png");
		Renderer->SetAutoSize(2.f, true);
		break;
	default:
		break;
	}
}

