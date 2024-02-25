#pragma once

#include "D2Game/UNIT/SUnitDmg_ESE.h"

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

extern SUNITDMG_SetHitClass_t SUNITDMG_SetHitClass_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_SetHitClass(D2DamageStrc* pDamage, uint32_t nHitClass);

extern SUNITDMG_GetColdEffect_t SUNITDMG_GetColdEffect_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern SUNITDMG_RemoveFreezeState_t SUNITDMG_RemoveFreezeState_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);

extern SUNITDMG_ApplyDamageBonuses_t SUNITDMG_ApplyDamageBonuses_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int32_t bGetStats, D2UnitStrc* pItem, int32_t nMinDmg, int32_t nMaxDmg, int32_t nDamagePercent, int32_t nDamage, uint8_t nSrcDam);

extern SUNITDMG_FillDamageValues_t SUNITDMG_FillDamageValues_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int32_t a5, uint8_t nSrcDam);

extern SUNITDMG_CheckMonType_t SUNITDMG_CheckMonType_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_CheckMonType(int32_t nMonType1, int32_t nMonType2);

extern SUNITDMG_RollDamageValueInRange_t SUNITDMG_RollDamageValueInRange_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_RollDamageValueInRange(D2UnitStrc* pUnit, int32_t nMinDamage, int32_t nMaxDamage, int32_t nMinDamageBonusPct, int32_t nMaxDamageBonusPct, int32_t nDamage);

extern SUNITDMG_CalculateTotalDamage_t SUNITDMG_CalculateTotalDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_CalculateTotalDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);

extern SUNITDMG_ApplyResistancesAndAbsorb_t SUNITDMG_ApplyResistancesAndAbsorb_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyResistancesAndAbsorb(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb);

extern SUNITDMG_ExecuteEvents_t SUNITDMG_ExecuteEvents_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bMissile, D2DamageStrc* pDamage);

extern SUNITDMG_GetMonStatsTxtRecordFromUnit_t SUNITDMG_GetMonStatsTxtRecordFromUnit_Original;
D2MonStatsTxt* __fastcall ESE_INTERCEPT_SUNITDMG_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit);

extern SUNITDMG_AddLeechedLife_t SUNITDMG_AddLeechedLife_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_AddLeechedLife(D2UnitStrc* pUnit, int32_t nLifeLeeched);

extern SUNITDMG_AddLeechedMana_t SUNITDMG_AddLeechedMana_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_AddLeechedMana(D2UnitStrc* pUnit, int32_t nManaLeeched);

extern SUNITDMG_ApplyPoisonDamage_t SUNITDMG_ApplyPoisonDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyPoisonDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nPoisonDamage, int32_t nPoisonLength);

extern SUNITDMG_ApplyBurnDamage_t SUNITDMG_ApplyBurnDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyBurnDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nBurnDamage, int32_t nBurnLength);

extern SUNITDMG_ApplyColdState_t SUNITDMG_ApplyColdState_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyColdState(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nColdLength);

extern SUNITDMG_RemoveShatterState_t SUNITDMG_RemoveShatterState_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);

extern SUNITDMG_ApplyFreezeState_t SUNITDMG_ApplyFreezeState_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyFreezeState(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nFreezeLength);

extern SUNITDMG_FreeAttackerCombatList_t SUNITDMG_FreeAttackerCombatList_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker);

extern SUNITDMG_FreeAttackerDefenderCombatList_t SUNITDMG_FreeAttackerDefenderCombatList_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender);

extern SUNITDMG_KillMonster_t SUNITDMG_KillMonster_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int32_t bPetKill);

extern SUNITDMG_ExecuteMissileDamage_t SUNITDMG_ExecuteMissileDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage);

extern sub_6FCC1870_t sub_6FCC1870_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FCC1870(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nHitClass);

extern SUNITDMG_GetHitClass_t SUNITDMG_GetHitClass_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetHitClass(D2DamageStrc* pDamage, uint32_t nBaseHitClass);

extern SUNITDMG_DrainItemDurability_t SUNITDMG_DrainItemDurability_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nUnused);

extern SUNITDMG_GetDamageFromUnits_t SUNITDMG_GetDamageFromUnits_Original;
D2DamageStrc* __fastcall ESE_INTERCEPT_SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender);

extern D2Game_10033_t D2Game_10033_Original;
bool __stdcall ESE_INTERCEPT_D2Game_10033(D2UnitStrc* pUnit, int32_t* a2, int32_t* a3);

extern SUNITDMG_IsHitSuccessful_t SUNITDMG_IsHitSuccessful_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nStatValue, int32_t bMissile);

extern SUNITDMG_GetResultFlags_t SUNITDMG_GetResultFlags_Original;
uint16_t __fastcall ESE_INTERCEPT_SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nStatValue, int32_t nRangeOffset);

extern SUNITDMG_AllocCombat_t SUNITDMG_AllocCombat_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, uint8_t nSrcDam);

extern SUNITDMG_ApplyBlockOrDodge_t SUNITDMG_ApplyBlockOrDodge_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bAvoid, int32_t bBlock);

extern SUNITDMG_ApplyDodge_t SUNITDMG_ApplyDodge_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyDodge(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bAvoid);

extern SUNITDMG_GetWeaponBlock_t SUNITDMG_GetWeaponBlock_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetWeaponBlock(D2UnitStrc* pUnit);

extern SUNITDMG_SetMissileDamageFlagsForNearbyUnits_t SUNITDMG_SetMissileDamageFlagsForNearbyUnits_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nSize, D2DamageStrc* pDamage, int32_t a7, int32_t a8, int32_t(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int32_t a10);

extern SUNITDMG_RollDamage_t SUNITDMG_RollDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_RollDamage(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage);

extern SUNITDMG_RollSuckBloodDamage_t SUNITDMG_RollSuckBloodDamage_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage);

extern SUNITDMG_DistributeExperience_t SUNITDMG_DistributeExperience_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender);

extern SUNITDMG_ComputeExperienceGain_t SUNITDMG_ComputeExperienceGain_Original;
uint32_t __fastcall ESE_INTERCEPT_SUNITDMG_ComputeExperienceGain(D2GameStrc* pGame, D2UnitStrc* pAttacker, uint32_t nAttackerLevel, uint32_t nDefenderLevel, uint32_t nDefenderExperience);

extern SUNITDMG_AddExperienceForPlayer_t SUNITDMG_AddExperienceForPlayer_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperienceForPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nOldLevel, uint32_t nExperienceGained);

extern SUNITDMG_PartyCallback_ComputePartyExperience_t SUNITDMG_PartyCallback_ComputePartyExperience_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_PartyCallback_ComputePartyExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern SUNITDMG_AddExperienceForHireling_t SUNITDMG_AddExperienceForHireling_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperienceForHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pHireling, uint32_t nLevel, uint32_t nExperienceBonus);

extern SUNITDMG_AddExperience_t SUNITDMG_AddExperience_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nExperienceBonus);

extern SUNITDMG_SetExperienceForTargetLevel_t SUNITDMG_SetExperienceForTargetLevel_Original;
void __fastcall ESE_INTERCEPT_SUNITDMG_SetExperienceForTargetLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nTargetLevel);

