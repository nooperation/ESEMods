#pragma once

#include "D2Game/MISSILES/Missiles_ESE.h"

#include <cstdlib>
#include <Units/Units.h>

//D2Game.0x6FC55360
D2UnitStrc* __fastcall ESE_INTERCEPT_MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* missileParams);

extern decltype(&MISSILES_CreateMissileFromParams) MISSILES_CreateMissileFromParams_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* missileParams);
