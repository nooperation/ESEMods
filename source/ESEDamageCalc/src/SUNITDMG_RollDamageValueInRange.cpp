#include "ESEDamageCalc.h"

#include <D2StatList.h>
#include <ITEMS/Items.h>

//D2Game.0x6FCBF450
int32_t __fastcall SUNITDMG_RollDamageValueInRange_ESEDamageCalc(D2UnitStrc* pUnit, int32_t nMinDamageCAPPED, int32_t nMaxDamageCAPPED, int32_t nMinDamageBonusPct, int32_t nMaxDamageBonusPct, int32_t nDamageCAPPED)
{
	int64_t nDamage = nDamageCAPPED;
	int64_t nMinDamage = nMinDamageCAPPED;
	int64_t nMaxDamage = nMaxDamageCAPPED;

	if (nMaxDamage > 0)
	{
		nMinDamage += MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nMinDamage, nMinDamageBonusPct, 100);

		nMaxDamage += MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nMaxDamage, nMaxDamageBonusPct, 100);

		nDamage += nMinDamage;

		if (nMaxDamage > nMinDamage)
		{
			auto maxMinDamageDiff = std::clamp(nMaxDamage - nMinDamage, (int64_t)INT32_MIN, (int64_t)INT32_MAX);

			nDamage += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, (int32_t)maxMinDamageDiff);
		}
	}

	return std::max(nDamage, 0ll);
}
