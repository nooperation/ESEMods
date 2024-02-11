#include "ESEDamageCalc.h"

#include <D2Dungeon.h>
#include <D2StatList.h>
#include <D2Math.h>
#include <D2Skills.h>
#include <D2States.h>
#include <SKILLS/Skills.h>
#include <SKILLS/SkillAss.h>
#include <UNIT/SUnit.h>
#include <UNIT/SUnitEvent.h>
#include <Units/UnitRoom.h>
#include <MONSTER/Monster.h>
#include <DataTbls/MonsterIds.h>
#include <MONSTER/MonsterMode.h>
#include <MONSTER/MonsterRegion.h>
#include <PLAYER/PlrModes.h>
#include <ITEMS/Items.h>
#include <GAME/SCmd.h>
#include <UNIT/SUnitDmg.h>

decltype(&SUNITDMG_CalculateTotalDamage) SUNITDMG_CalculateTotalDamage_Original = nullptr;
decltype(&SUNITDMG_ExecuteEvents) SUNITDMG_ExecuteEvents_Original = nullptr;
decltype(&MONSTERUNIQUE_CalculatePercentage) MONSTERUNIQUE_CalculatePercentage_Original = nullptr;
decltype(&SUNITDMG_AllocCombat) SUNITDMG_AllocCombat_Original = nullptr;

int64_t SUNITDMG_CalculateTotalDamage_ESEDamageCalc_64(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
int64_t SUNITDMG_ApplyResistancesAndAbsorb_ESEDamageCalc_64(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb);

void __fastcall SUNITDMG_ExecuteEvents_ESEDamageCalc(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bMissile, D2DamageStrc* pDamage)
{
    if (!sub_6FCBD900(pGame, pAttacker, pDefender) && !(pDamage->dwHitFlags & DAMAGEHITFLAG_4096))
    {
        pDamage->wResultFlags &= (uint16_t)(~(DAMAGERESULTFLAG_SUCCESSFULHIT | DAMAGERESULTFLAG_WILLDIE));
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pDefender);
    if (!pRoom)
    {
        pDamage->wResultFlags &= (uint16_t)(~(DAMAGERESULTFLAG_SUCCESSFULHIT | DAMAGERESULTFLAG_WILLDIE));
        return;
    }

    if (DUNGEON_IsRoomInTown(pRoom))
    {
        if (!pAttacker || pAttacker->dwUnitType != UNIT_MONSTER)
        {
            pDamage->wResultFlags &= (uint16_t)(~DAMAGERESULTFLAG_WILLDIE);
            return;
        }

        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (!pMonStatsTxtRecord || !(pMonStatsTxtRecord->dwMonStatsFlags & gdwBitMasks[MONSTATSFLAGINDEX_INTOWN]))
        {
            pDamage->wResultFlags &= (uint16_t)(~DAMAGERESULTFLAG_WILLDIE);
            return;
        }
    }

    int32_t nAttackerUnitType = 6;
    if (pAttacker)
    {
        nAttackerUnitType = pAttacker->dwUnitType;
    }

    int32_t nDefenderUnitType = 6;
    if (pDefender)
    {
        nDefenderUnitType = pDefender->dwUnitType;

        if (pDefender->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pDefender->dwClassId);
            if (!pMonStatsTxtRecord || !(pMonStatsTxtRecord->dwMonStatsFlags & gdwBitMasks[MONSTATSFLAGINDEX_KILLABLE]))
            {
                return;
            }
        }
    }

    if (SUNIT_IsDead(pDefender))
    {
        return;
    }

    UNITS_StoreLastAttacker(pDefender, pAttacker);

    int64_t damageTotal = 0;
    if (bMissile)
    {
        SUNITDMG_CalculateTotalDamage_ESEDamageCalc(pGame, pAttacker, pDefender, pDamage);
        damageTotal = (int64_t)(((uint64_t)pDamage->dwAbsLife << 32) | (uint64_t)pDamage->dwDmgTotal);
        pDamage->dwAbsLife = 0;
    }
    else
    {
        damageTotal = pDamage->dwDmgTotal;
    }

    if (!(pDamage->wResultFlags & DAMAGERESULTFLAG_32) && pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        if (bMissile)
        {
            if (pDamage->dwHitFlags & DAMAGEHITFLAG_32)
            {
                if (!(pDamage->dwHitFlags & DAMAGEHITFLAG_128))
                {
                    SUNITEVENT_EventFunc_Handler(pGame, EVENT_DOMISSILEDMG, pAttacker, pDefender, pDamage);
                }
                SUNITEVENT_EventFunc_Handler(pGame, EVENT_DAMAGEDBYMISSILE, pDefender, pAttacker, pDamage);
            }
        }
        else
        {
            SUNITEVENT_EventFunc_Handler(pGame, EVENT_DOMELEEDMG, pAttacker, pDefender, pDamage);
            SUNITEVENT_EventFunc_Handler(pGame, EVENT_DAMAGEDINMELEE, pDefender, pAttacker, pDamage);
        }
    }

    const int32_t nHp = STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0);
    pDamage->dwPhysDamage = std::min(pDamage->dwPhysDamage, nHp);

    if (pDamage->dwLifeLeech || pDamage->dwManaLeech)
    {
        int32_t nDrain = 0;
        if (pDefender && pDefender->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = SUNITDMG_GetMonStatsTxtRecordFromUnit(pDefender);
            if (pMonStatsTxtRecord)
            {
                nDrain = pMonStatsTxtRecord->nDrain[pGame->nDifficulty];
            }
        }
        else
        {
            nDrain = 100;
        }

        if (nDrain > 0)
        {
            pDamage->dwLifeLeech <<= 6;
            pDamage->dwManaLeech <<= 6;

            int32_t nUnitType = 0;
            if (pAttacker)
            {
                if (pAttacker->dwUnitType == UNIT_PLAYER)
                {
                    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pAttacker->pGame->nDifficulty);
                    if (pDifficultyLevelsTxtRecord->dwLifeStealDiv)
                    {
                        pDamage->dwLifeLeech /= pDifficultyLevelsTxtRecord->dwLifeStealDiv;
                    }

                    if (pDifficultyLevelsTxtRecord->dwManaStealDiv)
                    {
                        pDamage->dwManaLeech /= pDifficultyLevelsTxtRecord->dwManaStealDiv;
                    }
                }
                else
                {
                    if (pAttacker->dwUnitType != UNIT_MONSTER || !MONSTERS_GetHirelingTypeId(pAttacker))
                    {
                        nUnitType = pAttacker->dwUnitType;
                        int32_t nClassId = pAttacker->dwClassId;
                        int32_t nAnimMode = pAttacker->dwAnimMode;
                        D2COMMON_11013_ConvertMode(pAttacker, &nUnitType, &nClassId, &nAnimMode, __FILE__, __LINE__);
                    }
                }
            }
            else
            {
                nUnitType = 6;
                int32_t nClassId = -1;
                int32_t nAnimMode = 0;
                D2COMMON_11013_ConvertMode(pAttacker, &nUnitType, &nClassId, &nAnimMode, __FILE__, __LINE__);
            }

            if (!nUnitType)
            {
                if (pDamage->dwPhysDamage > 0)
                {
                    if (pDamage->dwManaLeech)
                    {
                        int32_t nLeechedMana = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(pDamage->dwPhysDamage, pDamage->dwManaLeech, 100);
                        if (nDrain != 100)
                        {
                            nLeechedMana = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(nLeechedMana, nDrain, 100);
                        }

                        SUNITDMG_AddLeechedMana(pAttacker, nLeechedMana / 64);
                    }

                    if (pDamage->dwLifeLeech)
                    {
                        int32_t nLeechedHp = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(pDamage->dwPhysDamage, pDamage->dwLifeLeech, 100);
                        if (nDrain != 100)
                        {
                            nLeechedHp = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(nLeechedHp, nDrain, 100);
                        }

                        SUNITDMG_AddLeechedLife(pAttacker, nLeechedHp / 64);

                        if (pDamage->dwManaLeech)
                        {
                            if (!ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 2))
                            {
                                UNITS_SetOverlay(pAttacker, 151, 0);
                            }
                            else
                            {
                                UNITS_SetOverlay(pAttacker, 152, 0);
                            }
                        }
                        else
                        {
                            UNITS_SetOverlay(pAttacker, 151, 0);
                        }
                    }
                    else if (pDamage->dwManaLeech)
                    {
                        UNITS_SetOverlay(pAttacker, 152, 0);
                    }
                }
            }
            else
            {
                const int32_t nMana = STATLIST_UnitGetStatValue(pDefender, STAT_MANA, 0);
                const int32_t nStamina = STATLIST_UnitGetStatValue(pDefender, STAT_STAMINA, 0);

                pDamage->dwLifeLeech <<= 6;
                pDamage->dwManaLeech <<= 6;

                const int32_t nLifeLeech = std::min(pDamage->dwLifeLeech, pDamage->dwPhysDamage);
                const int32_t nManaLeech = std::min(pDamage->dwManaLeech, nMana);
                const int32_t nStaminaLeech = std::min(pDamage->dwStamLeech, nStamina);
                int32_t nTotalLeech = nStaminaLeech + nManaLeech + nLifeLeech;
                if (nTotalLeech)
                {
                    if (nDrain != 100)
                    {
                        nTotalLeech = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(nTotalLeech, nDrain, 100);
                    }

                    const int32_t nMissingHp = STATLIST_GetMaxLifeFromUnit(pAttacker) - STATLIST_UnitGetStatValue(pAttacker, STAT_HITPOINTS, 0);
                    nTotalLeech = std::min(nTotalLeech, nMissingHp);

                    if (nTotalLeech > 0)
                    {
                        STATLIST_AddUnitStat(pAttacker, STAT_HITPOINTS, nTotalLeech, 0);
                        UNITS_SetOverlay(pAttacker, 151, 0);
                    }
                }
            }
        }
    }

    if (nAttackerUnitType == UNIT_MONSTER && pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        sub_6FC6E890(pGame, pAttacker);
    }

    if (damageTotal > 0)
    {
        const int32_t nMaxHp = STATLIST_GetMaxLifeFromUnit(pDefender);

        auto oldHp = (int64_t)STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0);
        auto newHpUncapped = oldHp - damageTotal;

        if (nAttackerUnitType == UNIT_PLAYER)
        {
            if (pAttacker != nullptr && pAttacker->pPlayerData != nullptr && pAttacker->pPlayerData->pClient != nullptr)
            {
                DamageReportPacket packet;
                packet.packetId = 0x45;
                packet.unitId = pDefender->dwUnitId;
                packet.damage = damageTotal;
                packet.unknownA = 1;
                packet.unknownB = 0;
                packet.unknownC = 0;
                packet.unknownD = 0;

                D2GAME_PACKETS_SendPacket_6FC3C710(pAttacker->pPlayerData->pClient, &packet, sizeof(packet));
            }
        }

        if (newHpUncapped > nMaxHp)
        {
            newHpUncapped = nMaxHp;
        }
        if (newHpUncapped < 256)
        {
            newHpUncapped = 0;
        }

        STATLIST_SetUnitStat(pDefender, STAT_HITPOINTS, (int32_t)newHpUncapped, 0);
    }

    if (pDamage->dwManaLeech > 0)
    {
        const int32_t nMaxMana = STATLIST_GetMaxManaFromUnit(pDefender);

        auto oldMana = (int64_t)STATLIST_UnitGetStatValue(pDefender, STAT_MANA, 0);
        auto newManaUncapped = oldMana - (int64_t)pDamage->dwManaLeech;

        if (newManaUncapped > nMaxMana)
        {
            newManaUncapped = nMaxMana;
        }
        else if (newManaUncapped < 256)
        {
            newManaUncapped = 0;
        }

        STATLIST_SetUnitStat(pDefender, STAT_MANA, (int32_t)newManaUncapped, 0);
    }

    if (pDamage->dwStamLeech > 0)
    {
        const int32_t nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pDefender);

        auto oldStamina = (int64_t)STATLIST_UnitGetStatValue(pDefender, STAT_STAMINA, 0);
        auto newStaminaUncapped = oldStamina - (int64_t)pDamage->dwStamLeech;

        if (newStaminaUncapped > nMaxStamina)
        {
            newStaminaUncapped = nMaxStamina;
        }
        else if (newStaminaUncapped < 256)
        {
            newStaminaUncapped = 0;
        }

        STATLIST_SetUnitStat(pDefender, STAT_STAMINA, newStaminaUncapped, 0);
    }

    uint32_t nStunLength = pDamage->dwStunLen;
    int32_t bApplyStun = 0;
    if (nStunLength > 0)
    {
        if (!pDefender || pDefender->dwUnitType != UNIT_MONSTER)
        {
            nStunLength = std::min(nStunLength, 250u);
            bApplyStun = 1;
        }

        if ((!MONSTERUNIQUE_CheckMonTypeFlag(pDefender, MONTYPEFLAG_UNIQUE) || ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 100) >= 90) &&
            !MONSTERS_IsBoss(0, pDefender) &&
            MONSTERMODE_GetMonStatsTxtRecord(pDefender->dwClassId)->nVelocity)
        {
            if (MONSTERS_GetHirelingTypeId(pDefender) && nStunLength >= 13)
            {
                nStunLength = 13;
            }
            else if (nStunLength > 250)
            {
                nStunLength = 250;
            }

            bApplyStun = 1;
        }

        if (bApplyStun)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, STATE_STUNNED);
            const int32_t nStunEndFrame = nStunLength + pAttacker->pGame->dwGameFrame;
            if (pStatList)
            {
                STATLIST_SetExpireFrame(pStatList, nStunEndFrame);
                EVENT_SetEvent(pAttacker->pGame, pDefender, UNITEVENTCALLBACK_REMOVESTATE, nStunEndFrame, 0, 0);
            }
            else
            {
                D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pAttacker->pGame->pMemoryPool, 2u, nStunEndFrame, pAttacker->dwUnitType, pAttacker->dwUnitId);
                EVENT_SetEvent(pAttacker->pGame, pDefender, UNITEVENTCALLBACK_REMOVESTATE, nStunEndFrame, 0, 0);
                STATLIST_SetState(pNewStatList, STATE_STUNNED);
                STATLIST_SetStatRemoveCallback(pNewStatList, sub_6FD10E50);
                D2COMMON_10475_PostStatToStatList(pDefender, pNewStatList, 1);
                STATES_ToggleState(pDefender, STATE_STUNNED, 1);
            }
        }
    }

    SUNITDMG_ApplyColdState(pAttacker, pDefender, pDamage->dwColdLen);
    SUNITDMG_ApplyFreezeState(pAttacker, pDefender, pDamage->dwFrzLen);
    SUNITDMG_ApplyPoisonDamage(pAttacker, pDefender, pDamage->dwPoisDamage, pDamage->dwPoisLen);
    SUNITDMG_ApplyBurnDamage(pAttacker, pDefender, pDamage->dwBurnDamage, pDamage->dwBurnLen);

    if (STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0) <= 0)
    {
        pDamage->wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
    }
    else
    {
        pDamage->wResultFlags &= (uint16_t)(~DAMAGERESULTFLAG_WILLDIE);
        if (damageTotal > 0 && nDefenderUnitType == UNIT_MONSTER)
        {
            if (STATLIST_UnitGetStatValue(pDefender, STAT_HPREGEN, 0))
            {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pDefender, UNITEVENTCALLBACK_STATREGEN, 0);
                EVENT_SetEvent(pGame, pDefender, UNITEVENTCALLBACK_STATREGEN, pGame->dwGameFrame + 1, 0, 0);
            }
            sub_6FCF8DD0(pDefender);
        }
    }

    if (!(pDamage->wResultFlags & DAMAGERESULTFLAG_32) && pDamage->wResultFlags & DAMAGERESULTFLAG_WILLDIE)
    {
        SUNITEVENT_EventFunc_Handler(pGame, EVENT_KILLED, pDefender, pAttacker, pDamage);
        SUNITEVENT_EventFunc_Handler(pGame, EVENT_KILL, pAttacker, pDefender, pDamage);
    }
}

int64_t SUNITDMG_CalculateTotalDamage_ESEDamageCalc_64(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    SUNITDMG_CalculateTotalDamage_ESEDamageCalc(pGame, pAttacker, pDefender, pDamage);

    int64_t totalDamage = (int64_t)(((uint64_t)pDamage->dwDmgTotal) | ((uint64_t)pDamage->dwAbsLife << 32));
    return totalDamage;
}

void __fastcall SUNITDMG_CalculateTotalDamage_ESEDamageCalc(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    //D2Game.0x6FD3F090
    constexpr D2DamageStatTableStrc sgDamageStatTable[12] =
    {
        { offsetof(D2DamageStrc, dwPhysDamage),	STAT_DAMAGERESIST,				-1,						-1,							-1,								-1,						DAMAGE_REDUCTION_PHYSICAL,	0, 1, "Dam", 8, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwFireDamage),	STAT_FIRERESIST,				STAT_MAXFIRERESIST,		STAT_PASSIVE_FIRE_PIERCE,	STAT_ITEM_ABSORBFIRE_PERCENT,	STAT_ITEM_ABSORBFIRE,	DAMAGE_REDUCTION_MAGICAL,	0, 1, "Fire", 8, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwLtngDamage),	STAT_LIGHTRESIST,				STAT_MAXLIGHTRESIST,	STAT_PASSIVE_LTNG_PIERCE,	STAT_ITEM_ABSORBLIGHT_PERCENT,	STAT_ITEM_ABSORBLIGHT,	DAMAGE_REDUCTION_MAGICAL,	0, 1, "Ligt", 8, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwColdDamage),	STAT_COLDRESIST,				STAT_MAXCOLDRESIST,		STAT_PASSIVE_COLD_PIERCE,	STAT_ITEM_ABSORBCOLD_PERCENT,	STAT_ITEM_ABSORBCOLD,	DAMAGE_REDUCTION_MAGICAL,	0, 1, "Cold", 8, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwMagDamage),	STAT_MAGICRESIST,				STAT_MAXMAGICRESIST,	-1,							STAT_ITEM_ABSORBMAGIC_PERCENT,	STAT_ITEM_ABSORBMAGIC,	DAMAGE_REDUCTION_MAGICAL,	0, 1, "Magc", 8, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwColdLen),	STAT_COLDRESIST,				STAT_MAXCOLDRESIST,		STAT_PASSIVE_COLD_PIERCE,	-1,								-1,						DAMAGE_REDUCTION_NONE,		0, 0, "Clen", 0, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwFrzLen),		STAT_COLDRESIST,				STAT_MAXCOLDRESIST,		STAT_PASSIVE_COLD_PIERCE,	-1,								-1,						DAMAGE_REDUCTION_NONE,		0, 0, "Flen", 0, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwPoisLen),	STAT_ITEM_POISONLENGTHRESIST,	-1,						STAT_PASSIVE_POIS_PIERCE,	-1,								-1,						DAMAGE_REDUCTION_NONE,		0, 0, "Plen", 0, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwPoisDamage),	STAT_POISONRESIST,				STAT_MAXPOISONRESIST,	STAT_PASSIVE_POIS_PIERCE,	-1,								-1,						DAMAGE_REDUCTION_NONE,		0, 1, "Pois", 0, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwLifeLeech),	-1,								-1,						-1,							-1,								-1,						DAMAGE_REDUCTION_NONE,		1, 1, "Life", 8, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwManaLeech),	-1,								-1,						-1,							-1,								-1,						DAMAGE_REDUCTION_NONE,		1, 1, "Mana", 8, 0, 0, 0 },
        { offsetof(D2DamageStrc, dwStamLeech),	-1,								-1,						-1,							-1,								-1,						DAMAGE_REDUCTION_NONE,		1, 1, "Stam", 8, 0, 0, 0 },
    };

    D2DamageInfoStrc damageInfo = {};
    damageInfo.pGame = pGame;
    damageInfo.pAttacker = pAttacker;
    damageInfo.pDifficultyLevelsTxt = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    damageInfo.pDefender = pDefender;
    damageInfo.pDamage = pDamage;


    damageInfo.bAttackerIsMonster = 0;
    if (damageInfo.pAttacker && pAttacker->dwUnitType == UNIT_MONSTER && !MONSTERS_GetHirelingTypeId(pAttacker))
    {
        damageInfo.bAttackerIsMonster = 1;
    }

    damageInfo.bDefenderIsMonster = 0;
    if (pDefender && pDefender->dwUnitType == UNIT_MONSTER && !MONSTERS_GetHirelingTypeId(pDefender))
    {
        damageInfo.bDefenderIsMonster = 1;
    }

    damageInfo.nDamageReduction[0] = 0;

    int32_t nDamageReduction = STATLIST_UnitGetStatValue(pDefender, STAT_NORMAL_DAMAGE_REDUCTION, 0) << 8;
    if (nDamageReduction > 0 && pDamage->dwPiercePct > 0)
    {
        nDamageReduction = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(nDamageReduction, pDamage->dwPiercePct, 1024);
    }
    damageInfo.nDamageReduction[1] = nDamageReduction;

    int32_t nMagicDamageReduction = STATLIST_UnitGetStatValue(pDefender, STAT_MAGIC_DAMAGE_REDUCTION, 0) << 8;
    if (nMagicDamageReduction > 0 && pDamage->dwPiercePct > 0)
    {
        nMagicDamageReduction = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(nMagicDamageReduction, pDamage->dwPiercePct, 1024);
    }
    damageInfo.nDamageReduction[2] = nMagicDamageReduction;

    if (damageInfo.pAttacker && damageInfo.pDefender && damageInfo.pAttacker != damageInfo.pDefender)
    {
        int32_t nDamagePercent = 100;

        if (damageInfo.pDefender->dwUnitType == UNIT_PLAYER)
        {
            if (damageInfo.pAttacker->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(damageInfo.pAttacker) || damageInfo.pAttacker->dwFlags & UNITFLAG_ISREVIVE)
            {
                nDamagePercent = 17;
            }
        }
        else if (MONSTERS_GetHirelingTypeId(damageInfo.pDefender) && MONSTERS_GetHirelingTypeId(damageInfo.pAttacker))
        {
            nDamagePercent = 25;
        }
        else if (MONSTERS_GetHirelingTypeId(damageInfo.pAttacker) && MONSTERS_IsBoss(nullptr, damageInfo.pDefender))
        {
            if (damageInfo.pDifficultyLevelsTxt)
            {
                nDamagePercent = damageInfo.pDifficultyLevelsTxt->dwHireableBossDmgPercent;
            }
        }
        else if (MONSTERS_IsPrimeEvil(damageInfo.pAttacker) && damageInfo.pDefender && damageInfo.pDefender->dwFlags & UNITFLAG_ISREVIVE)
        {
            if (MONSTERS_GetHirelingTypeId(damageInfo.pDefender))
            {
                nDamagePercent = 200;
            }
            else
            {
                nDamagePercent = 400;
            }
        }

        if (nDamagePercent != 100)
        {
            // TODO: What is this case?
            for (int32_t i = 0; i < std::size(sgDamageStatTable); ++i)
            {
                const D2DamageStatTableStrc* pDamageStatTableRecord = &sgDamageStatTable[i];
                if (pDamageStatTableRecord->unk0x20)
                {
                    int32_t* pDamageValue = (int32_t*)((char*)damageInfo.pDamage + pDamageStatTableRecord->nOffsetInDamageStrc);
                    if (*pDamageValue > 0)
                    {
                        *pDamageValue = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(*pDamageValue, nDamagePercent, 100);
                    }
                }
            }
        }
    }

    SUNITEVENT_EventFunc_Handler(pGame, EVENT_ABSORBDAMAGE, pDefender, pAttacker, pDamage);

    if (damageInfo.pDamage->dwColdLen > 0 || damageInfo.pDamage->dwFrzLen > 0)
    {
        if (STATLIST_UnitGetItemStatOrSkillStatValue(damageInfo.pDefender, STAT_ITEM_CANNOTBEFROZEN, 0))
        {
            damageInfo.pDamage->dwColdLen = 0;
            damageInfo.pDamage->dwFrzLen = 0;
        }
        else if (STATLIST_UnitGetItemStatOrSkillStatValue(damageInfo.pDefender, STAT_ITEM_HALFFREEZEDURATION, 0))
        {
            damageInfo.pDamage->dwColdLen /= 2;
            damageInfo.pDamage->dwFrzLen /= 2;
        }
    }

    if (damageInfo.pDamage->dwPoisLen > 0 && STATES_CheckState(damageInfo.pDefender, STATE_SHRINE_RESIST_POISON))
    {
        damageInfo.pDamage->dwPoisLen = 0;
    }

    if (damageInfo.pDamage->dwBurnLen > 0 && STATES_CheckState(damageInfo.pDefender, STATE_SHRINE_RESIST_FIRE))
    {
        damageInfo.pDamage->dwBurnLen = 0;
    }

    int32_t bDontAbsorb = 0;
    if (pDefender && pDefender->dwUnitType == UNIT_MONSTER)
    {
        const int32_t bIsUndead = MONSTERS_IsUndead(pDefender);
        const int32_t bIsDemon = MONSTERS_IsDemon(pDefender);
        if (bIsUndead && pDamage->dwHitFlags & DAMAGEHITFLAG_BYPASSUNDEAD)
        {
            bDontAbsorb = 1;
        }

        if (bIsDemon && pDamage->dwHitFlags & DAMAGEHITFLAG_BYPASSDEMON)
        {
            bDontAbsorb = 1;
        }

        if (!bIsUndead && !bIsDemon && pDamage->dwHitFlags & DAMAGEHITFLAG_BYPASSBEASTS)
        {
            bDontAbsorb = 1;
        }
    }
    else
    {
        if (pDamage->dwHitFlags & DAMAGEHITFLAG_BYPASSBEASTS)
        {
            bDontAbsorb = 1;
        }
    }

    int64_t dmgTotal = 0;
    for (int32_t i = 0; i < std::size(sgDamageStatTable); ++i)
    {
        const D2DamageStatTableStrc* pDamageStatTableRecord = &sgDamageStatTable[i];
        if (pDamageStatTableRecord->unk0x1C && !damageInfo.bAttackerIsMonster)
        {
            break;
        }

        auto damage = SUNITDMG_ApplyResistancesAndAbsorb_ESEDamageCalc_64(&damageInfo, pDamageStatTableRecord, bDontAbsorb);
        dmgTotal += damage;
    }

    if (damageInfo.bAttackerIsMonster)
    {
        dmgTotal += pDamage->dwLifeLeech;
    }

    if (dmgTotal < 0)
    {
        dmgTotal = 0;
    }

    pDamage->dwDmgTotal = (uint32_t)(dmgTotal & 0xFFFFFFFF);
    pDamage->dwAbsLife = (uint32_t)(dmgTotal >> 32);
}

int64_t __fastcall MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(int64_t nValue, int64_t nPercentage, int64_t divisor)
{
    if (nValue <= 0x100000)
    {
        if (nPercentage <= 0x10000)
        {
            return (nValue * nPercentage) / divisor;
        }
        if ((nPercentage >> 4) >= divisor)
        {
            return nValue * (nPercentage / divisor);
        }
    }
    else if ((nPercentage >> 4) >= divisor)
    {
        return nPercentage * (nValue / divisor);
    }

    return nValue * (__int64)nPercentage / divisor;
}

int32_t __fastcall MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(int32_t nValue, int32_t nPercentage, int32_t divisor)
{
    const auto result = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nValue, nPercentage, divisor);
    if (result > INT32_MAX)
    {
        return INT32_MAX;
    }

    if (result < INT32_MIN)
    {
        return INT32_MIN;
    }

    return (int32_t)result;
}

int64_t SUNITDMG_ApplyResistancesAndAbsorb_ESEDamageCalc_64(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb)
{
    auto pValue = (int*)((char*)pDamageInfo->pDamage + pDamageStatTableRecord->nOffsetInDamageStrc);
    int64_t nValue = *pValue;
    int64_t nPreviousValue = *pValue;

    if (*pValue <= 0)
    {
        *pValue = 0;
        return 0;
    }

    auto nResValue = 0;
    if (pDamageStatTableRecord->nResStatId != -1)
    {
        nResValue = STATLIST_UnitGetStatValue(pDamageInfo->pDefender, pDamageStatTableRecord->nResStatId, 0);
    }

    if (pDamageStatTableRecord->nPierceStatId != -1 && (nResValue < 100 || !pDamageInfo->bDefenderIsMonster))
    {
        auto nPierceValue = STATLIST_UnitGetStatValue(pDamageInfo->pAttacker, pDamageStatTableRecord->nPierceStatId, 0);
        if (nPierceValue)
        {
            nResValue -= nPierceValue;
        }
    }

    if (!pDamageInfo->bDefenderIsMonster)
    {
        if (pDamageStatTableRecord->nResStatId != STAT_DAMAGERESIST && pDamageStatTableRecord->nResStatId != STAT_MAGICRESIST)
        {
            if (pDamageInfo->pGame->bExpansion)
            {
                nResValue += pDamageInfo->pDifficultyLevelsTxt->dwResistPenalty;
            }
            else if (pDamageInfo->pGame->nDifficulty == DIFFMODE_NIGHTMARE)
            {
                nResValue -= 20;
            }
            else if (pDamageInfo->pGame->nDifficulty == DIFFMODE_HELL)
            {
                nResValue -= 50;
            }
        }
    }

    if (nResValue > 0)
    {
        if (!pDamageInfo->bDefenderIsMonster)
        {
            auto nMaxResValue = 95;
            if (pDamageStatTableRecord->nMaxResStatId == -1)
            {
                if (pDamageStatTableRecord->nResStatId == STAT_DAMAGERESIST)
                {
                    nMaxResValue = 90;
                }
            }
            else
            {
                nMaxResValue = STATLIST_UnitGetStatValue(pDamageInfo->pDefender, pDamageStatTableRecord->nMaxResStatId, pDamageInfo->bDefenderIsMonster) + 75;
                if (nMaxResValue >= 95)
                {
                    nMaxResValue = 95;
                }
            }
            if (nResValue >= nMaxResValue)
            {
                nResValue = nMaxResValue;
            }
        }
        if (pDamageStatTableRecord->nResStatId == STAT_DAMAGERESIST
            && STATES_CheckState(pDamageInfo->pAttacker, STATE_SANCTUARY)
            && MONSTERS_IsUndead(pDamageInfo->pDefender))
        {
            nResValue = 0;
        }
    }

    if (bDontAbsorb)
    {
        if (nResValue > 0)
        {
            nResValue = 0;
        }
    }
    else
    {
        nValue = nPreviousValue - pDamageInfo->nDamageReduction[pDamageStatTableRecord->nDamageReductionType];
        // todo: don't let nValue drop below 0 (monster attacked us, causing negative damage from damage reduction)?
    }

    if (nValue > 0 && nResValue)
    {
        if (nResValue >= 100)
        {
            nResValue = 100;
        }

        nValue = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nValue, 100 - nResValue, 100);
    }

    if (!bDontAbsorb && pDamageStatTableRecord->nAbsorbPctStatId != -1)
    {
        auto nAbsorbPctValue = STATLIST_UnitGetStatValue(pDamageInfo->pDefender, pDamageStatTableRecord->nAbsorbPctStatId, 0);
        if (nAbsorbPctValue > 0)
        {
            if (nAbsorbPctValue > 98)
            {
                nAbsorbPctValue = 98;
            }

            auto damageAbsorbed = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nValue, nAbsorbPctValue, 100);
            nValue -= damageAbsorbed;
        }

        auto nAbsorbStatValue = STATLIST_UnitGetStatValue(pDamageInfo->pDefender, pDamageStatTableRecord->nAbsorbStatId, 0) << 8;
        if (nAbsorbStatValue > 0)
        {
            if (nAbsorbStatValue >= nValue)
            {
                nAbsorbStatValue = nValue;
            }

            nValue -= nAbsorbStatValue;
        }
    }

    if (nValue > INT32_MAX)
    {
        *pValue = INT32_MAX;
    }
    else if (nValue < INT32_MIN)
    {
        *pValue = INT32_MIN;
    }
    else
    {
        *pValue = (int32_t)nValue;
    }

    return nValue;
}

void __fastcall SUNITDMG_AllocCombat_ESEDamageCalc(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, uint8_t nSrcDam)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    const auto dodgedAttack = pDamage->wResultFlags & DAMAGERESULTFLAG_DODGE | DAMAGERESULTFLAG_AVOID | DAMAGERESULTFLAG_EVADE | DAMAGERESULTFLAG_WEAPONBLOCK;
    const auto isSuccessfulHit = pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT;

    if (!dodgedAttack && isSuccessfulHit)
    {
        if (!(pDamage->dwHitFlags & DAMAGEHITFLAG_2))
        {
            SUNITDMG_FillDamageValues(pGame, pAttacker, pDefender, pDamage, 0, nSrcDam);
        }

        auto nTotalDamage = SUNITDMG_CalculateTotalDamage_ESEDamageCalc_64(pGame, pAttacker, pDefender, pDamage);

        const int64_t nHitpoints = STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0);

        if ((nTotalDamage >> 8) > (nHitpoints >> 8))
        {
            pDamage->wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
        }
    }

    if (pDefender->dwUnitType != UNIT_MONSTER && pDefender->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2CombatStrc* pCombat = D2_ALLOC_STRC_POOL(pGame->pMemoryPool, D2CombatStrc);
    pCombat->pGame = pGame;
    pCombat->dwAttackerType = pAttacker->dwUnitType;
    pCombat->dwAttackerId = pAttacker->dwUnitId;
    pCombat->dwDefenderType = pDefender->dwUnitType;
    pCombat->dwDefenderId = pDefender->dwUnitId;
    memcpy(&pCombat->tDamage, pDamage, sizeof(pCombat->tDamage));
    pCombat->pNext = pAttacker->pCombat;
    pAttacker->pCombat = pCombat;
}
