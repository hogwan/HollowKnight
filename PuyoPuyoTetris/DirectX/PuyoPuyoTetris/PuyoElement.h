#pragma once
#include "Element.h"

// ���� :
class APuyoElement : public AElement
{
	GENERATED_BODY(AElement)
public:
	// constructor destructor
	APuyoElement();
	~APuyoElement();

	// delete Function
	APuyoElement(const APuyoElement& _Other) = delete;
	APuyoElement(APuyoElement&& _Other) noexcept = delete;
	APuyoElement& operator=(const APuyoElement& _Other) = delete;
	APuyoElement& operator=(APuyoElement&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

