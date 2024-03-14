#pragma once

#include <../D2MooHeaders.h>
#include <cstdlib>

#pragma pack(push, 1)
struct DamageRangeValue
{
    int32_t minDamage;
    int32_t maxDamage;
    int32_t length;
    int32_t count;
    bool bHasMinAndMaxDamage;
    bool bHasBeenHandled;
};
#pragma pack(pop)

enum DamageRangeValueIndex
{
    DAMAGE_RANGE_PHYSICAL,
    DAMAGE_RANGE_PHYSICALPERCENT,
    DAMAGE_RANGE_COLD,
    DAMAGE_RANGE_LIGHTNING,
    DAMAGE_RANGE_FIRE,
    DAMAGE_RANGE_POISON,
    DAMAGE_RANGE_MAGIC,
    DAMAGE_RANGE_MAX
};

//D2Client.0x6FAE1890 (41890)
void __fastcall ESE_UI_INV_DrawMouseOverItemFrame(D2UnitStrc* pUnit, int32_t bFlag);
