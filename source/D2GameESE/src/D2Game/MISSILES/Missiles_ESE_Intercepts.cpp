#include "D2Game/MISSILES/Missiles_ESE_Intercepts.h"

MISSILES_CreateMissileFromParams_t MISSILES_CreateMissileFromParams_Original = nullptr;

D2UnitStrc* __fastcall ESE_INTERCEPT_MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* missileParams)
{
    return ESE_MISSILES_CreateMissileFromParams(pGame, missileParams);
}
