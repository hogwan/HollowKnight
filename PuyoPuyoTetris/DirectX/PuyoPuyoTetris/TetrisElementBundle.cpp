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

	switch (type)
	{
	case BundleType::Null:

	}

}

void ATetrisElementBundle::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

