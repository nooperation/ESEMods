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
#include <bitset>
#include <bit>

void ESE_D2Client_GetItemTextLineAttackSpeed_6FAE5570(D2UnitStrc* pItem, std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord);

std::wstring FormatWideString(const wchar_t* fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    size_t required = std::vswprintf(NULL, 0, fmt, ap);
    va_end(ap);

    va_start(ap, fmt);
    std::wstring buffer(required, L'\0');
    std::vswprintf(&buffer[0], buffer.size() + 1, fmt, ap);
    va_end(ap);

    return buffer;
}

void AppendFormattedWideString(std::wstring& outBuff, const wchar_t* fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    size_t required = std::vswprintf(NULL, 0, fmt, ap);
    va_end(ap);

    va_start(ap, fmt);
    std::wstring buffer(required, L'\0');
    std::vswprintf(&buffer[0], buffer.size() + 1, fmt, ap);
    va_end(ap);

    outBuff.append(buffer);
}

std::wstring BuildItemName_StripBracketPrefix(const std::wstring& input)
{
    auto index = input.find_last_of(L']');

    if (index == std::wstring::npos || index < 3 || input[index - 3] != L'[')
    {
        return input;
    }

    return input.substr(index + 1);
}

std::wstring ToWideString(const char* source)
{
    std::string str(source);
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    return converter.from_bytes(str);
}

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

void ESE_D2LANG_UnicodePersonalize_6FC11D50(std::wstring& outBuff, const std::wstring& subjectName, const std::wstring& itemName, int32_t language)
{
    // static const char* byte_6FC1D100 = "s"; // D100
    // static const char* byte_6FC1D0FC = "'s "; // D0FC
    // static const char* byte_6FC1D0F8 = "' "; // D0F8
    // static const char* byte_6FC1D0F0 = " de "; // D0F0
    // static const char* byte_6FC1D0E8 = "s "; // D0E8
    // static const char* byte_6FC1D0D4 = " di "; // D0D4
    // static const char* byte_6FC1D0D0 = "("; // D0D0
    // static const char* byte_6FC1D0CC = ")"; // D0CC
    // static const char* byte_6FC1D0C8 = " "; // D0C8
    // static const char* byte_6FC1D0DC = " d'"; // D0DC

    switch (language)
    {
    case LANGUAGE_ENGLISH:
    case LANGUAGE_ENGLISHKOR:
    {
        outBuff.assign(subjectName);

        if (subjectName.ends_with(L"s"))
        {
            outBuff.append(L"' ");
        }
        else
        {
            outBuff.append(L"'s ");
        }

        outBuff.append(itemName);
        return;
    }
    case LANGUAGE_SPANISH:
    {
        outBuff.assign(itemName);
        outBuff.append(L" de ");
        outBuff.append(subjectName);
        return;
    }
    case LANGUAGE_GERMAN:
    {
        const wchar_t lastChar = subjectName[subjectName.length() - 1];

        outBuff.assign(subjectName);

        if (lastChar == L's' || lastChar == L'z')
        {
            outBuff.append(L"' ");
        }
        else
        {
            outBuff.append(L"s ");
        }

        outBuff.append(itemName);
        return;
    }
    case LANGUAGE_FRENCH:
    {
        outBuff.assign(itemName);

        if (subjectName[0] == L'a' || subjectName[0] == L'e' || subjectName[0] == L'i' || subjectName[0] == L'o' || subjectName[0] == L'u')
        {
            outBuff.assign(L" d'");
        }
        else
        {
            outBuff.assign(L" de ");
        }

        outBuff.append(subjectName);
        return;
    }
    case LANGUAGE_ITALIAN:
    {
        outBuff.assign(itemName);
        outBuff.assign(L" di ");
        outBuff.assign(subjectName);
        return;
    }
    }

    outBuff.assign(L"(");
    outBuff.append(subjectName);
    outBuff.append(L") ");
    outBuff.append(itemName);
    return;
}

/*
    Replaces a single format token when the specified replacement string, storing the results in 'formatBuff'

    Replace token 1 "%1" with L"World":
        ESE_D2Client_ReplaceNameFormatToken_6FADCF10(formatBuff, 1, L"%0 %1", L"World", 0);
        formatBuff == L"%0 World";

    Replace token 0 "%0" with L"Hello"
        ESE_D2Client_ReplaceNameFormatToken_6FADCF10(formatBuff, 0, L"%0 World", L"Hello", 0);
        formatBuff == L"Hello World";
*/
void ESE_D2Client_ReplaceNameFormatToken_6FADCF10(std::wstring& formatBuff, int tokenIndex, const wchar_t* replacement)
{
    std::wstring indexStr = L"%" + std::to_wstring(tokenIndex);

    size_t indexPos = formatBuff.find(indexStr);
    if (indexPos != std::wstring::npos) {
        formatBuff.replace(indexPos, indexStr.length(), replacement);
    }
}

/*
     All of the following should result in buff equal to L"Hello World". Note that any call to this MUST have 0 or nullptr as the last argument

         D2Client_FormatName_6FADCFE0(buff, L"a0n1:%0 %1", L"Hello", L"World", 0);
         D2Client_FormatName_6FADCFE0(buff, L"a0n1:%0 %1", L"[ns]incorrect[dd]bad bad bad[ms]Hello[mb]wrong", L"[ms]World", 0);
         D2Client_FormatName_6FADCFE0(buff, L"a0:%0", L"[ns]incorrect[ms]Hello World[fs]wrong", 0);
         D2Client_FormatName_6FADCFE0(buff, L"a0:%0", L"[ns]incorrect[ms]Hello World", 0);
         D2Client_FormatName_6FADCFE0(buff, L"n0:%0", L"[ms]Hello World", 0);
         D2Client_FormatName_6FADCFE0(buff, L"%0", L"Hello World", 0);
         D2Client_FormatName_6FADCFE0(buff, L"%0 %1", L"Hello", L"World", 0);
 */
void ESE_D2Client_FormatName_6FADCFE0(std::wstring& outBuff, const wchar_t* format, ...)
{
    if (!format)
    {
        return;
    }

    std::vector<std::wstring> arguments;
    va_list args;
    va_start(args, format);

    while (true)
    {
        wchar_t* currentArg = va_arg(args, wchar_t*);
        if (currentArg == nullptr)
        {
            break;
        }

        arguments.push_back(std::wstring(currentArg));
    }

    std::wstring formatStr(format);
    va_end(args);

    auto colonIndex = formatStr.find_first_of(L':');
    if (colonIndex != std::wstring::npos)
    {
        // Hiquality 	    Superior 	[fs]superior[ms]superior[fp]superiores[mp]superiores
        // HiqualityFormat 	%0 %1 	    a0n1:%1 %0
        // 
        // HiqualityFormat "a0n1:%0 %1"
        // Monster2Format "a0n1:%1 %0 %2"

        const std::wstring defaultMarker = L"[ms]";

        int32_t argumentIndexA = -1;
        int32_t argumentIndexN = -1;

        auto formatIndexA = formatStr.find_first_of(L'a');
        if (formatIndexA != std::wstring::npos && formatIndexA < colonIndex)
        {
            argumentIndexA = formatStr[formatIndexA + 1] - '0';
        }

        auto formatIndexN = formatStr.find_first_of(L'n');
        if (formatIndexN != std::wstring::npos && formatIndexN < colonIndex)
        {
            argumentIndexN = formatStr[formatIndexN + 1] - '0';
        }

        if (argumentIndexA == -1)
        {
            if (argumentIndexN != -1)
            {
                arguments[argumentIndexN] = arguments[argumentIndexN].substr(4);
            }
        }
        else if (argumentIndexN == -1)
        {
            const auto& argument = arguments[argumentIndexA];
            auto markerIndex = argument.find(defaultMarker);
            if (markerIndex != std::wstring::npos)
            {
                auto nextMarkerIndex = argument.find_first_of(L'[', markerIndex + 1);
                if (nextMarkerIndex != std::wstring::npos)
                {
                    arguments[argumentIndexA] = argument.substr(markerIndex + 4, nextMarkerIndex - (markerIndex + 4));
                }
                else
                {
                    arguments[argumentIndexA] = argument.substr(markerIndex + 4);
                }
            }
        }
        else
        {
            std::wstring customMarker = defaultMarker;

            if (arguments[argumentIndexN][0] == L'[')
            {
                customMarker = arguments[argumentIndexN].substr(0, 4);
                arguments[argumentIndexN] = arguments[argumentIndexN].substr(4);
            }

            const auto& argumentA = arguments[argumentIndexA];
            if (argumentA[0] == L'[')
            {
                auto markerIndex = argumentA.find(customMarker);
                if (markerIndex != std::wstring::npos)
                {
                    auto nextMarkerIndex = argumentA.find_first_of(L'[', markerIndex + 1);

                    auto parsedArgument = argumentA.substr(markerIndex + 4, nextMarkerIndex - (markerIndex + 4));
                    arguments[argumentIndexA] = parsedArgument;
                }
            }
        }

        outBuff.assign(formatStr.substr(colonIndex + 1));
    }
    else
    {
        outBuff.assign(formatStr);
    }

    for (size_t i = 0; i < arguments.size(); i++)
    {
        ESE_D2Client_ReplaceNameFormatToken_6FADCF10(outBuff, i, arguments[i].c_str());
    }
}

void ESE_D2Client_GetItemTextLineDefense_6FAE51D0(D2UnitStrc* pUnit, D2UnitStrc* pItem, std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord)
{
    if (!pUnit)
    {
        return;
    }

    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    int32_t pStatNotDynamic = 0;
    D2UnitStrc* pOwner = STATLIST_GetOwner(*D2Client_pItemUnderCursor, &pStatNotDynamic);

    int32_t hasOwner = pOwner != 0;
    if (pOwner && pUnit != pOwner)
    {
        pUnit = pOwner;
    }

    STATLIST_MergeStatLists(pUnit, *D2Client_pItemUnderCursor, 1);
    int32_t defense = STATLIST_GetDefenseFromUnit(*D2Client_pItemUnderCursor);
    if (hasOwner)
    {
        STATLIST_MergeStatLists(pOwner, *D2Client_pItemUnderCursor, (BOOL)pItem);
    }
    else
    {
        STATLIST_ExpireUnitStatlist(pUnit, *D2Client_pItemUnderCursor);
    }

    pStatNotDynamic = STATLIST_GetUnitBaseStat(pItem, STAT_ARMORCLASS, 0) != defense;
    int32_t armorByTime = STATLIST_UnitGetStatValue(pItem, STAT_ITEM_ARMOR_BYTIME, 0);
    if (armorByTime)
    {
        // I have no idea what's going on here, but it doesn't really matter because nobody uses time of day based stuff
        if (sgptDataTables->nItemStatCostTxtRecordCount > 268 && sgptDataTables->pItemStatCostTxt != (D2ItemStatCostTxt*)-86832)
        {
            if (pUnit->pDrlgAct)
            {
                int32_t baseTime = 0;
                int32_t periodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &baseTime);
                int32_t armorTimeAdjustment = ITEMMODS_GetByTimeAdjustment(armorByTime, periodOfDay, (int)baseTime, 0, 0, 0);
                defense += armorTimeAdjustment;

                if (armorTimeAdjustment)
                {
                    pStatNotDynamic = 1;
                }
            }
        }
    }

    int32_t armorPercentByTime = STATLIST_UnitGetStatValue(pItem, STAT_ITEM_ARMORPERCENT_BYTIME, 0);
    if (armorPercentByTime)
    {
        if (sgptDataTables->nItemStatCostTxtRecordCount > 269 && sgptDataTables->pItemStatCostTxt != (D2ItemStatCostTxt*)-87156)
        {
            if (pUnit->pDrlgAct)
            {
                int32_t baseTime = 0;
                int32_t periodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &baseTime);
                int32_t armorPercentAdjustment = ITEMMODS_GetByTimeAdjustment(armorPercentByTime, periodOfDay, (int)baseTime, 0, 0, 0);

                defense += DATATBLS_ApplyRatio(defense, armorPercentAdjustment, 100);
                if (armorPercentAdjustment)
                {
                    pStatNotDynamic = 1;
                }
            }
        }
    }

    const wchar_t* v23 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3461_ItemStats1h);

    outBuff.append(v23);
    outBuff.append(strSpace);

    if (pStatNotDynamic)
    {
        AppendColorizedString(outBuff, std::to_wstring(defense), 3);
    }
    else
    {
        outBuff.append(std::to_wstring(defense));
    }

    outBuff.append(strNewLine);
}

void ESE_D2Client_GetItemTextLineDamage_6FAE43D0(D2UnitStrc* pItem, std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord)
{
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    D2UnitStrc* pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
    int32_t isDamageModified = 0;

    if (D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_MISSILE_POTION))
    {
        int32_t missileId = ITEMS_GetMissileType(pItem);
        int32_t minDamage = MISSILE_GetMinElemDamage(0, pCurrentPlayer, missileId, 1);
        int32_t maxDamage = MISSILE_GetMaxElemDamage(0, pCurrentPlayer, missileId, 1);
        int32_t elementColor = 0;

        switch ((unsigned __int8)MISSILE_GetElemTypeFromMissileId(missileId))
        {
        case ELEMTYPE_FIRE:
        {
            elementColor = 1;
            break;
        }
        case ELEMTYPE_LTNG:
        {
            elementColor = 4;
            break;
        }
        case ELEMTYPE_COLD:
        {
            elementColor = 3;
            break;
        }
        case ELEMTYPE_POIS:
        {
            elementColor = 2;
            int32_t poisonLength = MISSILE_GetElementalLength(0, pCurrentPlayer, missileId, 1) / 25;
            if (poisonLength <= 0)
            {
                poisonLength = 1;
            }

            minDamage /= poisonLength;
            maxDamage /= poisonLength;
            break;
        }
        default:
        {
            elementColor = 0;
            break;
        }
        }

        minDamage += MISSILE_GetMinDamage(0, pCurrentPlayer, missileId, 1);
        minDamage >>= 8;

        maxDamage += MISSILE_GetMaxDamage(0, pCurrentPlayer, missileId, 1) + maxDamage;
        maxDamage >>= 8;

        if (maxDamage <= minDamage)
        {
            maxDamage = minDamage;
        }

        const wchar_t* v11 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3467_ItemStats1n);
        outBuff.assign(v11);
        ColorizeString(outBuff, 0);
        outBuff.append(strSpace);
        AppendColorizedString(outBuff, std::to_wstring(minDamage), elementColor);

        if (minDamage != maxDamage)
        {
            const wchar_t* v17 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3464_ItemStast1k);

            outBuff.append(strSpace);
            outBuff.append(v17);
            outBuff.append(strSpace);
            AppendColorizedString(outBuff, std::to_wstring(maxDamage), elementColor);
        }
        outBuff.append(strNewLine);
        return;
    }

    if (ITEMS_Is1Or2Handed(pCurrentPlayer, pItem))
    {
        const wchar_t* v20 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3466_ItemStats1m);
        const wchar_t* v23 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3464_ItemStast1k);
        const wchar_t* v24 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3465_ItemStats1l);
        const wchar_t* v25 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3464_ItemStast1k);

        int32_t minDamage = 0;
        int32_t maxDamage = 0;
        D2Client_GetItemDamage_6FAE4C60(pCurrentPlayer, pItem, STAT_SECONDARY_MINDAMAGE, STAT_SECONDARY_MAXDAMAGE, &minDamage, &maxDamage, &isDamageModified);

        std::wstring v43 = v20;
        v43.append(strSpace);

        if (isDamageModified)
        {
            AppendColorizedString(v43, std::to_wstring(minDamage), 3);
        }
        else
        {
            v43.append(std::to_wstring(minDamage));
        }

        v43.append(strSpace);
        v43.append(v23);
        v43.append(strSpace);
        v43.append(std::to_wstring(maxDamage));
        v43.append(strNewLine);

        std::wstring v41 = v24;

        D2Client_GetItemDamage_6FAE4C60(pCurrentPlayer, pItem, STAT_MINDAMAGE, STAT_MAXDAMAGE, &minDamage, &maxDamage, &isDamageModified);

        v41.append(strSpace);

        if (isDamageModified)
        {
            AppendColorizedString(v43, std::to_wstring(minDamage), 3);
        }
        else
        {
            v41.append(std::to_wstring(minDamage));
        }

        v41.append(strSpace);
        v41.append(v25);
        v41.append(strSpace);
        v41.append(std::to_wstring(maxDamage));
        v41.append(strNewLine);

        outBuff.clear();
        AppendColorizedString(outBuff, v43, 0);
        AppendColorizedString(outBuff, v41, 0);
    }
    else
    {
        int32_t minDamage = 0;
        int32_t maxDamage = 0;

        int32_t v27 = 0;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            D2Client_GetItemDamage_6FAE4C60(pCurrentPlayer, pItem, STAT_SECONDARY_MINDAMAGE, STAT_SECONDARY_MAXDAMAGE, &minDamage, &maxDamage, &isDamageModified);
            v27 = STR_IDX_3466_ItemStats1m;
        }
        else
        {
            D2Client_GetItemDamage_6FAE4C60(pCurrentPlayer, pItem, STAT_MINDAMAGE, STAT_MAXDAMAGE, &minDamage, &maxDamage, &isDamageModified);
            v27 = STR_IDX_3465_ItemStats1l;
        }

        if (maxDamage <= minDamage + 1)
        {
            maxDamage = minDamage + 1;
        }

        const wchar_t* v28 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v27);
        const wchar_t* v29 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3464_ItemStast1k);

        outBuff.assign(v28);
        outBuff.append(strSpace);

        if (isDamageModified)
        {
            AppendColorizedString(outBuff, std::to_wstring(minDamage), 3);
        }
        else
        {
            outBuff.append(std::to_wstring(minDamage));
        }

        outBuff.append(strSpace);
        outBuff.append(v29);
        outBuff.append(strSpace);
        outBuff.append(std::to_wstring(maxDamage));
        outBuff.append(strNewLine);
    }

    if (STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MINDAMAGE_PERCENT, 0)
        || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MAXDAMAGE_PERCENT, 0)
        || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_THROW_MINDAMAGE, 0)
        || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_THROW_MAXDAMAGE, 0))
    {
        isDamageModified = 1;
    }

    if (ITEMS_CheckIfThrowable(pItem))
    {
        const wchar_t* v30 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3467_ItemStats1n);
        const wchar_t* v31 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3464_ItemStast1k);

        AppendColorizedString(outBuff, v30, 0);
        outBuff.append(strSpace);

        int32_t minDamage = 0;
        int32_t maxDamage = 0;

        D2Client_GetItemDamage_6FAE4C60(pCurrentPlayer, pItem, STAT_ITEM_THROW_MINDAMAGE, STAT_ITEM_THROW_MAXDAMAGE, &minDamage, &maxDamage, &isDamageModified);

        AppendColorizedString(outBuff, std::to_wstring(minDamage), isDamageModified != 0 ? 3 : 0);
        outBuff.append(strSpace);
        outBuff.append(v31);
        outBuff.append(strSpace);
        AppendColorizedString(outBuff, std::to_wstring(maxDamage), isDamageModified != 0 ? 3 : 0);
        outBuff.append(strNewLine);
    }
}

void ESE_D2Client_BuildItemName_6FADD360(D2UnitStrc* pItem, std::wstring& outBuff)
{
    if (!pItem)
    {
        return;
    }

    std::wstring localBuff;

    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    int32_t nameLength = 0;
    auto pItemTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    if (!pItemTxtRecord)
    {
        FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
        exit(-1);
    }

    auto pItemType = ITEMS_GetItemType(pItem);
    if (ITEMS_CheckItemFlag(pItem, IFLAG_RUNEWORD, __LINE__, __FILE__))
    {
        const wchar_t* itemName_1 = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);
        auto v17 = BuildItemName_StripBracketPrefix(itemName_1);

        std::wstring itemNamePrefix = v17;
        itemNamePrefix.append(strNewLine);

        auto strIndex = (unsigned __int16)ITEMS_GetPrefixId(pItem, 0);
        const wchar_t* v20 = (const wchar_t*)D2LANG_GetStringFromTblIndex(strIndex);
        if (!v20)
        {
            v20 = strSpace;
        }

        std::wstring v209 = (v20 == nullptr) ? strSpace : v20;
        ColorizeString(v209, 4);

        outBuff.append(itemNamePrefix);
        outBuff.append(v209);
    }
    else if (!ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, __LINE__, __FILE__))
    {
        const wchar_t* itemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);
        auto v56 = BuildItemName_StripBracketPrefix(itemName);
        outBuff.assign(v56);
    }
    else
    {
        switch (ITEMS_GetItemQuality(pItem))
        {
        case ITEMQUAL_INFERIOR:
        {
            auto lowQualityItemsTxtRecordIndex = ITEMS_GetFileIndex(pItem);
            auto lowQualityItemTxtRecord = DATATBLS_GetLowQualityItemsTxtRecord(lowQualityItemsTxtRecordIndex);
            if (lowQualityItemTxtRecord)
            {
                const wchar_t* strItemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);
                const wchar_t* v177 = (const wchar_t*)D2LANG_GetStringFromTblIndex(lowQualityItemTxtRecord->wTblId);
                const wchar_t* strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_1712_LowqualityFormat);

                std::wstring formattedName;
                ESE_D2Client_FormatName_6FADCFE0(formattedName, strFormat, v177, strItemName, 0);
                outBuff.append(formattedName);
            }
            break;
        }
        case ITEMQUAL_NORMAL:
        {
            if (!D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_SCROLL) && !D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BOOK))
            {
                if (D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_PLAYER_BODY_PART))
                {
                    auto earLevel = ITEMS_GetEarLevel(pItem);

                    std::wstring earName = ToWideString(ITEMS_GetEarName(pItem));

                    if (ITEMS_CheckItemFlag(pItem, IFLAG_NAMED, __LINE__, __FILE__))
                    {
                        const wchar_t* v33 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5126_Hardcore);
                        const wchar_t* v35 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4141_level);

                        outBuff.append(v33);
                        outBuff.append(strNewLine);
                        outBuff.append(v35);
                    }
                    else
                    {
                        const wchar_t* v36 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4141_level);

                        outBuff.append(v36);
                    }

                    outBuff.append(strSpace);
                    outBuff.append(std::to_wstring(earLevel));
                    outBuff.append(strNewLine);

                    auto nClass = ITEMS_GetFileIndex(pItem);
                    if (nClass >= 7)
                    {
                        FOG_DisplayAssert("nClass >= PLAYERCLASS_AMAZON && nClass < NUM_PLAYERCLASS", __FILE__, __LINE__);
                        exit(-1);
                    }

                    const wchar_t* v38;
                    switch (nClass)
                    {
                    case 0u:
                        v38 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4011_Amazon);
                        break;
                    case 1u:
                        v38 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4010_Sorceress);
                        break;
                    case 2u:
                        v38 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4009_Necromancer);
                        break;
                    case 3u:
                        v38 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4008_Paladin);
                        break;
                    case 4u:
                        v38 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4007_Barbarian);
                        break;
                    case 5u:
                        v38 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_10097_Druid);
                        break;
                    case 6u:
                        v38 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_10098_Assassin);
                        break;
                    default:
                        v38 = 0;
                        break;
                    }

                    outBuff.append(v38);
                    outBuff.append(strNewLine);

                    const wchar_t* itemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);

                    std::wstring personalizedName;
                    ESE_D2LANG_UnicodePersonalize_6FC11D50(personalizedName, earName, itemName, STRTABLE_GetLanguage());
                    outBuff.append(personalizedName);
                    break;
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BODY_PART))
                {
                    int32_t v45 = ITEMS_GetFileIndex(pItem);
                    D2MonStatsTxt* v46 = nullptr;
                    if (v45 >= 0 && v45 < sgptDataTables->nMonStatsTxtRecordCount)
                    {
                        v46 = &sgptDataTables->pMonStatsTxt[v45];
                    }

                    const wchar_t* v182 = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);
                    const wchar_t* v47 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v46->wNameStr);
                    const wchar_t* strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_1716_BodyPartsFormat);

                    std::wstring formattedName;
                    ESE_D2Client_FormatName_6FADCFE0(formattedName, strFormat, v47, v182, 0);
                    outBuff.append(formattedName);

                    break;
                }

                if (ITEMS_CheckItemFlag(pItem, IFLAG_SOCKETED, __LINE__, __FILE__) && pItem->pInventory && INVENTORY_GetItemCount(pItem->pInventory))
                {
                    const wchar_t* v183 = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);
                    const wchar_t* v178 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_1728_Gemmed);
                    const wchar_t* strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_1715_GemmedNormalName);

                    std::wstring formattedName;
                    ESE_D2Client_FormatName_6FADCFE0(formattedName, strFormat, v178, v183, 0);
                    outBuff.append(formattedName);

                    break;
                }

                const wchar_t* v53 = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);

                auto v56 = BuildItemName_StripBracketPrefix(v53);
                outBuff.assign(v56);
                break;
            }

            int32_t stringIndex;
            auto firstSuffixId = (unsigned __int16)ITEMS_GetSuffixId(pItem, 0);
            if (firstSuffixId == 0)
            {
                stringIndex = STR_IDX_2199_tbk;
                if (pItemType != ITEMTYPE_BOOK)
                {
                    stringIndex = STR_IDX_2200_tsc;
                }

                const wchar_t* v59 = (const wchar_t*)D2LANG_GetStringFromTblIndex(stringIndex);
                outBuff.assign(v59);
            }
            else if (firstSuffixId == 1)
            {
                stringIndex = STR_IDX_2201_ibk;
                if (pItemType != ITEMTYPE_BOOK)
                {
                    stringIndex = STR_IDX_2202_isc;
                }

                const wchar_t* v59 = (const wchar_t*)D2LANG_GetStringFromTblIndex(stringIndex);
                outBuff.assign(v59);
            }

            break;
        }
        case ITEMQUAL_SUPERIOR:
        {
            const wchar_t* v182 = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);
            const wchar_t* v47 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_1727_Hiquality);
            const wchar_t* strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_1711_HiqualityFormat);

            std::wstring formattedName;
            ESE_D2Client_FormatName_6FADCFE0(formattedName, strFormat, v47, v182, 0);
            outBuff.append(formattedName);

            break;
        }
        case ITEMQUAL_MAGIC:
        {
            auto magicPrefixId = ITEMS_GetPrefixId(pItem, 0);
            auto magicPrefixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(magicPrefixId);
            auto magicSuffixId = ITEMS_GetSuffixId(pItem, 0);
            auto magicSuffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(magicSuffixId);

            std::wstring itemNamePrefix;
            if (magicPrefixTxtRecord)
            {
                if (magicPrefixTxtRecord->wTblIndex)
                {
                    const wchar_t* v151 = (const wchar_t*)D2LANG_GetStringFromTblIndex(magicPrefixTxtRecord->wTblIndex);

                    itemNamePrefix = std::wstring(v151);
                    nameLength = itemNamePrefix.length();
                }
                else
                {
                    itemNamePrefix = L"(" + ToWideString(magicPrefixTxtRecord->szName) + L")";
                    nameLength = itemNamePrefix.length();
                }
            }

            std::wstring itemNameSuffix;
            if (magicSuffixTxtRecord)
            {
                if (magicSuffixTxtRecord->wTblIndex)
                {
                    const wchar_t* v154 = (const wchar_t*)D2LANG_GetStringFromTblIndex(magicSuffixTxtRecord->wTblIndex);
                    itemNameSuffix = std::wstring(v154);
                    nameLength += itemNameSuffix.length();
                }
                else
                {
                    itemNamePrefix = L"(" + ToWideString(magicSuffixTxtRecord->szName) + L")";
                    nameLength = itemNamePrefix.length();
                }
            }

            const wchar_t* strItemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);
            const wchar_t* strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_1714_MagicFormat);

            std::wstring formattedName;
            ESE_D2Client_FormatName_6FADCFE0(formattedName, strFormat, itemNamePrefix.c_str(), strItemName, itemNameSuffix.c_str(), 0);
            outBuff.append(formattedName);

            break;
        }
        case ITEMQUAL_SET:
        {
            auto setItemsTxtIndex = ITEMS_GetFileIndex(pItem);
            if (setItemsTxtIndex < 0)
            {
                break;
            }
            if (setItemsTxtIndex >= sgptDataTables->nSetItemsTxtRecordCount)
            {
                break;
            }

            auto pSetItemTxt = &sgptDataTables->pSetItemsTxt[setItemsTxtIndex];
            if (!pSetItemTxt)
            {
                break;
            }

            const wchar_t* v125 = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);

            auto v127 = BuildItemName_StripBracketPrefix(v125);
            outBuff.assign(v127);
            outBuff.append(strNewLine);
            if (pSetItemTxt->wStringId)
            {
                const wchar_t* itemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pSetItemTxt->wStringId);

                if (ITEMS_CheckItemFlag(pItem, IFLAG_PERSONALIZED, __LINE__, __FILE__))
                {
                    auto subjectName = ToWideString(ITEMS_GetEarName(pItem));

                    std::wstring personalizedName;
                    ESE_D2LANG_UnicodePersonalize_6FC11D50(personalizedName, subjectName, itemName, STRTABLE_GetLanguage());
                    outBuff.append(personalizedName);
                }
                else
                {
                    const wchar_t* strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_10089_SetItemFormatX);

                    std::wstring formattedName;
                    ESE_D2Client_FormatName_6FADCFE0(formattedName, strFormat, itemName, 0);
                    outBuff.append(formattedName);
                }
            }
            break;
        }
        case ITEMQUAL_RARE:
        case ITEMQUAL_CRAFT:
        case ITEMQUAL_TEMPERED:
        {
            auto v61 = ITEMS_GetRarePrefixId(pItem);
            auto pRarePrefixTxtRecord = DATATBLS_GetRareAffixTxtRecord(v61);
            auto v63 = ITEMS_GetRareSuffixId(pItem);
            auto pRareSuffixTxtRecord = DATATBLS_GetRareAffixTxtRecord(v63);

            std::wstring itemNamePrefix;
            if (pRarePrefixTxtRecord)
            {
                if (pRarePrefixTxtRecord->wStringId)
                {
                    const wchar_t* strRarePrefixName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pRarePrefixTxtRecord->wStringId);
                    itemNamePrefix.assign(strRarePrefixName);
                    nameLength = itemNamePrefix.length();
                }
                else
                {
                    itemNamePrefix = L"(" + ToWideString(pRarePrefixTxtRecord->szName) + L")";
                    nameLength = itemNamePrefix.length();
                }
            }

            std::wstring itemNameSuffix;
            if (pRareSuffixTxtRecord)
            {
                if (pRareSuffixTxtRecord->wStringId)
                {
                    const wchar_t* strRareSuffixName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pRareSuffixTxtRecord->wStringId);
                    itemNameSuffix.assign(strRareSuffixName);
                    nameLength += itemNameSuffix.length();
                }
                else
                {
                    itemNameSuffix = L"(" + ToWideString(pRareSuffixTxtRecord->szName) + L")";
                    nameLength += itemNameSuffix.length();
                }
            }

            const wchar_t* strItemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);
            std::wstring strippedItemName = BuildItemName_StripBracketPrefix(strItemName);
            outBuff.append(strippedItemName);
            outBuff.append(strNewLine);

            const wchar_t* strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_1718_RareFormat);

            std::wstring formattedName;
            ESE_D2Client_FormatName_6FADCFE0(formattedName, strFormat, itemNamePrefix.c_str(), itemNameSuffix.c_str(), 0);

            if (ITEMS_CheckItemFlag(pItem, IFLAG_PERSONALIZED, __LINE__, __FILE__))
            {
                auto earOwnerName = ToWideString(ITEMS_GetEarName(pItem));

                std::wstring personalizedName;
                ESE_D2LANG_UnicodePersonalize_6FC11D50(personalizedName, earOwnerName, formattedName, STRTABLE_GetLanguage());
                outBuff.append(personalizedName);
            }
            else
            {
                outBuff.append(formattedName);
            }

            break;
        }
        case ITEMQUAL_UNIQUE:
        {
            const wchar_t* v99 = (const wchar_t*)D2LANG_GetStringFromTblIndex(pItemTxtRecord->wNameStr);
            localBuff.assign(v99);

            if (ITEMS_GetFileIndex(pItem) >= 0)
            {
                auto uniqueItemTxtIndex = ITEMS_GetFileIndex(pItem);

                D2UniqueItemsTxt* pUniqueItemTxt = nullptr;
                if (uniqueItemTxtIndex >= 0 && uniqueItemTxtIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
                {
                    pUniqueItemTxt = &sgptDataTables->pUniqueItemsTxt[uniqueItemTxtIndex];
                }

                if (pUniqueItemTxt == nullptr)
                {
                    auto v104 = BuildItemName_StripBracketPrefix(localBuff);
                    outBuff.assign(v104);
                    break;
                }

                if (!pItemTxtRecord->nSkipName)
                {
                    auto v106 = BuildItemName_StripBracketPrefix(localBuff);
                    outBuff.assign(v106);
                    outBuff.append(strNewLine);
                }

                std::wstring itemName = std::wstring((const wchar_t*)D2LANG_GetStringFromTblIndex(pUniqueItemTxt->wTblIndex));
                itemName = BuildItemName_StripBracketPrefix(itemName);

                if (ITEMS_CheckItemFlag(pItem, IFLAG_PERSONALIZED, __LINE__, __FILE__))
                {
                    auto subjectName = ToWideString(ITEMS_GetEarName(pItem));

                    std::wstring personalizedName;
                    ESE_D2LANG_UnicodePersonalize_6FC11D50(personalizedName, subjectName, itemName, STRTABLE_GetLanguage());

                    outBuff.append(personalizedName);
                    break;
                }

                std::wstring v119 = std::wstring((const wchar_t*)D2LANG_GetStringFromTblIndex(pUniqueItemTxt->wTblIndex));
                v119 = BuildItemName_StripBracketPrefix(v119);
                outBuff.append(v119);
                break;
            }

            auto v56 = BuildItemName_StripBracketPrefix(localBuff);
            outBuff.assign(v56);
            break;
        }
        default:
            FOG_DisplayAssert("0", __FILE__, __LINE__);
            exit(-1);
        }
    }

    if (ITEMS_CheckItemFlag(pItem, IFLAG_PERSONALIZED, __LINE__, __FILE__))
    {
        int32_t itemQuality = ITEMS_GetItemQuality(pItem);
        if (itemQuality < ITEMQUAL_SET || itemQuality > ITEMQUAL_TEMPERED)
        {
            auto subjectName = ToWideString(ITEMS_GetEarName(pItem));

            std::wstring personalizedName;
            ESE_D2LANG_UnicodePersonalize_6FC11D50(personalizedName, subjectName, outBuff.c_str(), STRTABLE_GetLanguage());
            outBuff.assign(personalizedName);
        }
    }

    if (pItemTxtRecord->nQuest)
    {
        auto v176 = STATLIST_UnitGetStatValue(pItem, STAT_QUESTITEMDIFFICULTY, 0);
        if (pItemTxtRecord->nQuestDiffCheck && v176 < (unsigned __int8)D2Client_GetCurrentDifficulty_6FAAC090())
        {
            ColorizeString(outBuff, 1);
        }
        else if (pItemTxtRecord->dwCode != 543647084)
        {
            ColorizeString(outBuff, 4);
        }
    }
    return;
}

int ESE_D2Client_GetItemPropertyLine_6FAF21C0_Case199(int32_t nDescFunc, int32_t descStrIndex, std::wstring& outBuff)
{
    if (nDescFunc < 6 || nDescFunc > 10 && nDescFunc != 21)
    {
        return 1;
    }

    auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    if (descStrIndex == 5382)
    {
        auto v75 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11091_increaseswithplaylevelX);
        outBuff.append(strSpace);
        outBuff.append(v75);
        return 1;
    }
    else
    {
        auto v73 = (const wchar_t*)D2LANG_GetStringFromTblIndex(descStrIndex);
        outBuff.append(strSpace);
        outBuff.append(v73);
        return 1;
    }
}

int ESE_GetItemPropertyLine_HelperA(D2UnitStrc* pUnit, int nDescGrpFunc, int statValue, int recordId, D2ItemStatCostTxt* itemStatCostTxtForStat, std::wstring& outBuff)
{
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
            AppendFormattedWideString(outBuff, strRepairsNDurabilityPerSecond, 25);
        }
        else if (2500 / statValue > 30)
        {
            auto strRepairsNDurabilityInNSeconds = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21242_ModStre9u);
            AppendFormattedWideString(outBuff, strRepairsNDurabilityInNSeconds, 1, (2500 / statValue + 12) / 25);
        }
        else
        {
            auto strRepairsNDurabilityPerSecond1 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_21241_ModStre9t);
            AppendFormattedWideString(outBuff, strRepairsNDurabilityPerSecond1, 1);
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

        AppendFormattedWideString(outBuff, strFormat, statValue);
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

        AppendFormattedWideString(outBuff, strFormat, statValue, recordId & sgptDataTables->nShiftedStuff, strSkillName);

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

        AppendFormattedWideString(outBuff, strDesc, statValue, strSkillName);

        break;
    }
    case 17:
    case 18:
    {
        int32_t preiodOfDay = 0;
        int32_t pItemModPeriodOfDay = 0;
        int32_t baseTime = 0;
        if (*D2Client_pCurrentDrlgAct_6FBA7984)
        {
            preiodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(*D2Client_pCurrentDrlgAct_6FBA7984, &baseTime);
            pItemModPeriodOfDay = preiodOfDay;
        }

        int32_t itemModMin = 0;
        int32_t itemModMax = 0;
        auto timeAdjustmentThing = ITEMMODS_GetByTimeAdjustment(statValue, preiodOfDay, baseTime, &pItemModPeriodOfDay, &itemModMin, &itemModMax);
        if (!*D2Client_pCurrentDrlgAct_6FBA7984)
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
        AppendFormattedWideString(outBuff, strDesc, statValue);

        break;
    }
    case 20:
    case 21:
    {
        statValue = -statValue;

        if (nDescVal == 1)
        {
            if (statValue >= 0)
            {
                outBuff.assign(strPlusSign);
            }

            outBuff.append(std::to_wstring(statValue));
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

            outBuff.append(std::to_wstring(statValue));
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

        D2MonTypeTxt* pMonTypeTxt = nullptr;
        if (recordId < 0 || recordId >= sgptDataTables->nMonPropTxtRecordCount)
        {
            pMonTypeTxt = sgptDataTables->pMonTypeTxt;
        }
        else
        {
            pMonTypeTxt = &sgptDataTables->pMonTypeTxt[recordId];
        }

        if (!pMonTypeTxt)
        {
            break;
        }

        auto strColon = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3997_colon);
        auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
        auto strPlur = (const wchar_t*)D2LANG_GetStringFromTblIndex(pMonTypeTxt->wStrPlur);

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

        AppendFormattedWideString(outBuff, strDesc, nCurrentCharges, nMaxCharges);

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

        if (statVal > 0)
        {
            outBuff.assign(strPlusSign);
        }

        outBuff.append(std::to_wstring(statVal));
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
    bool bFlag = true;

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

        bFlag = itemStatCostTxtIndex == nStatId;

        auto currentStatValueUnshifted = D2Common_10466_STATLIST_GetStatValue(pStatList, itemStatCostTxtIndex, 0);
        if (currentItemStatCostTxt->nOp >= 2u && currentItemStatCostTxt->nOp <= 5u)
        {
            if (currentItemStatCostTxt->wOpBase >= sgptDataTables->nItemStatCostTxtRecordCount || (itemStatCostTxtForStat = &sgptDataTables->pItemStatCostTxt[currentItemStatCostTxt->wOpBase]) == 0)
            {
                if (originalStatValue != 0)
                {
                    return ESE_GetItemPropertyLine_HelperA(pItem, 0, originalStatValue, skillId, itemStatCostTxtForStat, outBuff);
                }

                statValue = originalStatValue;
                continue;
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

    if (bFlag)
    {
        return ESE_GetItemPropertyLine_HelperA(pItem, 1, originalStatValue, skillId, itemStatCostTxtForStat, outBuff);
    }

    return 0;
}

bool ESE_D2Client_PrintDamageRange_6FAF3460(DamageRangeValue* statValues, D2C_ItemStats nStatId, std::wstring& outBuff)
{

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
            auto fmt = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3623_strModMinDamageRange);
            AppendFormattedWideString(outBuff, fmt, damageRangeValue->minDamage, damageRangeValue->maxDamage);

            damageRangeValue->bHasBeenHandled = 1;
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
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage);

            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3614_strModColdDamage);
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->maxDamage);

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
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->maxDamage);

            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3617_strModLightningDamageRange);
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage);

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
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->maxDamage);

            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3613_strModFireDamageRange);
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage);

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
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage, damageRangeValue->length / 25);

            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3620_strModPoisonDamage);
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->maxDamage, damageRangeValue->length / 25);

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
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->minDamage, damageRangeValue->maxDamage);

            return true;
        }
        else
        {
            auto strFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3618_strModMagicDamage);
            AppendFormattedWideString(outBuff, strFormat, damageRangeValue->maxDamage);

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

void ESE_D2Client_GetItemTextLineDamageToUndead_6FAF12C0(std::wstring& outBuff)
{
    auto strPlus = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4002_plus);
    auto strNewline = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    auto strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    auto strPercent = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4001_percent);
    auto strDamageToUndead = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3554_ModStr4f);

    outBuff.append(strPlus);
    outBuff.append(std::to_wstring(50));
    outBuff.append(strPercent);
    outBuff.append(strSpace);
    outBuff.append(strDamageToUndead);
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
void ESE_D2Client_GetItemTextLinePropertiesInternal_6FAF19C0(D2UnitStrc* pUnit, std::wstring& outBuff, int bUnknownFlag1, int unitState, int nUnitState, int nUnitFlags, int addNewline)
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

        if (pUnit && pUnit->dwUnitType == UNIT_ITEM && pUnit->pInventory != nullptr)
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

        if (bUnknownFlag1 && D2Common_10731_ITEMS_CheckItemTypeId(pUnit, ITEMTYPE_BLUNT) && !STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0))
        {
            ESE_D2Client_GetItemTextLineDamageToUndead_6FAF12C0(outBuff);
        }


        DamageRangeValue statValues[DAMAGE_RANGE_MAX];
        memset(statValues, 0, sizeof(statValues));

        UnknownStructA* unknownStatArray = (UnknownStructA*)D2Client_pDWORD_6FB79B48;
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

                    std::wstring propertyLineBuffer;
                    if (!ESE_D2Client_GetItemPropertyLine_6FAF21C0(pUnit, pStatList, nStatId, d2StatStrcBuffer[copiedStatIndex].nLayer, d2StatStrcBuffer[copiedStatIndex].nValue, propertyLineBuffer))
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
                        outBuff.append(propertyLineBuffer);

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
        return;
    }

    auto pUnitFileIndex = ITEMS_GetFileIndex(pUnit);
    if (*D2Client_pElixirDescCount_6FB7A4A0)
    {
        for (int32_t i = 0; i < *D2Client_pElixirDescCount_6FB7A4A0; ++i)
        {
            ElixirDesc_6FB7A440* pElixierDesc = pElixierDesc = &D2Client_pElixirDescs_6FB7A440[i];
            if (pElixierDesc->StatId != pUnitFileIndex)
            {
                continue;
            }

            int32_t statValue = STATLIST_UnitGetStatValue(pUnit, STAT_VALUE, 0);

            if (pElixierDesc->StatId == 8 || pElixierDesc->StatId == 9)
            {
                statValue >>= 8;
            }
            if (pElixierDesc->StatId == 6 || pElixierDesc->StatId == 7)
            {
                statValue >>= 8;
            }
            if (pElixierDesc->StatId == 10 || pElixierDesc->StatId == 11)
            {
                statValue >>= 8;
            }

            if (statValue != 0)
            {
                if (pElixierDesc->UnknownMustBeOne != 1)
                {
                    FOG_DisplayAssert("0", __FILE__, __LINE__);
                    exit(-1);
                }

                if (pElixierDesc->UnknownMustBeTwo != 2)
                {
                    FOG_DisplayAssert("0", __FILE__, __LINE__);
                    exit(-1);
                }

                int32_t elixirNameStrIndex = 0;
                if (statValue <= 0)
                {
                    elixirNameStrIndex = pElixierDesc->PositiveStatStringIndex;
                }
                else
                {
                    elixirNameStrIndex = pElixierDesc->NegativeStatStringIndex;
                }

                auto strElixirName = (const wchar_t*)D2LANG_GetStringFromTblIndex(elixirNameStrIndex);
                outBuff.append(strElixirName);
                outBuff.append(strSpace);

                if (statValue > 0)
                {
                    outBuff.append(strPlus);
                }

                outBuff.append(std::to_wstring(statValue));
                outBuff.append(strNewLine);
            }
        }
    }
}

void ESE_D2Client_GetItemTextLineProperties_6FAF3160(D2UnitStrc* pItem, std::wstring& outBuff, int bFlag, const std::wstring* existingContents)
{
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    const wchar_t* strComma = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3852_KeyComma);

    // STATE_RUNEWORD and UNITFLAG_SKSRVDOFUNC may not be the correct names/enums. 171 and 64
    std::wstring propertiesBuff;
    ESE_D2Client_GetItemTextLinePropertiesInternal_6FAF19C0(pItem, propertiesBuff, 1, 0, STATE_RUNEWORD, UNITFLAG_SKSRVDOFUNC, bFlag);

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

void __fastcall ESE_D2Client_GetItemTextLineBookQuantity_6FAE54B0(D2UnitStrc* pUnit, std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord)
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

void __fastcall ESE_D2Client_GetItemTextLineSmiteOrKickDamage_6FAE5040(D2UnitStrc* pItem, std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord)
{
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    int64_t minDamage = pItemTxtRecord->nMinDam;
    int64_t maxDamage = pItemTxtRecord->nMaxDam;
    int32_t strIndex = 0;

    if (D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_ANY_SHIELD))
    {
        strIndex = 3468;
        D2UnitStrc* currentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
        D2SkillStrc* holyShieldSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(currentPlayer, SKILL_HOLYSHIELD);
        if (holyShieldSkill)
        {
            if (STATES_CheckState(currentPlayer, STATE_HOLYSHIELD))
            {
                int32_t skillLevel = SKILLS_GetSkillLevel(currentPlayer, holyShieldSkill, 1);
                minDamage += SKILLS_GetMinPhysDamage(currentPlayer, SKILL_HOLYSHIELD, skillLevel, 1) >> 8;
                maxDamage += SKILLS_GetMaxPhysDamage(currentPlayer, SKILL_HOLYSHIELD, skillLevel, 1) >> 8;
            }
        }
    }
    else
    {
        if (!D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BOOTS))
        {
            return;
        }

        strIndex = 21782;
    }

    const wchar_t* v12 = (const wchar_t*)D2LANG_GetStringFromTblIndex(strIndex);
    const wchar_t* v13 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3464_ItemStast1k);

    outBuff.append(v12);
    outBuff.append(strSpace);
    outBuff.append(std::to_wstring(minDamage));
    outBuff.append(strSpace);

    outBuff.append(v13);
    outBuff.append(strSpace);
    outBuff.append(std::to_wstring(maxDamage));
    outBuff.append(strNewLine);
}

enum MERCHANT_CLASSID
{
    MERCHANT_CLASSID_Cain1 = 146,
    MERCHANT_CLASSID_Gheed = 147,
    MERCHANT_CLASSID_Akara = 148,
    MERCHANT_CLASSID_Charsi = 154,
    MERCHANT_CLASSID_Drognan = 177,
    MERCHANT_CLASSID_Fara = 178,
    MERCHANT_CLASSID_Elzix = 199,
    MERCHANT_CLASSID_Lysander = 202,
    MERCHANT_CLASSID_Cain2 = 244,
    MERCHANT_CLASSID_Cain3 = 245,
    MERCHANT_CLASSID_Cain4 = 246,
    MERCHANT_CLASSID_Asheara = 252,
    MERCHANT_CLASSID_Hratli = 253,
    MERCHANT_CLASSID_Alkor = 254,
    MERCHANT_CLASSID_Ormus = 255,
    MERCHANT_CLASSID_Halbu = 257,
    MERCHANT_CLASSID_Cain5 = 265,
    MERCHANT_CLASSID_Jamella = 405,
    MERCHANT_CLASSID_Larzuk = 511,
    MERCHANT_CLASSID_Drehya = 512,
    MERCHANT_CLASSID_Malah = 513,
    MERCHANT_CLASSID_Nihlathak = 514,
};
int __fastcall ESE_D2Client_GetItemTextLinePrice_6FAFB200(D2UnitStrc* pItem, int a2, int* pTransactionCost, std::wstring& outBuff)
{
    *pTransactionCost = 0;

    if (pItem == nullptr)
    {
        return 0;
    }

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        return 0;
    }

    int32_t stringIndex;
    if (!a2)
    {
        D2C_TransactionTypes transactionType = TRANSACTIONTYPE_BUY;
        if (*D2Client_pIsGamblingSession_6FBB5D7C)
        {
            transactionType = TRANSACTIONTYPE_GAMBLE;
        }

        D2UnitStrc* activeNpc;
        int32_t activeNpcClassId = -1;
        if (*D2Client_pIsNpcDialogOpen_6FBB5CF9 && (activeNpc = D2Client_FindUnit_6FB269F0(*D2Client_pActiveNpcId_6FBB5CF5, 1)) != 0)
        {
            activeNpcClassId = activeNpc->dwClassId;
        }

        D2C_Difficulties currentDifficulty = (D2C_Difficulties)D2Client_GetCurrentDifficulty_6FAAC090();
        D2UnitStrc* currentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
        *pTransactionCost = ITEMS_GetTransactionCost(currentPlayer, pItem, currentDifficulty, *D2Client_pQuestFlags_6FBB5D13, activeNpcClassId, transactionType);
        const wchar_t* strString = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3329_cost);

        outBuff.assign(strString);
        outBuff.append(std::to_wstring(*pTransactionCost));

        return 1;
    }

    if (!*D2Client_pIsNpcDialogOpen_6FBB5CF9 || !D2Client_FindUnit_6FB269F0(*D2Client_pActiveNpcId_6FBB5CF5, 1))
    {
        return 0;
    }

    D2UnitStrc* activeNpc = nullptr;
    int32_t activeNpcClassId = -1;
    if (*D2Client_pIsNpcDialogOpen_6FBB5CF9 && (activeNpc = D2Client_FindUnit_6FB269F0(*D2Client_pActiveNpcId_6FBB5CF5, 1)) != 0)
    {
        activeNpcClassId = activeNpc->dwClassId;
    }

    DATATBLS_GetItemsTxtRecord(pItem->dwClassId);

    if ((activeNpcClassId == MERCHANT_CLASSID_Larzuk ||
        activeNpcClassId == MERCHANT_CLASSID_Hratli ||
        activeNpcClassId == MERCHANT_CLASSID_Halbu ||
        activeNpcClassId == MERCHANT_CLASSID_Charsi ||
        activeNpcClassId == MERCHANT_CLASSID_Fara) && D2Client_IsVendorRepairActive_6FAEB930())
    {
        if (!ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, __LINE__, __FILE__))
        {
            std::wstring v17 = std::wstring((const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_4022_strCannotDoThisToUnknown));
            ColorizeString(v17, 1);

            outBuff.append(v17);
            return 1;
        }

        if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD || !ITEMS_IsRepairable(pItem))
        {
            return 0;
        }

        int32_t maxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (!ITEMS_HasDurability(pItem) || maxDurability == 0 || STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) >= maxDurability)
        {
            int32_t quantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);
            if (!ITEMS_CheckIfStackable(pItem) || (quantity >= ITEMS_GetTotalMaxStack(pItem)))
            {
                if (!ITEMS_HasUsedCharges(pItem, (BOOL*)&pTransactionCost) || pTransactionCost)
                {
                    return 0;
                }
            }
        }

        activeNpcClassId = -1;
        if (*D2Client_pIsNpcDialogOpen_6FBB5CF9 && (activeNpc = D2Client_FindUnit_6FB269F0(*D2Client_pActiveNpcId_6FBB5CF5, 1)) != 0)
        {
            activeNpcClassId = activeNpc->dwClassId;
        }

        D2C_Difficulties currentDifficulty = (D2C_Difficulties)D2Client_GetCurrentDifficulty_6FAAC090();
        D2UnitStrc* pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
        *pTransactionCost = ITEMS_GetTransactionCost(pCurrentPlayer, pItem, currentDifficulty, *D2Client_pQuestFlags_6FBB5D13, activeNpcClassId, TRANSACTIONTYPE_REPAIR);
        const wchar_t* strString = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3330_Repair);

        outBuff.assign(strString);
        outBuff.append(std::to_wstring(*pTransactionCost));

        return 1;
    }

    if (activeNpcClassId == MERCHANT_CLASSID_Cain5 || activeNpcClassId == MERCHANT_CLASSID_Cain2 || activeNpcClassId == MERCHANT_CLASSID_Cain3)
    {
        auto isIdentified = ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, __LINE__, __FILE__);
        if (isIdentified)
        {
            outBuff.clear();
            return 1;
        }

        auto v12 = -(QUESTRECORD_GetQuestState(*D2Client_pQuestFlags_6FBB5D13, QUEST_A1Q4_CAIN, 0) != 0);
        stringIndex = STR_IDX_3332_Identify;

        v12 = (v12 & 0xFFFFFF00) | (v12 & 0x9C);
        *pTransactionCost = v12 + 100;

        const wchar_t* strString = (const wchar_t*)D2LANG_GetStringFromTblIndex(stringIndex);

        outBuff.assign(strString);
        outBuff.append(std::to_wstring(*pTransactionCost));

        return 1;
    }

    if (activeNpcClassId != MERCHANT_CLASSID_Gheed &&
        activeNpcClassId != MERCHANT_CLASSID_Akara &&
        activeNpcClassId != MERCHANT_CLASSID_Charsi &&
        activeNpcClassId != MERCHANT_CLASSID_Drognan &&
        activeNpcClassId != MERCHANT_CLASSID_Fara &&
        activeNpcClassId != MERCHANT_CLASSID_Elzix &&
        activeNpcClassId != MERCHANT_CLASSID_Lysander &&
        activeNpcClassId != MERCHANT_CLASSID_Cain4 &&
        activeNpcClassId != MERCHANT_CLASSID_Asheara &&
        activeNpcClassId != MERCHANT_CLASSID_Hratli &&
        activeNpcClassId != MERCHANT_CLASSID_Alkor &&
        activeNpcClassId != MERCHANT_CLASSID_Ormus &&
        activeNpcClassId != MERCHANT_CLASSID_Halbu &&
        activeNpcClassId != MERCHANT_CLASSID_Jamella &&
        activeNpcClassId != MERCHANT_CLASSID_Larzuk &&
        activeNpcClassId != MERCHANT_CLASSID_Drehya &&
        activeNpcClassId != MERCHANT_CLASSID_Malah &&
        activeNpcClassId != MERCHANT_CLASSID_Nihlathak)
    {
        return 0;
    }

    if (ITEMS_IsNotQuestItem(pItem))
    {
        int32_t activeNpcClassId = -1;
        if (*D2Client_pIsNpcDialogOpen_6FBB5CF9)
        {
            D2UnitStrc* activeNpc = D2Client_FindUnit_6FB269F0(*D2Client_pActiveNpcId_6FBB5CF5, 1);
            if (activeNpc != nullptr)
            {
                activeNpcClassId = activeNpc->dwClassId;
            }
        }

        D2C_Difficulties currentDifficulty = (D2C_Difficulties)D2Client_GetCurrentDifficulty_6FAAC090();
        D2UnitStrc* currentPlayer = D2Client_GetCurrentPlayer_6FB283D0();

        *pTransactionCost = ITEMS_GetTransactionCost(currentPlayer, pItem, currentDifficulty, *D2Client_pQuestFlags_6FBB5D13, activeNpcClassId, TRANSACTIONTYPE_SELL);
        const wchar_t* strString = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3331_Sell);

        outBuff.assign(strString);
        outBuff.append(std::to_wstring(*pTransactionCost));

        return 1;
    }

    return 0;
}


void ESE_D2Client_AddExtraTradeStatLines_6FAE5A40(std::wstring& outBuff)
{
    const wchar_t* newlineChar1 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    if (*D2Client_pVendorMode_6FBB58EC == VENDORMODE_REPAIR && ITEMS_CheckItemFlag(*D2Client_pItemUnderCursor, IFLAG_ETHEREAL, __LINE__, __FILE__))
    {
        const wchar_t* v7 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_22746_X_ItemCanNotBeRepaired);

        std::wstring cannotBeTradedString = std::wstring(v7);
        ColorizeString(cannotBeTradedString, 1);

        outBuff.append(newlineChar1);
        outBuff.append(cannotBeTradedString);
    }

    std::wstring itemPriceString;
    int32_t transactionCost = 0;
    if (ESE_D2Client_GetItemTextLinePrice_6FAFB200(*D2Client_pItemUnderCursor, *D2Client_pDWORD_6FB7928C, &transactionCost, itemPriceString))
    {
        if (itemPriceString[0] != 0)
        {
            outBuff.append(newlineChar1);
        }

        outBuff.append(itemPriceString);
    }
    else if (*D2Client_pVendorMode_6FBB58EC != VENDORMODE_REPAIR)
    {
        const wchar_t* strItemCannotBeTradedHere = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3333_priceless);

        std::wstring itemCannotBeTradedHereString = std::wstring(strItemCannotBeTradedHere);
        ColorizeString(itemCannotBeTradedHereString, 1);

        outBuff.append(newlineChar1);
        outBuff.append(itemCannotBeTradedHereString);
    }
}

void DrawTextForBookItem(D2UnitStrc* pItemUnderCursor)
{
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

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

    std::wstring itemDescription;
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

    std::wstring itemName;
    ESE_D2Client_BuildItemName_6FADD360(pItemUnderCursor, itemName);
    itemDescription.append(itemName);

    if (*D2Client_pVendorMode_6FBB58EC >= VENDORMODE_TRADE && *D2Client_pVendorMode_6FBB58EC <= VENDORMODE_UNKNOWN)
    {
        ESE_D2Client_AddExtraTradeStatLines_6FAE5A40(itemDescription);
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
}

void __fastcall ESE_D2Client_GetItemTextLineDurability_6FAE4060(D2UnitStrc* pUnit, std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord)
{
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);

    if (!ITEMS_HasDurability(pUnit) || STATLIST_GetMaxDurabilityFromUnit(pUnit) <= 0 || ITEMS_CheckIfThrowable(pUnit))
    {
        return;
    }

    auto strDurability = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3457_ItemStats1d);
    auto strOf = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3463_ItemStats1j);

    auto maxDurabilityPercent = STATLIST_GetUnitStatBonus(pUnit, STAT_ITEM_MAXDURABILITY_PERCENT, 0);
    auto durability = STATLIST_UnitGetStatValue(pUnit, STAT_DURABILITY, 0);
    auto maxDurability = STATLIST_GetMaxDurabilityFromUnit(pUnit);

    outBuff.append(strDurability);
    outBuff.append(strSpace);
    outBuff.append(std::to_wstring(durability));
    outBuff.append(strSpace);
    outBuff.append(strOf);
    outBuff.append(strSpace);

    std::wstring maxDurabilityStr = std::to_wstring(maxDurability);
    if (maxDurabilityPercent != 0)
    {
        ColorizeString(maxDurabilityStr, 3);
    }

    outBuff.append(maxDurabilityStr);
    outBuff.append(strNewLine);
}

void ESE_D2Client_GetItemTextSocketed_6FAE3EE0(D2UnitStrc* pItem, std::wstring& outBuff)
{
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);

    bool isEthereal = false;

    outBuff.assign(L""); // todo: D2Client_pUnknownStr_6FB9A828? this seems to always be empty and nothing writes to it?
    if (ITEMS_CheckItemFlag(pItem, IFLAG_ETHEREAL, __LINE__, __FILE__))
    {
        std::wstring strEtherealUnused = L"Ethereal";

        const wchar_t* strCannotBeRepaired = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_22745_X_Ethereal_CanNotBeRepaired);
        outBuff.append(strCannotBeRepaired);

        isEthereal = true;
    }

    if (ITEMS_CheckItemFlag(pItem, IFLAG_SOCKETED, __LINE__, __FILE__))
    {
        if (isEthereal)
        {
            outBuff.append(L", ");
        }

        const wchar_t* strSocketed = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3453_Socketable);
        int32_t numSockets = ITEMS_GetSockets(pItem);

        outBuff.append(strSocketed);
        outBuff.append(strSpace);
        outBuff.append(L"(" + std::to_wstring(numSockets) + L")");
        outBuff.append(strNewLine);
    }
    else if (isEthereal)
    {
        outBuff.append(strNewLine);
    }
}

void ESE_D2Client_GetItemTextLineBlockChance_6FAE4EE0(D2UnitStrc* pUnit, std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord)
{
    int32_t blockChance = STATLIST_UnitGetStatValue(pUnit, STAT_TOBLOCK, 0);
    const auto pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
    if (pCurrentPlayer != nullptr)
    {
        D2CharStatsTxt* pCharStatsTxt = nullptr;
        if (pCurrentPlayer->dwClassId >= 0 && pCurrentPlayer->dwClassId < sgptDataTables->nCharStatsTxtRecordCount)
        {
            pCharStatsTxt = &sgptDataTables->pCharStatsTxt[pCurrentPlayer->dwClassId];
        }

        blockChance += pCharStatsTxt->nBlockFactor;

        auto pHolyShieldSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pCurrentPlayer, SKILL_HOLYSHIELD);
        if (pHolyShieldSkill && STATES_CheckState(pCurrentPlayer, STATE_HOLYSHIELD))
        {
            auto holyShieldLevel = SKILLS_GetSkillLevel(pCurrentPlayer, pHolyShieldSkill, 1);
            blockChance += D2Common_11036_GetMonCurseResistanceSubtraction(holyShieldLevel, SKILL_HOLYSHIELD);
        }
    }

    if (blockChance == 0)
    {
        return;
    }

    if (blockChance > 75)
    {
        blockChance = 75;
    }

    std::wstring blockChanceString = std::to_wstring(blockChance) + L"%\n";

    if (blockChance > pItemTxtRecord->nBlock)
    {
        ColorizeString(blockChanceString, 3);
    }

    std::wstring strChanceToBlock = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11018_ItemStats1r);
    ColorizeString(strChanceToBlock, 0);

    outBuff.append(strChanceToBlock);
    outBuff.append(blockChanceString);
}

void ESE_D2Client_GetItemTextLineQuantity_6FAE5710(D2UnitStrc* pUnit, std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord)
{
    if (!pUnit)
    {
        return;
    }
    if (!pItemTxtRecord)
    {
        return;
    }

    if (!pItemTxtRecord->nSpellDesc)
    {
        return;
    }

    auto pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
    if (!pCurrentPlayer)
    {
        return;
    }

    if (pItemTxtRecord->wSpellDescStr == 5382)
    {
        return;
    }

    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);

    if (pItemTxtRecord->nSpellDesc == 1)
    {
        const wchar_t* v6 = (const wchar_t*)D2LANG_GetStringFromTblIndex((D2C_StringIndices)pItemTxtRecord->wSpellDescStr);
        outBuff.assign(v6);
        outBuff.append(strNewLine);
        return;
    }

    int v8 = 0;
    if (pItemTxtRecord->nSpellDesc == 2)
    {
        v8 = ITEMMODS_EvaluateItemFormula(pCurrentPlayer, pUnit, pItemTxtRecord->dwCalc[0]);

        if (pItemTxtRecord->wStat[0] == STAT_HITPOINTS || pItemTxtRecord->wStat[0] == STAT_HPREGEN)
        {
            v8 = ITEMS_GetBonusLifeBasedOnClass(pCurrentPlayer, v8);
        }
        else if (pItemTxtRecord->wStat[0] == STAT_MANA || pItemTxtRecord->wStat[0] == STAT_MANARECOVERY)
        {
            v8 = ITEMS_GetBonusManaBasedOnClass(pCurrentPlayer, v8);
        }
    }
    else if (pItemTxtRecord->nSpellDesc == 3)
    {
        v8 = ITEMMODS_EvaluateItemFormula(pCurrentPlayer, pUnit, pItemTxtRecord->dwCalc[0]);
    }
    else if (pItemTxtRecord->nSpellDesc == 4)
    {
        int32_t v14 = ITEMMODS_EvaluateItemFormula(pCurrentPlayer, pUnit, pItemTxtRecord->dwCalc[0]);
        const wchar_t* format = (const wchar_t*)D2LANG_GetStringFromTblIndex((D2C_StringIndices)pItemTxtRecord->wSpellDescStr);

        AppendFormattedWideString(outBuff, format, v14);
        outBuff.append(strNewLine);
    }
    else
    {
        return;
    }

    const wchar_t* v11 = (const wchar_t*)D2LANG_GetStringFromTblIndex((D2C_StringIndices)pItemTxtRecord->wSpellDescStr);

    outBuff.assign(v11);
    outBuff.append(strSpace);
    outBuff.append(std::to_wstring(v8));
    outBuff.append(strNewLine);
}

void ESE_D2Client_sub_6FAF13C0(D2UnitStrc* pItem, D2GemsTxt* pMods, int32_t nPropSet, std::wstring& outBuff, std::wstring* existingContents)
{
    ITEMMODS_AssignProperty(5, 0, pItem, pMods, nPropSet, 0);

    ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItem, outBuff, 1, existingContents);

    D2StatListStrc* v9 = (D2StatListStrc*)STATLIST_GetStatListFromUnitStateOrFlag(pItem, 0, 64);
    if (v9)
    {
        D2Common_10474(pItem, v9);
        STATLIST_FreeStatList(v9);
    }

    if (outBuff[outBuff.length() - 1] == 10)
    {
        outBuff[outBuff.length() - 1] = 0;
    }
}

void ESE_D2Client_GetItemTextLineRuneGemStats_6FAF1480(D2UnitStrc* pItem, std::wstring& outBuff)
{
    if (!D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_SOCKET_FILLER))
    {
        FOG_DisplayAssert("ITEMSIsA(hItem, ITEMTYPE_SOCKETFILLER_TYPE)", __FILE__, __LINE__);
        exit(-1);
    }

    auto classId = -1;
    if (pItem)
    {
        classId = pItem->dwClassId;
    }

    auto ptItemStats = DATATBLS_GetItemsTxtRecord(classId);
    if (!ptItemStats)
    {
        FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
        exit(-1);
    }

    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);

    const wchar_t* strHelmsAndBoots = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11073_GemXp1);
    const wchar_t* strShieldsArmorAndBelts = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11074_GemXp2);
    const wchar_t* strWeaponsAndGloves = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11075_GemXp3);
    const wchar_t* strRingsAmuletsAndCharms = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11076_GemXp4);

    if (D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_GEM))
    {
        auto ptGemMods = DATATBLS_GetGemsTxtRecord(ptItemStats->dwGemOffset);
        if (!ptGemMods)
        {
            FOG_DisplayAssert("ptGemMods", __FILE__, __LINE__);
            exit(-1);
        }

        outBuff.append(strNewLine);

        std::wstring temp;
        temp.append(strShieldsArmorAndBelts);
        temp.append(strSpace);

        ITEMMODS_AssignProperty(2, 0, pItem, ptGemMods, 2, 0);
        ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItem, outBuff, 0, &temp);

        D2StatListStrc* tempStatList = nullptr;

        tempStatList = (D2StatListStrc*)STATLIST_GetStatListFromUnitStateOrFlag(pItem, 0, 64);
        if (tempStatList)
        {
            D2Common_10474(pItem, tempStatList);
            STATLIST_FreeStatList(tempStatList);
        }

        if (outBuff.ends_with(L'\n'))
        {
            outBuff.pop_back();
        }
        outBuff.append(strNewLine);

        temp.clear();
        temp.append(strHelmsAndBoots);
        temp.append(strSpace);
        ITEMMODS_AssignProperty(2, 0, pItem, ptGemMods, 1, 0);
        ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItem, outBuff, 0, &temp);

        tempStatList = (D2StatListStrc*)STATLIST_GetStatListFromUnitStateOrFlag(pItem, 0, 64);
        if (tempStatList)
        {
            D2Common_10474(pItem, tempStatList);
            STATLIST_FreeStatList(tempStatList);
        }

        if (outBuff.ends_with(L'\n'))
        {
            outBuff.pop_back();
        }
        outBuff.append(strNewLine);

        temp.clear();
        temp.append(strRingsAmuletsAndCharms);
        temp.append(strSpace);
        ITEMMODS_AssignProperty(2, 0, pItem, ptGemMods, 1, 0);
        ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItem, outBuff, 0, &temp);
        tempStatList = (D2StatListStrc*)STATLIST_GetStatListFromUnitStateOrFlag(pItem, 0, 64);
        if (tempStatList)
        {
            D2Common_10474(pItem, tempStatList);
            STATLIST_FreeStatList(tempStatList);
        }

        if (outBuff.ends_with(L'\n'))
        {
            outBuff[outBuff.length() - 1] = 0;
        }
        outBuff.append(strNewLine);

        temp.clear();
        temp.append(strWeaponsAndGloves);
        temp.append(strSpace);
        ITEMMODS_AssignProperty(2, 0, pItem, ptGemMods, 0, 0);
        ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItem, outBuff, 0, &temp);

        tempStatList = (D2StatListStrc*)STATLIST_GetStatListFromUnitStateOrFlag(pItem, 0, 64);
        if (tempStatList)
        {
            D2Common_10474(pItem, tempStatList);
            STATLIST_FreeStatList(tempStatList);
        }

        if (outBuff.ends_with(L'\n'))
        {
            outBuff.pop_back();
        }
    }
    else
    {
        if (!D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_RUNE))
        {
            return;
        }

        auto ptGemMods = DATATBLS_GetGemsTxtRecord(ptItemStats->dwGemOffset);
        if (!ptGemMods)
        {
            FOG_DisplayAssert("ptGemMods", __FILE__, __LINE__);
            exit(-1);
        }

        outBuff.append(strNewLine);

        std::wstring temp;
        temp.append(strShieldsArmorAndBelts);
        temp.append(strSpace);
        ESE_D2Client_sub_6FAF13C0(pItem, ptGemMods, 2, outBuff, &temp);
        outBuff.append(strNewLine);

        temp.clear();
        temp.append(strHelmsAndBoots);
        temp.append(strSpace);
        ESE_D2Client_sub_6FAF13C0(pItem, ptGemMods, 1, outBuff, &temp);
        outBuff.append(strNewLine);

        temp.clear();
        temp.append(strRingsAmuletsAndCharms);
        temp.append(strSpace);
        ESE_D2Client_sub_6FAF13C0(pItem, ptGemMods, 1, outBuff, &temp);
        outBuff.append(strNewLine);

        temp.clear();
        temp.append(strWeaponsAndGloves);
        temp.append(strSpace);
        ESE_D2Client_sub_6FAF13C0(pItem, ptGemMods, 0, outBuff, &temp);
    }

    outBuff.append(strNewLine);
    outBuff.append(strNewLine);
}

void DrawTextForNonSetOrUnidSetItem(D2UnitStrc* v229, int32_t bFlag, int itemQuality)
{
    std::wstring itemDescription;
    itemDescription.reserve(4096);

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
        DrawTextForBookItem(pItemUnderCursor);
        return;
    }

    std::wstring statLine_ClassRestriction_512;
    auto itemUnderCursorClass = ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor);
    if (itemUnderCursorClass != PCLASS_EVILFORCE)
    {
        auto strClassRestriction = (const wchar_t*)D2LANG_GetStringFromTblIndex(itemUnderCursorClass + 10917);
        statLine_ClassRestriction_512.append(strClassRestriction);
        statLine_ClassRestriction_512.append(strNewLine);

        if (v229 && v229->dwClassId != itemUnderCursorClass)
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
            auto strQuantity = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3462_ItemStats1i);
            itemDescription.append(strQuantity);

            auto itemQuantity = STATLIST_UnitGetStatValue(pItemUnderCursor, STAT_QUANTITY, 0);
            itemDescription.append(strSpace);
            itemDescription.append(std::to_wstring(itemQuantity));
            itemDescription.append(strNewLine);

            auto strItemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(itemTxtRecord->wNameStr);
            itemDescription.append(strItemName);
        }
    }
    else
    {
        ESE_D2Client_GetItemTextLineDurability_6FAE4060(pItemUnderCursor, statLine_Durability_512, itemTxtRecord);
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

        auto strCanBeInsertedIntoSocket = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_11080_ExInsertSocketsX);

        ESE_D2Client_GetItemTextLineRuneGemStats_6FAF1480(pItemUnderCursor, statLine_RuneGemStats_512);
        statLine_RuneGemStats_512.append(strCanBeInsertedIntoSocket);
        statLine_RuneGemStats_512.append(strNewLine);
    }

    std::wstring statLine_RunewordName_512;
    if (ITEMS_CheckIfSocketable(pItemUnderCursor))
    {
        if (pItemUnderCursor->pInventory)
        {
            auto pItemInventoryIter = INVENTORY_GetFirstItem(pItemUnderCursor->pInventory);
            if (pItemInventoryIter)
            {
                auto bHasAddedStartingQuote = 0;
                auto strRuneQuote = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_20506_RuneQuote);

                while (INVENTORY_UnitIsItem(pItemInventoryIter))
                {
                    if (D2Common_10731_ITEMS_CheckItemTypeId(pItemInventoryIter, ITEMTYPE_RUNE))
                    {
                        auto gemTxtRecordIndex = DATATBLS_GetItemsTxtRecord(pItemInventoryIter->dwClassId)->dwGemOffset;
                        if (gemTxtRecordIndex > 0)
                        {
                            auto gemsTxtRecord = DATATBLS_GetGemsTxtRecord(gemTxtRecordIndex);
                            if (gemsTxtRecord)
                            {
                                if (!bHasAddedStartingQuote)
                                {
                                    bHasAddedStartingQuote = 1;
                                    statLine_RunewordName_512.append(strRuneQuote);
                                }

                                AppendString(statLine_RunewordName_512, gemsTxtRecord->szLetter);
                            }
                        }
                    }

                    pItemInventoryIter = INVENTORY_GetNextItem(pItemInventoryIter);
                }

                if (bHasAddedStartingQuote)
                {
                    statLine_RunewordName_512.append(strRuneQuote);
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
    std::wstring statLine_KickSmiteDamage;
    std::wstring statLine_Defense_512;

    if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_WEAPON) || D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR))
    {
        ESE_D2Client_GetItemTextSocketed_6FAE3EE0(pItemUnderCursor, statLine_Socketed_512);

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
                ESE_D2Client_GetItemTextLineDamage_6FAE43D0(pItemUnderCursor, statLine_Damage_512, itemTxtRecord);
            }
            ESE_D2Client_GetItemTextLineAttackSpeed_6FAE5570(pItemUnderCursor, statLine_AttackSpeed_2048, itemTxtRecord);
        }
        if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_SHIELD))
        {
            if (v229 && v229->dwClassId == PCLASS_PALADIN && (!ITEMS_IsClassValid(pItemUnderCursor) || ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor) == PCLASS_PALADIN))
            {
                ESE_D2Client_GetItemTextLineSmiteOrKickDamage_6FAE5040(pItemUnderCursor, statLine_KickSmiteDamage, itemTxtRecord);
            }

            ESE_D2Client_GetItemTextLineBlockChance_6FAE4EE0(pItemUnderCursor, statLine_blockChance_512, itemTxtRecord);
        }
        else if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_BOOTS) && v229 && v229->dwClassId == PCLASS_ASSASSIN)
        {
            ESE_D2Client_GetItemTextLineSmiteOrKickDamage_6FAE5040(pItemUnderCursor, statLine_KickSmiteDamage, itemTxtRecord);
        }
        if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR)
            && STATLIST_GetDefenseFromUnit(pItemUnderCursor) > 0)
        {
            // TODO: This is a shady call, investigate it
            ESE_D2Client_GetItemTextLineDefense_6FAE51D0(v229, pItemUnderCursor, statLine_Defense_512, itemTxtRecord);
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

        ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItemUnderCursor, statLine_Stats_8192, 1, 0);
    }
    else
    {
        auto v184 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3455_ItemStats1b);
        itemLineUnidentified.append(v184);
        itemLineUnidentified.append(strNewLine);
    }

    ESE_D2Client_GetItemTextLineQuantity_6FAE5710(pItemUnderCursor, statLine_Quantity_512, itemTxtRecord);

    std::wstring itemLineName;
    ESE_D2Client_BuildItemName_6FADD360(pItemUnderCursor, itemLineName);

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
    AppendColorizedString(itemDescription, statLine_KickSmiteDamage, 0);
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
        ESE_D2Client_AddExtraTradeStatLines_6FAE5A40(itemDescription);
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

void ESE_D2Client_GetItemTextLineLevelRequirement_6FAE41B0(std::wstring& outBuff, int levelRequirement)
{
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    const wchar_t* strRequiredLevel = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3469_ItemStats1p);

    outBuff.assign(strRequiredLevel);
    outBuff.append(strSpace);
    outBuff.append(std::to_wstring(levelRequirement));
    outBuff.append(strNewLine);
}

void ESE_D2Client_GetItemTextStrRequirement_6FAE4250(std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord, int requiredStr)
{
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    auto totalRequiredStr = requiredStr + pItemTxtRecord->wReqStr;
    if (totalRequiredStr > 0)
    {
        const wchar_t* v9 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3458_ItemStats1e);

        outBuff.assign(v9);
        outBuff.append(strSpace);
        outBuff.append(std::to_wstring(totalRequiredStr));
        outBuff.append(strNewLine);
    }
    else
    {
        outBuff.clear();
    }
}

void ESE_D2Client_GetItemTextDexRequirement_6FAE4310(std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord, int requiredDex)
{
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    auto totalRequiredDex = requiredDex + pItemTxtRecord->wReqDex;
    if (totalRequiredDex > 0)
    {
        const wchar_t* v9 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3459_ItemStats1f);

        outBuff.append(v9);
        outBuff.append(strSpace);
        outBuff.append(std::to_wstring(totalRequiredDex));
        outBuff.append(strNewLine);
    }
    else
    {
        outBuff.clear();
    }
}

void ESE_D2Client_GetItemTextLineAttackSpeed_6FAE5570(D2UnitStrc* pItem, std::wstring& outBuff, D2ItemsTxt* pItemTxtRecord)
{
    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
    const wchar_t* strDash = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3996_dash);
    D2UnitStrc* pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
    int32_t weaponAttackSpeed = ITEMS_GetWeaponAttackSpeed(pCurrentPlayer, pItem);
    int32_t fasterCastRateBonus = STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_FASTERATTACKRATE, 0);

    int32_t attackSpeedIndex = 5; // Very Slow Attack Speed
    if (weaponAttackSpeed < 28)
    {
        attackSpeedIndex = 1; // Very Fast Attack Speed
        if (weaponAttackSpeed >= 10)
        {
            bool isBowOrCrossbow = D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_CROSSBOW) || D2Common_10731_ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BOW);
            int32_t classId = -1;
            if (pCurrentPlayer)
            {
                classId = pCurrentPlayer->dwClassId;
            }
            attackSpeedIndex = D2Client_pWeaponSpeedStringIndexLookupTable_6FB79360[5 * weaponAttackSpeed - 50 + D2Client_pDWORD_6FB794C8[2 * classId + isBowOrCrossbow]];
        }
    }

    // D2Client_pWeaponClassStringIndices_6FB792D8 = [
    //   {id = 26 stringIndex = 4085 }  // Staff Class
    //   {id = 28 stringIndex = 4078 }  // Axe Class
    //   {id = 30 stringIndex = 4079 }  // Sword Class
    //   {id = 32 stringIndex = 4080 }  // Dagger Class
    //   {id = 38 stringIndex = 4081 }  // Equip to Throw
    //   {id = 44 stringIndex = 4082 }  // Javelin Class
    //   {id = 33 stringIndex = 4083 }  // Spear Class
    //   {id = 27 stringIndex = 4084 }  // Bow Class
    //   {id = 34 stringIndex = 4086 }  // Polearm Class
    //   {id = 35 stringIndex = 4087 }  // Crossbow Class
    //   {id = 67 stringIndex = 21258 } // Claw Class
    //   {id = 88 stringIndex = 21258 } // Claw Class
    //   {id = 68 stringIndex = 4085 }  // Staff Class
    //   {id = 25 stringIndex = 4085 }  // Staff Class
    //   {id = 57 stringIndex = 4077 }  // Mace Class
    // ]
    for (int32_t i = 0; i < 15; i++)
    {
        if (!D2Common_10731_ITEMS_CheckItemTypeId(pItem, D2Client_pWeaponClassStringIndices_6FB792D8[i].id))
        {
            continue;
        }

        const wchar_t* strWeaponClass = (const wchar_t*)D2LANG_GetStringFromTblIndex(D2Client_pWeaponClassStringIndices_6FB792D8[i].stringIndex);
        outBuff.append(strWeaponClass);
        outBuff.append(strSpace);
        outBuff.append(strDash);
        outBuff.append(strSpace);

        break;
    }

    // D2Client_pAttackSpeedStringIndices_6FB79334 = [
    //   {id = 0 stringIndex = 4088 } // Fastest Attack Speed
    //   {id = 1 stringIndex = 4089 } // Very Fast Attack Speed
    //   {id = 2 stringIndex = 4090 } // Fast Attack Speed
    //   {id = 3 stringIndex = 4091 } // Normal Attack Speed
    //   {id = 4 stringIndex = 4092 } // Slow Attack Speed
    //   {id = 5 stringIndex = 4093 } // Very Slow Attack Speed
    //   {id = 6 stringIndex = 4094 } // Slowest Attack Speed
    // ];
    std::wstring strAttackSpeed((const wchar_t*)D2LANG_GetStringFromTblIndex(D2Client_pAttackSpeedStringIndices_6FB79334[attackSpeedIndex].stringIndex));
    if (fasterCastRateBonus != 0)
    {
        ColorizeString(strAttackSpeed, 3);
    }

    outBuff.append(strAttackSpeed);
    outBuff.append(strNewLine);
}

void ESE_D2Client_GetItemTextSet_6FAF32B0(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, std::wstring& outBuff)
{
    static int32_t setItemStates[6] =
    {
       STATE_ITEMSET1, STATE_ITEMSET2, STATE_ITEMSET3, STATE_ITEMSET4, STATE_ITEMSET5, STATE_ITEMSET6
    };

    if (!pSetItem)
    {
        return;
    }

    if (pSetItem->dwUnitType != 4 || ITEMS_GetItemQuality(pSetItem) != ITEMQUAL_SET)
    {
        return;
    }

    auto pSetItemsTxtRecord = ITEMS_GetSetItemsTxtRecordFromItem(pSetItem);
    if (!pSetItemsTxtRecord)
    {
        return;
    }

    auto v7 = pSetItemsTxtRecord->nAddFunc - 1;
    if (v7)
    {
        if (v7 != 1)
        {
            return;
        }

        int32_t numSetItems = 0;
        auto setItemMask = ITEMS_GetSetItemsMask(pPlayer, pSetItem, 1);
        if (setItemMask < 64)
        {
            numSetItems = std::popcount(setItemMask);
        }

        for (int32_t i = 0; i < numSetItems - 1; ++i)
        {
            ESE_D2Client_GetItemTextLinePropertiesInternal_6FAF19C0(pSetItem, outBuff, 0, setItemStates[i], 0, 0, 1);
        }

        return;
    }

    auto setItemMask = std::bitset<32>(ITEMS_GetSetItemsMask(pPlayer, pSetItem, 0));
    auto numberOfSetItems = ITEMS_GetNoOfSetItemsFromItem(pSetItem);

    // Nothing about this loop or logic inside of it makes sense
    for (int32_t setItemIndex = 0; setItemIndex < std::size(setItemStates); ++setItemIndex)
    {
        if (setItemIndex == numberOfSetItems)
        {
            continue;
        }

        auto setItemNumber = setItemIndex;
        if (setItemIndex > numberOfSetItems)
        {
            --setItemNumber;
        }

        if (setItemMask.test(setItemIndex))
        {
            if (setItemNumber >= 0) // Bug: setItemNumber can potentially be -1 in the original code?
            {
                ESE_D2Client_GetItemTextLinePropertiesInternal_6FAF19C0(pSetItem, outBuff, 0, setItemStates[setItemNumber], 0, 0, 1);
            }
        }
    }
}

void ESE_D2Client_GetItemTextSetB_6FAF33C0(D2UnitStrc* pUnit, D2UnitStrc* pItem, std::wstring& outBuff)
{
    static int32_t setItemStates[6] =
    {
       STATE_ITEMSET1, STATE_ITEMSET2, STATE_ITEMSET3, STATE_ITEMSET4, STATE_ITEMSET5, STATE_ITEMSET6
    };

    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_SET)
    {
        return;
    }

    auto setItemTxtRecordIndex = ITEMS_GetFileIndex(pItem);
    if (setItemTxtRecordIndex < 0 || setItemTxtRecordIndex >= sgptDataTables->nSetItemsTxtRecordCount)
    {
        return;
    }

    auto pSetItemsTxt = &sgptDataTables->pSetItemsTxt[setItemTxtRecordIndex];
    if (!pSetItemsTxt)
    {
        return;
    }

    for (std::size_t i = 0; i < std::size(setItemStates); i++)
    {
        D2StatListStrc* setStatList = STATLIST_GetStatListFromUnitAndState(pUnit, setItemStates[i]);
        if (setStatList)
        {
            if (pSetItemsTxt->nSetId == D2Common_10466_STATLIST_GetStatValue(setStatList, STAT_VALUE, 0))
            {
                ESE_D2Client_GetItemTextLinePropertiesInternal_6FAF19C0(pUnit, outBuff, 0, setItemStates[i], 0, 0, 1);
                return;
            }
        }
    }
}

void DrawTextForSetItem(D2UnitStrc* pUnit_, int32_t bFlag, int itemQuality)
{
    std::wstring itemDescription;
    itemDescription.reserve(4096);

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

            ESE_D2Client_GetItemTextLineDurability_6FAE4060(pItemUnderCursor, itemLineDurability, pItemsTxtRecord);

            auto levelRequirement = ITEMS_GetLevelRequirement(pItemUnderCursor, pUnit_);
            if (levelRequirement > 1)
            {
                if (!bRequiresLevel)
                {
                    colorCodeLevelRequirement = 1;
                }

                ESE_D2Client_GetItemTextLineLevelRequirement_6FAE41B0(itemLineLevelRequirement, levelRequirement);
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

                    ESE_D2Client_GetItemTextStrRequirement_6FAE4250(itemLineStrRequirement, pItemsTxtRecord, strRequirement);
                }
                if (pItemsTxtRecord->wReqDex)
                {
                    if (!bRequiresDex)
                    {
                        colorCodeDexRequirement = 1;
                    }

                    ESE_D2Client_GetItemTextDexRequirement_6FAE4310(itemLineDexRequirement, pItemsTxtRecord, dexRequirement);
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
                std::wstring attackSpeed;
                ESE_D2Client_GetItemTextLineAttackSpeed_6FAE5570(pItemUnderCursor, attackSpeed, pItemsTxtRecord);
                AppendColorizedString(itemLineBasicInfo, attackSpeed, 0);

                if (STATLIST_GetMinDamageFromUnit(pItemUnderCursor, 0) >= 0 && STATLIST_GetMaxDamageFromUnit(pItemUnderCursor, 0) >= 0)
                {
                    std::wstring itemDamageString;
                    ESE_D2Client_GetItemTextLineDamage_6FAE43D0(pItemUnderCursor, itemDamageString, pItemsTxtRecord);
                    AppendColorizedString(itemLineBasicInfo, itemDamageString, 0);
                }
            }
            if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_SHIELD))
            {
                if (pUnit_ && !pUnit_->dwUnitType && pUnit_->dwClassId == PCLASS_PALADIN && (!ITEMS_IsClassValid(pItemUnderCursor) || ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor) == PCLASS_PALADIN))
                {
                    std::wstring smiteDamageLine;
                    ESE_D2Client_GetItemTextLineSmiteOrKickDamage_6FAE5040(pItemUnderCursor, smiteDamageLine, pItemsTxtRecord);
                    AppendColorizedString(itemLineBasicInfo, smiteDamageLine, 0);
                }

                std::wstring blockChanceLine;
                ESE_D2Client_GetItemTextLineBlockChance_6FAE4EE0(pItemUnderCursor, blockChanceLine, pItemsTxtRecord);
                ColorizeString(blockChanceLine, 0);
                itemLineBasicInfo.append(blockChanceLine);
            }
            if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR)
                && STATLIST_GetDefenseFromUnit(pItemUnderCursor) > 0)
            {
                std::wstring armorString;
                ESE_D2Client_GetItemTextLineDefense_6FAE51D0(pUnit_, pItemUnderCursor, armorString, pItemsTxtRecord);
                AppendColorizedString(itemLineBasicInfo, armorString, 0);
            }

            auto isItemBroken = ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_BROKEN, __LINE__, __FILE__);

            std::wstring itemNameBuff;
            ESE_D2Client_BuildItemName_6FADD360(pItemUnderCursor, itemNameBuff);
            AppendColorizedString(itemLineBasicInfo, itemNameBuff, isItemBroken ? 1 : 2);

            std::wstring textLineProperties;
            if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_SOCKETED, __LINE__, __FILE__))
            {
                ESE_D2Client_GetItemTextSocketed_6FAE3EE0(pItemUnderCursor, textLineProperties);
            }

            ESE_D2Client_GetItemTextLineProperties_6FAF3160(pItemUnderCursor, textLineProperties, 1, 0);

            std::wstring textLineSet;
            ESE_D2Client_GetItemTextSet_6FAF32B0(pUnit_, pItemUnderCursor, textLineSet);

            std::wstring textLineSetBonus;
            if (pItemUnderCursor && pItemUnderCursor->dwItemMode == IMODE_EQUIP)
            {
                ESE_D2Client_GetItemTextSetB_6FAF33C0(pUnit_, pItemUnderCursor, textLineSetBonus);
            }

            std::wstring textLineSetNames;

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

                    std::wstring setNameLine;
                    if (pUnita->wStringId)
                    {
                        auto strSetItemName = (const wchar_t*)D2LANG_GetStringFromTblIndex(pUnita->wStringId);
                        auto strSetItemNameFormat = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_10089_SetItemFormatX);

                        std::wstring formattedName;
                        ESE_D2Client_FormatName_6FADCFE0(formattedName, strSetItemNameFormat, strSetItemName, 0);
                        setNameLine.append(formattedName);
                        setNameLine.append(strNewLine);
                    }
                    AppendColorizedString(textLineSetNames, setNameLine, setItem ? 2 : 1);
                }
            }

            std::wstring pTextToDisplay;

            AppendColorizedString(pTextToDisplay, textLineSetNames, 2);
            AppendColorizedString(pTextToDisplay, itemLineCompleteSetName, 4);

            if (textLineSetBonus[0])
            {
                pTextToDisplay.append(strNewLine);
                AppendColorizedString(pTextToDisplay, textLineSetBonus, 4);
            }
            pTextToDisplay.append(strNewLine);
            if (textLineSet[0])
            {
                AppendColorizedString(pTextToDisplay, textLineSet, 2);
            }

            AppendColorizedString(pTextToDisplay, textLineProperties, 3);
            pTextToDisplay.append(itemLineBasicInfo);

            if (*D2Client_pVendorMode_6FBB58EC != VENDORMODE_NONE && *D2Client_pVendorMode_6FBB58EC >= 1 && *D2Client_pVendorMode_6FBB58EC <= 9)
            {
                int32_t transactionCost = 0;
                std::wstring itemPriceString;
                if (ESE_D2Client_GetItemTextLinePrice_6FAFB200(pItemUnderCursor, *D2Client_pDWORD_6FB7928C, &transactionCost, itemPriceString))
                {
                    if (itemPriceString[0])
                    {
                        pTextToDisplay.append(strNewLine);
                    }

                    pTextToDisplay.append(itemPriceString);
                }
                else
                {
                    if (*D2Client_pVendorMode_6FBB58EC != VENDORMODE_REPAIR)
                    {
                        pTextToDisplay.append(strNewLine);

                        auto strItemCannotBeSold = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3333_priceless);
                        AppendColorizedString(pTextToDisplay, strItemCannotBeSold, 1);
                    }
                }
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

    std::wstring itemNameBuff;
    ESE_D2Client_BuildItemName_6FADD360(pItemUnderCursor, itemNameBuff);

    itemDescription.append(strItemName);
    itemDescription.append(strNewLine);
    itemDescription.append(strConvertsTo);
    itemDescription.append(strNewLine);
    itemDescription.append(itemNameBuff);

    if (*D2Client_pVendorMode_6FBB58EC >= VENDORMODE_TRADE && *D2Client_pVendorMode_6FBB58EC <= VENDORMODE_UNKNOWN)
    {
        ESE_D2Client_AddExtraTradeStatLines_6FAE5A40(itemDescription);
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

    std::wstring itemNameBuff;
    ESE_D2Client_BuildItemName_6FADD360(pItemUnderCursor, itemNameBuff);

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

    itemDescription.append(itemNameBuff);
    ColorizeString(itemDescription, 0);

    ESE_D2Client_AddExtraTradeStatLines_6FAE5A40(itemDescription);

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

void __fastcall ESE_UI_INV_DrawMouseOverItemFrame_6FAE1890(D2UnitStrc* pUnit, int32_t bUnitIsMerchant)
{
    auto pItemUnderCursor = *D2Client_pItemUnderCursor;

    D2UnitStrc* currentPlayer = pUnit;
    if (bUnitIsMerchant && D2Client_GetCurrentPlayer_6FB283D0())
    {
        currentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
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
        // todo: skip this return for maphack inventory viewer
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
        DrawTextForNonSetOrUnidSetItem(currentPlayer, bUnitIsMerchant, itemQuality);
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
        DrawTextForSetItem(pUnit_, bUnitIsMerchant, itemQuality);
        return;
    }
}

