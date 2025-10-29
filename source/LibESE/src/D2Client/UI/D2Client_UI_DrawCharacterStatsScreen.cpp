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
#include <DataTbls/StringIds.h>

#pragma pack(push, 1)

#define NUM_CHARSHEETTEXTENTRIES 15
#define NUM_CHARSHEETBUTTONLOCATIONS 4
#define NUM_CHARSHEETSTATROWS 18

struct D2CharSheetButtonLocations
{
  int x;
  int y;
  int state;
  uint16_t statId;
};

struct D2CharSheetStatRow
{
  int32_t xLeft;
  int32_t y;
  int32_t xRight;
  D2C_ItemStats statId;
};

struct D2CharSheetTextEntry
{
  int32_t xLeft;
  int32_t y;
  int32_t xRight;
  D2C_StringIndices strId;
  uint32_t strLen;
};

struct D2CharSheetToHitTextLocation
{
  int32_t BoxX;
  int32_t BoxY;
  int32_t Line1X;
  int32_t Line1Y;
  int32_t Line2X;
  int32_t Line2Y;
};

#pragma pack(pop)

typedef void(__fastcall* D2SkillDescAttCallback_t)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int*, int*, int*, int*);


void __fastcall ESE_D2Client_UI_DrawCharacterStatsScreen_6FACFD60()
{
    auto currentPlayer = D2Client_GetCurrentPlayer_6FB283D0();
    D2GfxDataStrc pData = {};
    int32_t nColor = 0;

    pData.pCellFile = *D2Client_UI_pCelFile_UiInvChar_6FBB5E24;
    pData.nDirection = 0;
    pData.nFrame = 0;
    D2Gfx_TEXTURE_CelDraw_10072(&pData, *D2Client_pScreenXOffset_6FBBA748, *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 224, 0xFFFFFFFF, DRAWMODE_NORMAL, 0);
    pData.nFrame = 1;
    D2Gfx_TEXTURE_CelDraw_10072(&pData, *D2Client_pScreenXOffset_6FBBA748 + 256, *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 224, 0xFFFFFFFF, DRAWMODE_NORMAL, 0);
    pData.nFrame = 2;
    D2Gfx_TEXTURE_CelDraw_10072(&pData, *D2Client_pScreenXOffset_6FBBA748, *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 48, 0xFFFFFFFF, DRAWMODE_NORMAL, 0);
    pData.nFrame = 3;
    D2Gfx_TEXTURE_CelDraw_10072(&pData, *D2Client_pScreenXOffset_6FBBA748 + 256, *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 48, 0xFFFFFFFF, DRAWMODE_NORMAL, 0);

    auto mousePosX = D2Client_UI_GetMouseXPos_6FB57BC0();
    auto mousePosY = D2Client_UI_GetMouseYPos_6FB57BD0();

    if (mousePosX >= *D2Client_pScreenXOffset_6FBBA748 + 128
        && mousePosX <= *D2Client_pScreenXOffset_6FBBA748 + 160
        && mousePosY >= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 92
        && mousePosY <= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 60)
    {
        auto strIdxStrClose = D2LANG_GetStringFromTblIndex(STR_IDX_4144_strClose);
        D2Win_DrawFramedText_10129(
            strIdxStrClose,
            *D2Client_pScreenXOffset_6FBBA748 + 143,
            *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 95,
            0,
            1
        );
    }

    if (STATLIST_GetUnitBaseStat(currentPlayer, STAT_STATPTS, 0))
    {
        pData.pCellFile = *D2Client_UI_pCelFile_PanelSkillPoints_6FBB5E50;
        pData.nFrame = 0;
        D2Gfx_TEXTURE_CelDraw_10072(&pData, *D2Client_pScreenXOffset_6FBBA748 + 3, *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 116, 0xFFFFFFFF, DRAWMODE_NORMAL, 0);
        
        wchar_t v135[10 * 2] = {0};

        D2Win_SetFont_10127(D2FONT_FONT6);

        auto strChrStat = D2LANG_GetStringFromTblIndex(STR_IDX_4075_strchrstat);
        auto strChrStatY = *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 125;
        auto strChrStatX = *D2Client_pScreenXOffset_6FBBA748 + 11;
        auto strChrStatWidth = D2Win_GetTextWidth_10121(strChrStat);
        if (strChrStatWidth < 78)
        {
            strChrStatX += (78 - strChrStatWidth) >> 1;
        }
        D2Win_DrawText_10117(strChrStat, strChrStatX, strChrStatY, 1, 0);

        auto strChrRema = D2LANG_GetStringFromTblIndex(STR_IDX_4076_strchrrema);
        auto strChrRemaY = *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 117;
        auto strChrRemaX = *D2Client_pScreenXOffset_6FBBA748 + 11;
        auto strChrRemaWidth = D2Win_GetTextWidth_10121(strChrRema);
        if (strChrRemaWidth < 78)
        {
            strChrRemaX += (78 - strChrRemaWidth) >> 1;
        }
        D2Win_DrawText_10117(strChrRema, strChrRemaX, strChrRemaY, 1, 0);


        auto UnitBaseStat = STATLIST_GetUnitBaseStat(currentPlayer, STAT_STATPTS, 0);
        swprintf_s(v135, L"%i", UnitBaseStat);

        D2Win_SetFont_10127(D2FONT_FONT16);

        auto statPtsValueY = *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 120;
        auto statPtsValueX = *D2Client_pScreenXOffset_6FBBA748 + 92;
        auto statPtsValueWidth = D2Win_GetTextWidth_10121((const Unicode*)v135);
        if (statPtsValueWidth < 36)
        {
            statPtsValueX += (36 - statPtsValueWidth) >> 1;
        }
        D2Win_DrawText_10117((const Unicode*)v135, statPtsValueX, statPtsValueY, 0, 0);
    }

    if (STATLIST_GetUnitBaseStat(currentPlayer, STAT_STATPTS, 0))
    {
        for (auto i = 0; i < NUM_CHARSHEETBUTTONLOCATIONS; ++i)
        {
            const auto buttonLocationIter = &(*D2Client_UI_pD2CharSheetButtonLocations_6FB78240)[i];

            auto buttonXLeft = buttonLocationIter->x;
            auto buttonY = *D2Client_pScreenYOffset_6FBBA74C + buttonLocationIter->y;
            auto buttonFinalY = buttonY + *D2Client_pResolutionHeight_6FB740F0 - 480;
            auto buttonFinalX = *D2Client_pScreenXOffset_6FBBA748 + buttonXLeft;

            pData.pCellFile = *D2Client_UI_pCelFilePanelLevelSocket_6FBB5BB8;
            pData.nFrame = 0;
            D2Gfx_TEXTURE_CelDraw_10072(&pData, buttonFinalX + 5, buttonFinalY + 5, 0xFFFFFFFF, DRAWMODE_NORMAL, 0);

            pData.pCellFile = *D2Client_UI_pCelFilePanelLevel_6FBB5BB4;
            pData.nFrame = buttonLocationIter->state != 0;
            D2Gfx_TEXTURE_CelDraw_10072(&pData, buttonFinalX + 8, buttonFinalY + 1, 0xFFFFFFFF, DRAWMODE_NORMAL, 0);
        }
    }

    D2Win_SetFont_10127(D2FONT_FONT6);

    for (auto i = 0; i < NUM_CHARSHEETTEXTENTRIES; ++i)
    {
        const auto charSheetTextEntryIter = &(*D2Client_UI_pCharSheetTextEntries_6FB78010)[i];

        wchar_t text[100] = {};

        auto v28 = D2LANG_GetStringFromTblIndex(charSheetTextEntryIter->strId);
        Unicode::strncpy((struct Unicode*)text, v28, 99);

        auto textXLeft = *D2Client_pScreenXOffset_6FBBA748 + charSheetTextEntryIter->xLeft;
        auto textXRight = *D2Client_pScreenXOffset_6FBBA748 + charSheetTextEntryIter->xRight;
        auto textY = *D2Client_pScreenYOffset_6FBBA74C + charSheetTextEntryIter->y;
        auto textWidth = textXRight - textXLeft + 1;

        text[99] = 0;

        auto textFinalY = textY + *D2Client_pResolutionHeight_6FB740F0 - 480;
        auto textLength = Unicode::strlen((const struct Unicode*)text);

        int newlinePos = -1;
        for (int j = 0; j < textLength && text[j] != 0; ++j)
        {
            if (text[j] == L'\n')
            {
                newlinePos = j;
                text[newlinePos] = 0;
                break;
            }
        }

        if (newlinePos < textLength)
        {
            auto secondLineText = (Unicode*)(newlinePos + 1);

            auto firstLineWidth = D2Win_GetTextWidth_10121((const Unicode*)text);
            auto firstLineX = textXLeft;
            if (firstLineWidth < textWidth)
            {
                firstLineX += ((textWidth - firstLineWidth) >> 1);
            }
            D2Win_DrawText_10117((const Unicode*)text, firstLineX, textFinalY - 4, 0, 0);

            auto secondLineWidth = D2Win_GetTextWidth_10121(secondLineText);
            auto secondLineX = textXLeft;
            if (secondLineWidth < textWidth)
            {
                secondLineX += (textWidth - secondLineWidth) >> 1;
            }
            D2Win_DrawText_10117(secondLineText, secondLineX, textFinalY + 4, 0, 0);
        }
        else
        {
            auto singleLineWidth = D2Win_GetTextWidth_10121((const Unicode*)text);
            if (singleLineWidth < textWidth)
            {
                textXLeft += (textWidth - singleLineWidth) >> 1;
            }
            D2Win_DrawText_10117((const Unicode*)text, textXLeft, textFinalY, 0, 0);
        }
    }

    D2Client_UI_DrawLeftRightSkillDescs_6FB16190(currentPlayer);
    D2Win_SetFont_10127(D2FONT_FONT8);
    auto skillLeftToHit = D2Client_GetSkillDescAtt_6FB16200(currentPlayer, 1);
    auto finalToHitLeft = D2Client_UI_GetChanceToHitMonster_6FAD10D0(skillLeftToHit);
    auto skillRightToHit = D2Client_GetSkillDescAtt_6FB16200(currentPlayer, 0);
    auto finalToHitRight = D2Client_UI_GetChanceToHitMonster_6FAD10D0(skillRightToHit);
    auto currentPlayerDefense = UNITS_GetDefense((D2UnitStrc*)currentPlayer);
    auto currentPlayerAC = STATLIST_UnitGetStatValue((const D2UnitStrc*)currentPlayer, STAT_ARMORCLASS_VS_HTH, 0) + currentPlayerDefense;
    auto nDifficultyLevel = D2Client_GetCurrentDifficulty_6FAAC090();
    if (nDifficultyLevel >= 3)
    {
        FOG_DisplayAssert("nDifficultyLevel < NUM_DIFFICULTY_LEVELS", "C:\\projects\\D2\\head\\Diablo2\\Source\\D2Client\\UI\\char.cpp", 470);
        exit(-1);
    }

    auto lastSelectedMonsterClassId = D2Client_Unit_GetLastSelectedEvilMonsterClassId_6FAB5A80();
    auto finalMonsterToHitPercentage = 0;

    if (lastSelectedMonsterClassId >= 0 && lastSelectedMonsterClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        auto monStatsTxt = &sgptDataTables->pMonStatsTxt[lastSelectedMonsterClassId];
        if (monStatsTxt)
        {
            D2MonStatsInitStrc pMonStatsInit = {0};

            auto monsterLevel = (__int16)monStatsTxt->nLevel[nDifficultyLevel];
            auto gameType = D2Client_GetGameTypeButModified_6FAAC060();

            DATATBLS_CalculateMonsterStatsByLevel(lastSelectedMonsterClassId, gameType, nDifficultyLevel, monsterLevel, 8, &pMonStatsInit);
            auto monsterToHit = pMonStatsInit.nTH;

            if (!pMonStatsInit.nTH)
            {
                memset(&pMonStatsInit, 0, sizeof(pMonStatsInit));
                DATATBLS_CalculateMonsterStatsByLevel(lastSelectedMonsterClassId, gameType, nDifficultyLevel, monsterLevel, 16, &pMonStatsInit);
                monsterToHit = pMonStatsInit.nTH;

                if (!pMonStatsInit.nTH)
                {
                    memset(&pMonStatsInit, 0, sizeof(pMonStatsInit));
                    DATATBLS_CalculateMonsterStatsByLevel(lastSelectedMonsterClassId, gameType, nDifficultyLevel, monsterLevel, 32, &pMonStatsInit);
                    monsterToHit = pMonStatsInit.nTH;
                }
            }
            if (monStatsTxt->nAlign != 1 && !D2Client_IsExpansion_6FAAC080() && D2Client_GetCurrentDifficulty_6FAAC090())
            {
                monsterToHit = 10 * monsterToHit / 15;
            }

            auto modifiedPlayerAC = currentPlayerAC;

            if (currentPlayerAC < 0)
            {
                monsterToHit -= currentPlayerAC;
                modifiedPlayerAC = 0;
            }

            if (monsterToHit > 0)
            {
                monsterToHit = 100 * monsterToHit / (monsterToHit + modifiedPlayerAC);
            }
            else
            {
                if(monsterToHit < 0)
                {
                    modifiedPlayerAC += -monsterToHit;
                    monsterToHit = 0;
                }

                if (modifiedPlayerAC == 0)
                {
                    monsterToHit = 100;
                }
                else
                {
                    monsterToHit = 100 * monsterToHit / (monsterToHit + modifiedPlayerAC);
                }
            }

            finalMonsterToHitPercentage = 2 * monsterToHit * monsterLevel / (monsterLevel + STATLIST_UnitGetStatValue((const D2UnitStrc*)currentPlayer, STAT_LEVEL, 0));
        }
        else
        {
            finalMonsterToHitPercentage = 0;
        }
    }
    else
    {
        finalMonsterToHitPercentage = 0;
    }

    D2Client_UI_SetUnknownColorToBlack_6FB01C50();
    auto v58 = 0;
    auto v59 = 0;

    if (mousePosX >= *D2Client_pScreenXOffset_6FBBA748 + 162 && 
        mousePosX <= *D2Client_pScreenXOffset_6FBBA748 + 320 && 
        mousePosY >= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 334 &&
        mousePosY <= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 315)
    {
        v58 = 1;
    }
    else if (mousePosX >= *D2Client_pScreenXOffset_6FBBA748 + 162 && 
        mousePosX <= *D2Client_pScreenXOffset_6FBBA748 + 320 && 
        mousePosY >= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 308 &&
        mousePosY <= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 289)
    {
        v59 = 1;
    }

    auto v62 = 0;
    auto v61 = finalToHitLeft;

    if (!finalToHitLeft)
    {
        v58 = 0;
    }

    if (!finalToHitRight)
    {
        v59 = 0;
    }

    if (v58 || v59)
    {
        if (v58)
        {
            v62 = 0;
        }
        else
        {
            v62 = 1;
            v61 = finalToHitRight;
        }

        if (v61 >= 5)
        {
            if (v61 > 95)
            {
                v61 = 95;
            }
        }
        else
        {
            v61 = 5;
        }

        auto unknownIndex = 6 * v62;

        D2Gfx_DrawBox_10055(
            *D2Client_pScreenXOffset_6FBBA748 + (*D2Client_UI_pCharSheetToHitTextLocation_6FB6EF00)[unknownIndex].BoxX,
            *D2Client_pScreenYOffset_6FBBA74C + (*D2Client_UI_pCharSheetToHitTextLocation_6FB6EF00)[unknownIndex].BoxY + *D2Client_pResolutionHeight_6FB740F0 - 480,
            155,
            30,
            *D2Client_UI_pUnknownColor2_6FBB1A50,
            DRAWMODE_TRANS75);

        auto strAvgHitX = *D2Client_pScreenXOffset_6FBBA748 + (*D2Client_UI_pCharSheetToHitTextLocation_6FB6EF00)[unknownIndex].Line1X;
        auto strAvgHitY = *D2Client_pScreenYOffset_6FBBA74C + (*D2Client_UI_pCharSheetToHitTextLocation_6FB6EF00)[unknownIndex].Line1Y + *D2Client_pResolutionHeight_6FB740F0 - 480;
        auto strAvgHitIndex = D2LANG_GetStringFromTblIndex(STR_IDX_4159_charavghit);
        D2Win_DrawText_10117(strAvgHitIndex, strAvgHitX, strAvgHitY, 0, 0);

        D2MonStatsTxt *lastMonsterStatsTxt = nullptr;

        auto nLastSelectedMonsterClassId = D2Client_Unit_GetLastSelectedMonsterClassId_6FAB5A70();
        if (nLastSelectedMonsterClassId < 0
            || nLastSelectedMonsterClassId >= sgptDataTables->nMonStatsTxtRecordCount
            || (lastMonsterStatsTxt = &sgptDataTables->pMonStatsTxt[nLastSelectedMonsterClassId]) == 0)
        {
            FOG_DisplayAssert("ptStats", "C:\\projects\\D2\\head\\Diablo2\\Source\\D2Client\\UI\\char.cpp", 236);
            exit(-1);
        }

        wchar_t text[128] = {};
        auto lastMonsterName = D2LANG_GetStringFromTblIndex((D2C_StringIndices)lastMonsterStatsTxt->wNameStr);
        auto charMonsterXIdx = D2LANG_GetStringFromTblIndex(STR_IDX_10103_charmonsterX);
        Unicode::sprintf(128, (struct Unicode*)text, charMonsterXIdx, lastMonsterName, v61);
        D2Win_DrawText_10117(
            (const Unicode*)text,
            *D2Client_pScreenXOffset_6FBBA748 + (*D2Client_UI_pCharSheetToHitTextLocation_6FB6EF00)[unknownIndex].Line2X,
            *D2Client_pScreenYOffset_6FBBA74C + (*D2Client_UI_pCharSheetToHitTextLocation_6FB6EF00)[unknownIndex].Line2Y + *D2Client_pResolutionHeight_6FB740F0 - 480,
            0,
            0
        );
    }

    auto v69 = finalMonsterToHitPercentage;
    if (finalMonsterToHitPercentage >= 5)
    {
        if (finalMonsterToHitPercentage > 95)
        {
            v69 = 95;
        }
    }
    else
    {
        v69 = 5;
    }

    if (mousePosX >= *D2Client_pScreenXOffset_6FBBA748 + 173
        && mousePosX <= *D2Client_pScreenXOffset_6FBBA748 + 311
        && mousePosY >= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 286
        && mousePosY <= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 267)
    {
        auto isExpansion = D2Client_IsExpansion_6FAAC080();
        auto blockRate = UNITS_GetBlockRate(currentPlayer, isExpansion);
        if (blockRate <= 0)
        {
            blockRate = D2Client_UI_GetPassiveWeaponBlock_6FAD1010(currentPlayer);
            if (blockRate > 0)
            {
                int weaponClassId;
                COMPOSIT_GetWeaponClassId(currentPlayer, currentPlayer->pInventory, &weaponClassId, -1, 1);
                if (weaponClassId != WEAPONCLASS_HT2)
                {
                    blockRate = 0;
                }
            }
        }

        D2MonStatsTxt *v76 = nullptr;
        auto LastSelectedEvilMonsterClassId = D2Client_Unit_GetLastSelectedEvilMonsterClassId_6FAB5A80();
        if (LastSelectedEvilMonsterClassId < 0
            || LastSelectedEvilMonsterClassId >= sgptDataTables->nMonStatsTxtRecordCount
            || (v76 = &sgptDataTables->pMonStatsTxt[LastSelectedEvilMonsterClassId]) == 0)
        {
            FOG_DisplayAssert("ptStats", "C:\\projects\\D2\\head\\Diablo2\\Source\\D2Client\\UI\\char.cpp", 348);
            exit(-1);
        }

        wchar_t text[128] = {};

        auto blockMonsterNameStrIdx = D2LANG_GetStringFromTblIndex((D2C_StringIndices)v76->wNameStr);
        if (blockRate)
        {
            auto strIdxCharMonTohit2x = D2LANG_GetStringFromTblIndex(STR_IDX_10105_charmontohit2X);
            Unicode::sprintf(128, (struct Unicode*)text, strIdxCharMonTohit2x, blockRate, v69, blockMonsterNameStrIdx, v69);
        }
        else
        {
            auto strIdxCharMonTohit1x = D2LANG_GetStringFromTblIndex(STR_IDX_10104_charmontohit1X);
            Unicode::sprintf(128, (struct Unicode*)text, strIdxCharMonTohit1x, blockMonsterNameStrIdx, v69);
        }

        D2Win_10132_DrawBoxedTextClamped(
            (const Unicode*)text,
            *D2Client_pScreenXOffset_6FBBA748 + 139,
            *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 315,
            (unsigned __int8)*D2Client_UI_pUnknownColor2_6FBB1A50,
            DRAWMODE_TRANS75,
            0
        );
    }

    D2Win_SetFont_10127(D2FONT_FONT16);
    pData.pCellFile = D2Client_UI_GetBuySellBtnCellFile_6FB24110();
    pData.nFrame = (*D2Client_UI_pUnknownFlag_6FBB1A4C != 0) + 10;
    D2Gfx_TEXTURE_CelDraw_10072(&pData, *D2Client_pScreenXOffset_6FBBA748 + 128, *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 60, 0xFFFFFFFF, DRAWMODE_NORMAL, 0);
    
    wchar_t v140[128] = {};

    // Where the hell did this code go...
    if (currentPlayer && currentPlayer->dwUnitType == UNIT_PLAYER)
    {
        Unicode* playerClassName = nullptr;

        if (currentPlayer->dwClassId < 0 || currentPlayer->dwClassId >= sgptDataTables->nCharStatsTxtRecordCount)
        {
            playerClassName = 0;
        }
        else
        {
            playerClassName = &sgptDataTables->pCharStatsTxt[currentPlayer->dwClassId].wszClassName[0];
        }

        auto classNameX = *D2Client_pScreenXOffset_6FBBA748 + 193;
        auto classNameY = *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 455;
        auto classNameLength = D2Win_GetTextWidth_10121(playerClassName);
        if (classNameLength < 118)
        {
            classNameX += (118 - classNameLength) >> 1;
        }

        D2Win_DrawText_10117(playerClassName, classNameX, classNameY, 0, 0);
        auto playerName = D2Client_Roster_GetUnitNameFromD2UnitStrc_6FAB0C00(currentPlayer);

        auto playerNameUnicodeWidth = Unicode::unicodenwidth(playerName, strlen(playerName)) + 1;
        if (playerNameUnicodeWidth > 11)
        {
            if (playerNameUnicodeWidth < 14)
            {
                D2Win_SetFont_10127(D2FONT_FONT8);
            }
            else
            {
                D2Win_SetFont_10127(D2FONT_FONT6);
            }
        }

        // Uh there shouldn't be a 3rd param here? double check me
        Unicode::win2Unicode((struct Unicode*)v140, playerName, sizeof(v140));

        auto v89 = *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 455;
        auto v90 = *D2Client_pScreenXOffset_6FBBA748 + 13;
        auto v91 = D2Win_GetTextWidth_10121((const Unicode*)v140);
        if (v91 < 148)
        {
            v90 += (148 - v91) >> 1;
        }
        D2Win_DrawText_10117((const Unicode*)v140, v90, v89, 0, 0);
        D2Win_SetFont_10127(D2FONT_FONT16);
    }


    char v138[128] = {};

    for (auto v123 = 0; v123 < NUM_CHARSHEETSTATROWS; ++v123)
    {
        auto v92 = 0;
        auto StatValue = STATLIST_UnitGetStatValue(currentPlayer, (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].statId, 0);
        auto v94 = STATLIST_GetUnitBaseStat(currentPlayer, (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].statId, 0);
        
        bool shouldDrawText = false;
        bool shouldFormatNumber = false;
        
        switch ((*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].statId)
        {
        case STAT_HITPOINTS:
            StatValue >>= 8;
            if (currentPlayer && currentPlayer->dwUnitType == UNIT_PLAYER && currentPlayer->dwAnimMode != 17 && (unsigned int)StatValue <= 1)
            {
                StatValue = 1;
            }
            wsprintfA(v138, "%ld", StatValue);
            v92 = 1;
            shouldDrawText = true;
            break;
            
        case STAT_MAXHP:
            if (StatValue <= v94)
            {
                if (StatValue < v94)
                {
                    nColor = 1;
                }
            }
            else
            {
                nColor = 3;
            }
            StatValue >>= 8;
            wsprintfA(v138, "%ld", StatValue);
            v92 = 1;
            shouldDrawText = true;
            break;
            
        case STAT_MANA:
        case STAT_STAMINA:
            StatValue >>= 8;
            wsprintfA(v138, "%ld", StatValue);
            v92 = 1;
            shouldDrawText = true;
            break;
            
        case STAT_MAXMANA:
            if (StatValue <= v94)
            {
                if (StatValue < v94)
                {
                    nColor = 1;
                }
            }
            else
            {
                nColor = 3;
            }
            StatValue >>= 8;
            wsprintfA(v138, "%ld", StatValue);
            v92 = 1;
            shouldDrawText = true;
            break;
            
        case STAT_MAXSTAMINA:
            if (StatValue <= v94)
            {
                if (StatValue < v94)
                {
                    nColor = 1;
                }
            }
            else
            {
                nColor = 3;
            }
            StatValue >>= 8;
            wsprintfA(v138, "%ld", StatValue);
            v92 = 1;
            shouldDrawText = true;
            break;
            
        case STAT_EXPERIENCE:
            shouldFormatNumber = true;
            break;
            
        case STAT_NEXTEXP:
        {
            auto level = STATLIST_GetUnitBaseStat(currentPlayer, STAT_LEVEL, 0);
            auto classId = -1;

            if (currentPlayer)
            {
                classId = currentPlayer->dwClassId;
            }

            auto MaxLevel = DATATBLS_GetMaxLevel(classId);
            if (level != MaxLevel)
            {
                StatValue = DATATBLS_GetLevelThreshold(classId, level);
            }
            shouldFormatNumber = true;
            break;
        }
            
        case STAT_ARMORCLASS:
            StatValue = UNITS_GetDefense(currentPlayer);
            if (STATES_CheckStateMaskArmBlueOnUnit(currentPlayer))
            {
                nColor = 3;
            }

            if (currentPlayer->pInventory && INVENTORY_GetEquippedShield(currentPlayer->pInventory, 0) && STATES_CheckState(currentPlayer, STATE_HOLYSHIELD))
            {
                nColor = 3;
            }
            if (STATES_CheckStateMaskArmRedOnUnit(currentPlayer))
            {
                nColor = 1;
            }
            wsprintfA(v138, "%ld", StatValue);
            if (StatValue >= 1000 || STRTABLE_GetLanguage() == LANGUAGE_JAPANESE)
            {
                v92 = 1;
            }
            shouldDrawText = true;
            break;
            
        case STAT_MAGICRESIST:
        case STAT_FIRERESIST:
        case STAT_LIGHTRESIST:
        case STAT_COLDRESIST:
        case STAT_POISONRESIST:
        {
            auto CurrentDifficulty_6FAAC090 = D2Client_GetCurrentDifficulty_6FAAC090();
            auto v98 = 0;
            auto v97 = 0;
            auto difficultyLevelsTxt = DATATBLS_GetDifficultyLevelsTxtRecord(CurrentDifficulty_6FAAC090);
            switch ((*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].statId)
            {
            case STAT_MAGICRESIST:
                v98 = STATLIST_UnitGetStatValue(currentPlayer, STAT_MAXMAGICRESIST, 0);
                v97 = v98;
                break;
                
            case STAT_FIRERESIST:
                if (STATES_CheckStateMaskRFBlueOnUnit(currentPlayer))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRFRedOnUnit(currentPlayer))
                {
                    nColor = 1;
                }
                v98 = STATLIST_UnitGetStatValue(currentPlayer, STAT_MAXFIRERESIST, 0);
                v97 = v98;
                break;
                
            case STAT_LIGHTRESIST:
                if (STATES_CheckStateMaskRLBlueOnUnit(currentPlayer))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRLRedOnUnit(currentPlayer))
                {
                    nColor = 1;
                }
                v98 = STATLIST_UnitGetStatValue(currentPlayer, STAT_MAXLIGHTRESIST, 0);
                v97 = v98;
                break;
                
            case STAT_COLDRESIST:
                if (STATES_CheckStateMaskRCBlueOnUnit(currentPlayer))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRCRedOnUnit(currentPlayer))
                {
                    nColor = 1;
                }
                v98 = STATLIST_UnitGetStatValue(currentPlayer, STAT_MAXCOLDRESIST, 0);
                v97 = v98;
                break;
                
            case STAT_POISONRESIST:
                if (STATES_CheckStateMaskRPBlueOnUnit(currentPlayer))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRPRedOnUnit(currentPlayer))
                {
                    nColor = 1;
                }
                v98 = STATLIST_UnitGetStatValue(currentPlayer, STAT_MAXPOISONRESIST, 0);
                v97 = v98;
                break;
                
            default:
                break;
            }
            
            if (D2Client_IsExpansion_6FAAC080())
            {
                StatValue += difficultyLevelsTxt->dwResistPenalty;
            }
            else
            {
                v92 = 0;
                auto v99 = D2Client_GetCurrentDifficulty_6FAAC090() - 1;
                if (v99)
                {
                    if (v99 == 1)
                    {
                        StatValue -= 50;
                    }
                }
                else
                {
                    StatValue -= 20;
                }
            }

            auto v100 = v97 + 75;
            if (v100 >= 95)
            {
                v100 = 95;
            }
            if (StatValue <= -100)
            {
                StatValue = -100;
            }
            if (StatValue < v100 || (StatValue = v100, nColor == 3))
            {
                if (StatValue < 0)
                {
                    nColor = 1;
                }
                wsprintfA(v138, "%ld", StatValue);
            }
            else
            {
                nColor = 4;
                wsprintfA(v138, "%ld", v100);
            }
            shouldDrawText = true;
            break;
        }
            
        default:
            if (StatValue <= v94)
            {
                if (StatValue < v94)
                {
                    nColor = 1;
                }
            }
            else
            {
                nColor = 3;
            }
            wsprintfA(v138, "%ld", StatValue);
            shouldDrawText = true;
            break;
        }
        
        if (shouldFormatNumber)
        {
            D2Lang_FormatNumberWithCommas_10010((const Unicode*)v140, StatValue, 128);
            auto v104 = *D2Client_pScreenYOffset_6FBBA74C + (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].y + *D2Client_pResolutionHeight_6FB740F0 - 480;
            auto v105 = *D2Client_pScreenXOffset_6FBBA748 + (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xLeft;
            auto v106 = (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xRight - v105 + *D2Client_pScreenXOffset_6FBBA748 + 1;
            auto v107 = D2Win_GetTextWidth_10121((const Unicode*)v140);
            if (v107 < v106)
            {
                v105 += (v106 - v107) >> 1;
            }
            D2Win_DrawText_10117((const Unicode*)v140, v105, v104, 0, 0);
            nColor = 0;
        }
        else if (shouldDrawText)
        {
            Unicode::win2Unicode((struct Unicode*)v140, v138, 128);
            auto v108 = NUM_FONTS;

            if (v92)
            {
                int pWidth = 0;
                int pHeight = 0;

                if (StatValue >= 1000
                    || ( D2Win_GetTextDimensions_10131((const Unicode*)v140, &pWidth, &pHeight),
                        pWidth >= (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xRight - (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xLeft))
                {
                    v108 = D2Win_SetFont_10127(D2FONT_FONT8);
                }
            }

            auto statValueStrY = *D2Client_pScreenYOffset_6FBBA74C + (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].y + *D2Client_pResolutionHeight_6FB740F0 - 480;
            auto statValueStrX = *D2Client_pScreenXOffset_6FBBA748 + (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xLeft;
            auto statValueStrWidth = (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xRight - statValueStrX + *D2Client_pScreenXOffset_6FBBA748 + 1;
            auto statValueStrActualTextWidth = D2Win_GetTextWidth_10121((const Unicode*)v140);
            if (statValueStrActualTextWidth < statValueStrWidth)
            {
                statValueStrX += (statValueStrWidth - statValueStrActualTextWidth) >> 1;
            }
            D2Win_DrawText_10117((const Unicode*)v140, statValueStrX, statValueStrY, nColor, 0);

            nColor = 0;
            if (v108 != NUM_FONTS)
            {
                D2Win_SetFont_10127(v108);
            }
        }
    }
}