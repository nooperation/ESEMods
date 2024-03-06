#include "D2Game/SKILLS/SkillBar_ESE.h"
#include "D2Game/SKILLS/SkillAss_ESE.h"
#include "D2Game/SKILLS/SkillDruid_ESE.h"
#include "D2Game/SKILLS/SkillNec_ESE.h"
#include "D2Game/SKILLS/Skills_ESE.h"
#include "D2Game/UNIT/SUnitDmg_ESE.h"
#include "D2Common/Units/Missile_ESE.h"
#include "D2Common/D2Skills_ESE.h"
#include "D2Game/MISSILES/Missiles_ESE.h"

#include <D2DataTbls.h>
#include <DataTbls/SkillsTbls.h>
#include <D2Dungeon.h>
#include <D2StatList.h>
#include <D2States.h>
#include <Units/UnitRoom.h>
#include <D2Math.h>
#include <D2Monsters.h>
#include <D2Items.h>
#include <D2Collision.h>
#include <D2BitManip.h>
#include <Path/Step.h>
#include <Path/IDAStar.h>
#include <DataTbls/MonsterIds.h>
#include <D2Composit.h>
#include <UselessOrdinals.h>
#include <AI/AiGeneral.h>
#include <AI/AiThink.h>
#include <AI/AiUtil.h>
#include <GAME/Clients.h>
#include <GAME/Event.h>
#include <MONSTER/MonsterMode.h>
#include <MONSTER/MonsterMsg.h>
#include <MONSTER/MonsterRegion.h>
#include <OBJECTS/ObjMode.h>
#include <PLAYER/Player.h>
#include <PLAYER/PlrModes.h>
#include <PLAYER/PlrSave2.h>
#include <UNIT/SUnit.h>
#include <UNIT/SUnitEvent.h>
#include <UNIT/SUnitMsg.h>
#include <ITEMS/Items.h>

#include <algorithm>

#pragma pack(push, 1)
struct D2PotionCodeStrc
{
    uint32_t nHealthPotionCode;
    uint32_t nManaPotionCode;
    uint32_t nRejuvPotionCode;
};
#pragma pack(pop)


//D2Game.0x6FCFABF0
int32_t __fastcall ESE_SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    ESE_sub_6FD15470(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel));

    ESE_D2DamageStrc damage = {};
    damage.wResultFlags = ESE_SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        ESE_D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    uint8_t nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!pSkillsTxtRecord->nSrcDam)
    {
        nSrcDam = 0x80u;
    }

    ESE_SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);

    ESE_D2DamageStrc* pDamage = ESE_SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (pDamage)
    {
        pDamage->dwPhysDamage += (int64_t)SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel) << 8;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        int32_t nUnitGUID = -1;
        int32_t nUnitType = 6;
        if (pUnit)
        {
            nUnitGUID = pUnit->dwUnitId;
            nUnitType = pUnit->dwUnitType;
        }

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 4u, 0, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 1;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        D2Common_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatRemoveCallback(pStatList, ESE_sub_6FD10E50);
    }

    STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    ESE_sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);

    return 1;
}

//D2Game.0x6FCFAE50
int32_t __fastcall ESE_SKILLS_SrvSt33_FindPotion_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int32_t nResult = D2Common_11018(pTarget);
    if (!nResult || !STATES_CheckState(pTarget, STATE_CORPSE_NOSELECT))
    {
        return nResult;
    }

    return 0;
}

//D2Game.0x6FCFAE90
int32_t __fastcall ESE_SKILLS_SrvDo069_FindPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    constexpr D2PotionCodeStrc gdwPotionsTable[15] = {
        {' 2ph', ' 2pm', ' svr'},
        {' 3ph', ' 3pm', ' svr'},
        {' 3ph', ' 3pm', ' svr'},
        {' 4ph', ' 4pm', ' lvr'},
        {' 4ph', ' 4pm', ' lvr'},
        {' 4ph', ' 4pm', ' lvr'},
        {' 4ph', ' 5pm', ' lvr'},
        {' 5ph', ' 5pm', ' lvr'},
        {' 5ph', ' 5pm', ' lvr'},
        {' 5ph', ' 5pm', ' lvr'},
        {' 5ph', ' 5pm', ' lvr'},
        {' 5ph', ' 5pm', ' lvr'},
        {' 5ph', ' 5pm', ' lvr'},
        {' 5ph', ' 5pm', ' lvr'},
        {' 5ph', ' 5pm', ' lvr'},
    };

    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || !D2Common_11018(pTarget) || STATES_CheckState(pTarget, STATE_CORPSE_NOSELECT))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, STATE_CORPSE_NOSELECT, 1);
    UNITROOM_RefreshUnit(pTarget);

    if ((ITEMS_RollRandomNumber(&pUnit->pSeed) % 100) >= SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel))
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        OBJMODE_DropItemWithCodeAndQuality(pGame, pTarget, 0, 2);
        return 1;
    }

    const int32_t nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    if (nAct < 0 || nAct >= 5)
    {
        OBJMODE_DropItemWithCodeAndQuality(pGame, pTarget, 0, 2);
        return 1;
    }

    const int32_t nIndex = nAct + 5 * pGame->nDifficulty;
    if (nIndex >= std::size(gdwPotionsTable))
    {
        OBJMODE_DropItemWithCodeAndQuality(pGame, pTarget, 0, 2);
        return 1;
    }

    const uint32_t nChance = ITEMS_RollRandomNumber(&pUnit->pSeed) % 100;

    if (nChance >= pSkillsTxtRecord->dwParam[2])
    {
        if (nChance >= pSkillsTxtRecord->dwParam[2] + pSkillsTxtRecord->dwParam[3])
        {
            OBJMODE_DropItemWithCodeAndQuality(pGame, pTarget, gdwPotionsTable[nIndex].nHealthPotionCode, 2);
        }
        else
        {
            OBJMODE_DropItemWithCodeAndQuality(pGame, pTarget, gdwPotionsTable[nIndex].nRejuvPotionCode, 2);
        }
    }
    else
    {
        OBJMODE_DropItemWithCodeAndQuality(pGame, pTarget, gdwPotionsTable[nIndex].nManaPotionCode, 2);
    }

    return 1;
}

//D2Game.0x6FCFB070
int32_t __fastcall ESE_SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int32_t nExpireFrame = pGame->dwGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(a2, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        int32_t nUnitGUID = -1;
        int32_t nUnitType = 6;
        if (pUnit)
        {
            nUnitGUID = pUnit->dwUnitId;
            nUnitType = pUnit->dwUnitType;
        }

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, nUnitType, nUnitGUID);
        if (pStatList)
        {
            STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
            STATLIST_SetStatRemoveCallback(pStatList, ESE_sub_6FD10E50);
            D2Common_10475_PostStatToStatList(a2, pStatList, 1);
            STATES_ToggleState(a2, pSkillsTxtRecord->nAuraState, 1);
        }
    }

    STATES_ToggleGfxStateFlag(a2, pSkillsTxtRecord->nAuraState, 1);
    D2Common_10476(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, a2, UNITEVENTCALLBACK_REMOVESTATE, nExpireFrame, 0, 0);
    ESE_sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    ESE_sub_6FD14C30(a2);
    return 1;
}

//D2Game.0x6FCFB1D0
int32_t __fastcall ESE_SKILLS_SrvDo068_BasicShout(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (!ESE_SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int32_t nMissileId = ESE_SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    ESE_sub_6FD14170(pGame, pUnit, pUnit, nMissileId, nSkillId, nSkillLevel, 0);
    ESE_SKILLS_ApplyWarcryStats(pGame, pUnit, pUnit, nSkillId, nSkillLevel);
    return 1;
}

//D2Game.0x6FCFB270
int32_t __fastcall ESE_SKILLS_SrvDo070_DoubleSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (((pUnit->dwSeqFrame >> 8) % 2) != 0)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;

        pTarget = ESE_sub_6FD107F0(pGame, pUnit, 0, 0, ESE_sub_6FD15460(pUnit), 0x20003u, pTarget->dwUnitId, 0);
        if (!pTarget)
        {
            return 0;
        }

        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    }

    ESE_SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(pGame, pUnit, nSkillId, nSkillLevel);
    ESE_SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    return 1;
}

//D2Game.0x6FCFB320
int32_t __fastcall ESE_SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (!ESE_sub_6FD15190(pUnit, 12) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    int32_t nOwnerGUID = 0;
    int32_t nOwnerType = 0;
    AIGENERAL_GetOwnerData(pUnit, &nOwnerGUID, &nOwnerType);

    return nOwnerGUID == -1 || nOwnerType != UNIT_PLAYER;
}

//D2Game.0x6FCFB390
int32_t __fastcall ESE_SKILLS_SrvDo071_Taunt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int32_t nUnitGUID = 0;
    int32_t nUnitType = 0;
    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || !ESE_sub_6FD15190(pTarget, 12) || SUNIT_IsDead(pTarget) || (AIGENERAL_GetOwnerData(pTarget, &nUnitGUID, &nUnitType), nUnitGUID != -1) && nUnitType == UNIT_PLAYER || !sub_6FCBD900(pGame, pUnit, pTarget))
    {
        pTarget = ESE_SKILLS_FindAuraTarget(pGame, pUnit, 20, ESE_SKILLS_Callback_FindTargetForTaunt);
    }

    if (!pTarget)
    {
        return 0;
    }

    D2UnkNecSkillStrc curseData = {};

    curseData.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curseData.pGame = pGame;
    curseData.nSkillId = nSkillId;
    curseData.pUnit = pUnit;
    curseData.unk0x08 = 1;
    curseData.nSkillLevel = nSkillLevel;
    curseData.bUpdateAnimRate = 0;

    for (int32_t i = 0; i < 6; ++i)
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ESE_SKILLS_GetItemStatCostTxtRecord(pSkillsTxtRecord->wAuraStat[i]);
        if (!pItemStatCostTxtRecord)
        {
            curseData.nAuraStat[i] = -1;
            break;
        }

        if (pItemStatCostTxtRecord->dwItemStatFlags & gdwBitMasks[9])
        {
            curseData.bUpdateAnimRate = 1;
        }

        curseData.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
        curseData.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
    }

    curseData.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
    ESE_sub_6FD0B450(pTarget, &curseData);

    D2AiControlStrc* pAiControl = nullptr;
    if (pTarget->dwUnitType == UNIT_MONSTER && pTarget->pMonsterData)
    {
        pAiControl = pTarget->pMonsterData->pAiControl;
    }

    AITHINK_SetAiControlParams(pAiControl, -666, -666, -666);
    AIUTIL_SetOwnerGUIDAndType(pTarget, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, UNITEVENTCALLBACK_AITHINK, 0);
    EVENT_SetEvent(pGame, pTarget, UNITEVENTCALLBACK_AITHINK, pGame->dwGameFrame + 1, 0, 0);
    UNITS_SetTargetUnitForDynamicUnit(pTarget, pUnit);
    return 1;
}

//D2Game.0x6FCFB610
int32_t __fastcall ESE_SKILLS_SrvSt34_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return D2Common_11019(pTarget) != 0;
}

//D2Game.0x6FCFB630
int32_t __fastcall ESE_SKILLS_SrvDo072_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || !D2Common_11019(pTarget))
    {
        return 0;
    }

    if (STATES_CheckState(pTarget, STATE_CORPSE_NOSELECT))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, STATE_CORPSE_NOSELECT, 1);
    UNITROOM_RefreshUnit(pTarget);

    if ((ITEMS_RollRandomNumber(&pUnit->pSeed) % 100) >= SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel))
    {
        return 0;
    }

    const int32_t nRand = ITEMS_RollRandomNumber(&pUnit->pSeed) % 100;

    int32_t nParam = 1;
    const int32_t nSum1 = pSkillsTxtRecord->dwParam[0] + pSkillsTxtRecord->dwParam[1];
    if (nRand >= pSkillsTxtRecord->dwParam[0] && nRand < nSum1)
    {
        nParam = 2;
    }

    const int32_t nSum2 = nSum1 + pSkillsTxtRecord->dwParam[2];
    if (nRand >= nSum1 && nRand < nSum2)
    {
        nParam = 3;
    }

    if (nRand >= nSum1 + pSkillsTxtRecord->dwParam[2] && nRand < nSum2 + pSkillsTxtRecord->dwParam[3])
    {
        nParam = 4;
    }

    sub_6FC659B0(pGame, pTarget, pUnit, nParam);
    return 1;
}

//D2Game.0x6FCFB7A0
int32_t __fastcall ESE_SKILLS_SrvDo074_DoubleThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pItem = sub_6FC7C7B0(pUnit);
    if (!pItem)
    {
        return 0;
    }

    const int32_t nMissileId = ITEMS_GetMissileType(pItem);
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pMissile = nullptr;
    if (D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_MISSILE_POTION))
    {
        pMissile = ESE_sub_6FD11710(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = ESE_sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    if (pMissile)
    {
        STATLIST_AddUnitStat(pMissile, STAT_TOHIT, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
        STATLIST_AddUnitStat(pMissile, STAT_DAMAGEPERCENT, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel), 0);
    }

    return 1;
}

//D2Game.0x6FCFB8A0
int32_t __fastcall ESE_SKILLS_SrvDo075_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || !D2Common_11018(pTarget))
    {
        return 0;
    }

    D2CoordStrc coords = {};
    coords.nX = CLIENTS_GetUnitX(pTarget);
    coords.nY = CLIENTS_GetUnitY(pTarget);
    
    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pTarget), coords.nX, coords.nY);
    if (!pRoom || !COLLISION_GetFreeCoordinates(pRoom, &coords, 2, 0x1000u, 1) || pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }
    
    int32_t nMissileId = pSkillsTxtRecord->wSrvMissileA;
    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(pTarget->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pMonStats2TxtRecord->dwFlags & gdwBitMasks[MONSTATS2FLAGINDEX_LARGE])
    {
        nMissileId = pSkillsTxtRecord->wSrvMissileC;
    }
    else if (pMonStats2TxtRecord->dwFlags & gdwBitMasks[MONSTATS2FLAGINDEX_SMALL])
    {
        nMissileId = pSkillsTxtRecord->wSrvMissileB;
    }

    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nX = coords.nX;
    missileParams.nY = coords.nY;

    ESE_MISSILES_CreateMissileFromParams(pGame, &missileParams);
    STATES_ToggleState(pTarget, STATE_CORPSE_NODRAW, 1);
    STATES_ToggleState(pTarget, STATE_CORPSE_NOSELECT, 1);
    UNITROOM_RefreshUnit(pTarget);

    return 1;
}

//D2Game.0x6FCFBB40
int32_t __fastcall ESE_SKILLS_RollFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !pTarget)
    {
        return 0;
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);

    ESE_D2DamageStrc damage = {};
    damage.wResultFlags = ESE_SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

        if (pSkillsTxtRecord->nEType)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        ESE_D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    uint8_t nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!pSkillsTxtRecord->nSrcDam)
    {
        nSrcDam = 0x80u;
    }

    ESE_SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    ESE_SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
        {
            SKILLS_SetParam1(pSkill, 1);
            return 1;
        }

        SKILLS_SetParam1(pSkill, 0);
    }

    return 1;
}

//D2Game.0x6FCFBCE0
void __fastcall ESE_SKILLS_ApplyFrenzyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || !SKILLS_GetParam1(pSkill) || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    const int32_t nFrame = pGame->dwGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        int32_t nUnitGUID = -1;
        int32_t nUnitType = 6;
        if (pUnit)
        {
            nUnitGUID = pUnit->dwUnitId;
            nUnitType = pUnit->dwUnitType;
        }

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nFrame, nUnitType, nUnitGUID);
        if (pStatList)
        {
            STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
            STATLIST_SetStatRemoveCallback(pStatList, ESE_sub_6FD10E50);
            STATLIST_SetStatIfListIsValid(pStatList, STAT_SKILL_FRENZY, 0, 0);
            D2Common_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
        }
    }

    if (pStatList)
    {
        D2Common_10476(pStatList, nFrame);
        EVENT_SetEvent(pGame, pUnit, UNITEVENTCALLBACK_REMOVESTATE, nFrame, 0, 0);
        STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);

        int32_t nValue = D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_SKILL_FRENZY, 0) + 1;
        if (nValue > nSkillLevel)
        {
            nValue = nSkillLevel;
        }
        STATLIST_SetStatIfListIsValid(pStatList, STAT_SKILL_FRENZY, nValue, 0);
        ESE_sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nValue);
    }
}

//D2Game.0x6FCFBE80
int32_t __fastcall ESE_SKILLS_SrvDo009_Frenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (((pUnit->dwSeqFrame >> 8) % 2) == 0)
    {
        ESE_SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        ESE_SUNITDMG_FreeAttackerDefenderCombatList(pGame, pUnit, pTarget);
        sub_6FC80A30(pGame, pUnit);
        sub_6FC80E10(pGame, pUnit);
        ESE_SKILLS_ApplyFrenzyStats(pGame, pUnit, nSkillId, nSkillLevel);
        return ESE_SKILLS_RollFrenzyDamage(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
    }

    pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;

    ESE_SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    sub_6FC80A30(pGame, pUnit);
    sub_6FC80E10(pGame, pUnit);
    ESE_SKILLS_ApplyFrenzyStats(pGame, pUnit, nSkillId, nSkillLevel);
    return ESE_SKILLS_RollFrenzyDamage(pGame, pUnit, ESE_sub_6FD107F0(pGame, pUnit, 0, 0, ESE_sub_6FD15460(pUnit), 0x20003u, pTarget->dwUnitId, 0), nSkillId, nSkillLevel);
}

//D2Game.0x6FCFBF80
void __fastcall ESE_SKILLS_CurseStateCallback_Whirlwind(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    D2_MAYBE_UNUSED(pStatList);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);

    SUNITEVENT_FreeTimer(pGame, pUnit, 1, nState);

    if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        STATES_ToggleState(pUnit, nState, 0);
        D2Common_10376_UNITS_UpdateAnimRateAndVelocity(pUnit, __FILE__, __LINE__);
        ESE_sub_6FD14C30(pUnit);
    }
}

//D2Game.0x6FCFBFE0
int32_t __fastcall ESE_SKILLS_SrvSt38_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        sub_6FCC63D0(pUnit, nSkillId);
        return 0;
    }

    int32_t nX = 0;
    int32_t nY = 0;
    if (!ESE_D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        sub_6FCC63D0(pUnit, nSkillId);
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        sub_6FCC63D0(pUnit, nSkillId);
        return ESE_sub_6FD150A0(pGame, pUnit, pTarget);
    }

    int32_t nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }

    if (!pUnit->pDynamicPath)
    {
        sub_6FCC63D0(pUnit, nSkillId);
        return 0;
    }

    const int32_t a2 = nUnitType == UNIT_PLAYER ? COLLIDE_MASK_WALKING_UNIT : COLLIDE_MASK_MONSTER_DEFAULT;
    PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, COLLIDE_MASK_PLAYER_WW);
    PATH_SetType(pUnit->pDynamicPath, PATHTYPE_UNKNOWN_7);

    if (!D2Common_10142(pUnit->pDynamicPath, pUnit, 0))
    {
        sub_6FCC63D0(pUnit, nSkillId);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, a2);
        return 0;
    }

    PATH_SetVelocity(pUnit->pDynamicPath, ESE_sub_6FD15500(pUnit), __FILE__, __LINE__);
    PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, COLLIDE_BLOCK_PLAYER | COLLIDE_BARRIER | COLLIDE_BLANK | COLLIDE_UNIT_RELATED);

    D2PathPointStrc* ppPathPoints = nullptr;
    const int32_t nPathPoints = PATH_GetPathPoints(pUnit->pDynamicPath, &ppPathPoints);
    if (nPathPoints <= 0)
    {
        sub_6FCC63D0(pUnit, nSkillId);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, a2);
        return 0;
    }

    nX = ppPathPoints[nPathPoints - 1].X;
    nY = ppPathPoints[nPathPoints - 1].Y;
    COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nUnitType == UNIT_PLAYER ? 0x80u : 0x100u);
    sub_6FCBDE90(pUnit, 1);
    STATES_ToggleState(pUnit, STATE_SKILL_MOVE, 1);

    SKILLS_SetFlags(pSkill, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    SKILLS_SetParam3(pSkill, -1);
    SKILLS_SetParam4(pSkill, 0);

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    ESE_sub_6FD11C90(pUnit, pSkillsTxtRecord->nAuraState, 0);

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nStat = -1;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nState = pSkillsTxtRecord->nAuraState;
    curse.pStateRemoveCallback = ESE_SKILLS_CurseStateCallback_Whirlwind;

    D2StatListStrc* pStatList = ESE_sub_6FD10EC0(&curse);
    if (!pStatList)
    {
        return 0;
    }

    ESE_sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    ESE_sub_6FCFE200(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    if (pSkillsTxtRecord->wAuraEvent[0] >= 0)
    {
        SUNITEVENT_FreeTimer(pGame, pUnit, 1, pSkillsTxtRecord->nAuraState);

        for (int32_t i = 0; i < 3; ++i)
        {
            if (pSkillsTxtRecord->wAuraEvent[i] < 0)
            {
                break;
            }

            ESE_sub_6FD156A0(pGame, pUnit, pSkillsTxtRecord->wAuraEvent[i], nSkillId, nSkillLevel, pSkillsTxtRecord->wAuraEventFunc[0], 1, pSkillsTxtRecord->nAuraState);
        }
    }

    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);
    return 1;
}

//D2Game.0x6FCFC3A0
int32_t __fastcall ESE_SKILLS_RemoveWhirlwindStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int32_t a4, int32_t nX, int32_t nY)
{
    // TODO: v9, pUnita

    SKILLS_SetFlags(pSkill, 0);
    sub_6FCBDE90(pUnit, 0);
    sub_6FCC63D0(pUnit, a4);

    if (!pUnit->pDynamicPath)
    {
        return 0;
    }

    const int32_t v9 = pUnit->dwUnitType == UNIT_PLAYER ? COLLIDE_PLAYER : COLLIDE_MONSTER;
    const int32_t pUnita = pUnit->dwUnitType == UNIT_PLAYER ? COLLIDE_MASK_WALKING_UNIT : COLLIDE_MASK_MONSTER_DEFAULT;
    if (nX && nY)
    {
        COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), v9);
    }

    PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, v9);
    PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, pUnita);

    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(a4);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 0);
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (pStatList)
        {
            D2Common_10474(pUnit, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
    }

    return 1;
}

//D2Game.0x6FCFC4C0
int32_t __fastcall ESE_SKILLS_SrvDo076_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int32_t nX = SKILLS_GetParam1(pSkill);
    const int32_t nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        ESE_SKILLS_RemoveWhirlwindStats(pGame, pUnit, pSkill, nSkillId, nX, nY);
        return 0;
    }

    uint32_t nSkillFlags = SKILLS_GetFlags(pSkill);
    if ((nSkillFlags & 3) == 3)
    {
        ESE_SKILLS_RemoveWhirlwindStats(pGame, pUnit, pSkill, nSkillId, nX, nY);
        return 1;
    }

    if (!(nSkillFlags & 1) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        UNITS_SetAnimationFrame(pUnit, 0);
        pUnit->dwFrameCountPrecise = 1024;
    }
    else
    {
        D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 3);
    }

    int32_t nCount = 0;
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        nCount = (ITEMS_RollRandomNumber(&pUnit->pSeed) & 1) == 0;
    }
    else
    {
        if (pGame->bExpansion)
        {
            const int32_t nFrame = SKILLS_GetParam4(pSkill);
            if (nFrame)
            {
                if (nFrame <= pGame->dwGameFrame)
                {
                    nCount = 1;
                    int32_t nDuration = 0;
                    D2UnitStrc* pWeapon = sub_6FC7C7B0(pUnit);
                    if (pWeapon)
                    {
                        const int32_t nAttackSpeed = ITEMS_GetWeaponAttackSpeed(pUnit, pWeapon);
                        if (nAttackSpeed < 12)
                        {
                            nDuration = 4;
                        }
                        else if (nAttackSpeed < 15)
                        {
                            nDuration = 6;
                        }
                        else if (nAttackSpeed < 18)
                        {
                            nDuration = 8;
                        }
                        else if (nAttackSpeed < 20)
                        {
                            nDuration = 10;
                        }
                        else if (nAttackSpeed < 23)
                        {
                            nDuration = 12;
                        }
                        else if (nAttackSpeed < 26)
                        {
                            nDuration = 14;
                        }
                        else
                        {
                            nDuration = 16;
                        }
                    }
                    else
                    {
                        nDuration = 10;
                    }

                    if (pUnit->pInventory)
                    {
                        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetCompositItem(pUnit->pInventory, COMPOSIT_LEFTHAND);
                        D2UnitStrc* pRightHandWeapon = INVENTORY_GetCompositItem(pUnit->pInventory, COMPOSIT_RIGHTHAND);
                        if (pLeftHandWeapon && D2Common_10731_ITEMS_CheckItemTypeId(pLeftHandWeapon, ITEMTYPE_MELEE_WEAPON) && pRightHandWeapon && D2Common_10731_ITEMS_CheckItemTypeId(pRightHandWeapon, ITEMTYPE_MELEE_WEAPON))
                        {
                            nCount = 2;
                        }
                    }

                    int32_t nNewFrame = nDuration + nFrame;
                    if (nNewFrame < pGame->dwGameFrame)
                    {
                        nNewFrame = pGame->dwGameFrame + nDuration;
                    }

                    SKILLS_SetParam4(pSkill, nNewFrame);
                }
                else
                {
                    nCount = 0;
                }
            }
            else
            {
                SKILLS_SetParam4(pSkill, pGame->dwGameFrame + 4);
                nCount = 1;
            }
        }
        else
        {
            nCount = 1;
        }
    }

    for (int32_t i = 0; i < nCount; ++i)
    {
        D2UnitStrc* pTarget = ESE_sub_6FD107F0(pGame, pUnit, 0, 0, 5, 3, SKILLS_GetParam3(pSkill), 0);
        if (pTarget)
        {
            SKILLS_SetParam3(pSkill, pTarget->dwUnitId);

            ESE_D2DamageStrc damage = {};
            damage.wResultFlags = ESE_SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
            if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
            {
                damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
                damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
                if (pSkillsTxtRecord->dwHitClass)
                {
                    damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
                }
                damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
                ESE_D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
            }

            uint8_t nSrcDam = pSkillsTxtRecord->nSrcDam;
            if (!pSkillsTxtRecord->nSrcDam)
            {
                nSrcDam = 0x80u;
            }

            ESE_SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
            ESE_SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        }
        else
        {
            SKILLS_SetParam3(pSkill, -1);
            nCount = 0;
        }

        uint32_t nFlags = SKILLS_GetFlags(pSkill);
        if (nFlags & 0x2000)
        {
            nFlags &= 0xDFFF;
        }
        else
        {
            nFlags |= 0x2000;
        }

        SKILLS_SetFlags(pSkill, nFlags);
    }

    return 1;
}

//D2Game.0x6FCFC8E0
int32_t __fastcall ESE_SKILLS_SrvSt39_Berserk(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    ESE_D2DamageStrc damage = {};
    damage.wResultFlags = ESE_SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

        if (pSkillsTxtRecord->nEType)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        ESE_D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    uint8_t nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!pSkillsTxtRecord->nSrcDam)
    {
        nSrcDam = 0x80u;
    }

    ESE_SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int32_t nFrame = pGame->dwGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nFrame <= pGame->dwGameFrame)
    {
        nFrame = pGame->dwGameFrame + 10;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        int32_t nUnitGUID = -1;
        int32_t nUnitType = 6;
        if (pUnit)
        {
            nUnitGUID = pUnit->dwUnitId;
            nUnitType = pUnit->dwUnitType;
        }

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 1;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, ESE_sub_6FD10E50);
        D2Common_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    }

    D2Common_10476(pStatList, nFrame);
    EVENT_SetEvent(pGame, pUnit, UNITEVENTCALLBACK_REMOVESTATE, nFrame, 0, 0);
    ESE_sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    return 1;
}

//D2Game.0x6FCFCB30
int32_t __fastcall ESE_SKILLS_SrvSt40_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int32_t nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }

    int32_t nX = 0;
    int32_t nY = 0;
    D2CoordStrc coords = {};

    if (nUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget)
        {
            sub_6FC627B0(pUnit, MONMODE_ATTACK1);
            sub_6FC62D90(pUnit, pGame);
            ESE_SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
            SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
            SKILLS_SetParam4(pSkill, pTarget->dwUnitId);

            if (SUNIT_IsDead(pUnit))
            {
                return 0;
            }

            nX = 2 * CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
            nY = 2 * CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
        }
        else
        {
            if (!ESE_D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
            {
                UNITS_SetUsedSkill(pUnit, 0);
                return 0;
            }
            SKILLS_SetParam4(pSkill, -1);
        }

        coords.nX = nX;
        coords.nY = nY;

        if (!COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &coords, UNITS_GetUnitSizeX(pUnit), 0x3C01, 0))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            return 0;
        }

        nX = coords.nX;
        nY = coords.nY;
    }
    else
    {
        if (!ESE_D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        {
            return 0;
        }

        coords.nX = nX;
        coords.nY = nY;
        if (!pSkillsTxtRecord)
        {
            return 0;
        }
        
        D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), coords.nX, coords.nY);
        if (!pRoom || !(pSkillsTxtRecord->dwFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN]) && DUNGEON_IsRoomInTown(pRoom))
        {
            return 0;
        }

        if (!ESE_SKILLS_FindLeapTargetPosition(pUnit, nSkillId, nSkillLevel, &nX, &nY))
        {
            return 0;
        }
    }

    COLLISION_SetMaskWithPattern(D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY), nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80u);
    sub_6FCBDE90(pUnit, 1);
    STATES_ToggleState(pUnit, STATE_SKILL_MOVE, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);

    if (nUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget)
        {
            SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
            SKILLS_SetParam4(pSkill, pTarget->dwUnitId);
        }
    }

    SKILLS_SetFlags(pSkill, 0x80u);
    return 1;
}

//D2Game.0x6FCFCF60
int32_t __fastcall ESE_SKILLS_FindLeapTargetPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t* pX, int32_t* pY)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int32_t nUnitX = CLIENTS_GetUnitX(pUnit);
    const int32_t nUnitY = CLIENTS_GetUnitY(pUnit);
    const int32_t nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);

    int32_t nDistance = D2Common_10398_UNITS_GetDistanceToCoordinates(pUnit, *pX, *pY);
    if (nDistance <= 1)
    {
        nDistance = 1;
    }

    if (nDistance > nAuraRange)
    {
        *pX = nUnitX + nAuraRange * (*pX - nUnitX) / nDistance;
        *pY = nUnitY + nAuraRange * (*pY - nUnitY) / nDistance;
    }

    int32_t nY = *pY;
    int32_t nDiffY = D2Clamp(*pY - nUnitY, -2, 2);
    int32_t nX = *pX;
    int32_t nDiffX = D2Clamp(nUnitX - *pX, -2, 2);

    D2CoordStrc coords = {};
    coords.nX = nX;
    coords.nY = nY;

    int32_t nCounter = 3;
    while (nCounter)
    {
        D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), coords.nX, coords.nY), &coords, UNITS_GetUnitSizeX(pUnit), 0x1C09u, 1);
        nX = coords.nX;
        nY = coords.nY;
        if (pRoom && !COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x1C09) && D2Common_11025(nUnitX, nUnitY, nX, nY, pRoom, 0x804) && D2Common_10398_UNITS_GetDistanceToCoordinates(pUnit, nX, nY) <= nAuraRange)
        {
            *pX = nX;
            *pY = nY;
            return 1;
        }

        --nCounter;

        if (nCounter == 2)
        {
            coords.nX = nDiffY + *pX;
            coords.nY = nDiffX + *pY;
        }
        else if (nCounter == 1)
        {
            coords.nX = *pX - nDiffY;
            coords.nY = *pY - nDiffX;
        }
    }

    return 0;
}

//D2Game.0x6FCFD280
int32_t __fastcall ESE_SKILLS_SrvDo077_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);

    const int32_t nUnitType = pUnit ? pUnit->dwUnitType : 6;

    const int32_t nSkillFlags = SKILLS_GetFlags(pSkill);
    if (nSkillFlags & 0x100)
    {
        if (ESE_SKILLS_Leap(pGame, pUnit, pSkill) && nUnitType != UNIT_MONSTER)
        {
            ESE_D2DamageStrc damage = {};
            damage.wResultFlags = 9;
            ESE_sub_6FD10200(pGame, pUnit, 0, 0, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel), &damage, 0);
            return 1;
        }
    }
    else
    {
        if (nSkillFlags & 0x80)
        {
            return ESE_SKILLS_SetVelocityForLeap(pGame, pUnit, pSkill);
        }

        if (nUnitType != UNIT_MONSTER)
        {
            SKILLS_SetFlags(pSkill, 0);
        }
    }

    return 1;
}

//D2Game.0x6FCFD3C0
int32_t __fastcall ESE_SKILLS_SetVelocityForLeap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pUnit->pDynamicPath)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 0x1101u);
    PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, COLLIDE_NONE);
    PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_NONE);

    const int32_t nX = SKILLS_GetParam1(pSkill);
    const int32_t nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    D2Common_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    PATH_SetType(pUnit->pDynamicPath, PATHTYPE_LEAP);

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        PATH_SetVelocity(pUnit->pDynamicPath, PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId)->nRunSpeed << 8, __FILE__, __LINE__);
        D2Common_10142(pUnit->pDynamicPath, pUnit, 0);
        return 1;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (pMonStatsTxtRecord)
    {
        PATH_SetVelocity(pUnit->pDynamicPath, pMonStatsTxtRecord->nRun << 8, __FILE__, __LINE__);
        D2Common_10142(pUnit->pDynamicPath, pUnit, 0);
        return 1;
    }

    return 0;
}

//D2Game.0x6FCFD4C0
int32_t __fastcall ESE_SKILLS_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pUnit->pDynamicPath)
    {
        return 0;
    }
    
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int32_t nX = SKILLS_GetParam1(pSkill);
    const int32_t nY = SKILLS_GetParam2(pSkill);

    int32_t nBaseId = -1;
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord)
        {
            nBaseId = pMonStatsTxtRecord->nBaseId;
        }
    }

    if (nBaseId < 0 || nBaseId > sgptDataTables->nMonStatsTxtRecordCount)
    {
        nBaseId = -1;
    }

    if (CLIENTS_GetUnitX(pUnit) == nX && CLIENTS_GetUnitY(pUnit) == nY)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x100);
            PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_MONSTER);
            PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, COLLIDE_MASK_MONSTER_DEFAULT);
            PATH_SetType(pUnit->pDynamicPath, PATHTYPE_TOWARD);

            if (nBaseId == MONSTER_SANDLEAPER1)
            {
                if (pSkill)
                {
                    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam3(pSkill), SKILLS_GetParam4(pSkill));
                    if (pTarget)
                    {
                        SKILLS_SetFlags(pSkill, 1);
                        UNITS_SetAnimationFrame(pUnit, 12);
                        pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 256;
                        D2Common_10233_PATH_RecacheRoomIfNeeded(pUnit->pDynamicPath);
                        PATH_SetNewDistance(pUnit->pDynamicPath, 5);
                        PATH_SetStepNum(pUnit->pDynamicPath, 1);
                        PATH_SetTargetUnit(pUnit->pDynamicPath, 0);

                        const int32_t nTargetX = 3 * nX - 2 * CLIENTS_GetUnitX(pTarget);
                        const int32_t nTargetY = 3 * nY - 2 * CLIENTS_GetUnitY(pTarget);
                        D2ActiveRoomStrc* pTargetRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nTargetX, nTargetY);
                        if (!pTargetRoom || !DUNGEON_IsRoomInTown(pTargetRoom))
                        {
                            D2Common_10170_PathSetTargetPos(pUnit->pDynamicPath, nTargetX, nTargetY);
                            PATH_SetType(pUnit->pDynamicPath, PATHTYPE_KNOCKBACK_SERVER);
                            D2Common_10190_PATH_SetDistance(pUnit->pDynamicPath, 5u);
                            D2Common_10142(pUnit->pDynamicPath, pUnit, 0);
                        }
                    }
                }
            }
            else
            {
                SKILLS_SetFlags(pSkill, 0x200);
                pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) - 256;
            }
        }
        else
        {
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80u);
            PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_PLAYER);
            PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, COLLIDE_MASK_WALKING_UNIT);
            PATH_SetType(pUnit->pDynamicPath, PATHTYPE_UNKNOWN_7);
            SKILLS_SetFlags(pSkill, 0x200);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, UNITEVENTCALLBACK_ENDANIM, 0);
            EVENT_SetEvent(pGame, pUnit, UNITEVENTCALLBACK_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        }

        sub_6FCBDE90(pUnit, 0);
        sub_6FCC63D0(pUnit, SKILLS_GetSkillIdFromSkill(pSkill, __FILE__, __LINE__));
        return 1;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 10);
        return 0;
    }

    int32_t nAnimFrame = 0;
    if (nBaseId == MONSTER_SANDLEAPER1)
    {
        nAnimFrame = 8;
    }
    else if (nBaseId == MONSTER_ANCIENTBARB1)
    {
        nAnimFrame = D2Common_10398_UNITS_GetDistanceToCoordinates(pUnit, nX, nY) < 2 ? 12 : 10;
    }

    UNITS_SetAnimationFrame(pUnit, nAnimFrame);
    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 256;
    return 0;
}

//D2Game.0x6FCFD880
int32_t __fastcall ESE_SKILLS_SrvSt41_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
	if (!pSkill)
	{
		return 0;
	}

	D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    
    int32_t nX = 0;
    int32_t nY = 0;
    if (!SKILLS_CheckIfCanLeapTo(pUnit, pTarget, &nX, &nY))
    {
        if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            ESE_sub_6FD150A0(pGame, pUnit, pTarget);
            return 1;
        }

        return 0;
    }

	D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    COLLISION_SetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), COLLIDE_PLAYER);

    sub_6FCBDE90(pUnit, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);

    if (pTarget)
    {
        SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
        SKILLS_SetParam4(pSkill, pTarget->dwUnitId);
    }
    else
    {
        SKILLS_SetParam3(pSkill, 6);
    }

    SKILLS_SetFlags(pSkill, 0x1080);
    STATES_ToggleState(pUnit, STATE_SKILL_MOVE, 1);

    if (pTarget && STATES_CheckState(pTarget, STATE_UNINTERRUPTABLE))
    {
        ESE_sub_6FD14F70(pGame, pUnit, pTarget, 100);
    }

	return 1;
}

//D2Game.0x6FCFD9B0
int32_t __fastcall ESE_SKILLS_SrvDo078_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int32_t nSkillFlags = SKILLS_GetFlags(pSkill);
    if (nSkillFlags & 0x100)
    {
        if (ESE_SKILLS_Leap(pGame, pUnit, pSkill))
        {
            if (!ESE_SKILLS_FindLeapAttackTarget(pGame, pUnit, pSkill))
            {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
                EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + 4, 0, 0);
                return 0;
            }

            D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 16);
        }

        return 1;
    }

    if (nSkillFlags & 0x80)
    {
        return ESE_SKILLS_SetVelocityForLeap(pGame, pUnit, pSkill);
    }

    if (!(SKILLS_GetFlags(pSkill) & 0x200))
    {
        SKILLS_SetFlags(pSkill, 0x1000u);
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pDefender = ESE_SKILLS_FindLeapAttackTarget(pGame, pUnit, pSkill);
    if (!pDefender)
    {
        return 0;
    }

    ESE_D2DamageStrc damage = {};

    damage.wResultFlags = ESE_SUNITDMG_GetResultFlags(pGame, pUnit, pDefender, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.wResultFlags |= 8u;
        damage.dwHitClass = UNITS_GetHitClass(pUnit);
        damage.dwHitFlags |= 0x20;
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

        if (pSkillsTxtRecord->nEType)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        ESE_D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);

        uint8_t nSrcDam = pSkillsTxtRecord->nSrcDam;
        if (!pSkillsTxtRecord->nSrcDam)
        {
            nSrcDam = 0x80u;
        }

        ESE_SUNITDMG_AllocCombat(pGame, pUnit, pDefender, &damage, nSrcDam);

        ESE_SUNITDMG_DrainItemDurability(pGame, pUnit, pDefender, 0);

        if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay <= sgptDataTables->nOverlayTxtRecordCount)
        {
            UNITS_SetOverlay(pDefender, pSkillsTxtRecord->wSrvOverlay, 0);
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, STATE_STUNNED);
        if (pStatList)
        {
            D2Common_10474(pDefender, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
    }

    return 1;
}

//D2Game.0x6FCFDC40
D2UnitStrc* __fastcall ESE_SKILLS_FindLeapAttackTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        if (UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
            SKILLS_SetParam4(pSkill, pTarget->dwUnitId);
            return pTarget;
        }

        pTarget = nullptr;
    }

    const int32_t nUnitType = SKILLS_GetParam3(pSkill);
    if (nUnitType != 6)
    {
        pTarget = SUNIT_GetServerUnit(pGame, nUnitType, SKILLS_GetParam4(pSkill));
    }

    if (pTarget)
    {
        SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
        SKILLS_SetParam4(pSkill, pTarget->dwUnitId);
        return pTarget;
    }

    pTarget = ESE_sub_6FD107F0(pGame, pUnit, 0, 0, ESE_sub_6FD15460(pUnit), 0x20003u, -1, 0);
    if (!pTarget)
    {
        SKILLS_SetParam3(pSkill, 6);
        return nullptr;
    }

    SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
    SKILLS_SetParam4(pSkill, pTarget->dwUnitId);
    return pTarget;
}
