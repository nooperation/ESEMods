#include <D2Client/CHARSCREENDMG_ESE.h>
#include <D2Common/D2Skills_ESE.h>
#include <DataTbls/SkillsIds.h>
#include <DataTbls/StringIds.h>
#include <D2Common/Units/Missile_ESE.h>
#include "LibESE.h"
#include <D2Combat.h>
#include "Font.h"
#include <cinttypes>
#include <D2States.h>
#include <string>
#include <codecvt>

void AppendString(std::wstring& dest, const char* source)
{
    std::string str(source);
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    dest.append(converter.from_bytes(str));
}

void ColorizeString(std::wstring& str, int32_t color)
{
    auto colorCodeToken = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3994_colorcode);
    std::wstring colorStr(colorCodeToken);
    colorStr.append(std::to_wstring(color));

    str.insert(0, colorStr);
}

void AppendColorizedString(std::wstring& dest, const std::wstring& src, int32_t color)
{
    auto colorCodeToken = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3994_colorcode);
    dest.append(colorCodeToken);
    dest.append(std::to_wstring(color));
    dest.append(src);
}

int ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(int32_t nDescFunc, int32_t nItemStatCostTxtRecordCount, std::wstring outBuff)
{
    if (nDescFunc < 6 || nDescFunc > 10 && nDescFunc != 21)
    {
        return 1;
    }

    auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    if (nItemStatCostTxtRecordCount == 5382)
    {
        auto v75 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11091_increaseswithplaylevelX);
        outBuff.append(strSpace);
        outBuff.append(v75);
        return 1;
    }
    else
    {
        auto v73 = (const wchar_t*)D2LANG_GetStringFromTblIndex(nItemStatCostTxtRecordCount);
        outBuff.append(strSpace);
        outBuff.append(v73);
        return 1;
    }
}

int ESE_D2Client_GetItemPropertyLine_6FAF21C0(D2UnitStrc* pItem, D2StatListStrc* pStatList, int nStatId, int charStatsTxtRecordIndex, int statValueModifier, std::wstring outBuff)
{
    if (nStatId < 0)
    {
        return 0;
    }

    if (nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    auto itemStatCostTxtForStat = &sgptDataTables->pItemStatCostTxt[nStatId];
    if (!itemStatCostTxtForStat)
    {
        return 0;
    }

    auto itemStatCost_nOp = itemStatCostTxtForStat->nOp;
    auto v9 = statValueModifier;
    int32_t statValueMaybe = 0;

    if (itemStatCost_nOp < 2u || itemStatCost_nOp > 5u)
    {
        statValueMaybe = v9 >> itemStatCostTxtForStat->nValShift;
        if (nStatId == 122 && pItem && pItem->dwUnitType == 4 && D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BLUNT))
        {
            statValueMaybe += 50;
        }
    }
    else if (itemStatCostTxtForStat->wOpBase < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        auto opBaseItemStatCostTxt = &sgptDataTables->pItemStatCostTxt[itemStatCostTxtForStat->wOpBase];
        if (opBaseItemStatCostTxt)
        {
            auto v13 = D2Client_sub_6FB283D0();
            v9 = (statValueModifier * (STATLIST_UnitGetStatValue(v13, itemStatCostTxtForStat->wOpBase, 0) >> opBaseItemStatCostTxt->nValShift)) >> itemStatCostTxtForStat->nOpParam;
            statValueMaybe = v9 >> itemStatCostTxtForStat->nValShift;
            if (nStatId == 122 && pItem && pItem->dwUnitType == 4 && D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BLUNT))
            {
                statValueMaybe += 50;
            }
        }
    }

    auto wDescGrpIsZero = itemStatCostTxtForStat->wDescGrp == 0;
    auto a5a = statValueMaybe;

    uint8_t nDescFunc = 1;
    uint8_t nDescVal = 1;
    uint8_t nDescGrpFunc = 0;

    uint16_t descStrIndex = 0;

    if (wDescGrpIsZero)
    {
        nDescGrpFunc = 0;
    LABEL_37:
        nDescFunc = itemStatCostTxtForStat->nDescFunc;
        nDescVal = itemStatCostTxtForStat->nDescVal;
        descStrIndex = itemStatCostTxtForStat->wDescStr2;
        int16_t v25 = 0;

        if (nDescGrpFunc)
        {
            nDescFunc = itemStatCostTxtForStat->nDescGrpFunc;
            nDescVal = itemStatCostTxtForStat->nDescGrpVal;
            descStrIndex = itemStatCostTxtForStat->wDescGrpStr2;
            if (statValueMaybe < 0)
            {
                v25 = itemStatCostTxtForStat->wDescGrpStrNeg;
            }
            else
            {
                v25 = itemStatCostTxtForStat->wDescGrpStrPos;
            }
        }
        else if (statValueMaybe < 0)
        {
            v25 = itemStatCostTxtForStat->wDescStrNeg;
        }
        else
        {
            v25 = itemStatCostTxtForStat->wDescStrPos;
        }

        auto strDesc = (const wchar_t *)D2LANG_GetStringFromTblIndex(v25);
        SStrPrintf(v97, 10, "%i", statValueMaybe);
        Unicode::toUnicode(v95, v97, 9);

        auto strPercentSign = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4001_percent);
        auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
        auto strPlusSign = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4002_plus);

        switch (nDescFunc)
        {
        case 1:
        case 6:
        case 12:
            if (statValueMaybe <= 0)
            {
                Unicode::strcpy(v99, v95);
            }
            else if (nDescFunc != 12 || statValueMaybe > 1)
            {
                Unicode::strcpy(v99, strPlusSign);
                Unicode::strcat(v99, v95);
            }
            if (nDescVal == 1)
            {
                Unicode::strcpy(outputBuffer256, v99);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (nDescVal != 2)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            Unicode::strcpy(outputBuffer256, strDesc);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v99);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 2:
        case 7:
            if (nDescVal == 1)
            {
                Unicode::strcpy(outputBuffer256, v95);
                Unicode::strcat(outputBuffer256, strPercentSign);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }

            if (nDescVal != 2)
            {
                Unicode::strcpy(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            Unicode::strcpy(outputBuffer256, strDesc);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v95);
            Unicode::strcat(outputBuffer256, strPercentSign);

            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 3:
        case 9:
            if (nDescVal == 1)
            {
                Unicode::strcpy(outputBuffer256, v95);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (nDescVal != 2)
            {
                Unicode::strcpy(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            Unicode::strcpy(outputBuffer256, strDesc);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v95);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 4:
        case 8:
            if (nDescVal != 1)
            {
                if (nDescVal != 2)
                {
                    Unicode::strcpy(outputBuffer256, strDesc);
                    return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
                }
                Unicode::strcpy(outputBuffer256, strDesc);
                Unicode::strcat(outputBuffer256, strSpace);
                if (statValueMaybe >= 0)
                {
                    Unicode::strcat(outputBuffer256, strPlusSign);
                }
                Unicode::strcat(outputBuffer256, v95);
                Unicode::strcat(outputBuffer256, strPercentSign);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (statValueMaybe >= 0)
            {
                Unicode::strcpy(outputBuffer256, strPlusSign);
                Unicode::strcat(outputBuffer256, v95);
                Unicode::strcat(outputBuffer256, strPercentSign);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }

            *outputBuffer256 = 0;
            Unicode::strcat(outputBuffer256, v95);
            Unicode::strcat(outputBuffer256, strPercentSign);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, strDesc);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 5:
        case 10:
            SStrPrintf(v97, 10, "%i", 100 * statValueMaybe / 128);
            Unicode::toUnicode(v95, v97, 9);
            if (nDescVal == 1)
            {
                Unicode::strcpy(outputBuffer256, v95);
                Unicode::strcat(outputBuffer256, strPercentSign);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }

            if (nDescVal != 2)
            {
                Unicode::strcpy(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }

            Unicode::strcpy(outputBuffer256, strDesc);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v95);
            Unicode::strcat(outputBuffer256, strPercentSign);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 11:
            if (statValueMaybe <= 0)
            {
                auto strRepairsNDurabilityPerSecond = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21241_ModStre9t);
                Unicode::sprintf(128, outputBuffer256, strRepairsNDurabilityPerSecond, 25);
            }
            else if (2500 / statValueMaybe > 30)
            {
                auto strRepairsNDurabilityInNSeconds = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21242_ModStre9u);
                Unicode::sprintf(128, outputBuffer256, strRepairsNDurabilityInNSeconds, 1, (2500 / statValueMaybe + 12) / 25);
            }
            else
            {
                auto strRepairsNDurabilityPerSecond1 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21241_ModStre9t);
                Unicode::sprintf(128, outputBuffer256, strRepairsNDurabilityPerSecond1, 1);
            }

            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 13:
            v99[0] = 0;
            if (statValueMaybe <= 0)
            {
                if (statValueMaybe >= 0)
                {
                    return 0;
                }
                Unicode::strcpy(v99, v95);
            }
            else
            {
                Unicode::strcpy(v99, strPlusSign);
                Unicode::strcat(v99, v95);
            }
            if (charStatsTxtRecordIndex < 0)
            {
                return 0;
            }
            if (charStatsTxtRecordIndex >= sgptDataTables->nCharStatsTxtRecordCount)
            {
                return 0;
            }
            auto v39 = &sgptDataTables->pCharStatsTxt[charStatsTxtRecordIndex];
            if (!v39)
            {
                return 0;
            }
            auto strDesc = (const wchar_t*)D2LANG_GetStringFromTblIndex(v39->wStrAllSkills);
            if (nDescVal == 1)
            {
                Unicode::strcpy(outputBuffer256, v99);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (nDescVal != 2)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            Unicode::strcpy(outputBuffer256, strDesc);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v99);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 14:
            auto v40 = charStatsTxtRecordIndex >> 3;
            if (charStatsTxtRecordIndex >> 3 < 0)
            {
                return 0;
            }
            if (v40 >= sgptDataTables->nCharStatsTxtRecordCount)
            {
                return 0;
            }
            auto v41 = &sgptDataTables->pCharStatsTxt[v40];
            if (!v41 || (charStatsTxtRecordIndex & 7u) >= 3)
            {
                return 0;
            }
            auto v42 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v41->wStrSkillTab[charStatsTxtRecordIndex & 7]);
            Unicode::sprintf(256, outputBuffer256, v42, statValueMaybe);
            Unicode::strcat(outputBuffer256, strSpace);
            auto v28 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v41->wStrClassOnly);
            Unicode::strcat(outputBuffer256, v28);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 15:
            auto v43 = sgptDataTables->nStuff;
            auto v44 = charStatsTxtRecordIndex & sgptDataTables->nShiftedStuff;
            if (charStatsTxtRecordIndex >> v43 <= 0 || charStatsTxtRecordIndex >> v43 >= sgptDataTables->nSkillsTxtRecordCount)
            {
                return 0;
            }
            auto v45 = D2Client_sub_6FB0A440(charStatsTxtRecordIndex >> v43, 0);
            auto v78 = (const wchar_t *)D2LANG_GetStringFromTblIndex(v45);
            auto v46 = (const wchar_t *)D2LANG_GetStringFromTblIndex(itemStatCostTxtForStat->wDescStrPos);
            Unicode::sprintf(256, outputBuffer256, v46, statValueMaybe, 0, v44, v78);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 16:
            auto v47 = D2Client_sub_6FB0A440(charStatsTxtRecordIndex, 0);
            auto v48 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v47);
            if (!v48)
            {
                return 0;
            }
            Unicode::sprintf(256, outputBuffer256, strDesc, statValueMaybe, v48);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 17:
        case 18:
            int32_t preiodOfDay = 0;
            int32_t pItemModPeriodOfDay = 0;
            int32_t baseTime = 0;
            if (*D2Client_pDWORD_6FBA7984)
            {
                preiodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(*D2Client_pDWORD_6FBA7984, &baseTime);
                pItemModPeriodOfDay = preiodOfDay;
            }

            int32_t itemModMin = 0;
            int32_t itemModMax = 0;
            auto timeAdjustmentThing = ITEMMODS_GetByTimeAdjustment(statValueMaybe, preiodOfDay, baseTime, &pItemModPeriodOfDay, &itemModMin, &itemModMax);
            if (!*D2Client_pDWORD_6FBA7984)
            {
                timeAdjustmentThing = itemModMin;
            }
            
            auto v52 = (const wchar_t*)D2LANG_GetStringFromTblIndex(D2Client_pWORD_6FB6FA30[pItemModPeriodOfDay]);
            Unicode::strcat(outputBuffer256, v52);
            auto v53 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
            Unicode::strcat(outputBuffer256, v53);
            SStrPrintf(v97, 10, "%i", timeAdjustmentThing);
            Unicode::toUnicode(v95, v97, 9);
            if (timeAdjustmentThing < 0)
            {
                if (statValueMaybe < 0)
                {
                    Unicode::strcpy(v99, v95);
                }
            }
            else
            {
                Unicode::strcpy(v99, strPlusSign);
                Unicode::strcat(v99, v95);
            }
            if (nDescFunc == 18)
            {
                Unicode::strcat(v99, strPercentSign);
            }
            if (nDescVal == 1)
            {
                Unicode::strcat(outputBuffer256, v99);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (nDescVal != 2)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            Unicode::strcat(outputBuffer256, strDesc);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v99);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 19:
            Unicode::sprintf(256, outputBuffer256, strDesc, statValueMaybe);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 20:
        case 21:
            statValueMaybe = -statValueMaybe;
            SStrPrintf(v97, 10, "%i", statValueMaybe);
            Unicode::toUnicode(v95, v97, 9);
            if (nDescVal == 1)
            {
                if (statValueMaybe < 0)
                {
                    *outputBuffer256 = 0;
                    Unicode::strcat(outputBuffer256, v95);
                }
                else
                {
                    Unicode::strcpy(outputBuffer256, strPlusSign);
                    Unicode::strcat(outputBuffer256, v95);
                }

                Unicode::strcat(outputBuffer256, strPercentSign);
                Unicode::strcat(outputBuffer256, strSpace);
                v28 = strDesc;
                Unicode::strcat(outputBuffer256, v28);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            else
            {
                if (nDescVal != 2)
                {
                    Unicode::strcpy(outputBuffer256, strDesc);
                    return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
                }
                Unicode::strcpy(outputBuffer256, strDesc);
                Unicode::strcat(outputBuffer256, strSpace);
                if (statValueMaybe >= 0)
                {
                    Unicode::strcat(outputBuffer256, strPlusSign);
                }
                Unicode::strcat(outputBuffer256, v95);
                Unicode::strcat(outputBuffer256, strPercentSign);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
        case 22:
            if (nDescVal == 1)
            {
                if (statValueMaybe < 0)
                {
                    *outputBuffer256 = 0;
                }
                else
                {
                    Unicode::strcpy(outputBuffer256, strPlusSign);
                }

                Unicode::strcat(outputBuffer256, v95);
                Unicode::strcat(outputBuffer256, strPercentSign);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
            }
            else if (nDescVal == 2)
            {
                Unicode::strcpy(outputBuffer256, strDesc);
                Unicode::strcat(outputBuffer256, strSpace);
                if (statValueMaybe >= 0)
                {
                    Unicode::strcat(outputBuffer256, strPlusSign);
                }
                Unicode::strcat(outputBuffer256, v95);
                Unicode::strcat(outputBuffer256, strPercentSign);
            }
            else
            {
                Unicode::strcpy(outputBuffer256, strDesc);
            }
            if (charStatsTxtRecordIndex < 0 || charStatsTxtRecordIndex >= sgptDataTables->nMonPropTxtRecordCount)
            {
                v54 = sgptDataTables->pMonTypeTxt;
            }
            else
            {
                v54 = &sgptDataTables->pMonTypeTxt[charStatsTxtRecordIndex];
            }
            if (!v54)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            auto v55 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3997_colon);
            Unicode::strcat(outputBuffer256, v55);
            auto v56 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
            Unicode::strcat(outputBuffer256, v56);
            auto v28 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v54->wStrPlur);
            Unicode::strcat(outputBuffer256, v28);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 23:
            if (charStatsTxtRecordIndex < 0)
            {
                return 0;
            }
            if (charStatsTxtRecordIndex >= sgptDataTables->nMonStatsTxtRecordCount)
            {
                return 0;
            }
            v57 = &sgptDataTables->pMonStatsTxt[charStatsTxtRecordIndex];
            if (!v57)
            {
                return 0;
            }
            if (nDescVal == 1)
            {
                Unicode::strcpy(outputBuffer256, v95);
                Unicode::strcat(outputBuffer256, strPercentSign);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
            }
            else
            {
                Unicode::strcpy(outputBuffer256, strDesc);
                if (nDescVal == 2)
                {
                    Unicode::strcat(outputBuffer256, strSpace);
                    Unicode::strcat(outputBuffer256, v95);
                    Unicode::strcat(outputBuffer256, strPercentSign);
                }
            }
            auto v58 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
            Unicode::strcat(outputBuffer256, v58);
            auto v28 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v57->wNameStr);
            Unicode::strcat(outputBuffer256, v28);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 24:
            auto v59 = charStatsTxtRecordIndex >> sgptDataTables->nStuff;
            auto v92 = (charStatsTxtRecordIndex & sgptDataTables->nShiftedStuff);
            auto v96 = statValueMaybe >> 8;
            auto v60 = D2Client_sub_6FB0A440(v59, 0);
            auto v61 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v60);
            if (!v61)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }

            auto v62 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21249_ModStre10b);
            Unicode::strcat(outputBuffer256, v62);
            Unicode::strcat(outputBuffer256, strSpace);
            SStrPrintf(v97, 10, "%i", v92);
            Unicode::toUnicode(v95, v97, 9);
            Unicode::strcat(outputBuffer256, v95);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v61);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::sprintf(128, v99, strDesc, statValueMaybe, v96);
            Unicode::strcat(outputBuffer256, v99);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 25:
        case 26:
            if (statValueMaybe >= 0)
            {
                Unicode::strcpy(v99, v95);
            }
            else
            {
                Unicode::strcpy(v99, strPlusSign);
                Unicode::strcat(v99, v95);
            }

            if (nDescVal == 1)
            {
                Unicode::strcpy(outputBuffer256, v99);
                Unicode::strcat(outputBuffer256, strSpace);
                Unicode::strcat(outputBuffer256, strDesc);
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (nDescVal != 2)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            Unicode::strcpy(outputBuffer256, strDesc);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v99);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 27:
            auto v92 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4003_to);
            if (!v92)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (!statValueMaybe)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }

            auto v64 = D2Client_sub_6FB0A440(charStatsTxtRecordIndex, 0);
            auto v65 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v64);
            if (!v65)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (statValueMaybe <= 0)
            {
                Unicode::strcpy(outputBuffer256, v95);
            }
            else
            {
                Unicode::strcat(outputBuffer256, strPlusSign);
                Unicode::strcat(outputBuffer256, v95);
            }
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v92);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v65);
            Unicode::strcat(outputBuffer256, strSpace);

            int32_t playerClass = 7;
            if (!SKILLS_IsPlayerClassSkill(charStatsTxtRecordIndex, &playerClass))
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (playerClass < 0)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (playerClass >= 7)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (playerClass >= sgptDataTables->nCharStatsTxtRecordCount)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            
            auto charStatsTxt = &sgptDataTables->pCharStatsTxt[playerClass];
            if (!charStatsTxt)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            auto v28 = (const wchar_t*)D2LANG_GetStringFromTblIndex(charStatsTxt->wStrClassOnly);
            Unicode::strcat(outputBuffer256, v28);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        case 28:
            int32_t statVal = statValueMaybe;
            if (!statValueMaybe)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (charStatsTxtRecordIndex < 0)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            if (charStatsTxtRecordIndex >= sgptDataTables->nSkillsTxtRecordCount)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            
            auto pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[charStatsTxtRecordIndex];
            if (!pSkillsTxtRecord)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }

            D2SkillsTxt *v67 = pSkillsTxtRecord;
            D2UnitStrc* v68 = pItem;

            if (!pItem || pItem->dwUnitType)
            {
                v68 = D2Client_sub_6FB283D0();
                v67 = pSkillsTxtRecord;
            }

            int32_t classId = -1;
            if (v68)
            {
                classId = v68->dwClassId;
            }

            if (v67->nCharClass == classId && statValueMaybe > 3)
            {
                statVal = 3;
            }

            auto v92 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4003_to);
            if (!v92)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            auto v70 = D2Client_sub_6FB0A440(charStatsTxtRecordIndex, 0);
            auto v71 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v70);
            if (!v71)
            {
                return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
            }
            SStrPrintf(v97, 10, "%i", statVal);
            Unicode::toUnicode(v95, v97, 9);
            if (statVal <= 0)
            {
                Unicode::strcpy(outputBuffer256, v95);
            }
            else
            {
                Unicode::strcpy(outputBuffer256, strPlusSign);
                Unicode::strcat(outputBuffer256, v95);
            }
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v92);
            Unicode::strcat(outputBuffer256, strSpace);
            Unicode::strcat(outputBuffer256, v71);
            return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
        default:
            return 0;
        }

        return 0;
    }

    auto itemStatCostTxtIndex = sgptDataTables->nItemStatCostTxtRecordCount;
    while (--itemStatCostTxtIndex >= 0)
    {
        if (itemStatCostTxtIndex >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            nDescGrpFunc = 0;
            goto LABEL_37;
        }
        
        auto currentItemStatCostTxt = &sgptDataTables->pItemStatCostTxt[itemStatCostTxtIndex];
        if (!currentItemStatCostTxt)
        {
            nDescGrpFunc = 0;
            goto LABEL_37;
        }
        if (itemStatCostTxtForStat->wDescGrp != currentItemStatCostTxt->wDescGrp)
        {
            statValueMaybe = a5a;
            nDescGrpFunc = 1;
            if (nDescFunc)
            {
                goto LABEL_37;
            }

            return 0;
        }
        nDescFunc = itemStatCostTxtIndex == nStatId;
        auto v18 = D2Common_10466_STATLIST_GetStatValue(pStatList, itemStatCostTxtIndex, 0);
        auto v19 = currentItemStatCostTxt->nOp;
        if (v19 >= 2u && v19 <= 5u)
        {
            auto v20 = currentItemStatCostTxt->wOpBase;
            if (v20 >= sgptDataTables->nItemStatCostTxtRecordCount  || (itemStatCostTxtForStat = &sgptDataTables->pItemStatCostTxt[v20]) == 0)
            {
                if (a5a != 0)
                {
                    statValueMaybe = a5a;
                    nDescGrpFunc = 0;
                    goto LABEL_37;
                }
                statValueMaybe = a5a;
                nDescGrpFunc = 1;
                if (nDescFunc)
                {
                    goto LABEL_37;
                }

                return 0;
            }
            auto v22 = D2Client_sub_6FB283D0();
            v18 = (v18 * (STATLIST_UnitGetStatValue(v22, v20, 0) >> itemStatCostTxtForStat->nValShift)) >> currentItemStatCostTxt->nOpParam;
        }
        auto v21 = v18 >> currentItemStatCostTxt->nValShift;
        if (itemStatCostTxtIndex == 122 && pItem && pItem->dwUnitType == 4 && D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BLUNT))
        {
            v21 += 50;
        }

        if (a5a != v21)
        {
            statValueMaybe = a5a;
            nDescGrpFunc = 0;
            goto LABEL_37;
        }

        statValueMaybe = a5a;
    }

    nDescGrpFunc = 1;
    if (nDescFunc)
    {
        goto LABEL_37;
    }

    return 0;
}

int ESE_D2Client_sub_6FAF3460(int32_t* statValues, D2C_ItemStats nStatId, std::wstring& outBuff)
{
    wchar_t scratchpad[256] = { 0 };

    switch (nStatId)
    {
    case STAT_ITEM_MAXDAMAGE_PERCENT:
        return statValues[10];
    case STAT_ITEM_MINDAMAGE_PERCENT:
    {
        auto v26 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4001_percent);
        auto v38 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
        auto v37 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4002_plus);

        if (statValues[10])
        {
            auto v29 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_10023_strModEnhancedDamage);

            outBuff.append(v37);
            outBuff.append(std::to_wstring(statValues[6]));
            outBuff.append(v26);
            outBuff.append(v38);
            outBuff.append(v29);
            return 1;
        }
        return 0;
    }
    case STAT_MINDAMAGE:
    case STAT_MAXDAMAGE:
    case STAT_SECONDARY_MINDAMAGE:
        if (statValues[5])
        {
            return 1;
        }

        if (statValues[4])
        {
            if (*statValues < statValues[1])
            {
                statValues[5] = 1;
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3623_strModMinDamageRange);
                swprintf_s(scratchpad, fmt, *statValues, statValues[1]);
                outBuff.append(scratchpad);
                return 1;
            }
            statValues[5] = 0;
            statValues[4] = 0;
        }
        return 0;
    case STAT_SECONDARY_MAXDAMAGE:
        if (statValues[5])
        {
            return 1;
        }

        return statValues[4];
    case STAT_FIREMINDAM:
        if (statValues[28])
        {
            if (statValues[24] >= statValues[25])
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3612_strModFireDamage);
                swprintf_s(scratchpad, fmt, statValues[25]);
                outBuff.append(scratchpad);
                return 1;
            }
            else
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3613_strModFireDamageRange);
                swprintf_s(scratchpad, fmt, statValues[24], statValues[25]);
                outBuff.append(scratchpad);
                return 1;
            }
        }
        return 0;
    case STAT_FIREMAXDAM:
        return statValues[28];
    case STAT_LIGHTMINDAM:
        if (statValues[22])
        {
            if (statValues[18] >= statValues[19])
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3616_strModLightningDamage);
                swprintf_s(scratchpad, fmt, statValues[19]);
                outBuff.append(scratchpad);
                return 1;
            }
            else
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3617_strModLightningDamageRange);
                swprintf_s(scratchpad, fmt, statValues[18], statValues[19]);
                outBuff.append(scratchpad);
                return 1;
            }
        }
        return 0;
    case STAT_LIGHTMAXDAM:
        return statValues[22];
    case STAT_MAGICMINDAM:
        if (statValues[40])
        {
            if (statValues[36] < statValues[37])
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3619_strModMagicDamageRange);
                swprintf_s(scratchpad, fmt, statValues[36], statValues[37]);
                outBuff.append(scratchpad);
                return 1;
            }
            else
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3618_strModMagicDamage);
                swprintf_s(scratchpad, fmt, statValues[37]);
                outBuff.append(scratchpad);
                return 1;
            }
        }
        return 0;
    case STAT_MAGICMAXDAM:
        return statValues[40];
    case STAT_COLDMINDAM:
        if (statValues[16])
        {
            if (statValues[12] < statValues[13])
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3615_strModColdDamageRange);
                swprintf_s(scratchpad, fmt, statValues[12], statValues[13]);
                outBuff.append(scratchpad);
                return 1;
            }
            else
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3614_strModColdDamage);
                swprintf_s(scratchpad, fmt, statValues[13]);
                outBuff.append(scratchpad);
                return 1;
            }
        }
        return 0;
    case STAT_COLDMAXDAM:
        return statValues[16];
    case STAT_POISONMINDAM:
        if (statValues[34])
        {
            if (statValues[33] <= 0)
            {
                statValues[33] = 1;
            }

            int32_t v20 = statValues[32] / statValues[33];
            statValues[32] = v20;
            int32_t v21 = (v20 * statValues[30] + 128) >> 8;
            int32_t v22 = (v20 * statValues[31] + 128) >> 8;
            int32_t v36 = v20 / 25;
            statValues[30] = v21;
            statValues[31] = v22;

            if (v21 < v22)
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3621_strModPoisonDamageRange);
                swprintf_s(scratchpad, fmt, v21, v22, v36);
                outBuff.append(scratchpad);
                return 1;
            }
            else
            {
                auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3620_strModPoisonDamage);
                swprintf_s(scratchpad, fmt, v22, v36);
                outBuff.append(scratchpad);
                return 1;
            }
        }
        return 0;
    case STAT_POISONMAXDAM:
    case STAT_POISONLENGTH:
        return statValues[34];
    }

    return 0;
}

void ESE_D2Client_sub_6FAF12C0(std::wstring& outBuff)
{
    auto strPlus = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4002_plus);
    auto strNewline = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    auto strPercent = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4001_percent);

    outBuff.append(strPlus);
    outBuff.append(std::to_wstring(50));
    outBuff.append(strPercent);
    outBuff.append(strSpace);
    auto v9 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3554_ModStr4f);
    outBuff.append(v9);
    outBuff.append(strNewline);
}

void ESE_D2Client_GetItemTextLinePropertiesInternal_6FAF19C0(D2UnitStrc* pUnit, std::wstring& outBuff, int outBuffMaxLen, int bUnknownFlag1, int unitState, int nUnitState, int nUnitFlags, int bUnknownFlag2)
{
    auto strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    auto strComma = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3852_KeyComma);

    if (ITEMS_GetItemType(pUnit) != ITEMTYPE_ELIXIR)
    {
        auto v20 = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, unitState, nUnitFlags);
        if (!v20)
        {
            return;
        }

        D2StatListStrc* pStatList = nullptr;

        if (pUnit)
        {
            pStatList = STATLIST_AllocStatList(pUnit->pMemoryPool, 0, 0, pUnit->dwUnitType, pUnit->dwUnitId);
        }
        else
        {
            pStatList = STATLIST_AllocStatList(0, 0, 0, 6, -1);
        }

        STATLIST_MergeBaseStats(pStatList, v20);
        if (nUnitState)
        {
            auto baseStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, nUnitState, nUnitFlags);
            if (baseStatList)
            {
                STATLIST_MergeBaseStats(pStatList, baseStatList);
            }
        }

        if (pUnit)
        {
            if (pUnit->dwUnitType == 4)
            {
                if (pUnit->pInventory)
                {
                    auto childItem = INVENTORY_GetFirstItem(pUnit->pInventory);
                    while (childItem)
                    {
                        auto childItem1 = INVENTORY_UnitIsItem(childItem);
                        if (!childItem1)
                        {
                            break;
                        }

                        childItem = INVENTORY_GetNextItem(childItem);

                        auto childStatList = STATLIST_GetStatListFromUnitStateAndFlag(childItem1, unitState, nUnitFlags);
                        if (childStatList)
                        {
                            STATLIST_MergeBaseStats(pStatList, childStatList);
                        }
                    }
                }
            }
        }

        if (bUnknownFlag1 && D2Common_10731_ITEMS_CheckItemTypeId(pUnit, ITEMTYPE_BLUNT) && !STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0))
        {
            ESE_D2Client_sub_6FAF12C0(outBuff);
        }

        int32_t statValues[42];
        memset(statValues, 0, sizeof(statValues));

        if (D2Client_pDWORD_6FB7A438 > 0)
        {
            auto v45 = D2Client_pDWORD_6FB79B48;
            auto v29 = 0;
            do
            {
                switch (*v45)
                {
                case STAT_ITEM_MAXDAMAGE_PERCENT:
                    statValues[7] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_ITEM_MINDAMAGE_PERCENT:
                    statValues[6] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_MINDAMAGE:
                    statValues[0] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    if (!statValues[0])
                    {
                        statValues[0] = D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_SECONDARY_MINDAMAGE, 0);
                    }
                    break;
                case STAT_MAXDAMAGE:
                    statValues[1] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    if (!statValues[1])
                        statValues[1] = D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_SECONDARY_MAXDAMAGE, 0);
                    break;
                case STAT_FIREMINDAM:
                    statValues[24] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_FIREMAXDAM:
                    statValues[25] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_LIGHTMINDAM:
                    statValues[18] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_LIGHTMAXDAM:
                    statValues[19] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_MAGICMINDAM:
                    statValues[36] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_MAGICMAXDAM:
                    statValues[37] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_COLDMINDAM:
                    statValues[12] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_COLDMAXDAM:
                    statValues[13] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_POISONMINDAM:
                    statValues[30] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_POISONMAXDAM:
                    statValues[31] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    break;
                case STAT_POISONLENGTH:
                    statValues[32] = D2Common_10466_STATLIST_GetStatValue(pStatList, *v45, 0);
                    statValues[33] = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
                    break;
                default:
                    break;
                }

                ++v29;
                v45 += 4;
            } while (v29 < *D2Client_pDWORD_6FB7A438);
        }

        auto pStatValues = &statValues[1];
        auto v32 = 7;
        do
        {
            if (*(pStatValues - 1) > 0 && *pStatValues > 0)
            {
                pStatValues[3] = 1;
            }

            pStatValues += 6;
            --v32;
        } while (v32);

        auto v48 = 0;
        auto v50 = 0;
        if (sgptDataTables->nStatsWithDescFunc <= 0)
        {
        LABEL_106:
            if (pUnit)
            {
                if (pUnit->dwUnitType == 4)
                {
                    auto itemTxtRecord1 = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
                    if (!itemTxtRecord1->nNoDurability
                        && itemTxtRecord1->nDurability
                        && STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_INDESCTRUCTIBLE, 0) <= 0
                        && !STATLIST_GetMaxDurabilityFromUnit(pUnit))
                    {
                        auto strIndestructable = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21240_ModStre9s);
                        if (v48 && !bUnknownFlag2)
                        {
                            outBuff.append(strComma);
                            outBuff.append(strSpace);
                        }
                        outBuff.append(strIndestructable);
                        if (bUnknownFlag2)
                        {
                            outBuff.append(strNewLine);
                        }
                    }
                }
            }
            STATLIST_FreeStatList(pStatList);
            return;
        }

        int32_t v34 = 0;
        int32_t nCopiedStats = 0;

        D2StatStrc d2StatStrcBuffer[511];
        int32_t nStatId = 0;
        while (1)
        {
            nStatId = sgptDataTables->pStatsWithDescFunc[v34];
            if (nStatId >= STAT_STRENGTH && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
            {
                nCopiedStats = D2Common_11269_CopyStats((D2StatListExStrc*)pStatList, nStatId, d2StatStrcBuffer, std::size(d2StatStrcBuffer));
                if (nCopiedStats > 0)
                {
                    break;
                }
            }
        LABEL_105:
            v50 = ++v34;
            if (v34 >= sgptDataTables->nStatsWithDescFunc)
            {
                goto LABEL_106;
            }
        }

        int32_t v37 = 0;
        int32_t v46 = 0;
        while (1)
        {
            wchar_t propertyLineBuffer256[1024] = { 0 };

            if (
                d2StatStrcBuffer[v37].nValue &&
                !ESE_D2Client_sub_6FAF3460(statValues, (D2C_ItemStats)nStatId, outBuff) &&
                D2Client_GetItemPropertyLine_6FAF21C0(pUnit, pStatList, nStatId, d2StatStrcBuffer[v37].nStat, d2StatStrcBuffer[v37].nValue, (Unicode*)propertyLineBuffer256))
            {
                int32_t statValue = 0;
                if (nStatId == STAT_SECONDARY_MINDAMAGE)
                {
                    statValue = D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_MINDAMAGE, 0);
                }
                else
                {
                    if (nStatId != STAT_SECONDARY_MAXDAMAGE)
                    {
                        goto LABEL_96;
                    }

                    statValue = D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_MAXDAMAGE, 0);
                }
                if (!statValue)
                {
                LABEL_96:

                    if (!v48 || bUnknownFlag2)
                    {
                    }
                    else
                    {
                        outBuff.append(strComma);
                        outBuff.append(strSpace);
                    }
                    v48 = 1;

                    outBuff.append(propertyLineBuffer256);
                    if (bUnknownFlag2)
                    {
                        outBuff.append(strNewLine);
                    }

                    goto LABEL_103;
                }
            }
        LABEL_103:
            v37 = ++v46;
            if (v46 >= nCopiedStats)
            {
                v34 = v50;
                goto LABEL_105;
            }
        }
    }

    auto v49 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    auto v51 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    auto v53 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4002_plus);
    auto v56 = ITEMS_GetFileIndex(pUnit);
    auto v47 = 0;
    if (*D2Client_pDWORD_6FB7A4A0)
    {
        int32_t* i = nullptr;
        for (i = D2Client_pDWORD_6FB7A440; *i != v56; i += 16)
        {
        LABEL_32:
            if (++v47 >= *D2Client_pDWORD_6FB7A4A0)
            {
                return;
            }
        }

        auto v16 = STATLIST_UnitGetStatValue(pUnit, STAT_VALUE, 0);

        if (*i == 8 || *i == 9)
        {
            v16 >>= 8;
        }
        if (*i == 6 || *i == 7)
        {
            v16 >>= 8;
        }
        if (*i == 10 || *i == 11)
        {
            v16 >>= 8;
        }

        int32_t v19 = 0;
        if (v16 <= 0)
        {
            if (v16 >= 0)
            {
                goto LABEL_25;
            }

            v19 = *(i + 5);
        }
        else
        {
            v19 = *(i + 4);
        }

        auto v18 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v19);
    LABEL_25:
        if (v16)
        {
            if (*(i + 1) != 1)
            {
                FOG_DisplayAssert("0", __FILE__, __LINE__);
                exit(-1);
            }

            if (*(i + 3) != 2)
            {
                FOG_DisplayAssert("0", __FILE__, __LINE__);
                exit(-1);
            }

            outBuff.append(v18);
            outBuff.append(v51);

            if (v16 <= 0)
            {
                outBuff.append(std::to_wstring(v16));
            }
            else
            {
                outBuff.append(v53);
                outBuff.append(std::to_wstring(v16));
            }

            outBuff.append(v49);
        }
        goto LABEL_32;
    }
}

void ESE_D2Client_GetItemTextLineProperties_6FAF3160(D2UnitStrc* pItem, std::wstring& outBuff, int maxLen, int bFlag, const std::wstring* existingContents)
{
    wchar_t scratchpad[8192] = {};
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    const wchar_t* strComma = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3852_KeyComma);

    // STATE_RUNEWORD and UNITFLAG_SKSRVDOFUNC may not be the correct names/enums. 171 and 64
    //D2Client_GetItemTextLinePropertiesInternal_6FAF19C0(pItem, (Unicode *)scratchpad, std::size(scratchpad), 1, 0, STATE_RUNEWORD, UNITFLAG_SKSRVDOFUNC, bFlag);
    //std::wstring propertiesBuff(scratchpad);

    std::wstring propertiesBuff;
    ESE_D2Client_GetItemTextLinePropertiesInternal_6FAF19C0(pItem, propertiesBuff, std::size(scratchpad), 1, 0, STATE_RUNEWORD, UNITFLAG_SKSRVDOFUNC, bFlag);

    if (existingContents != nullptr && propertiesBuff.length() != 0)
    {
        size_t newlinePosition = propertiesBuff.find_last_of(strNewLine, 0);
        if (newlinePosition != std::wstring::npos)
        {
            outBuff.append(propertiesBuff.substr(0, newlinePosition));
            outBuff.append(strNewLine);
            outBuff.append(*existingContents);
            outBuff.append(propertiesBuff.substr(newlinePosition + 1));
            outBuff.append(strComma);
            outBuff.append(strNewLine);
        }
        else
        {
            outBuff.append(*existingContents);
            outBuff.append(propertiesBuff);
        }
    }
    else
    {
        outBuff.append(propertiesBuff);
    }
}

void __fastcall ESE_UI_INV_DrawMouseOverItemFrame(D2UnitStrc* pItemMaybe, int32_t bFlag)
{
    std::wstring itemDescription;
    itemDescription.reserve(4096);
    wchar_t scratchpad[8192] = { 0 };

    auto pItemUnderCursor = *D2Client_pItemUnderCursor_6FBB58F0;

    auto strNewline_1 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    D2UnitStrc* v229 = pItemMaybe;
    if (bFlag && D2Client_sub_6FB283D0())
    {
        v229 = D2Client_sub_6FB283D0();
    }

    if (!D2Client_sub_6FAFE9E0())
    {
        if (D2Client_sub_6FB23230(36))
        {
            auto v48 = *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 - 63;
            auto v49 = *D2Client_pDWORD_6FBBA748 + 272;
            auto v50 = D2Client_sub_6FB57BC0();
            auto v51 = D2Client_sub_6FB57BD0();
            if (v50 >= v49 && v50 <= v49 + 32 && v51 >= v48 - 32 && v51 <= v48)
            {
                auto v220 = *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 - 98;
                auto v52 = *D2Client_pDWORD_6FBBA748 + 287;
                auto v53 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4144_strClose);
                D2Win_10129_DrawFramedText((Unicode*)v53, v52, v220, 0, 1);
            }
        }
        if (!D2Client_sub_6FB23230(1)
            && !D2Client_sub_6FB23230(23)
            && !D2Client_sub_6FB23230(25)
            && !D2Client_sub_6FB23230(12)
            && !D2Client_sub_6FB23230(14)
            && !D2Client_sub_6FB23230(26))
        {
            goto LABEL_97;
        }
        auto v54 = *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 - 64;
        auto v55 = *D2Client_pDWORD_6FB740EC - *D2Client_pDWORD_6FBBA748 - 302;
        auto v56 = D2Client_sub_6FB57BC0();
        auto v57 = D2Client_sub_6FB57BD0();
        if (v56 >= v55 && v56 <= v55 + 32 && v57 >= v54 - 32 && v57 <= v54)
        {
            auto v221 = *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 - 99;
            auto v58 = *D2Client_pDWORD_6FB740EC - *D2Client_pDWORD_6FBBA748 - 287;
            auto v59 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4144_strClose);
            D2Win_10129_DrawFramedText((Unicode*)v59, v58, v221, 0, 1);
        }
        auto v60 = *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 - 69;
        auto v61 = *D2Client_pDWORD_6FB740EC - *D2Client_pDWORD_6FBBA748 - 237;
        auto v62 = D2Client_sub_6FB57BC0();
        auto v63 = D2Client_sub_6FB57BD0();
        if (v62 >= v61 && v62 <= v61 + 20 && v63 >= v60 - 18 && v63 <= v60 && !D2Client_sub_6FAFC0E0())
        {
            auto v64 = 4125;
            switch (*D2Client_pDWORD_6FBB58EC)
            {
            case 1:
                v64 = 4099;
                break;
            case 11:
                v64 = 4129;
                break;
            case 12:
            case 13:
            case 15:
                v64 = 4126;
                break;
            default:
                break;
            }
            auto v222 = *D2Client_pDWORD_6FBBA74C + *D2Client_pDWORD_6FB740F0 - 89;
            auto v65 = *D2Client_pDWORD_6FB740EC - *D2Client_pDWORD_6FBBA748 - 222;
            auto v66 = (wchar_t*)D2LANG_GetStringFromTblIndex(v64);
            D2Win_10129_DrawFramedText((Unicode*)v66, v65, v222, 0, 1);
        }

        auto isExpansion = FOG_IsExpansion();
        auto is6FAAC080 = D2Client_sub_6FAAC080();

        auto v67 = D2Client_sub_6FB57BD0();
        auto v68 = D2Client_sub_6FB57BC0();
        auto cmp1 = (v68 < *D2Client_pDWORD_6FBB59BC)
            || v68 > *D2Client_pDWORD_6FBB59C0
            || v67 < *D2Client_pDWORD_6FBB59C4 - 24
            || v67 >= *D2Client_pDWORD_6FBB59C4;

        auto cmp2 = v68 < *D2Client_pDWORD_6FBB59A8 || v68 > *D2Client_pDWORD_6FBB59AC ||
            v67 < *D2Client_pDWORD_6FBB59B0 - 24 || v67 >= *D2Client_pDWORD_6FBB59B0;

        if (!isExpansion || !is6FAAC080 || cmp1 && cmp2)
        {
            goto LABEL_97;
        }

        auto v73 = 0;
        auto v71 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_22726_Cfgswapweapons);

        itemDescription.append(v71);
        if (D2Client_sub_6FAD4B60(44, 1) == 0xFFFF)
        {
            if (D2Client_sub_6FAD4B60(44, 0) == 0xFFFF)
            {
                auto v76 = 368;
                if (D2Client_sub_6FB57BC0() > *D2Client_pDWORD_6FBBA748 + 500)
                {
                    v76 = 600;
                }

                D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), v76 + *D2Client_pDWORD_6FBBA748, 21 - *D2Client_pDWORD_6FBBA74C, 0, 1);
                goto LABEL_97;
            }
            auto v74 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3997_colon);
            itemDescription.append(v74);
            v73 = 0;
        }
        else
        {
            auto v72 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3997_colon);
            itemDescription.append(v72);
            v73 = 1;
        }
        auto v75 = (wchar_t*)D2Client_sub_6FAD56B0(44, v73);
        itemDescription.append(v75);
        auto v76 = 368;
        if (D2Client_sub_6FB57BC0() > *D2Client_pDWORD_6FBBA748 + 500)
        {
            v76 = 600;
        }

        D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), v76 + *D2Client_pDWORD_6FBBA748, 21 - *D2Client_pDWORD_6FBBA74C, 0, 1);
    }
LABEL_97:
    if (!*D2Client_pDWORD_6FBB58E4 && !*D2Client_pDWORD_6FBB58E0)
    {
        return;
    }

    if (!pItemUnderCursor)
    {
        return;
    }

    if (!pItemMaybe->pInventory)
    {
        return;
    }

    if (INVENTORY_GetCursorItem(pItemMaybe->pInventory))
    {
        return;
    }

    if (!D2Client_sub_6FB23230(23)
        && pItemMaybe->pInventory
        && pItemUnderCursor
        && !INVENTORY_CompareWithItemsParentInventory(pItemMaybe->pInventory, pItemUnderCursor))
    {
        return;
    }

    if (*D2Client_pDWORD_6FBB58E0 && !*D2Client_pDWORD_6FB7928C && D2Client_sub_6FAFC130() && *D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
    {
        itemDescription.clear();

        scratchpad[0] = 0;
        D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
        auto strUnidentified = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3455_ItemStats1b);
        itemDescription.append(strUnidentified);
        itemDescription.append(strNewline_1);

        int32_t v79 = 0;
        switch (ITEMS_GetItemType(pItemUnderCursor))
        {
        case ITEMTYPE_AMAZON_ITEM:
        case ITEMTYPE_AMAZON_BOW:
        case ITEMTYPE_AMAZON_SPEAR:
        case ITEMTYPE_AMAZON_JAVELIN:
            v79 = STR_IDX_10917_AmaOnly;
            break;
        case ITEMTYPE_BARBARIAN_ITEM:
        case ITEMTYPE_PRIMAL_HELM:
            v79 = STR_IDX_10921_BarOnly;
            break;
        case ITEMTYPE_NECROMANCER_ITEM:
        case ITEMTYPE_VOODOO_HEADS:
            v79 = STR_IDX_10919_NecOnly;
            break;
        case ITEMTYPE_PALADIN_ITEM:
        case ITEMTYPE_AURIC_SHIELDS:
            v79 = STR_IDX_10920_PalOnly;
            break;
        case ITEMTYPE_SORCERESS_ITEM:
        case ITEMTYPE_ORB:
            v79 = STR_IDX_10918_SorOnly;
            break;
        case ITEMTYPE_ASSASSIN_ITEM:
        case ITEMTYPE_HAND_TO_HAND:
        case ITEMTYPE_HAND_TO_HAND_2:
            v79 = STR_IDX_10923_AssOnly;
            break;
        case ITEMTYPE_DRUID_ITEM:
        case ITEMTYPE_PELT:
        case ITEMTYPE_CLOAK:
            v79 = STR_IDX_10922_DruOnly;
            break;
        default:
            break;
        }

        if (v79 > 0)
        {
            auto v80 = (wchar_t*)D2LANG_GetStringFromTblIndex(v79);
            itemDescription.append(v80);
            itemDescription.append(strNewline_1);
        }

        itemDescription.append(scratchpad);
        ColorizeString(itemDescription, 0);

        scratchpad[0] = 0;
        D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode*)itemDescription.c_str(), (Unicode*)scratchpad);

        int32_t nWidth = 0;
        int32_t nHeight = 0;
        D2Win_10131_GetTextDimensions((const Unicode*)itemDescription.c_str(), &nWidth, &nHeight);

        if (*D2Client_pDWORD_6FB79294 - nHeight > 0)
        {
            D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 1);
            return;
        }
        auto v120 = (*D2Client_pDWORD_6FB7929C + nHeight);
        D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79298, v120, 0, 1);
        return;
    }

    auto itemQuality = ITEMS_GetItemQuality(pItemUnderCursor);
    if (D2Client_sub_6FB57CC0() == 8 || ITEMS_GetTransmogrify(pItemUnderCursor))
    {
        itemDescription.clear();

        auto v209 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
        if (!ITEMS_GetTransmogrify(pItemUnderCursor))
        {
            return;
        }

        int32_t itemClassId = -1;
        if (pItemUnderCursor)
        {
            itemClassId = pItemUnderCursor->dwClassId;
        }

        auto ptOldItemStats = DATATBLS_GetItemsTxtRecord(itemClassId);
        if (!ptOldItemStats)
        {
            FOG_DisplayAssert("ptOldItemStats", __FILE__, __LINE__);
            exit(-1);
        }

        int32_t unused_ItemId = 0;
        auto ptNewItemStats = DATATBLS_GetItemRecordFromItemCode(ptOldItemStats->dwTransmogrifyType, &unused_ItemId);
        if (!ptNewItemStats)
        {
            FOG_DisplayAssert("ptNewItemStats", __FILE__, __LINE__);
            exit(-1);
        }

        auto v213 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5387_convertsto);
        itemDescription.append(v213);
        auto v214 = (wchar_t*)D2LANG_GetStringFromTblIndex(ptNewItemStats->wNameStr);
        itemDescription.append(v214);
        itemDescription.append(v209);
        auto v215 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5387_convertsto);
        itemDescription.append(v215);
        itemDescription.append(v209);

        scratchpad[0] = 0;
        D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
        itemDescription.append(scratchpad);

        if (*D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
        {
            scratchpad[0] = 0;
            D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode*)itemDescription.c_str(), (Unicode*)scratchpad);
            itemDescription = std::wstring(scratchpad);
        }

        int32_t height = 0;
        int32_t width = 0;
        D2Win_10131_GetTextDimensions((const Unicode*)itemDescription.c_str(), &height, &width);

        if (*D2Client_pDWORD_6FB79294 - width > 0)
        {
            D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 0);
            return;
        }

        D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79298, width + *D2Client_pDWORD_6FB7929C, 0, 0);
        return;
    }

    if (itemQuality != ITEMQUAL_SET || !ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_IDENTIFIED, __LINE__, __FILE__))
    {
        itemDescription.clear();

        int32_t colorCode = 0;
        int32_t colorCode2 = 0;
        int32_t colorCode3 = 0;
        int32_t colorCode245 = 0;

        if (ITEMS_GetItemType(pItemUnderCursor) == ITEMTYPE_BOOK)
        {
            auto v126 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
            if (!pItemUnderCursor || ITEMS_GetItemType(pItemUnderCursor) != ITEMTYPE_BOOK)
            {
                FOG_DisplayAssert("sghSelItem && ITEMSGetType(sghSelItem) == ITEMTYPE_BOOK", __FILE__, __LINE__);
                exit(-1);
            }

            int32_t itemClassId = -1;
            if (pItemUnderCursor)
            {
                itemClassId = pItemUnderCursor->dwClassId;
            }

            auto pItemTxtRecord = DATATBLS_GetItemsTxtRecord(itemClassId);
            if (!pItemTxtRecord)
            {
                FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
                exit(-1);
            }

            scratchpad[0] = 0;
            D2Client_sub_6FAE54B0(pItemUnderCursor, (Unicode*)scratchpad, pItemTxtRecord);
            if (!*D2Client_pDWORD_6FBB58EC)
            {
                auto v129 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2203_RightClicktoUse);
                itemDescription.append(v129);
                itemDescription.append(v126);

                auto v130 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2206_InsertScrolls);
                itemDescription.append(v130);
                itemDescription.append(v126);
            }

            scratchpad[0] = 0;
            D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
            itemDescription.append(scratchpad);

            if (*D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
            {
                scratchpad[0] = 0;
                D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode*)itemDescription.c_str(), (Unicode*)scratchpad);
                itemDescription = std::wstring(scratchpad);
            }

            int32_t height = 0;
            int32_t width = 0;
            D2Win_10131_GetTextDimensions((const Unicode*)itemDescription.c_str(), &width, &height);

            if (*D2Client_pDWORD_6FB79294 - height > 0)
            {
                D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 0);
                return;
            }

            auto v120 = height + *D2Client_pDWORD_6FB7929C;
            D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79298, v120, 0, 0);
            return;
        }

        std::wstring statLine_ClassRestriction_512;
        auto v132 = ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor);
        if (v132 != PCLASS_EVILFORCE)
        {
            auto v134 = (wchar_t*)D2LANG_GetStringFromTblIndex(v132 + 10917);
            statLine_ClassRestriction_512.append(v134);
            statLine_ClassRestriction_512.append(strNewline_1);

            auto v135 = v229 ? v229->dwClassId : -1;

            if (v135 != v132)
            {
                colorCode = 1;
            }
        }

        int32_t dwClassId_1 = -1;
        if (pItemUnderCursor)
        {
            dwClassId_1 = pItemUnderCursor->dwClassId;
        }

        auto itemTxtRecord = DATATBLS_GetItemsTxtRecord(dwClassId_1);
        if (!itemTxtRecord)
        {
            FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
            exit(-1);
        }

        std::wstring statLine_Durability_512;
        if (ITEMS_GetQuiverType(pItemUnderCursor))
        {
            auto strSpace2 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
            auto strNewline2 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
            if (STATLIST_UnitGetStatValue(pItemUnderCursor, STAT_QUANTITY, 0) > 0)
            {
                // TODO: This is going to be wiped out later with a strcpy to itemDescription...
                auto v143 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3462_ItemStats1i);
                itemDescription.append(v143);

                auto itemQuantity = STATLIST_UnitGetStatValue(pItemUnderCursor, STAT_QUANTITY, 0);
                itemDescription.append(strSpace2);
                itemDescription.append(std::to_wstring(itemQuantity));
                itemDescription.append(strNewline2);

                auto v145 = (wchar_t*)D2LANG_GetStringFromTblIndex(itemTxtRecord->wNameStr);
                itemDescription.append(v145);
            }
        }
        else
        {
            scratchpad[0] = 0;
            D2Client_GetItemTextLineDurability_6FAE4060(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
            statLine_Durability_512.append(scratchpad);
        }

        BOOL bRequiresDex = false;
        BOOL bRequiresStr = false;
        BOOL bRequiresLevel = false;

        std::wstring statLine_RequiredLevel512;
        ITEMS_CheckRequirements(pItemUnderCursor, v229, 0, &bRequiresStr, &bRequiresDex, &bRequiresLevel);
        if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_IDENTIFIED, __LINE__, __FILE__))
        {
            auto levelRequirement = ITEMS_GetLevelRequirement(pItemUnderCursor, v229);
            if (levelRequirement > 1)
            {
                if (!bRequiresLevel)
                {
                    colorCode245 = 1;
                }

                auto strSpace = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
                auto strNewline = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
                auto strRequiredLevel = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3469_ItemStats1p);

                statLine_RequiredLevel512.append(strRequiredLevel);
                statLine_RequiredLevel512.append(strSpace);
                statLine_RequiredLevel512.append(std::to_wstring(levelRequirement));
                statLine_RequiredLevel512.append(strNewline);
            }
        }

        std::wstring statLine_RuneGemStats_512;
        if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_SOCKET_FILLER))
        {
            auto v152 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
            if (!D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_SOCKET_FILLER))
            {
                FOG_DisplayAssert("ITEMSIsA(sghSelItem, ITEMTYPE_SOCKETFILLER_TYPE)", __FILE__, __LINE__);
                exit(-1);
            }
            scratchpad[0] = 0;
            D2Client_GetItemTextLineRuneGemStats_6FAF1480(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
            auto v153 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11080_ExInsertSocketsX);
            statLine_RuneGemStats_512.append(v153);
            statLine_RuneGemStats_512.append(v152);
        }

        std::wstring statLine_RunewordName_512;
        if (ITEMS_CheckIfSocketable(pItemUnderCursor))
        {
            if (pItemUnderCursor->pInventory)
            {
                auto v241 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
                auto v157 = INVENTORY_GetFirstItem(pItemUnderCursor->pInventory);
                if (v157)
                {

                    auto v158 = 0;
                    do
                    {
                        auto v159 = INVENTORY_UnitIsItem(v157);
                        if (!v159)
                        {
                            break;
                        }

                        if (D2Common_10731_ITEMS_CheckItemTypeId(v159, ITEMTYPE_RUNE))
                        {
                            auto v161 = DATATBLS_GetItemsTxtRecord(v159->dwClassId)->dwGemOffset;
                            if (v161 > 0)
                            {
                                auto v162 = DATATBLS_GetGemsTxtRecord(v161);
                                if (v162)
                                {
                                    if (!v158)
                                    {
                                        v158 = 1;
                                        auto v163 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_20506_RuneQuote);
                                        statLine_RunewordName_512.append(v163);
                                    }

                                    AppendString(statLine_RunewordName_512, v162->szLetter);
                                }
                            }
                        }
                        v157 = INVENTORY_GetNextItem(v157);
                    } while (v157);
                    if (v158)
                    {
                        AppendString(statLine_RunewordName_512, "'");
                        statLine_RunewordName_512.append(v241);
                    }
                }
            }
        }

        std::wstring statLine_CharmKeepInInv_512;
        if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_CHARM))
        {
            auto v164 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
            auto v165 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_20438_Charmdes);
            statLine_CharmKeepInInv_512.append(v165);
            statLine_CharmKeepInInv_512.append(v164);
        }

        std::wstring statLine_Socketed_512;
        std::wstring statLine_RequiredDexterity_256;
        std::wstring statLine_RequiredStength_256;
        std::wstring statLine_Damage_512;
        std::wstring statLine_AttackSpeed_2048;
        std::wstring statLine_blockChance_512;
        std::wstring statLine_v273_512;
        std::wstring statLine_Defense_512;

        if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_WEAPON)
            || D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR))
        {
            scratchpad[0] = 0;
            D2Client_GetItemTextSocketed_6FAE3EE0(pItemUnderCursor, (Unicode*)scratchpad);
            statLine_Socketed_512.append(scratchpad);

            auto v166 = 0;
            auto v167 = 0;
            auto v168 = STATLIST_UnitGetItemStatOrSkillStatValue(pItemUnderCursor, STAT_ITEM_REQ_PERCENT, 0);

            if (v168)
            {
                v167 = DATATBLS_ApplyRatio(v168, itemTxtRecord->wReqStr, 100);
                v166 = DATATBLS_ApplyRatio(v168, itemTxtRecord->wReqDex, 100);
            }

            if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_ETHEREAL, __LINE__, __FILE__))
            {
                v167 -= 10;
                v166 -= 10;
            }

            if (itemTxtRecord->wReqDex)
            {
                if (!bRequiresDex)
                {
                    colorCode2 = 1;
                }

                auto v237 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
                auto v241 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
                auto v171 = v166 + itemTxtRecord->wReqDex;
                if (v171 > 0)
                {
                    auto v172 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3459_ItemStats1f);
                    statLine_RequiredDexterity_256.append(v172);
                    statLine_RequiredDexterity_256.append(v237);
                    statLine_RequiredDexterity_256.append(std::to_wstring(v171));
                    statLine_RequiredDexterity_256.append(v241);
                }
                else
                {
                    statLine_RequiredDexterity_256[0] = 0;
                }
            }
            if (itemTxtRecord->wReqStr)
            {
                if (!bRequiresStr)
                {
                    colorCode3 = 1;
                }

                auto v174 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
                auto v238 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
                auto v175 = v167 + itemTxtRecord->wReqStr;
                if (v175 > 0)
                {
                    auto v176 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3458_ItemStats1e);
                    statLine_RequiredStength_256.append(v176);
                    statLine_RequiredStength_256.append(v174);
                    statLine_RequiredStength_256.append(std::to_wstring(v175));
                    statLine_RequiredStength_256.append(v238);
                }
            }


            if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_WEAPON))
            {
                if (STATLIST_GetMinDamageFromUnit(pItemUnderCursor, 0) >= 0
                    && STATLIST_GetMaxDamageFromUnit(pItemUnderCursor, 0) >= 0)
                {
                    scratchpad[0] = 0;
                    D2Client_GetItemTextLineDamage_6FAE43D0(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
                    statLine_Damage_512.append(scratchpad);
                }
                scratchpad[0] = 0;
                D2Client_GetItemTextLineAttackSpeed_6FAE5570(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
                statLine_AttackSpeed_2048.append(scratchpad);
            }
            if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_SHIELD))
            {
                if (v229
                    && v229->dwClassId == 3
                    && (!ITEMS_IsClassValid(pItemUnderCursor)
                        || ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor) == PCLASS_PALADIN))
                {
                    scratchpad[0] = 0;
                    D2Client_GetItemTextLineUnknownA_6FAE5040(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
                    statLine_v273_512.append(scratchpad);
                }
                scratchpad[0] = 0;
                D2Client_GetItemTextLineBlockChance_6FAE4EE0(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
                statLine_blockChance_512.append(scratchpad);

            }
            else if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_BOOTS) && v229 && v229->dwClassId == 6)
            {
                scratchpad[0] = 0;
                D2Client_GetItemTextLineUnknownA_6FAE5040(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
                statLine_v273_512.append(scratchpad);
            }
            if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR)
                && STATLIST_GetDefenseFromUnit(pItemUnderCursor) > 0)
            {
                // TODO: This is a shady call, investigate it
                scratchpad[0] = 0;
                D2Client_GetItemTextLineDefense_6FAE51D0(v229, pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
                statLine_Defense_512.append(scratchpad);
            }
        }

        int32_t colorCode_Name = 0;
        switch (itemQuality)
        {
        case ITEMQUAL_MAGIC:
            colorCode_Name = 3;
            break;
        case ITEMQUAL_SET:
            colorCode_Name = 2;
            break;
        case ITEMQUAL_RARE:
            colorCode_Name = 9;
            break;
        case ITEMQUAL_UNIQUE:
            colorCode_Name = 4;
            break;
        case ITEMQUAL_CRAFT:
            colorCode_Name = 8;
            break;
        case ITEMQUAL_TEMPERED:
            colorCode_Name = 10;
            break;
        default:
            if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_SOCKETED, __LINE__, __FILE__)
                || ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_ETHEREAL, __LINE__, __FILE__))
            {
                colorCode_Name = 5;
            }
            break;
        }
        if (!ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_IDENTIFIED, __LINE__, __FILE__)
            && *D2Client_pDWORD_6FBB58EC >= 1
            && *D2Client_pDWORD_6FBB58EC <= 9
            && !*D2Client_pDWORD_6FB7928C)
        {
            colorCode_Name = 0;
        }

        std::wstring statLine_Quantity_512;
        std::wstring statLine_Stats_8192;
        std::wstring itemLineUnidentified;

        if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_IDENTIFIED, __LINE__, __FILE__))
        {
            if (!ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_SOCKETED, __LINE__, __FILE__))
            {
                auto v177 = pItemUnderCursor;
                auto v178 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
                auto v179 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
                if (STATLIST_UnitGetStatValue(v177, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(v177) > 0)
                {
                    auto v180 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3462_ItemStats1i);
                    statLine_Quantity_512.append(v180);
                    auto v181 = STATLIST_UnitGetStatValue(v177, STAT_QUANTITY, 0);
                    statLine_Quantity_512.append(v178);
                    statLine_Quantity_512.append(std::to_wstring(v181));
                    statLine_Quantity_512.append(v179);
                }
            }

            scratchpad[0] = 0;
            ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItemUnderCursor, statLine_Stats_8192, std::size(scratchpad), 1, 0);
        }
        else
        {
            auto v184 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3455_ItemStats1b);
            itemLineUnidentified.append(v184);
            itemLineUnidentified.append(strNewline_1);
        }

        scratchpad[0] = 0;
        D2Client_GetItemTextLineQuantity_6FAE5710(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
        statLine_Quantity_512.append(scratchpad);

        scratchpad[0] = 0;
        D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode*)scratchpad, 256);
        std::wstring itemLineName(scratchpad);

        itemDescription.clear();
        AppendColorizedString(itemDescription, statLine_Socketed_512, 3);
        AppendColorizedString(itemDescription, statLine_Stats_8192, 3);
        AppendColorizedString(itemDescription, itemLineUnidentified, 1);
        AppendColorizedString(itemDescription, statLine_AttackSpeed_2048, 0);
        AppendColorizedString(itemDescription, statLine_RequiredLevel512, colorCode245);
        AppendColorizedString(itemDescription, statLine_RequiredStength_256, colorCode3);
        AppendColorizedString(itemDescription, statLine_RequiredDexterity_256, colorCode2);
        AppendColorizedString(itemDescription, statLine_ClassRestriction_512, colorCode);
        AppendColorizedString(itemDescription, statLine_Durability_512, 0);
        AppendColorizedString(itemDescription, statLine_RuneGemStats_512, 0);
        AppendColorizedString(itemDescription, statLine_CharmKeepInInv_512, 0);
        AppendColorizedString(itemDescription, statLine_Quantity_512, 0);
        AppendColorizedString(itemDescription, statLine_Damage_512, 0);
        AppendColorizedString(itemDescription, statLine_v273_512, 0);
        AppendColorizedString(itemDescription, statLine_blockChance_512, 0);
        AppendColorizedString(itemDescription, statLine_Defense_512, 0);
        AppendColorizedString(itemDescription, statLine_RunewordName_512, 4);

        if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_BROKEN, __LINE__, __FILE__))
        {
            colorCode_Name = 1;
        }

        AppendColorizedString(itemDescription, itemLineName, colorCode_Name);

        if (*D2Client_pDWORD_6FBB58EC && *D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
        {
            scratchpad[0] = 0;
            D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode*)itemDescription.c_str(), (Unicode*)scratchpad);
            itemDescription = std::wstring(scratchpad);
        }

        if (!itemTxtRecord->nQuest || itemTxtRecord->dwCode == 543647084)
        {
            int32_t nWidth = 0;
            int32_t nHeight = 0;
            D2Win_10131_GetTextDimensions((const Unicode*)itemDescription.c_str(), &nWidth, &nHeight);
            if (*D2Client_pDWORD_6FB79294 - nHeight > 0)
            {
                D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 1);
                return;
            }

            D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79298, (*D2Client_pDWORD_6FB7929C + nHeight), 0, 1);
            return;
        }

        if (!*D2Client_pDWORD_6FBB58EC && (!pItemUnderCursor || !pItemUnderCursor->dwAnimMode))
        {
            if (itemTxtRecord->dwCode == 543452002)
            {
                auto v205 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2205_RightClicktoRead);
                itemDescription.insert(0, std::wstring(v205) + std::wstring(strNewline_1));
            }
            else if (itemTxtRecord->dwCode == 544763746)
            {
                auto v205 = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2204_RightClicktoOpen);
                itemDescription.insert(0, std::wstring(v205) + std::wstring(strNewline_1));
            }
        }

        ColorizeString(itemDescription, 4);

        int32_t nWidth = 0;
        int32_t nHeight = 0;
        D2Win_10131_GetTextDimensions((const Unicode*)itemDescription.c_str(), &nWidth, &nHeight);
        if (*D2Client_pDWORD_6FB79294 - nHeight > 0)
        {
            D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 4, 1);
            return;
        }

        D2Win_10129_DrawFramedText((const Unicode*)itemDescription.c_str(), *D2Client_pDWORD_6FB79298, (*D2Client_pDWORD_6FB7929C + nHeight), 4, 1);
        return;
    }

    int32_t colorCode = 0;
    int32_t colorCode2 = 0;
    int32_t colorCode3 = 0;
    int32_t colorCode245 = 0;

    auto strNewLine = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    auto pUnit_ = pItemMaybe;
    if (pItemMaybe->dwUnitType == UNIT_MONSTER && !MONSTERS_GetHirelingTypeId(pItemMaybe))
    {
        pUnit_ = D2Client_sub_6FB283D0();
    }

    if ((*D2Client_pDWORD_6FBB58E4 || *D2Client_pDWORD_6FBB58E0) && pItemUnderCursor && !INVENTORY_GetCursorItem(pItemMaybe->pInventory))
    {
        int32_t dwClassId = -1;
        if (pItemUnderCursor)
        {
            dwClassId = pItemUnderCursor->dwClassId;
        }

        auto pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(dwClassId);
        if (!pItemsTxtRecord)
        {
            FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
            exit(-1);
        }
        auto itemFileIndex = ITEMS_GetFileIndex(pItemUnderCursor);
        auto setItemTxt = D2Client_GetSetItemsTxt_6FAE5C80(itemFileIndex);
        if (setItemTxt)
        {
            auto setsTxtRecord = D2Client_sub_6FAE5C50(setItemTxt->nSetId);
            if (setsTxtRecord)
            {
                std::wstring itemLineCompleteSetName;
                std::wstring itemLineBasicInfo;
                std::wstring itemLineLevelRequirement;
                std::wstring itemLineDurability;
                std::wstring itemLineStrRequirement;
                std::wstring itemLineDexRequirement;

                auto setName = (wchar_t*)D2LANG_GetStringFromTblIndex(setsTxtRecord->wStringId);
                itemLineCompleteSetName.append(setName);
                itemLineCompleteSetName.append(strNewLine);

                BOOL bRequiresStr = false;
                BOOL bRequiresDex = false;
                BOOL bRequiresLevel = false;
                ITEMS_CheckRequirements(pItemUnderCursor, pUnit_, 0, &bRequiresStr, &bRequiresDex, &bRequiresLevel);

                scratchpad[0] = 0;
                D2Client_GetItemTextLineDurability_6FAE4060(pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                itemLineDurability.append(scratchpad);

                auto levelRequirement = ITEMS_GetLevelRequirement(pItemUnderCursor, pUnit_);
                if (levelRequirement > 1)
                {
                    if (!bRequiresLevel)
                    {
                        colorCode = 1;
                    }

                    scratchpad[0] = 0;
                    D2Client_GetItemTextLineLevelRequirement_6FAE41B0((Unicode*)scratchpad, levelRequirement);
                    itemLineLevelRequirement.append(scratchpad);
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_WEAPON) || D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR))
                {
                    int32_t strRequirement = 0;
                    int32_t dexRequirement = 0;

                    auto itemReqPercent = STATLIST_UnitGetItemStatOrSkillStatValue(pItemUnderCursor, STAT_ITEM_REQ_PERCENT, 0);
                    if (itemReqPercent)
                    {
                        strRequirement = DATATBLS_ApplyRatio(itemReqPercent, pItemsTxtRecord->wReqStr, 100);
                        dexRequirement = DATATBLS_ApplyRatio(itemReqPercent, pItemsTxtRecord->wReqDex, 100);
                    }
                    if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_ETHEREAL, __LINE__, __FILE__))
                    {
                        strRequirement -= 10;
                        dexRequirement -= 10;
                    }
                    if (pItemsTxtRecord->wReqStr)
                    {
                        if (!bRequiresStr)
                        {
                            colorCode2 = 1;
                        }

                        scratchpad[0] = 0;
                        D2Client_GetItemTextStrRequirement_6FAE4250((Unicode*)scratchpad, pItemsTxtRecord, strRequirement);
                        itemLineStrRequirement.append(scratchpad);
                    }
                    if (pItemsTxtRecord->wReqDex)
                    {
                        if (!bRequiresDex)
                        {
                            colorCode3 = 1;
                        }

                        scratchpad[0] = 0;
                        D2Client_GetItemTextDexRequirement_6FAE4310((Unicode*)scratchpad, pItemsTxtRecord, dexRequirement);
                        itemLineDexRequirement.append(scratchpad);
                    }
                }

                AppendColorizedString(itemLineBasicInfo, itemLineLevelRequirement, colorCode);
                AppendColorizedString(itemLineBasicInfo, itemLineStrRequirement, colorCode2);
                AppendColorizedString(itemLineBasicInfo, itemLineDexRequirement, colorCode3);
                auto itemClassRestriction = ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor);
                if (itemClassRestriction != PCLASS_EVILFORCE)
                {
                    std::wstring itemLineUnknownB;

                    auto strClassRestriction = (wchar_t*)D2LANG_GetStringFromTblIndex(itemClassRestriction + 10917);
                    itemLineUnknownB.append(strClassRestriction);
                    itemLineUnknownB.append(strNewLine);
                    if (pUnit_ && !pUnit_->dwUnitType && pUnit_->dwClassId != itemClassRestriction)
                    {
                        colorCode245 = 1;
                    }
                    AppendColorizedString(itemLineBasicInfo, itemLineUnknownB, colorCode245);
                }
                AppendColorizedString(itemLineBasicInfo, itemLineDurability, 0);

                if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_WEAPON))
                {
                    scratchpad[0] = 0;
                    D2Client_GetItemTextLineAttackSpeed_6FAE5570(pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                    AppendColorizedString(itemLineBasicInfo, scratchpad, 0);

                    if (STATLIST_GetMinDamageFromUnit(pItemUnderCursor, 0) >= 0 && STATLIST_GetMaxDamageFromUnit(pItemUnderCursor, 0) >= 0)
                    {
                        scratchpad[0] = 0;
                        D2Client_GetItemTextLineDamage_6FAE43D0(pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                        AppendColorizedString(itemLineBasicInfo, scratchpad, 0);
                    }
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_SHIELD))
                {
                    if (pUnit_ && !pUnit_->dwUnitType && pUnit_->dwClassId == 3 && (!ITEMS_IsClassValid(pItemUnderCursor) || ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor) == PCLASS_PALADIN))
                    {
                        scratchpad[0] = 0;
                        D2Client_GetItemTextLineUnknownA_6FAE5040(pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                        AppendColorizedString(itemLineBasicInfo, scratchpad, 0);
                    }

                    scratchpad[0] = 0;
                    D2Client_GetItemTextLineBlockChance_6FAE4EE0(pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                    AppendColorizedString(itemLineBasicInfo, scratchpad, 0);
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR)
                    && STATLIST_GetDefenseFromUnit(pItemUnderCursor) > 0)
                {
                    scratchpad[0] = 0;
                    D2Client_GetItemTextLineDefense_6FAE51D0(pUnit_, pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                    AppendColorizedString(itemLineBasicInfo, scratchpad, 0);
                }

                scratchpad[0] = 0;
                D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
                auto isItemBroken = ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_BROKEN, __LINE__, __FILE__);
                AppendColorizedString(itemLineBasicInfo, scratchpad, isItemBroken ? 1 : 2);

                std::wstring textLineProperties;
                if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_SOCKETED, __LINE__, __FILE__))
                {
                    scratchpad[0] = 0;
                    D2Client_GetItemTextSocketed_6FAE3EE0(pItemUnderCursor, (Unicode*)scratchpad);
                    textLineProperties.append(scratchpad);
                }

                scratchpad[0] = 0;
                ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItemUnderCursor, textLineProperties, std::size(scratchpad), 1, 0);

                std::wstring textLineSet;
                scratchpad[0] = 0;
                D2Client_GetItemTextSet_6FAF32B0(pUnit_, pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
                textLineSet.append(scratchpad);

                std::wstring textLineSetBonus;
                if (pItemUnderCursor && pItemUnderCursor->dwItemMode == IMODE_EQUIP)
                {
                    scratchpad[0] = 0;
                    D2Client_GetItemTextSetB_6FAF33C0(pUnit_, pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
                    textLineSetBonus.append(scratchpad);
                }

                std::wstring textLineSetNames;
                std::wstring scratchpadBuffer;

                if (setsTxtRecord->nSetItems > 0)
                {
                    for (int i = 0; i < setsTxtRecord->nSetItems; ++i)
                    {
                        auto pUnita = setsTxtRecord->pSetItem[i];

                        if (!pUnita->wSetItemId)
                        {
                            break;
                        }

                        auto v108 = D2Client_sub_6FAE5990(pItemMaybe->pInventory, pUnita->wSetItemId);
                        scratchpadBuffer.clear();

                        if (pUnita->wStringId)
                        {
                            auto strSetItemName = (wchar_t*)D2LANG_GetStringFromTblIndex(pUnita->wStringId);
                            auto strSetItemNameFormat = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_10089_SetItemFormatX);

                            scratchpad[0] = 0;
                            D2Client_sub_6FADCFE0((Unicode*)scratchpad, (const Unicode*)strSetItemNameFormat, (const Unicode*)strSetItemName, 0);
                            scratchpadBuffer.append(scratchpad);
                            scratchpadBuffer.append(strNewLine);
                        }
                        AppendColorizedString(textLineSetNames, scratchpadBuffer, v108 ? 2 : 1);
                    }
                }

                scratchpadBuffer.clear();
                AppendColorizedString(scratchpadBuffer, textLineSetNames, 2);
                AppendColorizedString(scratchpadBuffer, itemLineCompleteSetName, 4);

                if (textLineSetBonus[0])
                {
                    scratchpadBuffer.append(strNewLine);
                    AppendColorizedString(scratchpadBuffer, textLineSetBonus, 4);
                }
                scratchpadBuffer.append(strNewLine);
                if (textLineSet[0])
                {
                    AppendColorizedString(scratchpadBuffer, textLineSet, 2);
                }

                AppendColorizedString(scratchpadBuffer, textLineProperties, 3);
                scratchpadBuffer.append(itemLineBasicInfo);

                std::wstring pTextToDisplay;

                if (*D2Client_pDWORD_6FBB58EC && *D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
                {
                    int32_t hasSkillCharges = false;
                    scratchpad[0] = 0;
                    if (D2Client_GetItemTextPriceMaybe_6FAFB200(pItemUnderCursor, *D2Client_pDWORD_6FB7928C, &hasSkillCharges, (Unicode*)scratchpad, std::size(scratchpad)))
                    {
                        pTextToDisplay.append(scratchpadBuffer);
                        if (scratchpad[0])
                        {
                            pTextToDisplay.append(strNewLine);
                        }

                        pTextToDisplay.append(scratchpad);
                    }
                    else
                    {
                        pTextToDisplay.append(scratchpadBuffer);
                        if (*D2Client_pDWORD_6FBB58EC != 4)
                        {
                            pTextToDisplay.append(strNewLine);

                            auto strItemCannotBeSold = (wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3333_priceless);
                            AppendColorizedString(pTextToDisplay, strItemCannotBeSold, 1);
                        }
                    }
                }
                else
                {
                    pTextToDisplay = scratchpadBuffer;
                }

                int32_t width = 0;
                int32_t height = 0;
                D2Win_10131_GetTextDimensions((const Unicode*)pTextToDisplay.c_str(), &width, &height);

                if (*D2Client_pDWORD_6FB79294 - height > 0)
                {
                    D2Win_10129_DrawFramedText((const Unicode*)pTextToDisplay.c_str(), *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 1);
                    return;
                }

                auto v120 = height + *D2Client_pDWORD_6FB7929C;
                D2Win_10129_DrawFramedText((const Unicode*)pTextToDisplay.c_str(), *D2Client_pDWORD_6FB79298, v120, 0, 1);
                return;
            }
        }
    }
}

