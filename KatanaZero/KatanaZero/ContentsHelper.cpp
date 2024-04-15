#include "PreCompile.h"
#include "ContentsHelper.h"
#include "Player.h"
#include "CameraManager.h"
#include "BackGroundMap.h"
#include "Cursor.h"
#include "EnemyLayerChangeCol.h"

std::shared_ptr<UEngineTexture> UConstValue::MapTex;
float4 UConstValue::MapTexScale;
std::shared_ptr<APlayer> UConstValue::Player;
std::shared_ptr<ACameraManager> UConstValue::MainCameraManager;
std::shared_ptr<ABackGroundMap> UConstValue::BackMap;
std::shared_ptr<ACursor> UConstValue::MainCursor;
std::vector<FVector> UConstValue::EnemyLayerChangeCols;
float UConstValue::Ratio = 0.8f;