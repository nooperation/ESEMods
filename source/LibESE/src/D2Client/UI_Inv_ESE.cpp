#include <D2Client/CHARSCREENDMG_ESE.h>
#include <D2Common/D2Skills_ESE.h>
#include <DataTbls/SkillsIds.h>
#include <D2Common/Units/Missile_ESE.h>
#include "LibESE.h"
#include <D2Combat.h>
#include "Font.h"
#include <cinttypes>
#include <D2States.h>

void __fastcall ESE_UI_INV_DrawMouseOverItemFrame(D2UnitStrc* pItemMaybe, int32_t bFlag)
{
    Unicode itemDescriptionFullBuffer_2048[2048] = { 0 };
    auto strNewline_1 = D2LANG_GetStringFromTblIndex(3998);

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
                auto v53 = D2LANG_GetStringFromTblIndex(4144);
                D2Win_10129_DrawFramedText(v53, v52, v220, 0, 1);
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
            auto v59 = D2LANG_GetStringFromTblIndex(4144);
            D2Win_10129_DrawFramedText(v59, v58, v221, 0, 1);
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
            auto v66 = D2LANG_GetStringFromTblIndex(v64);
            D2Win_10129_DrawFramedText(v66, v65, v222, 0, 1);
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

        Unicode unknownFramedTextA[1024] = { 0 };
        auto v73 = 0;
        auto v71 = D2LANG_GetStringFromTblIndex(22726);
        Unicode::strcpy(unknownFramedTextA, v71);
        if (D2Client_sub_6FAD4B60(44, 1) == 0xFFFF)
        {
            if (D2Client_sub_6FAD4B60(44, 0) == 0xFFFF)
            {
                auto v76 = 368;
                if (D2Client_sub_6FB57BC0() > *D2Client_pDWORD_6FBBA748 + 500)
                {
                    v76 = 600;
                }

                D2Win_10129_DrawFramedText(unknownFramedTextA, v76 + *D2Client_pDWORD_6FBBA748, 21 - *D2Client_pDWORD_6FBBA74C, 0, 1);
                goto LABEL_97;
            }
            auto v74 = D2LANG_GetStringFromTblIndex(3997);
            Unicode::strcat(unknownFramedTextA, v74);
            v73 = 0;
        }
        else
        {
            auto v72 = D2LANG_GetStringFromTblIndex(3997);
            Unicode::strcat(unknownFramedTextA, v72);
            v73 = 1;
        }
        auto v75 = D2Client_sub_6FAD56B0(44, v73);
        Unicode::strcat(unknownFramedTextA, v75);
        auto v76 = 368;
        if (D2Client_sub_6FB57BC0() > *D2Client_pDWORD_6FBBA748 + 500)
        {
            v76 = 600;
        }

        D2Win_10129_DrawFramedText(unknownFramedTextA, v76 + *D2Client_pDWORD_6FBBA748, 21 - *D2Client_pDWORD_6FBBA74C, 0, 1);
    }
LABEL_97:
    if (!*D2Client_pDWORD_6FBB58E4 && !*D2Client_pDWORD_6FBB58E0)
    {
        return;
    }

    if (!D2Client_pItemUnderCursor_6FBB58F0)
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
        && D2Client_pItemUnderCursor_6FBB58F0
        && !INVENTORY_CompareWithItemsParentInventory(pItemMaybe->pInventory, D2Client_pItemUnderCursor_6FBB58F0))
    {
        return;
    }

    Unicode itemLineUnidentified[256] = { 0 };
    Unicode itemLineName[1024] = { 0 };
    if (*D2Client_pDWORD_6FBB58E0 && !*D2Client_pDWORD_6FB7928C && D2Client_sub_6FAFC130() && *D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
    {
        D2Client_BuildItemName_6FADD360(D2Client_pItemUnderCursor_6FBB58F0, itemLineName, 128);
        auto strUnidentified = D2LANG_GetStringFromTblIndex(3455);
        Unicode::strcpy(itemLineUnidentified, strUnidentified);
        Unicode::strcat(itemLineUnidentified, strNewline_1);
        Unicode::strcat(itemDescriptionFullBuffer_2048, itemLineUnidentified);

        int32_t v79 = 0;
        switch (ITEMS_GetItemType(D2Client_pItemUnderCursor_6FBB58F0))
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
            auto v80 = D2LANG_GetStringFromTblIndex(v79);
            Unicode::strcat(itemDescriptionFullBuffer_2048, v80);
            Unicode::strcat(itemDescriptionFullBuffer_2048, strNewline_1);
        }
        Unicode::strcat(itemDescriptionFullBuffer_2048, itemLineName);
        D2Client_ColorizeLine_6FB20430(itemDescriptionFullBuffer_2048, 0);

        Unicode itemDescriptionFinalBuffer2046[2046] = { 0 };
        D2Client_AddExtraTradeStatLines_6FAE5A40(itemDescriptionFullBuffer_2048, itemDescriptionFinalBuffer2046);

        int32_t nWidth = 0;
        int32_t nHeight = 0;
        D2Win_10131_GetTextDimensions(itemDescriptionFinalBuffer2046, &nWidth, &nHeight);

        if (*D2Client_pDWORD_6FB79294 - nHeight > 0)
        {
            D2Win_10129_DrawFramedText(itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 1);
            return;
        }
        auto v120 = (*D2Client_pDWORD_6FB7929C + nHeight);
        D2Win_10129_DrawFramedText(itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79298, v120, 0, 1);
        return;
    }
    auto itemQuality = ITEMS_GetItemQuality(D2Client_pItemUnderCursor_6FBB58F0);
    if (D2Client_sub_6FB57CC0() == 8 || ITEMS_GetTransmogrify(D2Client_pItemUnderCursor_6FBB58F0))
    {
        auto v209 = D2LANG_GetStringFromTblIndex(3998);
        if (!ITEMS_GetTransmogrify(D2Client_pItemUnderCursor_6FBB58F0))
        {
            return;
        }

        int32_t itemClassId = -1;
        if (D2Client_pItemUnderCursor_6FBB58F0)
        {
            itemClassId = D2Client_pItemUnderCursor_6FBB58F0->dwClassId;
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

        Unicode scratchpadBuffer[1024] = { 0 };

        auto v213 = D2LANG_GetStringFromTblIndex(5387);
        Unicode::strcpy(scratchpadBuffer, v213);
        auto v214 = D2LANG_GetStringFromTblIndex(ptNewItemStats->wNameStr);
        Unicode::strcpy(scratchpadBuffer, v214);
        Unicode::strcat(scratchpadBuffer, v209);
        auto v215 = D2LANG_GetStringFromTblIndex(5387);
        Unicode::strcat(scratchpadBuffer, v215);
        Unicode::strcat(scratchpadBuffer, v209);

        Unicode itemLineName[128] = { 0 };
        D2Client_BuildItemName_6FADD360(D2Client_pItemUnderCursor_6FBB58F0, itemLineName, 128);
        Unicode::strcat(scratchpadBuffer, itemLineName);

        Unicode finalFramedText[1022] = { 0 };
        if (*D2Client_pDWORD_6FBB58EC < 1 || *D2Client_pDWORD_6FBB58EC > 9)
        {
            Unicode::strcpy(finalFramedText, scratchpadBuffer);
        }
        else
        {
            D2Client_AddExtraTradeStatLines_6FAE5A40(scratchpadBuffer, finalFramedText);
        }

        int32_t height = 0;
        int32_t width = 0;
        D2Win_10131_GetTextDimensions(finalFramedText, &height, &width);

        if (*D2Client_pDWORD_6FB79294 - width > 0)
        {
            D2Win_10129_DrawFramedText(finalFramedText, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 0);
            return;
        }

        D2Win_10129_DrawFramedText(finalFramedText, *D2Client_pDWORD_6FB79298, width + *D2Client_pDWORD_6FB7929C, 0, 0);
        return;
    }
    if (itemQuality != 5 || !ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_IDENTIFIED, __LINE__, __FILE__))
    {
        int32_t colorCode = 0;
        int32_t colorCode2 = 0;
        int32_t colorCode3 = 0;
        int32_t colorCode245 = 0;

        if (ITEMS_GetItemType(D2Client_pItemUnderCursor_6FBB58F0) == ITEMTYPE_BOOK)
        {
            auto v126 = D2LANG_GetStringFromTblIndex(3998);
            if (!D2Client_pItemUnderCursor_6FBB58F0 || ITEMS_GetItemType(D2Client_pItemUnderCursor_6FBB58F0) != ITEMTYPE_BOOK)
            {
                FOG_DisplayAssert("sghSelItem && ITEMSGetType(sghSelItem) == ITEMTYPE_BOOK", __FILE__, __LINE__);
                exit(-1);
            }

            int32_t itemClassId = -1;
            if (D2Client_pItemUnderCursor_6FBB58F0)
            {
                itemClassId = D2Client_pItemUnderCursor_6FBB58F0->dwClassId;
            }

            auto pItemTxtRecord = DATATBLS_GetItemsTxtRecord(itemClassId);
            if (!pItemTxtRecord)
            {
                FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
                exit(-1);
            }

            Unicode scratchpadBuffer[1024] = { 0 };
            D2Client_sub_6FAE54B0(D2Client_pItemUnderCursor_6FBB58F0, scratchpadBuffer, pItemTxtRecord);
            if (!*D2Client_pDWORD_6FBB58EC)
            {
                auto v129 = D2LANG_GetStringFromTblIndex(2203);
                Unicode::strcat(scratchpadBuffer, v129);
                Unicode::strcat(scratchpadBuffer, v126);
                auto v130 = D2LANG_GetStringFromTblIndex(2206);
                Unicode::strcat(scratchpadBuffer, v130);
                Unicode::strcat(scratchpadBuffer, v126);
            }

            Unicode itemLineName[128] = { 0 };
            D2Client_BuildItemName_6FADD360(D2Client_pItemUnderCursor_6FBB58F0, itemLineName, 128);
            Unicode::strcat(scratchpadBuffer, itemLineName);

            Unicode finalFramedText[1022] = { 0 };
            if (*D2Client_pDWORD_6FBB58EC < 1 || *D2Client_pDWORD_6FBB58EC > 9)
            {
                Unicode::strcpy(finalFramedText, scratchpadBuffer);
            }
            else
            {
                D2Client_AddExtraTradeStatLines_6FAE5A40(scratchpadBuffer, finalFramedText);
            }

            int32_t height = 0;
            int32_t width = 0;
            D2Win_10131_GetTextDimensions(finalFramedText, &width, &height);

            if (*D2Client_pDWORD_6FB79294 - height > 0)
            {
                D2Win_10129_DrawFramedText(finalFramedText, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 0);
                return;
            }

            auto v120 = height + *D2Client_pDWORD_6FB7929C;
            D2Win_10129_DrawFramedText(finalFramedText, *D2Client_pDWORD_6FB79298, v120, 0, 0);
            return;
        }

        Unicode statLine_ClassRestriction_512[256] = { 0 };
        auto v132 = ITEMS_GetClassOfClassSpecificItem(D2Client_pItemUnderCursor_6FBB58F0);
        if (v132 != PCLASS_EVILFORCE)
        {
            auto v134 = D2LANG_GetStringFromTblIndex(v132 + 10917);
            Unicode::strcat(statLine_ClassRestriction_512, v134);
            Unicode::strcat(statLine_ClassRestriction_512, strNewline_1);
            auto v135 = v229 ? v229->dwClassId : -1;

            if (v135 != v132)
            {
                colorCode = 1;
            }
        }

        int32_t dwClassId_1 = -1;
        if (D2Client_pItemUnderCursor_6FBB58F0)
        {
            dwClassId_1 = D2Client_pItemUnderCursor_6FBB58F0->dwClassId;
        }

        auto itemTxtRecord = DATATBLS_GetItemsTxtRecord(dwClassId_1);
        if (!itemTxtRecord)
        {
            FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
            exit(-1);
        }

        Unicode statLine_Durability_512[256] = { 0 };
        if (ITEMS_GetQuiverType(D2Client_pItemUnderCursor_6FBB58F0))
        {
            auto strSpace2 = D2LANG_GetStringFromTblIndex(3995);
            auto strNewline2 = D2LANG_GetStringFromTblIndex(3998);
            if (STATLIST_UnitGetStatValue(D2Client_pItemUnderCursor_6FBB58F0, STAT_QUANTITY, 0) > 0)
            {
                auto v143 = D2LANG_GetStringFromTblIndex(3462);
                Unicode::strcpy(itemDescriptionFullBuffer_2048, v143);
                auto itemQuantity = STATLIST_UnitGetStatValue(D2Client_pItemUnderCursor_6FBB58F0, STAT_QUANTITY, 0);

                Unicode toUnicodeScratchpad[32] = { 0 };
                swprintf((wchar_t*)&toUnicodeScratchpad[0], L"%ld", itemQuantity);

                Unicode::strcat(itemDescriptionFullBuffer_2048, strSpace2);
                Unicode::strcat(itemDescriptionFullBuffer_2048, toUnicodeScratchpad);
                Unicode::strcat(itemDescriptionFullBuffer_2048, strNewline2);
                auto v145 = D2LANG_GetStringFromTblIndex(itemTxtRecord->wNameStr);
                Unicode::strcat(itemDescriptionFullBuffer_2048, v145);
            }
        }
        else
        {
            D2Client_GetItemTextLineDurability_6FAE4060(D2Client_pItemUnderCursor_6FBB58F0, statLine_Durability_512, itemTxtRecord);
        }

        BOOL bRequiresDex = false;
        BOOL bRequiresStr = false;
        BOOL bRequiresLevel = false;

        Unicode statLine_RequiredLevel512[256] = { 0 };
        ITEMS_CheckRequirements(D2Client_pItemUnderCursor_6FBB58F0, v229, 0, &bRequiresStr, &bRequiresDex, &bRequiresLevel);
        if (ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_IDENTIFIED, __LINE__, __FILE__))
        {
            auto levelRequirement = ITEMS_GetLevelRequirement(D2Client_pItemUnderCursor_6FBB58F0, v229);
            if (levelRequirement > 1)
            {
                if (!bRequiresLevel)
                {
                    colorCode245 = 1;
                }

                auto strSpace = D2LANG_GetStringFromTblIndex(3995);
                auto strNewline = D2LANG_GetStringFromTblIndex(3998);
                auto strRequiredLevel = D2LANG_GetStringFromTblIndex(3469);
                Unicode::strcpy(statLine_RequiredLevel512, strRequiredLevel);

                Unicode toUnicodeScratchpad[32] = { 0 };
                swprintf((wchar_t*)&toUnicodeScratchpad[0], L"%i", levelRequirement);

                Unicode::strcat(statLine_RequiredLevel512, strSpace);
                Unicode::strcat(statLine_RequiredLevel512, toUnicodeScratchpad);
                Unicode::strcat(statLine_RequiredLevel512, strNewline);
            }
        }

        Unicode statLine_RuneGemStats_512[256] = { 0 };
        if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_SOCKET_FILLER))
        {
            auto v152 = D2LANG_GetStringFromTblIndex(3998);
            if (!D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_SOCKET_FILLER))
            {
                FOG_DisplayAssert("ITEMSIsA(sghSelItem, ITEMTYPE_SOCKETFILLER_TYPE)", __FILE__, __LINE__);
                exit(-1);
            }
            D2Client_GetItemTextLineRuneGemStats_6FAF1480(D2Client_pItemUnderCursor_6FBB58F0, statLine_RuneGemStats_512, 512);
            auto v153 = D2LANG_GetStringFromTblIndex(11080);
            Unicode::strcat(statLine_RuneGemStats_512, v153);
            Unicode::strcat(statLine_RuneGemStats_512, v152);
        }

        Unicode statLine_RunewordName_512[256] = { 0 };
        if (ITEMS_CheckIfSocketable(D2Client_pItemUnderCursor_6FBB58F0))
        {
            if (D2Client_pItemUnderCursor_6FBB58F0->pInventory)
            {
                auto v241 = D2LANG_GetStringFromTblIndex(3998);
                auto v157 = INVENTORY_GetFirstItem(D2Client_pItemUnderCursor_6FBB58F0->pInventory);
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
                                        auto v163 = D2LANG_GetStringFromTblIndex(20506);
                                        Unicode::strcat(statLine_RunewordName_512, v163);
                                    }

                                    Unicode letterScratchpad[16] = { 0 };
                                    Unicode::toUnicode(letterScratchpad, v162->szLetter, 6);
                                    Unicode::strcat(statLine_RunewordName_512, letterScratchpad);
                                }
                            }
                        }
                        v157 = INVENTORY_GetNextItem(v157);
                    } while (v157);
                    if (v158)
                    {
                        Unicode toUnicodeScratchpad[16] = { 0 };
                        Unicode::toUnicode(toUnicodeScratchpad, "'", 5);
                        Unicode::strcat(statLine_RunewordName_512, toUnicodeScratchpad);
                        Unicode::strcat(statLine_RunewordName_512, v241);
                    }
                }
            }
        }

        Unicode statLine_CharmKeepInInv_512[256] = { 0 };
        if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_CHARM))
        {
            auto v164 = D2LANG_GetStringFromTblIndex(3998);
            auto v165 = D2LANG_GetStringFromTblIndex(20438);
            Unicode::strcat(statLine_CharmKeepInInv_512, v165);
            Unicode::strcat(statLine_CharmKeepInInv_512, v164);
        }

        Unicode statLine_Socketed_512[256] = { 0 };
        Unicode statLine_RequiredDexterity_256[256] = { 0 };
        Unicode statLine_RequiredStength_256[256] = { 0 };
        Unicode statLine_Damage_512[256] = { 0 };
        Unicode statLine_AttackSpeed_2048[1024] = { 0 };
        Unicode statLine_blockChance_512[256] = { 0 };
        Unicode statLine_v273_512[256] = { 0 };
        Unicode statLine_Defense_512[256] = { 0 };

        if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_WEAPON)
            || D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_ANY_ARMOR))
        {
            D2Client_GetItemTextSocketed_6FAE3EE0(D2Client_pItemUnderCursor_6FBB58F0, statLine_Socketed_512);
            auto v166 = 0;
            auto v167 = 0;
            auto v168 = STATLIST_UnitGetItemStatOrSkillStatValue(D2Client_pItemUnderCursor_6FBB58F0, STAT_ITEM_REQ_PERCENT, 0);

            if (v168)
            {
                v167 = DATATBLS_ApplyRatio(v168, itemTxtRecord->wReqStr, 100);
                v166 = DATATBLS_ApplyRatio(v168, itemTxtRecord->wReqDex, 100);
            }

            if (ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_ETHEREAL, __LINE__, __FILE__))
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

                auto v237 = D2LANG_GetStringFromTblIndex(3995);
                auto v241 = D2LANG_GetStringFromTblIndex(3998);
                auto v171 = v166 + itemTxtRecord->wReqDex;
                if (v171 > 0)
                {
                    auto v172 = D2LANG_GetStringFromTblIndex(3459);
                    Unicode::strcpy(statLine_RequiredDexterity_256, v172);

                    Unicode toUnicodeScratchpad[32] = { 0 };
                    swprintf((wchar_t*)&toUnicodeScratchpad[0], L"%i", v171);

                    Unicode::strcat(statLine_RequiredDexterity_256, v237);
                    Unicode::strcat(statLine_RequiredDexterity_256, toUnicodeScratchpad);
                    Unicode::strcat(statLine_RequiredDexterity_256, v241);
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

                auto v174 = D2LANG_GetStringFromTblIndex(3995);
                auto v238 = D2LANG_GetStringFromTblIndex(3998);
                auto v175 = v167 + itemTxtRecord->wReqStr;
                if (v175 > 0)
                {
                    auto v176 = D2LANG_GetStringFromTblIndex(3458);
                    Unicode::strcpy(statLine_RequiredStength_256, v176);

                    Unicode toUnicodeScratchpad[32] = { 0 };
                    swprintf((wchar_t*)&toUnicodeScratchpad[0], L"%i", v175);

                    Unicode::strcat(statLine_RequiredStength_256, v174);
                    Unicode::strcat(statLine_RequiredStength_256, toUnicodeScratchpad);
                    Unicode::strcat(statLine_RequiredStength_256, v238);
                }
                else
                {
                    statLine_RequiredStength_256[0] = 0;
                }
            }


            if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_WEAPON))
            {
                if (STATLIST_GetMinDamageFromUnit(D2Client_pItemUnderCursor_6FBB58F0, 0) >= 0
                    && STATLIST_GetMaxDamageFromUnit(D2Client_pItemUnderCursor_6FBB58F0, 0) >= 0)
                {
                    D2Client_GetItemTextLineDamage_6FAE43D0(D2Client_pItemUnderCursor_6FBB58F0, statLine_Damage_512, itemTxtRecord);
                }
                D2Client_GetItemTextLineAttackSpeed_6FAE5570(D2Client_pItemUnderCursor_6FBB58F0, statLine_AttackSpeed_2048, itemTxtRecord);
            }
            if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_ANY_SHIELD))
            {
                if (v229
                    && v229->dwClassId == 3
                    && (!ITEMS_IsClassValid(D2Client_pItemUnderCursor_6FBB58F0)
                        || ITEMS_GetClassOfClassSpecificItem(D2Client_pItemUnderCursor_6FBB58F0) == PCLASS_PALADIN))
                {
                    D2Client_GetItemTextLineUnknownA_6FAE5040(D2Client_pItemUnderCursor_6FBB58F0, statLine_v273_512, itemTxtRecord);
                }
                D2Client_GetItemTextLineBlockChance_6FAE4EE0(D2Client_pItemUnderCursor_6FBB58F0, statLine_blockChance_512, itemTxtRecord);
            }
            else if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_BOOTS) && v229 && v229->dwClassId == 6)
            {
                D2Client_GetItemTextLineUnknownA_6FAE5040(D2Client_pItemUnderCursor_6FBB58F0, statLine_v273_512, itemTxtRecord);
            }
            if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_ANY_ARMOR)
                && STATLIST_GetDefenseFromUnit(D2Client_pItemUnderCursor_6FBB58F0) > 0)
            {
                // TODO: This is a shady call, investigate it
                D2Client_GetItemTextLineDefense_6FAE51D0(v229, D2Client_pItemUnderCursor_6FBB58F0, statLine_Defense_512, itemTxtRecord);
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
            if (ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_SOCKETED, __LINE__, __FILE__)
                || ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_ETHEREAL, __LINE__, __FILE__))
            {
                colorCode_Name = 5;
            }
            break;
        }
        if (!ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_IDENTIFIED, __LINE__, __FILE__)
            && *D2Client_pDWORD_6FBB58EC >= 1
            && *D2Client_pDWORD_6FBB58EC <= 9
            && !*D2Client_pDWORD_6FB7928C)
        {
            colorCode_Name = 0;
        }

        Unicode statLine_Quantity_512[256] = { 0 };
        Unicode statLine_Stats_8192[4096] = { 0 };

        if (ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_IDENTIFIED, __LINE__, __FILE__))
        {
            if (!ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_SOCKETED, __LINE__, __FILE__))
            {
                auto v177 = D2Client_pItemUnderCursor_6FBB58F0;
                auto v178 = D2LANG_GetStringFromTblIndex(3995);
                auto v179 = D2LANG_GetStringFromTblIndex(3998);
                if (STATLIST_UnitGetStatValue(v177, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(v177) > 0)
                {
                    auto v180 = D2LANG_GetStringFromTblIndex(3462);
                    Unicode::strcpy(statLine_Quantity_512, v180);
                    auto v181 = STATLIST_UnitGetStatValue(v177, STAT_QUANTITY, 0);

                    Unicode toUnicodeScratchpad[32] = { 0 };
                    swprintf((wchar_t*)&toUnicodeScratchpad[0], L"%i", v181);

                    Unicode::strcat(statLine_Quantity_512, v178);
                    Unicode::strcat(statLine_Quantity_512, toUnicodeScratchpad);
                    Unicode::strcat(statLine_Quantity_512, v179);
                }
            }
            D2Client_GetItemTextLineProperties_6FAF3160(D2Client_pItemUnderCursor_6FBB58F0, statLine_Stats_8192, std::size(statLine_Stats_8192), 1, 0);
        }
        else
        {
            auto v184 = D2LANG_GetStringFromTblIndex(3455);
            Unicode::strcpy(itemLineUnidentified, v184);
            Unicode::strcat(itemLineUnidentified, strNewline_1);
        }

        D2Client_GetItemTextLineQuantity_6FAE5710(D2Client_pItemUnderCursor_6FBB58F0, statLine_Quantity_512, itemTxtRecord);
        D2Client_BuildItemName_6FADD360(D2Client_pItemUnderCursor_6FBB58F0, itemLineName, 256);
        auto colored_statLine_Socketed_512 = D2Client_ColorizeLine_6FB20430(statLine_Socketed_512, 3);
        Unicode::strcpy(itemDescriptionFullBuffer_2048, colored_statLine_Socketed_512);
        auto colored_statLine_Stats_8192 = D2Client_ColorizeLine_6FB20430(statLine_Stats_8192, 3);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_Stats_8192);
        auto colored_itemLineUnidentified = D2Client_ColorizeLine_6FB20430(itemLineUnidentified, 1);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_itemLineUnidentified);
        auto colored_statLine_AttackSpeed_2048 = D2Client_ColorizeLine_6FB20430(statLine_AttackSpeed_2048, 0);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_AttackSpeed_2048);
        auto colored_statLine_RequiredLevel_512 = D2Client_ColorizeLine_6FB20430(statLine_RequiredLevel512, colorCode245);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_RequiredLevel_512);
        auto colored_statLine_RequiredStength_256 = D2Client_ColorizeLine_6FB20430(statLine_RequiredStength_256, colorCode3);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_RequiredStength_256);
        auto colored_statLine_RequiredDexterity_256 = D2Client_ColorizeLine_6FB20430(statLine_RequiredDexterity_256, colorCode2);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_RequiredDexterity_256);
        auto colored_statLine_ClassRestriction_512 = D2Client_ColorizeLine_6FB20430(statLine_ClassRestriction_512, colorCode);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_ClassRestriction_512);
        auto colored_statLine_Durability_512 = D2Client_ColorizeLine_6FB20430(statLine_Durability_512, 0);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_Durability_512);
        auto colored_statLine_RuneGemStats_512 = D2Client_ColorizeLine_6FB20430(statLine_RuneGemStats_512, 0);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_RuneGemStats_512);
        auto colored_statLine_CharmKeepInInv_512 = D2Client_ColorizeLine_6FB20430(statLine_CharmKeepInInv_512, 0);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_CharmKeepInInv_512);
        auto colored_statLine_Quantity_512 = D2Client_ColorizeLine_6FB20430(statLine_Quantity_512, 0);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_Quantity_512);
        auto colored_statLine_Damage_512 = D2Client_ColorizeLine_6FB20430(statLine_Damage_512, 0);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_Damage_512);
        auto colored_statLine_v273_512 = D2Client_ColorizeLine_6FB20430(statLine_v273_512, 0);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_v273_512);
        auto colored_statLine_blockChance_512 = D2Client_ColorizeLine_6FB20430(statLine_blockChance_512, 0);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_blockChance_512);
        auto colored_statLine_Defense_512 = D2Client_ColorizeLine_6FB20430(statLine_Defense_512, 0);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_Defense_512);
        auto colored_statLine_RunewordName_512 = D2Client_ColorizeLine_6FB20430(statLine_RunewordName_512, 4);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_statLine_RunewordName_512);

        if (ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_BROKEN, __LINE__, __FILE__))
        {
            colorCode_Name = 1;
        }

        auto colored_itemLineName = D2Client_ColorizeLine_6FB20430(itemLineName, colorCode_Name);
        Unicode::strcat(itemDescriptionFullBuffer_2048, colored_itemLineName);

        Unicode itemDescriptionFinalBuffer2046[2046] = { 0 };
        if (*D2Client_pDWORD_6FBB58EC && *D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
        {
            D2Client_AddExtraTradeStatLines_6FAE5A40(itemDescriptionFullBuffer_2048, itemDescriptionFinalBuffer2046);
        }
        else
        {
            Unicode::strcpy(itemDescriptionFinalBuffer2046, itemDescriptionFullBuffer_2048);
        }

        if (!itemTxtRecord->nQuest || itemTxtRecord->dwCode == 543647084)
        {
            if (Unicode::strlen(itemDescriptionFinalBuffer2046) >= 1023u)
            {
                // This is injecting a null terminator somewhere. I'm just going to assume itemDescriptionFinalBuffer
                itemDescriptionFinalBuffer2046[std::size(itemDescriptionFinalBuffer2046) - 1] = 0; 
            }

            int32_t nWidth = 0;
            int32_t nHeight = 0;
            D2Win_10131_GetTextDimensions(itemDescriptionFinalBuffer2046, &nWidth, &nHeight);
            if (*D2Client_pDWORD_6FB79294 - nHeight > 0)
            {
                D2Win_10129_DrawFramedText(itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 1);
                return;
            }

            D2Win_10129_DrawFramedText(itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79298, (*D2Client_pDWORD_6FB7929C + nHeight), 0, 1);
            return;
        }

        if (!*D2Client_pDWORD_6FBB58EC && (!D2Client_pItemUnderCursor_6FBB58F0 || !D2Client_pItemUnderCursor_6FBB58F0->dwAnimMode))
        {
            if (itemTxtRecord->dwCode == 543452002)
            {
                Unicode::strcpy(itemDescriptionFullBuffer_2048, itemDescriptionFinalBuffer2046);
                auto v205 = D2LANG_GetStringFromTblIndex(2205);
                Unicode::strcpy(itemDescriptionFinalBuffer2046, v205);
                Unicode::strcat(itemDescriptionFinalBuffer2046, strNewline_1);
                Unicode::strcat(itemDescriptionFinalBuffer2046, itemDescriptionFullBuffer_2048);
                goto LABEL_366;
            }
            if (itemTxtRecord->dwCode == 544763746)
            {
                Unicode::strcpy(itemDescriptionFullBuffer_2048, itemDescriptionFinalBuffer2046);
                auto v205 = D2LANG_GetStringFromTblIndex(2204);
                Unicode::strcpy(itemDescriptionFinalBuffer2046, v205);
                Unicode::strcat(itemDescriptionFinalBuffer2046, strNewline_1);
                Unicode::strcat(itemDescriptionFinalBuffer2046, itemDescriptionFullBuffer_2048);
                goto LABEL_366;
            }
        }
    LABEL_366:
        D2Client_ColorizeLine_6FB20430(itemDescriptionFinalBuffer2046, 4);
        if (Unicode::strlen(itemDescriptionFinalBuffer2046) >= 1023u)
        {
            // This is injecting a null terminator somewhere. I'm just going to assume itemDescriptionFinalBuffer
            itemDescriptionFinalBuffer2046[std::size(itemDescriptionFinalBuffer2046) - 1] = 0;
        }

        int32_t nWidth = 0;
        int32_t nHeight = 0;
        D2Win_10131_GetTextDimensions(itemDescriptionFinalBuffer2046, &nWidth, &nHeight);
        if (*D2Client_pDWORD_6FB79294 - nHeight > 0)
        {
            D2Win_10129_DrawFramedText(itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 4, 1);
            return;
        }

        D2Win_10129_DrawFramedText(itemDescriptionFinalBuffer2046, *D2Client_pDWORD_6FB79298, (*D2Client_pDWORD_6FB7929C + nHeight), 4, 1);
        return;
    }

    int32_t colorCode = 0;
    int32_t colorCode2 = 0;
    int32_t colorCode3 = 0;
    int32_t colorCode245 = 0;

    auto v235 = D2LANG_GetStringFromTblIndex(3998);

    auto pUnit_ = pItemMaybe;
    if (pItemMaybe->dwUnitType == 1 && !MONSTERS_GetHirelingTypeId(pItemMaybe))
    {
        pUnit_ = D2Client_sub_6FB283D0();
    }

    if ((*D2Client_pDWORD_6FBB58E4 || *D2Client_pDWORD_6FBB58E0)
        && D2Client_pItemUnderCursor_6FBB58F0
        && !INVENTORY_GetCursorItem(pItemMaybe->pInventory))
    {
        int32_t dwClassId = -1;
        if (D2Client_pItemUnderCursor_6FBB58F0)
        {
            dwClassId = D2Client_pItemUnderCursor_6FBB58F0->dwClassId;
        }

        auto pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(dwClassId);
        if (!pItemsTxtRecord)
        {
            FOG_DisplayAssert("ptItemStats", __FILE__, __LINE__);
            exit(-1);
        }
        auto itemFileIndex = ITEMS_GetFileIndex(D2Client_pItemUnderCursor_6FBB58F0);
        auto v90 = D2Client_GetSetItemsTxt_6FAE5C80(itemFileIndex);
        if (v90)
        {
            auto v233 = D2Client_sub_6FAE5C50(v90->nSetId);
            if (v233)
            {

                Unicode itemLineUnknownC[512] = { 0 };
                Unicode itemLineBasicInfo[1024] = { 0 };
                Unicode itemLineLevelRequirement[256] = { 0 };
                Unicode itemLineDurability[256] = { 0 };
                Unicode itemLineStrRequirement[256] = { 0 };
                Unicode itemLineDexRequirement[256] = { 0 };

                auto v92 = D2LANG_GetStringFromTblIndex(v233->wStringId);
                Unicode::strcpy(itemLineUnknownC, v92);
                Unicode::strcat(itemLineUnknownC, v235);


                BOOL bRequiresStr = false;
                BOOL bRequiresDex = false;
                BOOL bRequiresLevel = false;
                ITEMS_CheckRequirements(D2Client_pItemUnderCursor_6FBB58F0, pUnit_, 0, &bRequiresStr, &bRequiresDex, &bRequiresLevel);
                D2Client_GetItemTextLineDurability_6FAE4060(D2Client_pItemUnderCursor_6FBB58F0, itemLineDurability, pItemsTxtRecord);
                auto levelRequirement = ITEMS_GetLevelRequirement(D2Client_pItemUnderCursor_6FBB58F0, pUnit_);
                if (levelRequirement > 1)
                {
                    if (!bRequiresLevel)
                    {
                        colorCode = 1;
                    }

                    D2Client_GetItemTextLineLevelRequirement_6FAE41B0(itemLineLevelRequirement, levelRequirement);
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_WEAPON)
                    || D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_ANY_ARMOR))
                {
                    int32_t strRequirement = 0;
                    int32_t dexRequirement = 0;

                    auto itemReqPercent = STATLIST_UnitGetItemStatOrSkillStatValue(D2Client_pItemUnderCursor_6FBB58F0, STAT_ITEM_REQ_PERCENT, 0);
                    if (itemReqPercent)
                    {
                        strRequirement = DATATBLS_ApplyRatio(itemReqPercent, pItemsTxtRecord->wReqStr, 100);
                        dexRequirement = DATATBLS_ApplyRatio(itemReqPercent, pItemsTxtRecord->wReqDex, 100);
                    }
                    if (ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_ETHEREAL, __LINE__, __FILE__))
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

                        D2Client_GetItemTextStrRequirement_6FAE4250(itemLineStrRequirement, pItemsTxtRecord, strRequirement);
                    }
                    if (pItemsTxtRecord->wReqDex)
                    {
                        if (!bRequiresDex)
                        {
                            colorCode3 = 1;
                        }

                        D2Client_GetItemTextDexRequirement_6FAE4310(itemLineDexRequirement, pItemsTxtRecord, dexRequirement);
                    }
                }
                auto v96 = D2Client_ColorizeLine_6FB20430(itemLineLevelRequirement, colorCode);
                Unicode::strcpy(itemLineBasicInfo, v96);
                auto v97 = D2Client_ColorizeLine_6FB20430(itemLineStrRequirement, colorCode2);
                Unicode::strcat(itemLineBasicInfo, v97);
                auto v98 = D2Client_ColorizeLine_6FB20430(itemLineDexRequirement, colorCode3);
                Unicode::strcat(itemLineBasicInfo, v98);
                auto v99 = ITEMS_GetClassOfClassSpecificItem(D2Client_pItemUnderCursor_6FBB58F0);
                if (v99 != PCLASS_EVILFORCE)
                {
                    Unicode itemLineUnknownB[256] = { 0 };

                    auto v101 = D2LANG_GetStringFromTblIndex(v99 + 10917);
                    Unicode::strcat(itemLineUnknownB, v101);
                    Unicode::strcat(itemLineUnknownB, v235);
                    if (pUnit_ && !pUnit_->dwUnitType && pUnit_->dwClassId != v99)
                    {
                        colorCode245 = 1;
                    }

                    auto v102 = D2Client_ColorizeLine_6FB20430(itemLineUnknownB, colorCode245);
                    Unicode::strcat(itemLineBasicInfo, v102);
                }
                auto v103 = D2Client_ColorizeLine_6FB20430(itemLineDurability, 0);
                Unicode::strcat(itemLineBasicInfo, v103);
                if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_WEAPON))
                {
                    Unicode textLineAttackSpeed[256] = { 0 };
                    D2Client_GetItemTextLineAttackSpeed_6FAE5570(D2Client_pItemUnderCursor_6FBB58F0, textLineAttackSpeed, pItemsTxtRecord);
                    D2Client_ColorizeLine_6FB20430(textLineAttackSpeed, 0);
                    Unicode::strcat(itemLineBasicInfo, textLineAttackSpeed);

                    if (STATLIST_GetMinDamageFromUnit(D2Client_pItemUnderCursor_6FBB58F0, 0) >= 0
                        && STATLIST_GetMaxDamageFromUnit(D2Client_pItemUnderCursor_6FBB58F0, 0) >= 0)
                    {
                        Unicode textLineDamage[256] = { 0 };
                        D2Client_GetItemTextLineDamage_6FAE43D0(D2Client_pItemUnderCursor_6FBB58F0, textLineDamage, pItemsTxtRecord);
                        D2Client_ColorizeLine_6FB20430(textLineDamage, 0);
                        Unicode::strcat(itemLineBasicInfo, textLineDamage);
                    }
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_ANY_SHIELD))
                {
                    if (pUnit_
                        && !pUnit_->dwUnitType
                        && pUnit_->dwClassId == 3
                        && (!ITEMS_IsClassValid(D2Client_pItemUnderCursor_6FBB58F0)
                            || ITEMS_GetClassOfClassSpecificItem(D2Client_pItemUnderCursor_6FBB58F0) == PCLASS_PALADIN))
                    {

                        Unicode textLinePaladinShield[256] = { 0 };
                        D2Client_GetItemTextLineUnknownA_6FAE5040(D2Client_pItemUnderCursor_6FBB58F0, textLinePaladinShield, pItemsTxtRecord);
                        D2Client_ColorizeLine_6FB20430(textLinePaladinShield, 0);
                        Unicode::strcat(itemLineBasicInfo, textLinePaladinShield);
                    }

                    Unicode textLineBlockChance[256] = { 0 };
                    D2Client_GetItemTextLineBlockChance_6FAE4EE0(D2Client_pItemUnderCursor_6FBB58F0, textLineBlockChance, pItemsTxtRecord);
                    D2Client_ColorizeLine_6FB20430(textLineBlockChance, 0);
                    Unicode::strcat(itemLineBasicInfo, textLineBlockChance);
                }
                if (D2Common_10731_ITEMS_CheckItemTypeId(D2Client_pItemUnderCursor_6FBB58F0, ITEMTYPE_ANY_ARMOR)
                    && STATLIST_GetDefenseFromUnit(D2Client_pItemUnderCursor_6FBB58F0) > 0)
                {
                    Unicode textLineDefense[256] = { 0 };
                    // TODO: This is a shady call, investigate it
                    D2Client_GetItemTextLineDefense_6FAE51D0(pUnit_, D2Client_pItemUnderCursor_6FBB58F0, textLineDefense, pItemsTxtRecord);
                    D2Client_ColorizeLine_6FB20430(textLineDefense, 0);
                    Unicode::strcat(itemLineBasicInfo, textLineDefense);
                }

                Unicode textLineName[256] = { 0 };
                D2Client_BuildItemName_6FADD360(D2Client_pItemUnderCursor_6FBB58F0, textLineName, std::size(textLineName));
                auto isItemBroken = ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_BROKEN, __LINE__, __FILE__);
                D2Client_ColorizeLine_6FB20430(textLineName, isItemBroken ? 1 : 2);
                Unicode::strcat(itemLineBasicInfo, textLineName);

                Unicode textLineDetailsA[1024] = { 0 };
                if (ITEMS_CheckItemFlag(D2Client_pItemUnderCursor_6FBB58F0, IFLAG_SOCKETED, __LINE__, __FILE__))
                {
                    Unicode textLineSocketed[512] = { 0 };
                    D2Client_GetItemTextSocketed_6FAE3EE0(D2Client_pItemUnderCursor_6FBB58F0, textLineSocketed);
                    Unicode::strcpy(textLineDetailsA, textLineSocketed);
                }

                D2Client_GetItemTextLineProperties_6FAF3160(D2Client_pItemUnderCursor_6FBB58F0, textLineDetailsA, std::size(textLineDetailsA), 1, 0);

                Unicode textLineSet[512] = { 0 };
                D2Client_GetItemTextSet_6FAF32B0(pUnit_, D2Client_pItemUnderCursor_6FBB58F0, textLineSet, 512);

                Unicode textLineSetB[512] = { 0 };
                if (D2Client_pItemUnderCursor_6FBB58F0 && D2Client_pItemUnderCursor_6FBB58F0->dwAnimMode == 1)
                {
                    D2Client_GetItemTextSetB_6FAF33C0(pUnit_, D2Client_pItemUnderCursor_6FBB58F0, textLineSetB, 512);
                }
               
                Unicode scratchpadBuffer[1024] = { 0 };
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
                            D2Client_sub_6FADCFE0(scratchpadBuffer, v111, v224);
                            Unicode::strcat(scratchpadBuffer, v235);
                        }
                        D2Client_ColorizeLine_6FB20430(scratchpadBuffer, v108 ? 2 : 1);
                        Unicode::strcat(textLineDetailsA, scratchpadBuffer);
                    }
                }

                auto v113 = D2Client_ColorizeLine_6FB20430(textLineDetailsA, 2);
                Unicode::strcpy(scratchpadBuffer, v113);
                auto v114 = D2Client_ColorizeLine_6FB20430(itemLineUnknownC, 4);
                Unicode::strcat(scratchpadBuffer, v114);
                if (textLineSetB[0])
                {
                    Unicode::strcat(scratchpadBuffer, v235);
                    auto v115 = D2Client_ColorizeLine_6FB20430(textLineSetB, 4);
                    Unicode::strcat(scratchpadBuffer, v115);
                }
                Unicode::strcat(scratchpadBuffer, v235);
                if (textLineSet[0])
                {
                    auto v116 = D2Client_ColorizeLine_6FB20430(textLineSet, 2);
                    Unicode::strcat(scratchpadBuffer, v116);
                }
                auto v117 = D2Client_ColorizeLine_6FB20430(textLineDetailsA, 3);
                Unicode::strcat(scratchpadBuffer, v117);
                Unicode::strcat(scratchpadBuffer, itemLineBasicInfo);

                Unicode pTextToDisplay[2048] = { 0 };

                if (*D2Client_pDWORD_6FBB58EC && *D2Client_pDWORD_6FBB58EC >= 1 && *D2Client_pDWORD_6FBB58EC <= 9)
                {
                    Unicode itemLinePriceMaybe[64] = { 0 };
                    int32_t hasSkillCharges = false;
                    if (D2Client_GetItemTextPriceMaybe_6FAFB200(D2Client_pItemUnderCursor_6FBB58F0, *D2Client_pDWORD_6FB7928C, &hasSkillCharges, itemLinePriceMaybe, std::size(itemLinePriceMaybe)))
                    {
                        Unicode::strcpy(pTextToDisplay, scratchpadBuffer);
                        if (itemLinePriceMaybe[0])
                        {
                            Unicode::strcat(pTextToDisplay, v235);
                        }

                        Unicode::strcat(pTextToDisplay, itemLinePriceMaybe);
                    }
                    else
                    {
                        Unicode::strcpy(pTextToDisplay, scratchpadBuffer);
                        if (*D2Client_pDWORD_6FBB58EC != 4)
                        {
                            auto v118 = D2LANG_GetStringFromTblIndex(3333);
                            Unicode::strcpy(itemLinePriceMaybe, v118);
                            Unicode::strcat(pTextToDisplay, v235);
                            auto v119 = D2Client_ColorizeLine_6FB20430(itemLinePriceMaybe, 1);
                            Unicode::strcat(pTextToDisplay, v119);
                        }
                    }
                }
                else
                {
                    Unicode::strcpy(pTextToDisplay, scratchpadBuffer);
                }

                int32_t width = 0;
                int32_t height = 0;
                D2Win_10131_GetTextDimensions(pTextToDisplay, &width, &height);

                if (*D2Client_pDWORD_6FB79294 - height > 0)
                {
                    D2Win_10129_DrawFramedText(pTextToDisplay, *D2Client_pDWORD_6FB79290, *D2Client_pDWORD_6FB79294, 0, 1);
                    return;
                }

                auto v120 = height + *D2Client_pDWORD_6FB7929C;
                D2Win_10129_DrawFramedText(pTextToDisplay, *D2Client_pDWORD_6FB79298, v120, 0, 1);
                return;
            }
        }
    }
}

