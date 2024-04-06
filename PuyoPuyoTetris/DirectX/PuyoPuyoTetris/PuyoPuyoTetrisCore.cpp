#include "PreCompile.h"
#include "PuyoPuyoTetrisCore.h"
#include "PlayGameMode.h"
#include <EngineCore/EngineSprite.h>

UPuyoPuyoTetrisCore::UPuyoPuyoTetrisCore()
{
}

UPuyoPuyoTetrisCore::~UPuyoPuyoTetrisCore()
{
}

void UPuyoPuyoTetrisCore::Initialize()
{
	{
		// 파일의 헤더
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("PPT_Resource");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}

	}


	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("PPT_Resource");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
		for (UEngineFile& File : Files)
		{
			UEngineSound::Load(File.GetFullPath());
		}
	}

	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");

}
