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

struct QuestNameOverride
{
    int32_t nLevelId;
    int32_t nQuestId;
    char szName[4];
};


void InitializeExternalModules()
{
    // External mod support
    auto d2glModule = GetModuleHandle("ddraw.dll");
    if (d2glModule == 0)
    {
        d2glModule = GetModuleHandle("glide3x.dll");
    }

    if (d2glModule != NULL)
    {
        D2GL_d2glConfigQueryImpl = (D2GL_d2glConfigQueryImpl_t)GetProcAddress(d2glModule, "d2glConfigQueryImpl");
        D2GL_setCustomScreenSize = (D2GL_setCustomScreenSize_t)GetProcAddress(d2glModule, "setCustomScreenSize");
        D2GL_d2glGameDrawBegin = (D2GL_d2glGameDrawBegin_t)GetProcAddress(d2glModule, "d2glGameDrawBegin");
        D2GL_d2glAutomapDrawBegin = (D2GL_d2glAutomapDrawBegin_t)GetProcAddress(d2glModule, "d2glAutomapDrawBegin");
        D2GL_d2glAutomapDrawEnd = (D2GL_d2glAutomapDrawEnd_t)GetProcAddress(d2glModule, "d2glAutomapDrawEnd");
        D2GL_d2glUIDrawBegin = (D2GL_d2glUIDrawBegin_t)GetProcAddress(d2glModule, "d2glUIDrawBegin");
        D2GL_d2glUIDrawCursorItem = (D2GL_d2glUIDrawCursorItem_t)GetProcAddress(d2glModule, "d2glUIDrawCursorItem");
        D2GL_d2glUIDrawEnd = (D2GL_d2glUIDrawEnd_t)GetProcAddress(d2glModule, "d2glUIDrawEnd");
        D2GL_d2glDrawPerspectiveImage = (D2GL_d2glDrawPerspectiveImage_t)GetProcAddress(d2glModule, "d2glDrawPerspectiveImage");
        D2GL_d2glDrawShiftedImage = (D2GL_d2glDrawShiftedImage_t)GetProcAddress(d2glModule, "d2glDrawShiftedImage");
        D2GL_d2glDrawClippedImage = (D2GL_d2glDrawClippedImage_t)GetProcAddress(d2glModule, "d2glDrawClippedImage");
        D2GL_d2glDrawImageFast = (D2GL_d2glDrawImageFast_t)GetProcAddress(d2glModule, "d2glDrawImageFast");
        D2GL_d2glDrawShadow = (D2GL_d2glDrawShadow_t)GetProcAddress(d2glModule, "d2glDrawShadow");
        D2GL_d2glTakeScreenShot = (D2GL_d2glTakeScreenShot_t)GetProcAddress(d2glModule, "d2glTakeScreenShot");
        D2GL_d2glRectangledTextBegin = (D2GL_d2glRectangledTextBegin_t)GetProcAddress(d2glModule, "d2glRectangledTextBegin");
        D2GL_d2glRectangledTextEnd = (D2GL_d2glRectangledTextEnd_t)GetProcAddress(d2glModule, "d2glRectangledTextEnd");
        D2GL_d2glUnitHoverText = (D2GL_d2glUnitHoverText_t)GetProcAddress(d2glModule, "d2glUnitHoverText");
        D2GL_d2glDrawRectFrame = (D2GL_d2glDrawRectFrame_t)GetProcAddress(d2glModule, "d2glDrawRectFrame");
        D2GL_d2glDrawUnitHealthBar = (D2GL_d2glDrawUnitHealthBar_t)GetProcAddress(d2glModule, "d2glDrawUnitHealthBar");
        D2GL_d2glLoadUIImage = (D2GL_d2glLoadUIImage_t)GetProcAddress(d2glModule, "d2glLoadUIImage");
        D2GL_d2glDrawSubTextA = (D2GL_d2glDrawSubTextA_t)GetProcAddress(d2glModule, "d2glDrawSubTextA");
        D2GL_d2glDrawSubTextB = (D2GL_d2glDrawSubTextB_t)GetProcAddress(d2glModule, "d2glDrawSubTextB");
        D2GL_d2glDrawSubTextC = (D2GL_d2glDrawSubTextC_t)GetProcAddress(d2glModule, "d2glDrawSubTextC");
        D2GL_d2glDrawImage = (D2GL_d2glDrawImage_t)GetProcAddress(d2glModule, "d2glDrawImage");
        D2GL_d2glDrawVerticalCropImage = (D2GL_d2glDrawVerticalCropImage_t)GetProcAddress(d2glModule, "d2glDrawVerticalCropImage");
        D2GL_d2glDrawSolidRectEx = (D2GL_d2glDrawSolidRectEx_t)GetProcAddress(d2glModule, "d2glDrawSolidRectEx");
        D2GL_d2glDrawLine = (D2GL_d2glDrawLine_t)GetProcAddress(d2glModule, "d2glDrawLine");
        D2GL_d2glDrawGroundTile = (D2GL_d2glDrawGroundTile_t)GetProcAddress(d2glModule, "d2glDrawGroundTile");
        D2GL_d2glDrawWallTile = (D2GL_d2glDrawWallTile_t)GetProcAddress(d2glModule, "d2glDrawWallTile");
        D2GL_d2glDrawTransWallTile = (D2GL_d2glDrawTransWallTile_t)GetProcAddress(d2glModule, "d2glDrawTransWallTile");
        D2GL_d2glDrawShadowTile = (D2GL_d2glDrawShadowTile_t)GetProcAddress(d2glModule, "d2glDrawShadowTile");
        D2GL_d2glDrawNormalText = (D2GL_d2glDrawNormalText_t)GetProcAddress(d2glModule, "d2glDrawNormalText");
        D2GL_d2glDrawNormalTextEx = (D2GL_d2glDrawNormalTextEx_t)GetProcAddress(d2glModule, "d2glDrawNormalTextEx");
        D2GL_d2glDrawFramedText = (D2GL_d2glDrawFramedText_t)GetProcAddress(d2glModule, "d2glDrawFramedText");
        D2GL_d2glDrawRectangledText = (D2GL_d2glDrawRectangledText_t)GetProcAddress(d2glModule, "d2glDrawRectangledText");
        D2GL_d2glGetNormalTextWidth = (D2GL_d2glGetNormalTextWidth_t)GetProcAddress(d2glModule, "d2glGetNormalTextWidth");
        D2GL_d2glGetNormalTextNWidth = (D2GL_d2glGetNormalTextNWidth_t)GetProcAddress(d2glModule, "d2glGetNormalTextNWidth");
        D2GL_d2glGetFramedTextSize = (D2GL_d2glGetFramedTextSize_t)GetProcAddress(d2glModule, "d2glGetFramedTextSize");
        D2GL_d2glGetFontHeight = (D2GL_d2glGetFontHeight_t)GetProcAddress(d2glModule, "d2glGetFontHeight");
        D2GL_d2glSetTextSize = (D2GL_d2glSetTextSize_t)GetProcAddress(d2glModule, "d2glSetTextSize");
        D2GL_d2glAltItemsText = (D2GL_d2glAltItemsText_t)GetProcAddress(d2glModule, "d2glAltItemsText");
        D2GL_d2glLevelEntryText = (D2GL_d2glLevelEntryText_t)GetProcAddress(d2glModule, "d2glLevelEntryText");
    }

    auto sgd2Module = GetModuleHandle("SGD2FreeRes.dll");
    if (sgd2Module != NULL)
    {
        Sgd2fr_D2Client_DrawScreenBackground = (Sgd2fr_D2Client_DrawScreenBackground_t)GetProcAddress(sgd2Module, "Sgd2fr_D2Client_DrawScreenBackground");
        Sgd2fr_D2Client_SetScreenShift = (Sgd2fr_D2Client_SetScreenShift_t)GetProcAddress(sgd2Module, "Sgd2fr_D2Client_SetScreenShift");
    }
}

static void RenderMercenaryUI(D2UnitStrc* currentPlayerMerc)
{
    if (!D2Gfx_CheckPerspective_10010())
    {
        auto currentPlayerMercUIPosX = UNITS_GetClientCoordX(currentPlayerMerc);
        *D2Client_pUnitMouseOverTextPosX_6FB8EA28 = currentPlayerMercUIPosX - D2Client_GetAdjustedViewOffsetX_6FAB5890();

        auto currentPlayerMercUIPosY = UNITS_GetClientCoordY(currentPlayerMerc);
        *D2Client_pUnitMouseOverTextPosY_6FB8EA2C = currentPlayerMercUIPosY - D2Client_GetAdjustedViewOffsetY_6FAB58A0();
    }
    else
    {
        auto currentPlayerMercPrecisionX = UNITS_GetPrecisionX(currentPlayerMerc);
        auto currentPlayerMercPrecisionY = UNITS_GetPrecisionY(currentPlayerMerc);

        if (!D2Gfx_SCALE_CheckPerspectivePosition_10065(currentPlayerMercPrecisionX, currentPlayerMercPrecisionY))
        {
            return;
        }

        int32_t yAdjust = 0;
        int32_t xAdjust = 0;

        D2Gfx_SCALE_AdjustPerspectivePosition_10066(
            currentPlayerMercPrecisionX,
            currentPlayerMercPrecisionY,
            0,
            &xAdjust,
            &yAdjust
        );

        int32_t screenXAdjust = 0;
        int32_t screenYAdjust = D2Client_UI_GetGlobalUiState_6FAB5750() - 1;

        if (screenYAdjust == 0)
        {
            screenXAdjust = *D2Client_pResolutionWidth_6FB740EC / -4;
        }
        else if (screenYAdjust == 1)
        {
            screenXAdjust = *D2Client_pResolutionWidth_6FB740EC / 4;
        }

        xAdjust += screenXAdjust;
        *D2Client_pUnitMouseOverTextPosX_6FB8EA28 = xAdjust;
        *D2Client_pUnitMouseOverTextPosY_6FB8EA2C = yAdjust + 16;
    }

    int32_t tempActiveNpcId = 0;
    auto pTempActiveNpcId = &tempActiveNpcId;
    if (!D2Client_IsActiveNpcDialogOpen_6FAFBB50(&pTempActiveNpcId))
    {
        auto lifeColor = D2Client_GetMonsterLifeColor_6FB20670(currentPlayerMerc);
        auto posY = *D2Client_pUnitMouseOverTextPosY_6FB8EA2C - 72;
        auto unitName = D2Client_GetUnitName_6FB297F0(currentPlayerMerc);
        D2Client_UI_UpdateMercFloatingText_6FB20590(unitName, *D2Client_pUnitMouseOverTextPosX_6FB8EA28, posY, lifeColor);
    }
}

static void DrawLevelTitle(int32_t currentLevelId, int32_t newLevelTickCount)
{
    *D2Client_UI_pNewLevelTickCount120_6FBBA788 = newLevelTickCount + 1;

    auto currentLevelTxt = DATATBLS_GetLevelsTxtRecord(currentLevelId);
    char actDirectoryName[32];

    if (currentLevelId < 109)
    {
        auto actNumber = DRLG_GetActNoFromLevelId(currentLevelId);
        sprintf(actDirectoryName, "ACT%d", actNumber + 1);
    }
    else
    {
        sprintf(actDirectoryName, "EXPANSION");
    }

    char celFilePath[MAX_PATH];
    char languageCode[4];
    D2Lang_10006(&languageCode[0], 0);
    sprintf(celFilePath, "%s\\UI\\%s\\%s\\%s", "DATA\\LOCAL", languageCode, actDirectoryName, currentLevelTxt->szEntryFile);

    // Try to find quest name override
    int32_t questNameOverrideIndex = 0;
    if (*D2Client_Quest_pQuestNameOverridesCount_6FB8EC70 > 0)
    {
        auto questNameOverride = D2Client_Quest_pQuestNameOverrides_6FB8EC54;
        while (questNameOverrideIndex < *D2Client_Quest_pQuestNameOverridesCount_6FB8EC70)
        {
            if (currentLevelId == questNameOverride->nLevelId && D2Client_10002(0, questNameOverride->nQuestId))
            {
                sprintf(
                    celFilePath,
                    "%s\\UI\\%s\\ACT1\\%s",
                    "DATA\\LOCAL",
                    languageCode,
                    D2Client_Quest_pQuestNameOverrides_6FB8EC54[questNameOverrideIndex].szName
                );
                break;
            }

            ++questNameOverrideIndex;
            ++questNameOverride;
        }
    }

    auto finalCellFile = *D2Client_UI_pCellFileLevelTitle_6FBBA1E8;
    if (!finalCellFile)
    {
        finalCellFile = D2Client_LoadCelFile_6FAA1000(celFilePath, 0);
        *D2Client_UI_pCellFileLevelTitle_6FBBA1E8 = finalCellFile;
    }

    // ESE HACK:    D2GL -> levelEntryTextStub -> modules::HDText::Instance().startEntryText(); 
    if (D2GL_d2glLevelEntryText != nullptr)
    {
        D2GL_d2glLevelEntryText();
    }

    D2Win_DrawCellFile_10134(
        finalCellFile,
        *D2Client_pResolutionWidth_6FB740EC / 2,
        *D2Client_pResolutionHeight_6FB740F0 / 2 - 140,
        1,
        DRAWMODE_NORMAL,
        1
    );
}

static void HandleLevelTitleRendering()
{
    D2CellFileStrc* pCellFile = nullptr;
    int32_t newLevelTickCount = 0;
    bool shouldDrawTitle = false;

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
            D2Client_UI_UpdateRosterHealthColors_6FADA970(true);

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
            DrawLevelTitle(currentLevelId, newLevelTickCount);
            shouldDrawTitle = true;
        }
    }
    else
    {
        pCellFile = *D2Client_UI_pCellFileLevelTitle_6FBBA1E8;
    }

    if (!shouldDrawTitle && pCellFile)
    {
        D2Client_Archive_FreeCellFile_6FAA1140(pCellFile);
        *D2Client_UI_pCellFileLevelTitle_6FBBA1E8 = 0;
    }
}

void __fastcall ESE_D2Client_RenderUI_6FB21B70(D2ViewStruct* pRenderer)
{
    static bool InitializedModules = false;
    if (!InitializedModules)
    {
        InitializeExternalModules();
        InitializedModules = true;
    }

    // ESE HACK: D2GL -> uiDrawBeginStub -> uiDrawBegin()
    if (D2GL_d2glUIDrawBegin != nullptr)
    {
        D2GL_d2glUIDrawBegin();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_UNKNOWN18])
    {
        return;
    }

    // ESE HACK: SGD2 -> Sgd2fr_D2Client_SetScreenShift (This should probably just be done in this codebase, it's just managing the offsets)
    if (Sgd2fr_D2Client_SetScreenShift != nullptr)
    {
        Sgd2fr_D2Client_SetScreenShift();
    }
    else
    {
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
    }

    D2Win_DrawFramedText_10129(0, 0, 0, 0, 0);
    D2Client_pNormalMonsterInfoString256_6FBB9FE0[0] = 0;
    D2Client_pMonsterImmunitiesInfoString256_6FBBA4A0[0] = 0;

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_ESCMENU])
    {
        D2Client_UI_DrawEscapeMenu_6FB088B0();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_CONFIG])
    {
        D2Client_UI_DrawConfigMenu_6FAFC620();
    }

    auto selectedUnit = D2Client_GetSelectedUnit_6FAB5A20();
    ESE_D2Client_DrawGroundItemMouseOverText_6FB20A30(selectedUnit);

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_HIREICONS])
    {
        if (D2Client_UI_GetGlobalUiState_6FAB5750() != UISTATE_BOTH)
        {
            auto currentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
            auto currentPlayerMercId = D2Client_Roster_GetPetByUnitIdType_6FAB1920(currentPlayer, PETTYPE_HIREABLE, 0);
            if (currentPlayerMercId != -1 && ((uint8_t*)D2Client_Roster_GetPetUNK24_6FAB18D0(currentPlayerMercId))[2] == 1)
            {
                auto currentPlayerMerc = D2Client_FindUnit_6FB269F0(currentPlayerMercId, UNIT_MONSTER);
                if (currentPlayerMerc)
                {
                    RenderMercenaryUI(currentPlayerMerc);
                }
            }
        }
    }

    if (!D2Client_UI_pUIStates_6FBBA6A8[UI_INVENTORY] &&
        !D2Client_UI_pUIStates_6FBBA6A8[UI_NPCSHOP] &&
        !D2Client_UI_pUIStates_6FBBA6A8[UI_ANVIL])
    {
        D2Client_UI_DrawDurabilityWarning_6FAFEE70();
        D2Client_UI_DrawAmmoDurability_6FAFEA40();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_AUTOMAP] && D2Client_UI_GetGlobalUiState_6FAB5750() != UISTATE_BOTH)
    {
        D2Client_UI_DrawAutomap_6FACDCB0();

        // ESE HACK: D2GL -> automapDrawEndStub -> automapDrawEnd() -> "HUD" draw stage
        if (D2GL_d2glAutomapDrawEnd != nullptr)
        {
            D2GL_d2glAutomapDrawEnd();
        }
    }

    HandleLevelTitleRendering();

    // ESE HACK: SGD2FreeRes -> sgd2freeres._Sgd2fr_D2Client_DrawScreenBackground>
    if (Sgd2fr_D2Client_DrawScreenBackground != nullptr)
    {
        // Sgd2fr_D2Client_DrawScreenBackground calls D2Client_UI_UpdateHirePartyIconsVisibility_6FADB890 for us
        Sgd2fr_D2Client_DrawScreenBackground();
    }
    else
    {
        D2Client_UI_UpdateHirePartyIconsVisibility_6FADB890();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_HIRICONS])
    {
        D2Client_UI_DrawPartyMemberIcons_6FADAB00();
    }
    if (D2Client_UI_pUIStates_6FBBA6A8[UI_MERCINV])
    {
        D2Client_UI_DrawMercInventoryScreen_6FAED5D0();
    }
    if (D2Client_UI_pUIStates_6FBBA6A8[UI_RECIPESCROLL])
    {
        D2Client_UI_DrawRecipeScrollScreen_6FAEE9C0();
    }
    if (D2Client_UI_pUIStates_6FBBA6A8[UI_QUESTSCREEN])
    {
        D2Client_UI_DrawQuestScreen_6FB042D0();
    }
    if (D2Client_UI_pUIStates_6FBBA6A8[UI_INVENTORY]
        || D2Client_UI_pUIStates_6FBBA6A8[UI_NPCSHOP]
        || D2Client_UI_pUIStates_6FBBA6A8[UI_ANVIL]
        || D2Client_UI_pUIStates_6FBBA6A8[UI_STASH]
        || D2Client_UI_pUIStates_6FBBA6A8[UI_CUBE]
        || D2Client_UI_pUIStates_6FBBA6A8[UI_GUILDVAULT]
        || D2Client_UI_pUIStates_6FBBA6A8[UI_UNKNOWN29])
    {
        D2Client_UI_DrawInventoryScreen_6FADEAC0();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_MPTRADE])
    {
        D2Client_UI_DrawPlayerTradeButtonHoverText_6FB1F390();
        D2Client_UI_DrawInventoryScreen_6FADEAC0();
    }

    D2Client_UI_DrawProgressiveStates_6FB21A00();

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_SKILLTREE])
    {
        D2Client_UI_DrawSkillsTree_6FB16C00();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_STATSCREEN])
    {
        D2Client_UI_DrawCharacterStatsScreen_6FACFD60();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_PARTYSCREEN])
    {
        D2Client_UI_DrawPartyScreen_6FB01F10();
    }

    if (*D2Client_UI_pGoldTransferDialog_6FBB9FC4)
    {
        D2Client_UI_DrawDialog_6FAD6EB0(*D2Client_UI_pGoldTransferDialog_6FBB9FC4);
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_INISCROLL])
    {
        D2Client_UI_DrawInifussScrollPanel_6FB1E990();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_WAYPOINT])
    {
        D2Client_UI_DrawWaypointScreen_6FB25C70();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_HELPSCREEN])
    {
        D2Client_UI_DrawHelpScreenBorder_6FAD81F0();
        D2Client_UI_DrawHelpScreenBackground_6FAD82E0();
    }

    D2Client_UI_DrawBackground_6FAFF480();

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_MINISKILL])
    {
        D2Client_UI_DrawMiniSkills_6FB19660();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_BELTROWS])
    {
        D2Client_UI_DrawBeltRows_6FB01C20();
    }

    D2Client_UI_RefreshUIState_6FAEEC00();

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_HELPBUTTON])
    {
        D2Client_UI_DrawHelpButton_6FADA350();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_NEWSTATS])
    {
        D2Client_UI_DrawNewStatsButton_6FAEF360();
    }
    else
    {
        D2Client_UI_DrawStatsButton_6FAEF2A0();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_NEWSKILLS])
    {
        D2Client_UI_DrawNewSkillsButton_6FAEF730();
    }
    else
    {
        D2Client_UI_DrawSkillsButton_6FAEF670();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_QUESTLOG])
    {
        D2Client_UI_DrawQuestLogButton_6FB065F0();
    }

    D2Client_UI_DrawLifeAndManaOrbText_6FAFF0B0();

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_MINIPANEL])
    {
        D2Client_UI_DrawMiniPanel_6FB08DE0();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_CHATBOX])
    {
        D2Client_UI_DrawChatBox_6FAD2100();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_HELPSCREEN])
    {
        for (auto i = 0; i < 38; ++i)
        {
            if (D2Client_UI_pUIStates_6FBBA6A8[i] == 1 && D2Client_UI_pUIStatesIncompatibleWithHelpScreen_6FBBA6A8[i] == 1)
            {
                D2Client_UI_SetUIState_6FB23260((D2C_UIvars)i, UI_TURNOFF, 0);
                if (i == UI_STASH || i == UI_INVENTORY)
                {
                    D2Client_ClearItemUnderCursorInfo_6FAE8F10();
                }
            }
        }

        D2Client_UI_SetUIState_6FB23260(UI_HELPSCREEN, UI_TOGGLE, 0);
        D2Client_UI_DrawHelpScreen_6FAD8310();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_HOLDALT])
    {
        if (D2Client_UI_GetGlobalUiState_6FAB5750() != UISTATE_BOTH)
        {
            ESE_D2Client_DrawAllGroundItemTexts_6FB09F60();
            if (D2Client_GetGameType_6FAABFF0())
            {
                D2Client_Unit_EnumUnits_6FB29700(D2Client_UI_EnumUnitsCallback_6FB22560);
            }
        }
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_NPCMENU])
    {
        D2Client_UI_DrawNpcMenu_6FAF6070();
    }

    if (D2Client_UI_pUIStates_6FBBA6A8[UI_ANVIL])
    {
        D2Client_UI_DrawAnvilScreen_6FB25320();
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

        if (D2Client_pNormalMonsterInfoString256_6FBB9FE0[0] || D2Client_pUniqueMonsterInfoString256_6FBBA2A0[0])
        {
            fontHeight += D2Win_GetFontHeight_10125();
        }

        D2Client_UI_DrawText_6FB22280(
            (const struct Unicode*)D2Client_pMonsterImmunitiesInfoString256_6FBBA4A0,
            D2FONT_FONT6,
            fontHeight,
            *D2Client_pMonsterImmunitiesInfoStringColor_6FBBA6A0
        );
    }

    D2Client_UI_DrawMercFloatingText_6FB21970();
    if (wcslen(D2Client_pUniqueMonsterInfoString256_6FBBA2A0))
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
                    (const struct Unicode*)D2Client_pUniqueMonsterInfoString256_6FBBA2A0,
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

    // TODO: Draw buff icons
}

