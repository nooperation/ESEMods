#include "D2Client/UI_GroundItem_ESE.h"

#include <../D2MooHeaders.h>
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
#include "D2Roster.h"

void __fastcall ESE_D2Client_DrawGroundItemText_sub_6FB20740(D2UnitStrc* pItem, struct Unicode* outBuff, int outBuffSize)
{
    *D2Client_pUnitMouseOverTextPosY_6FB8EA2C -= 16;
    if (pItem)
    {
        auto v15 = (const wchar_t*)D2Client_GetUnitName_6FB297F0(pItem);
        int32_t colorCode = 0;
        switch (ITEMS_GetItemQuality(pItem))
        {
        case ITEMQUAL_MAGIC:
            colorCode = 3;
            break;
        case ITEMQUAL_SET:
            colorCode = 2;
            break;
        case ITEMQUAL_RARE:
            colorCode = 9;
            break;
        case ITEMQUAL_UNIQUE:
            colorCode = 4;
            break;
        case ITEMQUAL_CRAFT:
            colorCode = 8;
            break;
        case ITEMQUAL_TEMPERED:
            colorCode = 10;
            break;
        default:
            if (ITEMS_CheckItemFlag(pItem, IFLAG_SOCKETED, __LINE__, __FILE__) || ITEMS_CheckItemFlag(pItem, IFLAG_ETHEREAL, __LINE__, __FILE__))
            {
                colorCode = 5;
            }
            break;
        }

        auto v5 = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (v5->nQuest && v5->dwCode != 543647084)
        {
            colorCode = 4;
        }

        if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
        {
            const wchar_t* v11 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
            auto v8 = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);

            std::wstring itemName(std::to_wstring(v8));
            itemName.append(v11);
            itemName.append(v15);

            if (outBuff)
            {
                ColorizeString(itemName, colorCode);
                if (itemName.length() >= outBuffSize)
                {
                    FOG_DisplayAssert("Unicode::strlen(szString) < outBuffSize", __FILE__, __LINE__);
                    exit(-1);
                }
                
                wcscpy_s((wchar_t*)outBuff, outBuffSize, itemName.c_str());
            }
            else
            {
                D2Win_DrawFramedText_10129(
                    (const Unicode*)itemName.c_str(),
                    *D2Client_pUnitMouseOverTextPosX_6FB8EA28,
                    *D2Client_pUnitMouseOverTextPosY_6FB8EA2C,
                    colorCode,
                    1
                );
            }
        }
        else
        {
            std::wstring itemName;
            ESE_D2Client_BuildItemName_6FADD360(pItem, itemName);
            if (outBuff)
            {
                ColorizeString(itemName, colorCode);
                if (itemName.length() >= outBuffSize)
                {
                    FOG_DisplayAssert("Unicode::strlen(szItemName) < outBuffSize", __FILE__, __LINE__);
                    exit(-1);
                }

                wcscpy_s((wchar_t*)outBuff, outBuffSize, itemName.c_str());
            }
            else
            {
                D2Win_DrawFramedText_10129(
                    (const Unicode*)itemName.c_str(),
                    *D2Client_pUnitMouseOverTextPosX_6FB8EA28,
                    *D2Client_pUnitMouseOverTextPosY_6FB8EA2C,
                    colorCode,
                    1
                );
            }
        }
    }
}

void __fastcall ESE_D2Client_sub_6FB20A30(D2UnitStrc* pUnit)
{
    if (D2Client_GetOpenSidePanels_6FAB5750() == 3)
    {
        return;
    }

    if (!pUnit)
    {
        return;
    }

    if (pUnit->dwUnitType == 5)
    {
        D2UnitStrc* pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
        if (UNITS_GetDistanceToOtherUnit(pUnit, pCurrentPlayer) > 100)
        {
            return;
        }
    }

    if (!D2Gfx_CheckPerspective_10010())
    {
        int32_t v7 = UNITS_GetClientCoordX(pUnit);
        *D2Client_pUnitMouseOverTextPosX_6FB8EA28 = v7 - D2Client_GetViewXOffset_6FAB5890();
        int32_t v8 = UNITS_GetClientCoordY(pUnit);
        *D2Client_pUnitMouseOverTextPosY_6FB8EA2C = v8 - D2Client_GetViewYOffset_6FAB58A0();
    }
    else
    {
        int32_t v3 = UNITS_GetPrecisionX(pUnit);
        int32_t v4 = UNITS_GetPrecisionY(pUnit);
        if (!D2Gfx_SCALE_CheckPerspectivePosition_10065(v3, v4))
        {
            return;
        }

        int32_t pXAdjust;
        int32_t pYAdjust;
        D2Gfx_SCALE_AdjustPerspectivePosition_10066(v3, v4, 0, &pXAdjust, &pYAdjust);

        int32_t v5 = D2Client_GetOpenSidePanels_6FAB5750() - 1;
        if (!v5)
        {
            int32_t v6 = *D2Client_pScreenWidthUI_6FB740EC / -4;
            pXAdjust += v6;
        }
        if (v5 == 1)
        {
            int32_t v6 = *D2Client_pScreenWidthUI_6FB740EC / 4;
            pXAdjust += v6;
        }
        *D2Client_pUnitMouseOverTextPosX_6FB8EA28 = pXAdjust;
        *D2Client_pUnitMouseOverTextPosY_6FB8EA2C = pYAdjust + 16;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
    {
        int32_t nTextColor = 0;
        wchar_t nameBuff[128] = { 0 };
        int32_t pYAdjust = 0;
        D2Client_GetRosterPlayerNameAndColor_6FB21680(pUnit, &pYAdjust, &nTextColor, (struct Unicode*)nameBuff, 128);
        D2Win_DrawFramedTextEx_10130((const Unicode*)nameBuff, *D2Client_pUnitMouseOverTextPosX_6FB8EA28, *D2Client_pUnitMouseOverTextPosY_6FB8EA2C - 72, nTextColor, 1, pYAdjust);
        return;
    }
    case UNIT_MONSTER:
    {
        if (pUnit->dwClassId == 417 || pUnit->dwClassId == 418)
        {
            if (pUnit->dwClassId >= sgptDataTables->nMonStatsTxtRecordCount)
            {
                break;
            }

            auto v57 = &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
            if (!v57)
            {
                break;
            }

            const wchar_t* strMonsterName = (const wchar_t*)D2LANG_GetStringFromTblIndex((D2C_StringIndices)v57->wNameStr);
            MONSTERS_SetMonsterNameInMonsterData(pUnit, (const Unicode*)strMonsterName);

            int32_t* pActiveNpcId = nullptr;
            if (D2Client_IsActiveNpcDialogOpen_6FAFBB50(&pActiveNpcId))
            {
                break;
            }

            int32_t monsterLifeColor = D2Client_GetMonsterLifeColor_6FB20670(pUnit);
            const wchar_t* unitName = (const wchar_t*)D2Client_GetUnitName_6FB297F0(pUnit);
            D2Win_DrawFramedTextEx_10130((const Unicode*)unitName, *D2Client_pUnitMouseOverTextPosX_6FB8EA28, *D2Client_pUnitMouseOverTextPosY_6FB8EA2C - 72, 0, 1, monsterLifeColor);
            break;
        }

        if ((pUnit->dwFlags >> 9) & 1)
        {
            int32_t* pActiveNpcId = nullptr;
            if (D2Client_IsActiveNpcDialogOpen_6FAFBB50(&pActiveNpcId))
            {
                break;
            }

            int32_t monsterLifeColor = D2Client_GetMonsterLifeColor_6FB20670(pUnit);
            const wchar_t* unitName = (const wchar_t*)D2Client_GetUnitName_6FB297F0(pUnit);
            D2Win_DrawFramedTextEx_10130((const Unicode*)unitName, *D2Client_pUnitMouseOverTextPosX_6FB8EA28, *D2Client_pUnitMouseOverTextPosY_6FB8EA2C - 72, 0, 1, monsterLifeColor);
            break;
        }

        if (pUnit->dwClassId == 356)
        {
            auto rosterPetOwnerId = D2Client_GetRosterPetOwnerId_6FAB1B00(pUnit->dwUnitId);
            if (rosterPetOwnerId != -1)
            {
                if (!pUnit->dwAnimMode || pUnit->dwAnimMode == 12)
                {
                    return;
                }

                const char* rosterUnitName = (const char*)D2Client_GetRosterUnitName_6FAB0BC0(rosterPetOwnerId);
                if (rosterUnitName)
                {
                    auto rectangleColor = (D2Client_GetRosterUnitLife_6FAB1460(rosterPetOwnerId) << 7) / 100;
                    auto pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();

                    int32_t v24 = -1;
                    if (pCurrentPlayer)
                    {
                        v24 = pCurrentPlayer->dwUnitId;
                    }

                    int32_t textColor = 0;
                    if (D2Client_AreUnitsHostile_6FAB07D0(v24, rosterPetOwnerId))
                    {
                        textColor = 1;
                    }

                    D2Win_DrawFramedTextEx_10130((const Unicode*)ToWideString(rosterUnitName).c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, *D2Client_pUnitMouseOverTextPosY_6FB8EA2C - 72, textColor, 1, rectangleColor);
                    return;
                }
            }
        }

        auto originalFont = D2Win_SetFont_10127(D2FONT_FONT16);
        auto unitClassId = pUnit->dwClassId;

        D2MonStatsTxt* v28 = nullptr;
        if (unitClassId >= 0 && unitClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            v28 = &sgptDataTables->pMonStatsTxt[unitClassId];
        }

        int32_t unknownFlag = 0;
        auto v29 = v28->nMonStatsFlags[1];
        if ((v29 & gdwBitMasks[1]) == 0 && (v29 & gdwBitMasks[7]) != 0 && v28->wNameStr)
        {
            D2MonStats2Txt* v30 = D2Client_GetMonStats2TxtFromClassId_6FB247F0(pUnit->dwClassId);
            if (v30)
            {
                *D2Client_pUnitMouseOverTextPosY_6FB8EA2C -= v30->nPixHeight;
            }

            const wchar_t* v31 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
            const wchar_t* v32 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
            const wchar_t* v33 = (const wchar_t*)D2Client_GetUnitName_6FB297F0(pUnit);
            const wchar_t* v34 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);

            std::wstring v113;
            v113.append(v31);
            v113.append(v32);
            v113.append(v33);
            v113.append(v34);

            if (pUnit->dwAnimMode == 12)
            {
                auto v35 = UNITS_GetRoom(pUnit);
                if (DUNGEON_IsRoomInTown(v35))
                {
                    return;
                }

                unknownFlag = 1;
                if (STRTABLE_GetLanguage())
                {
                    const wchar_t* v39 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2315_Corpse);

                    v113.append(L"(");
                    v113.append(v39);
                    v113.append(L")");
                }
                else
                {
                    const wchar_t* v36 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2315_Corpse);
                    v113.append(v36);
                }

                const wchar_t* v42 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
                v113.append(v42);
            }

            const wchar_t* v43 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
            v113.append(v43);

            int32_t textColor = 0;
            int32_t v45 = D2Client_GetMonsterLifeColor_6FB20670(pUnit);
            int32_t pXAdjust = 0;
            if (D2Client_IsMonsterUnique_6FB40D00(pUnit))
            {
                textColor = 4;
                pXAdjust = 4;
            }
            if (D2Client_IsMonsterChampion_6FB40CC0(pUnit))
            {
                textColor = 3;
                pXAdjust = 3;
            }
            if (unknownFlag)
            {
                textColor = 1;
                pXAdjust = 1;
            }
            if (unitClassId == 243 || unitClassId == 333 || unitClassId == 242 || unitClassId == 211 || unitClassId == 544 || unitClassId == 570 || unitClassId == 229)
            {
                textColor = 4;
                pXAdjust = 4;
            }

            int screnOffsetDimensionStuff[4];
            if (!D2Client_GetScreenOffsetDimensionsTBD_6FB24690(screnOffsetDimensionStuff))
            {
                D2Win_SetFont_10127(originalFont);
                return;
            }

            auto v46 = D2Win_GetTextWidth_10121((const Unicode*)v113.c_str());
            D2Win_DrawFramedTextEx_10130((const Unicode*)v113.c_str(), ((screnOffsetDimensionStuff[0] + screnOffsetDimensionStuff[2]) >> 1) - (v46 >> 1), 32, textColor, 0, v45);
            if (unknownFlag)
            {
                (*D2Client_pUniqueMonsterInfoString_6FBBA2A0) = 0;
                D2Win_SetFont_10127(originalFont);
                return;
            }

            auto v47 = D2Client_GetMonStatsTxtFromClassId_6FAAE570(pUnit->dwClassId);
            auto v48 = 0;
            if (MONSTERS_IsDemon(pUnit))
            {
                v48 = 10078;
            }
            else if (MONSTERS_IsUndead(pUnit))
            {
                v48 = 10077;
            }

            if (!D2Client_UpdateUniqueMonsterInfoString_6FB20600(pUnit, v48))
            {
                if (v48)
                {
                    const wchar_t* v49 = (const wchar_t*)D2LANG_GetStringFromTblIndex((D2C_StringIndices)v48);
                    const wchar_t* v50 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);

                    std::wstring v112;
                    v112.append(v49);
                    v112.append(v50);

                    if (v47->wDescStr != STR_IDX_5382_dummy)
                    {
                        const wchar_t* v52 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v47->wDescStr);
                        v112.append(v52);
                    }

                    D2Client_UpdateNormalMonsterInfoString_6FB205D0((const Unicode*)v112.c_str(), pXAdjust);
                    D2Client_MonsterResistancesInfoString_6FB21570(pUnit);
                    D2Win_SetFont_10127(originalFont);
                    return;
                }

                if (v47->wDescStr != STR_IDX_5382_dummy)
                {
                    const wchar_t* v53 = (const wchar_t*)D2LANG_GetStringFromTblIndex(v47->wDescStr);
                    D2Client_UpdateNormalMonsterInfoString_6FB205D0((const Unicode*)v53, pXAdjust);
                    D2Client_MonsterResistancesInfoString_6FB21570(pUnit);
                    D2Win_SetFont_10127(originalFont);
                    return;
                }
            }

            D2Client_MonsterResistancesInfoString_6FB21570(pUnit);
            D2Win_SetFont_10127(originalFont);
            return;
        }
        *D2Client_pUniqueMonsterInfoString_6FBBA2A0 = nullptr;


        int32_t* pActiveNpcId = nullptr;
        if (D2Client_IsActiveNpcDialogOpen_6FAFBB50(&pActiveNpcId) || D2Client_IsActiveNpcTalking_6FB1EE90())
        {
            D2Win_SetFont_10127(originalFont);
        }
        else
        {
            D2MonStats2Txt* v55 = D2Client_GetMonStats2TxtFromClassId_6FB247F0(pUnit->dwClassId);
            if (v55)
            {
                *D2Client_pUnitMouseOverTextPosY_6FB8EA2C -= v55->nPixHeight;
            }

            auto v56 = (const Unicode*)D2Client_GetUnitName_6FB297F0(pUnit);
            D2Win_DrawFramedText_10129(v56, *D2Client_pUnitMouseOverTextPosX_6FB8EA28, *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
            D2Win_SetFont_10127(originalFont);
        }
        return;
    }
    case UNIT_OBJECT:
    {
        int32_t* activeNpcId = nullptr;
        if (D2Client_IsActiveNpcDialogOpen_6FAFBB50(&activeNpcId) || D2Client_IsActiveNpcTalking_6FB1EE90() == 1)
        {
            return;
        }

        auto v65 = D2Client_GetUnitName_6FB297F0(pUnit);
        auto v68 = UNITS_GetNameOffsetFromObject(pUnit);
        auto v69 = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId)->nSubClass;
        if ((v69 & 4) != 0)
        {
            const wchar_t* v75 = nullptr;

            auto v73 = DATATBLS_GetLevelsTxtRecord(pUnit->pObjectData->InteractType);
            if (v73)
            {
                if (pUnit->pObjectData->InteractType != 8)
                {
                    v75 = (const wchar_t*)v73->wszLevelName;
                }
                else if (D2Client_10002(0, 1))
                {
                    v75 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5048_Den_of_Evil);

                }
                else
                {
                    v75 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5047_Cave_Level_1);
                }
            }
            else
            {
                v75 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5389_strLevelLoadFailed);
            }

            std::wstring v104(v75);
            if (!*D2Client_pGameType_6FBA7960 || *D2Client_pGameType_6FBA7960 == 1)
            {
                D2Win_DrawFramedText_10129((const Unicode*)v104.c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, v68 + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
                return;
            }

            auto portalOwnerName = D2Client_GetRosterPortalOwnerName_6FAB0D00(pUnit->dwUnitId);
            if (portalOwnerName)
            {
                v104.append(L" (");
                v104.append(ToWideString(portalOwnerName));
                v104.append(L") ");
            }
            else
            {
                if (!strlen(D2Client_GetObjectOwnerName_6FB48550(pUnit)))
                {
                    D2Win_DrawFramedText_10129((const Unicode*)v104.c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, v68 + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
                    return;
                }

                const char* ownerName = D2Client_GetObjectOwnerName_6FB48550(pUnit);
                v104.append(L" (");
                v104.append(ToWideString(ownerName));
                v104.append(L") ");
            }

            D2Win_DrawFramedText_10129((const Unicode*)v104.c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, v68 + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
            return;
        }

        if (v69 >= 0)
        {
            if ((v69 & 0x40) != 0)
            {
                auto v77 = D2Client_GetUnitName_6FB297F0(pUnit);
                auto v78 = UNITS_GetRoom(pUnit);
                if (v78)
                {
                    auto v79 = DUNGEON_GetLevelIdFromRoom(v78);
                    auto v80 = DATATBLS_GetLevelsTxtRecord(v79);

                    const wchar_t* v81 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
                    const wchar_t* v82 = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
                    const wchar_t* v83 = (const wchar_t*)D2LANG_GetStringByReferenceString(v80->szLevelName);

                    std::wstring v110((const wchar_t*)v77);
                    v110.append(v81);
                    v110.append(v82);
                    v110.append(v83);

                    D2Win_DrawFramedText_10129((const Unicode*)v110.c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, v68 + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
                }
            }
            else
            {
                D2Win_DrawFramedText_10129((const Unicode*)v104.c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, v68 + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
            }
        }
        return;
    }
    case UNIT_ITEM:
    {
        if (!*D2Client_pShowAllGroundItemTexts_6FBBA6DC)
        {
            ESE_D2Client_DrawGroundItemText_sub_6FB20740(pUnit, nullptr, 0);
        }
        return;
    }
    case UNIT_TILE:
    {
        D2ActiveRoomStrc* v84 = UNITS_GetRoom(pUnit);
        auto destinationLevel = DUNGEON_GetWarpDestinationLevel(v84, pUnit->dwClassId);
        auto levelsTxtRecord = DATATBLS_GetLevelsTxtRecord(destinationLevel);
        if (levelsTxtRecord)
        {
            auto lvlWarmTxtRecord = DUNGEON_GetLvlWarpTxtRecordFromRoomAndUnit(v84, pUnit);
            if (lvlWarmTxtRecord)
            {
                auto textPosX = *D2Client_pUnitMouseOverTextPosX_6FB8EA28 + lvlWarmTxtRecord->dwSelectX + (lvlWarmTxtRecord->dwSelectDX >> 1);
                auto textPosY = *D2Client_pUnitMouseOverTextPosY_6FB8EA2C + lvlWarmTxtRecord->dwSelectY + (lvlWarmTxtRecord->dwSelectDY >> 1);
                const Unicode* v90 = levelsTxtRecord->wszLevelWarp;

                if (destinationLevel == 8)
                {
                    auto v91 = D2Client_10002(0, 1);
                    auto questNameIdx = STR_IDX_5086_To_The_Den_of_Evil;
                    if (!v91)
                    {
                        questNameIdx = STR_IDX_5085_To_The_Cave_Level_1;
                    }
                    v90 = D2LANG_GetStringFromTblIndex(questNameIdx);
                }

                D2Win_DrawFramedText_10129(v90, textPosX, textPosY, 0, 1);
            }
        }
        return;
    }
    default:
        return;
    }

    (*D2Client_pNormalMonsterInfoString_6FBB9FE0) = 0;
    (*D2Client_pMonsterImmunitiesInfoString_6FBBA4A0) = 0;
    (*D2Client_pUniqueMonsterInfoString_6FBBA2A0) = 0;
    return;
}
