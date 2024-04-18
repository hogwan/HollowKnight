#include "PreCompile.h"
#include "Laser.h"
#include "LaserLauncher.h"

ALaser::ALaser() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Collider = CreateDefaultSubObject<UCollision>("Collider");
	Collider->SetupAttachment(Root);

	SetRoot(Root);
}

ALaser::~ALaser() 
{
}

void ALaser::SetOwner(ALaserLauncher* _LaserLauncher)
{
	Owner = _LaserLauncher;
}

void ALaser::SetY(float Y)
{
	Renderer->SetScale(FVector(2.f, Y, 10.f));
	Collider->SetScale(FVector(2.f, Y, 10.f));
}



void ALaser::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Idle", "laser_idle", 0.05f, true);
	Renderer->CreateAnimation("Col", "laser_col", 0.1f, false);
	Renderer->SetOrder(ERenderOrder::Object);

	Collider->SetCollisionGroup(ECollisionOrder::Laser);
	Collider->SetCollisionType(ECollisionType::RotRect);
	

	Renderer->ChangeAnimation("Idle");
}

void ALaser::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector Pos = Owner->GetActorLocation() + FVector(0.f, -Renderer->GetLocalScale().Y/2.f, 0.f);
	SetActorLocation(Pos);

	Collider->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collision)
		{
			Renderer->ChangeAnimation("Col");
			DelayCallBack(0.2f, [=] {
				Renderer->ChangeAnimation("Idle");
				});
		}
	);

	Collider->CollisionEnter(ECollisionOrder::Enemy, [=](std::shared_ptr<UCollision> _Collision)
		{
			Renderer->ChangeAnimation("Col");
			DelayCallBack(0.2f, [=] {
				Renderer->ChangeAnimation("Idle");
				});
		}
	);
	
}

void ALaser::On()
{
	Renderer->SetActive(true);
	Collider->SetActive(true);
}

void ALaser::Off()
{
	Renderer->SetActive(false);
	Collider->SetActive(false);
}

