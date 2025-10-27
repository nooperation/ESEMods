#pragma once

#include <chrono>
#include <thread>
#include <type_traits>
#include <cstdlib>
#include <algorithm>
#include "D2Seed.h"
#include <UNIT/SUnitDmg.h>


int64_t __fastcall ESE_DATATBLS_ApplyRatio(int64_t nValue, int64_t nMultiplier, int64_t nDivisor);
int64_t __fastcall ESE_ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int64_t nMax);

inline constexpr int32_t Clamp64To32(const int64_t value)
{
    return static_cast<int32_t>(std::clamp<int64_t>(value, INT_MIN, INT_MAX));
}
inline constexpr uint32_t Clamp64To32Unsigned(const int64_t value)
{
	return static_cast<uint32_t>(std::clamp<int64_t>(value, 0, UINT32_MAX));
}

std::wstring FormatWideString(const wchar_t* fmt, ...);
void AppendFormattedWideString(std::wstring& outBuff, const wchar_t* fmt, ...);
void AppendString(std::wstring& dest, const char* source);
std::wstring ToWideString(const char* source);
void ColorizeString(std::wstring& str, int32_t color);
void AppendColorizedString(std::wstring& dest, const std::wstring& src, int32_t color);

void ESE_D2Client_BuildItemName_6FADD360(D2UnitStrc* pItem, std::wstring& outBuff);

#pragma pack(push, 1)
struct D2DamageReportPacket
{
    uint8_t packetId;
    uint8_t isPlayerBeingAttacked;
    uint32_t unitId;
    int64_t damage;
};

struct ESE_D2DamageStrc
{
	ESE_D2DamageStrc();
	ESE_D2DamageStrc(const D2DamageStrc* src);
	void WriteToOriginalStruct(D2DamageStrc* dest);

	uint32_t dwHitFlags;					//0x00
	uint16_t wResultFlags;					//0x04
	uint16_t wExtra;						//0x06
	int64_t dwPhysDamage;					//0x08
	int64_t dwEnDmgPct;						//0x0C
	int64_t dwFireDamage;					//0x10
	int64_t dwBurnDamage;					//0x14
	int64_t dwBurnLen;						//0x18
	int64_t dwLtngDamage;					//0x1C
	int64_t dwMagDamage;					//0x20
	int64_t dwColdDamage;					//0x24
	int64_t dwPoisDamage;					//0x28
	int64_t dwPoisLen;						//0x2C
	int64_t dwColdLen;						//0x30
	int64_t dwFrzLen;						//0x34
	int64_t dwLifeLeech;					//0x38
	int64_t dwManaLeech;					//0x3C
	int64_t dwStamLeech;					//0x40
	int64_t dwStunLen;						//0x44
	int64_t dwAbsLife;						//0x48
	int64_t dwDmgTotal;						//0x4C
	uint32_t unk0x50;						//0x50
	int64_t dwPiercePct;					//0x54
	int64_t dwDamageRate;					//0x58
	uint32_t unk0x5C;						//0x5C
	uint32_t dwHitClass;					//0x60
	uint8_t nHitClassActiveSet;				//0x64
	int8_t nConvType;						//0x65
	uint8_t unk0x66[2];						//0x66
	int32_t dwConvPct;						//0x68
	int32_t nOverlay;						//0x6C
};

struct ESE_D2CombatStrc
{
	D2GameStrc* pGame;						//0x00
	uint32_t dwAttackerType;				//0x04
	uint32_t dwAttackerId;					//0x08
	uint32_t dwDefenderType;				//0x0C
	uint32_t dwDefenderId;					//0x10
	ESE_D2DamageStrc tDamage;					//0x14
	ESE_D2CombatStrc* pNext;					//0x84
};

struct ESE_D2DamageInfoStrc
{
	D2GameStrc* pGame;
	D2DifficultyLevelsTxt* pDifficultyLevelsTxt;
	D2UnitStrc* pAttacker;
	D2UnitStrc* pDefender;
	int32_t bAttackerIsMonster;
	int32_t bDefenderIsMonster;
	ESE_D2DamageStrc* pDamage;
	int64_t nDamageReduction[DAMAGE_REDUCTION_TYPES_COUNT];
};
#pragma pack(pop)

// External exports
typedef void(__fastcall* D2GL_d2glConfigQueryImpl_t)();
typedef void(__fastcall* D2GL_setCustomScreenSize_t)();
typedef void(__fastcall* D2GL_d2glGameDrawBegin_t)();
typedef void(__fastcall* D2GL_d2glAutomapDrawBegin_t)();
typedef void(__fastcall* D2GL_d2glAutomapDrawEnd_t)();
typedef void(__fastcall* D2GL_d2glUIDrawBegin_t)();
typedef void(__fastcall* D2GL_d2glUIDrawCursorItem_t)();
typedef void(__fastcall* D2GL_d2glUIDrawEnd_t)();
typedef void(__fastcall* D2GL_d2glDrawPerspectiveImage_t)();
typedef void(__fastcall* D2GL_d2glDrawShiftedImage_t)();
typedef void(__fastcall* D2GL_d2glDrawClippedImage_t)();
typedef void(__fastcall* D2GL_d2glDrawImageFast_t)();
typedef void(__fastcall* D2GL_d2glDrawShadow_t)();
typedef void(__fastcall* D2GL_d2glTakeScreenShot_t)();
typedef void(__fastcall* D2GL_d2glRectangledTextBegin_t)();
typedef void(__fastcall* D2GL_d2glRectangledTextEnd_t)();
typedef void(__fastcall* D2GL_d2glUnitHoverText_t)();
typedef void(__fastcall* D2GL_d2glDrawRectFrame_t)();
typedef void(__fastcall* D2GL_d2glDrawUnitHealthBar_t)();
typedef void(__fastcall* D2GL_d2glLoadUIImage_t)();
typedef void(__fastcall* D2GL_d2glDrawSubTextA_t)();
typedef void(__fastcall* D2GL_d2glDrawSubTextB_t)();
typedef void(__fastcall* D2GL_d2glDrawSubTextC_t)();
typedef void(__fastcall* D2GL_d2glDrawImage_t)();
typedef void(__fastcall* D2GL_d2glDrawVerticalCropImage_t)();
typedef void(__fastcall* D2GL_d2glDrawSolidRectEx_t)();
typedef void(__fastcall* D2GL_d2glDrawLine_t)();
typedef void(__fastcall* D2GL_d2glDrawGroundTile_t)();
typedef void(__fastcall* D2GL_d2glDrawWallTile_t)();
typedef void(__fastcall* D2GL_d2glDrawTransWallTile_t)();
typedef void(__fastcall* D2GL_d2glDrawShadowTile_t)();
typedef void(__fastcall* D2GL_d2glDrawNormalText_t)();
typedef void(__fastcall* D2GL_d2glDrawNormalTextEx_t)();
typedef void(__fastcall* D2GL_d2glDrawFramedText_t)();
typedef void(__fastcall* D2GL_d2glDrawRectangledText_t)();
typedef void(__fastcall* D2GL_d2glGetNormalTextWidth_t)();
typedef void(__fastcall* D2GL_d2glGetNormalTextNWidth_t)();
typedef void(__fastcall* D2GL_d2glGetFramedTextSize_t)();
typedef void(__fastcall* D2GL_d2glGetFontHeight_t)();
typedef void(__fastcall* D2GL_d2glSetTextSize_t)();
typedef void(__fastcall* D2GL_d2glAltItemsText_t)();
typedef void(__fastcall* D2GL_d2glLevelEntryText_t)();

typedef void(__cdecl* Sgd2fr_D2Client_DrawScreenBackground_t)();
typedef void(__cdecl* Sgd2fr_D2Client_SetScreenShift_t)();

extern D2GL_d2glConfigQueryImpl_t D2GL_d2glConfigQueryImpl;
extern D2GL_setCustomScreenSize_t D2GL_setCustomScreenSize;
extern D2GL_d2glGameDrawBegin_t D2GL_d2glGameDrawBegin;
extern D2GL_d2glAutomapDrawBegin_t D2GL_d2glAutomapDrawBegin;
extern D2GL_d2glAutomapDrawEnd_t D2GL_d2glAutomapDrawEnd;
extern D2GL_d2glUIDrawBegin_t D2GL_d2glUIDrawBegin;
extern D2GL_d2glUIDrawCursorItem_t D2GL_d2glUIDrawCursorItem;
extern D2GL_d2glUIDrawEnd_t D2GL_d2glUIDrawEnd;
extern D2GL_d2glDrawPerspectiveImage_t D2GL_d2glDrawPerspectiveImage;
extern D2GL_d2glDrawShiftedImage_t D2GL_d2glDrawShiftedImage;
extern D2GL_d2glDrawClippedImage_t D2GL_d2glDrawClippedImage;
extern D2GL_d2glDrawImageFast_t D2GL_d2glDrawImageFast;
extern D2GL_d2glDrawShadow_t D2GL_d2glDrawShadow;
extern D2GL_d2glTakeScreenShot_t D2GL_d2glTakeScreenShot;
extern D2GL_d2glRectangledTextBegin_t D2GL_d2glRectangledTextBegin;
extern D2GL_d2glRectangledTextEnd_t D2GL_d2glRectangledTextEnd;
extern D2GL_d2glUnitHoverText_t D2GL_d2glUnitHoverText;
extern D2GL_d2glDrawRectFrame_t D2GL_d2glDrawRectFrame;
extern D2GL_d2glDrawUnitHealthBar_t D2GL_d2glDrawUnitHealthBar;
extern D2GL_d2glLoadUIImage_t D2GL_d2glLoadUIImage;
extern D2GL_d2glDrawSubTextA_t D2GL_d2glDrawSubTextA;
extern D2GL_d2glDrawSubTextB_t D2GL_d2glDrawSubTextB;
extern D2GL_d2glDrawSubTextC_t D2GL_d2glDrawSubTextC;
extern D2GL_d2glDrawImage_t D2GL_d2glDrawImage;
extern D2GL_d2glDrawVerticalCropImage_t D2GL_d2glDrawVerticalCropImage;
extern D2GL_d2glDrawSolidRectEx_t D2GL_d2glDrawSolidRectEx;
extern D2GL_d2glDrawLine_t D2GL_d2glDrawLine;
extern D2GL_d2glDrawGroundTile_t D2GL_d2glDrawGroundTile;
extern D2GL_d2glDrawWallTile_t D2GL_d2glDrawWallTile;
extern D2GL_d2glDrawTransWallTile_t D2GL_d2glDrawTransWallTile;
extern D2GL_d2glDrawShadowTile_t D2GL_d2glDrawShadowTile;
extern D2GL_d2glDrawNormalText_t D2GL_d2glDrawNormalText;
extern D2GL_d2glDrawNormalTextEx_t D2GL_d2glDrawNormalTextEx;
extern D2GL_d2glDrawFramedText_t D2GL_d2glDrawFramedText;
extern D2GL_d2glDrawRectangledText_t D2GL_d2glDrawRectangledText;
extern D2GL_d2glGetNormalTextWidth_t D2GL_d2glGetNormalTextWidth;
extern D2GL_d2glGetNormalTextNWidth_t D2GL_d2glGetNormalTextNWidth;
extern D2GL_d2glGetFramedTextSize_t D2GL_d2glGetFramedTextSize;
extern D2GL_d2glGetFontHeight_t D2GL_d2glGetFontHeight;
extern D2GL_d2glSetTextSize_t D2GL_d2glSetTextSize;
extern D2GL_d2glAltItemsText_t D2GL_d2glAltItemsText;
extern D2GL_d2glLevelEntryText_t D2GL_d2glLevelEntryText;

extern Sgd2fr_D2Client_DrawScreenBackground_t Sgd2fr_D2Client_DrawScreenBackground;
extern Sgd2fr_D2Client_SetScreenShift_t Sgd2fr_D2Client_SetScreenShift;