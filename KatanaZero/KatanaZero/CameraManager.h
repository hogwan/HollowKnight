#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"


class ACameraManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	//constructer destructer
	ACameraManager();
	~ACameraManager();

	//delete Function
	ACameraManager(const ACameraManager& _Other) = delete;
	ACameraManager(ACameraManager&& _Other) noexcept = delete;
	ACameraManager& operator=(const ACameraManager& _Other) = delete;
	ACameraManager& operator=(ACameraManager&& _Other) noexcept = delete;

	void SetCameraMode(ECameraMode _CameraMode)
	{
		CurMode = _CameraMode;
	}

	std::shared_ptr<UCamera> GetCamera()
	{
		return Camera;
	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	ECameraMode CurMode = ECameraMode::None;

	std::shared_ptr<UCamera> Camera = nullptr;

	bool XEndCheck();
	bool YEndCheck();

};