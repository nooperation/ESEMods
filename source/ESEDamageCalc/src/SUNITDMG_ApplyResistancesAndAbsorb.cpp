#include "ESEDamageCalc.h"

#include <D2States.h>
#include <SKILLS/Skills.h>

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
