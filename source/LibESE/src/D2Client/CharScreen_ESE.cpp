#include <D2Client/CharScreen_ESE.h>
#include "Font.h"

void ESE_PrintRangeString(wchar_t* pText, int minDamage, int maxDamage, int isAdditonRange, int allowThousandsSuffix)
{
    const wchar_t* prefix = isAdditonRange ? L"+" : L"";

    if (allowThousandsSuffix && minDamage >= 10000 && maxDamage >= 10000)
    {
        swprintf(pText, L"%s%dK-%dK", prefix, (minDamage + 500) / 1000, (maxDamage + 500) / 1000);
    }
    else if (allowThousandsSuffix && maxDamage >= 10000)
    {
        swprintf(pText, L"%s%d-%dK", prefix, minDamage, (maxDamage + 500) / 1000);
    }
    else 
    {
        swprintf(pText, L"%s%d-%d", prefix, minDamage, maxDamage);
    }
}

void __fastcall ESE_CHARSCREEN_DrawSkillDamageLeft(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
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

    int32_t minElemDamage = SKILLS_GetMinElemDamage(pUnit, pSkillsTxtIndex, nSkillLevel, 1);
    int32_t maxElemDamage = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel, 1);
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
    int32_t ddamCalc1 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], skillId, nSkillLevel);
    if (!ddamCalc1)
    {
        ddamCalc1 = 1;
    }

    int32_t skillIdAgain = SKILLS_GetSkillIdFromSkill(pSkill, __FILE__, __LINE__);
    int32_t ddamCalc2 = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], skillIdAgain, nSkillLevel);
    if (!ddamCalc2)
    {
        ddamCalc2 = 1;
    }

    int32_t nMinRange = (25 * minElemDamage * ddamCalc1 / ddamCalc2) >> 8;
    int32_t nMaxRange = (25 * maxElemDamage * ddamCalc1 / ddamCalc2) >> 8;
    if (nMinRange >= nMaxRange)
    {
        nMaxRange = nMinRange + 1;
    }

    if (nMinRange == nMaxRange)
    {
        swprintf_s(buff, L"%d", nMinRange);
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

void __fastcall ESE_CHARSCREEN_DrawSkillDamageRight(D2UnitStrc* pUnit, int a2, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{

}
