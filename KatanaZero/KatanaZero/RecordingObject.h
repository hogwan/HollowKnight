#pragma once

class URecordingObject;

struct FSpriteRendererInfo
{
public:
	FSpriteInfo SpriteInfo;
	FVector Position = FVector::Zero;
	FVector Rocation = FVector::Zero;
	EEngineDir Dir = EEngineDir::MAX;
	bool IsActive = false;
};

class URecordInfo
{
	friend URecordingObject;
private:
	std::map<std::shared_ptr<USpriteRenderer>, FSpriteRendererInfo> SpriteRendererData;
	FVector Position;
};

// 설명 : 리플레이 기능 오브젝트
class URecordingObject
{
public:
	// constrcuter destructer
	URecordingObject();
	~URecordingObject();

	// delete Function
	URecordingObject(const URecordingObject& _Other) = delete;
	URecordingObject(URecordingObject&& _Other) noexcept = delete;
	URecordingObject& operator=(const URecordingObject& _Other) = delete;
	URecordingObject& operator=(URecordingObject&& _Other) noexcept = delete;

	void SetRecordingSize(float _RecTime);
	void Recording(float _DeltaTime);

	void SetReplayStart();
	bool Replaying(float _DeltaTime);

	void SetRevertStart();
	bool Reverting(float _DeltaTime);

protected:
	void SetActor(AActor* _Actor)
	{
		Actor = _Actor;
	}

private:
	AActor* Actor = nullptr;

	int MaxSize = 100000;
	int CurIndex = 0;
	float TimeCount = UConstValue::recording_delay;

	std::vector<URecordInfo> AllRecordInfo;
};

