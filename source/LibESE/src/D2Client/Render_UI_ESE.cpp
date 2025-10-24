#include "D2Client/Render_UI_ESE.h"
#include "D2Client/UI_GroundItem_ESE.h"
#include "../D2ClientExports.h"
#include "LibESE.h"
#include <D2Combat.h>
#include "Font.h"
#include <cinttypes>
#include <D2States.h>
#include <string>
#include "D2Gfx.h"
#include "D2Config.h"
#include <bitset>
#include <bit>
#include <string>

void __fastcall ESE_D2Client_RenderUI_6FB21B70(D2ViewStruct* pRenderer)
{
    /*
    int result; // eax
    D2UnitStrc* v2; // eax
    D2UnitStrc* v3; // eax
    int v4; // eax
    int v5; // esi
    D2UnitStrc* v6; // esi
    int v7; // edi
    int v8; // ebp
    int v9; // eax
    int v10; // eax
    int v11; // edi
    int v12; // edi
    const struct Unicode* v13; // eax
    D2ActiveRoomStrc* v14; // eax
    D2CellFileStrc* pCellFile; // ecx
    int v16; // ebp
    int oldLevelId; // eax
    int v18; // eax
    int newLevelTickCount; // eax
    D2LevelsTxt* currentLevelTxt; // esi
    int v21; // eax
    char v22; // cl
    uint8_t v23; // al
    int v24; // esi
    int* v25; // edi
    D2CellFileStrc* finalCellFile; // ecx
    signed int i; // esi
    D2UnitStrc* v28; // eax
    int v29; // esi
    D2UnitStrc* v30; // eax
    D2UnitStrc* v31; // edi
    int v32; // esi
    int v33; // eax
    D2UnitStrc* v34; // eax
    D2RosterUnitStrc* v35; // eax
    uint32_t v36; // esi
    int v37; // [esp+18h] [ebp-154h]
    int v38; // [esp+1Ch] [ebp-150h]
    int32_t pXAdjust; // [esp+30h] [ebp-13Ch] BYREF
    D2ViewStruct* pYAdjust; // [esp+34h] [ebp-138h] BYREF
    CHAR v43[12]; // [esp+5Ch] [ebp-110h] BYREF
    char celFilePath[12]; // [esp+68h] [ebp-104h] BYREF

    */

    int32_t yAdjust = 0;
    int32_t xAdjust = 0;

    if (D2Client_UIStates_6FBBA6A8[18]) // UI_MSGLOG
    {
        return D2Client_UIStates_6FBBA6A8[18];
    }

    if (D2Gfx_GetResolutionMode_10005() == NUM_GAME_RESOLUTIONS)
    {
        *D2Client_pScreenXOffset_6FBBA748 = 80;
        *D2Client_pScreenYOffset_6FBBA74C = -60;
    }
    else
    {
        *D2Client_pScreenXOffset_6FBBA748 = 0;
        *D2Client_pScreenYOffset_6FBBA74C = 0;
    }

    D2Win_DrawFramedText_10129(0, 0, 0, 0, 0);
    D2Client_pNormalMonsterInfoString256_6FBB9FE0[0] = 0;
    D2Client_pMonsterImmunitiesInfoString256_6FBBA4A0[0] = 0;

    if (D2Client_UIStates_6FBBA6A8[9]) // UI_ESCMENU
    {
        D2Client_UI_DrawEscapeMenu_6FB088B0();
    }

    if (D2Client_UIStates_6FBBA6A8[11]) // UI_CONFIG
    {
        D2Client_UI_DrawConfigMenu_6FAFC620();
    }

    auto selectedUnit = D2Client_GetSelectedUnit_6FAB5A20();
    ESE_D2Client_DrawGroundItemMouseOverText_6FB20A30(selectedUnit);


    if (D2Client_UIStates_6FBBA6A8[35]) // UI_HIREICONS
    {
        if (D2Client_GetOpenUiPanelMask_6FAB5750() != 3)
        {
            auto currentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
            auto currentPlayerMercId = D2Client_Roster_GetPetByUnitIdType_6FAB1920(currentPlayer, PETTYPE_HIREABLE, 0);
            if (currentPlayerMercId != -1 && ((uint8_t *)D2Client_Roster_GetPetUNK24_6FAB18D0(currentPlayerMercId))[2] == 1) // TODO: This should reveal something about unk24?
            {
                auto currentPlayerMerc = D2Client_FindUnit_6FB269F0(currentPlayerMercId, UNIT_MONSTER);
                if (currentPlayerMerc)
                {
                    if (!D2Gfx_CheckPerspective_10010())
                    {
                        auto currentPlayerMercUIPosX = UNITS_GetClientCoordX(currentPlayerMerc);
                        *D2Client_pUnitMouseOverTextPosX_6FB8EA28 = currentPlayerMercUIPosX - D2Client_GetAdjustedViewOffsetX_6FAB5890();

                        auto currentPlayerMercUIPosY = UNITS_GetClientCoordY(currentPlayerMerc);
                        *D2Client_pUnitMouseOverTextPosY_6FB8EA2C = currentPlayerMercUIPosY - D2Client_GetAdjustedViewOffsetY_6FAB58A0();

                    LABEL_23:

                        int32_t tempActiveNpcId = 0;
                        auto pTempActiveNpcId = &tempActiveNpcId;
                        if (!D2Client_IsActiveNpcDialogOpen_6FAFBB50(&pTempActiveNpcId))
                        {
                            auto v38 = D2Client_GetMonsterLifeColor_6FB20670(currentPlayerMerc);
                            auto v37 = *D2Client_pUnitMouseOverTextPosY_6FB8EA2C - 72;
                            auto v13 = D2Client_GetUnitName_6FB297F0(currentPlayerMerc);
                            D2Client_UI_UpdateMercFloatingText_6FB20590(v13, D2Client_pUnitMouseOverTextPosX_6FB8EA28, v37, v38); // Draw unit name over head
                        }
                        goto LABEL_25;
                    }

                    auto currentPlayerMercPrecisionX = UNITS_GetPrecisionX(currentPlayerMerc);
                    auto currentPlayerMercPrecisionY = UNITS_GetPrecisionY(currentPlayerMerc);
                    if (!D2Gfx_SCALE_CheckPerspectivePosition_10065(currentPlayerMercPrecisionX, currentPlayerMercPrecisionY))
                    {
                        goto LABEL_25;
                    }

                    D2Gfx_SCALE_AdjustPerspectivePosition_10066(
                        currentPlayerMercPrecisionX,
                        currentPlayerMercPrecisionY,
                        0,
                        &xAdjust,
                        &yAdjust
                    );

                    int32_t screenXAdjust = 0;
                    int32_t screenYAdjust = D2Client_GetOpenUiPanelMask_6FAB5750() - 1;
                    if (screenYAdjust)
                    {
                        if (screenYAdjust != 1)
                        {
                        LABEL_21:
                            *D2Client_pUnitMouseOverTextPosX_6FB8EA28 = xAdjust;
                            *D2Client_pUnitMouseOverTextPosY_6FB8EA2C = yAdjust + 16;
                            goto LABEL_23;
                        }
                        screenXAdjust = *D2Client_pScreenWidthUI_6FB740EC / 4;
                    }
                    else
                    {
                        screenXAdjust = *D2Client_pScreenWidthUI_6FB740EC / -4;
                    }
                    xAdjust += screenXAdjust;
                    goto LABEL_21;
                }
            }
        }
    }
LABEL_25:
    if (!D2Client_UIStates_6FBBA6A8[1] &&  // UI_INVENTORY
        !D2Client_UIStates_6FBBA6A8[12] && // UI_NPCSHOP
        !D2Client_UIStates_6FBBA6A8[14])   // UI_ANVIL
    {
        D2Client_UI_DrawDurabilityWarning_6FAFEE70();
        D2Client_UI_DrawAmmoDurability_6FAFEA40();
    }

    if (D2Client_UIStates_6FBBA6A8[10] && D2Client_GetOpenUiPanelMask_6FAB5750() != 3) // UI_AUTOMAP
    {
        D2Client_UI_DrawAutomap_6FACDCB0();
    }

    D2CellFileStrc* pCellFile;
    int32_t newLevelTickCount = 0;

    // TEMP - need to define
    D2CellFileStrc** D2Client_UI_pCellFileLevelTitle_6FBBA1E8;
    uint32_t* D2Client_UI_pCurrentLevelId_6FBBA784;
    uint32_t* D2Client_UI_pNewLevelTickCount120_6FBBA788;
    QuestNameOverride* D2Client_Quest_pQuestNameOverrides_6FB8EC54;
    int32_t* D2Client_Quest_pQuestNameOverridesCount_6FB8EC70;
    int32_t* D2Client_pMonsterImmunitiesInfoStringColor_6FBBA6A0;
    int32_t* D2Client_pNormalMonsterInfoStringColor_6FBBA1E0;

    auto currentRoom = D2Client_GetCurrentRoom_6FB29370();
    if (currentRoom)
    {
        auto currentLevelId = DUNGEON_GetLevelIdFromRoom(currentRoom);
        if (currentLevelId == *D2Client_UI_pCurrentLevelId_6FBBA784)
        {
            pCellFile = *D2Client_UI_pCellFileLevelTitle_6FBBA1E8;
            newLevelTickCount = *D2Client_UI_pNewLevelTickCount120_6FBBA788;
        }
        else
        {
            // Something about drawing the level title when changing levels?
            sub_6FADA970(1);

            pCellFile = *D2Client_UI_pCellFileLevelTitle_6FBBA1E8;
            if (pCellFile)
            {
                D2Client_Archive_FreeCellFile_6FAA1140(pCellFile);
                pCellFile = nullptr;
                *D2Client_UI_pCellFileLevelTitle_6FBBA1E8 = nullptr;
            }

            auto oldLevelId = *D2Client_UI_pCurrentLevelId_6FBBA784;

            *D2Client_UI_pCurrentLevelId_6FBBA784 = currentLevelId;

            newLevelTickCount = (oldLevelId == 0) ? 120 : 0;

            *D2Client_UI_pNewLevelTickCount120_6FBBA788 = newLevelTickCount;
        }


        if (newLevelTickCount < 120)
        {
            *D2Client_UI_pNewLevelTickCount120_6FBBA788 = newLevelTickCount + 1;

            auto currentLevelTxt = DATATBLS_GetLevelsTxtRecord(currentLevelId);
            char actDirectoryName[32];

            if (currentLevelId < 109)
            {
                auto actNumber = DRLG_GetActNoFromLevelId(currentLevelId);

                // DATA\LOCAL\UI\ENG\Act#\filename.dc6
                sprintf(actDirectoryName, "ACT%d", actNumber + 1);
            }
            else
            {
                // DATA\LOCAL\UI\ENG\Expansion\filename.dc6
                sprintf(actDirectoryName, "EXPANSION");
            }

            char celFilePath[MAX_PATH];

            char languageCode[4];
            D2Lang_10006(&languageCode[0], 0);
            sprintf(celFilePath, "%s\\UI\\%s\\%s\\%s", "DATA\\LOCAL", languageCode, actDirectoryName, currentLevelTxt->szEntryFile);


            int32_t questNameOverrideIndex = 0;
            if (*D2Client_Quest_pQuestNameOverridesCount_6FB8EC70 > 0)
            {
                auto questNameOverride = D2Client_Quest_pQuestNameOverrides_6FB8EC54;
                while (currentLevelId != questNameOverride->nLevelId || !D2Client_10002(0, questNameOverride->nLevelId))
                {
                    ++questNameOverrideIndex;
                    ++questNameOverride;
                    if (questNameOverrideIndex >= *D2Client_Quest_pQuestNameOverridesCount_6FB8EC70)
                    {
                        goto LABEL_54;
                    }
                }
                sprintf(
                    celFilePath,
                    "%s\\UI\\%s\\ACT1\\%s",
                    "DATA\\LOCAL",
                    languageCode,
                    D2Client_Quest_pQuestNameOverrides_6FB8EC54[questNameOverrideIndex].szName
                );
            }

        LABEL_54:
            auto finalCellFile = *D2Client_UI_pCellFileLevelTitle_6FBBA1E8;
            if (!finalCellFile)
            {
                finalCellFile = (D2CellFileStrc*)SStrChr(celFilePath, 0);
                *D2Client_UI_pCellFileLevelTitle_6FBBA1E8 = finalCellFile;
            }

            D2Win_DrawCellFile_10134(
                finalCellFile,
                *D2Client_pScreenWidthUI_6FB740EC / 2,
                *D2Client_pScreenHeightUI_6FB740F0 / 2 - 140,
                1,
                DRAWMODE_NORMAL,
                1
            );

            goto LABEL_57;
        }
    }
    else
    {
        pCellFile = *D2Client_UI_pCellFileLevelTitle_6FBBA1E8;
    }

    if (pCellFile)
    {
        D2Client_Archive_FreeCellFile_6FAA1140(pCellFile);
        *D2Client_UI_pCellFileLevelTitle_6FBBA1E8 = 0;
    }

LABEL_57:
    sub_6FADB890();
    if (D2Client_UIStates_6FBBA6A8[19]) // UI_HIRICONS
    {
        D2Client_DrawHiringIcon_sub_6FADAB00();
    }
    if (D2Client_UIStates_6FBBA6A8[36]) // UI_MERCINV
    {
        sub_6FAED5D0();
    }
    if (D2Client_UIStates_6FBBA6A8[37]) // UI_RECIPESCROLL
    {
        sub_6FAEE9C0();
    }
    if (D2Client_UIStates_6FBBA6A8[15]) // UI_QUESTSCREEN
    {
        sub_6FB042D0();
    }
    if (D2Client_UIStates_6FBBA6A8[1]      // UI_INVENTORY
        || D2Client_UIStates_6FBBA6A8[12]  // UI_NPCSHOP
        || D2Client_UIStates_6FBBA6A8[14]  // UI_ANVIL
        || D2Client_UIStates_6FBBA6A8[25]  // UI_STASH
        || D2Client_UIStates_6FBBA6A8[26]  // UI_CUBE
        || D2Client_UIStates_6FBBA6A8[28]  // UI_GUILDVAULT
        || D2Client_UIStates_6FBBA6A8[29]) // UI_UNKNOWN29
    {
        D2Client_DrawMerchantUi_sub_6FADEAC0();
    }

    if (D2Client_UIStates_6FBBA6A8[23]) // UI_MPTRADE
    {
        sub_6FB1F390();
        D2Client_DrawMerchantUi_sub_6FADEAC0();
    }

    sub_6FB21A00();

    if (D2Client_UIStates_6FBBA6A8[4]) // UI_SKILLTREE
    {
        sub_6FB16C00();
    }

    if (D2Client_UIStates_6FBBA6A8[2]) // UI_STATSCREEN
    {
        D2Client_DrawCharSheet_sub_6FACFD60();
    }

    if (D2Client_UIStates_6FBBA6A8[22]) // UI_PARTYSCREEN
    {
        sub_6FB01F10();
    }

    if (dword_6FBB9FC4)
    {
        sub_6FAD6EB0();
    }

    if (D2Client_UIStates_6FBBA6A8[16]) // UI_INISCROLL - Inifuss Tree Scroll
    {
        sub_6FB1E990();
    }

    if (D2Client_UIStates_6FBBA6A8[20]) // UI_WAYPOINT
    {
        sub_6FB25C70();
    }

    if (D2Client_UIStates_6FBBA6A8[33]) // UI_HELPSCREEN
    {
        sub_6FAD81F0();
        sub_6FAD82E0();
    }

    sub_6FAFF480();

    if (D2Client_UIStates_6FBBA6A8[3]) // UI_MINISKILL
    {
        sub_6FB19660();
    }

    if (D2Client_UIStates_6FBBA6A8[31]) // UI_BELTROWS
    {
        D2Client_OpenBeltUi_6FB01C20();
    }

    sub_6FAEEC00();

    if (D2Client_UIStates_6FBBA6A8[34]) // UI_HELPBUTTON
    {
        sub_6FADA350();
    }

    if (D2Client_UIStates_6FBBA6A8[6]) // UI_NEWSTATS
    {
        sub_6FAEF360();
    }
    else
    {
        sub_6FAEF2A0();
    }

    if (D2Client_UIStates_6FBBA6A8[7]) // UI_NEWSKILLS
    {
        sub_6FAEF730();
    }
    else
    {
        sub_6FAEF670();
    }

    if (D2Client_UIStates_6FBBA6A8[17]) // UI_QUESTLOG
    {
        sub_6FB065F0();
    }

    sub_6FAFF0B0();

    if (D2Client_UIStates_6FBBA6A8[21]) // UI_MINIPANEL - CtrlPnl7 Mini Popop Menu
    {
        sub_6FB08DE0();
    }

    if (D2Client_UIStates_6FBBA6A8[5]) // UI_CHATBOX
    {
        sub_6FAD2100();
    }

    if (D2Client_UIStates_6FBBA6A8[33]) // UI_HELPSCREEN
    {
        for (i = 0; i < 38; ++i)
        {
            if (D2Client_UIStates_6FBBA6A8[i] == 1 && dword_6FB700B0[i] == 1)
            {
                sub_6FB23260(i, 1u, 0);
                if (i == 25 || i == 1)
                    sub_6FAE8F10();
            }
        }
        sub_6FB23260(0x21u, 2u, 0);
        sub_6FAD8310();
    }

    if (D2Client_UIStates_6FBBA6A8[13]) // UI_HOLDALT
    {
        if (D2Client_GetOpenUiPanelMask_6FAB5750() != 3)
        {
            ESE_D2Client_DrawAllGroundItemTexts_6FB09F60();
            if (sub_6FAABFF0())
                sub_6FB29700((int (*)(void))sub_6FB22560);
        }
    }

    if (D2Client_UIStates_6FBBA6A8[8]) // UI_NPCMENU
    {
        sub_6FAF6070();
    }

    if (D2Client_UIStates_6FBBA6A8[14]) // UI_ANVIL
    {
        sub_6FB25320();
    }

    D2Client_UI_DrawHostilePlayerIndicator_6FAFE650();
    D2Client_UI_DrawNPCScrollingDialog_6FB1BA00(pRenderer);

    D2Win_10124();

    auto selectedUnit_2 = D2Client_GetSelectedUnit_6FAB5A20();
    if (selectedUnit_2 && selectedUnit_2->dwUnitType == UNIT_MONSTER)
    {
        auto fontHeight = D2Win_GetFontHeight_10125() + 39;

        D2Client_UI_DrawText_6FB22280(
            (const struct Unicode*)D2Client_pNormalMonsterInfoString256_6FBB9FE0,
            D2FONT_FONT6,
            fontHeight,
            *D2Client_pNormalMonsterInfoStringColor_6FBBA1E0
        );

        if (D2Client_pNormalMonsterInfoString256_6FBB9FE0[0] || (WORD)D2Client_pUniqueMonsterInfoString256_6FBBA2A0)
        {
            fontHeight += D2Win_GetFontHeight_10125();
        }

        D2Client_UI_DrawText_6FB22280(
            (const struct Unicode*)&D2Client_pMonsterImmunitiesInfoString256_6FBBA4A0,
            D2FONT_FONT6,
            fontHeight,
            *D2Client_pMonsterImmunitiesInfoStringColor_6FBBA6A0
        );
    }

    D2Client_UI_DrawMercFloatingText_6FB21970();

    if (Unicode::strlen((const struct Unicode*)&D2Client_pUniqueMonsterInfoString256_6FBBA2A0))
    {
        auto selectedUnit_1 = D2Client_GetSelectedUnit_6FAB5A20();
        if (selectedUnit_1)
        {
            if (selectedUnit_1->dwUnitType == UNIT_MONSTER)
            {
                auto fontColor = 0;
                if (D2Client_IsMonsterUnique_6FB40D00(selectedUnit_1))
                {
                    fontColor = 4;
                }

                if (D2Client_IsMonsterChampion_6FB40CC0(selectedUnit_1))
                {
                    fontColor = 3;
                }

                auto fontHeight = D2Win_GetFontHeight_10125();
                D2Client_UI_DrawText_6FB22280(
                    (const struct Unicode*)&D2Client_pUniqueMonsterInfoString256_6FBBA2A0,
                    D2FONT_FONT6,
                    fontHeight + 39,
                    fontColor
                );
            }
        }
    }

    if (D2Client_Roster_IsSortingByKillCount_6FAA6990())
    {
        auto currentPlayerUnit = D2Client_GetCurrentPlayer_6FB283D0();
        if (currentPlayerUnit)
        {
            auto currentPlayerRosterUnit = D2Client_Roster_FindUnitByIdOrCorpseId_6FAAFD60(currentPlayerUnit->dwUnitId);
            if (currentPlayerRosterUnit)
            {
                auto killCount = D2Client_Roster_GetKillCount_6FAAFD30(currentPlayerRosterUnit);
                auto killCountString = std::to_wstring(killCount);

                D2Win_DrawText_10117((const Unicode*)killCountString.c_str(), 600, 25, 4, 0);
            }
        }
    }

    D2Client_UI_DrawDeathScreen_6FB22320();
    D2Client_UI_DrawLordOfTerrorDiedMessage_6FABA4A0();
}

struct QuestNameOverride {
    int32_t nLevelId;
    int32_t nQuestId;
    char szName[4];
};