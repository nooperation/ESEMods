
#pragma once

#include <Windows.h>
#include <cstdint>

#include <Drlg/D2DrlgDrlg.h>
#include <D2StatList.h>
#include <Units/UnitFinds.h>

struct D2WinAnimImageStrc;
struct D2CellFileStrc;
struct D2CompositeUnitStrc;
struct D2WinEditBoxStrc;
struct Unicode;
enum DrawMode;
enum Font;
struct D2WinListStrc;
struct SMSGHANDLER_PARAMS;
struct D2WinControlStrc;
struct D2WinControlInitStrc;
struct D2ShadowLightGammaPaletteStrc;
struct D2WinScrollBarStrc;
struct D2WinTextBoxStrc;

struct D2SplittedTextStrc;
struct D2ConfigStrc;
struct DrawFramedTextPtr;
struct GetTextDimensionsPtr;
struct D2WinTimerStrc;

void InitD2WinExports();

using D2UnitGUID = uint32_t;
typedef int (__fastcall *D2Win_10106_t)(D2WinAnimImageStrc* pAnimImage);
typedef int (__fastcall *D2Win_10104_t)(D2WinAnimImageStrc* pAnimImage);
typedef D2CellFileStrc* (__fastcall *D2Win_ARCHIVE_LoadCellFileWithFileSize_10040_t)(const char* szFile, uint32_t* pFileSize, int32_t nType);
typedef void (__fastcall *D2Win_ARCHIVE_FreeCellFile_10041_t)(D2CellFileStrc* pCellFile);
typedef BOOL (__stdcall *D2Win_ARCHIVE_ShowInsertExpansionDiscMessage_10205_t)();
typedef BOOL (__stdcall *D2Win_ARCHIVE_ShowInsertPlayDiscMessage_10174_t)();
typedef BOOL (__stdcall *D2Win_ARCHIVE_ShowInsertCinematicsDisc_10183_t)();
typedef BOOL (__fastcall *D2Win_ARCHIVE_LoadArchives_10037_t)();
typedef void (__fastcall *D2Win_ARCHIVE_FreeArchives_10036_t)();
typedef HD2ARCHIVE (__stdcall *D2Win_GetArchive_10038_t)();
typedef int (__stdcall *D2Win_10185_t)();
typedef BOOL (__fastcall *D2Win_ARCHIVE_LoadExpansionArchives_10171_t)(ARCHIVE_ShowMessageFunctionPtr pfShowInsertPlayDisc, ARCHIVE_ShowMessageFunctionPtr pfShowInsertExpansionDisc, HANDLE hFile, D2ConfigStrc* pConfig);
typedef BOOL (__fastcall *D2Win_ARCHIVE_LoadVideoArchives_10172_t)(ARCHIVE_ShowMessageFunctionPtr pfShowMessage, HANDLE hFile, int32_t bExpansion);
typedef void (__fastcall *D2Win_ARCHIVE_UnloadExpansionArchives_10173_t)();
typedef D2CompositeUnitStrc* (__stdcall *D2Win_10147_t)();
typedef void (__stdcall *D2Win_10142_t)(D2CompositeUnitStrc* pCompositeUnit, int a2);
typedef D2WinEditBoxStrc* (__fastcall *D2Win_EDITBOX_Create_10070_t)(int32_t nX, int32_t nY, int32_t nWidth, int32_t nHeight, int32_t a5, int32_t a6, D2CellFileStrc* pCellFile, int32_t a8, int32_t(__stdcall* a9)(SMSGHANDLER_PARAMS*), int32_t nEditBoxFlags, int32_t a11);
typedef int (__fastcall *D2Win_EDITBOX_Destroy_10071_t)(D2WinEditBoxStrc* pEditBox);
typedef void (__fastcall *D2Win_10072_t)(D2WinEditBoxStrc* pEditBox, int32_t a2);
typedef void (__fastcall *D2Win_10073_t)(D2WinEditBoxStrc* pEditBox, void(__stdcall* a2)(int32_t));
typedef void (__fastcall *D2Win_10083_t)(D2WinEditBoxStrc* pEditBox);
typedef int (__fastcall *D2Win_10082_t)(D2WinEditBoxStrc* pEditBox);
typedef int32_t (__fastcall *D2Win_10074_t)(D2WinEditBoxStrc* pEditBox, uint8_t a2);
typedef void (__fastcall *D2Win_10081_t)(D2WinEditBoxStrc* pEditBox, int32_t a2);
typedef int (__fastcall *D2Win_10076_t)(D2WinEditBoxStrc* pEditBox, const char* szText);
typedef int (__fastcall *D2Win_10075_t)(D2WinEditBoxStrc* pEditBox, const Unicode* pText);
typedef const Unicode* (__fastcall *D2Win_EDITBOX_GetText_10077_t)(D2WinEditBoxStrc* pEditBox);
typedef void (__fastcall *D2Win_10080_t)(D2WinEditBoxStrc* pEditBox, D2WinEditBoxStrc* pNext);
typedef bool (__stdcall *D2Win_IsNumber_10078_t)(int32_t nUnused1, int32_t nUnused2, char* szChar);
typedef bool (__stdcall *D2Win_IsLetter_10079_t)(int nUnused1, int nUnused2, char* szChar);
typedef void (__fastcall *D2Win_FONT_10115_t)();
typedef void (__stdcall *D2Win_10116_t)();
typedef Font (__fastcall *D2Win_SetFont_10127_t)(Font nFontSize);
typedef int (__fastcall *D2Win_10123_t)(const Unicode* wszText, int nTextLength);
typedef int (__fastcall *D2Win_10122_t)(const Unicode* wszText, int nTextLength);
typedef int (__fastcall *D2Win_GetTextWidth_10121_t)(const Unicode* wszText);
typedef int (__stdcall *D2Win_10125_t)();
typedef void (__fastcall *D2Win_DrawCroppedText_10119_t)(const Unicode* wszText, int32_t nX, int32_t nY, int32_t a4, int32_t a5, int32_t a6, int32_t a7);
typedef void (__stdcall *D2Win_10124_t)();
typedef void (__fastcall *D2Win_DrawFramedText_10129_t)(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign);
typedef void (__fastcall *D2Win_DrawFramedTextEx_10130_t)(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign, int nRectangleColor);
typedef void (__fastcall *D2Win_DrawText_10117_t)(const Unicode* wszText, int nX, int nY, int nColor, BOOL bCentered);
typedef void (__fastcall *D2Win_DrawBlendedText_10118_t)(const Unicode* wszText, int32_t nX, int32_t nY, int32_t nColor, int32_t bCentered, DrawMode eDrawMode);
typedef void (__fastcall *D2Win_DrawTextFromCache_10126_t)(Unicode *wszText, int nX, int nY);
typedef void (__fastcall *D2Win_10132_t)(const Unicode* wszText, int nX, int nY, DWORD dwColor, DrawMode eDrawMode, int nColor);
typedef void (__fastcall *D2Win_10133_t)(const Unicode* pText, int nX, int nY, DWORD dwColor, DrawMode eDrawMode, int nPaletteShift);
typedef void (__fastcall *D2Win_GetTextDimensions_10131_t)(const Unicode* pText, int* pWidth, int* pHeight);
typedef unsigned int (__fastcall *D2Win_10128_t)(uint8_t a1);
typedef void (__fastcall *D2Win_DrawCellFile_10134_t)(D2CellFileStrc* pCellFile, int nX, int nY, int nDiv, DrawMode eDrawMode, int nColor);
typedef void (__fastcall *D2Win_10120_t)(const Unicode* wszText, int nX, int nY, int a4, int a5, int a6);
typedef void (__fastcall *D2Win_10200_t)(D2SplittedTextStrc* pSplitText);
typedef D2SplittedTextStrc* (__fastcall *D2Win_10199_t)(const Unicode *wszText, int *pLines, int nMaxLength);
typedef DrawFramedTextPtr (__stdcall *D2Win_10206_t)();
typedef GetTextDimensionsPtr (__stdcall *D2Win_10207_t)();
typedef void (__fastcall *D2Win_10138_t)(D2WinListStrc* pList, const char* szText, int(__stdcall* a3)(SMSGHANDLER_PARAMS*), char a4, int a5, int a6, int a7);
typedef void (__fastcall *D2Win_10137_t)(D2WinListStrc* pList, Unicode* wszText, int(__stdcall* a3)(SMSGHANDLER_PARAMS*), char a4, int a5, int a6, int a7);
typedef int (__fastcall *D2Win_10141_t)(D2WinListStrc* pList);
typedef BOOL (__stdcall *D2Win_InitializeSpriteCache_10001_t)(BOOL bWindowed, D2GameResolutionMode nResolution);
typedef int (__stdcall *D2Win_SetWndProc_10014_t)(WNDPROC wndProc);
typedef int (__fastcall *D2Win_10015_t)();
typedef int (__stdcall *D2Win_CloseSpriteCache_10002_t)();
typedef void (__stdcall *D2Win_10003_t)();
typedef void (__stdcall *D2Win_10004_t)(BOOL bForceResize);
typedef int (__stdcall *D2Win_10016_t)();
typedef int (__stdcall *D2Win_10005_t)(BOOL bForceResize);
typedef void (__stdcall *D2Win_ClearDrawCaches_10006_t)();
typedef int (__stdcall *D2Win_BACKGROUND_SetCellFile_10007_t)(D2CellFileStrc* pCellFile);
typedef int (__stdcall *D2Win_CURSOR_SetCellFile_10011_t)(D2CellFileStrc* pCellFile);
typedef void (__stdcall *D2Win_10010_t)(int(*a1)());
typedef int (__stdcall *D2Win_10009_t)();
typedef int (__stdcall *D2Win_10008_t)(void(__stdcall* pCallback)(DWORD));
typedef int (__stdcall *D2Win_CONTROL_SetCellFile_10013_t)(D2WinControlStrc* pControl, D2CellFileStrc* pCellFile);
typedef int (__stdcall *D2Win_10012_t)(D2WinEditBoxStrc* pEditBox);
typedef D2WinEditBoxStrc* (__stdcall *D2Win_10023_t)();
typedef D2WinControlStrc* (__stdcall *D2Win_CONTROL_Create_10017_t)(D2WinControlInitStrc* pControlInit);
typedef int (__stdcall *D2Win_CONTROL_Destroy_10018_t)(void*a1);
typedef void (__fastcall *D2Win_CONTROL_ToggleFirstFlag_10025_t)(D2WinControlStrc* pControl, int bSet);
typedef int (__fastcall *D2Win_CONTROL_CheckFirstFlag_10024_t)(D2WinControlStrc* pControl);
typedef void (__fastcall *D2Win_CONTROL_ToggleThirdFlag_10027_t)(D2WinControlStrc* pControl, int bSet);
typedef int (__fastcall *D2Win_CONTROL_CheckThirdFlag_10026_t)(D2WinControlStrc* pControl);
typedef BOOL (__stdcall *D2Win_CONTROL_MouseInsideRect_10170_t)(const RECT* pRect);
typedef void (__stdcall *D2Win_10019_t)();
typedef void (__stdcall *D2Win_WINMAIN_CreateScreenshot_10168_t)();
typedef void (__stdcall *D2Win_10029_t)(int a1);
typedef void (__stdcall *D2Win_CONTROL_ToggleFourthFlag_10030_t)(D2WinControlStrc* pControl, int bSet);
typedef void (__stdcall *D2Win_10031_t)(void* a1);
typedef int (__stdcall *D2Win_IsMouseButtonPressed_10032_t)();
typedef signed int (__stdcall *D2Win_10033_t)(D2WinControlStrc* a1, int a2);
typedef int (__stdcall *D2Win_CONTROL_GetType_10035_t)(D2WinControlStrc* pControl);
typedef int32_t (__fastcall *D2Win_10177_t)(uint8_t nAct);
typedef uint8_t* (__fastcall *D2Win_GetPL2Shift_10175_t)(int32_t nIndex);
typedef void (__stdcall *D2Win_10179_t)();
typedef void (__fastcall *D2Win_10176_t)(int32_t a1);
typedef int32_t (__stdcall *D2Win_10028_t)(const char* pszPalDatFilename, const char* pszPalPL2Filename);
typedef uint8_t (__stdcall *D2Win_MixRGB_10034_t)(uint8_t nRed, uint8_t nGreen, uint8_t nBlue);
typedef void (__fastcall *D2Win_10178_t)(D2ShadowLightGammaPaletteStrc* pBuffer);
typedef void (__fastcall *D2Win_10202_t)(D2WinScrollBarStrc* pScrollBar, int nPosition);
typedef int (__fastcall *D2Win_10201_t)(D2WinScrollBarStrc* pScrollBar);
typedef void (__stdcall *D2Win_10184_t)();
typedef void (__fastcall *D2Win_10208_t)(int a1);
typedef D2WinTextBoxStrc* (__fastcall *D2Win_TEXTBOX_Create_10042_t)(int nX, int nY, int nWidth, int nHeight, int a5, int a6, D2CellFileStrc* pCellFile, int(__stdcall* a8)(SMSGHANDLER_PARAMS*), unsigned int dwTextBoxFlags, int a10, int a11);
typedef int (__fastcall *D2Win_TEXTBOX_Destroy_10043_t)(D2WinTextBoxStrc* pTextBox);
typedef int (__fastcall *D2Win_10047_t)(D2WinTextBoxStrc* pTextBox);
typedef int (__fastcall *D2Win_10062_t)(D2WinTextBoxStrc* pTextBox, int a2, int a3);
typedef void (__fastcall *D2Win_10045_t)(D2WinTextBoxStrc* pTextBox, const char* szText);
typedef BOOL (__fastcall *D2Win_10046_t)(D2WinTextBoxStrc* pTextBox, const char* szText, int a3);
typedef BOOL (__fastcall *D2Win_10044_t)(D2WinTextBoxStrc* pTextBox, const Unicode* wszText);
typedef BOOL (__fastcall *D2Win_10051_t)(D2WinTextBoxStrc* pTextBox, const Unicode* a2, int a3, char a4, signed int a5);
typedef int (__fastcall *D2Win_10198_t)(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int a3, int a4, char a5);
typedef int (__fastcall *D2Win_10057_t)(D2WinTextBoxStrc* pTextBox, const char* a2, int a3, int a4);
typedef int (__fastcall *D2Win_0_10058_t)(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int a3, int nColumn);
typedef void (__fastcall *D2Win_10197_t)(D2WinTextBoxStrc* pTextBox, int nLineNum);
typedef int (__fastcall *D2Win_TEXTBOX_GetNumLines_10052_t)(D2WinTextBoxStrc* pTextBox);
typedef int (__fastcall *D2Win_10054_t)(D2WinTextBoxStrc* pTextBox);
typedef int (__fastcall *D2Win_10049_t)(D2WinTextBoxStrc* pTextBox);
typedef void (__fastcall *D2Win_TEXTBOX_SetLine_10050_t)(D2WinTextBoxStrc* pTextBox, int nLine);
typedef int (__fastcall *D2Win_10053_t)(D2WinTextBoxStrc* pTextBox, int a2);
typedef int (__fastcall *D2Win_10055_t)(D2WinTextBoxStrc* pTextBox);
typedef Unicode* (__fastcall *D2Win_10048_t)(D2WinTextBoxStrc* pTextBox);
typedef Unicode* (__fastcall *D2Win_10196_t)(D2WinTextBoxStrc* pTextBox, int nLineNum, int nColumnNum);
typedef void (__fastcall *D2Win_10056_t)(D2WinTextBoxStrc* pTextBox, int nNumColumns);
typedef void (__fastcall *D2Win_10059_t)(D2WinTextBoxStrc* pTextBox, int nColumn, Unicode* pColumn);
typedef void (__fastcall *D2Win_10060_t)(D2WinTextBoxStrc* pTextBox, int nColumn, int a3);
typedef int (__fastcall *D2Win_10061_t)(D2WinTextBoxStrc* pTextBox);
typedef void (__fastcall *D2Win_10187_t)(D2WinTextBoxStrc* pTextBox, int bSet);
typedef int (__fastcall *D2Win_10188_t)(D2WinTextBoxStrc* pTextBox, int nLineNum, int a3);
typedef int (__fastcall *D2Win_10190_t)(D2WinTextBoxStrc* pTextBox);
typedef int (__fastcall *D2Win_10191_t)(D2WinTextBoxStrc* pTextBox, int a2);
typedef int (__fastcall *D2Win_10192_t)(D2WinTextBoxStrc* pTextBox);
typedef int (__fastcall *D2Win_10193_t)(D2WinTextBoxStrc* pTextBox, int a2);
typedef int (__fastcall *D2Win_10194_t)(D2WinTextBoxStrc* pTextBox, D2WinTextBoxStrc* a2);
typedef int (__fastcall *D2Win_10195_t)(D2WinTextBoxStrc* pTextBox, void(__stdcall* a2)(SMSGHANDLER_PARAMS*));
typedef void (__fastcall *D2Win_10204_t)(D2WinTextBoxStrc* pTextBox, int a2);
typedef int (__fastcall *D2Win_TEXTBOX_10203_t)(D2WinTextBoxStrc* pTextBox);
typedef void (__fastcall *D2Win_10180_t)(D2WinTimerStrc* pTimer);
typedef void (__fastcall *D2Win_10182_t)(D2WinTimerStrc* pTimer);

extern D2Win_10106_t D2Win_10106;
extern D2Win_10104_t D2Win_10104;
extern D2Win_ARCHIVE_LoadCellFileWithFileSize_10040_t D2Win_ARCHIVE_LoadCellFileWithFileSize_10040;
extern D2Win_ARCHIVE_FreeCellFile_10041_t D2Win_ARCHIVE_FreeCellFile_10041;
extern D2Win_ARCHIVE_ShowInsertExpansionDiscMessage_10205_t D2Win_ARCHIVE_ShowInsertExpansionDiscMessage_10205;
extern D2Win_ARCHIVE_ShowInsertPlayDiscMessage_10174_t D2Win_ARCHIVE_ShowInsertPlayDiscMessage_10174;
extern D2Win_ARCHIVE_ShowInsertCinematicsDisc_10183_t D2Win_ARCHIVE_ShowInsertCinematicsDisc_10183;
extern D2Win_ARCHIVE_LoadArchives_10037_t D2Win_ARCHIVE_LoadArchives_10037;
extern D2Win_ARCHIVE_FreeArchives_10036_t D2Win_ARCHIVE_FreeArchives_10036;
extern D2Win_GetArchive_10038_t D2Win_GetArchive_10038;
extern D2Win_10185_t D2Win_10185;
extern D2Win_ARCHIVE_LoadExpansionArchives_10171_t D2Win_ARCHIVE_LoadExpansionArchives_10171;
extern D2Win_ARCHIVE_LoadVideoArchives_10172_t D2Win_ARCHIVE_LoadVideoArchives_10172;
extern D2Win_ARCHIVE_UnloadExpansionArchives_10173_t D2Win_ARCHIVE_UnloadExpansionArchives_10173;
extern D2Win_10147_t D2Win_10147;
extern D2Win_10142_t D2Win_10142;
extern D2Win_EDITBOX_Create_10070_t D2Win_EDITBOX_Create_10070;
extern D2Win_EDITBOX_Destroy_10071_t D2Win_EDITBOX_Destroy_10071;
extern D2Win_10072_t D2Win_10072;
extern D2Win_10073_t D2Win_10073;
extern D2Win_10083_t D2Win_10083;
extern D2Win_10082_t D2Win_10082;
extern D2Win_10074_t D2Win_10074;
extern D2Win_10081_t D2Win_10081;
extern D2Win_10076_t D2Win_10076;
extern D2Win_10075_t D2Win_10075;
extern D2Win_EDITBOX_GetText_10077_t D2Win_EDITBOX_GetText_10077;
extern D2Win_10080_t D2Win_10080;
extern D2Win_IsNumber_10078_t D2Win_IsNumber_10078;
extern D2Win_IsLetter_10079_t D2Win_IsLetter_10079;
extern D2Win_FONT_10115_t D2Win_FONT_10115;
extern D2Win_10116_t D2Win_10116;
extern D2Win_SetFont_10127_t D2Win_SetFont_10127;
extern D2Win_10123_t D2Win_10123;
extern D2Win_10122_t D2Win_10122;
extern D2Win_GetTextWidth_10121_t D2Win_GetTextWidth_10121;
extern D2Win_10125_t D2Win_10125;
extern D2Win_DrawCroppedText_10119_t D2Win_DrawCroppedText_10119;
extern D2Win_10124_t D2Win_10124;
extern D2Win_DrawFramedText_10129_t D2Win_DrawFramedText_10129;
extern D2Win_DrawFramedTextEx_10130_t D2Win_DrawFramedTextEx_10130;
extern D2Win_DrawText_10117_t D2Win_DrawText_10117;
extern D2Win_DrawBlendedText_10118_t D2Win_DrawBlendedText_10118;
extern D2Win_DrawTextFromCache_10126_t D2Win_DrawTextFromCache_10126;
extern D2Win_10132_t D2Win_10132;
extern D2Win_10133_t D2Win_10133;
extern D2Win_GetTextDimensions_10131_t D2Win_GetTextDimensions_10131;
extern D2Win_10128_t D2Win_10128;
extern D2Win_DrawCellFile_10134_t D2Win_DrawCellFile_10134;
extern D2Win_10120_t D2Win_10120;
extern D2Win_10200_t D2Win_10200;
extern D2Win_10199_t D2Win_10199;
extern D2Win_10206_t D2Win_10206;
extern D2Win_10207_t D2Win_10207;
extern D2Win_10138_t D2Win_10138;
extern D2Win_10137_t D2Win_10137;
extern D2Win_10141_t D2Win_10141;
extern D2Win_InitializeSpriteCache_10001_t D2Win_InitializeSpriteCache_10001;
extern D2Win_SetWndProc_10014_t D2Win_SetWndProc_10014;
extern D2Win_10015_t D2Win_10015;
extern D2Win_CloseSpriteCache_10002_t D2Win_CloseSpriteCache_10002;
extern D2Win_10003_t D2Win_10003;
extern D2Win_10004_t D2Win_10004;
extern D2Win_10016_t D2Win_10016;
extern D2Win_10005_t D2Win_10005;
extern D2Win_ClearDrawCaches_10006_t D2Win_ClearDrawCaches_10006;
extern D2Win_BACKGROUND_SetCellFile_10007_t D2Win_BACKGROUND_SetCellFile_10007;
extern D2Win_CURSOR_SetCellFile_10011_t D2Win_CURSOR_SetCellFile_10011;
extern D2Win_10010_t D2Win_10010;
extern D2Win_10009_t D2Win_10009;
extern D2Win_10008_t D2Win_10008;
extern D2Win_CONTROL_SetCellFile_10013_t D2Win_CONTROL_SetCellFile_10013;
extern D2Win_10012_t D2Win_10012;
extern D2Win_10023_t D2Win_10023;
extern D2Win_CONTROL_Create_10017_t D2Win_CONTROL_Create_10017;
extern D2Win_CONTROL_Destroy_10018_t D2Win_CONTROL_Destroy_10018;
extern D2Win_CONTROL_ToggleFirstFlag_10025_t D2Win_CONTROL_ToggleFirstFlag_10025;
extern D2Win_CONTROL_CheckFirstFlag_10024_t D2Win_CONTROL_CheckFirstFlag_10024;
extern D2Win_CONTROL_ToggleThirdFlag_10027_t D2Win_CONTROL_ToggleThirdFlag_10027;
extern D2Win_CONTROL_CheckThirdFlag_10026_t D2Win_CONTROL_CheckThirdFlag_10026;
extern D2Win_CONTROL_MouseInsideRect_10170_t D2Win_CONTROL_MouseInsideRect_10170;
extern D2Win_10019_t D2Win_10019;
extern D2Win_WINMAIN_CreateScreenshot_10168_t D2Win_WINMAIN_CreateScreenshot_10168;
extern D2Win_10029_t D2Win_10029;
extern D2Win_CONTROL_ToggleFourthFlag_10030_t D2Win_CONTROL_ToggleFourthFlag_10030;
extern D2Win_10031_t D2Win_10031;
extern D2Win_IsMouseButtonPressed_10032_t D2Win_IsMouseButtonPressed_10032;
extern D2Win_10033_t D2Win_10033;
extern D2Win_CONTROL_GetType_10035_t D2Win_CONTROL_GetType_10035;
extern D2Win_10177_t D2Win_10177;
extern D2Win_GetPL2Shift_10175_t D2Win_GetPL2Shift_10175;
extern D2Win_10179_t D2Win_10179;
extern D2Win_10176_t D2Win_10176;
extern D2Win_10028_t D2Win_10028;
extern D2Win_MixRGB_10034_t D2Win_MixRGB_10034;
extern D2Win_10178_t D2Win_10178;
extern D2Win_10202_t D2Win_10202;
extern D2Win_10201_t D2Win_10201;
extern D2Win_10184_t D2Win_10184;
extern D2Win_10208_t D2Win_10208;
extern D2Win_TEXTBOX_Create_10042_t D2Win_TEXTBOX_Create_10042;
extern D2Win_TEXTBOX_Destroy_10043_t D2Win_TEXTBOX_Destroy_10043;
extern D2Win_10047_t D2Win_10047;
extern D2Win_10062_t D2Win_10062;
extern D2Win_10045_t D2Win_10045;
extern D2Win_10046_t D2Win_10046;
extern D2Win_10044_t D2Win_10044;
extern D2Win_10051_t D2Win_10051;
extern D2Win_10198_t D2Win_10198;
extern D2Win_10057_t D2Win_10057;
extern D2Win_0_10058_t D2Win_0_10058;
extern D2Win_10197_t D2Win_10197;
extern D2Win_TEXTBOX_GetNumLines_10052_t D2Win_TEXTBOX_GetNumLines_10052;
extern D2Win_10054_t D2Win_10054;
extern D2Win_10049_t D2Win_10049;
extern D2Win_TEXTBOX_SetLine_10050_t D2Win_TEXTBOX_SetLine_10050;
extern D2Win_10053_t D2Win_10053;
extern D2Win_10055_t D2Win_10055;
extern D2Win_10048_t D2Win_10048;
extern D2Win_10196_t D2Win_10196;
extern D2Win_10056_t D2Win_10056;
extern D2Win_10059_t D2Win_10059;
extern D2Win_10060_t D2Win_10060;
extern D2Win_10061_t D2Win_10061;
extern D2Win_10187_t D2Win_10187;
extern D2Win_10188_t D2Win_10188;
extern D2Win_10190_t D2Win_10190;
extern D2Win_10191_t D2Win_10191;
extern D2Win_10192_t D2Win_10192;
extern D2Win_10193_t D2Win_10193;
extern D2Win_10194_t D2Win_10194;
extern D2Win_10195_t D2Win_10195;
extern D2Win_10204_t D2Win_10204;
extern D2Win_TEXTBOX_10203_t D2Win_TEXTBOX_10203;
extern D2Win_10180_t D2Win_10180;
extern D2Win_10182_t D2Win_10182;
