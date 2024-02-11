#include "ESEDamageCalc.h"
#include <D2StatList.h>
#include <D2Skills.h>
#include <SKILLS/Skills.h>
#include <D2Combat.h>


D2SkillsTxt* __fastcall DATATBLS_GetSkillsTxtRecord_ESEDamageCalc(int nSkillId)
{
	if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
	{
		return &sgptDataTables->pSkillsTxt[nSkillId];
	}

	return NULL;
}

int64_t SKILLS_CalculateDamageBonusByLevel_ESEDamageCalc_64(int nLevel, int* pLevelDamage)
{
	if (nLevel > 1 && pLevelDamage)
	{
		if (nLevel > 28)
		{
			return 7ll * *pLevelDamage + (int64_t)(pLevelDamage[4]) * ((int64_t)nLevel - 28) + 6ll * ((int64_t)(pLevelDamage[2]) + (int64_t)(pLevelDamage[3])) + 8ll * pLevelDamage[1];
		}
		else if (nLevel > 22)
		{
			return 7ll * *pLevelDamage + (int64_t)(pLevelDamage[3]) * ((int64_t)nLevel - 22) + 6ll * (int64_t)(pLevelDamage[2]) + 8ll * pLevelDamage[1];
		}
		else if (nLevel > 16)
		{
			return 7ll * *pLevelDamage + (int64_t)(pLevelDamage[2]) * ((int64_t)nLevel - 16) + 8ll * (int64_t)(pLevelDamage[1]);
		}
		else if (nLevel > 8)
		{
			return 7ll * *pLevelDamage + (int64_t)(pLevelDamage[1]) * ((int64_t)nLevel - 8);
		}
		else
		{
			return (int64_t)(*pLevelDamage) * ((int64_t)nLevel - 1);
		}

	}

	return 0;
}

//D2Common.0x6FDB2810 (#11004)
int __stdcall SKILLS_GetMinElemDamage_ESEDamageCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	int64_t nDamage = 0;
	int64_t nBonus = 0;

	pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_ESEDamageCalc(nSkillId);

	if (pSkillsTxtRecord && nSkillLevel > 0)
	{
		nDamage = pSkillsTxtRecord->dwEMin;
		nDamage += SKILLS_CalculateDamageBonusByLevel_ESEDamageCalc_64(nSkillLevel, (int*)pSkillsTxtRecord->dwEMinLev);
		nDamage <<= pSkillsTxtRecord->nToHitShift;

		if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1 && (nDamage > 256 || pSkillsTxtRecord->dwEMinLev[0]))
		{
			nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

			if (nBonus)
			{
				nDamage += nDamage * nBonus / 100ll;
			}
		}

		if (a4 && pUnit)
		{
			nDamage += SKILLS_CalculateMasteryBonus_ESEDamageCalc_64(pUnit, pSkillsTxtRecord->nEType, nDamage);
		}

		nDamage = std::clamp(nDamage, (int64_t)INT32_MIN, (int64_t)INT32_MAX);
		return (int32_t)nDamage;
	}

	return 0;
}

int64_t SKILLS_CalculateMasteryBonus_ESEDamageCalc_64(D2UnitStrc* pUnit, int32_t nElemType, int64_t nSrcDamage)
{
	int64_t nPercentage = 0;

	switch (nElemType)
	{
	case ELEMTYPE_FIRE:
		nPercentage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_FIRE_MASTERY, 0);
		if (!nPercentage)
		{
			return 0;
		}

		return nSrcDamage * nPercentage / 100ll;
	case ELEMTYPE_LTNG:
		nPercentage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_LTNG_MASTERY, 0);
		if (!nPercentage)
		{
			return 0;
		}

		return nSrcDamage * nPercentage / 100ll;
	case ELEMTYPE_COLD:
	case ELEMTYPE_FREEZE:
		nPercentage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_COLD_MASTERY, 0);
		if (!nPercentage)
		{
			return 0;
		}

		return nSrcDamage * nPercentage / 100ll;
	case ELEMTYPE_POIS:
		nPercentage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_POIS_MASTERY, 0);
		if (!nPercentage)
		{
			return 0;
		}
		
		return nSrcDamage * nPercentage / 100ll;
	default:
		return 0;
	}
}

//D2Common.0x6FDB2B00 (#11005)
int __stdcall SKILLS_GetMaxElemDamage_ESEDamageCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	int64_t nDamage = 0;
	int64_t nBonus = 0;

	pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_ESEDamageCalc(nSkillId);

	if (pSkillsTxtRecord && nSkillLevel > 0)
	{
		nDamage = (int64_t)pSkillsTxtRecord->dwEMax;
		nDamage += SKILLS_CalculateDamageBonusByLevel_ESEDamageCalc_64(nSkillLevel, (int*)pSkillsTxtRecord->dwEMaxLev);
		nDamage <<= pSkillsTxtRecord->nToHitShift;

		if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1)
		{
			nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

			if (nBonus)
			{
				nDamage += nDamage * nBonus / 100ll;
			}
		}

		if (a4 && pUnit)
		{
			nDamage += SKILLS_CalculateMasteryBonus_ESEDamageCalc_64(pUnit, pSkillsTxtRecord->nEType, nDamage);
		}

		nDamage = std::clamp(nDamage, (int64_t)INT32_MIN, (int64_t)INT32_MAX);
		return (int32_t)nDamage;
	}

	return 0;
}

//D2Common.0x6FDB2390 (#11002)
int __stdcall SKILLS_GetMinPhysDamage_ESEDamageCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	D2UnitStrc* pItem = NULL;
	int64_t nDamage = 0;
	int64_t nBonus = 0;

	pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_ESEDamageCalc(nSkillId);

	if (pSkillsTxtRecord)
	{
		if (pSkillsTxtRecord->dwFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_KICK])
		{
			if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
			{
				nDamage = 3 * (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
			}
			else
			{
				nDamage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) + (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) - 20;
			}

			if (nDamage < 1)
			{
				nDamage = 1;
			}

			return nDamage / 4 << 8;
		}
		else
		{
			if (pSkillsTxtRecord->nSrcDam && a4)
			{
				pItem = D2Common_10434(pUnit, 0);
				int64_t nMinDamage = 0;
				if (pItem && INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
				{
					nMinDamage = STATLIST_GetMinDamageFromUnit(pItem, 1);
				}
				else
				{
					nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
				}
				nDamage = (nMinDamage * (int64_t)pSkillsTxtRecord->nSrcDam) / 128;
			}

			nDamage += (int64_t)pSkillsTxtRecord->dwMinDam + SKILLS_CalculateDamageBonusByLevel_ESEDamageCalc_64(nSkillLevel, (int*)pSkillsTxtRecord->dwMinLvlDam);

			if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
			{
				nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);

				if (nBonus)
				{
					nDamage += nDamage * nBonus / 100;
				}
			}

			auto result = nDamage << pSkillsTxtRecord->nToHitShift;
			result = std::clamp(result, (int64_t)INT32_MIN, (int64_t)INT32_MAX);

			return (int32_t)result;
		}
	}

	return 1;
}

//D2Common.0x6FDB25D0 (#11003)
int __stdcall SKILLS_GetMaxPhysDamage_ESEDamageCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	D2UnitStrc* pItem = NULL;
	int64_t nDamage = 0;
	int64_t nBonus = 0;

	pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_ESEDamageCalc(nSkillId);

	if (pSkillsTxtRecord)
	{
		if (pSkillsTxtRecord->dwFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_KICK])
		{
			if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
			{
				nDamage = 3 * (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
			}
			else
			{
				nDamage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) + (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) - 20;
			}

			if (nDamage < 1)
			{
				nDamage = 1;
			}

			return nDamage / 3 << 8;
		}
		else
		{
			if (pSkillsTxtRecord->nSrcDam && a4)
			{
				pItem = D2Common_10434(pUnit, 0);
				int64_t nMaxDamage = 0;
				if (pItem && INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
				{
					nMaxDamage = (int64_t)STATLIST_GetMaxDamageFromUnit(pItem, 24) * (int64_t)pSkillsTxtRecord->nSrcDam;
				}
				else
				{
					nMaxDamage = (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0) * (int64_t)pSkillsTxtRecord->nSrcDam;
				}

				nDamage = nMaxDamage / 128;
			}

			nDamage += (int64_t)pSkillsTxtRecord->dwMaxDam + SKILLS_CalculateDamageBonusByLevel_ESEDamageCalc_64(nSkillLevel, (int*)pSkillsTxtRecord->dwMaxLvlDam);

			if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
			{
				nBonus = (int64_t)SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);

				if (nBonus)
				{
					nDamage += nDamage * nBonus / 100;
				}
			}

			auto result = nDamage << pSkillsTxtRecord->nToHitShift;
			result = std::clamp(result, (int64_t)INT32_MIN, (int64_t)INT32_MAX);

			return (int32_t)result;
		}
	}

	return 2;
}