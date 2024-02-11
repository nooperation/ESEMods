#include "ESEDamageCalc.h"
#include <D2StatList.h>

void __fastcall SUNITDMG_AllocCombat_ESEDamageCalc(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, uint8_t nSrcDam)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    const auto dodgedAttack = pDamage->wResultFlags & DAMAGERESULTFLAG_DODGE | DAMAGERESULTFLAG_AVOID | DAMAGERESULTFLAG_EVADE | DAMAGERESULTFLAG_WEAPONBLOCK;
    const auto isSuccessfulHit = pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT;

    if (!dodgedAttack && isSuccessfulHit)
    {
        if (!(pDamage->dwHitFlags & DAMAGEHITFLAG_2))
        {
            SUNITDMG_FillDamageValues(pGame, pAttacker, pDefender, pDamage, 0, nSrcDam);
        }

        auto nTotalDamage = SUNITDMG_CalculateTotalDamage_ESEDamageCalc_64(pGame, pAttacker, pDefender, pDamage);

        const int64_t nHitpoints = STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0);

        if ((nTotalDamage >> 8) > (nHitpoints >> 8))
        {
            pDamage->wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
        }
    }

    if (pDefender->dwUnitType != UNIT_MONSTER && pDefender->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2CombatStrc* pCombat = D2_ALLOC_STRC_POOL(pGame->pMemoryPool, D2CombatStrc);
    pCombat->pGame = pGame;
    pCombat->dwAttackerType = pAttacker->dwUnitType;
    pCombat->dwAttackerId = pAttacker->dwUnitId;
    pCombat->dwDefenderType = pDefender->dwUnitType;
    pCombat->dwDefenderId = pDefender->dwUnitId;
    memcpy(&pCombat->tDamage, pDamage, sizeof(pCombat->tDamage));
    pCombat->pNext = pAttacker->pCombat;
    pAttacker->pCombat = pCombat;
}
