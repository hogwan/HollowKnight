#pragma once
#include <EngineCore/Actor.h>
#include <list>

enum class BundleType
{
	Null,
	Tetris,
	L1,
	L2,
	Key1,
	Key2,
	Square,
	T,
};

// Ό³Έν :
class ATetrisElementBundle : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ATetrisElementBundle();
	~ATetrisElementBundle();

	// delete Function
	ATetrisElementBundle(const ATetrisElementBundle& _Other) = delete;
	ATetrisElementBundle(ATetrisElementBundle&& _Other) noexcept = delete;
	ATetrisElementBundle& operator=(const ATetrisElementBundle& _Other) = delete;
	ATetrisElementBundle& operator=(ATetrisElementBundle&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::list<class ATetrisElement*> EleList;
	FVector CenterPos = FVector::Zero;
};

