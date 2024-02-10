#pragma once

#include <chrono>
#include <thread>
#include <type_traits>
#include <cstdlib>

#include "ESEGame.h"
#include <GAME/Game.h>
#include <UNIT/SUnitDmg.h>
#include <MONSTER/MonsterUnique.h>
#include <MONSTER/MonsterMode.h>

extern decltype(&SUNITDMG_ExecuteMissileDamage) SUNITDMG_ExecuteMissileDamage_Original;
void __fastcall SUNITDMG_ExecuteMissileDamage_ESEGame(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_ExecuteMissileDamage), decltype(&SUNITDMG_ExecuteMissileDamage_ESEGame)>, "SUNITDMG_ExecuteMissileDamage_ESEGame has a different type than previously known.");

extern decltype(&sub_6FC63FD0) sub_6FC63FD0_Original;
void __fastcall sub_6FC63FD0_ESEGame(D2GameStrc* pGame, D2UnitStrc* pAttacker);
static_assert(std::is_same_v<decltype(&sub_6FC63FD0), decltype(&sub_6FC63FD0_ESEGame)>, "sub_6FC63FD0_ESEGame has a different type than previously known.");

extern decltype(&SUNITDMG_AllocCombat) SUNITDMG_AllocCombat_Original;
void __fastcall SUNITDMG_AllocCombat_ESEGame(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, uint8_t nSrcDam);
static_assert(std::is_same_v<decltype(&SUNITDMG_AllocCombat), decltype(&SUNITDMG_AllocCombat_ESEGame)>, "SUNITDMG_AllocCombat_ESEGame has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyResistancesAndAbsorb) SUNITDMG_ApplyResistancesAndAbsorb_Original;
void __fastcall SUNITDMG_ApplyResistancesAndAbsorb_ESEGame(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyResistancesAndAbsorb), decltype(&SUNITDMG_ApplyResistancesAndAbsorb_ESEGame)>, "SUNITDMG_ApplyResistancesAndAbsorb_ESEGame has a different type than previously known.");

extern decltype(&SUNITDMG_CalculateTotalDamage) SUNITDMG_CalculateTotalDamage_Original;
void __fastcall SUNITDMG_CalculateTotalDamage_ESEGame(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_CalculateTotalDamage), decltype(&SUNITDMG_CalculateTotalDamage_ESEGame)>, "SUNITDMG_CalculateTotalDamage_ESEGame has a different type than previously known.");

extern decltype(&SUNITDMG_ExecuteEvents) SUNITDMG_ExecuteEvents_Original;
void __fastcall SUNITDMG_ExecuteEvents_ESEGame(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bMissile, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_ExecuteEvents), decltype(&SUNITDMG_ExecuteEvents_ESEGame)>, "SUNITDMG_ExecuteEvents_ESEGame has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CalculatePercentage) MONSTERUNIQUE_CalculatePercentage_Original;
int32_t __fastcall MONSTERUNIQUE_CalculatePercentage_ESEGame(int32_t a1, int32_t a2, int32_t a3);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CalculatePercentage), decltype(&MONSTERUNIQUE_CalculatePercentage_ESEGame)>, "MONSTERUNIQUE_CalculatePercentage_ESEGame has a different type than previously known.");
