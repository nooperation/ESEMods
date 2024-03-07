#include <D2Client/CharScreen_ESE.h>
#include <D2Common/D2Skills_ESE.h>
#include "LibESE.h"
#include <D2Combat.h>
#include "Font.h"
#include <cinttypes>

void __fastcall ESE_PrintRangeString_6FB0B140(wchar_t* pText, int64_t minDamage, int64_t maxDamage, int isAdditonRange, int allowThousandsSuffix);
void __fastcall ESE_sub_6FB0AC10(Unicode* pTextA, Unicode* pTextB, int offsetA, int offsetB, int offsetC, int nColorA, int nColorB);
void __fastcall ESE_sub_6FB0B0F0(struct Unicode* pText, int64_t damage, int isAdditonRange);
void __fastcall ESE_sub_6FB0B250(struct Unicode* pText, int64_t minDamage, int64_t maxDamage, int isAdditonRange);

typedef void(__fastcall* DamageCallback7D0_t)(D2UnitStrc* pUnit, int32_t* pUnknown1, int32_t* pUnknown2, int32_t* pColor, int32_t ddamCalc1, int32_t ddamCalc2, D2SkillStrc* pSkill, int32_t unknown5, D2UnitStrc* unknown6);

void __fastcall ESE_sub_6FB0C3A0(D2UnitStrc* pUnit, int32_t* pUnknown1, int32_t* pUnknown2, int32_t* pColor, int32_t ddamCalc1, int32_t ddamCalc2, D2SkillStrc* pSkill, int32_t unknown5, D2UnitStrc* unknown6)
{
    // TODO: Implement both of these, they contain overflowing damage calculations
    D2Client_sub_6FB0B2C0(pUnit, pUnknown1, pUnknown2, pColor, ddamCalc1, ddamCalc2, pSkill, unknown5, unknown6, 0);
    D2Client_sub_6FB0B6F0(pUnit, pUnknown1, pUnknown2, pColor, unknown6, pSkill);
}

int __fastcall ESE_sub_6FB0A7D0(D2UnitStrc* pUnit, int32_t* pMinDamageA, int32_t* pMaxDamageA, int32_t* pColorA, int32_t* pMinDamageB, int32_t* pMaxDamageB, int32_t* pColorB, D2SkillStrc* pSkill, DamageCallback7D0_t callback, int ddamCalc1, int ddamCalc2)
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
        maxElemDamage = nSkillLevela * ESE_SKILLS_GetMaxElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
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
        case 1u:
            *pColor = 1;
            break;
        case 2u:
            *pColor = 9;
            break;
        case 3u:
        case 4u:
            *pColor = 3;
            break;
        case 5u:
            *pColor = 2;
            break;
        default:
            break;
        }
    }

    *pMinElemDamage += minElemDamage;
    *pMaxElemDamage += maxElemDamage;
}

void __fastcall ESE_sub_6FB0C400(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, DamageCallback7D0_t callback, int32_t ddamCalc1, int32_t ddamCalc2, int32_t offsetA, int32_t offsetB, int32_t offsetC, int32_t flag)
{
    wchar_t buffB[64];
    wchar_t buffA[64];

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

    int32_t minDamageA_temp;
    int32_t maxDamageA_temp;
    int32_t minDamageB_temp;
    int32_t maxDamageB_temp;
    int32_t nColorA;
    int32_t nColorB;

    ESE_sub_6FB0A7D0(
        pUnit,
        &minDamageA_temp,
        &maxDamageA_temp,
        &nColorA,
        &minDamageB_temp,
        &maxDamageB_temp,
        &nColorB,
        pSkill,
        callback,
        ddamCalc1,
        ddamCalc2);

    int64_t minDamageA = (int64_t)minDamageA_temp;
    int64_t maxDamageA = (int64_t)maxDamageA_temp;
    int64_t minDamageB = (int64_t)minDamageB_temp;
    int64_t maxDamageB = (int64_t)maxDamageB_temp;

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

        int32_t pWidth = 0;
        int32_t pHeight = 0;
        int32_t v20 = 0;

        D2Win_10131_GetTextDimensions((Unicode*)&buffA[0], &pWidth, &pHeight);

        int32_t widthMod = (11 * pWidth) / 7;
        if (widthMod <= offsetC - offsetA)
        {
            D2Win_10127_SetFont(D2FONT_FONT16);
            v20 = offsetB;
        }
        else
        {
            D2Win_10127_SetFont(D2FONT_FONT6);
            v20 = (offsetB - 1);
        }

        D2Client_DrawTextCentered_6FACFCD0(
            *D2Client_pDWORD_6FBBA748 + offsetA,
            *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 + v20 - 0x1e0,
            *D2Client_pDWORD_6FBBA748 + offsetC,
            (Unicode*)&buffA[0],
            nColorB
        );

        return;
    }

    if (!minDamageB && !maxDamageB)
    {
        if (minDamageA >= maxDamageA)
        {
            maxDamageA = minDamageA + 1;
        }

        ESE_sub_6FB0B250((Unicode*)&buffA[0], minDamageA, maxDamageA, 0);

        int32_t pWidth = 0;
        int32_t pHeight = 0;
        int32_t v20 = 0;

        D2Win_10131_GetTextDimensions((Unicode*)&buffA[0], &pWidth, &pHeight);

        int32_t widthMod = (11 * pWidth) / 7;
        if (widthMod <= offsetC - offsetA)
        {
            D2Win_10127_SetFont(D2FONT_FONT16);
            v20 = offsetB;
        }
        else
        {
            D2Win_10127_SetFont(D2FONT_FONT6);
            v20 = (offsetB - 1);
        }

        D2Client_DrawTextCentered_6FACFCD0(
            *D2Client_pDWORD_6FBBA748 + offsetA,
            *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 + v20 - 0x1e0,
            *D2Client_pDWORD_6FBBA748 + offsetC,
            (Unicode*)&buffA[0],
            nColorA
        );
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

    ESE_sub_6FB0AC10((Unicode *)&buffA[0], (Unicode*)&buffB[0], offsetA, offsetB, offsetC, nColorA, nColorB);
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
    wchar_t buff[32];

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
    case 1u:
        nColor = 1;
        break;
    case 2u:
        nColor = 9;
        break;
    case 3u:
    case 4u:
        nColor = 3;
        break;
    case 5u:
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

    int32_t pWidth = 0;
    int32_t pHeight = 0;
    int32_t v20 = 0;

    D2Win_10131_GetTextDimensions((Unicode*)&buff[0], &pWidth, &pHeight);

    int32_t widthMod = (11 * pWidth) / 7;
    if (widthMod <= offsetC - offsetA)
    {
        D2Win_10127_SetFont(D2FONT_FONT16);
        v20 = offsetB;
    }
    else
    {
        D2Win_10127_SetFont(D2FONT_FONT6);
        v20 = (offsetB - 1);
    }

    D2Client_DrawTextCentered_6FACFCD0(
        *D2Client_pDWORD_6FBBA748 + offsetA,
        *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 + v20 - 0x1e0,
        *D2Client_pDWORD_6FBBA748 + offsetC,
        (Unicode*)&buff[0],
        nColor
    );
}

void __fastcall ESE_CHARSCREEN_DrawDescDam7(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    wchar_t buff[32];

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

    int32_t nUnknown1 = 0;
    int32_t nUnknown2 = 0;
    int32_t nColor = 0;

    D2Client_sub_6FB0B2C0(pUnit, &nUnknown1, &nUnknown2, &nColor, ddamCalc1, ddamCalc2, pSkill, 128, 0, 0);
    D2Client_sub_6FB0B6F0(pUnit, &nUnknown1, &nUnknown2, &nColor, 0, pSkill);

    int64_t nMinRange = ESE_DATATBLS_ApplyRatio(pSkillsTxtRecord->nSrcDam, nUnknown1, 128);
    int64_t nMaxRange = ESE_DATATBLS_ApplyRatio(pSkillsTxtRecord->nSrcDam, nUnknown2, 128);

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
        int32_t vUnknown1 = 0;
        int32_t vUnknown2 = 0;

        D2Client_sub_6FB0B2C0(pUnit, &vUnknown1, &vUnknown2, &nColorA, 0, 0, pSkill, 128, 0, 0);
        D2Client_sub_6FB0B6F0(pUnit, &vUnknown1, &vUnknown2, &nColorA, 0, pSkill);

        srcDamMin = (int64_t)pSkillsTxtRecord->nSrcDam * vUnknown1 / 128;
        srcDamMax = (int64_t)pSkillsTxtRecord->nSrcDam * vUnknown2 / 128;
    }

    int32_t nColorB = 0;
    switch (pSkillsTxtRecord->nEType)
    {
    case 1:
        nColorB = 1;
        break;
    case 2:
        nColorB = 9;
        break;
    case 3:
    case 4:
        nColorB = 3;
        break;
    case 5:
        nColorB = 2;
        break;
    default:
        nColorB = 0;
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

        int32_t v20 = 0;
        int32_t pWidth = 0;
        int32_t pHeight = 0;
        D2Win_10131_GetTextDimensions((Unicode*)&buffA[0], &pWidth, &pHeight);

        int32_t widthMod = (11 * pWidth) / 7;
        if (widthMod <= offsetC - offsetA)
        {
            D2Win_10127_SetFont(D2FONT_FONT16);
            v20 = offsetB;
        }
        else
        {
            D2Win_10127_SetFont(D2FONT_FONT6);
            v20 = (offsetB - 1);
        }

        D2Client_DrawTextCentered_6FACFCD0(
            *D2Client_pDWORD_6FBBA748 + offsetA,
            *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 + v20 - 0x1e0,
            *D2Client_pDWORD_6FBBA748 + offsetC,
            (Unicode*)&buffA[0],
            nColorB
        );

        return;
    }
    if (nMinRange == 0 && nMaxRange == 0)
    {
        if (srcDamMin >= srcDamMax)
        {
            srcDamMax = srcDamMin + 1;
        }

        ESE_sub_6FB0B250((Unicode*)&buffA[0], srcDamMin, srcDamMax, 0);

        int32_t v20 = 0;
        int32_t pWidth = 0;
        int32_t pHeight = 0;
        D2Win_10131_GetTextDimensions((Unicode*)&buffA[0], &pWidth, &pHeight);

        int32_t widthMod = (11 * pWidth) / 7;
        if (widthMod <= offsetC - offsetA)
        {
            D2Win_10127_SetFont(D2FONT_FONT16);
            v20 = offsetB;
        }
        else
        {
            D2Win_10127_SetFont(D2FONT_FONT6);
            v20 = (offsetB - 1);
        }

        D2Client_DrawTextCentered_6FACFCD0(
            *D2Client_pDWORD_6FBBA748 + offsetA,
            *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 + v20 - 0x1e0,
            *D2Client_pDWORD_6FBBA748 + offsetC,
            (Unicode*)&buffA[0],
            nColorA
        );

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

    ESE_sub_6FB0AC10((Unicode *)&buffB[0], (Unicode*)&buffA[0], offsetA, offsetB, offsetC, nColorA, nColorB);
}

void __fastcall ESE_CHARSCREEN_DrawDescDam5(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    wchar_t buff[32];

    if (pSkill == nullptr || pSkillsTxtRecord == nullptr)
    {
        return;
    }

    int32_t nColor = 0;
    switch (pSkillsTxtRecord->nEType - 1)
    {
    case 0:
        nColor = 1;
        break;
    case 1:
        nColor = 9;
        break;
    case 2:
    case 3:
        nColor = 3;
        break;
    case 4:
        nColor = 2;
        break;
    }

    int64_t srcDamMin = 0;
    int64_t srcDamMax = 0;
    if (pSkillsTxtRecord->nSrcDam)
    {
        int32_t vUnknown1 = 0;
        int32_t vUnknown2 = 0;

        D2Client_sub_6FB0B2C0(pUnit, &vUnknown1, &vUnknown2, &nColor, 0, 0, pSkill, 128, 0, 0);
        D2Client_sub_6FB0B6F0(pUnit, &vUnknown1, &vUnknown2, &nColor, 0, pSkill);

        srcDamMin = (int64_t)pSkillsTxtRecord->nSrcDam * vUnknown1 / 128;
        srcDamMax = (int64_t)pSkillsTxtRecord->nSrcDam * vUnknown2 / 128;
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

    int32_t v20 = 0;
    int32_t pWidth = 0;
    int32_t pHeight = 0;
    D2Win_10131_GetTextDimensions((Unicode*)&buff[0], &pWidth, &pHeight);

    int32_t widthMod = (11 * pWidth) / 7;
    if (widthMod <= offsetC - offsetA)
    {
        D2Win_10127_SetFont(D2FONT_FONT16);
        v20 = offsetB;
    }
    else
    {
        D2Win_10127_SetFont(D2FONT_FONT6);
        v20 = (offsetB - 1);
    }

    D2Client_DrawTextCentered_6FACFCD0(
        *D2Client_pDWORD_6FBBA748 + offsetA,
        *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 + v20 - 0x1e0,
        *D2Client_pDWORD_6FBBA748 + offsetC,
        (Unicode*)&buff[0],
        nColor
    );
}


void __fastcall ESE_CHARSCREEN_DrawDescDam1(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    wchar_t buff[32];

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
        int32_t ddamCalc1 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], skillId, nSkillLevel);

        int32_t skillIdAgain = SKILLS_GetSkillIdFromSkill(pSkill, __FILE__, __LINE__);
        int32_t ddamCalc2 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], skillIdAgain, nSkillLevel);

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
