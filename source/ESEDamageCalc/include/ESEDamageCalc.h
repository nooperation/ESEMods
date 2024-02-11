#pragma once

#include <chrono>
#include <thread>
#include <type_traits>
#include <cstdlib>

#include "ESEDamageCalc.h"
#include <GAME/Game.h>
#include <UNIT/SUnitDmg.h>
#include <MONSTER/MonsterUnique.h>
#include <MONSTER/MonsterMode.h>

extern decltype(&SUNITDMG_AllocCombat) SUNITDMG_AllocCombat_Original;
void __fastcall SUNITDMG_AllocCombat_ESEDamageCalc(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, uint8_t nSrcDam);
static_assert(std::is_same_v<decltype(&SUNITDMG_AllocCombat), decltype(&SUNITDMG_AllocCombat_ESEDamageCalc)>, "SUNITDMG_AllocCombat_ESEDamageCalc has a different type than previously known.");

extern decltype(&SUNITDMG_CalculateTotalDamage) SUNITDMG_CalculateTotalDamage_Original;
void __fastcall SUNITDMG_CalculateTotalDamage_ESEDamageCalc(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_CalculateTotalDamage), decltype(&SUNITDMG_CalculateTotalDamage_ESEDamageCalc)>, "SUNITDMG_CalculateTotalDamage_ESEDamageCalc has a different type than previously known.");

extern decltype(&SUNITDMG_ExecuteEvents) SUNITDMG_ExecuteEvents_Original;
void __fastcall SUNITDMG_ExecuteEvents_ESEDamageCalc(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bMissile, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_ExecuteEvents), decltype(&SUNITDMG_ExecuteEvents_ESEDamageCalc)>, "SUNITDMG_ExecuteEvents_ESEDamageCalc has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CalculatePercentage) MONSTERUNIQUE_CalculatePercentage_Original;
int32_t __fastcall MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(int32_t a1, int32_t a2, int32_t a3);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CalculatePercentage), decltype(&MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc)>, "MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc has a different type than previously known.");

#pragma pack(push, 1)
struct DamageReportPacket
{
    uint8_t packetId;
    uint8_t unknownA;
    uint8_t unknownB;
    uint8_t unknownC;
    uint32_t unitId;
    uint32_t damage;
    uint8_t unknownD;
};
#pragma pack(pop)
