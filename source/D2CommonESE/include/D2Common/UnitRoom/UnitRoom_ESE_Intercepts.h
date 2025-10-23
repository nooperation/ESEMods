#pragma once

#include <D2Common/UnitRoom/UnitRoom_ESE.h>

#include <CommonDefinitions.h>
#include <../D2CommonExports.h>
#include <D2Seed.h>
#include <Units/MissileStream.h>
#include <Path/Path.h>

#include <cstdlib>

extern D2Common_11279_UNITROOM_AddUnitToRoomEx_t D2Common_11279_UNITROOM_AddUnitToRoomEx_Original;
extern D2Common_10384_UNITROOM_AddUnitToRoom_t D2Common_10384_UNITROOM_AddUnitToRoom_Original;

int __stdcall ESE_INTERCEPT_UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused);
int __stdcall ESE_INTERCEPT_UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);
