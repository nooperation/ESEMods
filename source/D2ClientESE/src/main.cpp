#include <Windows.h>
#include <../D2MooHeaders.h>
#include <../D2CommonExports.h>
#include "LibESE.h"

D2GL_d2glConfigQueryImpl_t D2GL_d2glConfigQueryImpl = nullptr;
D2GL_setCustomScreenSize_t D2GL_setCustomScreenSize = nullptr;
D2GL_d2glGameDrawBegin_t D2GL_d2glGameDrawBegin = nullptr;
D2GL_d2glAutomapDrawBegin_t D2GL_d2glAutomapDrawBegin = nullptr;
D2GL_d2glAutomapDrawEnd_t D2GL_d2glAutomapDrawEnd = nullptr;
D2GL_d2glUIDrawBegin_t D2GL_d2glUIDrawBegin = nullptr;
D2GL_d2glUIDrawCursorItem_t D2GL_d2glUIDrawCursorItem = nullptr;
D2GL_d2glUIDrawEnd_t D2GL_d2glUIDrawEnd = nullptr;
D2GL_d2glDrawPerspectiveImage_t D2GL_d2glDrawPerspectiveImage = nullptr;
D2GL_d2glDrawShiftedImage_t D2GL_d2glDrawShiftedImage = nullptr;
D2GL_d2glDrawClippedImage_t D2GL_d2glDrawClippedImage = nullptr;
D2GL_d2glDrawImageFast_t D2GL_d2glDrawImageFast = nullptr;
D2GL_d2glDrawShadow_t D2GL_d2glDrawShadow = nullptr;
D2GL_d2glTakeScreenShot_t D2GL_d2glTakeScreenShot = nullptr;
D2GL_d2glRectangledTextBegin_t D2GL_d2glRectangledTextBegin = nullptr;
D2GL_d2glRectangledTextEnd_t D2GL_d2glRectangledTextEnd = nullptr;
D2GL_d2glUnitHoverText_t D2GL_d2glUnitHoverText = nullptr;
D2GL_d2glDrawRectFrame_t D2GL_d2glDrawRectFrame = nullptr;
D2GL_d2glDrawUnitHealthBar_t D2GL_d2glDrawUnitHealthBar = nullptr;
D2GL_d2glLoadUIImage_t D2GL_d2glLoadUIImage = nullptr;
D2GL_d2glDrawSubTextA_t D2GL_d2glDrawSubTextA = nullptr;
D2GL_d2glDrawSubTextB_t D2GL_d2glDrawSubTextB = nullptr;
D2GL_d2glDrawSubTextC_t D2GL_d2glDrawSubTextC = nullptr;
D2GL_d2glDrawImage_t D2GL_d2glDrawImage = nullptr;
D2GL_d2glDrawVerticalCropImage_t D2GL_d2glDrawVerticalCropImage = nullptr;
D2GL_d2glDrawSolidRectEx_t D2GL_d2glDrawSolidRectEx = nullptr;
D2GL_d2glDrawLine_t D2GL_d2glDrawLine = nullptr;
D2GL_d2glDrawGroundTile_t D2GL_d2glDrawGroundTile = nullptr;
D2GL_d2glDrawWallTile_t D2GL_d2glDrawWallTile = nullptr;
D2GL_d2glDrawTransWallTile_t D2GL_d2glDrawTransWallTile = nullptr;
D2GL_d2glDrawShadowTile_t D2GL_d2glDrawShadowTile = nullptr;
D2GL_d2glDrawNormalText_t D2GL_d2glDrawNormalText = nullptr;
D2GL_d2glDrawNormalTextEx_t D2GL_d2glDrawNormalTextEx = nullptr;
D2GL_d2glDrawFramedText_t D2GL_d2glDrawFramedText = nullptr;
D2GL_d2glDrawRectangledText_t D2GL_d2glDrawRectangledText = nullptr;
D2GL_d2glGetNormalTextWidth_t D2GL_d2glGetNormalTextWidth = nullptr;
D2GL_d2glGetNormalTextNWidth_t D2GL_d2glGetNormalTextNWidth = nullptr;
D2GL_d2glGetFramedTextSize_t D2GL_d2glGetFramedTextSize = nullptr;
D2GL_d2glGetFontHeight_t D2GL_d2glGetFontHeight = nullptr;
D2GL_d2glSetTextSize_t D2GL_d2glSetTextSize = nullptr;
D2GL_d2glAltItemsText_t D2GL_d2glAltItemsText = nullptr;
D2GL_d2glLevelEntryText_t D2GL_d2glLevelEntryText = nullptr;

Sgd2fr_D2Client_DrawScreenBackground_t Sgd2fr_D2Client_DrawScreenBackground = nullptr;
Sgd2fr_D2Client_SetScreenShift_t Sgd2fr_D2Client_SetScreenShift = nullptr;

BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		InitD2MooHeaders();
		InitD2CommonExports();
		InitD2FogExports();
		InitD2WinExports();
		InitD2ClientExports();
		InitD2LangExports();
		InitD2GfxExports();
		break;
	}
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}
