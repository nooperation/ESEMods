#pragma once

#include <D2Client/Map_ESE.h>
#include <../D2MooHeaders.h>
#include <cstdlib>

typedef D2ActiveRoomStrc* (__fastcall* D2Client_Unit_FindRoomContainingSubtile_6FB26C90_t)(int nX, int nY);
typedef void (__fastcall* D2Client_Light_pActCallbackFunction_6FAA5E10_t)(D2ActiveRoomStrc* a1);

extern D2Client_Unit_FindRoomContainingSubtile_6FB26C90_t D2Client_Unit_FindRoomContainingSubtile_6FB26C90_Original;
extern D2Client_Light_pActCallbackFunction_6FAA5E10_t D2Client_Light_pActCallbackFunction_6FAA5E10_Original;

//D2Client.0x6FB26C90 ()
D2ActiveRoomStrc* __fastcall ESE_INTERCEPT_D2Client_Unit_FindRoomContainingSubtile_6FB26C90(int nX, int nY);


void __fastcall ESE_INTERCEPT_D2Client_Light_pActCallbackFunction_6FAA5E10(D2ActiveRoomStrc* a1);
