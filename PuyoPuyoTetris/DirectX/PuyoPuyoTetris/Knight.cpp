#include "PreCompile.h"
#include "Knight.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineRandom.h>

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

	SetActorScale3D(FVector(60.0f, 130.0f, 100.0f));

	Renderer->CreateAnimation("Idle", "Idle", 0.08f);
	Renderer->ChangeAnimation("Idle");

}

void AKnight::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	LandCheck();
	if (Manupulate)
	{
		ManupulateUpdate(_DeltaTime);
	}

	//StateUpdate(_DeltaTime);
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
			IsAirborneStart = true;
			AddActorLocation(FVector::Up * 5.f);
		}
		else
		{
			AirborneTime = 0.f;
			IsAirborneStart = false;
		}
	}
	else
	{
		if (IsAirborneStart)
		{
			if (UEngineInput::IsUp('z') ||
				UEngineInput::IsUp('Z'))
			{
				AirborneTime = 0.f;
				IsAirborneStart = false;
			}
			else if (UEngineInput::IsPress('Z')
				|| UEngineInput::IsPress('z'))
			{
				AirborneTime += _DeltaTime;
				AddActorLocation(FVector::Up * AirborneSpeed * _DeltaTime);
			}

			if (AirborneTime > AirborneLimit)
			{
				AirborneTime = 0.f;
				IsAirborneStart = false;
			}
		}
	}

	if (!IsAirborneStart && !IsLanded)
	{
		AddActorLocation(FVector::Down * AirborneSpeed * _DeltaTime);
	}
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

void AKnight::ChangeState(EKnightState _State)
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

void AKnight::None(float _DeltaTime)
{
	ChangeState(EKnightState::Idle);
	return;
}

void AKnight::Idle(float _DeltaTime)
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

	if (IsLanded)
	{
		ChangeState(EKnightState::Fall);
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

void AKnight::LookUp(float _DeltaTime)
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

	if (IsLanded)
	{
		ChangeState(EKnightState::Fall);
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

void AKnight::LookUpToIdle(float _DeltaTime)
{
	ChangeState(EKnightState::Idle);
	return;
}

void AKnight::LookDown(float _DeltaTime)
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

	if (IsLanded)
	{
		ChangeState(EKnightState::Fall);
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

void AKnight::LookDownToIdle(float _DeltaTime)
{
	ChangeState(EKnightState::Idle);
	return;
}

void AKnight::Run(float _DeltaTime)
{
	
}

void AKnight::RunToIdle(float _DeltaTime)
{
}

void AKnight::Turn(float _DeltaTime)
{
}

void AKnight::TurnToIdle(float _DeltaTime)
{
}

void AKnight::Airborne(float _DeltaTime)
{
}

void AKnight::Fall(float _DeltaTime)
{
}

void AKnight::Land(float _DeltaTime)
{
}

void AKnight::HardLand(float _DeltaTime)
{
}

void AKnight::Slash(float _DeltaTime)
{
}

void AKnight::SlashAlt(float _DeltaTime)
{
}

void AKnight::UpSlash(float _DeltaTime)
{
}

void AKnight::DownSlash(float _DeltaTime)
{
}

void AKnight::Dash(float _DeltaTime)
{
}

void AKnight::DashToIdle(float _DeltaTime)
{
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
}

void AKnight::FocusGet(float _DeltaTime)
{
}

void AKnight::FocusEnd(float _DeltaTime)
{
}

void AKnight::CollectMagical1(float _DeltaTime)
{
}

void AKnight::CollectMagical2(float _DeltaTime)
{
}

void AKnight::CollectMagical3(float _DeltaTime)
{
}

void AKnight::CollectNormal1(float _DeltaTime)
{
}

void AKnight::CollectNormal2(float _DeltaTime)
{
}

void AKnight::CollectNormal3(float _DeltaTime)
{
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
}

void AKnight::FireballCast(float _DeltaTime)
{
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
}

void AKnight::LookUpStart()
{
}

void AKnight::LookUpToIdleStart()
{
}

void AKnight::LookDownStart()
{
}

void AKnight::LookDownToIdleStart()
{
}

void AKnight::RunStart()
{
}

void AKnight::RunToIdleStart()
{
}

void AKnight::TurnStart()
{
}

void AKnight::TurnToIdleStart()
{
}

void AKnight::AirborneStart()
{
}

void AKnight::FallStart()
{
}

void AKnight::LandStart()
{
}

void AKnight::HardLandStart()
{
}

void AKnight::SlashStart()
{
}

void AKnight::SlashAltStart()
{
}

void AKnight::UpSlashStart()
{
}

void AKnight::DownSlashStart()
{
}

void AKnight::DashStart()
{
}

void AKnight::DashToIdleStart()
{
}

void AKnight::WallSlideStart()
{
}

void AKnight::WallJumpStart()
{
}

void AKnight::SitStart()
{
}

void AKnight::SitOffStart()
{
}

void AKnight::MapOpenStart()
{
}

void AKnight::MapIdleStart()
{
}

void AKnight::MapWalkStart()
{
}

void AKnight::MapAwayStart()
{
}

void AKnight::MapTurnStart()
{
}

void AKnight::SitMapOpenStart()
{
}

void AKnight::SitMapCloseStart()
{
}

void AKnight::MapUpdateStart()
{
}

void AKnight::FocusStart()
{
}

void AKnight::FocusGetStart()
{
}

void AKnight::FocusEndStart()
{
}

void AKnight::CollectMagical1Start()
{
}

void AKnight::CollectMagical2Start()
{
}

void AKnight::CollectMagical3Start()
{
}

void AKnight::CollectNormal1Start()
{
}

void AKnight::CollectNormal2Start()
{
}

void AKnight::CollectNormal3Start()
{
}

void AKnight::EnterStart()
{
}

void AKnight::ProstrateStart()
{
}

void AKnight::ProstrateRiseStart()
{
}

void AKnight::FireballAnticStart()
{
}

void AKnight::FireballCastStart()
{
}

void AKnight::RecoilStart()
{
}

void AKnight::DeathStart()
{
}