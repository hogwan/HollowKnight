#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// ���� :
class ABoard : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ABoard();
	~ABoard();

	// delete Function
	ABoard(const ABoard& _Other) = delete;
	ABoard(ABoard&& _Other) noexcept = delete;
	ABoard& operator=(const ABoard& _Other) = delete;
	ABoard& operator=(ABoard&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	std::vector<std::vector<class AElement*>> Board;

private:
	USpriteRenderer* Renderer = nullptr;
};

