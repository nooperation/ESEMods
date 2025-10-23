#include "D2Common/UnitRoom/UnitRoom_ESE_Intercepts.h"
#include "LibESE.h"

#include <Units/UnitRoom.h>
#include "../D2MooHeaders.h"

#include "D2Dungeon.h"
#include "D2StatList.h"
#include "Units/Units.h"
#include "Path/Path.h"


D2Common_11279_UNITROOM_AddUnitToRoomEx_t D2Common_11279_UNITROOM_AddUnitToRoomEx_Original = nullptr;
D2Common_10384_UNITROOM_AddUnitToRoom_t D2Common_10384_UNITROOM_AddUnitToRoom_Original = nullptr;

int __stdcall ESE_INTERCEPT_UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused)
{
    return ESE_UNITROOM_AddUnitToRoomEx(pUnit, pRoom, nUnused);
}

int __stdcall ESE_INTERCEPT_UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    return ESE_UNITROOM_AddUnitToRoom(pUnit, pRoom);
}
