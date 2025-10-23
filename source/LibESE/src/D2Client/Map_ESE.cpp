#include "D2Client/Map_ESE.h"
#include "../D2ClientExports.h"
#include "LibESE.h"
#include <D2Combat.h>
#include "Font.h"
#include <cinttypes>
#include <D2States.h>
#include <string>
#include "D2Gfx.h"
#include "D2Config.h"
#include <bitset>
#include <bit>

void __fastcall ESE_D2Client_Light_pActCallbackFunction_6FAA5E10(D2ActiveRoomStrc* a1)
{
    // I don't care about lighting stuff. it just crashes sometimes so we're not doing it.
}

//D2Client.0x6FB26C90 ()
D2ActiveRoomStrc* __fastcall ESE_D2Client_Unit_FindRoomContainingSubtile_6FB26C90(int nX, int nY)
{
    if (!nX && !nY)
    {
        return nullptr;
    }

    auto* hControlUnit1 = *D2Client_pOwner_6FBBC200;
    D2ActiveRoomStrc* hUnitRoom = nullptr;

    if (hControlUnit1)
    {
        auto* ownerRoom = UNITS_GetRoom(hControlUnit1);
        hUnitRoom = ownerRoom;

        if (ownerRoom)
        {
            // Check if the subtile coordinates are within the owner's room bounds
            if (nX >= ownerRoom->tCoords.nSubtileX &&
                nX < ownerRoom->tCoords.nSubtileX + ownerRoom->tCoords.nSubtileWidth &&
                nY >= ownerRoom->tCoords.nSubtileY &&
                nY < ownerRoom->tCoords.nSubtileY + ownerRoom->tCoords.nSubtileHeight)
            {
                // Coordinates are within the owner's room
                return hUnitRoom;
            }
            else
            {
                // Search adjacent rooms
                D2ActiveRoomStrc** pppRoomList = nullptr;
                int pNumRooms = 0;
                DUNGEON_GetAdjacentRoomsListFromRoom(hUnitRoom, &pppRoomList, &pNumRooms);

                if (pNumRooms > 0)
                {
                    // Iterate through adjacent rooms
                    for (auto roomIndex = 0; roomIndex < pNumRooms; ++roomIndex)
                    {
                        auto* roomIter = pppRoomList[roomIndex];
                        if (roomIter)
                        {
                            if (nX >= roomIter->tCoords.nSubtileX && nX < roomIter->tCoords.nSubtileX + roomIter->tCoords.nSubtileWidth)
                            {
                                if (nY >= roomIter->tCoords.nSubtileY && nY < roomIter->tCoords.nSubtileY + roomIter->tCoords.nSubtileHeight)
                                {
                                    return pppRoomList[roomIndex];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Fallback: search by subtile coordinates in current act
    auto* result = DUNGEON_FindRoomBySubtileCoordinates(*D2Client_pCurrentDrlgAct_6FBA7984, nX, nY);

    if (!result)
    {
        // ESE HACK: just use current room if we fail to find the target room. whatever. beats crashing.
        result = UNITS_GetRoom(hControlUnit1);
        if (!result)
        {
            char errorMessage[512];
            sprintf_s(
                errorMessage,
                512,
                "Unable to find room for unit...  hControlUnit:%8x  hUnitRoom:%8x  ghAct:%8x  nX:%d  nY:%d",
                hControlUnit1,
                hUnitRoom,
                D2Client_pCurrentDrlgAct_6FBA7984,
                nX,
                nY);
            FOG_DisplayWarning(errorMessage, "C:\\projects\\D2\\head\\Diablo2\\Source\\D2Client\\UNIT\\CUnit.cpp", 314);
            FOG_DisplayAssert("hFindRoom", "C:\\projects\\D2\\head\\Diablo2\\Source\\D2Client\\UNIT\\CUnit.cpp", 315);
            exit(-1);
        }
        else
        {
            OutputDebugStringA("Avoiding crash by setting found room to current room...");
        }
    }

    return result;
}

