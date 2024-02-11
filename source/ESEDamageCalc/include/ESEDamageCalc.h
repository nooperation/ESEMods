#pragma once

#include <chrono>
#include <thread>
#include <type_traits>
#include <cstdlib>

#include <D2Skills.h>
#include <SKILLS/Skills.h>
#include <GAME/Game.h>
#include <UNIT/SUnitDmg.h>
#include <MONSTER/MonsterUnique.h>
#include <MONSTER/MonsterMode.h>
#include <MISSILES/MissMode.h>

extern decltype(&SKILLS_GetMinPhysDamage) SKILLS_GetMinPhysDamage_Original;
int __stdcall SKILLS_GetMinPhysDamage_ESEDamageCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
static_assert(std::is_same_v<decltype(&SKILLS_GetMinPhysDamage), decltype(&SKILLS_GetMinPhysDamage_ESEDamageCalc)>, "SKILLS_GetMinPhysDamage_ESEDamageCalc has a different type than previously known.");

extern decltype(&SKILLS_GetMaxPhysDamage) SKILLS_GetMaxPhysDamage_Original;
int __stdcall SKILLS_GetMaxPhysDamage_ESEDamageCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
static_assert(std::is_same_v<decltype(&SKILLS_GetMaxPhysDamage), decltype(&SKILLS_GetMaxPhysDamage_ESEDamageCalc)>, "SKILLS_GetMaxPhysDamage_ESEDamageCalc has a different type than previously known.");

extern decltype(&SKILLS_GetMinElemDamage) SKILLS_GetMinElemDamage_Original;
int __stdcall SKILLS_GetMinElemDamage_ESEDamageCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
static_assert(std::is_same_v<decltype(&SKILLS_GetMinElemDamage), decltype(&SKILLS_GetMinElemDamage_ESEDamageCalc)>, "SKILLS_GetMinElemDamage_ESEDamageCalc has a different type than previously known.");

extern decltype(&SKILLS_GetMaxElemDamage) SKILLS_GetMaxElemDamage_Original;
int __stdcall SKILLS_GetMaxElemDamage_ESEDamageCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
static_assert(std::is_same_v<decltype(&SKILLS_GetMaxElemDamage), decltype(&SKILLS_GetMaxElemDamage_ESEDamageCalc)>, "SKILLS_GetMaxElemDamage_ESEDamageCalc has a different type than previously known.");



extern decltype(&D2GAME_RollPhysicalDamage_6FD14EC0) D2GAME_RollPhysicalDamage_6FD14EC0_Original;
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0_ESEDamageCalc(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&D2GAME_RollPhysicalDamage_6FD14EC0), decltype(&D2GAME_RollPhysicalDamage_6FD14EC0_ESEDamageCalc)>, "D2GAME_RollPhysicalDamage_6FD14EC0_ESEDamageCalc has a different type than previously known.");

extern decltype(&D2GAME_RollElementalDamage_6FD14DD0) D2GAME_RollElementalDamage_6FD14DD0_Original;
int32_t __fastcall D2GAME_RollElementalDamage_6FD14DD0_ESEDamageCalc(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&D2GAME_RollElementalDamage_6FD14DD0), decltype(&D2GAME_RollElementalDamage_6FD14DD0_ESEDamageCalc)>, "D2GAME_RollElementalDamage_6FD14DD0_ESEDamageCalc has a different type than previously known.");

extern decltype(&SUNITDMG_RollDamageValueInRange) SUNITDMG_RollDamageValueInRange_Original;
int32_t __fastcall SUNITDMG_RollDamageValueInRange_ESEDamageCalc(D2UnitStrc* pUnit, int32_t nMinDamage, int32_t nMaxDamage, int32_t nMinDamageBonusPct, int32_t nMaxDamageBonusPct, int32_t nDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_RollDamageValueInRange), decltype(&SUNITDMG_RollDamageValueInRange_ESEDamageCalc)>, "SUNITDMG_RollDamageValueInRange_ESEDamageCalc has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyDamageBonuses) SUNITDMG_ApplyDamageBonuses_Original;
int32_t __fastcall SUNITDMG_ApplyDamageBonuses_ESEDamageCalc(D2UnitStrc* pUnit, int32_t bGetStats, D2UnitStrc* pItem, int32_t nMinDmg, int32_t nMaxDmg, int32_t nDamagePercent, int32_t nDamage, uint8_t nSrcDam);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyDamageBonuses), decltype(&SUNITDMG_ApplyDamageBonuses_ESEDamageCalc)>, "SUNITDMG_ApplyDamageBonuses_ESEDamageCalc has a different type than previously known.");

extern decltype(&MISSMODE_RollDamageValue) MISSMODE_RollDamageValue_Original;
int32_t __fastcall MISSMODE_RollDamageValue_ESEDamageCalc(D2UnitStrc* pUnit, int32_t nMinDamStat, int32_t nMaxDamStat, int32_t nMasteryStat);
static_assert(std::is_same_v<decltype(&MISSMODE_RollDamageValue), decltype(&MISSMODE_RollDamageValue_ESEDamageCalc)>, "MISSMODE_RollDamageValue_ESEDamageCalc has a different type than previously known.");

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

int64_t MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(int64_t nValue, int64_t nPercentage, int64_t divisor);
int64_t SUNITDMG_ApplyResistancesAndAbsorb_ESEDamageCalc_64(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb);
int64_t SUNITDMG_CalculateTotalDamage_ESEDamageCalc_64(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
int64_t SKILLS_CalculateMasteryBonus_ESEDamageCalc_64(D2UnitStrc* pUnit, int32_t nElemType, int64_t nSrcDamage);
