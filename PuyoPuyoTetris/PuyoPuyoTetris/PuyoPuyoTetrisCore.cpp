#include "PreCompile.h"
#include "PuyoPuyoTetrisCore.h"
#include "PlayGameMode.h"

UPuyoPuyoTetrisCore::UPuyoPuyoTetrisCore()
{
}

UPuyoPuyoTetrisCore::~UPuyoPuyoTetrisCore()
{
}

void UPuyoPuyoTetrisCore::Initialize()
{
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");
}
