#include <D2Client/CharScreen_ESE.h>
#include <D2Common/D2Skills_ESE.h>
#include "LibESE.h"
#include <D2Combat.h>
#include "Font.h"
#include <cinttypes>

void ESE_PrintRangeString(wchar_t* pText, int64_t minDamage, int64_t maxDamage, int isAdditonRange, int allowThousandsSuffix)
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
            dMinDamage = minDamage / 10000.0;
        }

        if (maxDamage >= 1000000)
        {
            maxDamageUnit = L'M';
            dMaxDamage = maxDamage / 1000000.0;
        }
        else if (maxDamage >= 10000)
        {
            maxDamageUnit = L'K';
            dMaxDamage = maxDamage / 10000.0;
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
        ESE_PrintRangeString(buff, nMinRange, nMaxRange, 0, 1);
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

    D2Client_DrawTextCentered(
        *D2Client_pDWORD_6FBBA748 + offsetA,
        *D2Client_pDWORD_6fbba74c + *D2Client_pDWORD_6fb740f0 + v20 - 0x1e0,
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
        ESE_PrintRangeString(buff, nMinRange, nMaxRange, 0, 1);
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

    D2Client_DrawTextCentered(
        *D2Client_pDWORD_6FBBA748 + offsetA,
        *D2Client_pDWORD_6fbba74c + *D2Client_pDWORD_6fb740f0 + textOffsetY - 0x1e0,
        *D2Client_pDWORD_6FBBA748 + offsetC,
        (Unicode*)&buff[0],
        nColor
    );
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
        ESE_PrintRangeString(buff, nMinRange, nMaxRange, 0, 1);
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

    D2Client_DrawTextCentered(
        *D2Client_pDWORD_6FBBA748 + offsetA,
        *D2Client_pDWORD_6fbba74c + *D2Client_pDWORD_6fb740f0 + v20 - 0x1e0,
        *D2Client_pDWORD_6FBBA748 + offsetC,
        (Unicode*)&buff[0],
        nColor
    );
}
