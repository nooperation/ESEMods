#include "D2Client/Map_ESE_Intercepts.h"
#include "LibESE.h"

extern D2Client_Unit_FindRoomContainingSubtile_6FB26C90_t D2Client_Unit_FindRoomContainingSubtile_6FB26C90_Original = nullptr;
extern D2Client_Light_pActCallbackFunction_6FAA5E10_t D2Client_Light_pActCallbackFunction_6FAA5E10_Original = nullptr;

//D2Client.0x6FB26C90 ()
D2ActiveRoomStrc* __fastcall ESE_INTERCEPT_D2Client_Unit_FindRoomContainingSubtile_6FB26C90(int nX, int nY)
{
    auto result = ESE_D2Client_Unit_FindRoomContainingSubtile_6FB26C90(nX, nY);
    return result;
}

//D2Client.0x6FAA5E10 ()
void __fastcall ESE_INTERCEPT_D2Client_Light_pActCallbackFunction_6FAA5E10(D2ActiveRoomStrc* a1)
{
  //  D2Client_Light_pActCallbackFunction_6FAA5E10_Original(a1);
    ESE_D2Client_Light_pActCallbackFunction_6FAA5E10(a1);
}
