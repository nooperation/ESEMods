#pragma once

#include "CommonDefinitions.h"
#include <Drlg/D2DrlgDrlg.h>

// Helper function, official name coming from D2Common.0x6FDBCF10
inline bool DungeonTestRoomGame(const D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    return nX >= pRoom->tCoords.nSubtileX && nX < (pRoom->tCoords.nSubtileX + pRoom->tCoords.nSubtileWidth)
        && nY >= pRoom->tCoords.nSubtileY && nY < (pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight);

}
// Helper function
inline D2ActiveRoomStrc* __fastcall DUNGEON_GetRoomAtPosition(D2ActiveRoomStrc* pRoom, int32_t nSubtileX, int32_t nSubtileY)
{
    if (!pRoom)
    {
        return nullptr;
    }

    if (DungeonTestRoomGame(pRoom, nSubtileX, nSubtileY))
    {
        return pRoom;
    }

    D2ActiveRoomStrc** ppRoomList = nullptr;
    int32_t nNumRooms = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    for (int32_t i = 0; i < nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pAdjacentRoom = ppRoomList[i];
        if (pAdjacentRoom && DungeonTestRoomGame(pAdjacentRoom, nSubtileX, nSubtileY))
        {
            return pAdjacentRoom;
        }
    }

    return nullptr;
}
