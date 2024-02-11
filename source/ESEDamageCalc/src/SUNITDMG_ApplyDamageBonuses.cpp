#include "ESEDamageCalc.h"

#include <PLAYER/Player.h>
#include <D2StatList.h>
#include <D2Skills.h>
#include <ITEMS/Items.h>

int32_t __fastcall SUNITDMG_ApplyDamageBonuses_ESEDamageCalc(D2UnitStrc* pUnit, int32_t bGetStats, D2UnitStrc* pItem, int32_t nMinDmg, int32_t nMaxDmg, int32_t nDamagePercent, int32_t nDamage, uint8_t nSrcDam)
{
    int64_t nMinDamage = 0;
    int64_t nMaxDamage = 0;

    if (bGetStats)
    {
        if (!pItem)
        {
            pItem = sub_6FC7C7B0(pUnit);
        }

        if (pItem)
        {
            if (INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
            {
                nMinDamage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0) << 8;
                nMaxDamage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0) << 8;
            }
            else
            {
                nMinDamage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0) << 8;
                nMaxDamage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0) << 8;
            }
        }
        else
        {
            nMinDamage = std::max(STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0), 1);
            nMaxDamage = std::max(STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0), 2);

            nMinDamage <<= 8;
            nMaxDamage <<= 8;
        }
    }
    else
    {
        nMinDamage = nMinDmg;
        nMaxDamage = nMaxDmg;
    }

    const int64_t nNormalDamage = (int64_t)STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_NORMALDAMAGE, 0) << 8;
    int64_t nTotalMinDamage = nNormalDamage + nMinDamage;
    int64_t nTotalMaxDamage = nNormalDamage + nMaxDamage;

    if (nTotalMinDamage < 1)
    {
        nTotalMinDamage = 256;
    }

    if (nTotalMaxDamage <= nTotalMinDamage)
    {
        nTotalMaxDamage = nTotalMinDamage + 256;
    }

    int64_t nDamagePct = (int64_t)nDamagePercent + (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);

    if (pItem)
    {
        const int64_t nStrengthBonus = ITEMS_GetStrengthBonus(pItem);
        if (nStrengthBonus)
        {
            nDamagePct += nStrengthBonus * STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) / 100ll;
        }

        const int64_t nDexterityBonus = ITEMS_GetDexBonus(pItem);
        if (nDexterityBonus)
        {
            nDamagePct += nDexterityBonus * STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) / 100ll;
        }

        nDamagePct += SKILLS_GetWeaponMasteryBonus(pUnit, pItem, 0, 1);
    }
    else if (bGetStats)
    {
        nDamagePct += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
    }

    nDamagePct = std::max(nDamagePct, -90ll);

    int64_t result = nDamage;
    if (nTotalMaxDamage > 0)
    {
        nTotalMinDamage += MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nTotalMinDamage, nDamagePct + STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0), 100);
        nTotalMaxDamage += MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nTotalMaxDamage, nDamagePct + STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0), 100);

        result += nTotalMinDamage;
        if (nTotalMaxDamage > nTotalMinDamage)
        {
            result += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nTotalMaxDamage - nTotalMinDamage);
        }
    }

    if (result < 0)
    {
        result = 0;
    }

    if (nSrcDam == 128)
    {
        return result;
    }

    auto finalResult = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(result, nSrcDam, 128);
    finalResult = std::clamp(finalResult, (int64_t)INT32_MIN, (int64_t)INT32_MAX);
    
    return (int32_t)finalResult;
}
