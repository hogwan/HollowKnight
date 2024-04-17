#include "PreCompile.h"
#include "FanBlade.h"

AFanBlade::AFanBlade() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Collider = CreateDefaultSubObject<UCollision>("Collider");
	Collider->SetupAttachment(Root);
	
	SetRoot(Root);
}

AFanBlade::~AFanBlade() 
{
}

void AFanBlade::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("FanBlade_Spin", "fanblade_spin", 0.005f, true);
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::Object);

	Collider->SetScale(FVector(100.f, 50.f, 10.f));


	Renderer->ChangeAnimation("FanBlade_Spin");
}

void AFanBlade::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Renderer->SetFrameCallback("FanBlade_Spin", 17, [=] {
		Collider->SetActive(false);
		});

	Renderer->SetFrameCallback("FanBlade_Spin", 32, [=] {
		Collider->SetActive(true);
		});
}

