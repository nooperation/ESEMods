#pragma once

#include <chrono>
#include <thread>
#include <type_traits>

#include "Foobar.h"
#include <GAME/Game.h>
#include <UNIT/SUnitDmg.h>
#include <MONSTER/MonsterUnique.h>

extern decltype(&SUNITDMG_CalculateTotalDamage) SUNITDMG_CalculateTotalDamage_Original;
void __fastcall SUNITDMG_CalculateTotalDamage_ESEGame(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_CalculateTotalDamage), decltype(&SUNITDMG_CalculateTotalDamage_ESEGame)>, "SUNITDMG_CalculateTotalDamage_ESEGame has a different type than previously known.");

extern decltype(&SUNITDMG_ExecuteEvents) SUNITDMG_ExecuteEvents_Original;
void __fastcall SUNITDMG_ExecuteEvents_ESEGame(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bMissile, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_ExecuteEvents), decltype(&SUNITDMG_ExecuteEvents_ESEGame)>, "SUNITDMG_ExecuteEvents_ESEGame has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CalculatePercentage) MONSTERUNIQUE_CalculatePercentage_Original;
int32_t __fastcall MONSTERUNIQUE_CalculatePercentage_ESEGame(int32_t a1, int32_t a2, int32_t a3);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CalculatePercentage), decltype(&MONSTERUNIQUE_CalculatePercentage_ESEGame)>, "MONSTERUNIQUE_CalculatePercentage_ESEGame has a different type than previously known.");
