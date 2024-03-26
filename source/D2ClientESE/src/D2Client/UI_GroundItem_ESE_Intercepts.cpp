#include "D2Client/UI_GroundItem_ESE_Intercepts.h"
#include "LibESE.h"

extern D2Client_sub_6FB20A30_t D2Client_sub_6FB20A30_Original = nullptr;

//D2Client.0x6FB20A30 (80A30)
void __fastcall ESE_INTERCEPT_D2Client_sub_6FB20A30(D2UnitStrc* pUnit)
{
    //D2Client_sub_6FB20A30_Original(pUnit);
    ESE_D2Client_sub_6FB20A30(pUnit);
}
