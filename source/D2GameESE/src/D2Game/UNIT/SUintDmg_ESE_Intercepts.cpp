#include "D2Game/UNIT/SUnitDmg_ESE.h"
#include "D2Game/MISSILES/MissMode_ESE.h"
#include "D2Game/MONSTER/MonsterMode_ESE.h"
#include "D2Game/SKILLS/Skills_ESE.h"
#include "D2Game/SKILLS/SkillAss_ESE.h"
#include "D2Game/SKILLS/SkillPal_ESE.h"
#include "D2Game/MONSTER/MonsterUnique_ESE.h"
#include "D2Common/D2Skills_ESE.h"

#include "D2Game/UNIT/SUnitDmg_ESE_INTERCEPTS.h"

#include <algorithm>

#include <D2BitManip.h>
#include <D2Math.h>
#include <D2Combat.h>
#include <D2DataTbls.h>
#include <D2Dungeon.h>
#include <D2Items.h>
#include <D2States.h>
#include <D2StatList.h>
#include <UselessOrdinals.h>
#include <DataTbls/MonsterIds.h>
#include <DataTbls/ObjectsIds.h>
#include <Units/UnitFinds.h>
#include <Units/UnitRoom.h>
#include <AI/AiGeneral.h>
#include <GAME/Arena.h>
#include <GAME/Clients.h>
#include <GAME/Event.h>
#include <GAME/SCmd.h>
#include <ITEMS/Items.h>
#include <MONSTER/Monster.h>
#include <MONSTER/MonsterAI.h>
#include <MONSTER/MonsterRegion.h>
#include <PLAYER/Player.h>
#include <PLAYER/PlayerPets.h>
#include <PLAYER/PlayerStats.h>
#include <PLAYER/PlrModes.h>
#include <QUESTS/Quests.h>
#include <UNIT/Party.h>
#include <UNIT/SUnitEvent.h>
#include <UNIT/SUnit.h>

SUNITDMG_SetHitClass_t SUNITDMG_SetHitClass_Original = nullptr;
SUNITDMG_GetColdEffect_t SUNITDMG_GetColdEffect_Original = nullptr;
SUNITDMG_RemoveFreezeState_t SUNITDMG_RemoveFreezeState_Original = nullptr;
SUNITDMG_ApplyDamageBonuses_t SUNITDMG_ApplyDamageBonuses_Original = nullptr;
SUNITDMG_FillDamageValues_t SUNITDMG_FillDamageValues_Original = nullptr;
SUNITDMG_CheckMonType_t SUNITDMG_CheckMonType_Original = nullptr;
SUNITDMG_RollDamageValueInRange_t SUNITDMG_RollDamageValueInRange_Original = nullptr;
SUNITDMG_CalculateTotalDamage_t SUNITDMG_CalculateTotalDamage_Original = nullptr;
SUNITDMG_ApplyResistancesAndAbsorb_t SUNITDMG_ApplyResistancesAndAbsorb_Original = nullptr;
SUNITDMG_ExecuteEvents_t SUNITDMG_ExecuteEvents_Original = nullptr;
SUNITDMG_GetMonStatsTxtRecordFromUnit_t SUNITDMG_GetMonStatsTxtRecordFromUnit_Original = nullptr;
SUNITDMG_AddLeechedLife_t SUNITDMG_AddLeechedLife_Original = nullptr;
SUNITDMG_AddLeechedMana_t SUNITDMG_AddLeechedMana_Original = nullptr;
SUNITDMG_ApplyPoisonDamage_t SUNITDMG_ApplyPoisonDamage_Original = nullptr;
SUNITDMG_ApplyBurnDamage_t SUNITDMG_ApplyBurnDamage_Original = nullptr;
SUNITDMG_ApplyColdState_t SUNITDMG_ApplyColdState_Original = nullptr;
SUNITDMG_RemoveShatterState_t SUNITDMG_RemoveShatterState_Original = nullptr;
SUNITDMG_ApplyFreezeState_t SUNITDMG_ApplyFreezeState_Original = nullptr;
SUNITDMG_FreeAttackerCombatList_t SUNITDMG_FreeAttackerCombatList_Original = nullptr;
SUNITDMG_FreeAttackerDefenderCombatList_t SUNITDMG_FreeAttackerDefenderCombatList_Original = nullptr;
SUNITDMG_KillMonster_t SUNITDMG_KillMonster_Original = nullptr;
SUNITDMG_ExecuteMissileDamage_t SUNITDMG_ExecuteMissileDamage_Original = nullptr;
sub_6FCC1870_t sub_6FCC1870_Original = nullptr;
SUNITDMG_GetHitClass_t SUNITDMG_GetHitClass_Original = nullptr;
SUNITDMG_DrainItemDurability_t SUNITDMG_DrainItemDurability_Original = nullptr;
SUNITDMG_GetDamageFromUnits_t SUNITDMG_GetDamageFromUnits_Original = nullptr;
D2Game_10033_t D2Game_10033_Original = nullptr;
SUNITDMG_IsHitSuccessful_t SUNITDMG_IsHitSuccessful_Original = nullptr;
SUNITDMG_GetResultFlags_t SUNITDMG_GetResultFlags_Original = nullptr;
SUNITDMG_AllocCombat_t SUNITDMG_AllocCombat_Original = nullptr;
SUNITDMG_ApplyBlockOrDodge_t SUNITDMG_ApplyBlockOrDodge_Original = nullptr;
SUNITDMG_ApplyDodge_t SUNITDMG_ApplyDodge_Original = nullptr;
SUNITDMG_GetWeaponBlock_t SUNITDMG_GetWeaponBlock_Original = nullptr;
SUNITDMG_SetMissileDamageFlagsForNearbyUnits_t SUNITDMG_SetMissileDamageFlagsForNearbyUnits_Original = nullptr;
SUNITDMG_RollDamage_t SUNITDMG_RollDamage_Original = nullptr;
SUNITDMG_RollSuckBloodDamage_t SUNITDMG_RollSuckBloodDamage_Original = nullptr;
SUNITDMG_DistributeExperience_t SUNITDMG_DistributeExperience_Original = nullptr;
SUNITDMG_ComputeExperienceGain_t SUNITDMG_ComputeExperienceGain_Original = nullptr;
SUNITDMG_AddExperienceForPlayer_t SUNITDMG_AddExperienceForPlayer_Original = nullptr;
SUNITDMG_PartyCallback_ComputePartyExperience_t SUNITDMG_PartyCallback_ComputePartyExperience_Original = nullptr;
SUNITDMG_AddExperienceForHireling_t SUNITDMG_AddExperienceForHireling_Original = nullptr;
SUNITDMG_AddExperience_t SUNITDMG_AddExperience_Original = nullptr;
SUNITDMG_SetExperienceForTargetLevel_t SUNITDMG_SetExperienceForTargetLevel_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_SetHitClass(D2DamageStrc* pDamage, uint32_t nHitClass)
{
    return ESE_SUNITDMG_SetHitClass(pDamage, nHitClass);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_SUNITDMG_GetColdEffect(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList)
{
    ESE_SUNITDMG_RemoveFreezeState(pUnit, nState, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int32_t bGetStats, D2UnitStrc* pItem, int32_t nMinDmg, int32_t nMaxDmg, int32_t nDamagePercent, int32_t nDamage, uint8_t nSrcDam)
{
    return ESE_SUNITDMG_ApplyDamageBonuses(pUnit, bGetStats, pItem, nMinDmg, nMaxDmg, nDamagePercent, nDamage, nSrcDam);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int32_t a5, uint8_t nSrcDam)
{
    ESE_SUNITDMG_FillDamageValues(pGame, pAttacker, pDefender, pDamage, a5, nSrcDam);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_CheckMonType(int32_t nMonType1, int32_t nMonType2)
{
    return ESE_SUNITDMG_CheckMonType(nMonType1, nMonType2);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_RollDamageValueInRange(D2UnitStrc* pUnit, int32_t nMinDamage, int32_t nMaxDamage, int32_t nMinDamageBonusPct, int32_t nMaxDamageBonusPct, int32_t nDamage)
{
    return ESE_SUNITDMG_RollDamageValueInRange(pUnit, nMinDamage, nMaxDamage, nMinDamageBonusPct, nMaxDamageBonusPct, nDamage);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_CalculateTotalDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    ESE_SUNITDMG_CalculateTotalDamage(pGame, pAttacker, pDefender, pDamage);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyResistancesAndAbsorb(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb)
{
    ESE_SUNITDMG_ApplyResistancesAndAbsorb(pDamageInfo, pDamageStatTableRecord, bDontAbsorb);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bMissile, D2DamageStrc* pDamage)
{
    ESE_SUNITDMG_ExecuteEvents(pGame, pAttacker, pDefender, bMissile, pDamage);
}

D2MonStatsTxt* __fastcall ESE_INTERCEPT_SUNITDMG_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    return ESE_SUNITDMG_GetMonStatsTxtRecordFromUnit(pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_AddLeechedLife(D2UnitStrc* pUnit, int32_t nLifeLeeched)
{
    return ESE_SUNITDMG_AddLeechedLife(pUnit, nLifeLeeched);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_AddLeechedMana(D2UnitStrc* pUnit, int32_t nManaLeeched)
{
    return ESE_SUNITDMG_AddLeechedMana(pUnit, nManaLeeched);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyPoisonDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nPoisonDamage, int32_t nPoisonLength)
{
    ESE_SUNITDMG_ApplyPoisonDamage(pAttacker, pDefender, nPoisonDamage, nPoisonLength);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyBurnDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nBurnDamage, int32_t nBurnLength)
{
    ESE_SUNITDMG_ApplyBurnDamage(pAttacker, pDefender, nBurnDamage, nBurnLength);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyColdState(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nColdLength)
{
    ESE_SUNITDMG_ApplyColdState(pAttacker, pDefender, nColdLength);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList)
{
    ESE_SUNITDMG_RemoveShatterState(pUnit, nState, pStatList);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_ApplyFreezeState(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nFreezeLength)
{
    ESE_SUNITDMG_ApplyFreezeState(pAttacker, pDefender, nFreezeLength);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    ESE_SUNITDMG_FreeAttackerCombatList(pGame, pAttacker);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    ESE_SUNITDMG_FreeAttackerDefenderCombatList(pGame, pAttacker, pDefender);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int32_t bPetKill)
{
    ESE_SUNITDMG_KillMonster(pGame, pDefender, pAttacker, bPetKill);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    ESE_SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, pDamage);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FCC1870(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nHitClass)
{
    return ESE_sub_6FCC1870(pUnit, pDamage, nHitClass);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetHitClass(D2DamageStrc* pDamage, uint32_t nBaseHitClass)
{
    return ESE_SUNITDMG_GetHitClass(pDamage, nBaseHitClass);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nUnused)
{
    ESE_SUNITDMG_DrainItemDurability(pGame, pAttacker, pDefender, nUnused);
}

D2DamageStrc* __fastcall ESE_INTERCEPT_SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    return ESE_SUNITDMG_GetDamageFromUnits(pAttacker, pDefender);
}

bool __stdcall ESE_INTERCEPT_D2Game_10033(D2UnitStrc* pUnit, int32_t* a2, int32_t* a3)
{
    return ESE_D2Game_10033(pUnit, a2, a3);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nStatValue, int32_t bMissile)
{
    return ESE_SUNITDMG_IsHitSuccessful(pAttacker, pDefender, nStatValue, bMissile);
}

uint16_t __fastcall ESE_INTERCEPT_SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nStatValue, int32_t nRangeOffset)
{
    return ESE_SUNITDMG_GetResultFlags(pGame, pAttacker, pDefender, nStatValue, nRangeOffset);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, uint8_t nSrcDam)
{
    ESE_SUNITDMG_AllocCombat(pGame, pAttacker, pDefender, pDamage, nSrcDam);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bAvoid, int32_t bBlock)
{
    return ESE_SUNITDMG_ApplyBlockOrDodge(pGame, pAttacker, pDefender, bAvoid, bBlock);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_ApplyDodge(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bAvoid)
{
    return ESE_SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_GetWeaponBlock(D2UnitStrc* pUnit)
{
    return ESE_SUNITDMG_GetWeaponBlock(pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nSize, D2DamageStrc* pDamage, int32_t a7, int32_t a8, int32_t(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int32_t a10)
{
    return ESE_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pUnit, nX, nY, nSize, pDamage, a7, a8, pfCallback, a10);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_RollDamage(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage)
{
    ESE_SUNITDMG_RollDamage(pUnit, nSkillId, nSkillLevel, pDamage);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage)
{
    ESE_SUNITDMG_RollSuckBloodDamage(pGame, pAttacker, pDefender, nSkillId, nSkillLevel, pDamage);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    ESE_SUNITDMG_DistributeExperience(pGame, pAttacker, pDefender);
}

uint32_t __fastcall ESE_INTERCEPT_SUNITDMG_ComputeExperienceGain(D2GameStrc* pGame, D2UnitStrc* pAttacker, uint32_t nAttackerLevel, uint32_t nDefenderLevel, uint32_t nDefenderExperience)
{
    return ESE_SUNITDMG_ComputeExperienceGain(pGame, pAttacker, nAttackerLevel, nDefenderLevel, nDefenderExperience);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperienceForPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nOldLevel, uint32_t nExperienceGained)
{
    ESE_SUNITDMG_AddExperienceForPlayer(pGame, pUnit, nOldLevel, nExperienceGained);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_PartyCallback_ComputePartyExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    ESE_SUNITDMG_PartyCallback_ComputePartyExperience(pGame, pUnit, pArg);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperienceForHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pHireling, uint32_t nLevel, uint32_t nExperienceBonus)
{
    ESE_SUNITDMG_AddExperienceForHireling(pGame, pPlayer, pHireling, nLevel, nExperienceBonus);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nExperienceBonus)
{
    ESE_SUNITDMG_AddExperience(pGame, pUnit, nExperienceBonus);
}

void __fastcall ESE_INTERCEPT_SUNITDMG_SetExperienceForTargetLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, uint32_t nTargetLevel)
{
    ESE_SUNITDMG_SetExperienceForTargetLevel(pGame, pUnit, nTargetLevel);
}
