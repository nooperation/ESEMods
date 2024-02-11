#include "ESEDamageCalc.h"

#include <D2States.h>
#include <SKILLS/SkillAss.h>
#include <UNIT/SUnitEvent.h>

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
