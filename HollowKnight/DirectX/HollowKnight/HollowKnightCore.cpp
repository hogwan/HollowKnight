#include "PreCompile.h"
#include "HollowKnightCore.h"
#include "PlayGameMode.h"
#include <EngineCore/EngineSprite.h>
UHollowKnightCore::UHollowKnightCore()
{
}

UHollowKnightCore::~UHollowKnightCore()
{
	
}

void UHollowKnightCore::Initialize()
{
	{
		// 파일의 헤더
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("HN_Resources");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		// 로드폴더는 이렇게 한다고 칩시다.
		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}
	}


	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("HN_Resources");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
		for (UEngineFile& File : Files)
		{

			UEngineSound::Load(File.GetFullPath());
		}
	}

	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");
}
