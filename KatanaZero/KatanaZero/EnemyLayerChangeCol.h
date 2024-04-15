#pragma once
#include "ActionCollider.h"

// Ό³Έν :
class AEnemyLayerChangeCol : public AActionCollider
{
	GENERATED_BODY(AActionCollider)
public:
	// constructor destructor
	AEnemyLayerChangeCol();
	~AEnemyLayerChangeCol();

	// delete Function
	AEnemyLayerChangeCol(const AEnemyLayerChangeCol& _Other) = delete;
	AEnemyLayerChangeCol(AEnemyLayerChangeCol&& _Other) noexcept = delete;
	AEnemyLayerChangeCol& operator=(const AEnemyLayerChangeCol& _Other) = delete;
	AEnemyLayerChangeCol& operator=(AEnemyLayerChangeCol&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

