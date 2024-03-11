#include <D2Client/CHARSCREENDMG_ESE.h>
#include <D2Common/D2Skills_ESE.h>
#include <DataTbls/SkillsIds.h>
#include <D2Common/Units/Missile_ESE.h>
#include "LibESE.h"
#include <D2Combat.h>
#include "Font.h"
#include <cinttypes>
#include <D2States.h>
#include <string>
#include <codecvt>

void AppendString(std::wstring &dest, const char* source)
{
    std::string str(source);
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    dest.append(converter.from_bytes(str));
}

void ColorizeString(std::wstring &str, int32_t color)
{
    auto colorCodeToken = (wchar_t *)D2LANG_GetStringFromTblIndex(3994);
    std::wstring colorStr(colorCodeToken);
    colorStr.append(std::to_wstring(color));

    str.insert(0, str);
}

void AppendColorizedString(std::wstring &dest, const std::wstring &src, int32_t color)
{
    auto colorCodeToken = (wchar_t*)D2LANG_GetStringFromTblIndex(3994);
    dest.append(colorCodeToken);
    dest.append(std::to_wstring(color));
    dest.append(src);
}

void __fastcall ESE_UI_INV_DrawMouseOverItemFrame(D2UnitStrc* pItemMaybe, int32_t bFlag)
{
    std::wstring itemDescription;
    itemDescription.reserve(4096);
    wchar_t scratchpad[8192] = { 0 };

    auto pItemUnderCursor = *D2Client_pItemUnderCursor_6FBB58F0;

    auto strNewline_1 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);

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
                auto v53 = (wchar_t*)D2LANG_GetStringFromTblIndex(4144);
                D2Win_10129_DrawFramedText((Unicode *)v53, v52, v220, 0, 1);
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
            auto v59 = (wchar_t*)D2LANG_GetStringFromTblIndex(4144);
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
        auto v71 = (wchar_t*)D2LANG_GetStringFromTblIndex(22726);

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

                D2Win_10129_DrawFramedText((Unicode*)itemDescription.c_str(), v76 + *D2Client_pDWORD_6FBBA748, 21 - *D2Client_pDWORD_6FBBA74C, 0, 1);
                goto LABEL_97;
            }
            auto v74 = (wchar_t*)D2LANG_GetStringFromTblIndex(3997);
            itemDescription.append(v74);
            v73 = 0;
        }
        else
        {
            auto v72 = (wchar_t*)D2LANG_GetStringFromTblIndex(3997);
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

        D2Win_10129_DrawFramedText((Unicode *)itemDescription.c_str(), v76 + *D2Client_pDWORD_6FBBA748, 21 - *D2Client_pDWORD_6FBBA74C, 0, 1);
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

        D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode *)scratchpad, std::size(scratchpad));
        auto strUnidentified = (wchar_t*)D2LANG_GetStringFromTblIndex(3455);
        itemDescription.append(strUnidentified);
        itemDescription.append(strNewline_1);

        int32_t v79 = 0;
        switch (ITEMS_GetItemType(pItemUnderCursor))
        {
        case ITEMTYPE_AMAZON_ITEM:
        case ITEMTYPE_AMAZON_BOW:
        case ITEMTYPE_AMAZON_SPEAR:
        case ITEMTYPE_AMAZON_JAVELIN:
            v79 = 10917;
            break;
        case ITEMTYPE_BARBARIAN_ITEM:
        case ITEMTYPE_PRIMAL_HELM:
            v79 = 10921;
            break;
        case ITEMTYPE_NECROMANCER_ITEM:
        case ITEMTYPE_VOODOO_HEADS:
            v79 = 10919;
            break;
        case ITEMTYPE_PALADIN_ITEM:
        case ITEMTYPE_AURIC_SHIELDS:
            v79 = 10920;
            break;
        case ITEMTYPE_SORCERESS_ITEM:
        case ITEMTYPE_ORB:
            v79 = 10918;
            break;
        case ITEMTYPE_ASSASSIN_ITEM:
        case ITEMTYPE_HAND_TO_HAND:
        case ITEMTYPE_HAND_TO_HAND_2:
            v79 = 10923;
            break;
        case ITEMTYPE_DRUID_ITEM:
        case ITEMTYPE_PELT:
        case ITEMTYPE_CLOAK:
            v79 = 10922;
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
        D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode *)itemDescription.c_str(), (Unicode *)scratchpad);

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

        auto v209 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
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

        auto v213 = (wchar_t*)D2LANG_GetStringFromTblIndex(5387);
        itemDescription.append(v213);
        auto v214 = (wchar_t*)D2LANG_GetStringFromTblIndex(ptNewItemStats->wNameStr);
        itemDescription.append(v214);
        itemDescription.append(v209);
        auto v215 = (wchar_t*)D2LANG_GetStringFromTblIndex(5387);
        itemDescription.append(v215);
        itemDescription.append(v209);
        
        D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode *)scratchpad, std::size(scratchpad));
        itemDescription.append(scratchpad);

        const wchar_t* finalFramedText = itemDescription.c_str();
        if (*D2Client_pDWORD_6FBB58EC < 1 || *D2Client_pDWORD_6FBB58EC > 9)
        {
            finalFramedText = itemDescription.c_str();
        }
        else
        {
            D2Client_AddExtraTradeStatLines_6FAE5A40((Unicode *)itemDescription.c_str(), (Unicode *)scratchpad);
            finalFramedText = scratchpad;
        }

        int32_t height = 0;
        int32_t width = 0;
        D2Win_10131_GetTextDimensions((const Unicode *)finalFramedText, &height, &width);

        if (*D2Client_pDWORD_6FB79294 - width > 0)
        {
            D2Win_10129_DrawFramedText((const Unicode*)finalFramedText, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 0);
            return;
        }

        D2Win_10129_DrawFramedText((const Unicode*)finalFramedText, *D2Client_pDWORD_6FB79298, width + *D2Client_pDWORD_6FB7929C, 0, 0);
        return;
    }

    if (itemQuality != 5 || !ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_IDENTIFIED, __LINE__, __FILE__))
    {
        itemDescription.clear();

        int32_t colorCode = 0;
        int32_t colorCode2 = 0;
        int32_t colorCode3 = 0;
        int32_t colorCode245 = 0;

        if (ITEMS_GetItemType(pItemUnderCursor) == ITEMTYPE_BOOK)
        {
            auto v126 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
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

            D2Client_sub_6FAE54B0(pItemUnderCursor, (Unicode *)scratchpad, pItemTxtRecord);
            if (!*D2Client_pDWORD_6FBB58EC)
            {
                auto v129 = (wchar_t*)D2LANG_GetStringFromTblIndex(2203);
                itemDescription.append(v129);
                itemDescription.append(v126);

                auto v130 = (wchar_t*)D2LANG_GetStringFromTblIndex(2206);
                itemDescription.append(v130);
                itemDescription.append(v126);
            }

            D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode *)scratchpad, std::size(scratchpad));
            itemDescription.append(scratchpad);

            const wchar_t *finalFramedText = nullptr;

            if (*D2Client_pDWORD_6FBB58EC < 1 || *D2Client_pDWORD_6FBB58EC > 9)
            {
                finalFramedText = itemDescription.c_str();
            }
            else
            {
                D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode *)itemDescription.c_str(), (Unicode *)scratchpad);
                finalFramedText = scratchpad;
            }

            int32_t height = 0;
            int32_t width = 0;
            D2Win_10131_GetTextDimensions((const Unicode *)finalFramedText, &width, &height);

            if (*D2Client_pDWORD_6FB79294 - height > 0)
            {
                D2Win_10129_DrawFramedText((const Unicode*)finalFramedText, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 0);
                return;
            }

            auto v120 = height + *D2Client_pDWORD_6FB7929C;
            D2Win_10129_DrawFramedText((const Unicode*)finalFramedText, *D2Client_pDWORD_6FB79298, v120, 0, 0);
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
            auto strSpace2 = (wchar_t*)D2LANG_GetStringFromTblIndex(3995);
            auto strNewline2 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
            if (STATLIST_UnitGetStatValue(pItemUnderCursor, STAT_QUANTITY, 0) > 0)
            {
                // TODO: This is going to be wiped out later with a strcpy to itemDescription...
                auto v143 = (wchar_t*)D2LANG_GetStringFromTblIndex(3462);
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
            D2Client_GetItemTextLineDurability_6FAE4060(pItemUnderCursor, (Unicode *)scratchpad, itemTxtRecord);
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

                auto strSpace = (wchar_t*)D2LANG_GetStringFromTblIndex(3995);
                auto strNewline = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
                auto strRequiredLevel = (wchar_t*)D2LANG_GetStringFromTblIndex(3469);

                statLine_RequiredLevel512.append(strRequiredLevel);
                statLine_RequiredLevel512.append(strSpace);
                statLine_RequiredLevel512.append(std::to_wstring(levelRequirement));
                statLine_RequiredLevel512.append(strNewline);
            }
        }

        std::wstring statLine_RuneGemStats_512;
        if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_SOCKET_FILLER))
        {
            auto v152 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
            if (!D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_SOCKET_FILLER))
            {
                FOG_DisplayAssert("ITEMSIsA(sghSelItem, ITEMTYPE_SOCKETFILLER_TYPE)", __FILE__, __LINE__);
                exit(-1);
            }
            D2Client_GetItemTextLineRuneGemStats_6FAF1480(pItemUnderCursor, (Unicode *)scratchpad, std::size(scratchpad));
            auto v153 = (wchar_t*)D2LANG_GetStringFromTblIndex(11080);
            statLine_RuneGemStats_512.append(v153);
            statLine_RuneGemStats_512.append(v152);
        }

        std::wstring statLine_RunewordName_512;
        if (ITEMS_CheckIfSocketable(pItemUnderCursor))
        {
            if (pItemUnderCursor->pInventory)
            {
                auto v241 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
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
                                        auto v163 = (wchar_t*)D2LANG_GetStringFromTblIndex(20506);
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
            auto v164 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
            auto v165 = (wchar_t*)D2LANG_GetStringFromTblIndex(20438);
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
            D2Client_GetItemTextSocketed_6FAE3EE0(pItemUnderCursor, (Unicode *)scratchpad);
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

                auto v237 = (wchar_t*)D2LANG_GetStringFromTblIndex(3995);
                auto v241 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
                auto v171 = v166 + itemTxtRecord->wReqDex;
                if (v171 > 0)
                {
                    auto v172 = (wchar_t*)D2LANG_GetStringFromTblIndex(3459);
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

                auto v174 = (wchar_t*)D2LANG_GetStringFromTblIndex(3995);
                auto v238 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
                auto v175 = v167 + itemTxtRecord->wReqStr;
                if (v175 > 0)
                {
                    auto v176 = (wchar_t*)D2LANG_GetStringFromTblIndex(3458);
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
                    D2Client_GetItemTextLineDamage_6FAE43D0(pItemUnderCursor, (Unicode *)scratchpad, itemTxtRecord);
                    statLine_Damage_512.append(scratchpad);
                }
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
                    D2Client_GetItemTextLineUnknownA_6FAE5040(pItemUnderCursor, (Unicode *)scratchpad, itemTxtRecord);
                    statLine_v273_512.append(scratchpad);
                }
                D2Client_GetItemTextLineBlockChance_6FAE4EE0(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
                statLine_blockChance_512.append(scratchpad);

            }
            else if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_BOOTS) && v229 && v229->dwClassId == 6)
            {
                D2Client_GetItemTextLineUnknownA_6FAE5040(pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
                statLine_v273_512.append(scratchpad);
            }
            if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR)
                && STATLIST_GetDefenseFromUnit(pItemUnderCursor) > 0)
            {
                // TODO: This is a shady call, investigate it
                D2Client_GetItemTextLineDefense_6FAE51D0(v229, pItemUnderCursor, (Unicode*)scratchpad, itemTxtRecord);
                statLine_Defense_512.append(scratchpad);
            }
        }

        int32_t colorCode_Name = 0;
        switch (itemQuality)
        {
        case 4u:
            colorCode_Name = 3;
            break;
        case 5u:
            colorCode_Name = 2;
            break;
        case 6u:
            colorCode_Name = 9;
            break;
        case 7u:
            colorCode_Name = 4;
            break;
        case 8u:
            colorCode_Name = 8;
            break;
        case 9u:
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
                auto v178 = (wchar_t*)D2LANG_GetStringFromTblIndex(3995);
                auto v179 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);
                if (STATLIST_UnitGetStatValue(v177, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(v177) > 0)
                {
                    auto v180 = (wchar_t*)D2LANG_GetStringFromTblIndex(3462);
                    statLine_Quantity_512.append(v180);
                    auto v181 = STATLIST_UnitGetStatValue(v177, STAT_QUANTITY, 0);
                    statLine_Quantity_512.append(v178);
                    statLine_Quantity_512.append(std::to_wstring(v181));
                    statLine_Quantity_512.append(v179);
                }
            }
            D2Client_GetItemTextLineProperties_6FAF3160(pItemUnderCursor, (Unicode *)scratchpad, std::size(scratchpad), 1, 0);
            statLine_Stats_8192.append(scratchpad);
        }
        else
        {
            auto v184 = (wchar_t*)D2LANG_GetStringFromTblIndex(3455);
            itemLineUnidentified.append(v184);
            itemLineUnidentified.append(strNewline_1);
        }

        D2Client_GetItemTextLineQuantity_6FAE5710(pItemUnderCursor, (Unicode *)scratchpad, itemTxtRecord);
        statLine_Quantity_512.append(scratchpad);

        
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

        const wchar_t *itemDescriptionFinalBuffer2046 = nullptr;
        if (*D2Client_pDWORD_6FBB58EC && *D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
        {
            D2Client_AddExtraTradeStatLines_6FAE5A40((const Unicode *)itemDescription.c_str(), (Unicode *)scratchpad);
            itemDescriptionFinalBuffer2046 = scratchpad;
        }
        else
        {
            itemDescriptionFinalBuffer2046 = itemDescription.c_str();
        }

        if (!itemTxtRecord->nQuest || itemTxtRecord->dwCode == 543647084)
        {
            //if (Unicode::strlen(itemDescriptionFinalBuffer2046) >= 1023u)
            //{
            //    // This is injecting a null terminator somewhere. I'm just going to assume itemDescriptionFinalBuffer
            //    itemDescriptionFinalBuffer2046[std::size(itemDescriptionFinalBuffer2046) - 1] = 0; 
            //}

            int32_t nWidth = 0;
            int32_t nHeight = 0;
            D2Win_10131_GetTextDimensions((const Unicode *)itemDescriptionFinalBuffer2046, &nWidth, &nHeight);
            if (*D2Client_pDWORD_6FB79294 - nHeight > 0)
            {
                D2Win_10129_DrawFramedText((const Unicode*)itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 1);
                return;
            }

            D2Win_10129_DrawFramedText((const Unicode*)itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79298, (*D2Client_pDWORD_6FB7929C + nHeight), 0, 1);
            return;
        }

        if (!*D2Client_pDWORD_6FBB58EC && (!pItemUnderCursor || !pItemUnderCursor->dwAnimMode))
        {
            if (itemTxtRecord->dwCode == 543452002)
            {
                itemDescription = std::wstring();

                auto v205 = (wchar_t*)D2LANG_GetStringFromTblIndex(2205);
                itemDescription.append(v205);
                itemDescription.append(strNewline_1);
                itemDescription.append(itemDescriptionFinalBuffer2046);
                itemDescriptionFinalBuffer2046 = itemDescription.c_str();
            }
            else if (itemTxtRecord->dwCode == 544763746)
            {
                itemDescription = std::wstring();

                auto v205 = (wchar_t*)D2LANG_GetStringFromTblIndex(2204);
                itemDescription.append(v205);
                itemDescription.append(strNewline_1);
                itemDescription.append(itemDescriptionFinalBuffer2046);
                itemDescriptionFinalBuffer2046 = itemDescription.c_str();
            }
        }

        // TODO: Colorize this
        //D2Client_ColorizeLine_6FB20430(itemDescriptionFinalBuffer2046, 4);
        
        //if (Unicode::strlen(itemDescriptionFinalBuffer2046) >= 1023u)
        //{
        //    // This is injecting a null terminator somewhere. I'm just going to assume itemDescriptionFinalBuffer
        //    itemDescriptionFinalBuffer2046[std::size(itemDescriptionFinalBuffer2046) - 1] = 0;
        //}

        int32_t nWidth = 0;
        int32_t nHeight = 0;
        D2Win_10131_GetTextDimensions((const Unicode *)itemDescriptionFinalBuffer2046, &nWidth, &nHeight);
        if (*D2Client_pDWORD_6FB79294 - nHeight > 0)
        {
            D2Win_10129_DrawFramedText((const Unicode*)itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 4, 1);
            return;
        }

        D2Win_10129_DrawFramedText((const Unicode*)itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79298, (*D2Client_pDWORD_6FB7929C + nHeight), 4, 1);
        return;
    }

    int32_t colorCode = 0;
    int32_t colorCode2 = 0;
    int32_t colorCode3 = 0;
    int32_t colorCode245 = 0;

    auto v235 = (wchar_t*)D2LANG_GetStringFromTblIndex(3998);

    auto pUnit_ = pItemMaybe;
    if (pItemMaybe->dwUnitType == 1 && !MONSTERS_GetHirelingTypeId(pItemMaybe))
    {
        pUnit_ = D2Client_sub_6FB283D0();
    }

    if ((*D2Client_pDWORD_6FBB58E4 || *D2Client_pDWORD_6FBB58E0)
        && pItemUnderCursor
        && !INVENTORY_GetCursorItem(pItemMaybe->pInventory))
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
        auto v90 = D2Client_GetSetItemsTxt_6FAE5C80(itemFileIndex);
        if (v90)
        {
            auto v233 = D2Client_sub_6FAE5C50(v90->nSetId);
            if (v233)
            {

                std::wstring itemLineUnknownC;
                std::wstring itemLineBasicInfo;
                std::wstring itemLineLevelRequirement;
                std::wstring itemLineDurability;
                std::wstring itemLineStrRequirement;
                std::wstring itemLineDexRequirement;

                auto v92 = (wchar_t*)D2LANG_GetStringFromTblIndex(v233->wStringId);
                itemLineUnknownC.append(v92);
                itemLineUnknownC.append(v235);


                BOOL bRequiresStr = false;
                BOOL bRequiresDex = false;
                BOOL bRequiresLevel = false;
                ITEMS_CheckRequirements(pItemUnderCursor, pUnit_, 0, &bRequiresStr, &bRequiresDex, &bRequiresLevel);

                D2Client_GetItemTextLineDurability_6FAE4060(pItemUnderCursor, (Unicode *)scratchpad, pItemsTxtRecord);
                itemLineDurability.append(scratchpad);

                auto levelRequirement = ITEMS_GetLevelRequirement(pItemUnderCursor, pUnit_);
                if (levelRequirement > 1)
                {
                    if (!bRequiresLevel)
                    {
                        colorCode = 1;
                    }

                    D2Client_GetItemTextLineLevelRequirement_6FAE41B0((Unicode *)scratchpad, levelRequirement);
                    itemLineLevelRequirement.append(scratchpad);
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_WEAPON)
                    || D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR))
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

                        D2Client_GetItemTextStrRequirement_6FAE4250((Unicode *)scratchpad, pItemsTxtRecord, strRequirement);
                        itemLineStrRequirement.append(scratchpad);
                    }
                    if (pItemsTxtRecord->wReqDex)
                    {
                        if (!bRequiresDex)
                        {
                            colorCode3 = 1;
                        }

                        D2Client_GetItemTextDexRequirement_6FAE4310((Unicode*)scratchpad, pItemsTxtRecord, dexRequirement);
                        itemLineDexRequirement.append(scratchpad);
                    }
                }
                ColorizeString(itemLineLevelRequirement, colorCode);
                itemLineBasicInfo.append(itemLineLevelRequirement);
                ColorizeString(itemLineStrRequirement, colorCode2);
                itemLineBasicInfo.append(itemLineStrRequirement);
                ColorizeString(itemLineDexRequirement, colorCode3);
                itemLineBasicInfo.append(itemLineDexRequirement);
                auto v99 = ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor);
                if (v99 != PCLASS_EVILFORCE)
                {
                    std::wstring itemLineUnknownB;

                    auto v101 = (wchar_t*)D2LANG_GetStringFromTblIndex(v99 + 10917);
                    itemLineUnknownB.append(v101);
                    itemLineUnknownB.append(v235);
                    if (pUnit_ && !pUnit_->dwUnitType && pUnit_->dwClassId != v99)
                    {
                        colorCode245 = 1;
                    }

                    ColorizeString(itemLineUnknownB, colorCode245);
                    itemLineBasicInfo.append(itemLineUnknownB);
                }
                ColorizeString(itemLineDurability, 0);
                itemLineBasicInfo.append(itemLineDurability);

                if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_WEAPON))
                {
                    D2Client_GetItemTextLineAttackSpeed_6FAE5570(pItemUnderCursor, (Unicode *)scratchpad, pItemsTxtRecord);
                    AppendColorizedString(itemLineBasicInfo, scratchpad, 0);

                    if (STATLIST_GetMinDamageFromUnit(pItemUnderCursor, 0) >= 0
                        && STATLIST_GetMaxDamageFromUnit(pItemUnderCursor, 0) >= 0)
                    {
                        D2Client_GetItemTextLineDamage_6FAE43D0(pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                        AppendColorizedString(itemLineBasicInfo, scratchpad, 0);
                    }
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_SHIELD))
                {
                    if (pUnit_
                        && !pUnit_->dwUnitType
                        && pUnit_->dwClassId == 3
                        && (!ITEMS_IsClassValid(pItemUnderCursor)
                            || ITEMS_GetClassOfClassSpecificItem(pItemUnderCursor) == PCLASS_PALADIN))
                    {

                        D2Client_GetItemTextLineUnknownA_6FAE5040(pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                        AppendColorizedString(itemLineBasicInfo, scratchpad, 0);
                    }

                    D2Client_GetItemTextLineBlockChance_6FAE4EE0(pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                    AppendColorizedString(itemLineBasicInfo, scratchpad, 0);
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(pItemUnderCursor, ITEMTYPE_ANY_ARMOR)
                    && STATLIST_GetDefenseFromUnit(pItemUnderCursor) > 0)
                {
                    // TODO: This is a shady call, investigate it
                    D2Client_GetItemTextLineDefense_6FAE51D0(pUnit_, pItemUnderCursor, (Unicode*)scratchpad, pItemsTxtRecord);
                    AppendColorizedString(itemLineBasicInfo, scratchpad, 0);
                }

                D2Client_BuildItemName_6FADD360(pItemUnderCursor, (Unicode *)scratchpad, std::size(scratchpad));
                auto isItemBroken = ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_BROKEN, __LINE__, __FILE__);
                AppendColorizedString(itemLineBasicInfo, scratchpad, isItemBroken ? 1 : 2);

                std::wstring textLineDetailsA;
                if (ITEMS_CheckItemFlag(pItemUnderCursor, IFLAG_SOCKETED, __LINE__, __FILE__))
                {
                    D2Client_GetItemTextSocketed_6FAE3EE0(pItemUnderCursor, (Unicode *)scratchpad);
                    textLineDetailsA.append(scratchpad);
                }

                scratchpad[0] = 0;
                D2Client_GetItemTextLineProperties_6FAF3160(pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad), 1, 0);
                textLineDetailsA.append(scratchpad);

                std::wstring textLineSet;
                D2Client_GetItemTextSet_6FAF32B0(pUnit_, pItemUnderCursor, (Unicode *)scratchpad, std::size(scratchpad));
                textLineSet.append(scratchpad);

                std::wstring textLineSetB;
                if (pItemUnderCursor && pItemUnderCursor->dwAnimMode == 1)
                {
                    D2Client_GetItemTextSetB_6FAF33C0(pUnit_, pItemUnderCursor, (Unicode*)scratchpad, std::size(scratchpad));
                }
               
                std::wstring scratchpadBuffer;
                if (v233->nSetItems > 0)
                {
                    for (int i = 0; i < v233->nSetItems; ++i)
                    {
                        auto pUnita = v233->pSetItem[i];

                        if (!pUnita->wSetItemId)
                        {
                            break;
                        }

                        auto v108 = D2Client_sub_6FAE5990(pItemMaybe->pInventory, pUnita->wSetItemId);
                        if (pUnita->wStringId)
                        {
                            auto v224 = D2LANG_GetStringFromTblIndex(pUnita->wStringId);
                            auto v111 = D2LANG_GetStringFromTblIndex(10089);
                            D2Client_sub_6FADCFE0((Unicode *)scratchpad, v111, v224);
                            scratchpadBuffer.append(scratchpad);
                            scratchpadBuffer.append(v235);
                        }
                        ColorizeString(scratchpadBuffer, v108 ? 2 : 1);
                        textLineDetailsA.append(scratchpadBuffer);
                    }
                }

                scratchpadBuffer.clear();
                ColorizeString(textLineDetailsA, 2);
                scratchpadBuffer.append(textLineDetailsA);
                ColorizeString(itemLineUnknownC, 4);
                scratchpadBuffer.append(itemLineUnknownC);
                if (textLineSetB[0])
                {
                    scratchpadBuffer.append(v235);
                    ColorizeString(textLineSetB, 4);
                    scratchpadBuffer.append(textLineSetB);
                }
                scratchpadBuffer.append(v235);
                if (textLineSet[0])
                {
                    ColorizeString(textLineSet, 2);
                    scratchpadBuffer.append(textLineSet);
                }
                ColorizeString(textLineDetailsA, 3);
                scratchpadBuffer.append(textLineDetailsA);
                scratchpadBuffer.append(itemLineBasicInfo);

                std::wstring pTextToDisplay;

                if (*D2Client_pDWORD_6FBB58EC && *D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
                {
                    int32_t hasSkillCharges = false;
                    scratchpad[0] = 0;
                    if (D2Client_GetItemTextPriceMaybe_6FAFB200(pItemUnderCursor, *D2Client_pDWORD_6FB7928C, &hasSkillCharges, (Unicode *)scratchpad, std::size(scratchpad)))
                    {
                        pTextToDisplay.append(scratchpadBuffer);
                        if (scratchpad[0])
                        {
                            pTextToDisplay.append(v235);
                        }

                        pTextToDisplay.append(scratchpad);
                    }
                    else
                    {
                        pTextToDisplay.append(scratchpadBuffer);
                        if (*D2Client_pDWORD_6FBB58EC != 4)
                        {
                            pTextToDisplay.append(v235);

                            auto v118 = (wchar_t*)D2LANG_GetStringFromTblIndex(3333);
                            std::wstring itemLinePriceMaybe(v118);
                            ColorizeString(itemLinePriceMaybe, 1);
                            pTextToDisplay.append(itemLinePriceMaybe);
                        }
                    }
                }
                else
                {
                    pTextToDisplay = scratchpadBuffer;
                }

                int32_t width = 0;
                int32_t height = 0;
                D2Win_10131_GetTextDimensions((const Unicode *)pTextToDisplay.c_str(), &width, &height);

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
