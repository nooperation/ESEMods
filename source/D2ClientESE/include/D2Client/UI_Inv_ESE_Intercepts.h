#pragma once

#include <D2Client/UI_Inv_ESE.h>
#include <../D2MooHeaders.h>
#include <cstdlib>

typedef void(__fastcall* UI_INV_DrawMouseOverItemFrame_t)(D2UnitStrc* pUnit, int32_t bFlag);

extern UI_INV_DrawMouseOverItemFrame_t UI_INV_DrawMouseOverItemFrame_Original;

//D2Client.0x6FAE1890 (41890)
void __fastcall ESE_INTERCEPT_UI_INV_DrawMouseOverItemFrame(D2UnitStrc* pUnit, int32_t bFlag);
