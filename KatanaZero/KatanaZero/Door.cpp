#include "PreCompile.h"
#include "Door.h"

ADoor::ADoor() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Collider = CreateDefaultSubObject<UCollision>("Collider");
	Collider->SetupAttachment(Root);

	SetRoot(Root);
}

ADoor::~ADoor() 
{
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetAutoSize(2.f, true);
	Renderer->CreateAnimation("Idle", "door_idle", 0.05f, true);
	Renderer->CreateAnimation("Open", "door_open", 0.05f, false);
	Renderer->SetOrder(ERenderOrder::Object);

	Collider->SetScale(FVector(50.f, 100.f, 30.f));
	Collider->SetCollisionGroup(ECollisionOrder::Door);
	Collider->SetCollisionType(ECollisionType::RotRect);

	Renderer->ChangeAnimation("Idle");
}

void ADoor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	if (IsOpen)
	{
		Collider->SetActive(false);
	}

	Collider->CollisionEnter(ECollisionOrder::PlayerSlash, [=](std::shared_ptr<UCollision> _Collision)
		{
			Renderer->ChangeAnimation("Open");
			IsOpen = true;
		}
	);


}

