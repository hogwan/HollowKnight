#include "PreCompile.h"
#include "KatanaZeroCore.h"
#include "Factory_0.h"
#include "Factory_1.h"
#include "Factory_2.h"
#include "Factory_3.h"
#include <EngineCore/EngineSprite.h>

KatanaZeroCore::KatanaZeroCore() 
{
}

KatanaZeroCore::~KatanaZeroCore() 
{
}

void KatanaZeroCore::Initialize()
{
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("KZ_Resources");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			UEngineSprite::Load(File.GetFullPath());
		}
	}

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("KZ_Resources");
		Dir.Move("Player");

		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}
	}

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("KZ_Resources");
		Dir.Move("FX");

		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}
	}

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("KZ_Resources");
		Dir.Move("Enemy");

		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}
	}

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("KZ_Resources");
		Dir.Move("Object");

		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}
	}


	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("KZ_Resources");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
		for (UEngineFile& File : Files)
		{
			UEngineSound::Load(File.GetFullPath());
		}
	}

	GEngine->CreateLevel<AFactory_0>("Factory_0");
	GEngine->CreateLevel<AFactory_1>("Factory_1");
	GEngine->CreateLevel<AFactory_2>("Factory_2");
	GEngine->CreateLevel<AFactory_3>("Factory_3");

	GEngine->ChangeLevel("Factory_0");
}

