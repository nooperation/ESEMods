#include "D2Common/UnitRoom/UnitRoom_ESE.h"
#include "LibESE.h"

#include "D2Dungeon.h"

int __stdcall ESE_UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused)
{
	D2_MAYBE_UNUSED(nUnused);

	D2_ASSERT(pUnit);
	D2_ASSERT(pRoom);

	//Note: tRoomCoord is unused but filled in the original code
	//D2DrlgCoordsStrc tRoomCoord = {};
	//DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoord);

	D2CoordStrc tCoord = {};
	UNITS_GetCoords(pUnit, &tCoord);

	// D2_ASSERT(DungeonTestRoomGame(pRoom, tCoord.nX, tCoord.nY));
	if (!DungeonTestRoomGame(pRoom, tCoord.nX, tCoord.nY))
	{
		// ESE Hack: There was an assert on DungeonTestRoomGame, crashing whenever it would fail. Let's fake it instead of crashing...");

		tCoord.nX = pRoom->tCoords.nSubtileX + 1;
		tCoord.nY = pRoom->tCoords.nSubtileY + 1;
	}

	for (D2UnitStrc* i = pRoom->pUnitFirst; i; i = i->pRoomNext)
	{
		D2_ASSERTM(pUnit != i, "Unit being added to a room it is already in");
	}

	D2UnitStrc** ppUnitFirst = DUNGEON_GetUnitListFromRoom(pRoom);
	D2_ASSERT(ppUnitFirst);
	pUnit->pRoomNext = *ppUnitFirst;
	*ppUnitFirst = pUnit;

	UNITROOM_RefreshUnit(pUnit);

	if (pUnit->dwUnitType == UNIT_PLAYER || (pUnit->dwUnitType == UNIT_MONSTER && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_GOOD))
	{
		DUNGEON_IncreaseAlliedCountOfRoom(pRoom);
	}

	return 1;
}

int __stdcall ESE_UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
	return ESE_UNITROOM_AddUnitToRoomEx(pUnit, pRoom, 1);
}
