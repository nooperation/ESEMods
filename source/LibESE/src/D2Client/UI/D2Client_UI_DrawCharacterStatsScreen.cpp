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
#pragma pack(pop)

typedef void(__fastcall* D2SkillDescAttCallback_t)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int*, int*, int*, int*);


void __fastcall ESE_D2Client_UI_DrawCharacterStatsScreen_6FACFD60()
{
/*
    int MouseXPos_6FB57BC0; // ebp
    int* v1; // esi
    int v2; // edi
    int closeButtonTextX; // esi
    const Unicode* StringFromTblIndex; // eax
    int* v5; // esi
    int v6; // edi
    const Unicode* strChrStat; // edi
    int strChrStatY; // ebx
    int strChrStatX; // esi
    int strChrStatWidth; // eax
    const Unicode* strChrRema; // edi
    int strChrRemaY; // ebx
    int strChrRemaX; // esi
    int strChrRemaWidth; // eax
    int UnitBaseStat; // eax
    int statPtsValueY; // ebx
    int statPtsValueX; // edi
    int statPtsValueWidth; // eax
    _DWORD* buttonLocationIter; // esi
    int buttonXLeft; // edi
    int buttonY; // eax
    int buttonFinalY; // ebp
    int buttonFinalX; // edi
    uint32_t v24; // eax
    unsigned int i; // ebx
    _WORD* v26; // esi
    int v27; // edi
    const struct Unicode* v28; // eax
    int textXLeft; // esi
    int textXRight; // edi
    int textY; // edx
    _WORD* v32; // ebp
    int v33; // eax
    int v34; // ecx
    __int16 v35; // dx
    int v36; // edi
    int v37; // eax
    int skillLeftToHit; // eax
    int skillRightToHit; // eax
    int currentPlayerDefense; // ebx
    unsigned int nDifficultyLevel; // esi
    int v42; // ebp
    int v43; // edi
    int TextWidth; // eax
    int v45; // eax
    int LastSelectedMonsterClassId_1; // eax
    int lastSelectedMonsterClassId; // ebx
    D2MonStatsTxt* monStatsTxt; // ebp
    int gameType; // eax
    int32_t monsterToHit; // edi
    int gameType_1; // eax
    int gameType_2; // eax
    int v53; // eax
    int v54; // edi
    int v55; // esi
    _WORD* v56; // esi
    int v57; // ebx
    uint32_t v58; // ecx
    int v59; // esi
    int mouseYPos; // ebp
    int v61; // ebx
    int v62; // esi
    int v63; // esi
    int strAvgHitX; // edi
    const Unicode* strAvgHitIndex; // eax
    int nLastSelectedMonsterClassId; // eax
    D2MonStatsTxt* lastMonsterStatsTxt; // eax
    const struct Unicode* charMonsterXIdx; // eax
    int v69; // edi
    _WORD* v70; // esi
    int v71; // ebx
    D2UnitStrc* currentPlayer_1; // ebx
    int IsExpansion_6FAAC080; // eax
    int BlockRate; // esi
    int LastSelectedEvilMonsterClassId_6FAB5A80; // eax
    D2MonStatsTxt* v76; // eax
    const struct Unicode* strIdxCharMonTohit2x; // eax
    const struct Unicode* strIdxCharMonTohit1x; // eax
    int* v79; // esi
    int v80; // ebx
    int dwClassId; // eax
    const Unicode* v82; // ebx
    int v83; // esi
    int v84; // ebp
    int v85; // eax
    char* UnitNameFromD2UnitStrc_6FAB0C00; // esi
    unsigned int v87; // eax
    Font v88; // ecx
    int v89; // ebx
    int v90; // edi
    int v91; // eax
    int v92; // ebx
    int StatValue; // esi
    int v94; // eax
    D2UnitStrc* CurrentPlayer_6FB283D0; // eax
    unsigned __int8 CurrentDifficulty_6FAAC090; // al
    int32_t v97; // ebp
    int32_t v98; // eax
    int v99; // eax
    int v100; // ebp
    D2InventoryStrc* pInventory; // eax
    int v102; // ebx
    int MaxLevel; // eax
    int v104; // ebx
    int v105; // esi
    int v106; // edi
    int v107; // eax
    Font v108; // ebp
    int statValueStrY; // ebx
    int statValueStrX; // esi
    int statValueStrWidth; // edi
    int statValueStrActualTextWidth; // eax
    int closeButtonTextY; // [esp+204h] [ebp-3CCh]
    int monsterLevel; // [esp+204h] [ebp-3CCh]
    int monsterLevel_1; // [esp+204h] [ebp-3CCh]
    int monsterLevel_2; // [esp+204h] [ebp-3CCh]
    int strAvgHitY; // [esp+204h] [ebp-3CCh]
    const Unicode* lastMonsterName; // [esp+208h] [ebp-3C8h]
    const Unicode* blockMonsterNameStrIdx; // [esp+208h] [ebp-3C8h]
    int nColor; // [esp+220h] [ebp-3B0h]
    D2UnitStrc* currentPlayer; // [esp+224h] [ebp-3ACh]
    int MouseYPos_6FB57BD0; // [esp+228h] [ebp-3A8h]
    int v123; // [esp+228h] [ebp-3A8h]
    int mouseXPos; // [esp+22Ch] [ebp-3A4h]
    int currentPlayerAC; // [esp+230h] [ebp-3A0h]
    Unicode* wszTexta; // [esp+230h] [ebp-3A0h]
    int wszTextb; // [esp+230h] [ebp-3A0h]
    int pWeaponClassId; // [esp+234h] [ebp-39Ch] BYREF
    int textFinalY; // [esp+238h] [ebp-398h]
    int pWidth; // [esp+23Ch] [ebp-394h] BYREF
    int finalToHitLeft; // [esp+240h] [ebp-390h]
    int currentPlayer; // [esp+244h] [ebp-38Ch]
    D2GfxDataStrc pData; // [esp+248h] [ebp-388h] BYREF
    int pHeight; // [esp+290h] [ebp-340h] BYREF
    int v135[5]; // [esp+294h] [ebp-33Ch] BYREF
    CHAR v136[12]; // [esp+2A8h] [ebp-328h] BYREF
    D2MonStatsInitStrc pMonStatsInit; // [esp+2B4h] [ebp-31Ch] BYREF
    CHAR v138[128]; // [esp+2ECh] [ebp-2E4h] BYREF
    _WORD text[128]; // [esp+36Ch] [ebp-264h] BYREF
    int v140[63]; // [esp+46Ch] [ebp-164h] BYREF
    __int16 v141; // [esp+56Ah] [ebp-66h]
    int v142; // [esp+56Ch] [ebp-64h] BYREF
    */

    char* __fastcall D2Client_Roster_GetUnitNameFromD2UnitStrc_6FAB0C00(D2UnitStrc* pUnit);
    D2CellFileStrc* __cdecl D2Client_UI_GetBuySellBtnCellFile_6FB24110();
    int __fastcall D2Client_UI_GetPassiveWeaponBlock_6FAD1010(D2UnitStrc* pUnit);
    int __fastcall D2Client_Unit_GetLastSelectedMonsterClassId_6FAB5A70();
    void D2Client_UI_SetUnknownColorToBlack_6FB01C50();
    int D2Client_GetGameTypeButModified_6FAAC060();
    int __fastcall D2Client_Unit_GetLastSelectedEvilMonsterClassId_6FAB5A80();
    int __fastcall D2Client_GetSkillDescAtt_6FB16200(D2UnitStrc* pUnit, int bIsLeftSkill);
    int __fastcall D2Client_UI_GetChanceToHitMonster_6FAD10D0(int baseToHit);
    void __fastcall D2Client_UI_DrawLeftRightSkillDescs_6FB16190(D2UnitStrc* pUnit);

    #define NUM_CHARSHEETTEXTENTRIES 15
    #define NUM_CHARSHEETBUTTONLOCATIONS 4
    #define NUM_CHARSHEETSTATROWS 18

    int32_t *D2Client_UI_pUnknownColor2_6FBB1A50 = nullptr;
    int32_t *D2Client_UI_pUnknownFlag_6FBB1A4C = nullptr;
    D2CharSheetStatRow** D2Client_UI_pD2CharSheetStatRows_6FB78120;
    D2CharSheetTextEntry** D2Client_UI_pCharSheetTextEntries_6FB78010;
    D2CharSheetButtonLocations** D2Client_UI_pD2CharSheetButtonLocations_6FB78240;
    D2CellFileStrc** D2Client_UI_pCelFile_PanelSkillPoints_6FBB5E50;
    D2CellFileStrc** D2Client_UI_pCelFile_UiInvChar_6FBB5E24;
    D2CellFileStrc** D2Client_UI_pCelFilePanelLevelSocket_6FBB5BB8;
    D2CellFileStrc** D2Client_UI_pCelFilePanelLevel_6FBB5BB4;

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

    // wchar_t v142[50] = {}
    // v1 = &v142;
    // v2 = 50;
    // do
    // {
    //     Unicode::`default constructor closure'((int)v1);
    //         v1 = (int*)((char*)v1 + 2);
    //     --v2;
    // } while (v2);

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

        char v136[4];
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

        wchar_t text[200] = {};

        auto v28 = D2LANG_GetStringFromTblIndex(charSheetTextEntryIter->strId);
        Unicode::strncpy((struct Unicode*)text, v28, 99);

        auto textXLeft = *D2Client_pScreenXOffset_6FBBA748 + charSheetTextEntryIter->xLeft;
        auto textXRight = *D2Client_pScreenXOffset_6FBBA748 + charSheetTextEntryIter->xRight;
        auto textY = *D2Client_pScreenYOffset_6FBBA74C + charSheetTextEntryIter->y;
        
        text[99] = 0;

        wchar_t v35 = 0;
        auto v32 = text;
        auto textFinalY = textY + *D2Client_pResolutionHeight_6FB740F0 - 480;
        auto v33 = Unicode::strlen((const struct Unicode*)text);
        auto v34 = 0;
        if (!text[0])
        {
            goto LABEL_28;
        }

        v35 = text[0];
        while (v35 != '\n')
        {
            v35 = v32[1];
            ++v32;
            ++v34;
            if (!v35)
            {
                goto LABEL_28;
            }
        }

        text[v34] = 0;
        if (v34 < v33)
        {
            wszTexta = (Unicode*)(v32 + 1);
            v42 = textXLeft;
            v43 = textXRight - textXLeft + 1;
            TextWidth = D2Win_GetTextWidth_10121((const Unicode*)text);
            if (TextWidth < v43)
            {
                v42 = textXLeft + ((v43 - TextWidth) >> 1);
            }
            D2Win_DrawText_10117((const Unicode*)text, v42, textFinalY - 4, 0, 0);
            v45 = D2Win_GetTextWidth_10121(wszTexta);
            if (v45 < v43)
            {
                textXLeft += (v43 - v45) >> 1;
            }
            D2Win_DrawText_10117(wszTexta, textXLeft, textFinalY + 4, 0, 0);
        }
        else
        {
        LABEL_28:
            v36 = textXRight - textXLeft + 1;
            v37 = D2Win_GetTextWidth_10121((const Unicode*)text);
            if (v37 < v36)
            {
                textXLeft += (v36 - v37) >> 1;
            }
            D2Win_DrawText_10117((const Unicode*)text, textXLeft, textFinalY, 0, 0);
        }
    }

    D2Client_UI_DrawLeftRightSkillDescs_6FB16190(currentPlayer);
    D2Win_SetFont_10127(D2FONT_FONT8);
    skillLeftToHit = D2Client_GetSkillDescAtt_6FB16200(currentPlayer, 1);
    finalToHitLeft = D2Client_UI_GetChanceToHitMonster_6FAD10D0(skillLeftToHit);
    skillRightToHit = D2Client_GetSkillDescAtt_6FB16200(currentPlayer, 0);
    pWeaponClassId = D2Client_UI_GetChanceToHitMonster_6FAD10D0(skillRightToHit);
    textFinalY = 100;
    currentPlayer = (int)D2Client_GetCurrentPlayer_6FB283D0();
    currentPlayerDefense = UNITS_GetDefense((D2UnitStrc*)currentPlayer);
    currentPlayerAC = STATLIST_UnitGetStatValue((const D2UnitStrc*)currentPlayer, STAT_ARMORCLASS_VS_HTH, 0) + currentPlayerDefense;
    nDifficultyLevel = D2Client_GetCurrentDifficulty_6FAAC090();
    if (nDifficultyLevel >= 3)
    {
        FOG_DisplayAssert("nDifficultyLevel < NUM_DIFFICULTY_LEVELS", "C:\\projects\\D2\\head\\Diablo2\\Source\\D2Client\\UI\\char.cpp", 470);
        exit(-1);
    }

    LastSelectedMonsterClassId_1 = D2Client_Unit_GetLastSelectedEvilMonsterClassId_6FAB5A80();
    lastSelectedMonsterClassId = LastSelectedMonsterClassId_1;
    if (LastSelectedMonsterClassId_1 >= 0 && LastSelectedMonsterClassId_1 < sgptDataTables->nMonStatsTxtRecordCount)
    {
        monStatsTxt = &sgptDataTables->pMonStatsTxt[LastSelectedMonsterClassId_1];
        if (monStatsTxt)
        {
            memset(&pMonStatsInit, 0, sizeof(pMonStatsInit));
            monsterLevel = (__int16)monStatsTxt->nLevel[nDifficultyLevel];
            gameType = D2Client_GetGameTypeButModified_6FAAC060();
            DATATBLS_CalculateMonsterStatsByLevel(lastSelectedMonsterClassId, gameType, nDifficultyLevel, monsterLevel, 8, &pMonStatsInit);
            monsterToHit = pMonStatsInit.nTH;
            if (!pMonStatsInit.nTH)
            {
                memset(&pMonStatsInit, 0, sizeof(pMonStatsInit));
                monsterLevel_1 = (__int16)monStatsTxt->nLevel[nDifficultyLevel];
                gameType_1 = D2Client_GetGameTypeButModified_6FAAC060();
                DATATBLS_CalculateMonsterStatsByLevel(lastSelectedMonsterClassId, gameType_1, nDifficultyLevel, monsterLevel_1, 16, &pMonStatsInit);
                monsterToHit = pMonStatsInit.nTH;
                if (!pMonStatsInit.nTH)
                {
                    memset(&pMonStatsInit, 0, sizeof(pMonStatsInit));
                    monsterLevel_2 = (__int16)monStatsTxt->nLevel[nDifficultyLevel];
                    gameType_2 = D2Client_GetGameTypeButModified_6FAAC060();
                    DATATBLS_CalculateMonsterStatsByLevel(lastSelectedMonsterClassId, gameType_2, nDifficultyLevel, monsterLevel_2, 32, &pMonStatsInit);
                    monsterToHit = pMonStatsInit.nTH;
                }
            }
            if (monStatsTxt->nAlign != 1 && !D2Client_IsExpansion_6FAAC080() && D2Client_GetCurrentDifficulty_6FAAC090())
            {
                monsterToHit = 10 * monsterToHit / 15;
            }
            v53 = currentPlayerAC;
            if (currentPlayerAC < 0)
            {
                monsterToHit -= currentPlayerAC;
                v53 = 0;
            }
            if (monsterToHit >= 0)
            {
                if (monsterToHit)
                {
                    goto LABEL_57;
                }
            }
            else
            {
                v53 -= monsterToHit;
                monsterToHit = 0;
            }
            if (!v53)
            {
                v54 = textFinalY;
                goto LABEL_59;
            }
        LABEL_57:
            v54 = 100 * monsterToHit / (monsterToHit + v53);
        LABEL_59:
            v55 = (__int16)monStatsTxt->nLevel[nDifficultyLevel];
            wszTextb = 2 * v54 * v55 / (v55 + STATLIST_UnitGetStatValue((const D2UnitStrc*)currentPlayer, STAT_LEVEL, 0));
            goto LABEL_60;
        }
    }
    wszTextb = 0;
LABEL_60:

    wchar_t v56[128] = {0};

    D2Client_UI_SetUnknownColorToBlack_6FB01C50();
    v58 = 0;
    v59 = 0;
    if (mouseXPos < *D2Client_pScreenXOffset_6FBBA748 + 162 || mouseXPos > *D2Client_pScreenXOffset_6FBBA748 + 320)
    {
        mouseYPos = MouseYPos_6FB57BD0;
    }
    else
    {
        mouseYPos = MouseYPos_6FB57BD0;
        if (MouseYPos_6FB57BD0 >= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 334
            && MouseYPos_6FB57BD0 <= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 315)
        {
            v58 = 1;
            goto LABEL_73;
        }
    }
    if (mouseXPos >= *D2Client_pScreenXOffset_6FBBA748 + 162
        && mouseXPos <= *D2Client_pScreenXOffset_6FBBA748 + 320
        && mouseYPos >= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 308
        && mouseYPos <= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 289)
    {
        v59 = 1;
    }
LABEL_73:
    v61 = finalToHitLeft;
    if (!finalToHitLeft)
    {
        v58 = 0;
    }
    if (!pWeaponClassId)
    {
        v59 = 0;
    }
    if (v58)
    {
        v62 = 0;
    }
    else
    {
        if (!v59)
        {
            goto LABEL_90;
        }
        v62 = 1;
        v61 = pWeaponClassId;
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
    LOBYTE(v58) = *D2Client_UI_pUnknownColor2_6FBB1A50;
    v63 = 6 * v62;
    D2Gfx_DrawBox_10055(
        *D2Client_pScreenXOffset_6FBBA748 + dword_6FB6EF00[v63],
        *D2Client_pScreenYOffset_6FBBA74C + dword_6FB6EF04[v63] + *D2Client_pResolutionHeight_6FB740F0 - 480,
        155,
        30,
        v58,
        DRAWMODE_TRANS75);
    strAvgHitX = *D2Client_pScreenXOffset_6FBBA748 + dword_6FB6EF08[v63];
    strAvgHitY = *D2Client_pScreenYOffset_6FBBA74C + dword_6FB6EF0C[v63] + *D2Client_pResolutionHeight_6FB740F0 - 480;
    strAvgHitIndex = D2LANG_GetStringFromTblIndex(STR_IDX_4159_charavghit);
    D2Win_DrawText_10117(strAvgHitIndex, strAvgHitX, strAvgHitY, 0, 0);
    nLastSelectedMonsterClassId = D2Client_Unit_GetLastSelectedMonsterClassId_6FAB5A70();
    if (nLastSelectedMonsterClassId < 0
        || nLastSelectedMonsterClassId >= sgptDataTables->nMonStatsTxtRecordCount
        || (lastMonsterStatsTxt = &sgptDataTables->pMonStatsTxt[nLastSelectedMonsterClassId]) == 0)
    {
        FOG_DisplayAssert("ptStats", "C:\\projects\\D2\\head\\Diablo2\\Source\\D2Client\\UI\\char.cpp", 236);
        exit(-1);
    }
    lastMonsterName = D2LANG_GetStringFromTblIndex((D2C_StringIndices)lastMonsterStatsTxt->wNameStr);
    charMonsterXIdx = D2LANG_GetStringFromTblIndex(STR_IDX_10103_charmonsterX);
    Unicode::sprintf(128, (struct Unicode*)text, charMonsterXIdx, lastMonsterName, v61);
    D2Win_DrawText_10117(
        (const Unicode*)text,
        *D2Client_pScreenXOffset_6FBBA748 + dword_6FB6EF10[v63],
        *D2Client_pScreenYOffset_6FBBA74C + dword_6FB6EF14[v63] + *D2Client_pResolutionHeight_6FB740F0 - 480,
        0,
        0);
LABEL_90:
    v69 = wszTextb;
    if (wszTextb >= 5)
    {
        if (wszTextb > 95)
        {
            v69 = 95;
        }
    }
    else
    {
        v69 = 5;
    }
    v70 = text;
    v71 = 128;
    do
    {
        Unicode::`default constructor closure'((int)v70++);
            --v71;
    } while (v71);
    if (mouseXPos >= *D2Client_pScreenXOffset_6FBBA748 + 173
        && mouseXPos <= *D2Client_pScreenXOffset_6FBBA748 + 311
        && mouseYPos >= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 286
        && mouseYPos <= *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 267)
    {
        currentPlayer_1 = D2Client_GetCurrentPlayer_6FB283D0();
        IsExpansion_6FAAC080 = D2Client_IsExpansion_6FAAC080();
        BlockRate = UNITS_GetBlockRate(currentPlayer_1, IsExpansion_6FAAC080);
        if (BlockRate <= 0)
        {
            BlockRate = D2Client_UI_GetPassiveWeaponBlock_6FAD1010(currentPlayer_1);
            if (BlockRate > 0)
            {
                COMPOSIT_GetWeaponClassId(currentPlayer_1, currentPlayer_1->pInventory, &pWeaponClassId, -1, 1);
                if (pWeaponClassId != 13)
                {
                    BlockRate = 0;
                }
            }
        }

        LastSelectedEvilMonsterClassId_6FAB5A80 = D2Client_Unit_GetLastSelectedEvilMonsterClassId_6FAB5A80();
        if (LastSelectedEvilMonsterClassId_6FAB5A80 < 0
            || LastSelectedEvilMonsterClassId_6FAB5A80 >= sgptDataTables->nMonStatsTxtRecordCount
            || (v76 = &sgptDataTables->pMonStatsTxt[LastSelectedEvilMonsterClassId_6FAB5A80]) == 0)
        {
            FOG_DisplayAssert("ptStats", "C:\\projects\\D2\\head\\Diablo2\\Source\\D2Client\\UI\\char.cpp", 348);
            exit(-1);
        }

        blockMonsterNameStrIdx = D2LANG_GetStringFromTblIndex((D2C_StringIndices)v76->wNameStr);
        if (BlockRate)
        {
            strIdxCharMonTohit2x = D2LANG_GetStringFromTblIndex(STR_IDX_10105_charmontohit2X);
            Unicode::sprintf(128, (struct Unicode*)text, strIdxCharMonTohit2x, BlockRate, v69, blockMonsterNameStrIdx, v69);
        }
        else
        {
            strIdxCharMonTohit1x = D2LANG_GetStringFromTblIndex(STR_IDX_10104_charmontohit1X);
            Unicode::sprintf(128, (struct Unicode*)text, strIdxCharMonTohit1x, blockMonsterNameStrIdx, v69);
        }

        D2Win_10132_DrawBoxedTextClamped(
            (const Unicode*)text,
            *D2Client_pScreenXOffset_6FBBA748 + 139,
            *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 315,
            (unsigned __int8)*D2Client_UI_pUnknownColor2_6FBB1A50,
            DRAWMODE_TRANS75,
            0);
    }
    D2Win_SetFont_10127(D2FONT_FONT16);
    pData.pCellFile = D2Client_UI_GetBuySellBtnCellFile_6FB24110();
    pData.nFrame = (*D2Client_UI_pUnknownFlag_6FBB1A4C != 0) + 10;
    D2Gfx_TEXTURE_CelDraw_10072(&pData, *D2Client_pScreenXOffset_6FBBA748 + 128, *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 60, 0xFFFFFFFF, DRAWMODE_NORMAL, 0);
    v79 = v140;
    v80 = 128;
    do
    {
        Unicode::`default constructor closure'((int)v79);
            v79 = (int*)((char*)v79 + 2);
        --v80;
    } while (v80);
    if (currentPlayer && currentPlayer->dwUnitType == UNIT_PLAYER)
    {
        dwClassId = currentPlayer->dwClassId;
        if (dwClassId < 0 || dwClassId >= sgptDataTables->nCharStatsTxtRecordCount)
        {
            v82 = 0;
        }
        else
        {
            v82 = (const Unicode*)&sgptDataTables->pCharStatsTxt[dwClassId];
        }
        v83 = *D2Client_pScreenXOffset_6FBBA748 + 193;
        v84 = *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 455;
        v85 = D2Win_GetTextWidth_10121(v82);
        if (v85 < 118)
        {
            v83 += (118 - v85) >> 1;
        }
        D2Win_DrawText_10117(v82, v83, v84, 0, 0);
        UnitNameFromD2UnitStrc_6FAB0C00 = D2Client_Roster_GetUnitNameFromD2UnitStrc_6FAB0C00(currentPlayer);
        v87 = Unicode::unicodenwidth(UnitNameFromD2UnitStrc_6FAB0C00, strlen(UnitNameFromD2UnitStrc_6FAB0C00)) + 1;
        if (v87 > 0xB)
        {
            if (v87 < 0xE)
            {
                v88 = D2FONT_FONT8;
            }
            else
            {
                v88 = D2FONT_FONT6;
            }
            D2Win_SetFont_10127(v88);
        }
        Unicode::win2Unicode((struct Unicode*)v140, UnitNameFromD2UnitStrc_6FAB0C00);
        v89 = *D2Client_pScreenYOffset_6FBBA74C + *D2Client_pResolutionHeight_6FB740F0 - 455;
        v90 = *D2Client_pScreenXOffset_6FBBA748 + 13;
        v91 = D2Win_GetTextWidth_10121((const Unicode*)v140);
        if (v91 < 148)
        {
            v90 += (148 - v91) >> 1;
        }
        D2Win_DrawText_10117((const Unicode*)v140, v90, v89, 0, 0);
        D2Win_SetFont_10127(D2FONT_FONT16);
    }
    v123 = 0;
    while (2)
    {
        v92 = 0;
        StatValue = STATLIST_UnitGetStatValue(currentPlayer, (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].statId, 0);
        v94 = STATLIST_GetUnitBaseStat(currentPlayer, (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].statId, 0);
        switch ((*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].statId)
        {
        case STAT_HITPOINTS:
            StatValue >>= 8;
            CurrentPlayer_6FB283D0 = D2Client_GetCurrentPlayer_6FB283D0();
            if (CurrentPlayer_6FB283D0 && CurrentPlayer_6FB283D0->dwUnitType == UNIT_PLAYER && CurrentPlayer_6FB283D0->dwAnimMode != 17 && (unsigned int)StatValue <= 1)
            {
                StatValue = 1;
            }
            goto LABEL_152;
        case STAT_MAXHP:
            if (StatValue <= v94)
            {
                if (StatValue < v94)
                {
                    nColor = 1;
                }
            LABEL_136:
                StatValue >>= 8;
                wsprintfA(v138, "%ld", StatValue);
                v92 = 1;
            }
            else
            {
                StatValue >>= 8;
                nColor = 3;
                wsprintfA(v138, "%ld", StatValue);
                v92 = 1;
            }
            goto LABEL_216;
        case STAT_MANA:
        case STAT_STAMINA:
            goto LABEL_136;
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
            goto LABEL_136;
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
        LABEL_152:
            wsprintfA(v138, "%ld", StatValue);
            v92 = 1;
            goto LABEL_216;
        case STAT_EXPERIENCE:
            goto LABEL_208;
        case STAT_NEXTEXP:
            pWeaponClassId = STATLIST_GetUnitBaseStat(currentPlayer, STAT_LEVEL, 0);
            if (currentPlayer)
            {
                v102 = currentPlayer->dwClassId;
            }
            else
            {
                v102 = -1;
            }
            MaxLevel = DATATBLS_GetMaxLevel(v102);
            if (pWeaponClassId != MaxLevel)
            {
                StatValue = DATATBLS_GetLevelThreshold(v102, pWeaponClassId);
            }
        LABEL_208:
            D2Lang_FormatNumberWithCommas_10010((const Unicode*)v140, StatValue, 128);
            v104 = *D2Client_pScreenYOffset_6FBBA74C + (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].y + *D2Client_pResolutionHeight_6FB740F0 - 480;
            v105 = *D2Client_pScreenXOffset_6FBBA748 + (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xLeft;
            v106 = (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xRight - v105 + *D2Client_pScreenXOffset_6FBBA748 + 1;
            v107 = D2Win_GetTextWidth_10121((const Unicode*)v140);
            if (v107 < v106)
            {
                v105 += (v106 - v107) >> 1;
            }
            D2Win_DrawText_10117((const Unicode*)v140, v105, v104, 0, 0);
            nColor = 0;
            goto LABEL_224;
        case STAT_ARMORCLASS:
            StatValue = UNITS_GetDefense(currentPlayer);
            if (STATES_CheckStateMaskArmBlueOnUnit(currentPlayer))
            {
                nColor = 3;
            }
            pInventory = currentPlayer->pInventory;
            if (pInventory && INVENTORY_GetEquippedShield(pInventory, 0) && STATES_CheckState(currentPlayer, STATE_HOLYSHIELD))
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
            goto LABEL_216;
        case STAT_MAGICRESIST:
        case STAT_FIRERESIST:
        case STAT_LIGHTRESIST:
        case STAT_COLDRESIST:
        case STAT_POISONRESIST:
            CurrentDifficulty_6FAAC090 = D2Client_GetCurrentDifficulty_6FAAC090();
            v97 = 0;
            pWeaponClassId = (int)DATATBLS_GetDifficultyLevelsTxtRecord(CurrentDifficulty_6FAAC090);
            switch ((*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].statId)
            {
            case STAT_MAGICRESIST:
                v98 = STATLIST_UnitGetStatValue(currentPlayer, STAT_MAXMAGICRESIST, 0);
                goto LABEL_175;
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
                goto LABEL_175;
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
                goto LABEL_175;
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
                goto LABEL_175;
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
            LABEL_175:
                v97 = v98;
                break;
            default:
                break;
            }
            if (D2Client_IsExpansion_6FAAC080())
            {
                StatValue += *(_DWORD*)pWeaponClassId;
            }
            else
            {
                v92 = 0;
                v99 = D2Client_GetCurrentDifficulty_6FAAC090() - 1;
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
            v100 = v97 + 75;
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
            LABEL_215:
                wsprintfA(v138, "%ld", StatValue);
            }
            else
            {
                nColor = 4;
                wsprintfA(v138, "%ld", v100);
            }
        LABEL_216:
            Unicode::win2Unicode((struct Unicode*)v140, v138);
            v141 = 0;
            v108 = NUM_FONTS;
            if (v92)
            {
                if (StatValue >= 1000
                    || ( D2Win_GetTextDimensions_10131((const Unicode*)v140, &pWidth, &pHeight),
                        pWidth >= (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xRight - (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xLeft))
                {
                    v108 = D2Win_SetFont_10127(D2FONT_FONT8);
                }
            }
            statValueStrY = *D2Client_pScreenYOffset_6FBBA74C + (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].y + *D2Client_pResolutionHeight_6FB740F0 - 480;
            statValueStrX = *D2Client_pScreenXOffset_6FBBA748 + (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xLeft;
            statValueStrWidth = (*D2Client_UI_pD2CharSheetStatRows_6FB78120)[v123].xRight - statValueStrX + *D2Client_pScreenXOffset_6FBBA748 + 1;
            statValueStrActualTextWidth = D2Win_GetTextWidth_10121((const Unicode*)v140);
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
        LABEL_224:
            if ((unsigned int)++v123 < 0x12)
            {
                continue;
            }
            return;
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
            goto LABEL_215;
        }
    }
}