#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ADoor : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ADoor();
	~ADoor();

	// delete Function
	ADoor(const ADoor& _Other) = delete;
	ADoor(ADoor&& _Other) noexcept = delete;
	ADoor& operator=(const ADoor& _Other) = delete;
	ADoor& operator=(ADoor&& _Other) noexcept = delete;

	void SetDir(EActorDir _Dir)
	{
		Dir = _Dir;
		if (Dir == EActorDir::Left)
		{
			FVector Scale = GetActorScale3D();
			Scale.X = -Scale.X;
			SetActorScale3D(Scale);
		}
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	EActorDir Dir = EActorDir::None;

private:
	USpriteRenderer* Renderer = nullptr;
	UCollision* Collider = nullptr;
};

