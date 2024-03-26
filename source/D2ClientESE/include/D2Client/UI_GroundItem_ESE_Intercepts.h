#pragma once

#include <D2Client/UI_GroundItem_ESE.h>
#include <../D2MooHeaders.h>
#include <cstdlib>

typedef void(__fastcall* D2Client_DrawGroundItemMouseOverText_6FB20A30_t)(D2UnitStrc* pUnit);
typedef void(__fastcall* D2Client_DrawGroundItemText_sub_6FB20740_t)(D2UnitStrc* pItem, struct Unicode* outBuff, int outBuffSize);

extern D2Client_DrawGroundItemMouseOverText_6FB20A30_t D2Client_DrawGroundItemMouseOverText_6FB20A30_Original;
extern D2Client_DrawGroundItemText_sub_6FB20740_t D2Client_DrawGroundItemText_sub_6FB20740_Original;

//D2Client.0x6FB20A30 (80A30)
void __fastcall ESE_INTERCEPT_D2Client_DrawGroundItemMouseOverText_6FB20A30(D2UnitStrc* pUnit);

//D2Client.0x6FB20740 ()
void __fastcall ESE_INTERCEPT_D2Client_DrawGroundItemText_sub_6FB20740(D2UnitStrc* pItem, struct Unicode* outBuff, int outBuffSize);
