#pragma once

#include <cstdint>

#include <Windows.h>
#include <D2Constants.h>

#include "DrawMode.h"
#include <DisplayType.h>


#pragma pack(push, 1)
struct D2PaletteTableStrc
{
	void* transPalettes[3];
	void* shadowLightGammaPalettes[49];
	void* standardShiftPalettes[13];
	void* pScreenPalette;
	void* pLuminancePalette;
	void* pDarkBlendPalette;
	void* pDarkenPalette;
	void* pStandardColorsPalette;
	uint8_t* unk0x118;
	uint8_t* unk0x11C;
	PALETTEENTRY datFilePalette[256];
};

struct D2GfxCellNodeStrc
{
	uint32_t unk;
};

struct D2GfxCellStrc
{
	BOOL bFlip;								//0x00
	uint32_t dwWidth;							//0x04
	uint32_t dwHeight;							//0x08
	int32_t nXOffset;							//0x0C
	int32_t nYOffset;							//0x10
	uint32_t unk0x14;							//0x14
	D2GfxCellNodeStrc* pCellNode;			//0x18
	uint32_t dwLength;							//0x1C
	uint8_t* pPixels;							//0x20
};

struct D2CellFileStrc
{
	uint32_t dwVersion;						//0x00
	struct
	{
		uint16_t dwFlags;
		uint8_t mylastcol;
		uint8_t mytabno : 1;
	};										//0x04
	uint32_t eFormat;							//0x08
	uint32_t dwTermination;					//0x0C
	int32_t nDirections;						//0x10
	int32_t nFrames;							//0x14
	D2GfxCellStrc* pGfxCells;				//0x18
};

struct D2GfxDataStrc
{
	D2GfxCellStrc* pCurrentCell;			//0x00
	D2CellFileStrc* pCellFile;				//0x04
	uint32_t nFrame;							//0x08
	uint32_t nDirection;						//0x0C
	int32_t nMaxDirections;						//0x10
	int32_t nMaxFrames;							//0x14
	uint32_t fFlags;							//0x18
	uint8_t fState;							//0x1C
	union									//0x1D
	{
		uint8_t nComponent;
		uint8_t fItemFlags;
	};
	uint8_t unk0x1E;							//0x1E - padding no doubt
	uint8_t unk0x1F;							//0x1F
	int32_t nUnitType;							//0x20
	int32_t nUnitIndex;							//0x24
	int32_t nMode;								//0x28
	int32_t nOverlay;							//0x2C
	union
	{
		struct
		{
			char szToken[4];				//0x30
			char szComponent[4];			//0x34
			char szArmorType[4];			//0x38 - lit, med, hvy
			char szMode[4];					//0x3C
			char szHitClass[4];				//0x40
		};
		uint32_t dwName[5];					//0x30
	};
	char* pName;							//0x44
};

struct D2GfxLightStrc
{
	uint8_t nIntensity;						//0x00
	uint8_t nRed;							//0x01
	uint8_t nGreen;							//0x02
	uint8_t nBlue;							//0x03
};

struct D2GfxLightExStrc
{
	uint8_t nIntensity;						//0x00
	uint8_t nRed;							//0x01
	uint8_t nGreen;							//0x02
	uint8_t nBlue;							//0x03
	int32_t nX;								//0x04
	int32_t nY;								//0x08
};

struct D2GfxLightExStrc;
struct D2TileLibraryEntryStrc;


struct D2GfxSettingsStrc
{
	BOOL bPerspectiveEnabled;				//0x00
	BOOL bPerspectiveCapable;				//0x04
	BOOL bLowQuality;						//0x08
	int32_t nGamma;							//0x0C
	BOOL bVSync;							//0x10
	BOOL bBlendedShadows;					//0x14
};

struct D2GfxHelperStrc
{
	void(__fastcall* pfFillYBufferTable)(uint8_t* ppvBits, int32_t nWidth, int32_t nHeight, int32_t a4);
	void(__fastcall* pfDrawVisTile)(uint8_t* a1, int32_t a2, int32_t a3);
	void(__fastcall* pfUnknown)(uint8_t* a1, int32_t a2, int32_t a3, uint8_t a4);
	void(__fastcall* pfFloorTileDraw)(D2TileLibraryEntryStrc* pTileLibraryEntry, int32_t nX, int32_t nY, D2GfxLightExStrc* pLightEx);
	void(__fastcall* pfTileDrawLit)(uint8_t* a1, int32_t a2, int32_t a3, int32_t* a4);
	void(__fastcall* pfDrawBlendedVisTile)(int32_t a1, int32_t a2, int32_t a3, uint8_t a4);
	void(__fastcall* pfDrawRoofTile)(int32_t a1, int32_t a2, int32_t a3, int32_t* a4, uint8_t a5);
};

struct D2GraphicsInterfaceStrc
{
	BOOL(__fastcall* pfDetect)(HINSTANCE);
	BOOL(__fastcall* pfInit)(D2GfxSettingsStrc* pSettings, const D2GfxHelperStrc* pHelpers);
	BOOL(__fastcall* pfClose)();
	BOOL(__fastcall* pfCreateSurface)(HWND hWnd, D2GameResolutionMode nResolutionMode);
	BOOL(__fastcall* pfCloseSurface)();
	void(__fastcall* pfPauseSurface)(HWND hWnd, D2GameResolutionMode nResolutionMode, int32_t nWindowState);
	BOOL(__fastcall* pfStartDraw)(int32_t bClear, uint8_t nRed, uint8_t nGreen, uint8_t nBlue);
	BOOL(__fastcall* pfEndDraw)();
	BOOL(__fastcall* pfBlit)();
	BOOL(__fastcall* pfChangeRes)(HWND hWnd, D2GameResolutionMode bForceResize);
	BOOL(__fastcall* pfGetBackBuffer)(uint8_t* pBuffer);
	BOOL(__fastcall* pfActivateWindow)();
	BOOL(__fastcall* pfSetOption)(int32_t nOption, int32_t nValue);
	BOOL(__fastcall* pfPlayCutscene)();
	void(__fastcall* pfOpenSmackCutscene)(const char* szFile, D2GameResolutionMode nResolutionMode, void* pfFrame);
	BOOL(__fastcall* pfCheckCutScene)();
	void(__fastcall* pfDecodeSmacker)(const char* szSmacker, uint8_t* pBuffer, int32_t nVersion);
	void(__fastcall* pfPlaySmacker)(void* pContext);
	void(__fastcall* pfCloseSmacker)(void* pContext);
	void* (__fastcall* pfGetCacheResults)();
	BOOL(__fastcall* pfGetDimensions)(int32_t* pWidth, int32_t* pHeight);
	void(__fastcall* pfSetGlobalScale)(int32_t nScaleFactor);
	BOOL(__fastcall* pfSetGamma)(int32_t nGamma);
	int32_t(__fastcall* pfGammaCanBeControlled)();
	void(__fastcall* pfUpdatePerspective)(int32_t nScaleX, int32_t nScaleY);
	void(__fastcall* pfPerspectiveTransform)(int32_t nPosX, int32_t nPosY, int32_t nBais, int32_t* pXAdjust, int32_t* pYAdjust);
	void(__fastcall* pfPerspectiveTransformScale)(int32_t nPosX, int32_t nPosY, int32_t nAngle, int32_t* pXAdjust, int32_t* pYAdjust, int32_t bOrder);
	void(__fastcall* pfPerspectiveClearScale)();
	void(__fastcall* pfSetPalette)(LPPALETTEENTRY pPalette);
	void(__fastcall* pfSetPaletteTables)(D2PaletteTableStrc* pPaletteTables);
	void(__fastcall* pfSetAmbientColor)(uint8_t nRed, uint8_t nGreen, uint8_t nBlue);
	int32_t(__fastcall* pfFloorTileDraw)(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int32_t nPosX, int32_t nPosY, int32_t nWorldXpos, int32_t nWorldYpos, uint8_t nAlpha, int32_t nScreenPanels, void* pTileData);
	void(__fastcall* pfCelFlatSpriteDraw)(D2GfxDataStrc* pData, int32_t nPosX, int32_t nPosY, uint32_t dwGamma, DrawMode eDrawMode, int32_t nScreenMode, uint8_t* pPalette);
	void(__fastcall* pfCelDraw)(D2GfxDataStrc* pData, int32_t nPosX, int32_t nPosY, uint32_t dwGamma, DrawMode eDrawMode, uint8_t* pPalette);
	void(__fastcall* pfCelDrawColor)(D2GfxDataStrc* pData, int32_t nPosX, int32_t nPosY, uint32_t dwGamma, DrawMode eDrawMode, int32_t nGlobalPaletteShift);
	void(__fastcall* pfCelDrawEx)(D2GfxDataStrc* pData, int32_t nPosX, int32_t nPosY, int32_t nSkipLines, int32_t nDrawLines, DrawMode eDrawMode);
	void(__fastcall* pfCelDrawShadow)(D2GfxDataStrc* pData, int32_t nPosX, int32_t nPosY);
	void(__fastcall* pfCelDrawHilight)(D2GfxDataStrc* pData, int32_t nPosX, int32_t nPosY, uint8_t nPaletteIndex);
	void(__fastcall* pfCelDrawClipped)(D2GfxDataStrc* pData, int32_t nPosX, int32_t nPosY, void* pCropRect, DrawMode eDrawMode);
	int32_t(__fastcall* pfTileDrawLit)(D2TileLibraryEntryStrc* pTile, int32_t nPosX, int32_t nPosY, D2GfxLightStrc* pLight, int32_t nScreenPanels);
	int32_t(__fastcall* pfTileDrawTrans)(D2TileLibraryEntryStrc* pTile, int32_t nPosX, int32_t nPosY, D2GfxLightStrc* pLight, int32_t nScreenPanels, uint8_t nAlpha);
	int32_t(__fastcall* pfShadowTileDraw)(D2TileLibraryEntryStrc* pTile, int32_t nPosX, int32_t nPosY, DrawMode eDrawMode, int32_t nScreenPanels);
	void(__fastcall* pfUtilDiamond)(RECT* pRect, uint8_t nPaletteIndex);
	void(__fastcall* pfUtilRect)(RECT* pRect, uint8_t nPaletteIndex);
	void(__fastcall* pfUtilFilledRect)(RECT* pRect, uint8_t nPaletteIndex);
	void(__fastcall* pfUtilPoint)(POINT* pPoint, uint8_t nSize, uint8_t nPaletteIndex);
	void(__fastcall* pfDrawBox)(int32_t nXStart, int32_t nYStart, int32_t nXEnd, int32_t nYEnd, uint32_t dwColor, DrawMode eDrawMode);
	void(__fastcall* pfDrawBoxAlpha)(int32_t nXStart, int32_t nYStart, int32_t nXEnd, int32_t nYEnd, uint32_t dwColor, uint8_t nAlpha);
	void(__fastcall* pfDrawLine)(int32_t nXStart, int32_t nYStart, int32_t nXEnd, int32_t nYEnd, uint32_t dwColor, uint8_t nAlpha);
	void(__fastcall* pfClearScreen)(int32_t bPartial);
	void(__fastcall* pfOutputString)(int32_t nPosX, int32_t nPosY, const char* szFormat, va_list va);
	void(__fastcall* pfDebugDraw)(uint32_t* pLight, uint32_t* pPlayerLight, int32_t nPosX, int32_t nPosY); // Related to lightmap debugging. Called from an unused stub in D2Client ?
	void(__fastcall* pfDebugFillBackBuffer)(int32_t nPosX, int32_t nPosY);
	void(__fastcall* pfClearCaches)();
};
#pragma pack(pop)
