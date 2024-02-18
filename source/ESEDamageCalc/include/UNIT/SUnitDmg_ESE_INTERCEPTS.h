#pragma once

#include <UNIT/SUnitDmg_ESE.h>
#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <D2DataTbls.h>

//D2Game.0x6FCBE2F0
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_SetHitClass(D2DamageStrc* pDamage, uint32_t nHitClass);
//D2Game.0x6FCBE310
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBE360
void __fastcall ESE_INTERCEPT_SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);
//D2Game.0x6FCBE420
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int32_t bGetStats, D2UnitStrc* pItem, int32_t nMinDmg, int32_t nMaxDmg, int32_t nDamagePercent, int32_t nDamage, uint8_t nSrcDam);
//D2Game.0x6FCBE7E0
void __fastcall ESE_INTERCEPT_SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int32_t a5, uint8_t nSrcDam);
//D2Game.0x6FCBF400
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_CheckMonType(int32_t nMonType1, int32_t nMonType2);
//D2Game.0x6FCBF450
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_RollDamageValueInRange(D2UnitStrc* pUnit, int32_t nMinDamage, int32_t nMaxDamage, int32_t nMinDamageBonusPct, int32_t nMaxDamageBonusPct, int32_t nDamage);
//D2Game.0x6FCBF620
void __fastcall ESE_INTERCEPT_SUNITDMG_CalculateTotalDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
//D2Game.0x6FCBFB40
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyResistancesAndAbsorb(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb);
//D2Game.0x6FCBFE90
void __fastcall ESE_INTERCEPT_SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bMissile, D2DamageStrc* pDamage);
//D2Game.0x6FCC05D0
D2MonStatsTxt* __fastcall ESE_INTERCEPT_SUNITDMG_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit);
//D2Game.0x6FCC05F0
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_AddLeechedLife(D2UnitStrc* pUnit, int32_t nLifeLeeched);
//D2Game.0x6FCC0660
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_AddLeechedMana(D2UnitStrc* pUnit, int32_t nManaLeeched);
//D2Game.0x6FCC06C0
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyPoisonDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nPoisonDamage, int32_t nPoisonLength);
//D2Game.0x6FCC0800
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyBurnDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nBurnDamage, int32_t nBurnLength);
//D2Game.0x6FCC0940
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyColdState(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nColdLength);
//D2Game.0x6FCC0B90
void __fastcall ESE_INTERCEPT_SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);
//D2Game.0x6FCC0BE0
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyFreezeState(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nFreezeLength);
//D2Game.0x6FCC0E20
void __fastcall ESE_INTERCEPT_SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker);
//D2Game.0x6FCC0E90
void __fastcall ESE_INTERCEPT_SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender);
//D2Game.0x6FCC0F10
void __fastcall ESE_INTERCEPT_SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int32_t bPetKill);
//D2Game.0x6FCC1260
void __fastcall ESE_INTERCEPT_SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage);
//D2Game.0x6FCC1870
int32_t __fastcall ESE_INTERCEPT_sub_6FCC1870(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nHitClass);
//D2Game.0x6FCC1A50
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetHitClass(D2DamageStrc* pDamage, uint32_t nBaseHitClass);
//D2Game.0x6FCC1AC0
void __fastcall ESE_INTERCEPT_SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nUnused);
//D2Game.0x6FCC1D70
D2DamageStrc* __fastcall ESE_INTERCEPT_SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender);
//D2Game.0x6FCC1DC0
bool __stdcall ESE_INTERCEPT_D2Game_10033(D2UnitStrc* pUnit, int32_t* a2, int32_t* a3);
//D2Game.0x6FCC1E70
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nStatValue, int32_t bMissile);
//D2Game.0x6FCC2300
uint16_t __fastcall ESE_INTERCEPT_SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nStatValue, int32_t nRangeOffset);
//D2Game.0x6FCC2420
void __fastcall ESE_INTERCEPT_SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, uint8_t nSrcDam);
//D2Game.0x6FCC2530
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bAvoid, int32_t bBlock);
//D2Game.0x6FCC2610
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyDodge(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bAvoid);
//D2Game.0x6FCC2850
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetWeaponBlock(D2UnitStrc* pUnit);
//D2Game.0x6FCC2910
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nSize, D2DamageStrc* pDamage, int32_t a7, int32_t a8, int32_t(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int32_t a10);
//D2Game.0x6FCC2BC0
void __fastcall ESE_INTERCEPT_SUNITDMG_RollDamage(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage);
//D2Game.0x6FCC2BF0
void __fastcall ESE_INTERCEPT_SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage);
//D2Game.0x6FCC2C70
void __fastcall ESE_INTERCEPT_SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender);
//D2Game.0x6FCC2EC0
uint32_t __fastcall ESE_INTERCEPT_SUNITDMG_ComputeExperienceGain(D2GameStrc* pGame, D2UnitStrc* pAttacker, uint32_t nAttackerLevel, uint32_t nDefenderLevel, uint32_t nDefenderExperience);
//D2Game.0x6FCC3170
void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperienceForPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nOldLevel, uint32_t nExperienceGained);
//D2Game.0x6FCC3200
void __fastcall ESE_INTERCEPT_SUNITDMG_PartyCallback_ComputePartyExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);
//D2Game.0x6FCC3360
void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperienceForHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pHireling, uint32_t nLevel, uint32_t nExperienceBonus);
//D2Game.0x6FCC34A0
void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nExperienceBonus);
//D2Game.0x6FCC3510
void __fastcall ESE_INTERCEPT_SUNITDMG_SetExperienceForTargetLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nTargetLevel);

extern decltype(&SUNITDMG_SetHitClass) SUNITDMG_SetHitClass_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_SetHitClass(D2DamageStrc* pDamage, uint32_t nHitClass);
static_assert(std::is_same_v<decltype(&SUNITDMG_SetHitClass), decltype(&ESE_INTERCEPT_SUNITDMG_SetHitClass)>, "ESE_INTERCEPT_SUNITDMG_SetHitClass has a different type than previously known.");

extern decltype(&SUNITDMG_GetColdEffect) SUNITDMG_GetColdEffect_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNITDMG_GetColdEffect), decltype(&ESE_INTERCEPT_SUNITDMG_GetColdEffect)>, "ESE_INTERCEPT_SUNITDMG_GetColdEffect has a different type than previously known.");

extern decltype(&SUNITDMG_RemoveFreezeState) SUNITDMG_RemoveFreezeState_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);
static_assert(std::is_same_v<decltype(&SUNITDMG_RemoveFreezeState), decltype(&ESE_INTERCEPT_SUNITDMG_RemoveFreezeState)>, "ESE_INTERCEPT_SUNITDMG_RemoveFreezeState has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyDamageBonuses) SUNITDMG_ApplyDamageBonuses_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int32_t bGetStats, D2UnitStrc* pItem, int32_t nMinDmg, int32_t nMaxDmg, int32_t nDamagePercent, int32_t nDamage, uint8_t nSrcDam);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyDamageBonuses), decltype(&ESE_INTERCEPT_SUNITDMG_ApplyDamageBonuses)>, "ESE_INTERCEPT_SUNITDMG_ApplyDamageBonuses has a different type than previously known.");

extern decltype(&SUNITDMG_FillDamageValues) SUNITDMG_FillDamageValues_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int32_t a5, uint8_t nSrcDam);
static_assert(std::is_same_v<decltype(&SUNITDMG_FillDamageValues), decltype(&ESE_INTERCEPT_SUNITDMG_FillDamageValues)>, "ESE_INTERCEPT_SUNITDMG_FillDamageValues has a different type than previously known.");

extern decltype(&SUNITDMG_CheckMonType) SUNITDMG_CheckMonType_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_CheckMonType(int32_t nMonType1, int32_t nMonType2);
static_assert(std::is_same_v<decltype(&SUNITDMG_CheckMonType), decltype(&ESE_INTERCEPT_SUNITDMG_CheckMonType)>, "ESE_INTERCEPT_SUNITDMG_CheckMonType has a different type than previously known.");

extern decltype(&SUNITDMG_RollDamageValueInRange) SUNITDMG_RollDamageValueInRange_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_RollDamageValueInRange(D2UnitStrc* pUnit, int32_t nMinDamage, int32_t nMaxDamage, int32_t nMinDamageBonusPct, int32_t nMaxDamageBonusPct, int32_t nDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_RollDamageValueInRange), decltype(&ESE_INTERCEPT_SUNITDMG_RollDamageValueInRange)>, "ESE_INTERCEPT_SUNITDMG_RollDamageValueInRange has a different type than previously known.");

extern decltype(&SUNITDMG_CalculateTotalDamage) SUNITDMG_CalculateTotalDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_CalculateTotalDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_CalculateTotalDamage), decltype(&ESE_INTERCEPT_SUNITDMG_CalculateTotalDamage)>, "ESE_INTERCEPT_SUNITDMG_CalculateTotalDamage has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyResistancesAndAbsorb) SUNITDMG_ApplyResistancesAndAbsorb_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyResistancesAndAbsorb(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyResistancesAndAbsorb), decltype(&ESE_INTERCEPT_SUNITDMG_ApplyResistancesAndAbsorb)>, "ESE_INTERCEPT_SUNITDMG_ApplyResistancesAndAbsorb has a different type than previously known.");

extern decltype(&SUNITDMG_ExecuteEvents) SUNITDMG_ExecuteEvents_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bMissile, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_ExecuteEvents), decltype(&ESE_INTERCEPT_SUNITDMG_ExecuteEvents)>, "ESE_INTERCEPT_SUNITDMG_ExecuteEvents has a different type than previously known.");

extern decltype(&SUNITDMG_GetMonStatsTxtRecordFromUnit) SUNITDMG_GetMonStatsTxtRecordFromUnit_Original;
D2MonStatsTxt* __fastcall ESE_INTERCEPT_SUNITDMG_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNITDMG_GetMonStatsTxtRecordFromUnit), decltype(&ESE_INTERCEPT_SUNITDMG_GetMonStatsTxtRecordFromUnit)>, "ESE_INTERCEPT_SUNITDMG_GetMonStatsTxtRecordFromUnit has a different type than previously known.");

extern decltype(&SUNITDMG_AddLeechedLife) SUNITDMG_AddLeechedLife_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_AddLeechedLife(D2UnitStrc* pUnit, int32_t nLifeLeeched);
static_assert(std::is_same_v<decltype(&SUNITDMG_AddLeechedLife), decltype(&ESE_INTERCEPT_SUNITDMG_AddLeechedLife)>, "ESE_INTERCEPT_SUNITDMG_AddLeechedLife has a different type than previously known.");

extern decltype(&SUNITDMG_AddLeechedMana) SUNITDMG_AddLeechedMana_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_AddLeechedMana(D2UnitStrc* pUnit, int32_t nManaLeeched);
static_assert(std::is_same_v<decltype(&SUNITDMG_AddLeechedMana), decltype(&ESE_INTERCEPT_SUNITDMG_AddLeechedMana)>, "ESE_INTERCEPT_SUNITDMG_AddLeechedMana has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyPoisonDamage) SUNITDMG_ApplyPoisonDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyPoisonDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nPoisonDamage, int32_t nPoisonLength);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyPoisonDamage), decltype(&ESE_INTERCEPT_SUNITDMG_ApplyPoisonDamage)>, "ESE_INTERCEPT_SUNITDMG_ApplyPoisonDamage has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyBurnDamage) SUNITDMG_ApplyBurnDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyBurnDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nBurnDamage, int32_t nBurnLength);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyBurnDamage), decltype(&ESE_INTERCEPT_SUNITDMG_ApplyBurnDamage)>, "ESE_INTERCEPT_SUNITDMG_ApplyBurnDamage has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyColdState) SUNITDMG_ApplyColdState_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyColdState(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nColdLength);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyColdState), decltype(&ESE_INTERCEPT_SUNITDMG_ApplyColdState)>, "ESE_INTERCEPT_SUNITDMG_ApplyColdState has a different type than previously known.");

extern decltype(&SUNITDMG_RemoveShatterState) SUNITDMG_RemoveShatterState_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);
static_assert(std::is_same_v<decltype(&SUNITDMG_RemoveShatterState), decltype(&ESE_INTERCEPT_SUNITDMG_RemoveShatterState)>, "ESE_INTERCEPT_SUNITDMG_RemoveShatterState has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyFreezeState) SUNITDMG_ApplyFreezeState_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyFreezeState(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nFreezeLength);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyFreezeState), decltype(&ESE_INTERCEPT_SUNITDMG_ApplyFreezeState)>, "ESE_INTERCEPT_SUNITDMG_ApplyFreezeState has a different type than previously known.");

extern decltype(&SUNITDMG_FreeAttackerCombatList) SUNITDMG_FreeAttackerCombatList_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker);
static_assert(std::is_same_v<decltype(&SUNITDMG_FreeAttackerCombatList), decltype(&ESE_INTERCEPT_SUNITDMG_FreeAttackerCombatList)>, "ESE_INTERCEPT_SUNITDMG_FreeAttackerCombatList has a different type than previously known.");

extern decltype(&SUNITDMG_FreeAttackerDefenderCombatList) SUNITDMG_FreeAttackerDefenderCombatList_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender);
static_assert(std::is_same_v<decltype(&SUNITDMG_FreeAttackerDefenderCombatList), decltype(&ESE_INTERCEPT_SUNITDMG_FreeAttackerDefenderCombatList)>, "ESE_INTERCEPT_SUNITDMG_FreeAttackerDefenderCombatList has a different type than previously known.");

extern decltype(&SUNITDMG_KillMonster) SUNITDMG_KillMonster_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int32_t bPetKill);
static_assert(std::is_same_v<decltype(&SUNITDMG_KillMonster), decltype(&ESE_INTERCEPT_SUNITDMG_KillMonster)>, "ESE_INTERCEPT_SUNITDMG_KillMonster has a different type than previously known.");

extern decltype(&SUNITDMG_ExecuteMissileDamage) SUNITDMG_ExecuteMissileDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_ExecuteMissileDamage), decltype(&ESE_INTERCEPT_SUNITDMG_ExecuteMissileDamage)>, "ESE_INTERCEPT_SUNITDMG_ExecuteMissileDamage has a different type than previously known.");

extern decltype(&sub_6FCC1870) sub_6FCC1870_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FCC1870(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nHitClass);
static_assert(std::is_same_v<decltype(&sub_6FCC1870), decltype(&ESE_INTERCEPT_sub_6FCC1870)>, "ESE_INTERCEPT_sub_6FCC1870 has a different type than previously known.");

extern decltype(&SUNITDMG_GetHitClass) SUNITDMG_GetHitClass_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetHitClass(D2DamageStrc* pDamage, uint32_t nBaseHitClass);
static_assert(std::is_same_v<decltype(&SUNITDMG_GetHitClass), decltype(&ESE_INTERCEPT_SUNITDMG_GetHitClass)>, "ESE_INTERCEPT_SUNITDMG_GetHitClass has a different type than previously known.");

extern decltype(&SUNITDMG_DrainItemDurability) SUNITDMG_DrainItemDurability_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nUnused);
static_assert(std::is_same_v<decltype(&SUNITDMG_DrainItemDurability), decltype(&ESE_INTERCEPT_SUNITDMG_DrainItemDurability)>, "ESE_INTERCEPT_SUNITDMG_DrainItemDurability has a different type than previously known.");

extern decltype(&SUNITDMG_GetDamageFromUnits) SUNITDMG_GetDamageFromUnits_Original;
D2DamageStrc* __fastcall ESE_INTERCEPT_SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender);
static_assert(std::is_same_v<decltype(&SUNITDMG_GetDamageFromUnits), decltype(&ESE_INTERCEPT_SUNITDMG_GetDamageFromUnits)>, "ESE_INTERCEPT_SUNITDMG_GetDamageFromUnits has a different type than previously known.");

extern decltype(&D2Game_10033) D2Game_10033_Original;
bool __stdcall ESE_INTERCEPT_D2Game_10033(D2UnitStrc* pUnit, int32_t* a2, int32_t* a3);
static_assert(std::is_same_v<decltype(&D2Game_10033), decltype(&ESE_INTERCEPT_D2Game_10033)>, "ESE_INTERCEPT_D2Game_10033 has a different type than previously known.");

extern decltype(&SUNITDMG_IsHitSuccessful) SUNITDMG_IsHitSuccessful_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nStatValue, int32_t bMissile);
static_assert(std::is_same_v<decltype(&SUNITDMG_IsHitSuccessful), decltype(&ESE_INTERCEPT_SUNITDMG_IsHitSuccessful)>, "ESE_INTERCEPT_SUNITDMG_IsHitSuccessful has a different type than previously known.");

extern decltype(&SUNITDMG_GetResultFlags) SUNITDMG_GetResultFlags_Original;
uint16_t __fastcall ESE_INTERCEPT_SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nStatValue, int32_t nRangeOffset);
static_assert(std::is_same_v<decltype(&SUNITDMG_GetResultFlags), decltype(&ESE_INTERCEPT_SUNITDMG_GetResultFlags)>, "ESE_INTERCEPT_SUNITDMG_GetResultFlags has a different type than previously known.");

extern decltype(&SUNITDMG_AllocCombat) SUNITDMG_AllocCombat_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, uint8_t nSrcDam);
static_assert(std::is_same_v<decltype(&SUNITDMG_AllocCombat), decltype(&ESE_INTERCEPT_SUNITDMG_AllocCombat)>, "ESE_INTERCEPT_SUNITDMG_AllocCombat has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyBlockOrDodge) SUNITDMG_ApplyBlockOrDodge_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bAvoid, int32_t bBlock);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyBlockOrDodge), decltype(&ESE_INTERCEPT_SUNITDMG_ApplyBlockOrDodge)>, "ESE_INTERCEPT_SUNITDMG_ApplyBlockOrDodge has a different type than previously known.");

extern decltype(&SUNITDMG_ApplyDodge) SUNITDMG_ApplyDodge_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyDodge(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bAvoid);
static_assert(std::is_same_v<decltype(&SUNITDMG_ApplyDodge), decltype(&ESE_INTERCEPT_SUNITDMG_ApplyDodge)>, "ESE_INTERCEPT_SUNITDMG_ApplyDodge has a different type than previously known.");

extern decltype(&SUNITDMG_GetWeaponBlock) SUNITDMG_GetWeaponBlock_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetWeaponBlock(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNITDMG_GetWeaponBlock), decltype(&ESE_INTERCEPT_SUNITDMG_GetWeaponBlock)>, "ESE_INTERCEPT_SUNITDMG_GetWeaponBlock has a different type than previously known.");

extern decltype(&SUNITDMG_SetMissileDamageFlagsForNearbyUnits) SUNITDMG_SetMissileDamageFlagsForNearbyUnits_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nSize, D2DamageStrc* pDamage, int32_t a7, int32_t a8, int32_t(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int32_t a10);
static_assert(std::is_same_v<decltype(&SUNITDMG_SetMissileDamageFlagsForNearbyUnits), decltype(&ESE_INTERCEPT_SUNITDMG_SetMissileDamageFlagsForNearbyUnits)>, "ESE_INTERCEPT_SUNITDMG_SetMissileDamageFlagsForNearbyUnits has a different type than previously known.");

extern decltype(&SUNITDMG_RollDamage) SUNITDMG_RollDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_RollDamage(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_RollDamage), decltype(&ESE_INTERCEPT_SUNITDMG_RollDamage)>, "ESE_INTERCEPT_SUNITDMG_RollDamage has a different type than previously known.");

extern decltype(&SUNITDMG_RollSuckBloodDamage) SUNITDMG_RollSuckBloodDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&SUNITDMG_RollSuckBloodDamage), decltype(&ESE_INTERCEPT_SUNITDMG_RollSuckBloodDamage)>, "ESE_INTERCEPT_SUNITDMG_RollSuckBloodDamage has a different type than previously known.");

extern decltype(&SUNITDMG_DistributeExperience) SUNITDMG_DistributeExperience_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender);
static_assert(std::is_same_v<decltype(&SUNITDMG_DistributeExperience), decltype(&ESE_INTERCEPT_SUNITDMG_DistributeExperience)>, "ESE_INTERCEPT_SUNITDMG_DistributeExperience has a different type than previously known.");

extern decltype(&SUNITDMG_ComputeExperienceGain) SUNITDMG_ComputeExperienceGain_Original;
uint32_t __fastcall ESE_INTERCEPT_SUNITDMG_ComputeExperienceGain(D2GameStrc* pGame, D2UnitStrc* pAttacker, uint32_t nAttackerLevel, uint32_t nDefenderLevel, uint32_t nDefenderExperience);
static_assert(std::is_same_v<decltype(&SUNITDMG_ComputeExperienceGain), decltype(&ESE_INTERCEPT_SUNITDMG_ComputeExperienceGain)>, "ESE_INTERCEPT_SUNITDMG_ComputeExperienceGain has a different type than previously known.");

extern decltype(&SUNITDMG_AddExperienceForPlayer) SUNITDMG_AddExperienceForPlayer_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperienceForPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nOldLevel, uint32_t nExperienceGained);
static_assert(std::is_same_v<decltype(&SUNITDMG_AddExperienceForPlayer), decltype(&ESE_INTERCEPT_SUNITDMG_AddExperienceForPlayer)>, "ESE_INTERCEPT_SUNITDMG_AddExperienceForPlayer has a different type than previously known.");

extern decltype(&SUNITDMG_PartyCallback_ComputePartyExperience) SUNITDMG_PartyCallback_ComputePartyExperience_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_PartyCallback_ComputePartyExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);
static_assert(std::is_same_v<decltype(&SUNITDMG_PartyCallback_ComputePartyExperience), decltype(&ESE_INTERCEPT_SUNITDMG_PartyCallback_ComputePartyExperience)>, "ESE_INTERCEPT_SUNITDMG_PartyCallback_ComputePartyExperience has a different type than previously known.");

extern decltype(&SUNITDMG_AddExperienceForHireling) SUNITDMG_AddExperienceForHireling_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperienceForHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pHireling, uint32_t nLevel, uint32_t nExperienceBonus);
static_assert(std::is_same_v<decltype(&SUNITDMG_AddExperienceForHireling), decltype(&ESE_INTERCEPT_SUNITDMG_AddExperienceForHireling)>, "ESE_INTERCEPT_SUNITDMG_AddExperienceForHireling has a different type than previously known.");

extern decltype(&SUNITDMG_AddExperience) SUNITDMG_AddExperience_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nExperienceBonus);
static_assert(std::is_same_v<decltype(&SUNITDMG_AddExperience), decltype(&ESE_INTERCEPT_SUNITDMG_AddExperience)>, "ESE_INTERCEPT_SUNITDMG_AddExperience has a different type than previously known.");

extern decltype(&SUNITDMG_SetExperienceForTargetLevel) SUNITDMG_SetExperienceForTargetLevel_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_SetExperienceForTargetLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nTargetLevel);
static_assert(std::is_same_v<decltype(&SUNITDMG_SetExperienceForTargetLevel), decltype(&ESE_INTERCEPT_SUNITDMG_SetExperienceForTargetLevel)>, "ESE_INTERCEPT_SUNITDMG_SetExperienceForTargetLevel has a different type than previously known.");

