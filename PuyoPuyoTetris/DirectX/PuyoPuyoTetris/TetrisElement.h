#pragma once
#include "Element.h"

// Ό³Έν :
class ATetrisElement : public AElement
{
	GENERATED_BODY(AElement)
public:
	// constructor destructor
	ATetrisElement();
	~ATetrisElement();

	// delete Function
	ATetrisElement(const ATetrisElement& _Other) = delete;
	ATetrisElement(ATetrisElement&& _Other) noexcept = delete;
	ATetrisElement& operator=(const ATetrisElement& _Other) = delete;
	ATetrisElement& operator=(ATetrisElement&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

