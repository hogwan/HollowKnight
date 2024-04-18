#include "PreCompile.h"
#include "LaserSwitch.h"

ALaserSwitch::ALaserSwitch() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetOrder(ERenderOrder::Object);
	
	Collider = CreateDefaultSubObject<UCollision>("Collider");
	Collider->SetupAttachment(Root);

	SetRoot(Root);
}

ALaserSwitch::~ALaserSwitch() 
{
}

void ALaserSwitch::On()
{
	for (std::shared_ptr<ALaserLauncher> LaserLauncher : Lasers)
	{
		LaserLauncher->LaserOn();
	}
	IsOn = true;
}

void ALaserSwitch::Off()
{
	for (std::shared_ptr<ALaserLauncher> LaserLauncher : Lasers)
	{
		LaserLauncher->LaserOff();
	}
	IsOn = false;
}

void ALaserSwitch::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorScale3D(FVector(30.f, 52.f, 10.f));
	Renderer->SetSprite("SwitchOff.png");

	Collider->SetCollisionGroup(ECollisionOrder::Switch);
	Collider->SetCollisionType(ECollisionType::RotRect);
	
}

void ALaserSwitch::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (IsOn)
	{
		Renderer->SetSprite("SwitchOn.png");
	}
	else
	{
		Renderer->SetSprite("SwitchOff.png");
	}
}

