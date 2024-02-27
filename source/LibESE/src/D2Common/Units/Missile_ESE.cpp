#include "D2Common/Units/Missile_ESE.h"
#include "D2Common/D2Skills_ESE.h"

#include <D2DataTbls.h>
#include <Drlg/D2DrlgMaze.h>
#include <D2Inventory.h>
#include <D2Items.h>
#include <D2Monsters.h>
#include <D2Seed.h>
#include <D2StatList.h>
#include <Units/Units.h>
#include <D2BitManip.h>
#include <D2Combat.h>
#include <Calc.h>

D2CalcCallbackInfoStrc ESE_off_6FDE5A50[] =
{
	{ ESE_MISSILE_GetMinimum, 2 },
	{ ESE_MISSILE_GetMaximum, 2 },
	{ ESE_MISSILE_GetRandomNumberInRange, 2 },
	{ ESE_MISSILE_GetSpecialParamValueForSkillMissile, 2 },
};

int ESE_dword_6FDE5A70 = ARRAY_SIZE(ESE_off_6FDE5A50);

// Inlined, not intercepted
D2MissilesTxt* __fastcall ESE_DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
	if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
	{
		return &sgptDataTables->pMissilesTxt[nMissileId];
	}

	return NULL;
}


//TODO: Find names

//D2Common.0x6FDBA5B0 (#11217)
void __stdcall ESE_MISSILE_CalculateDamageData(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel)
{
	D2MissilesTxt* pMissilesTxtRecord = NULL;
	D2SkillsTxt* pSkillsTxtRecord = NULL;
	D2UnitStrc* pItem = NULL;
	int nMissileSrcDamage = 0;
	int nMinDamagePercent = 0;
	int nMaxDamagePercent = 0;
	int nSkillSrcDamage = 0;
	int nMinPhysDamage = 0;
	int nMaxPhysDamage = 0;
	int nMinElemDamage = 0;
	int nMaxElemDamage = 0;
	int nDamagePercent = 0;
	int nBaseMinDamage = 0;
	int nBaseMaxDamage = 0;
	int nMinDamage = 0;
	int nMaxDamage = 0;
	int nElemType = 0;
	int nSkillId = 0;
	int nLength = 0;
	int nBonus = 0;
	short nStrBonus = 0;
	short nDexBonus = 0;

	memset(pMissileDamageData, 0x00, sizeof(D2MissileDamageDataStrc));

	if (!pOwner || !pMissile || pMissile->dwUnitType != UNIT_MISSILE)
	{
		return;
	}

	pMissilesTxtRecord = ESE_DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId);
	if (!pMissilesTxtRecord)
	{
		return;
	}

	if (pMissilesTxtRecord->nSkill <= 0 && !(pMissilesTxtRecord->dwMissileFlags & gdwBitMasks[MISSILESFLAGINDEX_MISSILESKILL]))
	{
		nSkillSrcDamage = pMissilesTxtRecord->nSrcDamage;

		nMissileSrcDamage = pMissilesTxtRecord->nSrcMissDmg;

		nMinPhysDamage = ESE_MISSILE_GetMinDamage(pMissile, pOwner, pMissile->dwClassId, nLevel);
		nMaxPhysDamage = ESE_MISSILE_GetMaxDamage(pMissile, pOwner, pMissile->dwClassId, nLevel);

		nMinElemDamage = ESE_MISSILE_GetMinElemDamage(pMissile, pOwner, pMissile->dwClassId, nLevel);
		nMaxElemDamage = ESE_MISSILE_GetMaxElemDamage(pMissile, pOwner, pMissile->dwClassId, nLevel);

		nLength = ESE_MISSILE_GetElementalLength(0, pMissile, pMissile->dwClassId, nLevel);
		nElemType = pMissilesTxtRecord->nElemType;

		if (pMissilesTxtRecord->dwMissileFlags & gdwBitMasks[MISSILESFLAGINDEX_APPLYMASTERY])
		{
			nMinElemDamage += ESE_MISSILE_CalculateMasteryBonus(pOwner, nElemType, nMinElemDamage);
			nMaxElemDamage += ESE_MISSILE_CalculateMasteryBonus(pOwner, nElemType, nMaxElemDamage);
		}
	}
	else
	{
		nSkillId = pMissilesTxtRecord->nSkill;

		if (pMissilesTxtRecord->dwMissileFlags & gdwBitMasks[MISSILESFLAGINDEX_MISSILESKILL])
		{
			if (pMissile->pMissileData && pMissile->pMissileData->nSkill > 0)
			{
				nSkillId = pMissile->pMissileData->nSkill;
			}
		}

		pSkillsTxtRecord = ESE_DATATBLS_GetSkillsTxtRecord(nSkillId);
		if (!pSkillsTxtRecord)
		{
			return;
		}

		nMissileSrcDamage = 0;
		if (pMissilesTxtRecord->nSrcDamage == uint8_t(-1))
		{
			nSkillSrcDamage = 0;
		}
		else
		{
			nSkillSrcDamage = pSkillsTxtRecord->nSrcDam;
		}

		nMinPhysDamage = ESE_SKILLS_GetMinPhysDamage(pOwner, nSkillId, nLevel, 0);
		nMaxPhysDamage = ESE_SKILLS_GetMaxPhysDamage(pOwner, nSkillId, nLevel, 0);

		nMinElemDamage = ESE_SKILLS_GetMinElemDamage(pOwner, nSkillId, nLevel, 1);
		nMaxElemDamage = ESE_SKILLS_GetMaxElemDamage(pOwner, nSkillId, nLevel, 1);

		nLength = ESE_SKILLS_GetElementalLength(pOwner, nSkillId, nLevel, 1);
		nElemType = pSkillsTxtRecord->nEType;
	}

	if (pMissilesTxtRecord->nHoly & 1)
	{
		pMissileDamageData->nFlags |= 0x100;
	}

	if (pMissilesTxtRecord->nHoly & 2)
	{
		pMissileDamageData->nFlags |= 0x200;
	}

	if (pMissilesTxtRecord->nHoly & 4)
	{
		pMissileDamageData->nFlags |= 0x400;
	}

	if (nSkillSrcDamage)
	{
		pMissileDamageData->nFlags |= 1;

		switch (pOwner->dwUnitType)
		{
		case UNIT_PLAYER:
			pItem = D2Common_10434(pOwner, 1);
			break;

		case UNIT_MONSTER:
			if (pOwner->pInventory)
			{
				pItem = UNITS_GetEquippedWeaponFromMonster(pOwner);
			}
			break;

		default:
			break;
		}

		if (MISSILE_HasBonusStats(pOwner, pItem))
		{
			pMissileDamageData->nFlags |= 2;
		}

		if (pItem && pItem->dwUnitType == UNIT_ITEM)
		{
			if (pMissilesTxtRecord->dwMissileFlags & gdwBitMasks[MISSILESFLAGINDEX_HALF2HSRC] && ITEMS_CheckWeaponIfTwoHanded(pItem))
			{
				nSkillSrcDamage /= 2;
			}

			nBonus = SKILLS_GetWeaponMasteryBonus(pOwner, pItem, NULL, 1);

			nStrBonus = ITEMS_GetStrengthBonus(pItem);
			if (nStrBonus)
			{
				nBonus += nStrBonus * STATLIST_UnitGetStatValue(pOwner, STAT_STRENGTH, 0) / 100;
			}

			nDexBonus = ITEMS_GetDexBonus(pItem);
			if (nDexBonus)
			{
				nBonus += nDexBonus * STATLIST_UnitGetStatValue(pOwner, STAT_DEXTERITY, 0) / 100;
			}

			if (ITEMS_CheckIfThrowable(pItem))
			{
				nBaseMinDamage = STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_THROW_MINDAMAGE, 0) << 8;
				nBaseMaxDamage = STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_THROW_MAXDAMAGE, 0) << 8;
			}
			else
			{
				if (pOwner->pInventory && INVENTORY_GetWieldType(pOwner, pOwner->pInventory) == 2)
				{
					nBaseMinDamage = STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MINDAMAGE, 0) << 8;
					nBaseMaxDamage = STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MAXDAMAGE, 0) << 8;
				}
				else
				{
					nBaseMinDamage = STATLIST_UnitGetStatValue(pOwner, STAT_MINDAMAGE, 0) << 8;
					nBaseMaxDamage = STATLIST_UnitGetStatValue(pOwner, STAT_MAXDAMAGE, 0) << 8;
				}
			}

			if (D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BLUNT))
			{
				pMissileDamageData->nUndeadDamagePercent += 50;
			}
		}
		else
		{
			if (pOwner->dwUnitType == UNIT_MONSTER && MONSTERS_GetHirelingTypeId(pOwner) != 0)
			{
				nDamagePercent = STATLIST_UnitGetStatValue(pOwner, STAT_DEXTERITY, 0);
			}

			nBaseMinDamage = STATLIST_UnitGetStatValue(pOwner, STAT_MINDAMAGE, 0) << 8;
			nBaseMaxDamage = STATLIST_UnitGetStatValue(pOwner, STAT_MAXDAMAGE, 0) << 8;
		}

		nMinDamage = nSkillSrcDamage * nBaseMinDamage / 128;
		nMaxDamage = nSkillSrcDamage * nBaseMaxDamage / 128;

		nDamagePercent += nBonus + STATLIST_UnitGetStatValue(pOwner, STAT_DAMAGEPERCENT, 0);
		nMinDamagePercent = STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_MINDAMAGE_PERCENT, 0);
		nMaxDamagePercent = STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_MAXDAMAGE_PERCENT, 0);

		pMissileDamageData->nDemonDamagePercent += STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
		pMissileDamageData->nUndeadDamagePercent += STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
		pMissileDamageData->nDamageTargetAC += STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_DAMAGETARGETAC, 0);

		if (STATLIST_UnitGetStatValue(pOwner, STAT_SKILL_BYPASS_UNDEAD, 0))
		{
			pMissileDamageData->nFlags |= 0x100;
		}

		if (STATLIST_UnitGetStatValue(pOwner, STAT_SKILL_BYPASS_DEMONS, 0))
		{
			pMissileDamageData->nFlags |= 0x200;
		}

		if (STATLIST_UnitGetStatValue(pOwner, STAT_SKILL_BYPASS_BEASTS, 0))
		{
			pMissileDamageData->nFlags |= 0x400;
		}
	}
	else if (nMissileSrcDamage && pOrigin)
	{
		if (MISSILE_HasBonusStats(pOrigin, NULL))
		{
			pMissileDamageData->nFlags |= 2;
		}

		nMinDamage = nMissileSrcDamage * STATLIST_UnitGetStatValue(pOrigin, STAT_MINDAMAGE, 0) / 128;
		nMaxDamage = nMissileSrcDamage * STATLIST_UnitGetStatValue(pOrigin, STAT_MAXDAMAGE, 0) / 128;

		nDamagePercent = STATLIST_UnitGetStatValue(pOrigin, STAT_DAMAGEPERCENT, 0);
		nMinDamagePercent = STATLIST_UnitGetStatValue(pOrigin, STAT_ITEM_MINDAMAGE_PERCENT, 0);
		nMaxDamagePercent = STATLIST_UnitGetStatValue(pOrigin, STAT_ITEM_MAXDAMAGE_PERCENT, 0);

		pMissileDamageData->nDemonDamagePercent += STATLIST_UnitGetStatValue(pOrigin, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
		pMissileDamageData->nUndeadDamagePercent += STATLIST_UnitGetStatValue(pOrigin, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
		pMissileDamageData->nDamageTargetAC += STATLIST_UnitGetStatValue(pOrigin, STAT_ITEM_DAMAGETARGETAC, 0);
	}

	if (nMinDamagePercent <= nMaxDamagePercent)
	{
		pMissileDamageData->nDamagePercent = nMaxDamagePercent + STATLIST_UnitGetStatValue(pMissile, STAT_DAMAGEPERCENT, 0) + nDamagePercent;
	}
	else
	{
		pMissileDamageData->nDamagePercent = nMinDamagePercent + STATLIST_UnitGetStatValue(pMissile, STAT_DAMAGEPERCENT, 0) + nDamagePercent;
	}

	if (pMissileDamageData->nDamagePercent <= -90)
	{
		pMissileDamageData->nDamagePercent = -90;
	}

	pMissileDamageData->nMinDamage = nMinPhysDamage + nMinDamage;
	pMissileDamageData->nMaxDamage = nMaxPhysDamage + nMaxDamage;

	switch (nElemType)
	{
	case ELEMTYPE_FIRE:
		pMissileDamageData->nFireMinDamage = nMinElemDamage;
		pMissileDamageData->nFireMaxDamage = nMaxElemDamage;
		pMissileDamageData->nFireLength = nLength;
		break;

	case ELEMTYPE_LTNG:
		pMissileDamageData->nLightMinDamage = nMinElemDamage;
		pMissileDamageData->nLightMaxDamage = nMaxElemDamage;
		break;

	case ELEMTYPE_MAGIC:
		pMissileDamageData->nMagicMinDamage = nMinElemDamage;
		pMissileDamageData->nMagicMaxDamage = nMaxElemDamage;
		break;

	case ELEMTYPE_COLD:
	case ELEMTYPE_FREEZE:
		pMissileDamageData->nColdMinDamage = nMinElemDamage;
		pMissileDamageData->nColdMaxDamage = nMaxElemDamage;
		pMissileDamageData->nColdLength = nLength;
		break;

	case ELEMTYPE_POIS:
		pMissileDamageData->nPoisonMinDamage = nMinElemDamage;
		pMissileDamageData->nPoisonMaxDamage = nMaxElemDamage;
		pMissileDamageData->nPoisonLength = nLength;
		break;

	case ELEMTYPE_LIFE:
		pMissileDamageData->nLifeDrainMinDamage = nMinElemDamage;
		pMissileDamageData->nLifeDrainMaxDamage = nMaxElemDamage;
		break;

	case ELEMTYPE_MANA:
		pMissileDamageData->nManaDrainMinDamage = nMinElemDamage;
		pMissileDamageData->nManaDrainMaxDamage = nMaxElemDamage;
		break;

	case ELEMTYPE_STAMINA:
		pMissileDamageData->nStaminaDrainMinDamage = nMinElemDamage;
		pMissileDamageData->nStaminaDrainMaxDamage = nMaxElemDamage;
		break;

	case ELEMTYPE_STUN:
		pMissileDamageData->nStunLength = nLength;
		break;

	case ELEMTYPE_BURN:
		pMissileDamageData->nBurningMin = nMinElemDamage;
		pMissileDamageData->nBurningMax = nMaxElemDamage;
		pMissileDamageData->nBurnLength = nLength;
		break;

	default:
		break;
	}

	if (nSkillSrcDamage)
	{
		UNITS_MergeDualWieldWeaponStatLists(pOwner, 1);
		ESE_MISSILE_AddStatsToDamage(pMissileDamageData, pOwner, 8);
		ESE_MISSILE_CalculateFinalDamage(pMissileDamageData, nSkillSrcDamage);
		//D2COMMON_11077_Return((int)pOwner, 1);
	}
	else if (nMissileSrcDamage && pOrigin)
	{
		ESE_MISSILE_AddStatsToDamage(pMissileDamageData, pOrigin, 0);
		ESE_MISSILE_CalculateFinalDamage(pMissileDamageData, nMissileSrcDamage);
	}
}



//D2Common.0x6FDBAED0
void __fastcall ESE_MISSILE_AddStatsToDamage(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pMissile, uint8_t nShift)
{
	int nPoisonLength = 0;

	pMissileDamageData->nFireMinDamage += STATLIST_UnitGetStatValue(pMissile, STAT_FIREMINDAM, 0) << nShift;
	pMissileDamageData->nFireMaxDamage += STATLIST_UnitGetStatValue(pMissile, STAT_FIREMAXDAM, 0) << nShift;
	pMissileDamageData->nLightMinDamage += STATLIST_UnitGetStatValue(pMissile, STAT_LIGHTMINDAM, 0) << nShift;
	pMissileDamageData->nLightMaxDamage += STATLIST_UnitGetStatValue(pMissile, STAT_LIGHTMAXDAM, 0) << nShift;
	pMissileDamageData->nMagicMinDamage += STATLIST_UnitGetStatValue(pMissile, STAT_MAGICMINDAM, 0) << nShift;
	pMissileDamageData->nMagicMaxDamage += STATLIST_UnitGetStatValue(pMissile, STAT_MAGICMAXDAM, 0) << nShift;
	pMissileDamageData->nColdMinDamage += STATLIST_UnitGetStatValue(pMissile, STAT_COLDMINDAM, 0) << nShift;
	pMissileDamageData->nColdMaxDamage += STATLIST_UnitGetStatValue(pMissile, STAT_COLDMAXDAM, 0) << nShift;
	pMissileDamageData->nColdLength += STATLIST_UnitGetStatValue(pMissile, STAT_COLDLENGTH, 0);
	pMissileDamageData->nPoisonMinDamage += STATLIST_UnitGetStatValue(pMissile, STAT_POISONMINDAM, 0);
	pMissileDamageData->nPoisonMaxDamage += STATLIST_UnitGetStatValue(pMissile, STAT_POISONMAXDAM, 0);

	nPoisonLength = STATLIST_UnitGetStatValue(pMissile, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);

	if (nPoisonLength <= 0)
	{
		pMissileDamageData->nPoisonLength += STATLIST_UnitGetStatValue(pMissile, STAT_POISONLENGTH, 0);
		pMissileDamageData->nPoisonCount += STATLIST_UnitGetStatValue(pMissile, STAT_POISON_COUNT, 0);
	}
	else
	{
		pMissileDamageData->nPoisonLength += nPoisonLength;
	}

	pMissileDamageData->nLifeDrainMinDamage += STATLIST_UnitGetStatValue(pMissile, STAT_LIFEDRAINMINDAM, 0);
	pMissileDamageData->nManaDrainMinDamage += STATLIST_UnitGetStatValue(pMissile, STAT_MANADRAINMINDAM, 0);
	pMissileDamageData->nBurningMin += STATLIST_UnitGetStatValue(pMissile, STAT_BURNINGMIN, 0);
	pMissileDamageData->nBurningMax += STATLIST_UnitGetStatValue(pMissile, STAT_BURNINGMAX, 0);
	pMissileDamageData->nBurnLength += STATLIST_UnitGetStatValue(pMissile, STAT_FIRELENGTH, 0);
}

//D2Common.0x6FDBB060
void __fastcall ESE_MISSILE_CalculateFinalDamage(D2MissileDamageDataStrc* pMissileDamageData, int nSrcDamage)
{
	if (nSrcDamage != 128)
	{
		pMissileDamageData->nFireMinDamage = nSrcDamage * pMissileDamageData->nFireMinDamage / 128;
		pMissileDamageData->nFireMaxDamage = nSrcDamage * pMissileDamageData->nFireMaxDamage / 128;
		pMissileDamageData->nLightMinDamage = nSrcDamage * pMissileDamageData->nLightMinDamage / 128;
		pMissileDamageData->nLightMaxDamage = nSrcDamage * pMissileDamageData->nLightMaxDamage / 128;
		pMissileDamageData->nMagicMinDamage = nSrcDamage * pMissileDamageData->nMagicMinDamage / 128;
		pMissileDamageData->nMagicMaxDamage = nSrcDamage * pMissileDamageData->nMagicMaxDamage / 128;
		pMissileDamageData->nColdMinDamage = nSrcDamage * pMissileDamageData->nColdMinDamage / 128;
		pMissileDamageData->nColdMaxDamage = nSrcDamage * pMissileDamageData->nColdMaxDamage / 128;
		pMissileDamageData->nColdLength = nSrcDamage * pMissileDamageData->nColdLength / 128;
		pMissileDamageData->nPoisonMinDamage = nSrcDamage * pMissileDamageData->nPoisonMinDamage / 128;
		pMissileDamageData->nPoisonMaxDamage = nSrcDamage * pMissileDamageData->nPoisonMaxDamage / 128;
		pMissileDamageData->nPoisonCount = nSrcDamage * pMissileDamageData->nPoisonCount / 128;
		pMissileDamageData->nLifeDrainMinDamage = nSrcDamage * pMissileDamageData->nLifeDrainMinDamage / 128;
		pMissileDamageData->nManaDrainMinDamage = nSrcDamage * pMissileDamageData->nManaDrainMinDamage / 128;
		pMissileDamageData->nBurningMin = nSrcDamage * pMissileDamageData->nBurningMin / 128;
		pMissileDamageData->nBurningMax = nSrcDamage * pMissileDamageData->nBurningMax / 128;
		pMissileDamageData->nBurnLength = nSrcDamage * pMissileDamageData->nBurnLength / 128;
	}
}

//D2Common.0x6FDBB1B0
int __fastcall ESE_MISSILE_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage)
{
	int statId = 0;

	switch (nElemType)
	{
	case ELEMTYPE_FIRE:
		statId = STAT_PASSIVE_FIRE_MASTERY;
		break;
	case ELEMTYPE_LTNG:
		statId = STAT_PASSIVE_LTNG_MASTERY;
		break;
	case ELEMTYPE_COLD:
	case ELEMTYPE_FREEZE:
		statId = STAT_PASSIVE_COLD_MASTERY;
		break;
	case ELEMTYPE_POIS:
		statId = STAT_PASSIVE_POIS_MASTERY;
		break;
	default:
		return 0;
	}

	auto nPercentage = STATLIST_UnitGetStatValue(pUnit, statId, 0);

	// NOTE: This is an exact copy of D2Game.0x6FC6AF70 (MONSTERUNIQUE_CalculatePercentage)
	if (!nPercentage)
	{
		return 0;
	}

	if (nSrcDamage <= 0x100000)
	{
		if (nPercentage <= 0x10000)
		{
			return nSrcDamage * nPercentage / 100;
		}

		if ((nPercentage >> 4) >= 100)
		{
			return nSrcDamage * (nPercentage / 100);
		}
	}
	else
	{
		if ((nSrcDamage >> 4) >= 100)
		{
			return nPercentage * (nSrcDamage / 100);
		}
	}

	return nSrcDamage * (__int64)nPercentage / 100;
}

//D2Common.0x6FDBB2E0 (#11218)
void __stdcall ESE_MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel)
{
	D2StatStrc pStat[128] = {};
	int nStats = 0;

	if (pMissile && pMissile->dwUnitType == UNIT_MISSILE)
	{
		if (pMissile->pMissileData)
		{
			if (pMissileDamageData->nFlags & 1)
			{
				pMissile->pMissileData->fFlags |= 1;
			}
			if (pMissileDamageData->nFlags & 4)
			{
				pMissile->pMissileData->fFlags |= 2;
			}
		}

		STATLIST_SetUnitStat(pMissile, STAT_LEVEL, nLevel, 0);
		STATLIST_SetUnitStat(pMissile, STAT_MINDAMAGE, pMissileDamageData->nMinDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_MAXDAMAGE, pMissileDamageData->nMaxDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_FIREMINDAM, pMissileDamageData->nFireMinDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_FIREMAXDAM, pMissileDamageData->nFireMaxDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_FIRELENGTH, pMissileDamageData->nFireLength, 0);
		STATLIST_SetUnitStat(pMissile, STAT_LIGHTMINDAM, pMissileDamageData->nLightMinDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_LIGHTMAXDAM, pMissileDamageData->nLightMaxDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_MAGICMINDAM, pMissileDamageData->nMagicMinDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_MAGICMAXDAM, pMissileDamageData->nMagicMaxDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_COLDMINDAM, pMissileDamageData->nColdMinDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_COLDMAXDAM, pMissileDamageData->nColdMaxDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_COLDLENGTH, pMissileDamageData->nColdLength, 0);
		STATLIST_SetUnitStat(pMissile, STAT_POISONMINDAM, pMissileDamageData->nPoisonMinDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_POISONMAXDAM, pMissileDamageData->nPoisonMaxDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_POISONLENGTH, pMissileDamageData->nPoisonLength, 0);
		STATLIST_SetUnitStat(pMissile, STAT_POISON_COUNT, pMissileDamageData->nPoisonCount, 0);
		STATLIST_SetUnitStat(pMissile, STAT_LIFEDRAINMINDAM, pMissileDamageData->nLifeDrainMinDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_LIFEDRAINMAXDAM, pMissileDamageData->nLifeDrainMaxDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_MANADRAINMINDAM, pMissileDamageData->nManaDrainMinDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_MANADRAINMAXDAM, pMissileDamageData->nManaDrainMaxDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_STAMDRAINMINDAM, pMissileDamageData->nStaminaDrainMinDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_STAMDRAINMAXDAM, pMissileDamageData->nStaminaDrainMaxDamage, 0);
		STATLIST_SetUnitStat(pMissile, STAT_STUNLENGTH, pMissileDamageData->nStunLength, 0);
		STATLIST_SetUnitStat(pMissile, STAT_BURNINGMIN, pMissileDamageData->nBurningMin, 0);
		STATLIST_SetUnitStat(pMissile, STAT_BURNINGMAX, pMissileDamageData->nBurningMax, 0);
		STATLIST_SetUnitStat(pMissile, STAT_FIRELENGTH, pMissileDamageData->nBurnLength, 0);
		STATLIST_SetUnitStat(pMissile, STAT_ITEM_DEMONDAMAGE_PERCENT, pMissileDamageData->nDemonDamagePercent, 0);
		STATLIST_SetUnitStat(pMissile, STAT_ITEM_UNDEADDAMAGE_PERCENT, pMissileDamageData->nUndeadDamagePercent, 0);
		STATLIST_SetUnitStat(pMissile, STAT_ITEM_DAMAGETARGETAC, pMissileDamageData->nDamageTargetAC, 0);
		STATLIST_SetUnitStat(pMissile, STAT_DAMAGEPERCENT, pMissileDamageData->nDamagePercent, 0);

		if (pMissileDamageData->nFlags & 0x100)
		{
			STATLIST_SetUnitStat(pMissile, STAT_SKILL_BYPASS_UNDEAD, 1, 0);
		}

		if (pMissileDamageData->nFlags & 0x200)
		{
			STATLIST_SetUnitStat(pMissile, STAT_SKILL_BYPASS_DEMONS, 1, 0);
		}

		if (pMissileDamageData->nFlags & 0x400)
		{
			STATLIST_SetUnitStat(pMissile, STAT_SKILL_BYPASS_BEASTS, 1, 0);
		}

		if (pMissileDamageData->nFlags & 2)
		{
			STATLIST_SetUnitStat(pMissile, STAT_ITEM_DEADLYSTRIKE, 1, 0);
		}

		if (pOwner)
		{
			nStats = STATLIST_CopyStats(pOwner, STAT_DAMAGE_VS_MONTYPE, pStat, ARRAY_SIZE(pStat));
			for (int i = 0; i < nStats; ++i)
			{
				STATLIST_SetUnitStat(pMissile, STAT_DAMAGE_VS_MONTYPE, pStat[i].nValue, pStat[i].nLayer);
			}
		}
	}
}

//D2Common.0x6FDBB5A0 (#11285)
int __stdcall ESE_MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
	D2MissilesTxt* pMissilesTxtRecord = NULL;
	long long int nBonus = 0;
	int nMissileIdLevel = 0;
	int nPercentage = 0;
	int nMissile = 0;
	int nDamage = 0;

	if (!pMissile || pMissile->dwUnitType == UNIT_MISSILE)
	{
		nMissile = nMissileId;
		if (nMissileId < 0 && pMissile)
		{
			nMissile = pMissile->dwClassId;
		}

		nMissileIdLevel = nLevel;
		if (nLevel <= 0 && pMissile)
		{
			nMissileIdLevel = 0;
			if (pMissile->dwUnitType == UNIT_MISSILE)
			{
				if (pMissile->pMissileData)
				{
					nMissileIdLevel = pMissile->pMissileData->nLevel;
				}
			}
		}

		pMissilesTxtRecord = ESE_DATATBLS_GetMissilesTxtRecord(nMissile);
		if (pMissilesTxtRecord)
		{
			nDamage = pMissilesTxtRecord->dwMinDamage + ESE_SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, (int*)pMissilesTxtRecord->dwMinLevDam);

			if (pMissilesTxtRecord->dwDmgSymPerCalc != -1)
			{
				nPercentage = ESE_MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwDmgSymPerCalc, nMissile, nMissileIdLevel);

				if (nPercentage)
				{
					nBonus = nDamage * nPercentage / 100;

					nDamage += (int)nBonus;
				}
			}

			return nDamage << pMissilesTxtRecord->nHitShift;
		}
	}

	return 0;
}

//D2Common.0x6FDBB710 (#11286)
int __stdcall ESE_MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
	D2MissilesTxt* pMissilesTxtRecord = NULL;
	long long int nBonus = 0;
	int nMissileIdLevel = 0;
	int nPercentage = 0;
	int nMissile = 0;
	int nDamage = 0;

	if (!pMissile || pMissile->dwUnitType == UNIT_MISSILE)
	{
		nMissile = nMissileId;
		if (nMissileId < 0 && pMissile)
		{
			nMissile = pMissile->dwClassId;
		}

		nMissileIdLevel = nLevel;
		if (nLevel <= 0 && pMissile)
		{
			nMissileIdLevel = 0;
			if (pMissile->dwUnitType == UNIT_MISSILE)
			{
				if (pMissile->pMissileData)
				{
					nMissileIdLevel = pMissile->pMissileData->nLevel;
				}
			}
		}

		pMissilesTxtRecord = ESE_DATATBLS_GetMissilesTxtRecord(nMissile);
		if (pMissilesTxtRecord)
		{
			nDamage = pMissilesTxtRecord->dwMaxDamage + ESE_SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, (int*)pMissilesTxtRecord->dwMaxLevDam);

			if (pMissilesTxtRecord->dwDmgSymPerCalc != -1)
			{
				nPercentage = ESE_MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwDmgSymPerCalc, nMissile, nMissileIdLevel);

				if (nPercentage)
				{
					nBonus = nDamage * nPercentage / 100;

					nDamage += (int)nBonus;
				}
			}

			return nDamage << pMissilesTxtRecord->nHitShift;
		}
	}

	return 0;
}

//D2Common.0x6FDBB8C0 (#11287)
int __stdcall ESE_MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
	D2MissilesTxt* pMissilesTxtRecord = NULL;
	long long int nBonus = 0;
	int nMissileIdLevel = 0;
	int nPercentage = 0;
	int nMissile = 0;
	int nDamage = 0;

	if (!pMissile || pMissile->dwUnitType == UNIT_MISSILE)
	{
		nMissile = nMissileId;
		if (nMissileId < 0 && pMissile)
		{
			nMissile = pMissile->dwClassId;
		}

		nMissileIdLevel = nLevel;
		if (nLevel <= 0 && pMissile)
		{
			nMissileIdLevel = 0;
			if (pMissile->dwUnitType == UNIT_MISSILE)
			{
				if (pMissile->pMissileData)
				{
					nMissileIdLevel = pMissile->pMissileData->nLevel;
				}
			}
		}

		pMissilesTxtRecord = ESE_DATATBLS_GetMissilesTxtRecord(nMissile);
		if (pMissilesTxtRecord)
		{
			nDamage = pMissilesTxtRecord->dwElemMin + ESE_SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, (int*)pMissilesTxtRecord->dwMinElemLev);

			if (pMissilesTxtRecord->dwElemDmgSymPerCalc != -1)
			{
				nPercentage = ESE_MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwElemDmgSymPerCalc, nMissile, nMissileIdLevel);

				if (nPercentage)
				{
					nBonus = nDamage * nPercentage / 100;

					nDamage += (int)nBonus;
				}
			}

			return nDamage << pMissilesTxtRecord->nHitShift;
		}
	}

	return 0;
}

//D2Common.0x6FDBBA30 (#11288)
int __stdcall ESE_MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
	D2MissilesTxt* pMissilesTxtRecord = NULL;
	long long int nBonus = 0;
	int nMissileIdLevel = 0;
	int nPercentage = 0;
	int nMissile = 0;
	int nDamage = 0;

	if (!pMissile || pMissile->dwUnitType == UNIT_MISSILE)
	{
		nMissile = nMissileId;
		if (nMissileId < 0 && pMissile)
		{
			nMissile = pMissile->dwClassId;
		}

		nMissileIdLevel = nLevel;
		if (nLevel <= 0 && pMissile)
		{
			nMissileIdLevel = 0;
			if (pMissile->dwUnitType == UNIT_MISSILE)
			{
				if (pMissile->pMissileData)
				{
					nMissileIdLevel = pMissile->pMissileData->nLevel;
				}
			}
		}

		pMissilesTxtRecord = ESE_DATATBLS_GetMissilesTxtRecord(nMissile);
		if (pMissilesTxtRecord)
		{
			nDamage = pMissilesTxtRecord->dwElemMax + ESE_SKILLS_CalculateDamageBonusByLevel(nMissileIdLevel, (int*)pMissilesTxtRecord->dwMaxElemLev);

			if (pMissilesTxtRecord->dwElemDmgSymPerCalc != -1)
			{
				nPercentage = ESE_MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwElemDmgSymPerCalc, nMissile, nMissileIdLevel);

				if (nPercentage)
				{
					nBonus = nDamage * nPercentage / 100;

					nDamage += (int)nBonus;
				}
			}

			return nDamage << pMissilesTxtRecord->nHitShift;
		}
	}

	return 0;
}

//D2Common.0x6FDBBBA0 (#11221)
int __stdcall ESE_MISSILE_GetElementalLength(int nUnused, D2UnitStrc* pMissile, int nMissileId, int nLevel)
{
	D2_MAYBE_UNUSED(nUnused);
	D2MissilesTxt* pMissilesTxtRecord = NULL;
	int nLength = 0;

	pMissilesTxtRecord = ESE_DATATBLS_GetMissilesTxtRecord(nMissileId);
	if (!pMissilesTxtRecord)
	{
		return 0;
	}

	if (nLevel <= 0)
	{
		return pMissilesTxtRecord->dwElemLen;
	}

	if (nLevel > 16)
	{
		nLength = (nLevel - 16) * pMissilesTxtRecord->dwElemLevLen[2] + 8 * pMissilesTxtRecord->dwElemLevLen[1];
		return 7 * pMissilesTxtRecord->dwElemLevLen[0] + nLength + pMissilesTxtRecord->dwElemLen;
	}

	if (nLevel > 8)
	{
		nLength = (nLevel - 8) * pMissilesTxtRecord->dwElemLevLen[1];
		return 7 * pMissilesTxtRecord->dwElemLevLen[0] + nLength + pMissilesTxtRecord->dwElemLen;
	}

	return pMissilesTxtRecord->dwElemLevLen[0] * (nLevel - 1) + pMissilesTxtRecord->dwElemLen;
}

//D2Common.0x6FDBBC50 (#11290)
int __stdcall ESE_MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, uint8_t nParamId, int nMissileId, int nLevel)
{
	D2MissilesTxt* pMissilesTxtRecord = NULL;

	if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
	{
		return 0;
	}

	pMissilesTxtRecord = ESE_DATATBLS_GetMissilesTxtRecord(nMissileId);
	if (pMissilesTxtRecord)
	{
		switch (nParamId)
		{
		case 0:
			return pMissilesTxtRecord->dwParam[0];

		case 1:
			return pMissilesTxtRecord->dwParam[1];

		case 2:
			return pMissilesTxtRecord->dwParam[2];

		case 3:
			return pMissilesTxtRecord->dwParam[3];

		case 4:
			return pMissilesTxtRecord->dwParam[4];

		case 5:
			return pMissilesTxtRecord->dwCltParam[0];

		case 6:
			return pMissilesTxtRecord->dwCltParam[1];

		case 7:
			return pMissilesTxtRecord->dwCltParam[2];

		case 8:
			return pMissilesTxtRecord->dwCltParam[3];

		case 9:
			return pMissilesTxtRecord->dwCltParam[4];

		case 10:
			return pMissilesTxtRecord->dwHitPar[0];

		case 11:
			return pMissilesTxtRecord->dwHitPar[1];

		case 12:
			return pMissilesTxtRecord->dwHitPar[2];

		case 13:
			return pMissilesTxtRecord->dwCltHitPar[0];

		case 14:
			return pMissilesTxtRecord->dwCltHitPar[1];

		case 15:
			return pMissilesTxtRecord->dwCltHitPar[2];

		case 16:
			return pMissilesTxtRecord->dwDmgParam[0];

		case 17:
			return pMissilesTxtRecord->dwDmgParam[1];

		case 18:
			return nLevel;

		case 19:
			return ESE_MISSILE_GetMinElemDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;

		case 20:
			return ESE_MISSILE_GetMaxElemDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;

		case 21:
			return ESE_MISSILE_GetElementalLength(0, pMissile, nMissileId, nLevel);

		case 22:
			return ESE_MISSILE_GetMinElemDamage(pMissile, pOwner, nMissileId, nLevel);

		case 23:
			return ESE_MISSILE_GetMaxElemDamage(pMissile, pOwner, nMissileId, nLevel);

		case 24:
			return ESE_MISSILE_GetMinDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;

		case 25:
			return ESE_MISSILE_GetMaxDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;

		case 26:
			return ESE_MISSILE_GetMinDamage(pMissile, pOwner, nMissileId, nLevel);

		case 27:
			return ESE_MISSILE_GetMaxDamage(pMissile, pOwner, nMissileId, nLevel);

		case 28:
			return pMissilesTxtRecord->wRange + nLevel * pMissilesTxtRecord->wLevRange;

		case 29:
			return pMissilesTxtRecord->dwParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwParam[1];

		case 30:
			return ESE_D2Common_11033(nLevel, pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->dwParam[1]);

		case 31:
			return pMissilesTxtRecord->dwParam[2] + (nLevel - 1) * pMissilesTxtRecord->dwParam[3];

		case 32:
			return ESE_D2Common_11033(nLevel, pMissilesTxtRecord->dwParam[2], pMissilesTxtRecord->dwParam[3]);

		case 33:
			return pMissilesTxtRecord->dwCltParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwCltParam[1];

		case 34:
			return ESE_D2Common_11033(nLevel, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1]);

		case 35:
			return pMissilesTxtRecord->dwCltParam[2] + (nLevel - 1) * pMissilesTxtRecord->dwCltParam[3];

		case 36:
			return ESE_D2Common_11033(nLevel, pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->dwCltParam[3]);

		case 37:
			return pMissilesTxtRecord->dwHitPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwHitPar[1];

		case 38:
			return ESE_D2Common_11033(nLevel, pMissilesTxtRecord->dwHitPar[0], pMissilesTxtRecord->dwHitPar[1]);

		case 39:
			return pMissilesTxtRecord->dwCltHitPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwCltHitPar[1];

		case 40:
			return ESE_D2Common_11033(nLevel, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1]);

		case 41:
			return pMissilesTxtRecord->dwDmgParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwDmgParam[1];

		case 42:
			return ESE_D2Common_11033(nLevel, pMissilesTxtRecord->dwDmgParam[0], pMissilesTxtRecord->dwDmgParam[1]);

		default:
			return 0;
		}
	}

	return 0;
}

//D2Common.0x6FDBC060
int __fastcall ESE_MISSILE_GetCalcParamValue(int32_t nParamId, void* pUserData)
{
	if (D2MissileCalcStrc * pMissileCalc = (D2MissileCalcStrc*)pUserData)
	{
		return ESE_MISSILE_GetSpecialParamValue(pMissileCalc->pMissile, pMissileCalc->pOwner, nParamId, pMissileCalc->nMissileId, pMissileCalc->nMissileLevel);
	}

	return 0;
}

//D2Common.0x6FDBC080
int __fastcall ESE_MISSILE_GetMinimum(int a1, int a2, int a3, void* pUserData)
{
	if (a1 >= a2)
	{
		return a2;
	}

	return a1;
}

//D2Common.0x6FDBC090
int __fastcall ESE_MISSILE_GetMaximum(int a1, int a2, int a3, void* pUserData)
{
	if (a1 <= a2)
	{
		return a2;
	}

	return a1;
}

//D2Common.0x6FDBC0A0
int __fastcall ESE_MISSILE_GetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData){
	D2_MAYBE_UNUSED(nUnused);
	D2UnkMissileCalcStrc* pCalc = (D2UnkMissileCalcStrc*)pUserData;
	int nPossibilities = 0;

	if (pCalc)
	{
		if (nMin < nMax)
		{
			nPossibilities = nMax - nMin + 1;

			return nMin + SEED_RollLimitedRandomNumber(&pCalc->pSeed, nPossibilities);
		}

		return nMin;
	}

	return 0;
}

//D2Common.0x6FDBC120
int __fastcall ESE_MISSILE_GetSpecialParamValueForSkillMissile(int nSkillId, int nParamId, int nUnused, void* pUserData)
{
	D2_MAYBE_UNUSED(nUnused);

	D2SkillStrc* pSkill = NULL;
	int nSkillLevel = 0;

	if (D2MissileCalcStrc* pMissileCalc = (D2MissileCalcStrc*)pUserData)
	{
		if (pMissileCalc->pOwner)
		{
			pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pMissileCalc->pOwner, nSkillId);
			if (pSkill)
			{
				nSkillLevel = SKILLS_GetSkillLevel(pMissileCalc->pOwner, pSkill, 1);
			}
		}

		return ESE_SKILLS_GetSpecialParamValue(pMissileCalc->pOwner, nParamId, nSkillId, nSkillLevel);
	}

	return 0;
}

//D2Common.0x6FDBC170 (#11284)
int __stdcall ESE_MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel)
{
	D2MissileCalcStrc pMissileCalc = {};
	int nMissileLevel = 0;
	int nMissile = 0;

	if (pMissile)
	{
		if (pMissile->dwUnitType != UNIT_MISSILE)
		{
			return 0;
		}

		nMissile = nMissileId;
		if (nMissileId < 0)
		{
			nMissile = pMissile->dwClassId;
		}

		nMissileLevel = nLevel;
		if (nLevel < 0)
		{
			if (pMissile->pMissileData)
			{
				nMissileLevel = pMissile->pMissileData->nLevel;
			}
			else
			{
				nMissileLevel = 0;
			}
		}
	}
	else
	{
		nMissileLevel = nLevel;
		nMissile = nMissileId;
	}

	if (sgptDataTables->pMissCode && nCalc < sgptDataTables->nMissCodeSize)
	{
		pMissileCalc.pMissile = pMissile;
		pMissileCalc.pOwner = pOwner;
		pMissileCalc.nMissileId = nMissile;
		pMissileCalc.nMissileLevel = nMissileLevel;

		return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pMissCode[nCalc], sgptDataTables->nMissCodeSize - nCalc, ESE_MISSILE_GetCalcParamValue, ESE_off_6FDE5A50, ESE_dword_6FDE5A70, &pMissileCalc);
	}

	return 0;
}
