#include "Knight.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineRandom.h>

Knight::Knight()
{
}

Knight::~Knight()
{
}



void Knight::BeginPlay()
{
}

void Knight::Tick(float _DeltaTime)
{
	if (Manupulate)
	{
		ManupulateUpdate(_DeltaTime);
	}

	StateUpdate(_DeltaTime);
}

void Knight::ManupulateUpdate(float _DeltaTime)
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

		}
	}
}

void Knight::ChangeState(EKnightState _State)
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
		case EKnightState::RunToIdle:
			RunToIdleStart();
			break;
		case EKnightState::Turn:
			TurnStart();
			break;
		case EKnightState::TurnToIdle:
			TurnToIdleStart();
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

void Knight::StateUpdate(float _DeltaTime)
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
	case EKnightState::RunToIdle:
		RunToIdle(_DeltaTime);
		break;
	case EKnightState::Turn:
		Turn(_DeltaTime);
		break;
	case EKnightState::TurnToIdle:
		TurnToIdle(_DeltaTime);
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

void Knight::None(float _DeltaTime)
{
	ChangeState(EKnightState::Idle);
	return;
}

void Knight::Idle(float _DeltaTime)
{
	if (UEngineInput::IsPress(VK_RIGHT)
		|| UEngineInput::IsPress(VK_LEFT))
	{
		ChangeState(EKnightState::Run);
		return;
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		ChangeState(EKnightState::LookUp);
		return;
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		ChangeState(EKnightState::LookDown);
		return;
	}

	if (UEngineInput::IsDown('z') ||
		UEngineInput::IsDown('Z'))
	{
		ChangeState(EKnightState::Airborne);
		return;
	}

	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		int Random = UEngineRandom::MainRandom.RandomInt(0,1);
		if (Random == 0)
		{
			ChangeState(EKnightState::Slash);
			return;
		}
		else
		{
			ChangeState(EKnightState::SlashAlt);
			return;
		}
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		ChangeState(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			ChangeState(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		ChangeState(EKnightState::FireballAntic);
		return;
	}
}

void Knight::LookUp(float _DeltaTime)
{
	if (UEngineInput::IsFree(VK_UP))
	{
		ChangeState(EKnightState::LookUpToIdle);
		return;
	}

	if (UEngineInput::IsPress(VK_RIGHT)
		|| UEngineInput::IsPress(VK_LEFT))
	{
		ChangeState(EKnightState::Run);
		return;
	}

	if (UEngineInput::IsDown('z') ||
		UEngineInput::IsDown('Z'))
	{
		ChangeState(EKnightState::Airborne);
		return;
	}

	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		int Random = UEngineRandom::MainRandom.RandomInt(0, 1);
		if (Random == 0)
		{
			ChangeState(EKnightState::Slash);
			return;
		}
		else
		{
			ChangeState(EKnightState::SlashAlt);
			return;
		}
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		ChangeState(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			ChangeState(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		ChangeState(EKnightState::FireballAntic);
		return;
	}
}

void Knight::LookUpToIdle(float _DeltaTime)
{
	ChangeState(EKnightState::Idle);
	return;
}

void Knight::LookDown(float _DeltaTime)
{
	if (UEngineInput::IsFree(VK_DOWN))
	{
		ChangeState(EKnightState::LookDownToIdle);
		return;
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		ChangeState(EKnightState::LookUp);
		return;
	}

	if (UEngineInput::IsPress(VK_RIGHT)
		|| UEngineInput::IsPress(VK_LEFT))
	{
		ChangeState(EKnightState::Run);
		return;
	}

	if (UEngineInput::IsDown('z') ||
		UEngineInput::IsDown('Z'))
	{
		ChangeState(EKnightState::Airborne);
		return;
	}

	if (UEngineInput::IsDown('x') ||
		UEngineInput::IsDown('X'))
	{
		int Random = UEngineRandom::MainRandom.RandomInt(0, 1);
		if (Random == 0)
		{
			ChangeState(EKnightState::Slash);
			return;
		}
		else
		{
			ChangeState(EKnightState::SlashAlt);
			return;
		}
	}

	if (UEngineInput::IsDown('c') ||
		UEngineInput::IsDown('C'))
	{
		ChangeState(EKnightState::Dash);
		return;
	}

	if (UEngineInput::IsPress('a') ||
		UEngineInput::IsPress('A'))
	{
		PressTime += _DeltaTime;
		if (PressTime > FocusTime)
		{
			PressTime = 0.f;
			ChangeState(EKnightState::Focus);
			return;
		}
	}

	if (UEngineInput::IsUp('a') ||
		UEngineInput::IsUp('A'))
	{
		PressTime = 0.f;
		ChangeState(EKnightState::FireballAntic);
		return;
	}
}

void Knight::LookDownToIdle(float _DeltaTime)
{
	ChangeState(EKnightState::Idle);
	return;
}

void Knight::Run(float _DeltaTime)
{
	
}

void Knight::RunToIdle(float _DeltaTime)
{
}

void Knight::Turn(float _DeltaTime)
{
}

void Knight::TurnToIdle(float _DeltaTime)
{
}

void Knight::Airborne(float _DeltaTime)
{
}

void Knight::Fall(float _DeltaTime)
{
}

void Knight::Land(float _DeltaTime)
{
}

void Knight::HardLand(float _DeltaTime)
{
}

void Knight::Slash(float _DeltaTime)
{
}

void Knight::SlashAlt(float _DeltaTime)
{
}

void Knight::UpSlash(float _DeltaTime)
{
}

void Knight::DownSlash(float _DeltaTime)
{
}

void Knight::Dash(float _DeltaTime)
{
}

void Knight::DashToIdle(float _DeltaTime)
{
}

void Knight::WallSlide(float _DeltaTime)
{
}

void Knight::WallJump(float _DeltaTime)
{
}

void Knight::Sit(float _DeltaTime)
{
}

void Knight::SitOff(float _DeltaTime)
{
}

void Knight::MapOpen(float _DeltaTime)
{
}

void Knight::MapIdle(float _DeltaTime)
{
}

void Knight::MapWalk(float _DeltaTime)
{
}

void Knight::MapAway(float _DeltaTime)
{
}

void Knight::MapTurn(float _DeltaTime)
{
}

void Knight::SitMapOpen(float _DeltaTime)
{
}

void Knight::SitMapClose(float _DeltaTime)
{
}

void Knight::MapUpdate(float _DeltaTime)
{
}

void Knight::Focus(float _DeltaTime)
{
}

void Knight::FocusGet(float _DeltaTime)
{
}

void Knight::FocusEnd(float _DeltaTime)
{
}

void Knight::CollectMagical1(float _DeltaTime)
{
}

void Knight::CollectMagical2(float _DeltaTime)
{
}

void Knight::CollectMagical3(float _DeltaTime)
{
}

void Knight::CollectNormal1(float _DeltaTime)
{
}

void Knight::CollectNormal2(float _DeltaTime)
{
}

void Knight::CollectNormal3(float _DeltaTime)
{
}

void Knight::Enter(float _DeltaTime)
{
}

void Knight::Prostrate(float _DeltaTime)
{
}

void Knight::ProstrateRise(float _DeltaTime)
{
}

void Knight::FireballAntic(float _DeltaTime)
{
}

void Knight::FireballCast(float _DeltaTime)
{
}

void Knight::Recoil(float _DeltaTime)
{
}

void Knight::Death(float _DeltaTime)
{
}

void Knight::NoneStart()
{
}

void Knight::IdleStart()
{
}

void Knight::LookUpStart()
{
}

void Knight::LookUpToIdleStart()
{
}

void Knight::LookDownStart()
{
}

void Knight::LookDownToIdleStart()
{
}

void Knight::RunStart()
{
}

void Knight::RunToIdleStart()
{
}

void Knight::TurnStart()
{
}

void Knight::TurnToIdleStart()
{
}

void Knight::AirborneStart()
{
}

void Knight::FallStart()
{
}

void Knight::LandStart()
{
}

void Knight::HardLandStart()
{
}

void Knight::SlashStart()
{
}

void Knight::SlashAltStart()
{
}

void Knight::UpSlashStart()
{
}

void Knight::DownSlashStart()
{
}

void Knight::DashStart()
{
}

void Knight::DashToIdleStart()
{
}

void Knight::WallSlideStart()
{
}

void Knight::WallJumpStart()
{
}

void Knight::SitStart()
{
}

void Knight::SitOffStart()
{
}

void Knight::MapOpenStart()
{
}

void Knight::MapIdleStart()
{
}

void Knight::MapWalkStart()
{
}

void Knight::MapAwayStart()
{
}

void Knight::MapTurnStart()
{
}

void Knight::SitMapOpenStart()
{
}

void Knight::SitMapCloseStart()
{
}

void Knight::MapUpdateStart()
{
}

void Knight::FocusStart()
{
}

void Knight::FocusGetStart()
{
}

void Knight::FocusEndStart()
{
}

void Knight::CollectMagical1Start()
{
}

void Knight::CollectMagical2Start()
{
}

void Knight::CollectMagical3Start()
{
}

void Knight::CollectNormal1Start()
{
}

void Knight::CollectNormal2Start()
{
}

void Knight::CollectNormal3Start()
{
}

void Knight::EnterStart()
{
}

void Knight::ProstrateStart()
{
}

void Knight::ProstrateRiseStart()
{
}

void Knight::FireballAnticStart()
{
}

void Knight::FireballCastStart()
{
}

void Knight::RecoilStart()
{
}

void Knight::DeathStart()
{
}