#include "D2Client/UI_GroundItem_ESE_Intercepts.h"
#include "LibESE.h"

extern D2Client_DrawGroundItemMouseOverText_6FB20A30_t D2Client_DrawGroundItemMouseOverText_6FB20A30_Original = nullptr;
extern D2Client_DrawGroundItemText_sub_6FB20740_t D2Client_DrawGroundItemText_sub_6FB20740_Original = nullptr;

//D2Client.0x6FB20A30 (80A30)
void __fastcall ESE_INTERCEPT_D2Client_DrawGroundItemMouseOverText_6FB20A30(D2UnitStrc* pUnit)
{
    ESE_D2Client_DrawGroundItemMouseOverText_6FB20A30(pUnit);
}

//D2Client.6FB20740 ()
void __fastcall ESE_INTERCEPT_D2Client_DrawGroundItemText_sub_6FB20740(D2UnitStrc* pItem, struct Unicode* outBuff, int outBuffSize)
{
    ESE_D2Client_DrawGroundItemText_sub_6FB20740(pItem, outBuff, outBuffSize);
}
