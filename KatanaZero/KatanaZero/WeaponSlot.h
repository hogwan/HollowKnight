#pragma once
#include "UIBase.h"

// Ό³Έν :
class AWeaponSlot : public AUIBase
{
	GENERATED_BODY(AUIBase)
public:
	// constructor destructor
	AWeaponSlot();
	~AWeaponSlot();

	// delete Function
	AWeaponSlot(const AWeaponSlot& _Other) = delete;
	AWeaponSlot(AWeaponSlot&& _Other) noexcept = delete;
	AWeaponSlot& operator=(const AWeaponSlot& _Other) = delete;
	AWeaponSlot& operator=(AWeaponSlot&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

