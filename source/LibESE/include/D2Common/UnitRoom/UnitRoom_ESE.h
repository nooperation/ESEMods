#include <../D2MooHeaders.h>
#include <Units/Missile.h>
#include <CommonDefinitions.h>
#include <D2Seed.h>
#include <Units/MissileStream.h>
#include <Path/Path.h>
#include "LibESE.h"

//D2Common.0x6FDBCF10 (#11279)
int __stdcall ESE_UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused);

//D2Common.0x6FDBD100 (#10384)
int __stdcall ESE_UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);
