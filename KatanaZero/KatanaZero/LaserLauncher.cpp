#include "PreCompile.h"
#include "LaserLauncher.h"
#include "Laser.h"

ALaserLauncher::ALaserLauncher() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

ALaserLauncher::~ALaserLauncher() 
{
}

void ALaserLauncher::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::Object);

	Laser = GetWorld()->SpawnActor<ALaser>("Laser");
	Laser->SetOwner(this);

	LaserOn();
}

void ALaserLauncher::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (IsLaserOn)
	{
		Renderer->SetSprite("laser_on_00.png");
		Laser->SetActive(true);
	}
	else
	{
		Renderer->SetSprite("laser_off_00.png");
		Laser->SetActive(false);
	}

	
	AddActorLocation(MoveVector * MoveSpeed * _DeltaTime);

	MoveAcc += MoveSpeed * _DeltaTime;

	if (MoveAcc > MoveDistant)
	{
		MoveVector.X = -MoveVector.X;
		MoveAcc = 0.f;
	}

	
}

