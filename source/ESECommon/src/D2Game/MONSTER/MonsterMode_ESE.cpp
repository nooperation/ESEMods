#include "D2Game/MONSTER/MonsterMode_ESE.h"
#include "D2Game/MONSTER/MonsterUnique_ESE.h"
#include "D2Game/SKILLS/SkillMonst_ESE.h"
#include "D2Game/SKILLS/Skills_ESE.h"
#include "D2Game/SKILLS/SkillSor_ESE.h"
#include "D2Game/UNIT/SUnitDmg_ESE.h"
#include "D2Common/D2Skills_ESE.h"

#include <D2BitManip.h>
#include <D2Chat.h>
#include <D2Collision.h>
#include <D2Dungeon.h>
#include <D2Monsters.h>
#include <D2States.h>
#include <DataTbls/MonsterIds.h>
#include <DataTbls/MonsterTbls.h>
#include <D2StatList.h>
#include <D2QuestRecord.h>
#include <Units/UnitRoom.h>
#include <D2DataTbls.h>
#include <D2Combat.h>
#include <DataTbls/MissilesIds.h>
#include <AI/AiGeneral.h>
#include <AI/AiTactics.h>
#include <AI/AiThink.h>
#include <GAME/Clients.h>
#include <GAME/Event.h>
#include <GAME/Targets.h>
#include <ITEMS/Items.h>
#include <MONSTER/Monster.h>
#include <MONSTER/MonsterAI.h>
#include <MONSTER/MonsterRegion.h>
#include <UNIT/SUnit.h>
#include <UNIT/SUnitEvent.h>
#include <UNIT/SUnitMsg.h>

#include <algorithm>

#pragma pack(push, 1)
struct D2MonModeInfoTableStrc
{
    int32_t unk0x00;
    int32_t unk0x04;
    int32_t unk0x08;
};
#pragma pack(pop)

constexpr D2MonModeInfoTableStrc stru_6FD28738[16] =
{
    { 0, 1, 0 },
    { 0, 1, 0 },
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 1, 0 },
    { 1, 0, 0 },
    { 1, 0, 0 },
    { 1, 0, 0 },
};

//D2Game.0x6FC627B0
void __fastcall ESE_sub_6FC627B0(D2UnitStrc* pUnit, int32_t nMode)
{
    constexpr int32_t dword_6FD2870C[] =
    {
        0, 0, 8, 16, 24, 32, 40, 48, 56
    };

    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pMonsterData)
    {
        return;
    }
    
    D2MonStatsTxt* pMonStatsTxtRecord = pUnit->pMonsterData->pMonstatsTxt;
    if (!pMonStatsTxtRecord)
    {
        return;
    }
    
    D2MonSkillInfoStrc monSkillInfo = {};
    ESE_sub_6FD14D20(pUnit, nMode, &monSkillInfo);

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
    if (!pStatList)
    {
        return;
    }

    STATLIST_RemoveAllStats(pStatList);

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    int32_t nGameType = 0;
    if (pGame->nGameType || pGame->dwGameType)
    {
        nGameType = 1;
    }

    int32_t nMultiplier = 0;
    if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
    {
        const int32_t nPlayerCount = std::max(STATLIST_UnitGetStatValue(pUnit, STAT_MONSTER_PLAYERCOUNT, 0), 1);

        if (pGame->nDifficulty != DIFFMODE_NORMAL && nPlayerCount >= 2)
        {
            if (nPlayerCount >= std::size(dword_6FD2870C))
            {
                nMultiplier = 8 * nPlayerCount - 16;
            }
            else
            {
                nMultiplier = dword_6FD2870C[nPlayerCount];
            }
        }
    }

    D2MonStatsInitStrc pMonStatsInit = {};
    int32_t nMinDamage = 0;
    int32_t nMaxDamage = 0;
    int32_t nToHit = 0;
    if (nMode == MONMODE_ATTACK2)
    {
        DATATBLS_CalculateMonsterStatsByLevel(pUnit->dwClassId, nGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 16, &pMonStatsInit);
        nMinDamage = pMonStatsInit.nA2MinD + monSkillInfo.nMinDamage;
        nMaxDamage = pMonStatsInit.nA2MaxD + monSkillInfo.nMaxDamage;
        nToHit = pMonStatsInit.nTH + monSkillInfo.nToHit;
    }
    else if (nMode == MONMODE_BLOCK || nMode == MONMODE_CAST || nMode == MONMODE_SKILL1)
    {
        DATATBLS_CalculateMonsterStatsByLevel(pUnit->dwClassId, nGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 32, &pMonStatsInit);
        nMinDamage = pMonStatsInit.nS1MinD + monSkillInfo.nMinDamage;
        nMaxDamage = pMonStatsInit.nS1MaxD + monSkillInfo.nMaxDamage;
        nToHit = pMonStatsInit.nTH + monSkillInfo.nToHit;
    }
    else
    {
        DATATBLS_CalculateMonsterStatsByLevel(pUnit->dwClassId, nGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 8, &pMonStatsInit);
        nMinDamage = pMonStatsInit.nA1MinD + monSkillInfo.nMinDamage;
        nMaxDamage = pMonStatsInit.nA1MaxD + monSkillInfo.nMaxDamage;
        nToHit = pMonStatsInit.nTH + monSkillInfo.nToHit;
    }

    if (pGame->bExpansion)
    {
        if (nMultiplier)
        {
            nMinDamage += nMultiplier * nMinDamage / 128;
            nMaxDamage += nMultiplier * nMaxDamage / 128;
            nToHit += nMultiplier * nToHit / 128;
        }
    }
    else
    {
        if (pGame->nDifficulty != DIFFMODE_NORMAL && pMonStatsTxtRecord->nAlign != MONALIGN_GOOD)
        {
            nMinDamage = 10 * nMinDamage / 12;
            nMaxDamage = 10 * nMaxDamage / 12;
            nToHit = 10 * nToHit / 15;
        }
    }

    STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, nMinDamage, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, nMaxDamage, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_TOHIT, nToHit, 0);

    for (int32_t i = 0; i < 3; ++i)
    {
        if (pMonStatsTxtRecord->nElMode[i] && nMode == pMonStatsTxtRecord->nElMode[i])
        {
            const uint8_t nChance = pMonStatsTxtRecord->nElPct[i][pGame->nDifficulty];
            if (nChance && (nChance >= 100 || (ITEMS_RollRandomNumber(&pUnit->pSeed) % 100) < nChance))
            {
                memset(&pMonStatsInit, 0, sizeof(pMonStatsInit));
                DATATBLS_CalculateMonsterStatsByLevel(pUnit->dwClassId, nGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 0x40 + i, &pMonStatsInit);

                int32_t nElemDuration = pMonStatsInit.nElDur;
                int32_t nElemMinDamage = pMonStatsInit.nElMaxD;
                int32_t nElemMaxDamage = pMonStatsInit.nElMinD;
                if (pGame->bExpansion && nMultiplier)
                {
                    nElemMaxDamage = pMonStatsInit.nElMinD + nMultiplier * pMonStatsInit.nElMinD / 128;
                    nElemMinDamage = pMonStatsInit.nElMaxD + nMultiplier * pMonStatsInit.nElMaxD / 128;
                    nElemDuration = pMonStatsInit.nElDur + nMultiplier * pMonStatsInit.nElDur / 128;
                }

                uint8_t nElemType = pMonStatsTxtRecord->nElType[i];
                if (nElemType == ELEMTYPE_RAND)
                {
                    nElemType = ITEMS_RollRandomNumber(&pUnit->pSeed) % 5 + 1;

                    if (!nElemDuration)
                    {
                        nElemDuration = 25;
                    }
                }

                switch (nElemType)
                {
                case ELEMTYPE_FIRE:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMINDAM, nElemMaxDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMAXDAM, nElemMinDamage, 0);
                    break;

                case ELEMTYPE_LTNG:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMINDAM, nElemMaxDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMAXDAM, nElemMinDamage, 0);
                    break;

                case ELEMTYPE_MAGIC:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_MAGICMINDAM, nElemMaxDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_MAGICMAXDAM, nElemMinDamage, 0);
                    break;

                case ELEMTYPE_COLD:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_COLDMINDAM, nElemMaxDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_COLDMAXDAM, nElemMinDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_COLDLENGTH, nElemDuration, 0);
                    break;

                case ELEMTYPE_POIS:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMINDAM, 10 * nElemMaxDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMAXDAM, 10 * nElemMinDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONLENGTH, 2 * nElemDuration, 0);
                    break;

                case ELEMTYPE_LIFE:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_LIFEDRAINMINDAM, nElemMaxDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_LIFEDRAINMAXDAM, nElemMinDamage, 0);
                    break;

                case ELEMTYPE_MANA:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_MANADRAINMINDAM, nElemMaxDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_MANADRAINMAXDAM, nElemMinDamage, 0);
                    break;

                case ELEMTYPE_STAMINA:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_STAMDRAINMINDAM, nElemMaxDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_STAMDRAINMAXDAM, nElemMinDamage, 0);
                    break;

                case ELEMTYPE_STUN:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_STUNLENGTH, nElemDuration, 0);
                    break;

                case ELEMTYPE_BURN:
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_BURNINGMIN, nElemMaxDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_BURNINGMAX, nElemMinDamage, 0);
                    STATLIST_SetStatIfListIsValid(pStatList, STAT_FIRELENGTH, nElemDuration, 0);
                    break;

                default:
                    break;
                }
            }
        }
    }
}

//D2Game.0x6FC62D90
void __fastcall ESE_sub_6FC62D90(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        D2DamageStrc damage = {};
        damage.wResultFlags = ESE_SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0);
        ESE_SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    }
}

//D2Game.0x6FC62DF0
void __stdcall ESE_sub_6FC62DF0(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (pDamage->wResultFlags & 4 && D2GAME_GetMonsterBaseId_6FC64B10(pUnit) == MONSTER_SANDLEAPER1 && !STATES_CheckState(pUnit, STATE_FREEZE))
    {
        pDamage->wResultFlags |= 8u;
    }
}

//D2Game.0x6FC62E70
void __fastcall ESE_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (pAttacker && pAttacker->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nCrit && (ITEMS_RollRandomNumber(&pAttacker->pSeed) % 100) < pMonStatsTxtRecord->nCrit)
        {
            pDamage->dwPhysDamage *= 2;
            pDamage->dwFireDamage *= 2;
            pDamage->dwLtngDamage *= 2;
            pDamage->dwMagDamage *= 2;
            pDamage->dwColdDamage *= 2;
            pDamage->dwPoisDamage *= 2;

            if (pDefender && !ESE_SUNITDMG_SetHitClass(pDamage, 0x10u))
            {
                UNITS_SetOverlay(pDefender, 54, 0);
            }
        }
    }
}

//D2Game.0x6FC63440
void __fastcall ESE_D2GAME_ApplyPeriodicStatDamage_6FC63440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4)
{
    pUnit = pUnit;

    int32_t nHpRegen = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0);

    if (STATES_CheckStateMaskLifeOnUnit(pUnit))
    {
        nHpRegen -= STATLIST_GetUnitBaseStat(pUnit, STAT_HPREGEN, 0);
    }

    if (!STATES_CheckState(pUnit, STATE_PREVENTHEAL) || nHpRegen < 0)
    {
        EVENT_SetEvent(pGame, pUnit, UNITEVENTCALLBACK_STATREGEN, pGame->dwGameFrame + 1, 0, 0);

        if (nHpRegen)
        {
            const int32_t nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
            if (nHpRegen < 0 && nHitpoints < 256)
            {
                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
                if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
                {
                    return;
                }
            }

            int32_t nNewHp = nHpRegen + nHitpoints;

            const int32_t nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
            if (nNewHp > nMaxHp)
            {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, UNITEVENTCALLBACK_STATREGEN, 0);
                nNewHp = nMaxHp;
            }

            if (nNewHp < 1)
            {
                nNewHp = 0;
            }

            STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

            const uint8_t nLastSentHpPct = STATLIST_UnitGetStatValue(pUnit, STAT_LAST_SENT_HP_PCT, 0);
            const uint8_t nNewSentHpPct = sub_6FC62F50(pUnit);
            int32_t nHpPctDiff = nLastSentHpPct - nNewSentHpPct;
            nHpPctDiff = std::abs(nHpPctDiff);

            if (nHpPctDiff > 4)
            {
                sub_6FCC6270(pUnit, nNewSentHpPct);
                STATLIST_SetUnitStat(pUnit, STAT_LAST_SENT_HP_PCT, nNewSentHpPct, 0);
            }

            if (!nNewHp && pUnit && pUnit->dwAnimMode != MONMODE_DEATH && pUnit->dwAnimMode != MONMODE_DEAD)
            {
                D2StatListStrc* pStatList = nullptr;

                constexpr int32_t states[] = { STATE_POISON, STATE_OPENWOUNDS };
                for (size_t i = 0; i < std::size(states); ++i)
                {
                    if (pStatList)
                    {
                        break;
                    }

                    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, states[i]);
                }

                pUnit->dwLastHitClass = 0;

                D2UnitStrc* pStatListOwner = nullptr;
                if (pStatList)
                {
                    pStatListOwner = SUNIT_GetServerUnit(pGame, STATLIST_GetOwnerType(pStatList), STATLIST_GetOwnerGUID(pStatList));
                }

                if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
                {
                    STATES_ToggleState(pUnit, STATE_DEATH_DELAY, 1);
                }
                else
                {
                    ESE_SUNITDMG_KillMonster(pGame, pUnit, pStatListOwner, 1);
                    SUNITEVENT_EventFunc_Handler(pGame, EVENT_KILLED, pUnit, pStatListOwner, 0);

                    if (pStatListOwner)
                    {
                        SUNITEVENT_EventFunc_Handler(pGame, EVENT_KILL, pStatListOwner, pUnit, 0);
                    }
                }
            }
        }
        else
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, UNITEVENTCALLBACK_STATREGEN, 0);
        }
    }
}

//D2Game.0x6FC63B30
int32_t __fastcall ESE_sub_6FC63B30(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    SUNIT_SetCombatMode(pGame, pModeChange->pUnit, MONMODE_DEATH);
    sub_6FC63E80(pGame, pModeChange->pUnit, pModeChange->unk0x14[0]);
    D2GAME_MONSTERMODE_Unk_6FC63040(pGame, pModeChange, 0);
    sub_6FC68240(pGame->pMonReg, pModeChange->pUnit);
    DUNGEON_SaveKilledUnitGUID(UNITS_GetRoom(pModeChange->pUnit), pModeChange->pUnit ? pModeChange->pUnit->dwUnitId : -1);

    if (!pModeChange->pUnit)
    {
        return 1;
    }
    
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pModeChange->pUnit->dwClassId);
    if (!pMonStatsTxtRecord || !(pMonStatsTxtRecord->dwMonStatsFlags & gdwBitMasks[MONSTATSFLAGINDEX_DEATHDMG]))
    {
        return 1;
    }

    if (pModeChange->pUnit->dwUnitType == UNIT_MONSTER)
    {
        if (pMonStatsTxtRecord->nBaseId == MONSTER_BONEFETISH1)
        {
            const int32_t nX = CLIENTS_GetUnitX(pModeChange->pUnit);
            const int32_t nY = CLIENTS_GetUnitY(pModeChange->pUnit);
            D2UnitStrc* pMissile = ESE_sub_6FD11420(pGame, MISSILE_MONSTERCORPSEEXPLODE, pModeChange->pUnit, 0, 1, 0, 0, nX, nY, 1);
            if (pMissile)
            {
                D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
                if (pDifficultyLevelsTxtRecord)
                {
                    D2MonStatsInitStrc monStatsInit = {};
                    DATATBLS_CalculateMonsterStatsByLevel(pModeChange->pUnit->dwClassId, pGame->dwGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pModeChange->pUnit, STAT_LEVEL, 0), 1, &monStatsInit);

                    const int32_t nMaxDamage = ESE_MONSTERUNIQUE_CalculatePercentage(monStatsInit.nMaxHP, pDifficultyLevelsTxtRecord->dwMonsterCEDmgPercent, 100);
                    const int32_t nMinDamage = ESE_MONSTERUNIQUE_CalculatePercentage(nMaxDamage, 60, 100);
                    
                    D2DamageStrc damage = {};
                    damage.dwPhysDamage = (nMinDamage + ITEMS_RollLimitedRandomNumber(&pModeChange->pUnit->pSeed, nMaxDamage - nMinDamage)) << 7;
                    ESE_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, 5, &damage, 0, 0, nullptr, 0x581);
                    return 1;

                }
            }
            return 1;
        }
        else if (pMonStatsTxtRecord->nBaseId == MONSTER_SIEGEBEAST1)
        {
            sub_6FC64090(pGame, pModeChange->pUnit);
            return 1;
        }
    }

    ESE_sub_6FC63FD0(pGame, pModeChange->pUnit);
    return 1;
}

//D2Game.0x6FC63FD0
void __fastcall ESE_sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    for (D2UnitStrc* i = UNITS_GetRoom(pAttacker)->pUnitFirst; i; i = i->pRoomNext)
    {
        if (i->dwUnitType == UNIT_PLAYER && i->dwAnimMode != PLRMODE_DEAD && UNITS_GetDistanceToOtherUnit(pAttacker, i) <= 2 && !UNITS_TestCollisionBetweenInteractingUnits(i, pAttacker, 15361))
        {
            D2DamageStrc pDamage = {};
            pDamage.dwPhysDamage = (int32_t )STATLIST_UnitGetStatValue(i, STAT_HITPOINTS, 0) >> 5;
            pDamage.wResultFlags = DAMAGERESULTFLAG_SUCCESSFULHIT;
            if (!STATES_CheckState(i, STATE_UNINTERRUPTABLE))
            {
                pDamage.wResultFlags |= DAMAGERESULTFLAG_GETHIT;
            }

            ESE_SUNITDMG_CalculateTotalDamage(pGame, pAttacker, i, &pDamage);
            ESE_SUNITDMG_ExecuteEvents(pGame, pAttacker, i, 1, &pDamage);
            ESE_SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, i, &pDamage);
        }
    }
}

//D2Game.0x6FC64090
void __fastcall ESE_sub_6FC64090(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pMonster = SUNIT_GetOwner(pGame, pUnit);
    if (pMonster)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pMonster->dwClassId);
        if (pMonStatsTxtRecord)
        {
            D2CoordStrc pCoord = {};
            pCoord.nX = CLIENTS_GetUnitX(pMonster);
            pCoord.nY = CLIENTS_GetUnitY(pMonster);
            D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pMonster), &pCoord, UNITS_GetUnitSizeX(pMonster), 0x3C01u, 0);
            if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL && pRoom && AITACTICS_UseSkill(pGame, pMonster, pMonStatsTxtRecord->nSkillMode[0], pMonStatsTxtRecord->nSkill[0], 0, pCoord.nX, pCoord.nY))
            {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pMonster, 2, 0);
            }
            else
            {
                ESE_SUNITDMG_KillMonster(pGame, pMonster, 0, 1);
            }
        }
    }
}

//D2Game.0x6FC641D0
void __fastcall ESE_sub_6FC641D0(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    if (pAttacker)
    {
        SUNIT_SetCombatMode(pGame, pAttacker, 12);
        SUNITEVENT_EventFunc_Handler(pGame, EVENT_DEATH, pAttacker, 0, 0);

        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (pMonStatsTxtRecord)
        {
            if (pMonStatsTxtRecord->nSplEndDeath == 1)
            {
                if (pMonStatsTxtRecord->wMinion[0] >= 0 && pMonStatsTxtRecord->wMinion[0] <= sgptDataTables->nMonStatsTxtRecordCount)
                {
                    MONSTER_Reinitialize(pGame, pAttacker, pMonStatsTxtRecord->wMinion[0], 1);
                    MONSTER_UpdateAiCallbackEvent(pGame, pAttacker);
                }
            }
            else if (pMonStatsTxtRecord->nSplEndDeath == 2)
            {
                D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pAttacker);
                if (pOwner)
                {
                    ESE_SUNITDMG_KillMonster(pGame, pOwner, 0, 1);
                }
            }
        }
    }
}

//D2Game.0x6FC64790
int32_t __fastcall ESE_sub_6FC64790(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        // TODO: v10
        int32_t v10 = 0;
        if (pUnit)
        {
            if (pUnit->dwAnimMode < 16)
            {
                const D2MonModeInfoTableStrc* pMonModeInfoTableRecord = &stru_6FD28738[pUnit->dwAnimMode];
                if (pMonModeInfoTableRecord->unk0x00)
                {
                    v10 = 1;
                }
                else if (!pMonModeInfoTableRecord->unk0x04 && pMonModeInfoTableRecord->unk0x08)
                {
                    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(pUnit->dwClassId);
                    if (pMonStats2TxtRecord && pMonStats2TxtRecord->nModeEnabledWhenMovingFlags[pUnit->dwAnimMode >> 3] & gdwBitMasks[pUnit->dwAnimMode & 7])
                    {
                        v10 = 1;
                    }
                }
            }
        }

        if (v10)
        {
            sub_6FCBC930(pGame, pUnit);
            UNITS_StopSequence(pUnit);

            if (UNITS_IsAtEndOfFrameCycle(pUnit))
            {
                return 2;
            }

            if (pUnit->dwAnimMode == MONMODE_SEQUENCE)
            {
                if (!(pUnit->dwFlags & UNITFLAG_SKSRVDOFUNC))
                {
                    return 1;
                }
            }
            else
            {
                if (pUnit->nActionFrame != 1)
                {
                    return 1;
                }
            }
        }

        int32_t nMissileId = D2Common_11050(pUnit, v10);
        if (nMissileId >= 0)
        {
            int32_t nSkillLevel = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty)->dwMonsterSkillBonus + 1;
            if (pUnit->dwFlags & UNITFLAG_ISMERC)
            {
                nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
            }

            if (ESE_sub_6FD11420(pGame, nMissileId, pUnit, 0, nSkillLevel, 0, 0, 0, 0, 1))
            {
                const int32_t nBaseId = D2GAME_GetMonsterBaseId_6FC64B10(pUnit);
                if (nBaseId == MONSTER_QUILLRAT1)
                {
                    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
                    int32_t nX = 0;
                    int32_t nY = 0;
                    if (pTarget)
                    {
                        nX = CLIENTS_GetUnitX(pTarget);
                        nY = CLIENTS_GetUnitY(pTarget);
                    }
                    else
                    {
                        nX = D2Common_10175_PathGetFirstPointX(pUnit->pDynamicPath);
                        nY = D2Common_10176_PathGetFirstPointY(pUnit->pDynamicPath);
                    }

                    int32_t nYOffset = 5;
                    int32_t nXOffset = 5;
                    
                    PATH_SetTargetUnit(pUnit->pDynamicPath, nullptr);

                    D2SeedStrc seed = {};
                    SEED_InitSeed(&seed);
                    SEED_InitLowSeed(&seed, 'SEIS');

                    const int32_t nParam = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId)->wAiParam[2][pGame->nDifficulty];
                    for (int32_t i = 0; i < nParam; ++i)
                    {
                        if (ITEMS_RollRandomNumber(&seed) & 1)
                        {
                            nXOffset = -nXOffset;
                        }

                        if (ITEMS_RollRandomNumber(&seed) & 1)
                        {
                            nYOffset = -nYOffset;
                        }

                        D2Common_10170_PathSetTargetPos(pUnit->pDynamicPath, nX + nXOffset, nY + nYOffset);
                        ESE_sub_6FD11420(pGame, nMissileId, pUnit, 0, 1, 0, 0, 0, 0, 0);
                    }

                    PATH_SetTargetUnit(pUnit->pDynamicPath, pTarget);
                    return 1;
                }
            }
        }
        else
        {
            ESE_sub_6FC62D90(pUnit, pGame);

            D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
            if (pTarget)
            {
                ESE_SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
            }
        }

        return 1;
    }

    const int32_t nSkillFlags = SKILLS_GetFlags(pSkill);
    if (!(nSkillFlags & 1))
    {
        ESE_sub_6FD13410(pGame, pUnit);
        UNITS_StopSequence(pUnit);
        return 1;
    }

    sub_6FCBC7E0(pGame, pUnit);

    if (sub_6FCBC930(pGame, pUnit) != 2)
    {
        ESE_sub_6FD13410(pGame, pUnit);
        UNITS_StopSequence(pUnit);
        return 1;
    }

    SKILLS_SetFlags(pSkill, nSkillFlags | 2);

    ESE_sub_6FD13410(pGame, pUnit);

    if (pUnit && pUnit->dwAnimMode == MONMODE_SEQUENCE)
    {
        if (pUnit->dwFlags & UNITFLAG_SKSRVDOFUNC)
        {
            ESE_sub_6FD13410(pGame, pUnit);
        }
    }
    else
    {
        if (pUnit->nActionFrame == 1)
        {
            ESE_sub_6FD13410(pGame, pUnit);
        }
    }

    UNITS_StopSequence(pUnit);
    return 1;
}
