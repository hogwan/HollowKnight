#include "PreCompile.h"
#include "TetrisElementBundle.h"

ATetrisElementBundle::ATetrisElementBundle() 
{
}

ATetrisElementBundle::~ATetrisElementBundle() 
{
}

void ATetrisElementBundle::BeginPlay()
{
	Super::BeginPlay();
	
	BundleType type = static_cast<BundleType>(rand() % 8);

	/*Null,
		Tetris,
		L1,
		L2,
		Key1,
		Key2,
		Square,
		T,
};*/
	switch (type)
	{
	case BundleType::Null:
		break;
	case BundleType::Tetris:
		break;
	case BundleType::L1:
		break;
	case BundleType::L2:
		break;
	case BundleType::Key1:
		break;
	case BundleType::Key2:
		break;
	case BundleType::Square:
		break;
	case BundleType::T:
		break;
	default:
		break;
	}

}

void ATetrisElementBundle::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

