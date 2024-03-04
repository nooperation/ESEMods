#include "D2Game/OBJECTS/ObjEval_ESE.h"
#include "D2Game/UNIT/SUnitDmg_ESE.h"

#include <D2Dungeon.h>
#include <D2StatList.h>
#include <D2States.h>
#include <DataTbls/ObjectsTbls.h>
#include <ITEMS/Items.h>

#include <algorithm>

//D2Game.0x6FC745D0
void __fastcall ESE_OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int32_t nDamageType)
{
    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pTargetUnit);

    if (DUNGEON_IsRoomInTown(pTargetRoom) || UNITS_TestCollisionBetweenInteractingUnits(pTargetUnit, pSrcUnit, 0x804u))
    {
        return;
    }

    D2_ASSERT(pTargetUnit);

    const int64_t nHitpoints = STATLIST_UnitGetStatValue(pTargetUnit, STAT_HITPOINTS, 0);
    const int64_t nMinDamage = std::max<int64_t>(nHitpoints >> 5, 1);
    const int64_t nMaxDamage = std::max<int64_t>(nHitpoints >> 3, nMinDamage + 1);

    const int64_t nLevel = STATLIST_UnitGetStatValue(pTargetUnit, STAT_LEVEL, 0);
    const int64_t dexterity = STATLIST_UnitGetStatValue(pTargetUnit, STAT_DEXTERITY, 0);
    const int64_t randParam = ESE_ITEMS_RollLimitedRandomNumber(&pSrcUnit->pSeed, nLevel >> 2);

    const int64_t nParam = 2LL * ((nLevel + randParam) - 5LL * (dexterity >> 1) - nLevel);

    const int64_t armorClass = (int64_t)STATLIST_UnitGetStatValue(pTargetUnit, STAT_ARMORCLASS, 0);
    const int64_t nChanceToHit = std::max<int64_t>(nParam - armorClass + 125, 65);

    if ((ITEMS_RollRandomNumber(&pSrcUnit->pSeed) % 100) >= nChanceToHit)
    {
        return;
    }

    D2_ASSERT(nMinDamage <= nMaxDamage);

    const int64_t nBaseDamage = DATATBLS_GetObjectsTxtRecord(pSrcUnit ? pSrcUnit->dwClassId : -1)->nDamage;

    const int64_t nDamage = (ESE_ITEMS_RollLimitedRandomNumber(&pSrcUnit->pSeed, nMaxDamage - nMinDamage + 256) + nMinDamage) * nBaseDamage / 100;
    if (!nBaseDamage)
    {
        FOG_DisplayWarning("ptObjectData->bDamage", __FILE__, __LINE__);
    }

    if (!nDamage)
    {
        return;
    }

    ESE_D2DamageStrc damage = {};
    switch (nDamageType)
    {
    case 1:
        damage.dwFireDamage = nDamage;
        damage.dwHitClass = 0x20;
        break;

    case 2:
        damage.dwLtngDamage = nDamage;
        damage.dwHitClass = 0x40;
        break;

    case 3:
        damage.dwColdDamage = nDamage;
        damage.dwHitClass = 0x30;
        break;

    default:
        damage.dwPhysDamage = nDamage;
        break;
    }

    damage.wResultFlags = DAMAGERESULTFLAG_SUCCESSFULHIT;

    if (!STATES_CheckState(pTargetUnit, STATE_UNINTERRUPTABLE))
    {
        damage.wResultFlags |= DAMAGERESULTFLAG_GETHIT;
    }

    ESE_SUNITDMG_CalculateTotalDamage(pGame, pSrcUnit, pTargetUnit, &damage);
    ESE_SUNITDMG_ExecuteEvents(pGame, pSrcUnit, pTargetUnit, 0, &damage);
    ESE_SUNITDMG_ExecuteMissileDamage(pGame, pSrcUnit, pTargetUnit, &damage);
}
