#include "D2Common/D2Skills_ESE.h"
#include "D2Common/Units/Missile_ESE.h"

#include <D2Collision.h>
#include <D2Composit.h>
#include <D2DataTbls.h>
#include <D2Dungeon.h>
#include <D2Inventory.h>
#include <D2ItemMods.h>
#include <D2Items.h>
#include <Path/Path.h>
#include <D2Seed.h>
#include <D2States.h>
#include <D2StatList.h>
#include <Units/Units.h>
#include <D2BitManip.h>
#include <DataTbls/SkillsIds.h>
#include <D2Combat.h>
#include <D2Monsters.h>
#include <Calc.h>

// Inlined, not intercepted
D2SkillsTxt* __fastcall ESE_DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
	if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
	{
		return &sgptDataTables->pSkillsTxt[nSkillId];
	}

	return NULL;
}
// Inlined, not intercepted
D2SkillDescTxt* __fastcall ESE_DATATBLS_GetSkillDescTxtRecord(int nSkillDesc)
{
	if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
	{
		return &sgptDataTables->pSkillDescTxt[nSkillDesc];
	}

	return NULL;
}


//D2Common.0x6FDAEB60 (#11271)
//TODO: v8
int __stdcall ESE_SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, uint8_t nParamId, int nSkillId, int nSkillLevel)
{
	D2SkillDescTxt* pSkillDescTxtRecord = NULL;
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	D2SkillStrc* pSkill = NULL;
	int nMissileId = 0;
	D2SkillCalcStrc pSkillCalc = {};

	pSkillsTxtRecord = ESE_DATATBLS_GetSkillsTxtRecord(nSkillId);
	if (pSkillsTxtRecord)
	{
		switch (nParamId)
		{
		case 0:
			if (nSkillLevel > 0)
			{
				return pSkillsTxtRecord->dwParam[0] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[1];
			}
			break;

		case 1:
			if (nSkillLevel > 0)
			{
				return ESE_D2Common_11033(nSkillLevel, pSkillsTxtRecord->dwParam[0], pSkillsTxtRecord->dwParam[1]);
			}
			break;

		case 2:
			if (nSkillLevel > 0)
			{
				return pSkillsTxtRecord->dwParam[2] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[3];
			}
			break;

		case 3:
			if (nSkillLevel > 0)
			{
				return ESE_D2Common_11033(nSkillLevel, pSkillsTxtRecord->dwParam[2], pSkillsTxtRecord->dwParam[3]);
			}
			break;

		case 4:
			if (nSkillLevel > 0)
			{
				return pSkillsTxtRecord->dwParam[4] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[5];
			}
			break;

		case 5:
			if (nSkillLevel > 0)
			{
				return ESE_D2Common_11033(nSkillLevel, pSkillsTxtRecord->dwParam[4], pSkillsTxtRecord->dwParam[5]);
			}
			break;

		case 6:
			if (nSkillLevel > 0)
			{
				return pSkillsTxtRecord->dwParam[6] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[7];
			}
			break;

		case 7:
			return ESE_D2Common_11033(nSkillLevel, pSkillsTxtRecord->dwParam[6], pSkillsTxtRecord->dwParam[7]);

		case 8:
			return pSkillsTxtRecord->dwParam[0];

		case 9:
			return pSkillsTxtRecord->dwParam[1];

		case 10:
			return pSkillsTxtRecord->dwParam[2];

		case 11:
			return pSkillsTxtRecord->dwParam[3];

		case 12:
			return pSkillsTxtRecord->dwParam[4];

		case 13:
			return pSkillsTxtRecord->dwParam[5];

		case 14:
			return pSkillsTxtRecord->dwParam[6];

		case 15:
			return pSkillsTxtRecord->dwParam[7];

		case 16:
			return nSkillLevel;

		case 17:
			return ESE_SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;

		case 18:
			return ESE_SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;

		case 19:
			return ESE_SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);

		case 20:
			if (nSkillLevel > 0)
			{
				if (pSkillsTxtRecord->dwToHitCalc == -1)
				{
					return pSkillsTxtRecord->dwToHit + (nSkillLevel - 1) * pSkillsTxtRecord->dwLevToHit;
				}
				else
				{
					return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwToHitCalc, nSkillId, nSkillLevel);
				}
			}
			break;

		case 21:
			if (nSkillLevel > 0)
			{
				return ESE_SKILLS_GetManaCosts(nSkillId, nSkillLevel) >> 8;
			}
			break;

		case 22:
			if (nSkillLevel > 0)
			{
				int32_t nTemp = ((25 * pSkillsTxtRecord->wMana) + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana);
				nTemp /= 2;
				nTemp <<= pSkillsTxtRecord->nManaShift;
				return nTemp >> 8;
			}
			break;

		case 23:
			return D2Common_11032(pUnit, nSkillId, nSkillLevel, 0);

		case 24:
			return D2Common_11032(pUnit, nSkillId, nSkillLevel, 1);

		case 25:
			return D2Common_11032(pUnit, nSkillId, nSkillLevel, 2);

		case 26:
		case 29:
		case 32:
			if (nSkillLevel > 0)
			{
				pSkillDescTxtRecord = ESE_DATATBLS_GetSkillDescTxtRecord(pSkillsTxtRecord->wSkillDesc);
				if (pSkillDescTxtRecord)
				{
					nMissileId = pSkillDescTxtRecord->wDescMissile[(nParamId - 26) / 3];
					if (ESE_DATATBLS_GetMissilesTxtRecord(nMissileId))
					{
						return ESE_MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
					}
				}
			}
			break;

		case 27:
		case 30:
		case 33:
			if (nSkillLevel > 0)
			{
				pSkillDescTxtRecord = ESE_DATATBLS_GetSkillDescTxtRecord(pSkillsTxtRecord->wSkillDesc);
				if (pSkillDescTxtRecord)
				{
					nMissileId = pSkillDescTxtRecord->wDescMissile[(nParamId - 27) / 3];
					if (ESE_DATATBLS_GetMissilesTxtRecord(nMissileId))
					{
						return ESE_MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
					}
				}
			}
			break;

		case 28:
		case 31:
		case 34:
			if (nSkillLevel > 0)
			{
				pSkillDescTxtRecord = ESE_DATATBLS_GetSkillDescTxtRecord(pSkillsTxtRecord->wSkillDesc);
				if (pSkillDescTxtRecord)
				{
					nMissileId = pSkillDescTxtRecord->wDescMissile[(nParamId - 28) / 3];
					if (ESE_DATATBLS_GetMissilesTxtRecord(nMissileId))
					{
						return ESE_MISSILE_GetElementalLength(0, pUnit, nMissileId, nSkillLevel);
					}
				}
			}
			break;

		case 35:
		case 36:
		case 37:
			if (nSkillLevel > 0)
			{
				pSkillDescTxtRecord = ESE_DATATBLS_GetSkillDescTxtRecord(pSkillsTxtRecord->wSkillDesc);
				if (pSkillDescTxtRecord)
				{
					nMissileId = pSkillDescTxtRecord->wDescMissile[nParamId - 35];
					if (ESE_DATATBLS_GetMissilesTxtRecord(nMissileId))
					{
						return sgptDataTables->pMissilesTxt[nMissileId].wRange + nSkillLevel * sgptDataTables->pMissilesTxt[nMissileId].wLevRange;
					}
				}
			}
			break;

		case 38:
			return ESE_SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 0);

		case 39:
			return ESE_SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 0);

		case 40:
			if (pUnit)
			{
				return STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
			}
			break;

		case 41:
			if (pUnit)
			{
				pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);
				if (pSkill)
				{
					return SKILLS_GetSkillLevel(pUnit, pSkill, FALSE);
				}
			}
			break;

		case 42:
			if (nSkillLevel > 0)
			{
				return ESE_SKILLS_GetManaCosts(nSkillId, nSkillLevel);
			}
			break;

		case 43:
		case 45:
		case 47:
			if (nSkillLevel > 0)
			{
				pSkillDescTxtRecord = ESE_DATATBLS_GetSkillDescTxtRecord(pSkillsTxtRecord->wSkillDesc);
				if (pSkillDescTxtRecord)
				{
					nMissileId = pSkillDescTxtRecord->wDescMissile[(nParamId - 43) / 3];//TODO: Probably Copy-Paste-Error, Should be (a2 - 43) / 2
					if (ESE_DATATBLS_GetMissilesTxtRecord(nMissileId))
					{
						return ESE_MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel);
					}
				}
			}
			break;

		case 44:
		case 46:
		case 48:
			if (nSkillLevel > 0)
			{
				pSkillDescTxtRecord = ESE_DATATBLS_GetSkillDescTxtRecord(pSkillsTxtRecord->wSkillDesc);
				if (pSkillDescTxtRecord)
				{
					nMissileId = pSkillDescTxtRecord->wDescMissile[(nParamId - 44) / 3];//TODO: Probably Copy-Paste-Error, Should be (a2 - 44) / 2
					if (ESE_DATATBLS_GetMissilesTxtRecord(nMissileId))
					{
						return ESE_MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel);
					}
				}
			}
			break;

		case 49:
			return ESE_SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;

		case 50:
			return ESE_SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;

		case 51:
			return ESE_SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);

		case 52:
			return ESE_SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);

		case 53:
			return ESE_SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);

		case 54:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);

		case 55:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

		case 56:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);

		case 57:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);

		case 58:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);

		case 59:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);

		case 60:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[0], nSkillId, nSkillLevel);

		case 61:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[1], nSkillId, nSkillLevel);

		case 62:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[2], nSkillId, nSkillLevel);

		case 63:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[3], nSkillId, nSkillLevel);

		case 64:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[4], nSkillId, nSkillLevel);

		case 65:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[5], nSkillId, nSkillLevel);

		case 66:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[0], nSkillId, nSkillLevel);

		case 67:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[1], nSkillId, nSkillLevel);

		case 68:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[2], nSkillId, nSkillLevel);

		case 69:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[3], nSkillId, nSkillLevel);

		case 70:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[4], nSkillId, nSkillLevel);

		case 71:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

		case 72:
			return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwSkPoints, nSkillId, nSkillLevel);

		default:
			return 0;
		}
	}
	
	return 0;
}

//D2Common.0x6FDB2280 (#11001)
int __stdcall ESE_SKILLS_GetManaCosts(int nSkillId, int nSkillLevel)
{
	D2SkillsTxt* pSkillsTxtRecord = ESE_DATATBLS_GetSkillsTxtRecord(nSkillId);

	if (pSkillsTxtRecord)
	{
		return (pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
	}

	return 0;
}

//D2Common.0x6FDB22E0
int __fastcall ESE_SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage)
{
	if (nLevel > 1 && pLevelDamage)
	{
		if (nLevel > 28)
		{
			return 7 * *pLevelDamage + pLevelDamage[4] * (nLevel - 28) + 6 * (pLevelDamage[2] + pLevelDamage[3]) + 8 * pLevelDamage[1];
		}
		else if (nLevel > 22)
		{
			return 7 * *pLevelDamage + pLevelDamage[3] * (nLevel - 22) + 6 * pLevelDamage[2] + 8 * pLevelDamage[1];
		}
		else if (nLevel > 16)
		{
			return 7 * *pLevelDamage + pLevelDamage[2] * (nLevel - 16) + 8 * pLevelDamage[1];
		}
		else if (nLevel > 8)
		{
			return 7 * *pLevelDamage + pLevelDamage[1] * (nLevel - 8);
		}
		else
		{
			return *pLevelDamage * (nLevel - 1);
		}

	}
	
	return 0;
}

//D2Common.0x6FDB2390 (#11002)
int __stdcall ESE_SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	D2UnitStrc* pItem = NULL;
	int nDamage = 0;
	int nBonus = 0;

	pSkillsTxtRecord = ESE_DATATBLS_GetSkillsTxtRecord(nSkillId);

	if (pSkillsTxtRecord)
	{
		if (pSkillsTxtRecord->dwFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_KICK])
		{
			if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
			{
				nDamage = 3 * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
			}
			else
			{
				nDamage = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) + STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) - 20;
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
				int32_t nMinDamage = 0;
				if (pItem && INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
				{
					nMinDamage = STATLIST_GetMinDamageFromUnit(pItem, 1);
				}
				else
				{
					nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
				}
				nDamage = (nMinDamage * pSkillsTxtRecord->nSrcDam) / 128;
			}

			nDamage += pSkillsTxtRecord->dwMinDam + ESE_SKILLS_CalculateDamageBonusByLevel(nSkillLevel, (int*)pSkillsTxtRecord->dwMinLvlDam);

			if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
			{
				nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);

				if (nBonus)
				{
					nDamage += nDamage * nBonus / 100;
				}
			}

			return nDamage << pSkillsTxtRecord->nToHitShift;
		}
	}

	return 1;
}

//D2Common.0x6FDB25D0 (#11003)
int __stdcall ESE_SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	D2UnitStrc* pItem = NULL;
	int nDamage = 0;
	int nBonus = 0;

	pSkillsTxtRecord = ESE_DATATBLS_GetSkillsTxtRecord(nSkillId);

	if (pSkillsTxtRecord)
	{
		if (pSkillsTxtRecord->dwFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_KICK])
		{
			if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
			{
				nDamage = 3 * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
			}
			else
			{
				nDamage = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) + STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) - 20;
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
				int32_t nMaxDamage = 0;
				if (pItem && INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
				{
					nMaxDamage = STATLIST_GetMaxDamageFromUnit(pItem, 24) * pSkillsTxtRecord->nSrcDam;
				}
				else
				{
					nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0) * pSkillsTxtRecord->nSrcDam;
				}

				nDamage = nMaxDamage / 128;
			}

			nDamage += pSkillsTxtRecord->dwMaxDam + ESE_SKILLS_CalculateDamageBonusByLevel(nSkillLevel, (int*)pSkillsTxtRecord->dwMaxLvlDam);

			if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
			{
				nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);

				if (nBonus)
				{
					nDamage += nDamage * nBonus / 100;
				}
			}

			return nDamage << pSkillsTxtRecord->nToHitShift;
		}
	}

	return 2;
}

//D2Common.0x6FDB2810 (#11004)
int __stdcall ESE_SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	int nDamage = 0;
	int nBonus = 0;

	pSkillsTxtRecord = ESE_DATATBLS_GetSkillsTxtRecord(nSkillId);

	if (pSkillsTxtRecord && nSkillLevel > 0)
	{
		nDamage = (pSkillsTxtRecord->dwEMin + ESE_SKILLS_CalculateDamageBonusByLevel(nSkillLevel, (int*)pSkillsTxtRecord->dwEMinLev)) << pSkillsTxtRecord->nToHitShift;

		if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1 && (nDamage > 256 || pSkillsTxtRecord->dwEMinLev[0]))
		{
			nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

			if (nBonus)
			{
				nDamage += nDamage * nBonus / 100;
			}
		}

		if (a4 && pUnit)
		{
			nDamage += ESE_SKILLS_CalculateMasteryBonus(pUnit, pSkillsTxtRecord->nEType, nDamage);
		}

		return nDamage;
	}

	return 0;
}

//D2Common.0x6FDB29D0
int __fastcall ESE_SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage)
{
	int nPercentage = 0;

	switch (nElemType)
	{
	case ELEMTYPE_FIRE:
		nPercentage = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_FIRE_MASTERY, 0);
		if (!nPercentage)
		{
			return 0;
		}

		return nSrcDamage * nPercentage / 100;
	case ELEMTYPE_LTNG:
		nPercentage = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_LTNG_MASTERY, 0);
		if (!nPercentage)
		{
			return 0;
		}

		return nSrcDamage * nPercentage / 100;
	case ELEMTYPE_COLD:
	case ELEMTYPE_FREEZE:
		nPercentage = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_COLD_MASTERY, 0);
		if (!nPercentage)
		{
			return 0;
		}

		return nSrcDamage * nPercentage / 100;
	case ELEMTYPE_POIS:
		nPercentage = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_POIS_MASTERY, 0);
		if (!nPercentage)
		{
			return 0;
		}
		
		return nSrcDamage * nPercentage / 100;
	default:
		return 0;
	}
}

//D2Common.0x6FDB2B00 (#11005)
int __stdcall ESE_SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	int nDamage = 0;
	int nBonus = 0;

	pSkillsTxtRecord = ESE_DATATBLS_GetSkillsTxtRecord(nSkillId);

	if (pSkillsTxtRecord && nSkillLevel > 0)
	{
		nDamage = (pSkillsTxtRecord->dwEMax + ESE_SKILLS_CalculateDamageBonusByLevel(nSkillLevel, (int*)pSkillsTxtRecord->dwEMaxLev)) << pSkillsTxtRecord->nToHitShift;

		if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1)
		{
			nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

			if (nBonus)
			{
				nDamage += nDamage * nBonus / 100;
			}
		}

		if (a4 && pUnit)
		{
			nDamage += ESE_SKILLS_CalculateMasteryBonus(pUnit, pSkillsTxtRecord->nEType, nDamage);
		}

		return nDamage;
	}

	return 0;
}

//D2Common.0x6FDB2CA0 (#11006)
int __stdcall ESE_SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL bUnused)
{
	D2_MAYBE_UNUSED(bUnused);
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	int nLength = 0;
	int nBonus = 0;

	pSkillsTxtRecord = ESE_DATATBLS_GetSkillsTxtRecord(nSkillId);

	if (!pSkillsTxtRecord || nSkillLevel <= 0)
	{
		return 0;
	}

	if (nSkillLevel <= 16)
	{
		if (nSkillLevel <= 8)
		{
			nLength = pSkillsTxtRecord->dwELevLen[0] * (nSkillLevel - 1);
		}
		else
		{
			nLength = 7 * pSkillsTxtRecord->dwELevLen[0] + (nSkillLevel - 8) * pSkillsTxtRecord->dwELevLen[1];
		}
	}
	else
	{
		nLength = 7 * pSkillsTxtRecord->dwELevLen[0] + (nSkillLevel - 16) * pSkillsTxtRecord->dwELevLen[2] + 8 * pSkillsTxtRecord->dwELevLen[1];
	}

	nLength += pSkillsTxtRecord->dwELen;

	if (pSkillsTxtRecord->dwELenSymPerCalc != -1)
	{
		nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwELenSymPerCalc, nSkillId, nSkillLevel);

		if (nBonus)
		{
			nLength += nLength * nBonus / 100;
		}
	}

	return nLength;
}

//D2Common.0x6FDB3A90 (#11028)
int __stdcall ESE_D2Common_11028(int a1)
{
	return 20 * (5 * a1 + 5) / (a1 + 8);
}

//D2Common.0x6FDB3AB0 (#11033)
int __stdcall ESE_D2Common_11033(int nLevel, int nParam, int nMax)
{
	int nValue = nParam + (nMax - nParam) * 110 * nLevel / (nLevel + 6) / 100;

	if (nValue > nMax)
	{
		nValue = nMax;
	}

	return nValue;
}

//D2Common.0x6FDB41D0 (#11047)
int __stdcall ESE_SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId)
{
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	D2StatListStrc* pStatList = NULL;

	if (STATES_CheckState(pUnit, STATE_CONCENTRATION))
	{
		pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_CONCENTRATION);
		if (pStatList)
		{
			pSkillsTxtRecord = ESE_DATATBLS_GetSkillsTxtRecord(nSkillId);
			if (pSkillsTxtRecord)
			{
				return D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_DAMAGEPERCENT, 0) * pSkillsTxtRecord->dwParam[0] / 8;
			}
		}
	}

	return 0;
}

//D2Common.0x6FDB4260 (#11283)
void __stdcall ESE_SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent)
{
	D2ItemsTxt* pItemsTxtRecord = NULL;
	D2UnitStrc* pRightHandItem = NULL;
	D2UnitStrc* pLeftHandItem = NULL;
	D2UnitStrc* pBoots = NULL;
	int nDamagePercent = 0;
	int nKickDamage = 0;
	int nMinDamage = 0;
	int nMaxDamage = 0;
	short nStrBonus = 0;
	short nDexBonus = 0;

	if (pUnit)
	{
		nKickDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_KICKDAMAGE, 0);
		*pMinDamage += nKickDamage;
		*pMaxDamage += nKickDamage;

		if (pUnit->pInventory)
		{
			pLeftHandItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

			if (pLeftHandItem)
			{
				pRightHandItem = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, (ITEMS_GetBodyLocation(pLeftHandItem) == BODYLOC_RARM) + 4);
			}
			else
			{
				pRightHandItem = NULL;
			}

			if (D2Common_10731_ITEMS_CheckItemTypeId(pLeftHandItem, ITEMTYPE_WEAPON) && ITEMS_CanBeEquipped(pLeftHandItem) && STATLIST_GetOwner(pLeftHandItem, 0))
			{
				STATLIST_MergeStatLists(pUnit, pLeftHandItem, 0);
			}
			else
			{
				pLeftHandItem = NULL;
			}

			if (pRightHandItem && pRightHandItem != pLeftHandItem && D2Common_10731_ITEMS_CheckItemTypeId(pRightHandItem, ITEMTYPE_WEAPON) && ITEMS_CanBeEquipped(pRightHandItem) && STATLIST_GetOwner(pRightHandItem, 0))
			{
				STATLIST_MergeStatLists(pUnit, pRightHandItem, 0);
			}

			pBoots = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, BODYLOC_FEET);
			if (pBoots && pBoots->dwUnitType == UNIT_ITEM)
			{
				pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pBoots->dwClassId);
				if (pItemsTxtRecord)
				{
					nMinDamage = nKickDamage + pItemsTxtRecord->nMinDam;
					nMaxDamage = nKickDamage + pItemsTxtRecord->nMaxDam;

					nStrBonus = ITEMS_GetStrengthBonus(pBoots);
					if (nStrBonus)
					{
						nDamagePercent += nStrBonus * STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) / 100;
					}

					nDexBonus = ITEMS_GetDexBonus(pBoots);
					if (nDexBonus)
					{
						nDamagePercent += nDexBonus * STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) / 100;
					}

					nDamagePercent += STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
					if (nDamagePercent <= -90)
					{
						nDamagePercent = -90;
					}

					if (nMinDamage >= nMaxDamage)
					{
						nMaxDamage = nMinDamage;
					}

					*pDamagePercent += STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0) + nDamagePercent;
					*pMinDamage += nMinDamage;
					*pMaxDamage += nMaxDamage;
				}
			}

			if (pLeftHandItem)
			{
				STATLIST_MergeStatLists(pUnit, pLeftHandItem, 1);
			}
		}
	}
}
