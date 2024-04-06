#pragma once

#define CreateKnightAnimation \
Renderer->CreateAnimation("Idle", "Idle", 0.08f,true);\
Renderer->CreateAnimation("LookUp", "LookUp", 0.08f,false);\
Renderer->CreateAnimation("LookUpToIdle", "LookUpToIdle", 0.08f,false);\
Renderer->CreateAnimation("LookDown", "LookDown", 0.08f,false);\
Renderer->CreateAnimation("LookDownToIdle", "LookDownToIdle", 0.08f, false);\
Renderer->CreateAnimation("Run", "Run", 0.08f, true);\
Renderer->CreateAnimation("RunToIdle", "RunToIdle", 0.08f, false);\
Renderer->CreateAnimation("Turn", "Turn", 0.08f, false);\
Renderer->CreateAnimation("TurnToIdle", "TurnToIdle", 0.08f,false);\
Renderer->CreateAnimation("Airborne", "Airborne", 0.08f,false);\
Renderer->CreateAnimation("Fall", "Fall", 0.08f, true);\
Renderer->CreateAnimation("Land", "Land", 0.08f,false);\
Renderer->CreateAnimation("HardLand", "HardLand", 0.08f,false);\
Renderer->CreateAnimation("Slash", "Slash", 0.08f,false);\
Renderer->CreateAnimation("SlashAlt", "SlashAlt", 0.08f, false);\
Renderer->CreateAnimation("UpSlash", "UpSlash", 0.08f, false);\
Renderer->CreateAnimation("DownSlash", "DownSlash", 0.08f, false);\
Renderer->CreateAnimation("Dash", "Dash", 0.08f, false);\
Renderer->CreateAnimation("WallSlide", "WallSlide", 0.08f, true);\
Renderer->CreateAnimation("WallJump", "WallJump", 0.08f, false);\
Renderer->CreateAnimation("Sit", "Sit", 0.08f, false);\
Renderer->CreateAnimation("SitOff", "SitOff", 0.08f, false);\
Renderer->CreateAnimation("MapOpen", "MapOpen", 0.08f, false);\
Renderer->CreateAnimation("MapIdle", "MapIdle", 0.08f, true);\
Renderer->CreateAnimation("MapWalk", "MapWalk", 0.08f, true);\
Renderer->CreateAnimation("MapAway", "MapAway", 0.08f, false);\
Renderer->CreateAnimation("MapTurn", "MapTurn", 0.08f, false);\
Renderer->CreateAnimation("SitMapOpen", "SitMapOpen", 0.08f, false);\
Renderer->CreateAnimation("SitMapClose", "SitMapClose", 0.08f, false);\
Renderer->CreateAnimation("MapUpdate", "MapUpdate", 0.08f, false);\
Renderer->CreateAnimation("Focus", "Focus", 0.08f, false);\
Renderer->CreateAnimation("FocusGet", "FocusGet", 0.08f, false);\
Renderer->CreateAnimation("FocusEnd", "FocusEnd", 0.08f, false);\
Renderer->CreateAnimation("CollectMagical1", "CollectMagical1", 0.08f, false);\
Renderer->CreateAnimation("CollectMagical2", "CollectMagical2", 0.08f, false);\
Renderer->CreateAnimation("CollectMagical3", "CollectMagical3", 0.08f, false);\
Renderer->CreateAnimation("CollectNormal1", "CollectNormal1", 0.08f, false);\
Renderer->CreateAnimation("CollectNormal2", "CollectNormal2", 0.08f, false);\
Renderer->CreateAnimation("CollectNormal3", "CollectNormal3", 0.08f, false);\
Renderer->CreateAnimation("Enter", "Enter", 0.08f, false);\
Renderer->CreateAnimation("Prostrate", "Prostrate", 0.08f, false);\
Renderer->CreateAnimation("ProstrateRise", "ProstrateRise", 0.08f, false);\
Renderer->CreateAnimation("FireballAntic", "FireballAntic", 0.08f, false);\
Renderer->CreateAnimation("FireballCast", "FireballCast", 0.08f, false);\
Renderer->CreateAnimation("Recoil", "Recoil", 0.08f, false);\
Renderer->CreateAnimation("Death", "Death", 0.08f, false);