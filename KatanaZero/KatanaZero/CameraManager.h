#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"


class CameraManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	//constructer destructer
	CameraManager();
	~CameraManager();

	//delete Function
	CameraManager(const CameraManager& _Other) = delete;
	CameraManager(CameraManager&& _Other) noexcept = delete;
	CameraManager& operator=(const CameraManager& _Other) = delete;
	CameraManager& operator=(CameraManager&& _Other) noexcept = delete;

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

	void XEndCheck();
	void YEndCheck();

};