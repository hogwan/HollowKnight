#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AElement : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	AElement();
	~AElement();

	// delete Function
	AElement(const AElement& _Other) = delete;
	AElement(AElement&& _Other) noexcept = delete;
	AElement& operator=(const AElement& _Other) = delete;
	AElement& operator=(AElement&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

