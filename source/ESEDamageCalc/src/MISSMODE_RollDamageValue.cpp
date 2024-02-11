#include "ESEDamageCalc.h"

#include <D2StatList.h>
#include <ITEMS/Items.h>

int32_t __fastcall MISSMODE_RollDamageValue_ESEDamageCalc(D2UnitStrc* pUnit, int32_t nMinDamStat, int32_t nMaxDamStat, int32_t nMasteryStat)
{
    int64_t nMaxDam = STATLIST_UnitGetStatValue(pUnit, nMaxDamStat, 0);
    if (nMaxDam <= 0)
    {
        return 0;
    }

    int64_t nMinDam = STATLIST_UnitGetStatValue(pUnit, nMinDamStat, 0);
    if (nMinDam <= 0)
    {
        return 0;
    }

    if (nMinDam > nMaxDam)
    {
        const auto nTemp = nMaxDam;

        nMaxDam = nMinDam;
        nMinDam = nTemp;
    }

    if (nMasteryStat != -1)
    {
        const int32_t nMastery = STATLIST_UnitGetStatValue(pUnit, nMasteryStat, 0);
        if (nMastery)
        {
            nMinDam += MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nMinDam, nMastery, 100);
            nMaxDam += MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nMaxDam, nMastery, 100);
        }
    }

    auto maxMinDiff = std::clamp(nMaxDam - nMinDam, (int64_t)INT32_MIN, (int64_t)INT32_MAX);

    auto resultUncapped = nMinDam + (int64_t)ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, (int32_t)maxMinDiff);
    resultUncapped = std::clamp(resultUncapped, (int64_t)INT32_MIN, (int64_t)INT32_MAX);

    return (int32_t)resultUncapped;
}