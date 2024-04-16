#include "PreCompile.h"
#include "WeaponSlot.h"

AWeaponSlot::AWeaponSlot() 
{
}

AWeaponSlot::~AWeaponSlot() 
{
}

void AWeaponSlot::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("WeaponSlot.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::UI);
}

void AWeaponSlot::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CameraPos = GetWorld()->GetMainCamera()->GetActorLocation();
	CameraPos.Z = 300.f;
	SetActorLocation(CameraPos + FVector(560.f, 337.f, 0.f));
}

