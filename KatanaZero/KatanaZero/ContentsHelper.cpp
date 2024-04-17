#include "PreCompile.h"
#include "ContentsHelper.h"
#include "Player.h"
#include "BackGroundMap.h"
#include "Cursor.h"

std::shared_ptr<UEngineTexture> UConstValue::MapTex;
float4 UConstValue::MapTexScale;
std::shared_ptr<APlayer> UConstValue::Player;
std::shared_ptr<ACursor> UConstValue::MainCursor;
std::vector<FVector> UConstValue::LayerChangePos;
float UConstValue::Ratio = 1.0f;