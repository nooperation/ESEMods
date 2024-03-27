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
#include <DataTbls/MonsterIds.h>
#include <DataTbls/LevelsIds.h>

int __fastcall ESE_D2Client_sub_6FB09D80(int* drawModeMaybe, int* xPosSomething, int* yPosSomething, int* a4, int a5, int a6, int a7)
{
    auto v24 = *D2Client_pScreenHeightUI_6FB740F0 - 48;

    if (*drawModeMaybe < a7)
    {
        *yPosSomething += a7 - *drawModeMaybe;
        *drawModeMaybe = 6;
    }

    if (*xPosSomething < 6)
    {
        *a4 += 6 - *xPosSomething;
        *xPosSomething = 6;
    }

    auto v9 = *yPosSomething;
    if (*yPosSomething >= a6)
    {
        *yPosSomething = a6 - 1;
        *drawModeMaybe -= v9 - a6 + 1;
    }

    auto v10 = *a4;
    if (*a4 >= v24)
    {
        *a4 = v24;
        *xPosSomething -= v10 - v24;
    }

    if (*D2Client_pNumGroundItemsToShow_6FBB9428 >= 32)
    {
        FOG_DisplayAssert("sgnNumShowItems < MAX_SHOW_ITEMS", __FILE__, __LINE__);
        exit(-1);
    }

    if (*D2Client_pNumGroundItemsToShow_6FBB9428 <= 0)
    {
        return 1;
    }

    int32_t v11 = 0;
    for (GroundItemText* i = D2Client_pGroundItemsToShow_6FBB7028; ; ++i)
    {
        auto v15 = *drawModeMaybe <= i->UnknownB && *yPosSomething >= i->nX;
        auto v16 = *xPosSomething <= i->nY && *a4 >= i->UnknownA;

        if (v15 && v16)
        {
            break;
        }

        if (++v11 >= *D2Client_pNumGroundItemsToShow_6FBB9428)
        {
            return 1;
        }

        yPosSomething = yPosSomething;
    }

    if (a5 <= 6)
    {
        int32_t v22 = 0;
        if ((*a4 - *xPosSomething) / 2 && *xPosSomething <= v24)
        {
            v22 = D2Client_pGroundItemsToShow_6FBB7028[v11].UnknownA - *a4 - 3;
        }
        else
        {
            v22 = D2Client_pGroundItemsToShow_6FBB7028[v11].nY - *xPosSomething + 5;
        }

        *xPosSomething = v22 + *xPosSomething;
        *a4 = v22 + *a4;
        return 0;
    }
    else if ((*yPosSomething - *drawModeMaybe) / 2 && *drawModeMaybe >= a6)
    {
        *drawModeMaybe += D2Client_pGroundItemsToShow_6FBB7028[v11].nX - *yPosSomething - 1 ;
        *yPosSomething = D2Client_pGroundItemsToShow_6FBB7028[v11].nX - *yPosSomething - 1;
        return 0;
    }
    else
    {
        *yPosSomething += D2Client_pGroundItemsToShow_6FBB7028[v11].UnknownB - *drawModeMaybe + 1;
        *drawModeMaybe = D2Client_pGroundItemsToShow_6FBB7028[v11].UnknownB + 1;
        return 0;
    }

    return 0;
}

void ESE_D2Client_DrawAllGroundItemTexts_Helper(
    GroundItemText* pGroundItemToShowIter,
    D2UnitStrc* pItem,
    D2UnitStrc* pSelectedUnit,
    int32_t mouseX,
    int32_t mouseY,
    int32_t finalCoordX,
    int32_t finalCoordY,
    int32_t nColorRgb,
    int32_t& v36
)
{
    auto v39 = finalCoordY;
    auto screenXOffsetFromOpenSidePanel = 0;
    auto screenXMiddle = *D2Client_pScreenWidthUI_6FB740EC;
    auto isSidenPanelOpen = D2Client_GetOpenUiPanelMask_6FAB5750() - 1;
    if (isSidenPanelOpen)
    {
        if (isSidenPanelOpen == 1)
        {
            screenXOffsetFromOpenSidePanel = *D2Client_pScreenWidthUI_6FB740EC / 2;
        }
    }
    else
    {
        screenXMiddle = *D2Client_pScreenWidthUI_6FB740EC / 2 - 32;
    }

    if (finalCoordX >= screenXOffsetFromOpenSidePanel
        && finalCoordX <= screenXMiddle
        && finalCoordY >= -8
        && finalCoordY <= *D2Client_pScreenHeightUI_6FB740F0 - 16)
    {
        pGroundItemToShowIter->wszText[0] = 0;
        ESE_D2Client_DrawGroundItemText_sub_6FB20740(pItem, (struct Unicode*)pGroundItemToShowIter->wszText, std::size(pGroundItemToShowIter->wszText));

        int32_t pWidth = 0;
        int32_t pHeight = 0;
        D2Win_GetTextDimensions_10131((const Unicode*)pGroundItemToShowIter->wszText, &pWidth, &pHeight);
        pWidth += 8;
        auto v42 = finalCoordX - (pWidth >> 1);
        pHeight = finalCoordY - pHeight + 4;
        auto v41 = v42 + pWidth;
        auto v19 = 0;

        auto v20 = screenXOffsetFromOpenSidePanel;
        auto v21 = screenXMiddle;

        auto v22 = 1;
        while (1)
        {
            if (ESE_D2Client_sub_6FB09D80(&v42, &pHeight, &v41, &v39, v19, screenXMiddle, screenXOffsetFromOpenSidePanel))
            {
                break;
            }
            if (++v19 >= 12)
            {
                v22 = 0;
                break;
            }
        }

        if (v41 <= v21)
        {
            auto v24 = v42;
            if (v42 >= v20 && v22)
            {
                pGroundItemToShowIter->nX = v42;
                pGroundItemToShowIter->UnknownA = pHeight;
                pGroundItemToShowIter->UnknownB = v41;
                pGroundItemToShowIter->nY = v39;
                if (v36 == 0)
                {
                    if (mouseX >= v24 && mouseX <= v41 && mouseY >= pHeight && mouseY <= v39 + 4)
                    {
                        pGroundItemToShowIter->nDrawMode = 5;
                        pGroundItemToShowIter->nColor = 0;
                        pGroundItemToShowIter->colorRgb = nColorRgb;
                        D2Client_sub_6FAB5A90(pItem);
                        v36 = 1;
                        ++(*D2Client_pNumGroundItemsToShow_6FBB9428);
                        return;
                    }

                    if (pItem == pSelectedUnit)
                    {
                        pGroundItemToShowIter->colorRgb = (unsigned __int8)nColorRgb;
                        pGroundItemToShowIter->nDrawMode = 5;
                        pGroundItemToShowIter->nColor = 0;
                        D2Win_DrawFramedText_10129(0, 0, 0, 0, 0);
                        D2Client_ClearUnitSelection_6FAB5D40();
                        v36 = 1;
                        ++(*D2Client_pNumGroundItemsToShow_6FBB9428);
                        return;
                    }
                }


                pGroundItemToShowIter->colorRgb = 0;
                pGroundItemToShowIter->nDrawMode = 1;
                switch (ITEMS_GetItemQuality(pItem))
                {
                case ITEMQUAL_MAGIC:
                    pGroundItemToShowIter->nColor = 3;
                    break;
                case ITEMQUAL_SET:
                    pGroundItemToShowIter->nColor = 2;
                    break;
                case ITEMQUAL_RARE:
                    pGroundItemToShowIter->nColor = 9;
                    break;
                case ITEMQUAL_UNIQUE:
                    pGroundItemToShowIter->nColor = 4;
                    break;
                case ITEMQUAL_CRAFT:
                    pGroundItemToShowIter->nColor = 8;
                    break;
                case ITEMQUAL_TEMPERED:
                    pGroundItemToShowIter->nColor = 10;
                    break;
                default:
                    if (ITEMS_CheckItemFlag(pItem, IFLAG_SOCKETED, __LINE__, __FILE__)
                        && ITEMS_CheckIfSocketable(pItem)
                        && ITEMS_GetMaxSockets(pItem)
                        || ITEMS_CheckItemFlag(pItem, IFLAG_ETHEREAL, __LINE__, __FILE__))
                    {
                        pGroundItemToShowIter->nColor = 5;
                    }
                    break;
                }
                auto pItemTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
                if (pItemTxtRecord->nQuest && pItemTxtRecord->dwCode != 543647084)
                {
                    pGroundItemToShowIter->nColor = 4;
                }
                ++(*D2Client_pNumGroundItemsToShow_6FBB9428);
                return;
            }
        }
    }
}

void __stdcall ESE_D2Client_DrawAllGroundItemTexts_6FB09F60()
{
    auto isPerspective = D2Gfx_CheckPerspective_10010();

    auto pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
    if (!pCurrentPlayer)
    {
        return;
    }

    auto currentPlayerRoom = UNITS_GetRoom(pCurrentPlayer);
    if (!currentPlayerRoom)
    {
        return;
    }

    auto pSelectedUnit = D2Client_GetSelectedUnit_6FAB5A20();
    auto mouseX = D2Client_GetMouseXPos();
    auto mouseY = D2Client_GetMouseYPos();

    D2ActiveRoomStrc** pppRoomList;
    int32_t pNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(currentPlayerRoom, &pppRoomList, &pNumRooms);

    int32_t nColorRgb = D2Win_MixRGB_10034(0, 0x40u, 0x80u);
    auto roomIndex = 0;
    *D2Client_pNumGroundItemsToShow_6FBB9428 = 0;
    auto v36 = 0;
    if (pNumRooms)
    {
        do
        {
            auto pUnit = pppRoomList[roomIndex]->pUnitFirst;
            if (!pUnit)
            {
                ++roomIndex;
                continue;
            }

            while (1)
            {
                if ((pUnit->dwFlagEx & UNITFLAGEX_ISINLOS) && pUnit->dwUnitType == UNIT_ITEM && *D2Client_pNumGroundItemsToShow_6FBB9428 < 32)
                {
                    auto pGroundItemToShowIter = &D2Client_pGroundItemsToShow_6FBB7028[*D2Client_pNumGroundItemsToShow_6FBB9428];
                    pGroundItemToShowIter->pUnit = pUnit;

                    if (isPerspective == 0)
                    {
                        auto clientCoordX = UNITS_GetClientCoordX(pUnit);
                        auto finalCoordX = clientCoordX - D2Client_GetViewXOffset_6FAB5890();
                        auto viewOffsetY = -16 - D2Client_GetViewYOffset_6FAB58A0();
                        auto clinetCoordY = UNITS_GetClientCoordY(pUnit);
                        auto finalCoordY = clinetCoordY + viewOffsetY;

                        ESE_D2Client_DrawAllGroundItemTexts_Helper(
                            pGroundItemToShowIter,
                            pUnit,
                            pSelectedUnit,
                            mouseX,
                            mouseY,
                            finalCoordX,
                            finalCoordY,
                            nColorRgb,
                            v36
                        );
                    }
                    else
                    {
                        auto v7 = UNITS_GetPrecisionX(pUnit);
                        auto v8 = UNITS_GetPrecisionY(pUnit);
                        if (D2Gfx_SCALE_CheckPerspectivePosition_10065(v7, v8))
                        {
                            int32_t pXAdjust;
                            int32_t pYAdjust;
                            D2Gfx_SCALE_AdjustPerspectivePosition_10066(v7, v8, 0, &pXAdjust, &pYAdjust);
                            auto v9 = D2Client_GetOpenUiPanelMask_6FAB5750();

                            if (v9 - 1 == 0)
                            {
                                pXAdjust += *D2Client_pScreenWidthUI_6FB740EC / -4;
                            }
                            else if (v9 - 1 == 1)
                            {
                                pXAdjust += *D2Client_pScreenWidthUI_6FB740EC / 4;
                            }

                            auto finalCoordX = pXAdjust;
                            auto finalCoordY = pYAdjust;
                            ESE_D2Client_DrawAllGroundItemTexts_Helper(
                                pGroundItemToShowIter,
                                pUnit,
                                pSelectedUnit,
                                mouseX,
                                mouseY,
                                finalCoordX,
                                finalCoordY,
                                nColorRgb,
                                v36
                            );
                        }
                    }
                }

            LABEL_63:
                pUnit = pUnit->pRoomNext;
                if (!pUnit)
                {
                    break;
                }
            }

            ++roomIndex;
        } while (roomIndex < pNumRooms);
    }

    for (int32_t i = 0; i < *D2Client_pNumGroundItemsToShow_6FBB9428; ++i)
    {
        auto currentGroundItemToShow = &D2Client_pGroundItemsToShow_6FBB7028[i];

        D2Win_10132(
            (const Unicode*)currentGroundItemToShow->wszText,
            currentGroundItemToShow->nX,
            currentGroundItemToShow->nY,
            currentGroundItemToShow->colorRgb,
            (DrawMode)currentGroundItemToShow->nDrawMode,
            currentGroundItemToShow->nColor
        );
    }

    if (!v36)
    {
        D2Client_ClearUnitSelection_6FAB5D40();
        D2Win_DrawFramedText_10129(0, 0, 0, 0, 0);
    }
}

void __fastcall ESE_D2Client_DrawGroundItemText_sub_6FB20740(D2UnitStrc* pItem, struct Unicode* outBuff, int outBuffSize)
{
    *D2Client_pUnitMouseOverTextPosY_6FB8EA2C -= 16;
    if (pItem)
    {
        auto itemName = (const wchar_t*)D2Client_GetUnitName_6FB297F0(pItem);
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

        auto pItemTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemTxtRecord->nQuest && pItemTxtRecord->dwCode != 543647084)
        {
            colorCode = 4;
        }

        if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
        {
            const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);

            auto goldAmount = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);

            std::wstring displayName(std::to_wstring(goldAmount));
            displayName.append(strSpace);
            displayName.append(itemName);

            if (outBuff)
            {
                ColorizeString(displayName, colorCode);
                if (displayName.length() >= outBuffSize)
                {
                    FOG_DisplayAssert("Unicode::strlen(szString) < outBuffSize", __FILE__, __LINE__);
                    exit(-1);
                }

                wcscpy_s((wchar_t*)outBuff, outBuffSize, displayName.c_str());
            }
            else
            {
                D2Win_DrawFramedText_10129(
                    (const Unicode*)displayName.c_str(),
                    *D2Client_pUnitMouseOverTextPosX_6FB8EA28,
                    *D2Client_pUnitMouseOverTextPosY_6FB8EA2C,
                    colorCode,
                    1
                );
            }
        }
        else
        {
            std::wstring displayName;
            ESE_D2Client_BuildItemName_6FADD360(pItem, displayName);
            if (outBuff)
            {
                ColorizeString(displayName, colorCode);
                if (displayName.length() >= outBuffSize)
                {
                    FOG_DisplayAssert("Unicode::strlen(szItemName) < outBuffSize", __FILE__, __LINE__);
                    exit(-1);
                }

                wcscpy_s((wchar_t*)outBuff, outBuffSize, displayName.c_str());
            }
            else
            {
                D2Win_DrawFramedText_10129(
                    (const Unicode*)displayName.c_str(),
                    *D2Client_pUnitMouseOverTextPosX_6FB8EA28,
                    *D2Client_pUnitMouseOverTextPosY_6FB8EA2C,
                    colorCode,
                    1
                );
            }
        }
    }
}

void __fastcall ESE_D2Client_DrawGroundItemMouseOverText_6FB20A30(D2UnitStrc* pUnit)
{
    if (D2Client_GetOpenUiPanelMask_6FAB5750() == 3)
    {
        return;
    }

    if (!pUnit)
    {
        return;
    }

    if (pUnit->dwUnitType == UNIT_TILE)
    {
        D2UnitStrc* pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
        if (UNITS_GetDistanceToOtherUnit(pUnit, pCurrentPlayer) > 100)
        {
            return;
        }
    }

    if (!D2Gfx_CheckPerspective_10010())
    {
        int32_t unitX = UNITS_GetClientCoordX(pUnit);
        int32_t unitY = UNITS_GetClientCoordY(pUnit);

        *D2Client_pUnitMouseOverTextPosX_6FB8EA28 = unitX - D2Client_GetViewXOffset_6FAB5890();
        *D2Client_pUnitMouseOverTextPosY_6FB8EA2C = unitY - D2Client_GetViewYOffset_6FAB58A0();
    }
    else
    {
        int32_t unitX = UNITS_GetPrecisionX(pUnit);
        int32_t unitY = UNITS_GetPrecisionY(pUnit);

        if (!D2Gfx_SCALE_CheckPerspectivePosition_10065(unitX, unitY))
        {
            return;
        }

        int32_t pXAdjust;
        int32_t pYAdjust;
        D2Gfx_SCALE_AdjustPerspectivePosition_10066(unitX, unitY, 0, &pXAdjust, &pYAdjust);

        int32_t openSidePanelStatus = D2Client_GetOpenUiPanelMask_6FAB5750();
        if (openSidePanelStatus == 1)
        {
            int32_t openPanelOffset = *D2Client_pScreenWidthUI_6FB740EC / -4;
            pXAdjust += openPanelOffset;
        }
        if (openSidePanelStatus == 2)
        {
            int32_t openPanelOffset = *D2Client_pScreenWidthUI_6FB740EC / 4;
            pXAdjust += openPanelOffset;
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
        D2Client_GetRosterPlayerNameAndColor_6FB21680(pUnit, &pYAdjust, &nTextColor, (struct Unicode*)nameBuff, std::size(nameBuff));
        D2Win_DrawFramedTextEx_10130((const Unicode*)nameBuff, *D2Client_pUnitMouseOverTextPosX_6FB8EA28, *D2Client_pUnitMouseOverTextPosY_6FB8EA2C - 72, nTextColor, 1, pYAdjust);
        return;
    }
    case UNIT_MONSTER:
    {
        if (pUnit->dwClassId == MONSTER_SHADOWWARRIOR || pUnit->dwClassId == MONSTER_SHADOWMASTER)
        {
            if (pUnit->dwClassId >= sgptDataTables->nMonStatsTxtRecordCount)
            {
                break;
            }

            auto pMonStatsTxt = &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
            if (!pMonStatsTxt)
            {
                break;
            }

            const wchar_t* strMonsterName = (const wchar_t*)D2LANG_GetStringFromTblIndex((D2C_StringIndices)pMonStatsTxt->wNameStr);
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

        if (pUnit->dwFlags & UNITFLAG_ISMERC)
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

        if (pUnit->dwClassId == MONSTER_DOPPLEZON)
        {
            auto rosterPetOwnerId = D2Client_GetRosterPetOwnerId_6FAB1B00(pUnit->dwUnitId);
            if (rosterPetOwnerId != -1)
            {
                if (pUnit->dwAnimMode == MONMODE_DEATH || pUnit->dwAnimMode == MONMODE_DEAD)
                {
                    return;
                }

                const char* rosterUnitName = (const char*)D2Client_GetRosterUnitName_6FAB0BC0(rosterPetOwnerId);
                if (rosterUnitName)
                {
                    auto rectangleColor = (D2Client_GetRosterUnitLife_6FAB1460(rosterPetOwnerId) << 7) / 100;
                    auto pCurrentPlayer = D2Client_GetCurrentPlayer_6FB283D0();

                    int32_t currentPlayerUnitId = -1;
                    if (pCurrentPlayer)
                    {
                        currentPlayerUnitId = pCurrentPlayer->dwUnitId;
                    }

                    int32_t textColor = 0;
                    if (D2Client_AreUnitsHostile_6FAB07D0(currentPlayerUnitId, rosterPetOwnerId))
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

        D2MonStatsTxt* pMonStatsTxt = nullptr;
        if (unitClassId >= 0 && unitClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxt = &sgptDataTables->pMonStatsTxt[unitClassId];
        }

        int32_t unknownFlag = 0;
        auto v29 = pMonStatsTxt->nMonStatsFlags[1];
        if ((v29 & gdwBitMasks[1]) == 0 && (v29 & gdwBitMasks[7]) != 0 && pMonStatsTxt->wNameStr)
        {
            D2MonStats2Txt* v30 = D2Client_GetMonStats2TxtFromClassId_6FB247F0(pUnit->dwClassId);
            if (v30)
            {
                *D2Client_pUnitMouseOverTextPosY_6FB8EA2C -= v30->nPixHeight;
            }

            const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
            const wchar_t* strUnitName = (const wchar_t*)D2Client_GetUnitName_6FB297F0(pUnit);

            std::wstring displayName;
            displayName.append(strSpace);
            displayName.append(strSpace);
            displayName.append(strUnitName);
            displayName.append(strSpace);

            if (pUnit->dwAnimMode == MONMODE_DEAD)
            {
                const wchar_t* strCorpse = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_2315_Corpse);

                auto unitRoom = UNITS_GetRoom(pUnit);
                if (DUNGEON_IsRoomInTown(unitRoom))
                {
                    return;
                }

                unknownFlag = 1;
                if (STRTABLE_GetLanguage())
                {

                    displayName.append(L"(");
                    displayName.append(strCorpse);
                    displayName.append(L")");
                }
                else
                {
                    displayName.append(strCorpse);
                }

                displayName.append(strSpace);
            }

            displayName.append(strSpace);

            int32_t textColor = 0;
            int32_t backgroundColor = D2Client_GetMonsterLifeColor_6FB20670(pUnit);
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

            if (
                unitClassId == MONSTER_DIABLO ||
                unitClassId == MONSTER_DIABLOCLONE ||
                unitClassId == MONSTER_MEPHISTO ||
                unitClassId == MONSTER_DURIEL ||
                unitClassId == MONSTER_BAALCRAB ||
                unitClassId == MONSTER_BAALCLONE ||
                unitClassId == MONSTER_RADAMENT)
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

            auto displayNameTextWidth = D2Win_GetTextWidth_10121((const Unicode*)displayName.c_str());
            D2Win_DrawFramedTextEx_10130(
                (const Unicode*)displayName.c_str(),
                ((screnOffsetDimensionStuff[0] + screnOffsetDimensionStuff[2]) >> 1) - (displayNameTextWidth >> 1),
                32,
                textColor,
                0,
                backgroundColor
            );
            if (unknownFlag)
            {
                *D2Client_pUniqueMonsterInfoString_6FBBA2A0 = 0;
                D2Win_SetFont_10127(originalFont);
                return;
            }

            auto pMonStatsTxt = D2Client_GetMonStatsTxtFromClassId_6FAAE570(pUnit->dwClassId);
            auto stringIndex = 0;
            if (MONSTERS_IsDemon(pUnit))
            {
                stringIndex = STR_IDX_10078_DemonID;
            }
            else if (MONSTERS_IsUndead(pUnit))
            {
                stringIndex = STR_IDX_10077_UndeadDescriptX;
            }

            if (!D2Client_UpdateUniqueMonsterInfoString_6FB20600(pUnit, stringIndex))
            {
                if (stringIndex)
                {
                    const wchar_t* strMonsterType = (const wchar_t*)D2LANG_GetStringFromTblIndex((D2C_StringIndices)stringIndex);
                    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);

                    std::wstring monsterInfoString;
                    monsterInfoString.append(strMonsterType);
                    monsterInfoString.append(strSpace);

                    if (pMonStatsTxt->wDescStr != STR_IDX_5382_dummy)
                    {
                        const wchar_t* strDesc = (const wchar_t*)D2LANG_GetStringFromTblIndex(pMonStatsTxt->wDescStr);
                        monsterInfoString.append(strDesc);
                    }

                    D2Client_UpdateNormalMonsterInfoString_6FB205D0((const Unicode*)monsterInfoString.c_str(), pXAdjust);
                    D2Client_MonsterResistancesInfoString_6FB21570(pUnit);
                    D2Win_SetFont_10127(originalFont);
                    return;
                }

                if (pMonStatsTxt->wDescStr != STR_IDX_5382_dummy)
                {
                    const wchar_t* strDesc = (const wchar_t*)D2LANG_GetStringFromTblIndex(pMonStatsTxt->wDescStr);

                    D2Client_UpdateNormalMonsterInfoString_6FB205D0((const Unicode*)strDesc, pXAdjust);
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
            D2MonStats2Txt* monStats2Txt = D2Client_GetMonStats2TxtFromClassId_6FB247F0(pUnit->dwClassId);
            if (monStats2Txt)
            {
                *D2Client_pUnitMouseOverTextPosY_6FB8EA2C -= monStats2Txt->nPixHeight;
            }

            auto unitName = (const Unicode*)D2Client_GetUnitName_6FB297F0(pUnit);
            D2Win_DrawFramedText_10129(unitName, *D2Client_pUnitMouseOverTextPosX_6FB8EA28, *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
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

        auto objectName = D2Client_GetUnitName_6FB297F0(pUnit);
        auto nameOffset = UNITS_GetNameOffsetFromObject(pUnit);
        auto objectSubclass = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId)->nSubClass;
        if ((objectSubclass & OBJSUBCLASS_TOWNPORTAL) != 0)
        {
            std::wstring displayName;

            auto v73 = DATATBLS_GetLevelsTxtRecord(pUnit->pObjectData->InteractType);
            if (v73)
            {
                if (pUnit->pObjectData->InteractType != LEVEL_DENOFEVIL)
                {
                    displayName.assign((const wchar_t*)v73->wszLevelName);
                }
                else if (D2Client_10002(0, 1))
                {
                    displayName.assign((const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5048_Den_of_Evil));

                }
                else
                {
                    displayName.assign((const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5047_Cave_Level_1));
                }
            }
            else
            {
                displayName.assign((const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_5389_strLevelLoadFailed));
            }

            if (*D2Client_pGameType_6FBA7960 == 0 || *D2Client_pGameType_6FBA7960 == 1)
            {
                D2Win_DrawFramedText_10129((const Unicode*)displayName.c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, nameOffset + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
                return;
            }

            auto portalOwnerName = D2Client_GetRosterPortalOwnerName_6FAB0D00(pUnit->dwUnitId);
            if (portalOwnerName)
            {
                displayName.append(L" (");
                displayName.append(ToWideString(portalOwnerName));
                displayName.append(L") ");
            }
            else
            {
                if (!strlen(D2Client_GetObjectOwnerName_6FB48550(pUnit)))
                {
                    D2Win_DrawFramedText_10129((const Unicode*)displayName.c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, nameOffset + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
                    return;
                }

                const char* ownerName = D2Client_GetObjectOwnerName_6FB48550(pUnit);
                displayName.append(L" (");
                displayName.append(ToWideString(ownerName));
                displayName.append(L") ");
            }

            D2Win_DrawFramedText_10129((const Unicode*)displayName.c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, nameOffset + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
            return;
        }

        if (objectSubclass >= 0)
        {
            if ((objectSubclass & OBJSUBCLASS_WAYPOINT) != 0)
            {
                auto waypointName = D2Client_GetUnitName_6FB297F0(pUnit);
                auto unitRoom = UNITS_GetRoom(pUnit);
                if (unitRoom)
                {
                    auto levelId = DUNGEON_GetLevelIdFromRoom(unitRoom);
                    auto levelTxtRecord = DATATBLS_GetLevelsTxtRecord(levelId);

                    const wchar_t* strSpace = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3995_space);
                    const wchar_t* strNewLine = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3998_newline);
                    const wchar_t* strLevelName = (const wchar_t*)D2LANG_GetStringByReferenceString(levelTxtRecord->szLevelName);

                    std::wstring displayName((const wchar_t*)waypointName);
                    displayName.append(strSpace);
                    displayName.append(strNewLine);
                    displayName.append(strLevelName);

                    D2Win_DrawFramedText_10129((const Unicode*)displayName.c_str(), *D2Client_pUnitMouseOverTextPosX_6FB8EA28, nameOffset + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
                }
            }
            else
            {
                D2Win_DrawFramedText_10129((const Unicode*)objectName, *D2Client_pUnitMouseOverTextPosX_6FB8EA28, nameOffset + *D2Client_pUnitMouseOverTextPosY_6FB8EA2C, 0, 1);
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
        D2ActiveRoomStrc* unitRoom = UNITS_GetRoom(pUnit);
        auto destinationLevel = DUNGEON_GetWarpDestinationLevel(unitRoom, pUnit->dwClassId);
        auto levelsTxtRecord = DATATBLS_GetLevelsTxtRecord(destinationLevel);
        if (levelsTxtRecord)
        {
            auto lvlWarmTxtRecord = DUNGEON_GetLvlWarpTxtRecordFromRoomAndUnit(unitRoom, pUnit);
            if (lvlWarmTxtRecord)
            {
                auto textPosX = *D2Client_pUnitMouseOverTextPosX_6FB8EA28 + lvlWarmTxtRecord->dwSelectX + (lvlWarmTxtRecord->dwSelectDX >> 1);
                auto textPosY = *D2Client_pUnitMouseOverTextPosY_6FB8EA2C + lvlWarmTxtRecord->dwSelectY + (lvlWarmTxtRecord->dwSelectDY >> 1);
                const Unicode* strLevelName = levelsTxtRecord->wszLevelWarp;

                if (destinationLevel == 8)
                {
                    auto v91 = D2Client_10002(0, 1);
                    auto questNameIdx = STR_IDX_5086_To_The_Den_of_Evil;
                    if (!v91)
                    {
                        questNameIdx = STR_IDX_5085_To_The_Cave_Level_1;
                    }
                    strLevelName = D2LANG_GetStringFromTblIndex(questNameIdx);
                }

                D2Win_DrawFramedText_10129(strLevelName, textPosX, textPosY, 0, 1);
            }
        }
        return;
    }
    default:
        return;
    }

    *D2Client_pNormalMonsterInfoString_6FBB9FE0 = 0;
    *D2Client_pMonsterImmunitiesInfoString_6FBBA4A0 = 0;
    *D2Client_pUniqueMonsterInfoString_6FBBA2A0 = 0;
    return;
}
