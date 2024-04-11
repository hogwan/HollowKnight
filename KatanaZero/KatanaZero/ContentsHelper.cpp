#include "PreCompile.h"
#include "ContentsHelper.h"
#include "Player.h"
#include "CameraManager.h"
#include "BackGroundMap.h"
#include "Cursor.h"

std::shared_ptr<UEngineTexture> UConstValue::MapTex;
float4 UConstValue::MapTexScale;
std::shared_ptr<Player> UConstValue::MainCharacter;
std::shared_ptr<CameraManager> UConstValue::MainCameraManager;
std::shared_ptr<BackGroundMap> UConstValue::BackMap;
std::shared_ptr<Cursor> UConstValue::MainCursor;
float UConstValue::Ratio = 1.0f;