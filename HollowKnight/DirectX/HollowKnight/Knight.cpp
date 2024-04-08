#include "PreCompile.h"
#include "Knight.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineRandom.h>
#include "KnightAnimation.h"

AKnight::AKnight()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

AKnight::~AKnight()
{
}



void AKnight::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(Scale);

	Renderer->CreateAnimation("Idle", "Idle", 0.08f, true);
	Renderer->CreateAnimation("LookUp", "LookUp", 0.08f, true);
	Renderer->CreateAnimation("LookUpToIdle", "LookUpToIdle", 0.08f, false);
	Renderer->CreateAnimation("LookDown", "LookDown", 0.08f, false);
	Renderer->CreateAnimation("LookDownToIdle", "LookDownToIdle", 0.08f, false);
	Renderer->CreateAnimation("Run", "Run", 0.08f, false);
	Renderer->CreateAnimation("Walk", "Walk", 0.08f, true);
	Renderer->CreateAnimation("RunToIdle", "RunToIdle", 0.08f, false);
	Renderer->CreateAnimation("Turn", "Turn", 0.08f, false);
	Renderer->CreateAnimation("Airborne", "Airborne", 0.08f, false);
	Renderer->CreateAnimation("Fall", "Fall", 0.08f, true);
	Renderer->CreateAnimation("Land", "Land", 0.08f, false);
	Renderer->CreateAnimation("HardLand", "HardLand", 0.08f, false);
	Renderer->CreateAnimation("Slash", "Slash", 0.08f, false);
	Renderer->CreateAnimation("SlashAlt", "SlashAlt", 0.08f, false);
	Renderer->CreateAnimation("UpSlash", "UpSlash", 0.08f, false);
	Renderer->CreateAnimation("DownSlash", "DownSlash", 0.08f, false);
	Renderer->CreateAnimation("Dash", "Dash", 0.08f, false);
	Renderer->CreateAnimation("DashToIdle", "DashToIdle", 0.08f, false);
	Renderer->CreateAnimation("WallSlide", "WallSlide", 0.08f, true);
	Renderer->CreateAnimation("WallJump", "WallJump", 0.08f, false);
	Renderer->CreateAnimation("Sit", "Sit", 0.08f, false);
	Renderer->CreateAnimation("SitOff", "SitOff", 0.08f, false);
	Renderer->CreateAnimation("MapOpen", "MapOpen", 0.08f, false);
	Renderer->CreateAnimation("MapIdle", "MapIdle", 0.08f, true);
	Renderer->CreateAnimation("MapWalk", "MapWalk", 0.08f, true);
	Renderer->CreateAnimation("MapAway", "MapAway", 0.08f, false);
	Renderer->CreateAnimation("MapTurn", "MapTurn", 0.08f, false);
	Renderer->CreateAnimation("SitMapOpen", "SitMapOpen", 0.08f, false);
	Renderer->CreateAnimation("SitMapClose", "SitMapClose", 0.08f, false);
	Renderer->CreateAnimation("MapUpdate", "MapUpdate", 0.08f, false);
	Renderer->CreateAnimation("Focus", "Focus", 0.08f, false);
	Renderer->CreateAnimation("FocusGet", "FocusGet", 0.08f, false);
	Renderer->CreateAnimation("FocusEnd", "FocusEnd", 0.08f, false);
	Renderer->CreateAnimation("CollectMagical1", "CollectMagical1", 0.08f, false);
	Renderer->CreateAnimation("CollectMagical2", "CollectMagical2", 0.08f, false);
	Renderer->CreateAnimation("CollectMagical3", "CollectMagical3", 0.08f, false);
	Renderer->CreateAnimation("CollectNormal1", "CollectNormal1", 0.08f, false);
	Renderer->CreateAnimation("CollectNormal2", "CollectNormal2", 0.08f, false);
	Renderer->CreateAnimation("CollectNormal3", "CollectNormal3", 0.08f, false);
	Renderer->CreateAnimation("Enter", "Enter", 0.08f, false);
	Renderer->CreateAnimation("Prostrate", "Prostrate", 0.08f, false);
	Renderer->CreateAnimation("ProstrateRise", "ProstrateRise", 0.08f, false);
	Renderer->CreateAnimation("FireballAntic", "FireballAntic", 0.08f, false);
	Renderer->CreateAnimation("FireballCast", "FireballCast", 0.08f, false);
	Renderer->CreateAnimation("Recoil", "Recoil", 0.08f, false);
	Renderer->CreateAnimation("Death", "Death", 0.08f, false);

}

void AKnight::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	LandCheck();
	DirCheck();
	if (Manupulate)
	{
		ManupulateUpdate(_DeltaTime);
	}

	StateUpdate(_DeltaTime);
}

void AKnight::ManupulateUpdate(float _DeltaTime)
{
	if (UEngineInput::IsPress(VK_RIGHT) && UEngineInput::IsFree(VK_LEFT))
	{
		Dir = FVector::Right;
		AddActorLocation(Dir * MoveSpeed * _DeltaTime);
	}

	if (UEngineInput::IsPress(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		Dir = FVector::Left;
		AddActorLocation(Dir * MoveSpeed * _DeltaTime);
	}

	if (IsLanded)
	{
		if (UEngineInput::IsDown('z')
			|| UEngineInput::IsDown('Z'))
		{
			IsAirborne = true;
			AddActorLocation(FVector::Up * 5.f);
		}
		else
		{
			AirborneReset();
		}
	}
	else
	{
		if (IsAirborne)
		{
			if (UEngineInput::IsUp('z') ||
				UEngineInput::IsUp('Z'))
			{
				AirborneReset();
			}
			else if (UEngineInput::IsPress('Z')
				|| UEngineInput::IsPress('z'))
			{
				AirborneTime += _DeltaTime;
				AddActorLocation(FVector::Up * AirborneSpeed * _DeltaTime);
			}

			if (AirborneTime > AirborneLimit)
			{
				AirborneReset();
			}
		}
	}

	if (!IsAirborne && !IsLanded)
	{
		AddActorLocation(FVector::Down * AirborneSpeed * _DeltaTime);
		StateChange(EKnightState::Fall);
		return;
	}
	int a = 0;
}

void AKnight::LandCheck()
{
	FVector Pos = GetActorLocation();

	if ((Pos.Y - 60.f) <= -200.0f)
	{
		IsLanded = true;
	}
	else
	{
		IsLanded = false;
	}
}

void AKnight::DirCheck()
{
	if (Dir.X < 0.f)
	{
		SetActorScale3D(Scale);
	}
	else
	{
		FVector tempScale = Scale;
		tempScale.X = -Scale.X;
		SetActorScale3D(tempScale);
	}

}

void AKnight::AirborneReset()
{
	IsAirborne = false;
	AirborneTime = 0.f;
}

void AKnight::StateChange(EKnightState _State)
{
	if (CurState != _State)
	{
		switch (_State)
		{
		case EKnightState::None:
			NoneStart();
			break;
		case EKnightState::Idle:
			IdleStart();
			break;
		case EKnightState::LookUp:
			LookUpStart();
			break;
		case EKnightState::LookUpToIdle:
			LookUpToIdleStart();
			break;
		case EKnightState::LookDown:
			LookDownStart();
			break;
		case EKnightState::LookDownToIdle:
			LookDownToIdleStart();
			break;
		case EKnightState::Run:
			RunStart();
			break;
		case EKnightState::Walk:
			WalkStart();
			break;
		case EKnightState::RunToIdle:
			RunToIdleStart();
			break;
		case EKnightState::Turn:
			TurnStart(); 
			break;
		case EKnightState::Airborne:
			AirborneStart();
			break;
		case EKnightState::Fall:
			FallStart();
			break;
		case EKnightState::Land:
			LandStart();
			break;
		case EKnightState::HardLand:
			HardLandStart();
			break;
		case EKnightState::Slash:
			SlashStart();
			break;
		case EKnightState::SlashAlt:
			SlashAltStart();
			break;
		case EKnightState::UpSlash:
			UpSlashStart();
			break;
		case EKnightState::DownSlash:
			DownSlashStart();
			break;
		case EKnightState::Dash:
			DashStart();
			break;
		case EKnightState::DashToIdle:
			DashToIdleStart();
			break;
		case EKnightState::WallSlide:
			WallSlideStart();
			break;
		case EKnightState::WallJump:
			WallJumpStart();
			break;
		case EKnightState::Sit:
			SitStart();
			break;
		case EKnightState::SitOff:
			SitOffStart();
			break;
		case EKnightState::MapOpen:
			MapOpenStart();
			break;
		case EKnightState::MapIdle:
			MapIdleStart();
			break;
		case EKnightState::MapWalk:
			MapWalkStart();
			break;
		case EKnightState::MapAway:
			MapAwayStart();
			break;
		case EKnightState::MapTurn:
			MapTurnStart();
			break;
		case EKnightState::SitMapOpen:
			SitMapOpenStart();
			break;
		case EKnightState::SitMapClose:
			SitMapCloseStart();
			break;
		case EKnightState::MapUpdate:
			MapUpdateStart();
			break;
		case EKnightState::Focus:
			FocusStart();
			break;
		case EKnightState::FocusGet:
			FocusGetStart();
			break;
		case EKnightState::FocusEnd:
			FocusEndStart();
			break;
		case EKnightState::CollectMagical1:
			CollectMagical1Start();
			break;
		case EKnightState::CollectMagical2:
			CollectMagical2Start();
			break;
		case EKnightState::CollectMagical3:
			CollectMagical3Start();
			break;
		case EKnightState::CollectNormal1:
			CollectNormal1Start();
			break;
		case EKnightState::CollectNormal2:
			CollectNormal2Start();
			break;
		case EKnightState::CollectNormal3:
			CollectNormal3Start();
			break;
		case EKnightState::Enter:
			EnterStart();
			break;
		case EKnightState::Prostrate:
			ProstrateStart();
			break;
		case EKnightState::ProstrateRise:
			ProstrateRiseStart();
			break;
		case EKnightState::FireballAntic:
			FireballAnticStart();
			break;
		case EKnightState::FireballCast:
			FireballCastStart();
			break;
		case EKnightState::Recoil:
			RecoilStart();
			break;
		case EKnightState::Death:
			DeathStart();
			break;
		}
	}

	CurState = _State;
}

void AKnight::StateUpdate(float _DeltaTime)
{
	switch (CurState)
	{
	case EKnightState::None:
		None(_DeltaTime);
		break;
	case EKnightState::Idle:
		Idle(_DeltaTime);
		break;
	case EKnightState::LookUp:
		LookUp(_DeltaTime);
		break;
	case EKnightState::LookUpToIdle:
		LookUpToIdle(_DeltaTime);
		break;
	case EKnightState::LookDown:
		LookDown(_DeltaTime);
		break;
	case EKnightState::LookDownToIdle:
		LookDownToIdle(_DeltaTime);
		break;
	case EKnightState::Run:
		Run(_DeltaTime);
		break;
	case EKnightState::Walk:
		Walk(_DeltaTime);
		break;
	case EKnightState::RunToIdle:
		RunToIdle(_DeltaTime);
		break;
	case EKnightState::Turn:
		Turn(_DeltaTime);
		break;
	case EKnightState::Airborne:
		Airborne(_DeltaTime);
		break;
	case EKnightState::Fall:
		Fall(_DeltaTime);
		break;
	case EKnightState::Land:
		Land(_DeltaTime);
		break;
	case EKnightState::HardLand:
		HardLand(_DeltaTime);
		break;
	case EKnightState::Slash:
		Slash(_DeltaTime);
		break;
	case EKnightState::SlashAlt:
		SlashAlt(_DeltaTime);
		break;
	case EKnightState::UpSlash:
		UpSlash(_DeltaTime);
		break;
	case EKnightState::DownSlash:
		DownSlash(_DeltaTime);
		break;
	case EKnightState::Dash:
		Dash(_DeltaTime);
		break;
	case EKnightState::DashToIdle:
		DashToIdle(_DeltaTime);
		break;
	case EKnightState::WallSlide:
		WallSlide(_DeltaTime);
		break;
	case EKnightState::WallJump:
		WallJump(_DeltaTime);
		break;
	case EKnightState::Sit:
		Sit(_DeltaTime);
		break;
	case EKnightState::SitOff:
		SitOff(_DeltaTime);
		break;
	case EKnightState::MapOpen:
		MapOpen(_DeltaTime);
		break;
	case EKnightState::MapIdle:
		MapIdle(_DeltaTime);
		break;
	case EKnightState::MapWalk:
		MapWalk(_DeltaTime);
		break;
	case EKnightState::MapAway:
		MapAway(_DeltaTime);
		break;
	case EKnightState::MapTurn:
		MapTurn(_DeltaTime);
		break;
	case EKnightState::SitMapOpen:
		SitMapOpen(_DeltaTime);
		break;
	case EKnightState::SitMapClose:
		SitMapClose(_DeltaTime);
		break;
	case EKnightState::MapUpdate:
		MapUpdate(_DeltaTime);
		break;
	case EKnightState::Focus:
		Focus(_DeltaTime);
		break;
	case EKnightState::FocusGet:
		FocusGet(_DeltaTime);
		break;
	case EKnightState::FocusEnd:
		FocusEnd(_DeltaTime);
		break;
	case EKnightState::CollectMagical1:
		CollectMagical1(_DeltaTime);
		break;
	case EKnightState::CollectMagical2:
		CollectMagical2(_DeltaTime);
		break;
	case EKnightState::CollectMagical3:
		CollectMagical3(_DeltaTime);
		break;
	case EKnightState::CollectNormal1:
		CollectNormal1(_DeltaTime);
		break;
	case EKnightState::CollectNormal2:
		CollectNormal2(_DeltaTime);
		break;
	case EKnightState::CollectNormal3:
		CollectNormal3(_DeltaTime);
		break;
	case EKnightState::Enter:
		Enter(_DeltaTime);
		break;
	case EKnightState::Prostrate:
		Prostrate(_DeltaTime);
		break;
	case EKnightState::ProstrateRise:
		ProstrateRise(_DeltaTime);
		break;
	case EKnightState::FireballAntic:
		FireballAntic(_DeltaTime);
		break;
	case EKnightState::FireballCast:
		FireballCast(_DeltaTime);
		break;
	case EKnightState::Recoil:
		Recoil(_DeltaTime);
		break;
	case EKnightState::Death:
		Death(_DeltaTime);
		break;
	}
}

void AKnight::None(float _DeltaTime)
{
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::Idle(float _DeltaTime)
{
	if ((Dir.X > 0.f && UEngineInput::IsPress(VK_LEFT))
		|| Dir.X < 0.f && UEngineInput::IsPress(VK_RIGHT))
	{
		StateChange(EKnightState::Turn);
		return;
	}

	if (UEngineInput::IsPress(VK_RIGHT)
		&& UEngineInput::IsFree(VK_LEFT))
	{
		StateChange(EKnightState::Run);
		return;
	}

	if (UEngineInput::IsFree(VK_RIGHT)
		&& UEngineInput::IsPress(VK_LEFT))
	{
		StateChange(EKnightState::Run);
		return;
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		StateChange(EKnightState::LookUp);
		return;
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		StateChange(EKnightState::LookDown);
		return;
	}

	if (UEngineInput::IsDown('z') ||
		UEngineInput::IsDown('Z'))
	{
		StateChange(EKnightState::Airborne);
		return;
	}

	if (!IsLanded)
	{
		StateChange(EKnightState::Fall);
		return;
	}

	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		int Random = UEngineRandom::MainRandom.RandomInt(0, 1);
		if (Random == 0)
		{
			StateChange(EKnightState::Slash);
			return;
		}
		else
		{
			StateChange(EKnightState::SlashAlt);
			return;
		}
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		StateChange(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			StateChange(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		StateChange(EKnightState::FireballAntic);
		return;
	}
}

void AKnight::LookUp(float _DeltaTime)
{
	if (UEngineInput::IsFree(VK_UP))
	{
		StateChange(EKnightState::LookUpToIdle);
		return;
	}

	if (UEngineInput::IsPress(VK_RIGHT)
		|| UEngineInput::IsPress(VK_LEFT))
	{
		StateChange(EKnightState::Run);
		return;
	}

	if (UEngineInput::IsDown('z') ||
		UEngineInput::IsDown('Z'))
	{
		StateChange(EKnightState::Airborne);
		return;
	}

	if (!IsLanded)
	{
		StateChange(EKnightState::Fall);
		return;
	}

	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		StateChange(EKnightState::UpSlash);
		return;
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		StateChange(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			StateChange(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		StateChange(EKnightState::FireballAntic);
		return;
	}
}

void AKnight::LookUpToIdle(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::LookDown(float _DeltaTime)
{
	if (UEngineInput::IsFree(VK_DOWN))
	{
		StateChange(EKnightState::LookDownToIdle);
		return;
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		StateChange(EKnightState::LookUp);
		return;
	}

	if (UEngineInput::IsPress(VK_RIGHT)
		|| UEngineInput::IsPress(VK_LEFT))
	{
		StateChange(EKnightState::Run);
		return;
	}

	if (UEngineInput::IsDown('z') ||
		UEngineInput::IsDown('Z'))
	{
		StateChange(EKnightState::Airborne);
		return;
	}

	if (!IsLanded)
	{
		StateChange(EKnightState::Fall);
		return;
	}

	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		int Random = UEngineRandom::MainRandom.RandomInt(0, 1);
		if (Random == 0)
		{
			StateChange(EKnightState::Slash);
			return;
		}
		else
		{
			StateChange(EKnightState::SlashAlt);
			return;
		}
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		StateChange(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			StateChange(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		StateChange(EKnightState::FireballAntic);
		return;
	}
}

void AKnight::LookDownToIdle(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::Run(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Walk);
	return;

	if (UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		StateChange(EKnightState::RunToIdle);
		return;
	}

	if (UEngineInput::IsPress(VK_LEFT) && UEngineInput::IsPress(VK_RIGHT))
	{
		StateChange(EKnightState::RunToIdle);
		return;
	}

	if (UEngineInput::IsDown('z') ||
		UEngineInput::IsDown('Z'))
	{
		StateChange(EKnightState::Airborne);
		return;
	}

	if (!IsLanded)
	{
		StateChange(EKnightState::Fall);
		return;
	}

	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		int Random = UEngineRandom::MainRandom.RandomInt(0, 1);
		if (Random == 0)
		{
			StateChange(EKnightState::Slash);
			return;
		}
		else
		{
			StateChange(EKnightState::SlashAlt);
			return;
		}
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		StateChange(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			StateChange(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		StateChange(EKnightState::FireballAntic);
		return;
	}
}

void AKnight::Walk(float _DeltaTime)
{
	if (UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		StateChange(EKnightState::RunToIdle);
		return;
	}

	if (UEngineInput::IsPress(VK_LEFT) && UEngineInput::IsPress(VK_RIGHT))
	{
		StateChange(EKnightState::RunToIdle);
		return;
	}

	if (UEngineInput::IsDown('z') ||
		UEngineInput::IsDown('Z'))
	{
		StateChange(EKnightState::Airborne);
		return;
	}

	if (!IsLanded)
	{
		StateChange(EKnightState::Fall);
		return;
	}

	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		int Random = UEngineRandom::MainRandom.RandomInt(0, 1);
		if (Random == 0)
		{
			StateChange(EKnightState::Slash);
			return;
		}
		else
		{
			StateChange(EKnightState::SlashAlt);
			return;
		}
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		StateChange(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			StateChange(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		StateChange(EKnightState::FireballAntic);
		return;
	}
}

void AKnight::RunToIdle(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::Turn(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::Airborne(float _DeltaTime)
{
	if (UEngineInput::IsUp('Z') ||
		UEngineInput::IsUp('z'))
	{
		StateChange(EKnightState::Fall);
		return;
	}


	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		if (UEngineInput::IsPress(VK_UP))
		{
			StateChange(EKnightState::UpSlash);
			return;
		}
		else if (UEngineInput::IsPress(VK_DOWN))
		{
			StateChange(EKnightState::DownSlash);
			return;
		}
		else
		{
			int Random = UEngineRandom::MainRandom.RandomInt(0, 1);
			if (Random == 0)
			{
				StateChange(EKnightState::Slash);
				return;
			}
			else
			{
				StateChange(EKnightState::SlashAlt);
				return;
			}
		}
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		StateChange(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			StateChange(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		StateChange(EKnightState::FireballAntic);
		return;
	}
}

void AKnight::Fall(float _DeltaTime)
{
	if (IsLanded)
	{
		StateChange(EKnightState::Land);
		return;
	}

	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		if (UEngineInput::IsPress(VK_UP))
		{
			StateChange(EKnightState::UpSlash);
			return;
		}
		else if (UEngineInput::IsPress(VK_DOWN))
		{
			StateChange(EKnightState::DownSlash);
			return;
		}
		else
		{
			int Random = UEngineRandom::MainRandom.RandomInt(0, 1);
			if (Random == 0)
			{
				StateChange(EKnightState::Slash);
				return;
			}
			else
			{
				StateChange(EKnightState::SlashAlt);
				return;
			}
		}
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		StateChange(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			StateChange(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		StateChange(EKnightState::FireballAntic);
		return;
	}
}

void AKnight::Land(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::HardLand(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::Slash(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::SlashAlt(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::UpSlash(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::DownSlash(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::Dash(float _DeltaTime)
{
	AccDash += _DeltaTime;
	if (AccDash > DashTime)
	{
		AccDash = 0.f;
		StateChange(EKnightState::DashToIdle);
		return;
	}
	AddActorLocation(Dir * DashSpeed * _DeltaTime);
}

void AKnight::DashToIdle(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::WallSlide(float _DeltaTime)
{
}

void AKnight::WallJump(float _DeltaTime)
{
}

void AKnight::Sit(float _DeltaTime)
{
}

void AKnight::SitOff(float _DeltaTime)
{
}

void AKnight::MapOpen(float _DeltaTime)
{
}

void AKnight::MapIdle(float _DeltaTime)
{
}

void AKnight::MapWalk(float _DeltaTime)
{
}

void AKnight::MapAway(float _DeltaTime)
{
}

void AKnight::MapTurn(float _DeltaTime)
{
}

void AKnight::SitMapOpen(float _DeltaTime)
{
}

void AKnight::SitMapClose(float _DeltaTime)
{
}

void AKnight::MapUpdate(float _DeltaTime)
{
}

void AKnight::Focus(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::FocusGet);
	return;
}

void AKnight::FocusGet(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::FocusEnd);
	return;
}

void AKnight::FocusEnd(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::CollectMagical1(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::CollectMagical2);
	return;
}

void AKnight::CollectMagical2(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::CollectMagical3);
	return;
}

void AKnight::CollectMagical3(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::CollectNormal1(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::CollectNormal2);
	return;
}

void AKnight::CollectNormal2(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::CollectNormal3);
	return;
}

void AKnight::CollectNormal3(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::Enter(float _DeltaTime)
{
}

void AKnight::Prostrate(float _DeltaTime)
{
}

void AKnight::ProstrateRise(float _DeltaTime)
{
}

void AKnight::FireballAntic(float _DeltaTime)
{
	//if(Renderer->IsCurAnimationEnd())
	StateChange(EKnightState::FireballCast);
	return;
}

void AKnight::FireballCast(float _DeltaTime)
{
	//if(Renderer->IsCurAniamtionEnd())
	StateChange(EKnightState::Idle);
	return;
}

void AKnight::Recoil(float _DeltaTime)
{
}

void AKnight::Death(float _DeltaTime)
{
}

void AKnight::NoneStart()
{
}

void AKnight::IdleStart()
{
	Renderer->ChangeAnimation("Idle");
	return;
}

void AKnight::LookUpStart()
{
	Renderer->ChangeAnimation("LookUp");
	return;
}

void AKnight::LookUpToIdleStart()
{
	Renderer->ChangeAnimation("LookUpToIdle");
	return;
}

void AKnight::LookDownStart()
{
	Renderer->ChangeAnimation("LookDown");
	return;
}

void AKnight::LookDownToIdleStart()
{
	Renderer->ChangeAnimation("LookDownToIdle");
	return;
}

void AKnight::RunStart()
{
	Renderer->ChangeAnimation("Run");
	return;
}

void AKnight::WalkStart()
{
	Renderer->ChangeAnimation("Walk");
	return;
}

void AKnight::RunToIdleStart()
{
	Renderer->ChangeAnimation("RunToIdle");
	return;
}

void AKnight::TurnStart()
{
	Renderer->ChangeAnimation("Turn");
	return;
}

void AKnight::AirborneStart()
{
	Renderer->ChangeAnimation("Airborne");
	return;
}

void AKnight::FallStart()
{
	Renderer->ChangeAnimation("Fall");
	return;
}

void AKnight::LandStart()
{
	Renderer->ChangeAnimation("Land");
	return;
}

void AKnight::HardLandStart()
{
	Renderer->ChangeAnimation("HardLand");
	return;
}

void AKnight::SlashStart()
{
	Renderer->ChangeAnimation("Slash");
	return;
}

void AKnight::SlashAltStart()
{
	Renderer->ChangeAnimation("SlashAlt");
	return;
}

void AKnight::UpSlashStart()
{
	Renderer->ChangeAnimation("UpSlash");
	return;
}

void AKnight::DownSlashStart()
{
	Renderer->ChangeAnimation("DownSlash");
	return;
}

void AKnight::DashStart()
{
	ManupulateOff();
	AirborneReset();
	Renderer->ChangeAnimation("Dash");
	return;
}

void AKnight::DashToIdleStart()
{
	ManupulateOn();
	Renderer->ChangeAnimation("DashToIdle");
	return;
}

void AKnight::WallSlideStart()
{
	Renderer->ChangeAnimation("WallSlide");
	return;
}

void AKnight::WallJumpStart()
{
	Renderer->ChangeAnimation("WallJump");
	return;
}

void AKnight::SitStart()
{
	Renderer->ChangeAnimation("Sit");
	return;
}

void AKnight::SitOffStart()
{
	Renderer->ChangeAnimation("SitOff");
	return;
}

void AKnight::MapOpenStart()
{
	Renderer->ChangeAnimation("MapOpen");
	return;
}

void AKnight::MapIdleStart()
{
	Renderer->ChangeAnimation("MapIdle");
	return;
}

void AKnight::MapWalkStart()
{
	Renderer->ChangeAnimation("MapWalk");
	return;
}

void AKnight::MapAwayStart()
{
	Renderer->ChangeAnimation("MapAway");
	return;
}

void AKnight::MapTurnStart()
{
	Renderer->ChangeAnimation("MapTurn");
	return;
}

void AKnight::SitMapOpenStart()
{
	Renderer->ChangeAnimation("SitMapOpen");
	return;
}

void AKnight::SitMapCloseStart()
{
	Renderer->ChangeAnimation("SitMapClose");
	return;
}

void AKnight::MapUpdateStart()
{
	Renderer->ChangeAnimation("MapUpdate");
	return;
}

void AKnight::FocusStart()
{
	Renderer->ChangeAnimation("Focus");
	return;
}

void AKnight::FocusGetStart()
{
	Renderer->ChangeAnimation("FocusGet");
	return;
}

void AKnight::FocusEndStart()
{
	Renderer->ChangeAnimation("FocusEnd");
	return;
}

void AKnight::CollectMagical1Start()
{
	Renderer->ChangeAnimation("CollectMagical1");
	return;
}

void AKnight::CollectMagical2Start()
{
	Renderer->ChangeAnimation("CollectMagical2");
	return;
}

void AKnight::CollectMagical3Start()
{
	Renderer->ChangeAnimation("CollectMagical3");
	return;
}

void AKnight::CollectNormal1Start()
{
	Renderer->ChangeAnimation("CollectNormal1");
	return;
}

void AKnight::CollectNormal2Start()
{
	Renderer->ChangeAnimation("CollectNormal2");
	return;
}

void AKnight::CollectNormal3Start()
{
	Renderer->ChangeAnimation("CollectNormal3");
	return;
}

void AKnight::EnterStart()
{
	Renderer->ChangeAnimation("Enter");
	return;
}

void AKnight::ProstrateStart()
{
	Renderer->ChangeAnimation("Prostrate");
	return;
}

void AKnight::ProstrateRiseStart()
{
	Renderer->ChangeAnimation("ProstrateRise");
	return;
}

void AKnight::FireballAnticStart()
{
	Renderer->ChangeAnimation("FireballAntic");
	return;
}

void AKnight::FireballCastStart()
{
	Renderer->ChangeAnimation("FireballCast");
	return;
}

void AKnight::RecoilStart()
{
	Renderer->ChangeAnimation("Recoil");
	return;
}

void AKnight::DeathStart()
{
	Renderer->ChangeAnimation("Death");
	return;
}