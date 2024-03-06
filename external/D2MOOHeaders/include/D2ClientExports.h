#pragma once

#include <Windows.h>
#include <cstdint>

#include <Drlg/D2DrlgDrlg.h>
#include <D2StatList.h>
#include <Units/UnitFinds.h>

struct Unicode;

void InitD2ClientExports();

typedef void(__fastcall * D2Client_DrawTextCentered_t)(int nX, int nY, int maxWidthMaybe, const Unicode* text, int nColor);

extern D2Client_DrawTextCentered_t D2Client_DrawTextCentered;

extern int32_t * D2Client_pDWORD_6FBBA748; // 11A748
extern int32_t * D2Client_pDWORD_6fbba74c; // 11A74C
extern int32_t * D2Client_pDWORD_6fb740f0; // D40F0
