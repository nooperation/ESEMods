#include "ESEGame.h"

#include <D2Dungeon.h>
#include <D2StatList.h>
#include <D2Math.h>
#include <D2Skills.h>
#include <D2States.h>
#include <SKILLS/Skills.h>
#include <SKILLS/SkillAss.h>
#include <UNIT/SUnit.h>
#include <UNIT/SUnitEvent.h>
#include <MONSTER/MonsterMode.h>
#include <ITEMS/Items.h>

decltype(&SUNITDMG_CalculateTotalDamage) SUNITDMG_CalculateTotalDamage_Original = nullptr;
decltype(&SUNITDMG_ExecuteEvents) SUNITDMG_ExecuteEvents_Original = nullptr;
decltype(&MONSTERUNIQUE_CalculatePercentage) MONSTERUNIQUE_CalculatePercentage_Original = nullptr;
decltype(&SUNITDMG_ApplyResistancesAndAbsorb) SUNITDMG_ApplyResistancesAndAbsorb_Original = nullptr;

uint32_t damageCounter = 0;

#include <UNIT/SUnitDmg.h>

void __fastcall SUNITDMG_ExecuteEvents_ESEGame(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int32_t bMissile, D2DamageStrc* pDamage)
{
	SUNITDMG_ExecuteEvents_Original(pGame, pAttacker, pDefender, bMissile, pDamage);
	return;

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

	if (bMissile)
	{
		SUNITDMG_CalculateTotalDamage_ESEGame(pGame, pAttacker, pDefender, pDamage);
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
						int32_t nLeechedMana = MONSTERUNIQUE_CalculatePercentage_ESEGame(pDamage->dwPhysDamage, pDamage->dwManaLeech, 100);
						if (nDrain != 100)
						{
							nLeechedMana = MONSTERUNIQUE_CalculatePercentage_ESEGame(nLeechedMana, nDrain, 100);
						}

						SUNITDMG_AddLeechedMana(pAttacker, nLeechedMana / 64);
					}

					if (pDamage->dwLifeLeech)
					{
						int32_t nLeechedHp = MONSTERUNIQUE_CalculatePercentage_ESEGame(pDamage->dwPhysDamage, pDamage->dwLifeLeech, 100);
						if (nDrain != 100)
						{
							nLeechedHp = MONSTERUNIQUE_CalculatePercentage_ESEGame(nLeechedHp, nDrain, 100);
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
						nTotalLeech = MONSTERUNIQUE_CalculatePercentage_ESEGame(nTotalLeech, nDrain, 100);
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

	if (pDamage->dwAbsLife > 0 && !SUNIT_IsDead(pDefender) && !STATES_CheckState(pDefender, STATE_DEATH_DELAY))
	{
		const int32_t nMaxHp = STATLIST_GetMaxLifeFromUnit(pDefender);
		const int32_t nNewHp = std::min(pDamage->dwAbsLife + (int32_t)STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0), nMaxHp);
		STATLIST_SetUnitStat(pDefender, STAT_HITPOINTS, nNewHp, 0);
	}

	if (pDamage->dwDmgTotal > 0)
	{
		int64_t oldHp = STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0);
		int64_t nNewHp = std::min((int64_t)INT32_MAX, oldHp - pDamage->dwDmgTotal);

		char buff[1024];
		sprintf(buff, "Damage = %u | oldHp = %lld | newHp = %lld \n", pDamage->dwDmgTotal >> 8, oldHp >> 8, nNewHp >> 8);
		OutputDebugStringA(buff);

		if (nNewHp < 256)
		{
			nNewHp = 0;
		}

		int32_t truncatedNewHp = (int32_t)nNewHp;
		STATLIST_SetUnitStat(pDefender, STAT_HITPOINTS, truncatedNewHp, 0);
	}

	if (pDamage->dwManaLeech > 0)
	{
		int32_t nNewMana = STATLIST_UnitGetStatValue(pDefender, STAT_MANA, 0) - pDamage->dwManaLeech;
		if (nNewMana < 256)
		{
			nNewMana = 0;
		}
		STATLIST_SetUnitStat(pDefender, STAT_MANA, nNewMana, 0);
	}

	if (pDamage->dwStamLeech > 0)
	{
		int32_t nNewStamina = STATLIST_UnitGetStatValue(pDefender, STAT_STAMINA, 0) - pDamage->dwStamLeech;
		if (nNewStamina < 256)
		{
			nNewStamina = 0;
		}
		STATLIST_SetUnitStat(pDefender, STAT_STAMINA, nNewStamina, 0);
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

		if ((!MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 8u) || ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 100) >= 90) && !MONSTERS_IsBoss(0, pDefender) && MONSTERMODE_GetMonStatsTxtRecord(pDefender->dwClassId)->nVelocity)
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
		if (pDamage->dwDmgTotal && nDefenderUnitType == UNIT_MONSTER)
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

void __fastcall SUNITDMG_CalculateTotalDamage_ESEGame(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
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
		nDamageReduction = MONSTERUNIQUE_CalculatePercentage_ESEGame(nDamageReduction, pDamage->dwPiercePct, 1024);
	}
	damageInfo.nDamageReduction[1] = nDamageReduction;

	int32_t nMagicDamageReduction = STATLIST_UnitGetStatValue(pDefender, STAT_MAGIC_DAMAGE_REDUCTION, 0) << 8;
	if (nMagicDamageReduction > 0 && pDamage->dwPiercePct > 0)
	{
		nMagicDamageReduction = MONSTERUNIQUE_CalculatePercentage_ESEGame(nMagicDamageReduction, pDamage->dwPiercePct, 1024);
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
			for (int32_t i = 0; i < std::size(sgDamageStatTable); ++i)
			{
				const D2DamageStatTableStrc* pDamageStatTableRecord = &sgDamageStatTable[i];
				if (pDamageStatTableRecord->unk0x20)
				{
					int32_t* pDamageValue = (int32_t*)((char*)damageInfo.pDamage + pDamageStatTableRecord->nOffsetInDamageStrc);
					if (*pDamageValue > 0)
					{
						*pDamageValue = MONSTERUNIQUE_CalculatePercentage_ESEGame(*pDamageValue, nDamagePercent, 100);
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

	for (int32_t i = 0; i < std::size(sgDamageStatTable); ++i)
	{
		const D2DamageStatTableStrc* pDamageStatTableRecord = &sgDamageStatTable[i];
		if (pDamageStatTableRecord->unk0x1C && !damageInfo.bAttackerIsMonster)
		{
			break;
		}

		SUNITDMG_ApplyResistancesAndAbsorb_ESEGame(&damageInfo, pDamageStatTableRecord, bDontAbsorb);
	}

	auto dmgTotal = (int64_t)pDamage->dwPhysDamage + (int64_t)pDamage->dwFireDamage + (int64_t)pDamage->dwLtngDamage + (int64_t)pDamage->dwMagDamage + (int64_t)pDamage->dwColdDamage + (int64_t)pDamage->dwPoisDamage;
	pDamage->dwDmgTotal = std::max(0, (int32_t)std::min((int64_t)INT32_MAX, dmgTotal));

	if (damageInfo.bAttackerIsMonster)
	{
		pDamage->dwDmgTotal += pDamage->dwLifeLeech;
	}
}

int64_t __fastcall MONSTERUNIQUE_CalculatePercentage_ESEGame_Helper(int64_t a1, int64_t a2, int64_t a3)
{
	if (!a3)
	{
		return 0;
	}

	if (a1 <= 1048576)
	{
		if (a2 <= 65536)
		{
			return a2 * a1 / a3;
		}

		if (a3 <= a2 >> 4)
		{
			return a1 * a2 / a3;
		}
	}
	else
	{
		if (a3 <= a1 >> 4)
		{
			return a2 * a1 / a3;
		}
	}

	return a2 * (int64_t)a1 / a3;
}

int32_t __fastcall MONSTERUNIQUE_CalculatePercentage_ESEGame(int32_t a1, int32_t a2, int32_t a3)
{
	const auto result = MONSTERUNIQUE_CalculatePercentage_ESEGame_Helper(a1, a2, a3);
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

int64_t CalculatePercentage(int32_t a1, int32_t a2, int32_t a3)
{
	if (a1 <= 0x100000)
	{
		if (a2 <= 0x10000)
		{
			return (a1 * a2) / a3;
		}
		if ((a2 >> 4) >= a3)
		{
			return a1 * (a2 / a3);
		}
	}
	else if ((a2 >> 4) >= a3)
	{
		return a2 * (a1 / a3);
	}

	return a1 * (__int64)a2 / a3;
}

//D2Game.0x6FCBFB40
void __fastcall SUNITDMG_ApplyResistancesAndAbsorb_ESEGame(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb)
{
	auto pValue = (int*)((char*)pDamageInfo->pDamage + pDamageStatTableRecord->nOffsetInDamageStrc);
	auto nValue = *pValue;
	auto nPreviousValue = *pValue;

	if (*pValue <= 0)
	{
		*pValue = 0;
		return;
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
	}

	if (nValue > 0 && nResValue)
	{
		if (nResValue >= 100)
		{
			nResValue = 100;
		}

		nValue = CalculatePercentage(nValue, 100 - nResValue, 100);
	}

	if (bDontAbsorb)
	{
		*pValue = nValue;
		return;
	}

	if (pDamageStatTableRecord->nAbsorbPctStatId == -1)
	{
		*pValue = nValue;
		return;
	}

	auto nAbsorbPctValue = STATLIST_UnitGetStatValue(pDamageInfo->pDefender, pDamageStatTableRecord->nAbsorbPctStatId, 0);
	if (nAbsorbPctValue > 0)
	{
		if (nAbsorbPctValue > 98)
		{
			nAbsorbPctValue = 98;
		}

		auto damageAbsorbed = CalculatePercentage(nValue, nAbsorbPctValue, 100);

		nValue -= damageAbsorbed;
		pDamageInfo->pDamage->dwAbsLife = HIDWORD(damageAbsorbed);
	}

	auto nAbsorbStatId = STATLIST_UnitGetStatValue(pDamageInfo->pDefender, pDamageStatTableRecord->nAbsorbStatId, 0) << 8;
	if (nAbsorbStatId > 0)
	{
		if (nAbsorbStatId >= nValue)
		{
			nAbsorbStatId = nValue;
		}

		nValue -= nAbsorbStatId;
		pDamageInfo->pDamage->dwAbsLife += nAbsorbStatId;
	}

	*pValue = nValue;
}
