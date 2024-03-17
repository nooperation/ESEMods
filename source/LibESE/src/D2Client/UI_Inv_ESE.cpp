#include "D2Client/UI_Inv_ESE.h"
#include <D2Client/CharScreenDmg_ESE.h>
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
#include "D2Gfx.h"
#include "D2Config.h"

void AppendString(std::wstring& dest, const char* source)
{
    std::string str(source);
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    dest.append(converter.from_bytes(str));
}

void ColorizeString(std::wstring& str, int32_t color)
{
    auto colorCodeToken = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3994_colorcode);
    std::wstring colorStr(colorCodeToken);
    colorStr.append(std::to_wstring(color));

    str.insert(0, colorStr);
}

void AppendColorizedString(std::wstring& dest, const std::wstring& src, int32_t color)
{
    auto colorCodeToken = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3994_colorcode);
    dest.append(colorCodeToken);
    dest.append(std::to_wstring(color));
    dest.append(src);
}

int ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(int32_t nDescFunc, int32_t nItemStatCostTxtRecordCount, std::wstring& outBuff)
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

int ESE_GetItemPropertyLine_HelperA(D2UnitStrc* pUnit, int nDescGrpFunc, int statValue, int recordId, D2ItemStatCostTxt* itemStatCostTxtForStat, std::wstring& outBuff)
{
    wchar_t scratchpad[1024] = { 0 };

    auto nDescFunc = itemStatCostTxtForStat->nDescFunc;
    auto nDescVal = itemStatCostTxtForStat->nDescVal;
    auto descStrIndex = itemStatCostTxtForStat->wDescStr2;
    int16_t strDescIndex = 0;

    if (nDescGrpFunc)
    {
        nDescFunc = itemStatCostTxtForStat->nDescGrpFunc;
        nDescVal = itemStatCostTxtForStat->nDescGrpVal;
        descStrIndex = itemStatCostTxtForStat->wDescGrpStr2;
        if (statValue < 0)
        {
            strDescIndex = itemStatCostTxtForStat->wDescGrpStrNeg;
        }
        else
        {
            strDescIndex = itemStatCostTxtForStat->wDescGrpStrPos;
        }
    }
    else if (statValue < 0)
    {
        strDescIndex = itemStatCostTxtForStat->wDescStrNeg;
    }
    else
    {
        strDescIndex = itemStatCostTxtForStat->wDescStrPos;
    }

    auto strDesc = (const wchar_t*)D2LANG_GetStringFromTblIndex(strDescIndex);
    auto strStatValue = std::to_wstring(statValue);

    auto strPercentSign = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4001_percent);
    auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    auto strPlusSign = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4002_plus);

    switch (nDescFunc)
    {
    case 1:
    case 6:
    case 12:
    {
        std::wstring statValueBuff;
        if (statValue <= 0)
        {
            statValueBuff.assign(strStatValue);
        }
        else if (nDescFunc != 12 || statValue > 1)
        {
            statValueBuff.assign(strPlusSign);
            statValueBuff.append(strStatValue);
        }

        if (nDescVal == 1)
        {
            outBuff.assign(statValueBuff);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
            break;
        }

        if (nDescVal != 2)
        {
            break;
        }

        outBuff.assign(strDesc);
        outBuff.append(strSpace);
        outBuff.append(statValueBuff);
        break;
    }
    case 2:
    case 7:
    {
        if (nDescVal == 1)
        {
            outBuff.assign(strStatValue);
            outBuff.append(strPercentSign);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
            break;
        }

        if (nDescVal != 2)
        {
            outBuff.assign(strDesc);
            break;
        }

        outBuff.assign(strDesc);
        outBuff.append(strSpace);
        outBuff.append(strStatValue);
        outBuff.append(strPercentSign);
        break;
    }
    case 3:
    case 9:
    {
        if (nDescVal == 1)
        {
            outBuff.assign(strStatValue);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
            break;
        }
        if (nDescVal != 2)
        {
            outBuff.assign(strDesc);
            break;
        }
        outBuff.assign(strDesc);
        outBuff.append(strSpace);
        outBuff.append(strStatValue);
        break;
    }
    case 4:
    case 8:
    {
        if (nDescVal != 1)
        {
            if (nDescVal != 2)
            {
                outBuff.assign(strDesc);
                break;
            }

            outBuff.assign(strDesc);
            outBuff.append(strSpace);
            if (statValue >= 0)
            {
                outBuff.append(strPlusSign);
            }
            outBuff.append(strStatValue);
            outBuff.append(strPercentSign);
            break;
        }
        if (statValue >= 0)
        {
            outBuff.assign(strPlusSign);
            outBuff.append(strStatValue);
            outBuff.append(strPercentSign);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
            break;
        }

        outBuff.assign(strStatValue);
        outBuff.append(strPercentSign);
        outBuff.append(strSpace);
        outBuff.append(strDesc);
        break;
    }
    case 5:
    case 10:
    {
        auto percentage = std::to_wstring(100 * statValue / 128);
        if (nDescVal == 1)
        {
            outBuff.assign(percentage);
            outBuff.append(strPercentSign);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
            break;
        }

        if (nDescVal != 2)
        {
            outBuff.assign(strDesc);
            break;
        }

        outBuff.assign(strDesc);
        outBuff.append(strSpace);
        outBuff.append(percentage);
        outBuff.append(strPercentSign);
        break;
    }
    case 11:
    {
        if (statValue <= 0)
        {
            auto strRepairsNDurabilityPerSecond = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21241_ModStre9t);
            swprintf_s(scratchpad, strRepairsNDurabilityPerSecond, 25);
            outBuff.append(scratchpad);
        }
        else if (2500 / statValue > 30)
        {
            auto strRepairsNDurabilityInNSeconds = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21242_ModStre9u);
            swprintf_s(scratchpad, strRepairsNDurabilityInNSeconds, 1, (2500 / statValue + 12) / 25);
            outBuff.append(scratchpad);
        }
        else
        {
            auto strRepairsNDurabilityPerSecond1 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21241_ModStre9t);
            swprintf_s(scratchpad, strRepairsNDurabilityPerSecond1, 1);
            outBuff.append(scratchpad);
        }

        break;
    }
    case 13:
    {
        if (statValue == 0 || recordId < 0 || recordId >= sgptDataTables->nCharStatsTxtRecordCount)
        {
            return 0;
        }

        std::wstring statValueBuff;
        if (statValue < 0)
        {
            statValueBuff.assign(strStatValue);
        }
        else
        {
            statValueBuff.assign(strPlusSign);
            statValueBuff.append(strStatValue);
        }

        auto charStatsTxtRecord = &sgptDataTables->pCharStatsTxt[recordId];
        if (!charStatsTxtRecord)
        {
            return 0;
        }

        auto strDesc = (const wchar_t*)D2LANG_GetStringFromTblIndex(charStatsTxtRecord->wStrAllSkills);

        if (nDescVal == 1)
        {
            outBuff.assign(statValueBuff);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
            break;
        }
        if (nDescVal != 2)
        {
            break;
        }

        outBuff.assign(strDesc);
        outBuff.append(strSpace);
        outBuff.append(statValueBuff);
        break;
    }
    case 14:
    {
        auto charStatsTxtRecordIndex = recordId >> 3;
        if (charStatsTxtRecordIndex < 0 || charStatsTxtRecordIndex >= sgptDataTables->nCharStatsTxtRecordCount)
        {
            return 0;
        }

        auto pCharStatsTxt = &sgptDataTables->pCharStatsTxt[charStatsTxtRecordIndex];
        if (!pCharStatsTxt || (recordId & 7u) >= 3)
        {
            return 0;
        }

        auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(pCharStatsTxt->wStrSkillTab[recordId & 7]);
        auto strClassOnly = (const wchar_t*)D2LANG_GetStringFromTblIndex(pCharStatsTxt->wStrClassOnly);

        swprintf_s(scratchpad, strFormat, statValue);

        outBuff.append(scratchpad);
        outBuff.append(strSpace);
        outBuff.append(strClassOnly);
        break;
    }
    case 15:
    {
        auto shiftedIndex = recordId >> sgptDataTables->nStuff;
        if (shiftedIndex <= 0 || shiftedIndex >= sgptDataTables->nSkillsTxtRecordCount)
        {
            return 0;
        }

        auto skillNameStrIndex = D2Client_GetSkillStringId_6FB0A440(shiftedIndex, 0);
        auto strSkillName = (const wchar_t*)D2LANG_GetStringFromTblIndex(skillNameStrIndex);
        auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(itemStatCostTxtForStat->wDescStrPos);

        swprintf_s(scratchpad, strFormat, statValue, recordId& sgptDataTables->nShiftedStuff, strSkillName);
        outBuff.append(scratchpad);

        break;
    }
    case 16:
    {
        auto skillStringIndex = D2Client_GetSkillStringId_6FB0A440(recordId, 0);
        auto strSkillName = (const wchar_t*)D2LANG_GetStringFromTblIndex(skillStringIndex);
        if (!strSkillName)
        {
            return 0;
        }

        swprintf_s(scratchpad, strDesc, statValue, strSkillName);
        outBuff.append(scratchpad);

        break;
    }
    case 17:
    case 18:
    {
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
        auto timeAdjustmentThing = ITEMMODS_GetByTimeAdjustment(statValue, preiodOfDay, baseTime, &pItemModPeriodOfDay, &itemModMin, &itemModMax);
        if (!*D2Client_pDWORD_6FBA7984)
        {
            timeAdjustmentThing = itemModMin;
        }

        auto v52 = (const wchar_t*)D2LANG_GetStringFromTblIndex(D2Client_pWORD_6FB6FA30[pItemModPeriodOfDay]);
        auto strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

        outBuff.append(v52);
        outBuff.append(strNewLine);

        auto v95 = std::to_wstring(timeAdjustmentThing);
        std::wstring v99;

        if (timeAdjustmentThing < 0)
        {
            if (statValue < 0)
            {
                v99.assign(v95);
            }
        }
        else
        {
            v99.assign(strPlusSign);
            v99.append(v95);
        }
        if (nDescFunc == 18)
        {
            v99.append(strPercentSign);
        }
        if (nDescVal == 1)
        {
            outBuff.append(v99);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
            break;
        }
        if (nDescVal != 2)
        {
            break;
        }
        outBuff.append(strDesc);
        outBuff.append(strSpace);
        outBuff.append(v99);
        break;
    }
    case 19:
    {
        swprintf_s(scratchpad, strDesc, statValue);
        outBuff.append(scratchpad);
        break;
    }
    case 20:
    case 21:
    {
        statValue = -statValue;

        auto v95 = std::to_wstring(statValue);

        if (nDescVal == 1)
        {
            if (statValue < 0)
            {
                outBuff.assign(v95);
            }
            else
            {
                outBuff.assign(strPlusSign);
                outBuff.append(v95);
            }

            outBuff.append(strPercentSign);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
            break;
        }
        else
        {
            if (nDescVal != 2)
            {
                outBuff.assign(strDesc);
                break;
            }
            outBuff.assign(strDesc);
            outBuff.append(strSpace);
            if (statValue >= 0)
            {
                outBuff.append(strPlusSign);
            }
            outBuff.append(v95);
            outBuff.append(strPercentSign);
            break;
        }
    }
    case 22:
    {
        if (nDescVal == 1)
        {
            if (statValue >= 0)
            {
                outBuff.assign(strPlusSign);
            }

            outBuff.append(strStatValue);
            outBuff.append(strPercentSign);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
        }
        else if (nDescVal == 2)
        {
            outBuff.assign(strDesc);
            outBuff.append(strSpace);
            if (statValue >= 0)
            {
                outBuff.append(strPlusSign);
            }
            outBuff.append(strStatValue);
            outBuff.append(strPercentSign);
        }
        else
        {
            outBuff.assign(strDesc);
        }

        D2MonTypeTxt* v54 = nullptr;
        if (recordId < 0 || recordId >= sgptDataTables->nMonPropTxtRecordCount)
        {
            v54 = sgptDataTables->pMonTypeTxt;
        }
        else
        {
            v54 = &sgptDataTables->pMonTypeTxt[recordId];
        }

        if (!v54)
        {
            break;
        }

        auto strColon = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3997_colon);
        auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
        auto strPlur = (const wchar_t*)D2LANG_GetStringFromTblIndex(v54->wStrPlur);

        outBuff.append(strColon);
        outBuff.append(strSpace);
        outBuff.append(strPlur);
        break;
    }
    case 23:
    {
        if (recordId < 0 || recordId >= sgptDataTables->nMonStatsTxtRecordCount)
        {
            return 0;
        }

        auto monStatsTxtRecord = &sgptDataTables->pMonStatsTxt[recordId];
        if (!monStatsTxtRecord)
        {
            return 0;
        }

        if (nDescVal == 1)
        {
            outBuff.assign(strStatValue);
            outBuff.append(strPercentSign);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
        }
        else
        {
            outBuff.assign(strDesc);
            if (nDescVal == 2)
            {
                outBuff.append(strSpace);
                outBuff.append(strStatValue);
                outBuff.append(strPercentSign);
            }
        }
        auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
        auto strName = (const wchar_t*)D2LANG_GetStringFromTblIndex(monStatsTxtRecord->wNameStr);

        outBuff.append(strSpace);
        outBuff.append(strName);
        break;
    }
    case 24:
    {
        auto skillId = recordId >> sgptDataTables->nStuff;
        auto skillLevel = (recordId & sgptDataTables->nShiftedStuff);
        auto nMaxCharges = statValue >> 8;
        auto nCurrentCharges = statValue & 0xFF;
        auto skillStringId = D2Client_GetSkillStringId_6FB0A440(skillId, 0);
        auto strSkillName = (const wchar_t*)D2LANG_GetStringFromTblIndex(skillStringId);
        if (!strSkillName)
        {
            break;
        }

        auto strLevel = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21249_ModStre10b);
        outBuff.append(strLevel);
        outBuff.append(strSpace);
        outBuff.append(std::to_wstring(skillLevel));
        outBuff.append(strSpace);
        outBuff.append(strSkillName);
        outBuff.append(strSpace);

        swprintf_s(scratchpad, strDesc, nCurrentCharges, nMaxCharges);
        outBuff.append(scratchpad);

        break;
    }
    case 25:
    case 26:
    {
        std::wstring statValueBuff;
        if (statValue >= 0)
        {
            statValueBuff.assign(strStatValue);
        }
        else
        {
            statValueBuff.assign(strPlusSign);
            statValueBuff.append(strStatValue);
        }

        if (nDescVal == 1)
        {
            outBuff.assign(statValueBuff);
            outBuff.append(strSpace);
            outBuff.append(strDesc);
            break;
        }
        if (nDescVal != 2)
        {
            break;
        }

        outBuff.assign(strDesc);
        outBuff.append(strSpace);
        outBuff.append(statValueBuff);
        break;
    }
    case 27:
    {
        auto strTo = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4003_to);
        if (!strTo)
        {
            break;
        }

        if (!statValue)
        {
            break;
        }

        auto skillStringId = D2Client_GetSkillStringId_6FB0A440(recordId, 0);
        auto strSkillName = (const wchar_t*)D2LANG_GetStringFromTblIndex(skillStringId);
        if (!strSkillName)
        {
            break;
        }
        if (statValue <= 0)
        {
            outBuff.assign(strStatValue);
        }
        else
        {
            outBuff.append(strPlusSign);
            outBuff.append(strStatValue);
        }
        outBuff.append(strSpace);
        outBuff.append(strTo);
        outBuff.append(strSpace);
        outBuff.append(strSkillName);
        outBuff.append(strSpace);

        int32_t playerClass = 7;
        if (!SKILLS_IsPlayerClassSkill(recordId, &playerClass))
        {
            break;
        }
        if (playerClass < 0 || playerClass >= 7 || playerClass >= sgptDataTables->nCharStatsTxtRecordCount)
        {
            break;
        }

        auto charStatsTxt = &sgptDataTables->pCharStatsTxt[playerClass];
        if (!charStatsTxt)
        {
            break;
        }
        auto strClassRestricted = (const wchar_t*)D2LANG_GetStringFromTblIndex(charStatsTxt->wStrClassOnly);
        outBuff.append(strClassRestricted);
        break;
    }
    case 28:
    {
        int32_t statVal = statValue;
        if (!statValue || recordId < 0 || recordId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            break;
        }

        auto pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[recordId];
        if (!pSkillsTxtRecord)
        {
            break;
        }

        D2UnitStrc* pPlayer = pUnit;
        if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
        {
            pPlayer = D2Client_GetCurrentPlayer_6FB283D0();
        }

        int32_t classId = -1;
        if (pPlayer)
        {
            classId = pPlayer->dwClassId;
        }

        if (pSkillsTxtRecord->nCharClass == classId && statValue > 3)
        {
            statVal = 3;
        }

        auto strTo = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4003_to);
        if (!strTo)
        {
            break;
        }
        auto skillStringId = D2Client_GetSkillStringId_6FB0A440(recordId, 0);
        auto strSkillName = (const wchar_t*)D2LANG_GetStringFromTblIndex(skillStringId);
        if (!strSkillName)
        {
            break;
        }

        auto v95 = std::to_wstring(statVal);
        if (statVal <= 0)
        {
            outBuff.assign(v95);
        }
        else
        {
            outBuff.assign(strPlusSign);
            outBuff.append(v95);
        }

        outBuff.append(strSpace);
        outBuff.append(strTo);
        outBuff.append(strSpace);
        outBuff.append(strSkillName);
        break;
    }
    default:
        return 0;
    }

    return ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(nDescFunc, descStrIndex, outBuff);
}

int ESE_D2Client_GetItemPropertyLine_6FAF21C0(D2UnitStrc* pItem, D2StatListStrc* pStatList, int nStatId, int skillId, int statValueModifier, std::wstring& outBuff)
{
    if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    auto itemStatCostTxtForStat = &sgptDataTables->pItemStatCostTxt[nStatId];
    if (!itemStatCostTxtForStat)
    {
        return 0;
    }

    int32_t statValue = 0;
    if (itemStatCostTxtForStat->nOp < 2u || itemStatCostTxtForStat->nOp > 5u)
    {
        statValue = statValueModifier >> itemStatCostTxtForStat->nValShift;
        if (nStatId == STAT_ITEM_UNDEADDAMAGE_PERCENT && pItem && pItem->dwUnitType == UNIT_ITEM && D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BLUNT))
        {
            statValue += 50;
        }
    }
    else if (itemStatCostTxtForStat->wOpBase < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        D2ItemStatCostTxt* pOpBaseItemStatCostTxt = &sgptDataTables->pItemStatCostTxt[itemStatCostTxtForStat->wOpBase];
        if (pOpBaseItemStatCostTxt)
        {
            auto pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
            auto opBaseValue = STATLIST_UnitGetStatValue(pCurrentPlayer, itemStatCostTxtForStat->wOpBase, 0) >> pOpBaseItemStatCostTxt->nValShift;

            int32_t unshiftedStatValue = (statValueModifier * opBaseValue) >> itemStatCostTxtForStat->nOpParam;
            statValue = unshiftedStatValue >> itemStatCostTxtForStat->nValShift;
            if (nStatId == STAT_ITEM_UNDEADDAMAGE_PERCENT && pItem && pItem->dwUnitType == UNIT_ITEM && D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BLUNT))
            {
                statValue += 50;
            }
        }
    }

    // This is not part of a group of stats, just do it
    if (itemStatCostTxtForStat->wDescGrp == 0)
    {
        return ESE_GetItemPropertyLine_HelperA(pItem, 0, statValue, skillId, itemStatCostTxtForStat, outBuff);
    }

    auto originalStatValue = statValue;
    auto itemStatCostTxtIndex = sgptDataTables->nItemStatCostTxtRecordCount;

    while (--itemStatCostTxtIndex >= 0)
    {
        auto currentItemStatCostTxt = &sgptDataTables->pItemStatCostTxt[itemStatCostTxtIndex];
        if (currentItemStatCostTxt == nullptr)
        {
            return ESE_GetItemPropertyLine_HelperA(pItem, 0, statValue, skillId, itemStatCostTxtForStat, outBuff);
        }

        // Skip stats that are not part of the group
        if (itemStatCostTxtForStat->wDescGrp != currentItemStatCostTxt->wDescGrp)
        {
            statValue = originalStatValue;
            continue;
        }

        auto currentStatValueUnshifted = D2Common_10466_STATLIST_GetStatValue(pStatList, itemStatCostTxtIndex, 0);
        if (currentItemStatCostTxt->nOp >= 2u && currentItemStatCostTxt->nOp <= 5u)
        {
            if (currentItemStatCostTxt->wOpBase >= sgptDataTables->nItemStatCostTxtRecordCount || (itemStatCostTxtForStat = &sgptDataTables->pItemStatCostTxt[currentItemStatCostTxt->wOpBase]) == 0)
            {
                if (originalStatValue != 0)
                {
                    return ESE_GetItemPropertyLine_HelperA(pItem, 0, originalStatValue, skillId, itemStatCostTxtForStat, outBuff);
                }

                if (itemStatCostTxtIndex == nStatId)
                {
                    return ESE_GetItemPropertyLine_HelperA(pItem, 1, originalStatValue, skillId, itemStatCostTxtForStat, outBuff);
                }

                return 0;
            }

            auto pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
            auto playerStatValue = STATLIST_UnitGetStatValue(pCurrentPlayer, currentItemStatCostTxt->wOpBase, 0) >> itemStatCostTxtForStat->nValShift;

            currentStatValueUnshifted = (currentStatValueUnshifted * playerStatValue) >> currentItemStatCostTxt->nOpParam;
        }

        auto currentStatValue = currentStatValueUnshifted >> currentItemStatCostTxt->nValShift;
        if (itemStatCostTxtIndex == STAT_ITEM_UNDEADDAMAGE_PERCENT && pItem && pItem->dwUnitType == UNIT_ITEM && D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BLUNT))
        {
            currentStatValue += 50;
        }

        if (originalStatValue != currentStatValue)
        {
            return ESE_GetItemPropertyLine_HelperA(pItem, 0, originalStatValue, skillId, itemStatCostTxtForStat, outBuff);
        }

        statValue = originalStatValue;
    }

    if (itemStatCostTxtIndex == nStatId)
    {
        return ESE_GetItemPropertyLine_HelperA(pItem, 1, originalStatValue, skillId, itemStatCostTxtForStat, outBuff);
    }

    return 0;
}

bool ESE_D2Client_PrintDamageRange_6FAF3460(DamageRangeValue* statValues, D2C_ItemStats nStatId, std::wstring& outBuff)
{
    wchar_t scratchpad[256] = { 0 };

    switch (nStatId)
    {
    case STAT_MINDAMAGE:
    case STAT_MAXDAMAGE:
    case STAT_SECONDARY_MINDAMAGE:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_PHYSICAL];

        if (damageRangeValue->bHasBeenHandled)
        {
            return true;
        }

        if (!damageRangeValue->bHasMinAndMaxDamage)
        {
            return false;
        }

        if (damageRangeValue->minDamage < damageRangeValue->maxDamage)
        {
            damageRangeValue->bHasBeenHandled = 1;
            auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3623_strModMinDamageRange);
            swprintf_s(scratchpad, fmt, damageRangeValue->minDamage, damageRangeValue->maxDamage);
            outBuff.append(scratchpad);
            return true;
        }
        else
        {
            damageRangeValue->bHasMinAndMaxDamage = false;
            damageRangeValue->bHasBeenHandled = false;
            return false;
        }
    }
    case STAT_SECONDARY_MAXDAMAGE:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_PHYSICAL];

        if (damageRangeValue->bHasBeenHandled)
        {
            return true;
        }

        return damageRangeValue->bHasMinAndMaxDamage;
    }

    case STAT_ITEM_MAXDAMAGE_PERCENT:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_PHYSICALPERCENT];
        return damageRangeValue->bHasMinAndMaxDamage;
    }
    case STAT_ITEM_MINDAMAGE_PERCENT:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_PHYSICALPERCENT];
        if (!damageRangeValue->bHasMinAndMaxDamage)
        {
            return false;
        }

        const auto strPercent = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4001_percent);
        const auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
        const auto strPlus = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4002_plus);
        const auto strEnhancedDamage = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_10023_strModEnhancedDamage);

        outBuff.append(strPlus);
        outBuff.append(std::to_wstring(damageRangeValue->minDamage));
        outBuff.append(strPercent);
        outBuff.append(strSpace);
        outBuff.append(strEnhancedDamage);
        return true;
    }
    case STAT_COLDMINDAM:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_COLD];
        if (!damageRangeValue->bHasMinAndMaxDamage)
        {
            return false;
        }

        if (damageRangeValue->minDamage < damageRangeValue->maxDamage)
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3615_strModColdDamageRange);
            swprintf_s(scratchpad, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage);
            outBuff.append(scratchpad);
            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3614_strModColdDamage);
            swprintf_s(scratchpad, strFormat, damageRangeValue->maxDamage);
            outBuff.append(scratchpad);
            return true;
        }
    }
    case STAT_COLDMAXDAM:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_COLD];
        return damageRangeValue->bHasMinAndMaxDamage;
    }
    case STAT_LIGHTMINDAM:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_LIGHTNING];

        if (!damageRangeValue->bHasMinAndMaxDamage)
        {
            return false;
        }

        if (damageRangeValue->minDamage >= damageRangeValue->maxDamage)
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3616_strModLightningDamage);
            swprintf_s(scratchpad, strFormat, damageRangeValue->maxDamage);
            outBuff.append(scratchpad);
            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3617_strModLightningDamageRange);
            swprintf_s(scratchpad, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage);
            outBuff.append(scratchpad);
            return true;
        }
    }
    case STAT_LIGHTMAXDAM:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_LIGHTNING];
        return damageRangeValue->bHasMinAndMaxDamage;
    }
    case STAT_FIREMINDAM:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_FIRE];
        if (!damageRangeValue->bHasMinAndMaxDamage)
        {
            return false;
        }

        if (damageRangeValue->minDamage >= damageRangeValue->maxDamage)
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3612_strModFireDamage);
            swprintf_s(scratchpad, strFormat, damageRangeValue->maxDamage);
            outBuff.append(scratchpad);
            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3613_strModFireDamageRange);
            swprintf_s(scratchpad, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage);
            outBuff.append(scratchpad);
            return true;
        }
    }
    case STAT_FIREMAXDAM:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_FIRE];
        return damageRangeValue->bHasMinAndMaxDamage;
    }
    case STAT_POISONMINDAM:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_POISON];
        if (!damageRangeValue->bHasMinAndMaxDamage)
        {
            return false;
        }

        if (damageRangeValue->count <= 0)
        {
            damageRangeValue->count = 1;
        }

        damageRangeValue->length /= damageRangeValue->count;
        damageRangeValue->minDamage = (damageRangeValue->length * damageRangeValue->minDamage + 128) >> 8;
        damageRangeValue->maxDamage = (damageRangeValue->length * damageRangeValue->maxDamage + 128) >> 8;

        if (damageRangeValue->minDamage < damageRangeValue->maxDamage)
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3621_strModPoisonDamageRange);
            swprintf_s(scratchpad, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage, damageRangeValue->length / 25);
            outBuff.append(scratchpad);
            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3620_strModPoisonDamage);
            swprintf_s(scratchpad, strFormat, damageRangeValue->maxDamage, damageRangeValue->length / 25);
            outBuff.append(scratchpad);
            return true;
        }
    }
    case STAT_POISONMAXDAM:
    case STAT_POISONLENGTH:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_POISON];
        return damageRangeValue->bHasMinAndMaxDamage;
    }
    case STAT_MAGICMINDAM:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_MAGIC];

        if (!damageRangeValue->bHasMinAndMaxDamage)
        {
            return false;
        }

        if (damageRangeValue->minDamage < damageRangeValue->maxDamage)
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3619_strModMagicDamageRange);
            swprintf_s(scratchpad, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage);
            outBuff.append(scratchpad);
            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3618_strModMagicDamage);
            swprintf_s(scratchpad, strFormat, damageRangeValue->maxDamage);
            outBuff.append(scratchpad);
            return true;
        }
    }
    case STAT_MAGICMAXDAM:
    {
        const auto damageRangeValue = &statValues[DAMAGE_RANGE_MAGIC];
        return damageRangeValue->bHasMinAndMaxDamage;
    }
    }

    return false;
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

#pragma pack(push, 1)
struct UnknownStructA
{
    int32_t statId;
    int32_t unknownA;
    int32_t unknownB;
    int32_t unknownC;
};
#pragma pack(pop)
void ESE_D2Client_GetItemTextLinePropertiesInternal_6FAF19C0(D2UnitStrc* pUnit, std::wstring& outBuff, int outBuffMaxLen, int bUnknownFlag1, int unitState, int nUnitState, int nUnitFlags, int addNewline)
{
    auto strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    auto strComma = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3852_KeyComma);
    auto strPlus = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4002_plus);

    if (ITEMS_GetItemType(pUnit) != ITEMTYPE_ELIXIR)
    {
        auto unitStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, unitState, nUnitFlags);
        if (!unitStatList)
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

        STATLIST_MergeBaseStats(pStatList, unitStatList);
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
            if (pUnit->dwUnitType == UNIT_ITEM)
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


        DamageRangeValue statValues[DAMAGE_RANGE_MAX];
        memset(statValues, 0, sizeof(statValues));

        auto unknownStatArray = (UnknownStructA*)D2Client_pDWORD_6FB79B48;
        int32_t numUnknownStatArrayElements = *D2Client_pDWORD_6FB7A438;

        for (int32_t unknownStatArrayIndex = 0; unknownStatArrayIndex < numUnknownStatArrayElements; ++unknownStatArrayIndex)
        {
            const int32_t statId = unknownStatArray[unknownStatArrayIndex].statId;

            switch (statId)
            {
            case STAT_ITEM_MAXDAMAGE_PERCENT:
                statValues[DAMAGE_RANGE_PHYSICALPERCENT].maxDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_ITEM_MINDAMAGE_PERCENT:
                statValues[DAMAGE_RANGE_PHYSICALPERCENT].minDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_MINDAMAGE:
                statValues[DAMAGE_RANGE_PHYSICAL].minDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                if (!statValues[DAMAGE_RANGE_PHYSICAL].minDamage)
                {
                    statValues[DAMAGE_RANGE_PHYSICAL].minDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_SECONDARY_MINDAMAGE, 0);
                }
                break;
            case STAT_MAXDAMAGE:
                statValues[DAMAGE_RANGE_PHYSICAL].maxDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                if (!statValues[DAMAGE_RANGE_PHYSICAL].maxDamage)
                {
                    statValues[DAMAGE_RANGE_PHYSICAL].maxDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_SECONDARY_MAXDAMAGE, 0);
                }
                break;
            case STAT_FIREMINDAM:
                statValues[DAMAGE_RANGE_FIRE].minDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_FIREMAXDAM:
                statValues[DAMAGE_RANGE_FIRE].maxDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_LIGHTMINDAM:
                statValues[DAMAGE_RANGE_LIGHTNING].minDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_LIGHTMAXDAM:
                statValues[DAMAGE_RANGE_LIGHTNING].maxDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_MAGICMINDAM:
                statValues[DAMAGE_RANGE_MAGIC].minDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_MAGICMAXDAM:
                statValues[DAMAGE_RANGE_MAGIC].maxDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_COLDMINDAM:
                statValues[DAMAGE_RANGE_COLD].minDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_COLDMAXDAM:
                statValues[DAMAGE_RANGE_COLD].maxDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_POISONMINDAM:
                statValues[DAMAGE_RANGE_POISON].minDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_POISONMAXDAM:
                statValues[DAMAGE_RANGE_POISON].maxDamage = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                break;
            case STAT_POISONLENGTH:
                statValues[DAMAGE_RANGE_POISON].length = D2Common_10466_STATLIST_GetStatValue(pStatList, statId, 0);
                statValues[DAMAGE_RANGE_POISON].count = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
                break;
            default:
                break;
            }
        }

        for (auto& item : statValues)
        {
            item.bHasMinAndMaxDamage = item.minDamage > 0 && item.maxDamage > 0;
        }

        auto hasSecondaryMinMaxDmg = 0;
        if (sgptDataTables->nStatsWithDescFunc > 0)
        {
            D2StatStrc d2StatStrcBuffer[511];
            for (int32_t statsWithDescIndex = 0; statsWithDescIndex < sgptDataTables->nStatsWithDescFunc; ++statsWithDescIndex)
            {
                uint16_t nStatId = sgptDataTables->pStatsWithDescFunc[statsWithDescIndex];
                if (nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    continue;
                }

                int32_t nCopiedStats = D2Common_11269_CopyStats((D2StatListExStrc*)pStatList, nStatId, d2StatStrcBuffer, std::size(d2StatStrcBuffer));
                if (nCopiedStats <= 0)
                {
                    continue;
                }

                for (int32_t copiedStatIndex = 0; copiedStatIndex < nCopiedStats; ++copiedStatIndex)
                {
                    if (!d2StatStrcBuffer[copiedStatIndex].nValue)
                    {
                        continue;
                    }

                    if (ESE_D2Client_PrintDamageRange_6FAF3460(statValues, (D2C_ItemStats)nStatId, outBuff))
                    {
                        continue;
                    }

                    std::wstring propertyLineBuffer256;
                    if (!ESE_D2Client_GetItemPropertyLine_6FAF21C0(pUnit, pStatList, nStatId, d2StatStrcBuffer[copiedStatIndex].nLayer, d2StatStrcBuffer[copiedStatIndex].nValue, propertyLineBuffer256))
                    {
                        continue;
                    }

                    int32_t statValue = 0;
                    if (nStatId == STAT_SECONDARY_MINDAMAGE)
                    {
                        statValue = D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_MINDAMAGE, 0);
                    }
                    else if (nStatId == STAT_SECONDARY_MAXDAMAGE)
                    {
                        statValue = D2Common_10466_STATLIST_GetStatValue(pStatList, STAT_MAXDAMAGE, 0);
                    }

                    if (statValue != 0 || (nStatId != STAT_SECONDARY_MINDAMAGE && nStatId != STAT_SECONDARY_MAXDAMAGE))
                    {
                        if (hasSecondaryMinMaxDmg && !addNewline)
                        {
                            outBuff.append(strComma);
                            outBuff.append(strSpace);
                        }

                        hasSecondaryMinMaxDmg = 1;
                        outBuff.append(propertyLineBuffer256);

                        if (addNewline)
                        {
                            outBuff.append(strNewLine);
                        }
                    }
                }
            }
        }

        if (pUnit)
        {
            if (pUnit->dwUnitType == UNIT_ITEM)
            {
                auto itemTxtRecord1 = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
                if (!itemTxtRecord1->nNoDurability
                    && itemTxtRecord1->nDurability
                    && STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_INDESCTRUCTIBLE, 0) <= 0
                    && !STATLIST_GetMaxDurabilityFromUnit(pUnit))
                {
                    auto strIndestructable = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21240_ModStre9s);
                    if (hasSecondaryMinMaxDmg && !addNewline)
                    {
                        outBuff.append(strComma);
                        outBuff.append(strSpace);
                    }
                    outBuff.append(strIndestructable);
                    if (addNewline)
                    {
                        outBuff.append(strNewLine);
                    }
                }
            }
        }

        STATLIST_FreeStatList(pStatList);
    }

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
            outBuff.append(strSpace);

            if (v16 <= 0)
            {
                outBuff.append(std::to_wstring(v16));
            }
            else
            {
                outBuff.append(strPlus);
                outBuff.append(std::to_wstring(v16));
            }

            outBuff.append(strNewLine);
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

void RenderMercCloseButtonText(int32_t mouseX, int32_t mouseY) 
{
    auto closeButtonY = *D2Client_pScreenYOffset + *D2Client_pScreenHeightUI - 63;
    auto closeButtonX = *D2Client_pScreenXOffset + 272;

    if (mouseX >= closeButtonX && mouseX <= closeButtonX + 32 && mouseY >= closeButtonY - 32 && mouseY <= closeButtonY)
    {
        auto closeButtonTextY = *D2Client_pScreenYOffset + *D2Client_pScreenHeightUI - 98;
        auto closeButtonTextX = *D2Client_pScreenXOffset + 287;
        auto strClose = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4144_strClose);
        D2Win_DrawFramedText_10129((Unicode*)strClose, closeButtonTextX, closeButtonTextY, 0, 1);
    }
}

void RenderCloseButtonText(int32_t mouseX, int32_t mouseY) 
{
    auto closeButtonY = *D2Client_pScreenYOffset + *D2Client_pScreenHeightUI - 64;
    auto closeButtonX = *D2Client_pScreenWidthUI - *D2Client_pScreenXOffset - 302;

    if (mouseX >= closeButtonX && mouseX <= closeButtonX + 32 && mouseY >= closeButtonY - 32 && mouseY <= closeButtonY)
    {
        auto closeButtonTextX = *D2Client_pScreenWidthUI - *D2Client_pScreenXOffset - 287;
        auto closeButtonTextY = *D2Client_pScreenYOffset + *D2Client_pScreenHeightUI - 99;
        auto strClose = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4144_strClose);
        D2Win_DrawFramedText_10129((Unicode*)strClose, closeButtonTextX, closeButtonTextY, 0, 1);
    }
}

void RenderDropGoldText(int32_t mouseX, int32_t mouseY)
{
    auto dropGoldButtonY = *D2Client_pScreenYOffset + *D2Client_pScreenHeightUI - 69;
    auto dropGoldButtonX = *D2Client_pScreenWidthUI - *D2Client_pScreenXOffset - 237;

    if (mouseX >= dropGoldButtonX && mouseX <= dropGoldButtonX + 20 && mouseY >= dropGoldButtonY - 18 && mouseY <= dropGoldButtonY && !D2Client_sub_6FAFC0E0())
    {
        // "Drop Gold"
        auto strDropGoldButtonTextId = 4125;
        switch (*D2Client_pVendorMode_6FBB58EC)
        {
        case VENDORMODE_TRADE:
            // "Gold"
            strDropGoldButtonTextId = 4099;
            break;
        case VENDORMODE_PLRTRADE:
            // "Trade Gold"
            strDropGoldButtonTextId = 4129;
            break;
        case VENDORMODE_STASH:
        case VENDORMODE_DEPOSIT:
        case 15:
            // "Deposit"
            strDropGoldButtonTextId = 4126;
            break;
        default:
            break;
        }

        auto dropGoldButtonTextX = *D2Client_pScreenWidthUI - *D2Client_pScreenXOffset - 222;
        auto dropGoldButtonTextY = *D2Client_pScreenYOffset + *D2Client_pScreenHeightUI - 89;
        auto strDropGoldButtonText = (const wchar_t*)D2LANG_GetStringFromTblIndex(strDropGoldButtonTextId);
        D2Win_DrawFramedText_10129((Unicode*)strDropGoldButtonText, dropGoldButtonTextX, dropGoldButtonTextY, 0, 1);
    }
}

void RenderSwapWeaponsButtonText(int32_t mouseX, int32_t mouseY) 
{
    auto isExpansion = FOG_IsExpansion();
    auto isLod = D2Client_IsLod_6FAAC080();

    auto mouseIsOverRightSwapWeaponButton = (mouseX >= *D2Client_pRightSwapWeaponButtonXLeft_6FBB59BC)
        && mouseX <= *D2Client_pRightSwapWeaponButtonXRight_6FBB59C0
        && mouseY >= *D2Client_pRightSwapWeaponButtonYTop_6FBB59C4 - 24
        && mouseY < *D2Client_pRightSwapWeaponButtonYTop_6FBB59C4;

    auto mouseIsOverLeftSwapWeaponButton =
        mouseX >= *D2Client_pLeftSwapWeaponButtonXLeft_6FBB59A8 &&
        mouseX <= *D2Client_pLeftSwapWeaponButtonXRight_6FBB59AC &&
        mouseY >= *D2Client_pLeftSwapWeaponButtonYTop_6FBB59B0 - 24 &&
        mouseY < *D2Client_pLeftSwapWeaponButtonYTop_6FBB59B0;

    if (isExpansion && isLod && (mouseIsOverRightSwapWeaponButton || mouseIsOverLeftSwapWeaponButton))
    {
        const auto kWeaponSwapHotkeyIndex = 44;

        auto framedTextXOffset = 368;
        if (mouseX > *D2Client_pScreenXOffset + 500)
        {
            framedTextXOffset = 600;
        }

        auto primaryHotkeyCode = D2Client_GetHotkeyCharCode_6FAD4B60(kWeaponSwapHotkeyIndex, 0);
        auto secondaryHotkeyCode = D2Client_GetHotkeyCharCode_6FAD4B60(kWeaponSwapHotkeyIndex, 0);

        int32_t useAlternativeHotkey = -1;
        if (primaryHotkeyCode != -1)
        {
            useAlternativeHotkey = 0;
        }
        else if (secondaryHotkeyCode != -1)
        {
            useAlternativeHotkey = 1;
        }

        std::wstring buttonText = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_22726_Cfgswapweapons);

        if (useAlternativeHotkey != -1)
        {
            auto strColon = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3997_colon);
            auto strWeaponSwapHotkey = (wchar_t*)D2Client_GetHotkeyString_6FAD56B0(kWeaponSwapHotkeyIndex, useAlternativeHotkey);

            buttonText.append(strColon);
            buttonText.append(strWeaponSwapHotkey);
        }

        D2Win_DrawFramedText_10129((const Unicode*)buttonText.c_str(), framedTextXOffset + *D2Client_pScreenXOffset, 21 - *D2Client_pScreenYOffset, 0, 1);
    }
}

void __fastcall ESE_D2Client_GetItemTextLineBookQuantity_6FAE54B0(D2UnitStrc* pUnit, std::wstring &outBuff, D2ItemsTxt* pItemTxtRecord)
{
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);

    if (STATLIST_UnitGetStatValue(pUnit, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(pUnit) > 0)
    {
        int32_t nQuantity = STATLIST_UnitGetStatValue(pUnit, STAT_QUANTITY, 0);
        const wchar_t* strQuantity = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3462_ItemStats1i);

        outBuff.append(strQuantity);
        outBuff.append(strSpace);
        outBuff.append(std::to_wstring(nQuantity));
        outBuff.append(strNewLine);
    }
}

void DrawTextForNonSetOrUnidSetItem(D2UnitStrc* v229, int32_t bFlag, int itemQuality)
{
    std::wstring itemDescription;
    itemDescription.reserve(4096);
    wchar_t scratchpad[8192] = { 0 };

    auto pItemUnderCursor = *D2Client_pItemUnderCursor;
    if (pItemUnderCursor == nullptr)
    {
        return;
    }

    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);

    int32_t colorCodeClassRestriction = 0;
    int32_t colorCodeDexRequirement = 0;
    int32_t colorCodeStrRequirement = 0;
    int32_t colorCodeLevelRequirement = 0;

    if (ITEMS_GetItemType(pItemUnderCursor) == ITEMTYPE_BOOK)
    {
        if (!pItemUnderCursor || ITEMS_GetItemType(pItemUnderCursor) != ITEMTYPE_BOOK)
        {
            FOG_DisplayAssert("sghSelItem && ITEMSGetType(sghSelItem) == ITEMTYPE_BOOK", __FILE__, __LINE__);
            exit(-1);
        }

        auto pItemTxtRecord = DATATBLS_GetItemsTxtRecord(pItemUnderCursor->dwClassId);
        if (!pItemTxtRecord)
        {
            FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
            exit(-1);
        }

        scratchpad[0] = 0;
        ESE_D2Client_GetItemTextLineBookQuantity_6FAE54B0(pItemUnderCursor, itemDescription, pItemTxtRecord);
        if (*D2Client_pVendorMode_6FBB58EC == VENDORMODE_NONE)
        {
            auto strRightClickToUse = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2203_RightClicktoUse);
            itemDescription.append(strRightClickToUse);
            itemDescription.append(strNewLine);

            auto strInsertScrolls = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2206_InsertScrolls);
            itemDescription.append(strInsertScrolls);
            itemDescription.append(strNewLine);
        }

        scratchpad[0] = 0;
        D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
        itemDescription.append(scratchpad);

        if (*D2Client_pVendorMode_6FBB58EC >= VENDORMODE_TRADE && *D2Client_pVendorMode_6FBB58EC <= VENDORMODE_UNKNOWN)
        {
            scratchpad[0] = 0;
            D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode*)itemDescription.c_str(), (Unicode*)scratchpad);
            itemDescription = std::wstring(scratchpad);
        }

        int32_t height = 0;
        int32_t width = 0;
        D2Win_GetTextDimensions_10131((const Unicode*)itemDescription.c_str(), &width, &height);

        if (*D2Client_pItemUnderCursorPosYb_6FB79294 - height > 0)
        {
            D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosXb_6FB79290, *D2Client_pItemUnderCursorPosYb_6FB79294, 0, 0);
            return;
        }

        D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosX_6FB79298, height + *D2Client_pItemUnderCursorPosY_6FB7929C, 0, 0);
        return;
    }

    std::wstring statLine_ClassRestriction_512;
    auto v132 = ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor);
    if (v132 != PCLASS_EVILFORCE)
    {
        auto v134 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v132 + 10917);
        statLine_ClassRestriction_512.append(v134);
        statLine_ClassRestriction_512.append(strNewLine);

        auto v135 = v229 ? v229->dwClassId : -1;

        if (v135 != v132)
        {
            colorCodeClassRestriction = 1;
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
        if (STATLIST_UnitGetStatValue(pItemUnderCursor, STAT_QUANTITY, 0) > 0)
        {
            // TODO: This is going to be wiped out later with a strcpy to itemDescription...
            auto v143 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3462_ItemStats1i);
            itemDescription.append(v143);

            auto itemQuantity = STATLIST_UnitGetStatValue(pItemUnderCursor, STAT_QUANTITY, 0);
            itemDescription.append(strSpace);
            itemDescription.append(std::to_wstring(itemQuantity));
            itemDescription.append(strNewLine);

            auto v145 = (const wchar_t*)D2LANG_GetStringFromTblIndex(itemTxtRecord->wNameStr);
            itemDescription.append(v145);
        }
    }
    else
    {
        scratchpad[0] = 0;
        D2Client_GetItemTextLineDurability_6FAE4060(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
        statLine_Durability_512.append(scratchpad);
    }

    std::wstring statLine_RequiredLevel512;
    BOOL bRequiresDex = false;
    BOOL bRequiresStr = false;
    BOOL bRequiresLevel = false;
    ITEMS_CheckRequirements(pItemUnderCursor, v229, 0, &bRequiresStr, &bRequiresDex, &bRequiresLevel);
    if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_IDENTIFIED, __LINE__, __FILE__))
    {
        auto levelRequirement = ITEMS_GetLevelRequirement(pItemUnderCursor, v229);
        if (levelRequirement > 1)
        {
            if (!bRequiresLevel)
            {
                colorCodeLevelRequirement = 1;
            }

            auto strRequiredLevel = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3469_ItemStats1p);

            statLine_RequiredLevel512.append(strRequiredLevel);
            statLine_RequiredLevel512.append(strSpace);
            statLine_RequiredLevel512.append(std::to_wstring(levelRequirement));
            statLine_RequiredLevel512.append(strNewLine);
        }
    }

    std::wstring statLine_RuneGemStats_512;
    if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_SOCKET_FILLER))
    {
        if (!D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_SOCKET_FILLER))
        {
            FOG_DisplayAssert("ITEMSIsA(sghSelItem, ITEMTYPE_SOCKETFILLER_TYPE)", __FILE__, __LINE__);
            exit(-1);
        }
        scratchpad[0] = 0;
        D2Client_GetItemTextLineRuneGemStats_6FAF1480(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
        auto v153 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11080_ExInsertSocketsX);
        statLine_RuneGemStats_512.append(v153);
        statLine_RuneGemStats_512.append(strNewLine);
    }

    std::wstring statLine_RunewordName_512;
    if (ITEMS_CheckIfSocketable(pItemUnderCursor))
    {
        if (pItemUnderCursor->pInventory)
        {
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
                                    auto v163 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_20506_RuneQuote);
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
                    statLine_RunewordName_512.append(strNewLine);
                }
            }
        }
    }

    std::wstring statLine_CharmKeepInInv_512;
    if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_CHARM))
    {
        auto strCharmDes = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_20438_Charmdes);
        statLine_CharmKeepInInv_512.append(strCharmDes);
        statLine_CharmKeepInInv_512.append(strNewLine);
    }

    std::wstring statLine_Socketed_512;
    std::wstring statLine_RequiredDexterity_256;
    std::wstring statLine_RequiredStength_256;
    std::wstring statLine_Damage_512;
    std::wstring statLine_AttackSpeed_2048;
    std::wstring statLine_blockChance_512;
    std::wstring statLine_v273_512;
    std::wstring statLine_Defense_512;

    if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_WEAPON) || D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR))
    {
        scratchpad[0] = 0;
        D2Client_GetItemTextSocketed_6FAE3EE0(pItemUnderCursor, (Unicode*)scratchpad);
        statLine_Socketed_512.append(scratchpad);

        auto requiredDex = 0;
        auto requiredStr = 0;

        auto itemRequirementPercent = STATLIST_UnitGetItemStatOrSkillStatValue(pItemUnderCursor, STAT_ITEM_REQ_PERCENT, 0);
        if (itemRequirementPercent)
        {
            requiredStr = DATATBLS_ApplyRatio(itemRequirementPercent, itemTxtRecord->wReqStr, 100);
            requiredDex = DATATBLS_ApplyRatio(itemRequirementPercent, itemTxtRecord->wReqDex, 100);
        }

        if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_ETHEREAL, __LINE__, __FILE__))
        {
            requiredStr -= 10;
            requiredDex -= 10;
        }

        if (itemTxtRecord->wReqDex)
        {
            if (!bRequiresDex)
            {
                colorCodeDexRequirement = 1;
            }

            auto totalRequiredDex = requiredDex + itemTxtRecord->wReqDex;
            if (totalRequiredDex > 0)
            {
                auto strRequiredDex = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3459_ItemStats1f);

                statLine_RequiredDexterity_256.append(strRequiredDex);
                statLine_RequiredDexterity_256.append(strSpace);
                statLine_RequiredDexterity_256.append(std::to_wstring(totalRequiredDex));
                statLine_RequiredDexterity_256.append(strNewLine);
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
                colorCodeStrRequirement = 1;
            }

            auto totalRequiredStr = requiredStr + itemTxtRecord->wReqStr;
            if (totalRequiredStr > 0)
            {
                auto strRequiredStr = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3458_ItemStats1e);

                statLine_RequiredStength_256.append(strRequiredStr);
                statLine_RequiredStength_256.append(strSpace);
                statLine_RequiredStength_256.append(std::to_wstring(totalRequiredStr));
                statLine_RequiredStength_256.append(strNewLine);
            }
        }

        if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_WEAPON))
        {
            if (STATLIST_GetMinDamageFromUnit(pItemUnderCursor, 0) >= 0 && STATLIST_GetMaxDamageFromUnit(pItemUnderCursor, 0) >= 0)
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
            if (v229 && v229->dwClassId == 3 && (!ITEMS_IsClassValid(pItemUnderCursor) || ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor) == PCLASS_PALADIN))
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
        && *D2Client_pVendorMode_6FBB58EC >= VENDORMODE_TRADE
        && *D2Client_pVendorMode_6FBB58EC <= VENDORMODE_UNKNOWN
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
            if (STATLIST_UnitGetStatValue(pItemUnderCursor, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(pItemUnderCursor) > 0)
            {
                auto strQuantity = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3462_ItemStats1i);
                auto quantity = STATLIST_UnitGetStatValue(pItemUnderCursor, STAT_QUANTITY, 0);
                statLine_Quantity_512.append(strQuantity);
                statLine_Quantity_512.append(strSpace);
                statLine_Quantity_512.append(std::to_wstring(quantity));
                statLine_Quantity_512.append(strNewLine);
            }
        }

        scratchpad[0] = 0;
        ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItemUnderCursor, statLine_Stats_8192, std::size(scratchpad), 1, 0);
    }
    else
    {
        auto v184 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3455_ItemStats1b);
        itemLineUnidentified.append(v184);
        itemLineUnidentified.append(strNewLine);
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
    AppendColorizedString(itemDescription, statLine_RequiredLevel512, colorCodeLevelRequirement);
    AppendColorizedString(itemDescription, statLine_RequiredStength_256, colorCodeStrRequirement);
    AppendColorizedString(itemDescription, statLine_RequiredDexterity_256, colorCodeDexRequirement);
    AppendColorizedString(itemDescription, statLine_ClassRestriction_512, colorCodeClassRestriction);
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

    if (*D2Client_pVendorMode_6FBB58EC && *D2Client_pVendorMode_6FBB58EC >= VENDORMODE_TRADE && *D2Client_pVendorMode_6FBB58EC <= VENDORMODE_UNKNOWN)
    {
        scratchpad[0] = 0;
        D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode*)itemDescription.c_str(), (Unicode*)scratchpad);
        itemDescription = std::wstring(scratchpad);
    }

    if (!itemTxtRecord->nQuest || itemTxtRecord->dwCode == 543647084)
    {
        int32_t nWidth = 0;
        int32_t nHeight = 0;
        D2Win_GetTextDimensions_10131((const Unicode*)itemDescription.c_str(), &nWidth, &nHeight);
        if (*D2Client_pItemUnderCursorPosYb_6FB79294 - nHeight > 0)
        {
            D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosXb_6FB79290, *D2Client_pItemUnderCursorPosYb_6FB79294, 0, 1);
            return;
        }

        D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosX_6FB79298, (*D2Client_pItemUnderCursorPosY_6FB7929C + nHeight), 0, 1);
        return;
    }

    if (*D2Client_pVendorMode_6FBB58EC == VENDORMODE_NONE && (!pItemUnderCursor || !pItemUnderCursor->dwAnimMode))
    {
        if (itemTxtRecord->dwCode == 543452002)
        {
            auto strRightClickToRead = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2205_RightClicktoRead);
            itemDescription.insert(0, std::wstring(strRightClickToRead) + std::wstring(strNewLine));
        }
        else if (itemTxtRecord->dwCode == 544763746)
        {
            auto strRightClickToOpen = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2204_RightClicktoOpen);
            itemDescription.insert(0, std::wstring(strRightClickToOpen) + std::wstring(strNewLine));
        }
    }

    ColorizeString(itemDescription, 4);

    int32_t nWidth = 0;
    int32_t nHeight = 0;
    D2Win_GetTextDimensions_10131((const Unicode*)itemDescription.c_str(), &nWidth, &nHeight);
    if (*D2Client_pItemUnderCursorPosYb_6FB79294 - nHeight > 0)
    {
        D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosXb_6FB79290, *D2Client_pItemUnderCursorPosYb_6FB79294, 4, 1);
        return;
    }

    D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosX_6FB79298, (*D2Client_pItemUnderCursorPosY_6FB7929C + nHeight), 4, 1);
    return;
}

void DrawTextForSetItem(D2UnitStrc* pUnit_, int32_t bFlag, int itemQuality)
{
    std::wstring itemDescription;
    itemDescription.reserve(4096);
    wchar_t scratchpad[8192] = { 0 };

    auto pItemUnderCursor = *D2Client_pItemUnderCursor;
    if (pItemUnderCursor == nullptr)
    {
        return;
    }

    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    // Set items
    auto pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItemUnderCursor->dwClassId);
    if (!pItemsTxtRecord)
    {
        FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
        exit(-1);
    }

    int32_t colorCodeLevelRequirement = 0;
    int32_t colorCodeStrRequirement = 0;
    int32_t colorCodeDexRequirement = 0;

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

            auto setName = (const wchar_t*)D2LANG_GetStringFromTblIndex(setsTxtRecord->wStringId);
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
                    colorCodeLevelRequirement = 1;
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
                        colorCodeStrRequirement = 1;
                    }

                    scratchpad[0] = 0;
                    D2Client_GetItemTextStrRequirement_6FAE4250((Unicode*)scratchpad, pItemsTxtRecord, strRequirement);
                    itemLineStrRequirement.append(scratchpad);
                }
                if (pItemsTxtRecord->wReqDex)
                {
                    if (!bRequiresDex)
                    {
                        colorCodeDexRequirement = 1;
                    }

                    scratchpad[0] = 0;
                    D2Client_GetItemTextDexRequirement_6FAE4310((Unicode*)scratchpad, pItemsTxtRecord, dexRequirement);
                    itemLineDexRequirement.append(scratchpad);
                }
            }

            AppendColorizedString(itemLineBasicInfo, itemLineLevelRequirement, colorCodeLevelRequirement);
            AppendColorizedString(itemLineBasicInfo, itemLineStrRequirement, colorCodeStrRequirement);
            AppendColorizedString(itemLineBasicInfo, itemLineDexRequirement, colorCodeDexRequirement);
            auto itemClassRestriction = ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor);
            if (itemClassRestriction != PCLASS_EVILFORCE)
            {
                std::wstring itemLineUnknownB;

                auto strClassRestriction = (const wchar_t*)D2LANG_GetStringFromTblIndex(itemClassRestriction + 10917);
                itemLineUnknownB.append(strClassRestriction);
                itemLineUnknownB.append(strNewLine);

                int32_t colorCodeClassRestriction = 0;
                if (pUnit_ && !pUnit_->dwUnitType && pUnit_->dwClassId != itemClassRestriction)
                {
                    colorCodeClassRestriction = 1;
                }
                AppendColorizedString(itemLineBasicInfo, itemLineUnknownB, colorCodeClassRestriction);
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

                    D2UnitStrc* setItem = D2Client_sub_6FAE5990(pUnit_->pInventory, pUnita->wSetItemId);
                    scratchpadBuffer.clear();

                    if (pUnita->wStringId)
                    {
                        auto strSetItemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pUnita->wStringId);
                        auto strSetItemNameFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_10089_SetItemFormatX);

                        scratchpad[0] = 0;
                        D2Client_sub_6FADCFE0((Unicode*)scratchpad, (const Unicode*)strSetItemNameFormat, (const Unicode*)strSetItemName, 0);
                        scratchpadBuffer.append(scratchpad);
                        scratchpadBuffer.append(strNewLine);
                    }
                    AppendColorizedString(textLineSetNames, scratchpadBuffer, setItem ? 2 : 1);
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

            if (*D2Client_pVendorMode_6FBB58EC != VENDORMODE_NONE && *D2Client_pVendorMode_6FBB58EC >= 1 && *D2Client_pVendorMode_6FBB58EC <= 9)
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
                    if (*D2Client_pVendorMode_6FBB58EC != VENDORMODE_REPAIR)
                    {
                        pTextToDisplay.append(strNewLine);

                        auto strItemCannotBeSold = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3333_priceless);
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
            D2Win_GetTextDimensions_10131((const Unicode*)pTextToDisplay.c_str(), &width, &height);

            if (*D2Client_pItemUnderCursorPosYb_6FB79294 - height > 0)
            {
                D2Win_DrawFramedText_10129((const Unicode*)pTextToDisplay.c_str(), *D2Client_pItemUnderCursorPosXb_6FB79290, *D2Client_pItemUnderCursorPosYb_6FB79294, 0, 1);
                return;
            }

            auto v120 = height + *D2Client_pItemUnderCursorPosY_6FB7929C;
            D2Win_DrawFramedText_10129((const Unicode*)pTextToDisplay.c_str(), *D2Client_pItemUnderCursorPosX_6FB79298, v120, 0, 1);
            return;
        }
    }
}

void DrawTextForTransmogrifyItem(D2UnitStrc* pItemUnderCursor)
{
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    std::wstring itemDescription;
    itemDescription.reserve(4096);
    wchar_t scratchpad[8192] = { 0 };

    if (!ITEMS_GetTransmogrify(pItemUnderCursor))
    {
        return;
    }

    auto ptOldItemStats = DATATBLS_GetItemsTxtRecord(pItemUnderCursor->dwClassId);
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

    auto strItemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(ptNewItemStats->wNameStr);
    auto strConvertsTo = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5387_convertsto);

    scratchpad[0] = 0;
    D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));

    itemDescription.append(strItemName);
    itemDescription.append(strNewLine);
    itemDescription.append(strConvertsTo);
    itemDescription.append(strNewLine);
    itemDescription.append(scratchpad);

    if (*D2Client_pVendorMode_6FBB58EC >= VENDORMODE_TRADE && *D2Client_pVendorMode_6FBB58EC <= VENDORMODE_UNKNOWN)
    {
        scratchpad[0] = 0;
        D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode*)itemDescription.c_str(), (Unicode*)scratchpad);
        itemDescription = std::wstring(scratchpad);
    }

    int32_t height = 0;
    int32_t width = 0;
    D2Win_GetTextDimensions_10131((const Unicode*)itemDescription.c_str(), &height, &width);

    if (*D2Client_pItemUnderCursorPosYb_6FB79294 - width > 0)
    {
        D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosXb_6FB79290, *D2Client_pItemUnderCursorPosYb_6FB79294, 0, 0);
        return;
    }

    D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosX_6FB79298, width + *D2Client_pItemUnderCursorPosY_6FB7929C, 0, 0);
}

void DrawTextForGambleItem(D2UnitStrc* pItemUnderCursor)
{
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    std::wstring itemDescription;
    itemDescription.reserve(4096);
    wchar_t scratchpad[8192] = { 0 };

    scratchpad[0] = 0;
    D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
    auto strUnidentified = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3455_ItemStats1b);
    itemDescription.append(strUnidentified);
    itemDescription.append(strNewLine);

    int32_t classRequirementStringId = 0;
    switch (ITEMS_GetItemType(pItemUnderCursor))
    {
    case ITEMTYPE_AMAZON_ITEM:
    case ITEMTYPE_AMAZON_BOW:
    case ITEMTYPE_AMAZON_SPEAR:
    case ITEMTYPE_AMAZON_JAVELIN:
        classRequirementStringId = STR_IDX_10917_AmaOnly;
        break;
    case ITEMTYPE_BARBARIAN_ITEM:
    case ITEMTYPE_PRIMAL_HELM:
        classRequirementStringId = STR_IDX_10921_BarOnly;
        break;
    case ITEMTYPE_NECROMANCER_ITEM:
    case ITEMTYPE_VOODOO_HEADS:
        classRequirementStringId = STR_IDX_10919_NecOnly;
        break;
    case ITEMTYPE_PALADIN_ITEM:
    case ITEMTYPE_AURIC_SHIELDS:
        classRequirementStringId = STR_IDX_10920_PalOnly;
        break;
    case ITEMTYPE_SORCERESS_ITEM:
    case ITEMTYPE_ORB:
        classRequirementStringId = STR_IDX_10918_SorOnly;
        break;
    case ITEMTYPE_ASSASSIN_ITEM:
    case ITEMTYPE_HAND_TO_HAND:
    case ITEMTYPE_HAND_TO_HAND_2:
        classRequirementStringId = STR_IDX_10923_AssOnly;
        break;
    case ITEMTYPE_DRUID_ITEM:
    case ITEMTYPE_PELT:
    case ITEMTYPE_CLOAK:
        classRequirementStringId = STR_IDX_10922_DruOnly;
        break;
    default:
        break;
    }

    if (classRequirementStringId > 0)
    {
        auto strClassRequirement = (const wchar_t*)D2LANG_GetStringFromTblIndex(classRequirementStringId);
        itemDescription.append(strClassRequirement);
        itemDescription.append(strNewLine);
    }

    itemDescription.append(scratchpad);
    ColorizeString(itemDescription, 0);

    scratchpad[0] = 0;
    D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode*)itemDescription.c_str(), (Unicode*)scratchpad);
    itemDescription = std::wstring(scratchpad);

    int32_t nWidth = 0;
    int32_t nHeight = 0;
    D2Win_GetTextDimensions_10131((const Unicode*)itemDescription.c_str(), &nWidth, &nHeight);

    if (*D2Client_pItemUnderCursorPosYb_6FB79294 - nHeight > 0)
    {
        D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosXb_6FB79290, *D2Client_pItemUnderCursorPosYb_6FB79294, 0, 1);
        return;
    }

    D2Win_DrawFramedText_10129((const Unicode*)itemDescription.c_str(), *D2Client_pItemUnderCursorPosX_6FB79298, *D2Client_pItemUnderCursorPosY_6FB7929C + nHeight, 0, 1);
}

void __fastcall ESE_UI_INV_DrawMouseOverItemFrame_6FAE1890(D2UnitStrc* pUnit, int32_t bFlag)
{
    auto pItemUnderCursor = *D2Client_pItemUnderCursor;

    D2UnitStrc* v229 = pUnit;
    if (bFlag && D2Client_GetCurrentPlayer_6FB283D0())
    {
        v229 = D2Client_GetCurrentPlayer_6FB283D0();
    }

    if (!D2Client_IsBeltOpen_6FAFE9E0())
    {
        auto mouseX = D2Client_GetMouseXPos();
        auto mouseY = D2Client_GetMouseYPos();

        if (D2Client_IsUiOpen_6FB23230(UI_MERCINV))
        {
            RenderMercCloseButtonText(mouseX, mouseY);
        }

        if (D2Client_IsUiOpen_6FB23230(UI_INVENTORY)
            || D2Client_IsUiOpen_6FB23230(UI_MPTRADE)
            || D2Client_IsUiOpen_6FB23230(UI_STASH)
            || D2Client_IsUiOpen_6FB23230(UI_NPCSHOP)
            || D2Client_IsUiOpen_6FB23230(UI_ANVIL)
            || D2Client_IsUiOpen_6FB23230(UI_CUBE))
        {
            RenderCloseButtonText(mouseX, mouseY);
            RenderDropGoldText(mouseX, mouseY);
            RenderSwapWeaponsButtonText(mouseX, mouseY);
        }
    }

    if (!*D2Client_pIsItemUnderCursorEquipped_6FBB58E4 && !*D2Client_pIsItemUnderCursorInInventory_6FBB58E0)
    {
        return;
    }

    if (!pItemUnderCursor)
    {
        return;
    }

    if (!pUnit->pInventory)
    {
        return;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return;
    }

    if (!D2Client_IsUiOpen_6FB23230(UI_MPTRADE)
        && pUnit->pInventory
        && !INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItemUnderCursor))
    {
        return;
    }

    if (*D2Client_pIsItemUnderCursorInInventory_6FBB58E0 && !*D2Client_pDWORD_6FB7928C && D2Client_IsGambling_6FAFC130() && *D2Client_pVendorMode_6FBB58EC >= VENDORMODE_TRADE && *D2Client_pVendorMode_6FBB58EC <= VENDORMODE_UNKNOWN)
    {
        DrawTextForGambleItem(pItemUnderCursor);
        return;
    }

    auto itemQuality = ITEMS_GetItemQuality(pItemUnderCursor);
    if (D2Client_sub_6FB57CC0() == 8 || ITEMS_GetTransmogrify(pItemUnderCursor))
    {
        DrawTextForTransmogrifyItem(pItemUnderCursor);
        return;
    }

    if (itemQuality != ITEMQUAL_SET || !ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_IDENTIFIED, __LINE__, __FILE__))
    {
        DrawTextForNonSetOrUnidSetItem(v229, bFlag, itemQuality);
        return;
    }

    auto pUnit_ = pUnit;
    if (pUnit->dwUnitType == UNIT_MONSTER && !MONSTERS_GetHirelingTypeId(pUnit))
    {
        pUnit_ = D2Client_GetCurrentPlayer_6FB283D0();
    }

    bool itemIsEquippedOrInInventory = (*D2Client_pIsItemUnderCursorEquipped_6FBB58E4 || *D2Client_pIsItemUnderCursorInInventory_6FBB58E0);
    if (itemIsEquippedOrInInventory && !INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        DrawTextForSetItem(pUnit_, bFlag, itemQuality);
        return;
    }
}

