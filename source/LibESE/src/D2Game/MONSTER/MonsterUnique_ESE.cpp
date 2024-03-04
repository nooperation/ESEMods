#include "D2Game/MONSTER/MonsterUnique_ESE.h"
#include "D2Game/MONSTER/MonsterMode_ESE.h"
#include "D2Game/SKILLS/SkillAss_ESE.h"
#include "D2Game/SKILLS/Skills_ESE.h"
#include "D2Game/SKILLS/SkillSor_ESE.h"
#include "D2Game/UNIT/SUnitDmg_ESE.h"
#include "D2Common/Units/Missile_ESE.h"
#include "D2Common/D2Skills_ESE.h"

#include <D2BitManip.h>
#include <D2Math.h>
#include <D2StatList.h>
#include <D2DataTbls.h>
#include <DataTbls/SkillsIds.h>
#include <D2Monsters.h>
#include <D2States.h>
#include <DataTbls/MonsterIds.h>
#include <DataTbls/MissilesIds.h>
#include <D2Collision.h>
#include <D2Items.h>
#include <D2Dungeon.h>
#include <AI/AiGeneral.h>
#include <AI/AiTactics.h>
#include <AI/AiThink.h>
#include <AI/AiUtil.h>
#include <GAME/Clients.h>
#include <GAME/Event.h>
#include <ITEMS/ItemMode.h>
#include <ITEMS/Items.h>
#include <MONSTER/Monster.h>
#include <MONSTER/MonsterRegion.h>
#include <MONSTER/MonsterSpawn.h>
#include <PLAYER/PlayerPets.h>
#include <QUESTS/Quests.h>
#include <QUESTS/QuestsFX.h>
#include <UNIT/SUnit.h>

#include <algorithm>

//D2Game.0x6FC6B030
void __fastcall ESE_MONSTERUNIQUE_UMod16_Champion(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (!pMonStatsTxtRecord || !bUnique)
    {
        return;
    }

    STATLIST_SetUnitStat(pUnit, STAT_LEVEL, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) - 1, 0);
    const int64_t nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
    STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, Clamp64To32Unsigned(nExperience - 2LL * nExperience / 5LL), 0);

    D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(11);
    int64_t nDamagePercent = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;
    pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(10);
    int64_t nToHitPercent = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pDifficultyLevelsTxtRecord)
    {
        nDamagePercent = nDamagePercent * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;
        nToHitPercent = nToHitPercent * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_DAMAGEPERCENT, Clamp64To32(nDamagePercent), 0);
    STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, Clamp64To32(nToHitPercent), 0);

    if (pMonStatsTxtRecord->nVelocity <= 0 || nUMod == 36)
    {
        return;
    }

    // TODO: First case can never be reached
    if (nUMod == 36)
    {
        STATLIST_AddUnitStat(pUnit, STAT_VELOCITYPERCENT, -33, 0);
    }
    else if (nUMod == 37)
    {
        const int32_t nVelocityPercent = D2Clamp(2048 / pMonStatsTxtRecord->nVelocity - 128, 10, 100);
        STATLIST_AddUnitStat(pUnit, STAT_VELOCITYPERCENT, nVelocityPercent, 0);
    }
    else
    {
        STATLIST_AddUnitStat(pUnit, STAT_VELOCITYPERCENT, 20, 0);
    }
}

//D2Game.0x6FC6B210
void __fastcall ESE_MONSTERUNIQUE_UMod36_Ghostly(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame || !bUnique)
    {
        return;
    }

    if (pUnit->pMonsterData)
    {
        pUnit->pMonsterData->nTypeFlag |= 0x40u;
    }

    STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, 80, 0);
    ESE_MONSTERUNIQUE_UMod16_Champion(pUnit, nUMod, bUnique);

    const uint8_t nDifficulty = D2Clamp(pGame->nDifficulty, 0ui8, 2ui8);
    const int32_t nGameType = pGame->nGameType || pGame->dwGameType;
    const int32_t nLevel = D2Clamp(STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, sgptDataTables->nMonLvlTxtRecordCount - 1);

    D2MonLvlTxt* pMonLvlTxtRecord = &sgptDataTables->pMonLvlTxt[nLevel];
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int64_t nDamage = nGameType ? pMonLvlTxtRecord->dwLDM[nDifficulty] : pMonLvlTxtRecord->dwDM[nDifficulty];

    D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 22);
    int64_t nDamagePercent = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

    STATLIST_AddUnitStat(pUnit, STAT_COLDMINDAM, Clamp64To32(nDamage * nDamagePercent / 100), 0);

    pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 25);
    nDamagePercent = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

    STATLIST_AddUnitStat(pUnit, STAT_COLDMAXDAM, Clamp64To32(nDamage * nDamagePercent / 100), 0);
    STATLIST_AddUnitStat(pUnit, STAT_COLDLENGTH, 150, 0);
}

//D2Game.0x6FC6B4B0
void __fastcall ESE_MONSTERUNIQUE_UMod39_Berserk(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pGame || !bUnique)
    {
        return;
    }

    const int64_t nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    const int64_t nNewHp = ESE_DATATBLS_ApplyRatio(nMaxHp, -75, 100) + nMaxHp;
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, Clamp64To32(nNewHp), 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, Clamp64To32(nNewHp), 0);

    int64_t nDamage = 300;
    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pUnit->pGame->nDifficulty);
    if (pDifficultyLevelsTxtRecord)
    {
        nDamage = 3LL * pDifficultyLevelsTxtRecord->dwChampionDmgBonus;
    }
    STATLIST_AddUnitStat(pUnit, STAT_DAMAGEPERCENT, Clamp64To32(nDamage), 0);
    STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, Clamp64To32(nDamage), 0);
}

//D2Game.0x6FC6B610
void __fastcall ESE_MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !bUnique)
    {
        return;
    }

    if (nUMod == 28)
    {
        STATLIST_SetUnitStat(pUnit, STAT_ARMORCLASS, Clamp64To32(2LL * (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_ARMORCLASS, 0)), 0);
    }

    int32_t nImmunities = 0;
    const int32_t nFireResist = STATLIST_UnitGetStatValue(pUnit, STAT_FIRERESIST, 0);
    const int32_t nLightResist = STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTRESIST, 0);
    const int32_t nColdResist = STATLIST_UnitGetStatValue(pUnit, STAT_COLDRESIST, 0);
    const int32_t nPoisonResist = STATLIST_UnitGetStatValue(pUnit, STAT_POISONRESIST, 0);
    const int32_t nDamageResist = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGERESIST, 0);
    const int32_t nMagicResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAGICRESIST, 0);

    if (nFireResist >= 100)
    {
        ++nImmunities;
    }

    if (nLightResist >= 100)
    {
        ++nImmunities;
    }

    if (nColdResist >= 100)
    {
        ++nImmunities;
    }

    if (nPoisonResist >= 100)
    {
        ++nImmunities;
    }

    if (nDamageResist >= 100)
    {
        ++nImmunities;
    }

    if (nMagicResist >= 100)
    {
        ++nImmunities;
    }

    if (nImmunities < 2)
    {
        switch (nUMod)
        {
        case 8:
            if (nColdResist < 100)
            {
                const int32_t nNewColdResist = nColdResist + 40;
                STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                if (nNewColdResist >= 100)
                {
                    ++nImmunities;
                }
            }

            if (nImmunities < 2)
            {
                if (nFireResist < 100)
                {
                    const int32_t nNewFireResist = nFireResist + 40;
                    STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                    if (nNewFireResist >= 100)
                    {
                        ++nImmunities;
                    }
                }

                if (nImmunities < 2)
                {
                    if (nLightResist < 100)
                    {
                        STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nLightResist + 40, 0);
                    }
                }
            }
            break;

        case 9:
            STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nFireResist + 75, 0);
            break;

        case 18:
            STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nColdResist + 75, 0);
            break;

        case 17:
            STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nLightResist + 75, 0);
            break;

        case 23:
            STATLIST_SetUnitStat(pUnit, STAT_POISONRESIST, nPoisonResist + 75, 0);
            break;

        case 25:
            STATLIST_SetUnitStat(pUnit, STAT_MAGICRESIST, nMagicResist + 20, 0);
            break;

        case 27:
            if (nColdResist < 75)
            {
                const int32_t nNewColdResist = nColdResist + 20;
                STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                if (nNewColdResist >= 100)
                {
                    ++nImmunities;
                }
            }

            if (nImmunities < 2)
            {
                if (nFireResist < 75)
                {
                    const int32_t nNewFireResist = nFireResist + 20;
                    STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                    if (nNewFireResist >= 100)
                    {
                        ++nImmunities;
                    }
                }

                if (nImmunities < 2 && nLightResist < 75)
                {
                    STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nLightResist + 20, 0);
                }
            }
            break;

        case 28:
            STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, nDamageResist + 50, 0);
            break;
        }
    }
}

//D2Game.0x6FC6BA70
void __fastcall ESE_MONSTERUNIQUE_UMod5_Strong(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    int64_t nDamagePercent = 0;
    int64_t nToHitPercent = 0;
    if (bUnique)
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(15);
        nDamagePercent = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(13);
        nToHitPercent = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;
    }
    else
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(14);
        nDamagePercent = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(12);
        nToHitPercent = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pDifficultyLevelsTxtRecord)
    {
        nDamagePercent = nDamagePercent * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;
        nToHitPercent = nToHitPercent * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_DAMAGEPERCENT, Clamp64To32(nDamagePercent), 0);
    STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, Clamp64To32(nToHitPercent), 0);
}

//D2Game.0x6FC6BC10
void __fastcall ESE_MONSTERUNIQUE_UMod9_FireEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const uint8_t nDifficulty = D2Clamp(pGame->nDifficulty, 0ui8, 2ui8);
    const int32_t nGameType = pGame->nGameType || pGame->dwGameType;
    const int32_t nLevel = D2Clamp(STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = &sgptDataTables->pMonLvlTxt[nLevel];
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int64_t nDamage = nGameType ? pMonLvlTxtRecord->dwLDM[nDifficulty] : pMonLvlTxtRecord->dwDM[nDifficulty];
    if (bUnique)
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 28);
        int64_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_FIREMINDAM, Clamp64To32(nDamage * nPercentage / 100), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 31);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_FIREMAXDAM, Clamp64To32(nDamage * nPercentage / 100), 0);
    }
    else
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 16);
        int64_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_FIREMINDAM, Clamp64To32(nDamage * nPercentage / 100), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 19);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_FIREMAXDAM, Clamp64To32(nDamage * nPercentage / 100), 0);
    }

    ESE_MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

//D2Game.0x6FC6BDD0
void __fastcall ESE_MONSTERUNIQUE_UMod17_LightningEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const uint8_t nDifficulty = D2Clamp(pGame->nDifficulty, 0ui8, 2ui8);
    const int32_t nGameType = pGame->nGameType || pGame->dwGameType;
    const int32_t nLevel = D2Clamp(STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = &sgptDataTables->pMonLvlTxt[nLevel];
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int64_t nDamage = nGameType ? pMonLvlTxtRecord->dwLDM[nDifficulty] : pMonLvlTxtRecord->dwDM[nDifficulty];
    if (bUnique)
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 28);
        int64_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_LIGHTMINDAM, Clamp64To32(nDamage * nPercentage / 100), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 31);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_LIGHTMAXDAM, Clamp64To32(nDamage * nPercentage / 100), 0);
    }
    else
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 16);
        int64_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_LIGHTMINDAM, Clamp64To32(nDamage * nPercentage / 100), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 19);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_LIGHTMAXDAM, Clamp64To32(nDamage * nPercentage / 100), 0);
    }

    ESE_MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

//D2Game.0x6FC6BF90
void __fastcall ESE_MONSTERUNIQUE_UMod18_ColdEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const uint8_t nDifficulty = D2Clamp(pGame->nDifficulty, 0ui8, 2ui8);
    const int32_t nGameType = pGame->nGameType || pGame->dwGameType;
    const int32_t nLevel = D2Clamp(STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = &sgptDataTables->pMonLvlTxt[nLevel];
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int32_t nDamage = nGameType ? pMonLvlTxtRecord->dwLDM[nDifficulty] : pMonLvlTxtRecord->dwDM[nDifficulty];
    if (bUnique)
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 28);
        int32_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_COLDMINDAM, Clamp64To32(nDamage * nPercentage / 100), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 31);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_COLDMAXDAM, Clamp64To32(nDamage * nPercentage / 100), 0);
    }
    else
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 16);
        int32_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_COLDMINDAM, Clamp64To32(nDamage * nPercentage / 100), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 19);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_COLDMAXDAM, Clamp64To32(nDamage * nPercentage / 100), 0);
    }

    STATLIST_AddUnitStat(pUnit, STAT_COLDLENGTH, 5 * nLevel + 100, 0);

    ESE_MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

//D2Game.0x6FC6C160
void __fastcall ESE_MONSTERUNIQUE_UMod23_PoisonEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const uint8_t nDifficulty = D2Clamp(pGame->nDifficulty, 0ui8, 2ui8);
    const int32_t nGameType = pGame->nGameType || pGame->dwGameType;
    const int32_t nLevel = D2Clamp(STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = &sgptDataTables->pMonLvlTxt[nLevel];
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int64_t nDamage = nGameType ? pMonLvlTxtRecord->dwLDM[nDifficulty] : pMonLvlTxtRecord->dwDM[nDifficulty];
    if (bUnique)
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 28);
        int64_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_POISONMINDAM, Clamp64To32(nDamage * nPercentage / 100), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 31);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_POISONMAXDAM, Clamp64To32(nDamage * nPercentage / 100), 0);
    }
    else
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 16);
        int64_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_POISONMINDAM, Clamp64To32(nDamage * nPercentage / 100), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 19);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_POISONMAXDAM, Clamp64To32(nDamage * nPercentage / 100), 0);
    }

    STATLIST_AddUnitStat(pUnit, STAT_POISONLENGTH, 2 * (5 * nLevel + 150), 0);

    ESE_MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

//D2Game.0x6FC6C340
void __fastcall ESE_MONSTERUNIQUE_UMod25_ManaSteal(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const uint8_t nDifficulty = D2Clamp(pGame->nDifficulty, 0ui8, 2ui8);
    const int32_t nGameType = pGame->nGameType || pGame->dwGameType;
    const int32_t nLevel = D2Clamp(STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = &sgptDataTables->pMonLvlTxt[nLevel];
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int64_t nDamage = nGameType ? pMonLvlTxtRecord->dwLDM[nDifficulty] : pMonLvlTxtRecord->dwDM[nDifficulty];
    if (bUnique)
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 28);
        int64_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_MANADRAINMINDAM, Clamp64To32((nDamage * nPercentage / 100) << 8), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 31);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_MANADRAINMAXDAM, Clamp64To32((nDamage * nPercentage / 100) << 8), 0);
    }
    else
    {
        D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 16);
        int64_t nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_MANADRAINMINDAM, Clamp64To32((nDamage * nPercentage / 100) << 8), 0);

        pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(nDifficulty + 19);
        nPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

        STATLIST_AddUnitStat(pUnit, STAT_MANADRAINMAXDAM, Clamp64To32((nDamage * nPercentage / 100) << 8), 0);
    }

    ESE_MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

//D2Game.0x6FC6C740
void __fastcall ESE_MONSTERUNIQUE_CastCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    const int32_t nX = CLIENTS_GetUnitX(pUnit);
    const int32_t nY = CLIENTS_GetUnitY(pUnit);

    D2UnitStrc* pMissile = ESE_sub_6FD11420(pGame, MISSILE_MONSTERCORPSEEXPLODE, pUnit, 0, 1, 0, 0, nX, nY, 1);
    if (!pMissile)
    {
        return;
    }

    D2MonStatsInitStrc monStatsInit = {};
    DATATBLS_CalculateMonsterStatsByLevel(pUnit->dwClassId, pGame->nGameType || pGame->dwGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, &monStatsInit);

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (!pDifficultyLevelsTxtRecord)
    {
        return;
    }

    const int64_t nMaxDamage = ESE_DATATBLS_ApplyRatio(monStatsInit.nMaxHP, pDifficultyLevelsTxtRecord->dwMonsterCEDmgPercent, 100);
    const int64_t nMinDamage = ESE_DATATBLS_ApplyRatio(nMaxDamage, 60, 100);
    const int64_t nDamage = ESE_ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage);

    ESE_D2DamageStrc damage = {};
    damage.dwPhysDamage = std::max<int64_t>(INT64_MAX>>6, (nMinDamage + nDamage)) << 6;
    damage.dwFireDamage = damage.dwPhysDamage;
    ESE_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, pGame->nDifficulty + 4, &damage, 0, 0, nullptr, 0x581u);
}

//D2Game.0x6FC6C9E0
void __fastcall ESE_MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    const int32_t nX = CLIENTS_GetUnitX(pUnit);
    const int32_t nY = CLIENTS_GetUnitY(pUnit);

    D2UnitStrc* pMissile = ESE_sub_6FD11420(pGame, MISSILE_MONSTERCORPSEEXPLODE, pUnit, 0, 1, 0, 0, nX, nY, 1);
    if (!pMissile)
    {
        return;
    }

    ESE_D2DamageStrc damage = {};
    damage.dwPhysDamage = 0x6400u;
    damage.dwFireDamage = 0x6400u;
    ESE_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, 6, &damage, 0, 0, nullptr, 0x583);
}

//D2Game.0x6FC6CF10
void __fastcall ESE_sub_6FC6CF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    int64_t nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
    int64_t nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    if (nMaxDamage > 0 && (!pUnit || pUnit->dwClassId != MONSTER_ROGUEHIRE))
    {
        nMinDamage += (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0) - 1;
        nMaxDamage += (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0) - 1;

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, std::max<int64_t>(nMinDamage, 0), 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, std::max<int64_t>(nMaxDamage, 0), 0);
    }
}

//D2Game.0x6FC6CF90
void __fastcall ESE_sub_6FC6CF90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    int64_t nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
    int64_t nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    if (nMaxDamage <= 0)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || pOwner->dwClassId != MONSTER_ROGUEHIRE)
    {
        return;
    }

    nMinDamage += ((int64_t)STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MINDAMAGE, 0) << 8) - 256;
    nMaxDamage += ((int64_t)STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MAXDAMAGE, 0) << 8) - 256;

    STATLIST_SetUnitStat(pUnit, STAT_MINDAMAGE, Clamp64To32(std::max<int64_t>(nMinDamage, 0)), 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXDAMAGE, Clamp64To32(std::max<int64_t>(nMaxDamage, 0)), 0);
}

//D2Game.0x6FC6D1C0
void __fastcall ESE_MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    constexpr int32_t dword_6FD28C38[5][3] =
    {
        { STAT_FIREMINDAM, STAT_FIREMAXDAM, -1 },
        { STAT_LIGHTMINDAM, STAT_LIGHTMAXDAM, -1 },
        { STAT_MAGICMINDAM, STAT_MAGICMAXDAM, -1 },
        { STAT_COLDMINDAM, STAT_COLDMAXDAM, STAT_COLDLENGTH },
        { STAT_POISONMINDAM, STAT_POISONMAXDAM, STAT_POISONLENGTH },
    };

    if (!bUnique)
    {
        return;
    }

    const uint32_t nRand = ITEMS_RollRandomNumber(&pUnit->pSeed) % 5;
    const int32_t nMinDamageStatId = dword_6FD28C38[nRand][0];
    const int32_t nMaxDamageStatId = dword_6FD28C38[nRand][1];
    const int32_t nLengthStatId = dword_6FD28C38[nRand][2];

    if (pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = ESE_SKILLS_GetMissilesTxtRecord(pUnit->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->dwMissileFlags & gdwBitMasks[MISSILESFLAGINDEX_NOUNIQUEMOD])
        {
            return;
        }
    }

    const uint8_t nDifficulty = D2Clamp(pGame->nDifficulty, 0ui8, 2ui8);
    const int32_t nGameType = pGame->nGameType || pGame->dwGameType;
    const int32_t nLevel = D2Clamp(STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = &sgptDataTables->pMonLvlTxt[nLevel];
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int64_t nDamage = nGameType ? pMonLvlTxtRecord->dwLDM[nDifficulty] : pMonLvlTxtRecord->dwDM[nDifficulty];

    D2MonUModTxt* pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(28);
    const int64_t nMinPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

    pMonUModTxtRecord = MONSTERUNIQUE_GetMonUModTxtRecord(31);
    const int64_t nMaxPercentage = pMonUModTxtRecord ? pMonUModTxtRecord->dwConstants : 0;

    D2StatListStrc* pStatList = nullptr;

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStatIfListIsValid(pStatList, nMinDamageStatId, Clamp64To32(nDamage * nMinPercentage / 100), 0);
        STATLIST_SetStatIfListIsValid(pStatList, nMaxDamageStatId, Clamp64To32(nDamage * nMaxPercentage / 100), 0);
    }
    else
    {
        STATLIST_SetUnitStat(pUnit, nMinDamageStatId, Clamp64To32(nDamage * nMinPercentage / 100), 0);
        STATLIST_SetUnitStat(pUnit, nMaxDamageStatId, Clamp64To32(nDamage * nMaxPercentage / 100), 0);
    }

    if (nLengthStatId == -1)
    {
        return;
    }

    const int32_t nLength = STATLIST_UnitGetStatValue(pUnit, nLengthStatId, 0) + 40;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        STATLIST_SetStatIfListIsValid(pStatList, nLengthStatId, nLength, 0);
    }
    else
    {
        STATLIST_SetUnitStat(pUnit, nLengthStatId, nLength, 0);
    }
}

//D2Game.0x6FC6E240
void __fastcall ESE_sub_6FC6E240(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    int64_t randomFiredamage = ESE_ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, (int64_t)pMonStatsTxtRecord->nElMaxD[0][0] - (int64_t)pMonStatsTxtRecord->nElMinD[0][0]);

    ESE_D2DamageStrc damage = {};
    damage.dwFireDamage = (randomFiredamage + (int64_t)pMonStatsTxtRecord->nElMinD[0][0]) << 8;

    ESE_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pUnit, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), (int64_t)pMonStatsTxtRecord->wAiParam[2][pGame->nDifficulty] * (int64_t)STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), &damage, 0, 0, nullptr, 0);
}

//D2Game.0x6FC6E410
void __fastcall ESE_MONSTERUNIQUE_CastSuicideExplodeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    if (!pUnit)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);

    int32_t nGameType = 0;
    if (pGame->nGameType || pGame->dwGameType)
    {
        nGameType = 1;
    }

    D2MonStatsInitStrc monStatsInit = {};
    DATATBLS_CalculateMonsterStatsByLevel(pUnit->dwClassId, nGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 8, &monStatsInit);

    ESE_D2DamageStrc damage = {};

    damage.wResultFlags |= 8u;

    const int64_t nDamage = (ESE_ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, (int64_t)monStatsInit.nA1MaxD - (int64_t)monStatsInit.nA1MinD) + (int64_t)monStatsInit.nA1MinD) << 8;
    damage.dwPhysDamage = nDamage;

    const int32_t nX = CLIENTS_GetUnitX(pUnit);
    const int32_t nY = CLIENTS_GetUnitY(pUnit);

    const int64_t nColdLength = pMonStatsTxtRecord->wAiParam[0][pGame->nDifficulty];
    int32_t nMissileId = 0;
    if (nColdLength == 1)
    {
        damage.dwFireDamage = nDamage;

        nMissileId = MISSILE_SUICIDEFIREEXPLODE;
    }
    else if (nColdLength < 2)
    {
        nMissileId = MISSILE_SUICIDECORPSEEXPLODE;
    }
    else
    {
        damage.dwColdLen = nColdLength;
        damage.dwColdDamage = nDamage;
        nMissileId = MISSILE_SUICIDEICEEXPLODE;
    }

    D2UnitStrc* pMissile = ESE_sub_6FD11420(pGame, nMissileId, pUnit, 0, 1, 0, 0, nX, nY, 1);
    if (pMissile)
    {
        ESE_SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, pMonStatsTxtRecord->wAiParam[3][pGame->nDifficulty], &damage, 0, 0, nullptr, 0x581);
    }
}
