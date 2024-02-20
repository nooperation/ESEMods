#pragma once

#include <Units/Units.h>
#include <UNIT/SUnitDmg.h>


#pragma pack(push, 1)
struct D2AuraCallbackStrc;
struct D2MissilesTxt;

struct D2MissileUnitFindArgStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    D2MissilesTxt* pMissilesTxtRecord;
};

using MissileUnitFindFunc = int32_t(__fastcall*)(D2UnitStrc*, void*);
struct D2MissileUnitFindTableStrc
{
    MissileUnitFindFunc pfUnitFindCallback;
    int32_t nCollisionMask;
};
#pragma pack(pop)
