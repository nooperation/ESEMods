#include "ESEDamageCalc.h"

#include <D2Dungeon.h>
#include <D2States.h>
#include <SKILLS/Skills.h>
#include <SKILLS/SkillAss.h>
#include <UNIT/SUnit.h>
#include <UNIT/SUnitEvent.h>
#include <ITEMS/Items.h>
#include <GAME/SCmd.h>
#include <AI/AiGeneral.h>

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

        D2ClientStrc* ownerClient = nullptr;
        if (nAttackerUnitType == UNIT_PLAYER)
        {
            if (pAttacker != nullptr && pAttacker->pPlayerData != nullptr)
            {
                ownerClient = pAttacker->pPlayerData->pClient;
            }
        }
        else if (nAttackerUnitType == UNIT_MONSTER) 
        {
            auto owner = AIGENERAL_GetMinionOwner(pAttacker);
            if (owner != nullptr && owner->pPlayerData != nullptr)
            {
                ownerClient = owner->pPlayerData->pClient;
            }
        }

        if (ownerClient != nullptr)
        {
            DamageReportPacket packet;
            packet.packetId = 0x45;
            packet.unitId = pDefender->dwUnitId;
            packet.damage = damageTotal;
            packet.unknownA = 1;
            packet.unknownB = 0;
            packet.unknownC = 0;
            packet.unknownD = 0;

            D2GAME_PACKETS_SendPacket_6FC3C710(ownerClient, &packet, sizeof(packet));
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
