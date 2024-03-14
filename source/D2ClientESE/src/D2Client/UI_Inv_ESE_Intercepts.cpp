#include "D2Client/UI_Inv_ESE_Intercepts.h"
#include "LibESE.h"

extern UI_INV_DrawMouseOverItemFrame_t UI_INV_DrawMouseOverItemFrame_Original = nullptr;

//D2Client.0x6FAE1890 (41890)
void __fastcall ESE_INTERCEPT_UI_INV_DrawMouseOverItemFrame_6FAE1890(D2UnitStrc* pUnit, int32_t bFlag)
{
    ESE_UI_INV_DrawMouseOverItemFrame_6FAE1890(pUnit, bFlag);
}
