#include <D2Client/CharScreen_ESE.h>
#include <D2Common/D2Skills_ESE.h>
#include <D2Common/Units/Missile_ESE.h>
#include "LibESE.h"
#include <D2Combat.h>
#include "Font.h"
#include <cinttypes>
#include <D2States.h>

void ESE_Helper_DrawTextCentered(wchar_t* buff, int32_t offsetA, int32_t offsetB, int32_t offsetC, int32_t nColor);

void __fastcall ESE_PrintRangeString_6FB0B140(wchar_t* pText, int64_t minDamage, int64_t maxDamage, int isAdditonRange, int allowThousandsSuffix);
void __fastcall ESE_sub_6FB0AC10(Unicode* pTextA, Unicode* pTextB, int offsetA, int offsetB, int offsetC, int nColorA, int nColorB);
void __fastcall ESE_sub_6FB0B0F0(struct Unicode* pText, int64_t damage, int isAdditonRange);
void __fastcall ESE_sub_6FB0B250(struct Unicode* pText, int64_t minDamage, int64_t maxDamage, int isAdditonRange);

typedef void(__fastcall* DamageCallback7D0_t)(D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, int32_t* pColor, int64_t additionalDamagePct, int64_t additionalDamage, D2SkillStrc* pSkill, int64_t nSrcDamOverride, D2UnitStrc* pItem);


void ESE_Helper_DrawTextCentered(wchar_t* buff, int32_t offsetA, int32_t offsetB, int32_t offsetC, int32_t nColor)
{
    int32_t pWidth = 0;
    int32_t pHeight = 0;
    int32_t textOffsetY = 0;

    D2Win_10131_GetTextDimensions((Unicode*)&buff[0], &pWidth, &pHeight);

    int32_t widthMod = (11 * pWidth) / 7;
    if (widthMod <= offsetC - offsetA)
    {
        D2Win_10127_SetFont(D2FONT_FONT16);
        textOffsetY = offsetB;
    }
    else
    {
        D2Win_10127_SetFont(D2FONT_FONT6);
        textOffsetY = (offsetB - 1);
    }

    D2Client_DrawTextCentered_6FACFCD0(
        *D2Client_pDWORD_6FBBA748 + offsetA,
        *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 + textOffsetY - 0x1e0,
        *D2Client_pDWORD_6FBBA748 + offsetC,
        (Unicode*)&buff[0],
        nColor
    );
}

void __fastcall ESE_sub_6FB0B2C0(D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, int32_t* pColor, int64_t additionalDamagePct, int64_t additionalDamage, D2SkillStrc* pSkill, int64_t nSrcDamOverride, D2UnitStrc* item, int32_t unknown7)
{
    if (pSkill == nullptr)
    {
        return;
    }

    auto skillTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (skillTxtRecord == nullptr)
    {
        return;
    }

    auto pInventory = pUnit->pInventory;
    if (pInventory == nullptr)
    {
        return;
    }

    if (item == nullptr)
    {
        item = INVENTORY_GetLeftHandWeapon(pInventory);
    }

    int64_t minDamage = 0;
    int64_t maxDamage = 0;

    if (item != 0)
    {
        DATATBLS_GetItemsTxtRecord(item->dwClassId);
        if (unknown7)
        {
            minDamage = D2Common_11248(pUnit, item, STAT_MINDAMAGE);
            maxDamage = D2Common_11248(pUnit, item, STAT_MAXDAMAGE);
        }
        else if (INVENTORY_GetWieldType(pUnit, pInventory) == 2)
        {
            minDamage = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
            maxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0);
        }
        else
        {
            minDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
            maxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
        }
    }
    else
    {
        minDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0) + 1;
        maxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0) + 2;
    }


    int64_t nSrcDam = nSrcDamOverride;
    if (!nSrcDamOverride)
    {
        nSrcDam = skillTxtRecord->nSrcDam;
    }

    if (nSrcDam != 128)
    {
        minDamage = nSrcDam * minDamage / 128;
        maxDamage = nSrcDam * maxDamage / 128;
    }
    if (nSrcDam)
    {
        if (minDamage < 1)
        {
            minDamage = 1;
        }
        *pMinDamage += minDamage;

        if (maxDamage < 2)
        {
            maxDamage = 2;
        }
        *pMaxDamage += maxDamage;
    }

    int64_t damagePercent = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0) + additionalDamagePct;
    int64_t masteryBonus = SKILLS_GetWeaponMasteryBonus(pUnit, item, pSkill, 1) + damagePercent;
    int64_t minDamagePercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0);
    int64_t maxDamagePercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);

    if ((skillTxtRecord->dwFlags[0] & gdwBitMasks[12]) != 0)
    {
        auto masteryBonusFromAura = D2Client_sub_6FB0B580();
        if (masteryBonusFromAura)
        {
            masteryBonus += masteryBonusFromAura;
            *pColor = 3;
        }
    }

    int64_t normalDamage = 0;
    if (item)
    {
        int64_t strengthBonus = ITEMS_GetStrengthBonus(item);
        if (strengthBonus)
        {
            masteryBonus += strengthBonus * STATLIST_UnitGetStatValue(pUnit, 0, 0) / 100;
        }

        int64_t dexBonus = ITEMS_GetDexBonus(item);
        if (dexBonus)
        {
            masteryBonus += dexBonus * STATLIST_UnitGetStatValue(pUnit, 2, 0) / 100;
        }

        normalDamage = STATLIST_UnitGetItemStatOrSkillStatValue(item, STAT_ITEM_NORMALDAMAGE, 0);
    }
    else
    {
        masteryBonus += STATLIST_UnitGetStatValue(pUnit, 0, 0);
    }

    if (STATES_CheckStateMaskDamBlueOnUnit(pUnit))
    {
        *pColor = 3;
    }

    if (STATES_CheckStateMaskDamRedOnUnit(pUnit))
    {
        *pColor = 1;
    }

    if (masteryBonus <= -90)
    {
        masteryBonus = -90;
    }

    *pMinDamage = additionalDamage + normalDamage + *pMinDamage * (minDamagePercent + masteryBonus + 100) / 100;
    *pMaxDamage = additionalDamage + normalDamage + *pMaxDamage * (maxDamagePercent + masteryBonus + 100) / 100;
}

void __fastcall ESE_sub_6FB0BB10(D2UnitStrc* pUnit, int64_t* pMinElemDamage, int64_t* pMaxElemDamage, int32_t* pColor)
{
    if (sgptDataTables->nProgressiveStates <= 0)
    {
        return;
    }

    for (size_t progressiveStateIndex = 0; progressiveStateIndex < sgptDataTables->nProgressiveStates; progressiveStateIndex++)
    {
        if (!STATES_CheckState(pUnit, sgptDataTables->pProgressiveStates[progressiveStateIndex]))
        {
            continue;
        }

        D2StatListStrc* progressiveState = D2Common_10480_STATLIST_GetStatListFromUnitAndState(pUnit, sgptDataTables->pProgressiveStates[progressiveStateIndex]);
        if (!progressiveState)
        {
            continue;
        }

        int32_t nSkillId = D2Common_10466_STATLIST_GetStatValue(progressiveState, STAT_MODIFIERLIST_SKILL, 0);
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            continue;
        }

        D2SkillsTxt* modiferListSkillTxt = &sgptDataTables->pSkillsTxt[nSkillId];
        if (modiferListSkillTxt == nullptr)
        {
            continue;
        }

        int32_t nSkillLevel = D2Common_10466_STATLIST_GetStatValue(progressiveState, STAT_MODIFIERLIST_LEVEL, 0);
        if (nSkillLevel <= 0)
        {
            continue;
        }

        int16_t auraStat = modiferListSkillTxt->wAuraStat[0];
        if (auraStat < 0 || auraStat >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            continue;
        }

        int32_t auraStatValue = D2Common_10466_STATLIST_GetStatValue(progressiveState, auraStat, 0);
        if (auraStatValue <= 0)
        {
            continue;
        }

        if (nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            *pMinElemDamage += ESE_SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
            *pMaxElemDamage += ESE_SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
            continue;
        }

        D2SkillsTxt* pSkillTxt = &sgptDataTables->pSkillsTxt[nSkillId];
        if (pSkillTxt == nullptr || pSkillTxt->wSkillDesc < 0 || pSkillTxt->wSkillDesc >= sgptDataTables->nSkillDescTxtRecordCount)
        {
            *pMinElemDamage += ESE_SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
            *pMaxElemDamage += ESE_SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
            continue;
        }

        D2SkillDescTxt* pSkillDescTxt = &sgptDataTables->pSkillDescTxt[pSkillTxt->wSkillDesc];
        if (pSkillDescTxt == nullptr)
        {
            *pMinElemDamage += ESE_SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
            *pMaxElemDamage += ESE_SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
            continue;
        }

        if (auraStatValue <= 1)
        {
            auraStatValue = 1;
        }
        else if (auraStatValue >= 3)
        {
            auraStatValue = 3;
        }

        *pMinElemDamage += (int64_t)SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwProgDmgMin[auraStatValue - 1], nSkillId, nSkillLevel);
        *pMaxElemDamage += (int64_t)SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwProgDmgMax[auraStatValue - 1], nSkillId, nSkillLevel);

        uint8_t nElement = pSkillDescTxt->nPrgDamElem[auraStatValue - 1];
        if (nElement > 0 && nElement < 13)
        {
            switch (nElement)
            {
            case ELEMTYPE_FIRE:
                *pColor = 1;
                break;
            case ELEMTYPE_LTNG:
                *pColor = 9;
                break;
            case ELEMTYPE_MAGIC:
            case ELEMTYPE_COLD:
                *pColor = 3;
                break;
            case ELEMTYPE_POIS:
                *pColor = 2;
                break;
            default:
                *pColor = 0;
                break;
            }
        }
    }
}

struct StatList6F0
{
    int32_t minDamStatId;
    int32_t maxDamStatId;
    int32_t masteryStatId;
};

void __fastcall ESE_sub_6FB0B6F0(D2UnitStrc* pUnit, int64_t* pMinElemDamage, int64_t* pMaxElemDamage, int32_t* pColor, D2UnitStrc* pItem, D2SkillStrc* pSkill)
{
    static StatList6F0 stats_6FB6FB6C[] = {
        {STAT_FIREMINDAM, STAT_FIREMAXDAM, STAT_PASSIVE_FIRE_MASTERY},
        {STAT_LIGHTMINDAM, STAT_LIGHTMAXDAM, STAT_PASSIVE_LTNG_MASTERY},
        {STAT_COLDMINDAM, STAT_COLDMAXDAM, STAT_PASSIVE_COLD_MASTERY},
        {STAT_MAGICMINDAM, STAT_MAGICMAXDAM, -1},
    };
    static int32_t statColors_6FB6FB9C[] = {
        1, 9, 3, 3
    };

    for (size_t i = 0; i < std::size(stats_6FB6FB6C); i++)
    {
        int64_t minElemDam = STATLIST_UnitGetStatValue(pUnit, stats_6FB6FB6C[i].minDamStatId, 0);
        int64_t maxElemDam = STATLIST_UnitGetStatValue(pUnit, stats_6FB6FB6C[i].maxDamStatId, 0);
        if (stats_6FB6FB6C[i].masteryStatId != -1)
        {
            int64_t elemMasteryPct = STATLIST_UnitGetStatValue(pUnit, stats_6FB6FB6C[i].masteryStatId, 0);
            if (elemMasteryPct)
            {
                minElemDam += ESE_DATATBLS_ApplyRatio(minElemDam, elemMasteryPct, 100);
                maxElemDam += ESE_DATATBLS_ApplyRatio(maxElemDam, elemMasteryPct, 100);
            }
        }

        if (minElemDam >= maxElemDam)
        {
            minElemDam = maxElemDam;
        }

        *pMinElemDamage += minElemDam;
        *pMaxElemDamage += maxElemDam;
        if (minElemDam || maxElemDam)
        {
            *pColor = statColors_6FB6FB9C[i];
        }
    }

    int64_t minPoisonDam = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
    int64_t maxPoisonDam = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);
    if (maxPoisonDam)
    {
        int64_t poisonMasteryPct = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_POIS_MASTERY, 0);
        if (poisonMasteryPct)
        {
            minPoisonDam += ESE_DATATBLS_ApplyRatio(minPoisonDam, poisonMasteryPct, 100);
            maxPoisonDam += ESE_DATATBLS_ApplyRatio(maxPoisonDam, poisonMasteryPct, 100);
        }

        int64_t poisonOverrideLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
        if (poisonOverrideLength <= 0)
        {
            int64_t poisonCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            if (poisonCount <= 1)
            {
                poisonCount = 1;
            }

            poisonOverrideLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / poisonCount;
        }

        *pColor = 2;
        *pMinElemDamage += (minPoisonDam * poisonOverrideLength) >> 8;
        *pMaxElemDamage += (maxPoisonDam * poisonOverrideLength) >> 8;
    }

    if (*pMaxElemDamage > 0)
    {
        if (*pMinElemDamage < 1)
        {
            *pMinElemDamage = 1;
        }

        if ((*pMinElemDamage + 1) > *pMaxElemDamage)
        {
            *pMaxElemDamage = *pMinElemDamage + 1;
        }
    }

    if (pSkill)
    {
        D2SkillsTxt* skillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (skillsTxt != nullptr)
        {
            if ((skillsTxt->dwFlags[0] & gdwBitMasks[12]) != 0)
            {
                ESE_sub_6FB0BB10(pUnit, pMinElemDamage, pMaxElemDamage, pColor);
            }
        }
    }

    if (STATES_CheckStateMaskDamBlueOnUnit(pUnit))
    {
        *pColor = 3;
    }
    if (STATES_CheckStateMaskDamRedOnUnit(pUnit))
    {
        *pColor = 1;
    }
}

void __fastcall ESE_sub_6FB0C3A0(D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, int32_t* pColor, int64_t additionalDamagePct, int64_t additionalDamage, D2SkillStrc* pSkill, int64_t nSrcDamOverride, D2UnitStrc* pItem)
{
    ESE_sub_6FB0B2C0(pUnit, pMinDamage, pMaxDamage, pColor, additionalDamagePct, additionalDamage, pSkill, nSrcDamOverride, pItem, 0);
    ESE_sub_6FB0B6F0(pUnit, pMinDamage, pMaxDamage, pColor, pItem, pSkill);
}

int __fastcall ESE_sub_6FB0A7D0(D2UnitStrc* pUnit, int64_t* pMinDamageA, int64_t* pMaxDamageA, int32_t* pColorA, int64_t* pMinDamageB, int64_t* pMaxDamageB, int32_t* pColorB, D2SkillStrc* pSkill, DamageCallback7D0_t callback, int ddamCalc1, int ddamCalc2)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    bool bCanDualWield = UNITS_CanDualWield(pUnit);
    if (!bCanDualWield)
    {
        return 0;
    }

    D2UnitStrc* rightArmWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (!D2Common_10839_ITEMS_CanBeEquipped(rightArmWeapon) || D2Common_10731_ITEMS_CheckItemTypeId(rightArmWeapon, ITEMTYPE_MISSILE_POTION))
    {
        rightArmWeapon = nullptr;
    }

    D2UnitStrc* leftArmWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (!D2Common_10839_ITEMS_CanBeEquipped(leftArmWeapon) || D2Common_10731_ITEMS_CheckItemTypeId(leftArmWeapon, ITEMTYPE_MISSILE_POTION))
    {
        leftArmWeapon = nullptr;
    }

    if (rightArmWeapon && leftArmWeapon)
    {
        D2UnitStrc* v16 = D2Client_sub_6FB0A950(pUnit);
        if (v16)
        {
            callback(pUnit, pMinDamageB, pMaxDamageB, pColorB, ddamCalc1, ddamCalc2, pSkill, 0, v16);
        }
        else
        {
            *pMinDamageB = 0;
            *pMaxDamageB = 0;
        }

        D2UnitStrc* v17 = D2Client_sub_6FB0AA00(pUnit);
        if (v17)
        {
            callback(pUnit, pMinDamageA, pMaxDamageA, pColorA, ddamCalc1, ddamCalc2, pSkill, 0, v17);
        }
        else
        {
            *pMinDamageA = 0;
            *pMaxDamageA = 0;
        }

        return 1;
    }
    else
    {
        D2UnitStrc* leftArmWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
        if (leftArmWeapon && ITEMS_CanBeEquipped(leftArmWeapon))
        {
            STATLIST_MergeStatLists(pUnit, leftArmWeapon, 1);
        }

        callback(pUnit, pMinDamageA, pMaxDamageA, pColorA, ddamCalc1, ddamCalc2, pSkill, 0, 0);
        return 1;
    }
}

void __fastcall ESE_sub_6FB0C840(D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillLevel, int64_t* pMinElemDamage, int64_t* pMaxElemDamage, int* pColor)
{
    int64_t minElemDamage = 0;
    int64_t maxElemDamage = 0;

    if (pSkillsTxtRecord->nEType == 5)
    {
        int64_t nSkillLevela = ESE_SKILLS_GetElementalLength(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
        *pColor = 2;

        minElemDamage = (ESE_SKILLS_GetMinElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1) * nSkillLevela) >> 8;
        maxElemDamage = (ESE_SKILLS_GetMaxElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1) * nSkillLevela) >> 8;
    }
    else
    {
        minElemDamage = ESE_SKILLS_GetMinElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1) >> 8;
        maxElemDamage = ESE_SKILLS_GetMaxElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1) >> 8;
    }

    if (pColor)
    {
        switch (pSkillsTxtRecord->nEType)
        {
        case ELEMTYPE_FIRE:
            *pColor = 1;
            break;
        case ELEMTYPE_LTNG:
            *pColor = 9;
            break;
        case ELEMTYPE_MAGIC:
        case ELEMTYPE_COLD:
            *pColor = 3;
            break;
        case ELEMTYPE_POIS:
            *pColor = 2;
            break;
        }
    }

    *pMinElemDamage += minElemDamage;
    *pMaxElemDamage += maxElemDamage;
}

void __fastcall ESE_sub_6FB0C400(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, DamageCallback7D0_t callback, int32_t ddamCalc1, int32_t ddamCalc2, int32_t offsetA, int32_t offsetB, int32_t offsetC, int32_t flag)
{
    wchar_t buffB[64] = {0};
    wchar_t buffA[64] = {0};

    if (pSkill == nullptr || pSkillsTxtRecord == nullptr || callback == nullptr)
    {
        return;
    }

    int64_t nMinElemDamage = 0;
    int64_t nMaxElemDamage = 0;
    int32_t nColor = 0;

    if (!flag)
    {
        ESE_sub_6FB0C840(pUnit, pSkillsTxtRecord, nSkillLevel, &nMinElemDamage, &nMaxElemDamage, &nColor);
    }

    int64_t minDamageA = 0;
    int64_t maxDamageA = 0;
    int64_t minDamageB = 0;
    int64_t maxDamageB = 0;
    int32_t nColorA = 0;
    int32_t nColorB = 0;

    ESE_sub_6FB0A7D0(
        pUnit,
        &minDamageA,
        &maxDamageA,
        &nColorA,
        &minDamageB,
        &maxDamageB,
        &nColorB,
        pSkill,
        callback,
        ddamCalc1,
        ddamCalc2);

    if (minDamageA && maxDamageA)
    {
        minDamageA = pSkillsTxtRecord->nSrcDam * minDamageA / 128 + nMinElemDamage;
        maxDamageA = nMaxElemDamage + pSkillsTxtRecord->nSrcDam * maxDamageA / 128;
    }

    if (minDamageB && maxDamageB)
    {
        minDamageB = pSkillsTxtRecord->nSrcDam * minDamageB / 128 + nMinElemDamage;
        maxDamageB = nMaxElemDamage + pSkillsTxtRecord->nSrcDam * maxDamageB / 128;
    }

    if (!minDamageA && !maxDamageA)
    {
        if (minDamageB >= maxDamageB)
        {
            maxDamageB = minDamageB + 1;
        }

        if (minDamageB == maxDamageB)
        {
            ESE_sub_6FB0B0F0((Unicode*)&buffA[0], minDamageB, 0);
        }
        else
        {
            ESE_PrintRangeString_6FB0B140(buffA, minDamageB, maxDamageB, 0, 1);
        }

        ESE_Helper_DrawTextCentered(buffA, offsetA, offsetB, offsetC, nColorB);
        return;
    }

    if (!minDamageB && !maxDamageB)
    {
        if (minDamageA >= maxDamageA)
        {
            maxDamageA = minDamageA + 1;
        }

        ESE_sub_6FB0B250((Unicode*)&buffA[0], minDamageA, maxDamageA, 0);

        ESE_Helper_DrawTextCentered(buffA, offsetA, offsetB, offsetC, nColorA);
    }

    if (minDamageA == maxDamageA)
    {
        swprintf(buffA, L"%lld", minDamageA);
    }
    else
    {
        ESE_PrintRangeString_6FB0B140(buffA, minDamageA, maxDamageA, 0, 1);
    }

    if (minDamageB == maxDamageB)
    {
        swprintf(buffB, L"%lld", minDamageB);
    }
    else
    {
        ESE_PrintRangeString_6FB0B140(buffB, minDamageB, maxDamageB, 0, 1);
    }

    ESE_sub_6FB0AC10((Unicode*)&buffA[0], (Unicode*)&buffB[0], offsetA, offsetB, offsetC, nColorA, nColorB);
}

void __fastcall ESE_sub_6FB0AC10(Unicode* pTextA, Unicode* pTextB, int offsetA, int offsetB, int offsetC, int nColorA, int nColorB)
{
    static bool hasLoadedLanguageOffset = false;
    static int32_t languageOffset = -7;

    D2Win_10127_SetFont(D2FONT_FONT6);
    if (!hasLoadedLanguageOffset)
    {
        int32_t language = STRTABLE_GetLanguage();
        if (language < 6 || language > 9)
        {
            languageOffset = -6;
        }
    }

    D2Client_DrawTextCentered_6FACFCD0(
        *D2Client_pDWORD_6FBBA748 + offsetA,
        languageOffset + *D2Client_pDWORD_6FB740F0 + *D2Client_pDWORD_6FBBA74C + offsetB - 480,
        *D2Client_pDWORD_6FBBA748 + offsetC,
        pTextA,
        nColorA);

    D2Client_DrawTextCentered_6FACFCD0(
        *D2Client_pDWORD_6FBBA748 + offsetA,
        *D2Client_pDWORD_6FB740F0 + *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB8CCF8 + offsetB - 480,
        *D2Client_pDWORD_6FBBA748 + offsetC,
        pTextB,
        nColorB);
}

void __fastcall ESE_sub_6FB0B0F0(struct Unicode* pText, int64_t damage, int isAdditonRange)
{
    swprintf((wchar_t*)&pText[0], L"%s%lld", (isAdditonRange && damage >= 0) ? L"+" : L"", damage);
}

void __fastcall ESE_sub_6FB0B250(struct Unicode* pText, int64_t minDamage, int64_t maxDamage, int isAdditonRange)
{
    if (minDamage == maxDamage)
    {
        swprintf((wchar_t*)&pText[0], L"%s%lld", (isAdditonRange && minDamage >= 0) ? L"+" : L"", minDamage);
    }
    else
    {
        ESE_PrintRangeString_6FB0B140((wchar_t*)&pText[0], minDamage, maxDamage, isAdditonRange, 1);
    }
}

void __fastcall ESE_sub_6FB0BD60(const D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, uint8_t elemType)
{
    switch (elemType - 1)
    {
    case ELEMTYPE_FIRE:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_FIREMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_FIREMAXDAM, 0);
        break;
    case ELEMTYPE_LTNG:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTMAXDAM, 0);
        break;
    case ELEMTYPE_MAGIC:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_MAGICMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_MAGICMAXDAM, 0);
        break;
    case ELEMTYPE_COLD:
    case ELEMTYPE_FREEZE:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_COLDMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_COLDMAXDAM, 0);
        break;
    case ELEMTYPE_POIS:
        int64_t poisonOverrideLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
        if (poisonOverrideLength <= 0)
        {
            int64_t poisonCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            if (poisonCount <= 1)
            {
                poisonCount = 1;
            }

            poisonOverrideLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / poisonCount;
        }

        int64_t minPoisonDamage = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
        int64_t maxPoisonDamage = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);

        *pMinDamage += (poisonOverrideLength * minPoisonDamage) >> 8;
        *pMaxDamage += (poisonOverrideLength * maxPoisonDamage) >> 8;
        break;
    }
}

void __fastcall ESE_PrintRangeString_6FB0B140(wchar_t* pText, int64_t minDamage, int64_t maxDamage, int isAdditonRange, int allowThousandsSuffix)
{
    const wchar_t* prefix = isAdditonRange ? L"+" : L"";
    double dMinDamage = 0.0;
    double dMaxDamage = 0.0;
    wchar_t minDamageUnit = L' ';
    wchar_t maxDamageUnit = L' ';

    if (allowThousandsSuffix)
    {
        if (minDamage >= 1000000)
        {
            minDamageUnit = L'M';
            dMinDamage = minDamage / 1000000.0;
        }
        else if (minDamage >= 10000)
        {
            minDamageUnit = L'K';
            dMinDamage = minDamage / 1000.0;
        }

        if (maxDamage >= 1000000)
        {
            maxDamageUnit = L'M';
            dMaxDamage = maxDamage / 1000000.0;
        }
        else if (maxDamage >= 10000)
        {
            maxDamageUnit = L'K';
            dMaxDamage = maxDamage / 1000.0;
        }
    }

    if (minDamageUnit != L' ' && maxDamageUnit != L' ')
    {
        swprintf(pText, L"%s%.1f%c-%.1f%c", prefix, dMinDamage, minDamageUnit, dMaxDamage, maxDamageUnit);
    }
    else if (minDamageUnit != L' ')
    {
        swprintf(pText, L"%s%.1f%c-%lld", prefix, dMinDamage, minDamageUnit, maxDamage);
    }
    else if (maxDamageUnit != L' ')
    {
        swprintf(pText, L"%s%lld-%.1f%c", prefix, minDamage, dMaxDamage, maxDamageUnit);
    }
    else
    {
        swprintf(pText, L"%s%lld-%lld", prefix, minDamage, maxDamage);
    }
}

void __fastcall ESE_CHARSCREEN_DrawDescDam8(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    wchar_t buff[32] = { 0 };

    if (pSkill == nullptr || pSkillsTxtRecord == nullptr)
    {
        return;
    }

    uint16_t pSkillsTxtIndex = pSkillsTxtRecord->nSkillId;
    if (pSkillsTxtIndex < 0 || pSkillsTxtIndex >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return;
    }

    D2SkillsTxt* skillTxt = &sgptDataTables->pSkillsTxt[pSkillsTxtIndex];
    if (skillTxt == nullptr)
    {
        return;
    }

    uint16_t pSkillsDescTxtIndex = skillTxt->wSkillDesc;
    if (pSkillsDescTxtIndex < 0 || pSkillsDescTxtIndex >= sgptDataTables->nSkillDescTxtRecordCount)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = &sgptDataTables->pSkillDescTxt[pSkillsDescTxtIndex];
    if (pSkillDescTxt == nullptr)
    {
        return;
    }

    int64_t minElemDamage = ESE_SKILLS_GetMinElemDamage(pUnit, pSkillsTxtIndex, nSkillLevel, 1);
    int64_t maxElemDamage = ESE_SKILLS_GetMaxElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
    int8_t nColor = 0;

    switch (pSkillsTxtRecord->nEType)
    {
    case ELEMTYPE_FIRE:
        nColor = 1;
        break;
    case ELEMTYPE_LTNG:
        nColor = 9;
        break;
    case ELEMTYPE_MAGIC:
    case ELEMTYPE_COLD:
        nColor = 3;
        break;
    case ELEMTYPE_POIS:
        nColor = 2;
        break;
    }

    int32_t skillId = SKILLS_GetSkillIdFromSkill(pSkill, __FILE__, __LINE__);
    int64_t ddamCalc1 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], skillId, nSkillLevel);
    if (!ddamCalc1)
    {
        ddamCalc1 = 1;
    }

    int32_t skillIdAgain = SKILLS_GetSkillIdFromSkill(pSkill, __FILE__, __LINE__);
    int64_t ddamCalc2 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], skillIdAgain, nSkillLevel);
    if (!ddamCalc2)
    {
        ddamCalc2 = 1;
    }

    int64_t nMinRange = (25ll * minElemDamage * ddamCalc1 / ddamCalc2) >> 8;
    int64_t nMaxRange = (25ll * maxElemDamage * ddamCalc1 / ddamCalc2) >> 8;
    if (nMinRange >= nMaxRange)
    {
        nMaxRange = nMinRange + 1;
    }

    if (nMinRange == nMaxRange)
    {
        swprintf_s(buff, L"%lld", nMinRange);
    }
    else
    {
        ESE_PrintRangeString_6FB0B140(buff, nMinRange, nMaxRange, 0, 1);
    }

    ESE_Helper_DrawTextCentered(buff, offsetA, offsetB, offsetC, nColor);
}

void __fastcall ESE_CHARSCREEN_DrawDescDam7(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    wchar_t buff[32] = { 0 };

    if (pSkill == nullptr || pSkillsTxtRecord == nullptr)
    {
        return;
    }

    uint16_t pSkillsTxtIndex = pSkillsTxtRecord->nSkillId;
    if (pSkillsTxtIndex < 0 || pSkillsTxtIndex >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return;
    }

    D2SkillsTxt* skillTxt = &sgptDataTables->pSkillsTxt[pSkillsTxtIndex];
    if (skillTxt == nullptr)
    {
        return;
    }

    uint16_t pSkillsDescTxtIndex = skillTxt->wSkillDesc;
    if (pSkillsDescTxtIndex < 0 || pSkillsDescTxtIndex >= sgptDataTables->nSkillDescTxtRecordCount)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = &sgptDataTables->pSkillDescTxt[pSkillsDescTxtIndex];
    if (pSkillDescTxt == nullptr)
    {
        return;
    }

    int32_t skillId = SKILLS_GetSkillIdFromSkill(pSkill, __FILE__, __LINE__);
    int32_t ddamCalc1 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], skillId, nSkillLevel);

    int32_t skillIdAgain = SKILLS_GetSkillIdFromSkill(pSkill, __FILE__, __LINE__);
    int32_t ddamCalc2 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], skillIdAgain, nSkillLevel);

    int64_t srcDamModMin = 0;
    int64_t srcDamModMax = 0;
    int32_t nColor = 0;

    ESE_sub_6FB0B2C0(pUnit, &srcDamModMin, &srcDamModMax, &nColor, ddamCalc1, ddamCalc2, pSkill, 128, 0, 0);
    ESE_sub_6FB0B6F0(pUnit, &srcDamModMin, &srcDamModMax, &nColor, 0, pSkill);

    int64_t nMinRange = ESE_DATATBLS_ApplyRatio(pSkillsTxtRecord->nSrcDam, srcDamModMin, 128);
    int64_t nMaxRange = ESE_DATATBLS_ApplyRatio(pSkillsTxtRecord->nSrcDam, srcDamModMax, 128);

    int64_t minPhysDamage = SKILLS_GetMinPhysDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 0);
    nMinRange += minPhysDamage >> 8;

    int64_t maxPhysDamage = SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 0);
    nMaxRange += maxPhysDamage >> 8;

    int64_t minElemDamage = SKILLS_GetMinElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
    nMinRange += minElemDamage >> 8;

    int64_t maxElemDamage = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
    nMaxRange += maxElemDamage >> 8;

    if (nMinRange >= nMaxRange)
    {
        nMaxRange = nMinRange + 1;
    }

    if (nMinRange == nMaxRange)
    {
        swprintf_s(buff, L"%lld", nMinRange);
    }
    else
    {
        ESE_PrintRangeString_6FB0B140(buff, nMinRange, nMaxRange, 0, 1);
    }

    ESE_Helper_DrawTextCentered(buff, offsetA, offsetB, offsetC, nColor);
}

void __fastcall ESE_CHARSCREEN_DrawDescDam6(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    wchar_t buffA[32];
    wchar_t buffB[32];

    if (pSkill == nullptr || pSkillsTxtRecord == nullptr)
    {
        return;
    }

    int32_t nColorA = 0;
    int64_t srcDamMin = 0;
    int64_t srcDamMax = 0;

    if (pSkillsTxtRecord->nSrcDam)
    {
        int64_t srcDamModMin = 0;
        int64_t srcDamModMax = 0;

        ESE_sub_6FB0B2C0(pUnit, &srcDamModMin, &srcDamModMax, &nColorA, 0, 0, pSkill, 128, 0, 0);
        ESE_sub_6FB0B6F0(pUnit, &srcDamModMin, &srcDamModMax, &nColorA, 0, pSkill);

        srcDamMin = pSkillsTxtRecord->nSrcDam * srcDamModMin / 128;
        srcDamMax = pSkillsTxtRecord->nSrcDam * srcDamModMax / 128;
    }

    int32_t nColorB = 0;
    switch (pSkillsTxtRecord->nEType)
    {
    case ELEMTYPE_FIRE:
        nColorB = 1;
        break;
    case ELEMTYPE_LTNG:
        nColorB = 9;
        break;
    case ELEMTYPE_MAGIC:
    case ELEMTYPE_COLD:
        nColorB = 3;
        break;
    case ELEMTYPE_POIS:
        nColorB = 2;
        break;
    }

    int64_t nMinRange = 0;
    int64_t nMaxRange = 0;

    int64_t minPhysDamage = SKILLS_GetMinPhysDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 0);
    nMinRange += minPhysDamage >> 8;

    int64_t maxPhysDamage = SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 0);
    nMaxRange += maxPhysDamage >> 8;

    int64_t minElemDamage = SKILLS_GetMinElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
    nMinRange += minElemDamage >> 8;

    int64_t maxElemDamage = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
    nMaxRange += maxElemDamage >> 8;

    ESE_sub_6FB0BD60(pUnit, &nMinRange, &nMaxRange, pSkillsTxtRecord->nEType);

    if (srcDamMin == 0 && srcDamMax == 0)
    {
        if (nMinRange >= nMaxRange)
        {
            nMaxRange = nMinRange + 1;
        }

        ESE_sub_6FB0B250((Unicode*)&buffA[0], nMinRange, nMaxRange, 0);

        ESE_Helper_DrawTextCentered(buffA, offsetA, offsetB, offsetC, nColorB);
        return;
    }
    if (nMinRange == 0 && nMaxRange == 0)
    {
        if (srcDamMin >= srcDamMax)
        {
            srcDamMax = srcDamMin + 1;
        }

        ESE_sub_6FB0B250((Unicode*)&buffA[0], srcDamMin, srcDamMax, 0);

        ESE_Helper_DrawTextCentered(buffA, offsetA, offsetB, offsetC, nColorA);
        return;
    }

    if (srcDamMin == srcDamMax)
    {
        ESE_sub_6FB0B0F0((Unicode*)&buffB[0], srcDamMin, 0);
    }
    else
    {
        ESE_PrintRangeString_6FB0B140(buffB, srcDamMin, srcDamMax, 0, 1);
    }

    if (nMinRange == nMaxRange)
    {
        ESE_sub_6FB0B0F0((Unicode*)&buffA[0], nMinRange, 0);
    }
    else
    {
        ESE_PrintRangeString_6FB0B140(buffA, nMinRange, nMaxRange, 0, 1);
    }

    ESE_sub_6FB0AC10((Unicode*)&buffB[0], (Unicode*)&buffA[0], offsetA, offsetB, offsetC, nColorA, nColorB);
}

void __fastcall ESE_CHARSCREEN_DrawDescDam5(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    wchar_t buff[32] = { 0 };

    if (pSkill == nullptr || pSkillsTxtRecord == nullptr)
    {
        return;
    }

    int32_t nColor = 0;
    switch (pSkillsTxtRecord->nEType)
    {
    case ELEMTYPE_FIRE:
        nColor = 1;
        break;
    case ELEMTYPE_LTNG:
        nColor = 9;
        break;
    case ELEMTYPE_MAGIC:
    case ELEMTYPE_COLD:
        nColor = 3;
        break;
    case ELEMTYPE_POIS:
        nColor = 2;
        break;
    }

    int64_t srcDamMin = 0;
    int64_t srcDamMax = 0;
    if (pSkillsTxtRecord->nSrcDam)
    {
        int64_t srcDamModMin = 0;
        int64_t srcDamModMax = 0;

        ESE_sub_6FB0B2C0(pUnit, &srcDamModMin, &srcDamModMax, &nColor, 0, 0, pSkill, 128, 0, 0);
        ESE_sub_6FB0B6F0(pUnit, &srcDamModMin, &srcDamModMax, &nColor, 0, pSkill);

        srcDamMin = pSkillsTxtRecord->nSrcDam * srcDamModMin / 128;
        srcDamMax = pSkillsTxtRecord->nSrcDam * srcDamModMax / 128;
    }

    int64_t minPhysDamage = (ESE_SKILLS_GetMinPhysDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 0) >> 8) + srcDamMin;
    int64_t maxPhysDamage = (ESE_SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 0) >> 8) + srcDamMax;

    int64_t minDamage;
    int64_t maxDamage;
    if (pSkillsTxtRecord->nEType == ELEMTYPE_POIS)
    {
        int64_t elementalLength = ESE_SKILLS_GetElementalLength(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);

        minDamage = elementalLength * ESE_SKILLS_GetMinElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
        maxDamage = elementalLength * ESE_SKILLS_GetMaxElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
    }
    else
    {
        minDamage = ESE_SKILLS_GetMinElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
        maxDamage = ESE_SKILLS_GetMaxElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
    }

    int64_t nMinRange = (minDamage >> 8) + minPhysDamage;
    int64_t nMaxRange = (maxDamage >> 8) + maxPhysDamage;

    if (nMinRange >= nMaxRange)
    {
        nMaxRange = nMinRange + 1;
    }
   
    if (nMinRange == nMaxRange)
    {
        swprintf_s(buff, L"%lld", nMinRange);
    }
    else
    {
        ESE_PrintRangeString_6FB0B140(buff, nMinRange, nMaxRange, 0, 1);
    }

    ESE_Helper_DrawTextCentered(buff, offsetA, offsetB, offsetC, nColor);
}


void __fastcall ESE_CHARSCREEN_DrawDescDam1(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    if (pSkill == nullptr || pSkillsTxtRecord == nullptr)
    {
        return;
    }

    uint16_t pSkillsTxtIndex = pSkillsTxtRecord->nSkillId;
    if (pSkillsTxtIndex < 0 || pSkillsTxtIndex >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return;
    }

    D2SkillsTxt* skillTxt = &sgptDataTables->pSkillsTxt[pSkillsTxtIndex];
    if (skillTxt == nullptr)
    {
        return;
    }

    uint16_t pSkillsDescTxtIndex = skillTxt->wSkillDesc;
    if (pSkillsDescTxtIndex < 0 || pSkillsDescTxtIndex >= sgptDataTables->nSkillDescTxtRecordCount)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = &sgptDataTables->pSkillDescTxt[pSkillsDescTxtIndex];
    if (pSkillDescTxt == nullptr)
    {
        return;
    }

    if (UNITS_CanDualWield(pUnit))
    {
        int32_t skillId = SKILLS_GetSkillIdFromSkill(pSkill, __FILE__, __LINE__);
        int64_t ddamCalc1 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], skillId, nSkillLevel);

        int32_t skillIdAgain = SKILLS_GetSkillIdFromSkill(pSkill, __FILE__, __LINE__);
        int64_t ddamCalc2 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], skillIdAgain, nSkillLevel);

        ESE_sub_6FB0C400(
            pUnit,
            pSkill,
            pSkillsTxtRecord,
            nSkillLevel,
            ESE_sub_6FB0C3A0,
            ddamCalc1,
            ddamCalc2,
            offsetA,
            offsetB,
            offsetC,
            1);
    }
    else
    {
        ESE_CHARSCREEN_DrawDescDam7(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
    }
}


void __fastcall ESE_sub_6FB0D4F0(D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, int32_t* pColor, int64_t additionalWeaponMasteryBonus, int a6, D2SkillStrc* pSkill, int a8, D2UnitStrc* pItem)
{
    if (pSkill == nullptr) 
    {
        return;
    }

    *pMinDamage = 0;
    *pMaxDamage = 0;
    if (pItem == nullptr)
    {
        if (pUnit->pInventory == nullptr)
        {
            return;
        }

        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        if (pItem == nullptr)
        {
            return;
        }
    }

    if (ITEMS_CheckIfThrowable(pItem))
    {
        if (D2Common_10731_ITEMS_CheckItemTypeId(pItem, 38))
        {
            int32_t missileType = ITEMS_GetMissileType(pItem);
            int64_t minElemDamage = ESE_MISSILE_GetMinElemDamage(0, pUnit, missileType, 1);
            int64_t minDamage = ESE_MISSILE_GetMinDamage(0, pUnit, missileType, 1) + minElemDamage;
            int64_t maxElemDamage = ESE_MISSILE_GetMaxElemDamage(0, pUnit, missileType, 1);
            int64_t maxDamage = ESE_MISSILE_GetMaxDamage(0, pUnit, missileType, 1) + maxElemDamage;

            int32_t missileElemType = MISSILE_GetElemTypeFromMissileId(missileType);
            switch (missileElemType)
            {
            case ELEMTYPE_FIRE:
                *pColor = 1;
                break;
            case ELEMTYPE_LTNG:
                *pColor = 4;
                break;
            case ELEMTYPE_COLD:
                *pColor = 3;
                break;
            case ELEMTYPE_POIS:
                *pColor = 2;
                break;
            default:
                *pColor = 0;
                break;
            }

            if (missileElemType == ELEMTYPE_POIS)
            {
                int64_t elemLength = ESE_MISSILE_GetElementalLength(0, pUnit, missileType, 1) / 25;
                if (elemLength <= 0)
                {
                    elemLength = 1;
                }

                minDamage /= elemLength;
                maxDamage /= elemLength;
            }

            minDamage >>= 8;
            maxDamage >>= 8;

            if (maxDamage <= minDamage)
            {
                maxDamage = minDamage;
            }

            *pMinDamage = minDamage;
            *pMaxDamage = maxDamage;
        }
        else
        {
            int64_t damagePercentFromStats = 0;

            int64_t strBonus = ITEMS_GetStrengthBonus(pItem);
            if (strBonus)
            {
                damagePercentFromStats = strBonus * STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) / 100;
            }

            int64_t dexBonus = ITEMS_GetDexBonus(pItem);
            if (dexBonus)
            {
                damagePercentFromStats += dexBonus * STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) / 100;
            }

            *pMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_THROW_MINDAMAGE, 0);
            *pMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_THROW_MAXDAMAGE, 0);
            int64_t totalDamagePercent = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0) + damagePercentFromStats;
            int64_t minDamagePercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0);
            int64_t maxDamagePercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);

            if (totalDamagePercent <= -90)
            {
                totalDamagePercent = -90;
            }

            *pMinDamage += *pMinDamage * (totalDamagePercent + minDamagePercent) / 100;
            *pMaxDamage += *pMaxDamage * (maxDamagePercent + totalDamagePercent) / 100;

            int64_t totalWeaponMasteryBonus = additionalWeaponMasteryBonus;
            if (STATES_CheckState(pUnit, STATE_THROWINGMASTERY))
            {
                totalWeaponMasteryBonus = additionalWeaponMasteryBonus + SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 1);
            }

            *pMinDamage += ESE_DATATBLS_ApplyRatio(totalWeaponMasteryBonus, *pMinDamage, 100);
            *pMaxDamage += ESE_DATATBLS_ApplyRatio(totalWeaponMasteryBonus, *pMaxDamage, 100);

            if (*pMaxDamage < *pMinDamage)
            {
                *pMaxDamage = *pMinDamage;
            }

            int64_t nMinElemDamage = 0;
            int64_t nMaxElemDamage = 0;
            ESE_sub_6FB0B6F0(pUnit, &nMinElemDamage, &nMaxElemDamage, pColor, pItem, pSkill);

            if (nMaxElemDamage < nMinElemDamage)
            {
                nMaxElemDamage = nMinElemDamage;
            }

            *pMinDamage += nMinElemDamage;
            *pMaxDamage += nMaxElemDamage;
        }
    }
}

void __fastcall ESE_CHARSCREEN_DrawDescDam22(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    wchar_t buffA[32] = {0};
    wchar_t buffB[32] = {0};

    if (pSkill == nullptr || pSkillsTxtRecord == nullptr)
    {
        return;
    }

    int32_t nColorA = 0;
    int64_t nMinElemDamageATemp = 0;
    int64_t nMaxElemDamageATemp = 0;
    ESE_sub_6FB0D4F0(pUnit, &nMinElemDamageATemp, &nMaxElemDamageATemp, &nColorA, 0, 0, pSkill, 0, 0);

    int64_t nMinElemDamageA = ESE_DATATBLS_ApplyRatio(nMinElemDamageATemp, pSkillsTxtRecord->nSrcDam, 128);
    int64_t nMaxElemDamageA = ESE_DATATBLS_ApplyRatio(nMaxElemDamageATemp, pSkillsTxtRecord->nSrcDam, 128);

    int32_t nColorB = 0;
    int64_t nMinElemDamageB = 0;
    int64_t nMaxElemDamageB = 0;
    ESE_sub_6FB0C840(pUnit, pSkillsTxtRecord, nSkillLevel, &nMinElemDamageB, &nMaxElemDamageB, &nColorB);

    if (nMinElemDamageA || nMaxElemDamageA)
    {
        if (nMinElemDamageB || nMaxElemDamageB)
        {
            if (nMinElemDamageA == nMaxElemDamageA)
            {
                ESE_sub_6FB0B0F0((Unicode *)&buffA[0], nMinElemDamageA, 0);
            }
            else
            {
                ESE_PrintRangeString_6FB0B140(buffA, nMinElemDamageA, nMaxElemDamageA, 0, 1);
            }

            ESE_sub_6FB0B250((Unicode*)&buffB[0], nMinElemDamageB, nMaxElemDamageB, 0);
            ESE_sub_6FB0AC10((Unicode*)&buffA[0], (Unicode*)&buffB[0], offsetA, offsetB, offsetC, nColorA, nColorB);
        }
        else
        {
            if (nMinElemDamageA >= nMaxElemDamageA)
            {
                nMaxElemDamageA = nMinElemDamageA + 1;
            }

            ESE_sub_6FB0B250((Unicode*)&buffA[0], nMinElemDamageA, nMaxElemDamageA, 0);

            ESE_Helper_DrawTextCentered(buffA, offsetA, offsetB, offsetC, nColorA);
        }
    }
    else
    {
        if (nMinElemDamageB >= nMaxElemDamageB)
        {
            nMaxElemDamageB = nMinElemDamageB + 1;
        }

        ESE_sub_6FB0B250((Unicode*)&buffA[0], nMinElemDamageB, nMaxElemDamageB, 0);

        ESE_Helper_DrawTextCentered(buffA, offsetA, offsetB, offsetC, nColorA);
    }
}
