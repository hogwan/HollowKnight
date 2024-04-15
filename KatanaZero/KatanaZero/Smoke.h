#pragma once
#include "Item.h"

// Ό³Έν :
class ASmoke : public AItem
{
	GENERATED_BODY(AItem)
public:
	// constructor destructor
	ASmoke();
	~ASmoke();

	// delete Function
	ASmoke(const ASmoke& _Other) = delete;
	ASmoke(ASmoke&& _Other) noexcept = delete;
	ASmoke& operator=(const ASmoke& _Other) = delete;
	ASmoke& operator=(ASmoke&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

