#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Nihlathak
struct D2Act5Quest4Strc						//sizeof 0x90
{
	D2QuestGUIDStrc tPlayerGUIDs;					//0x00
	uint8_t unused0x84;						//0x84
	uint8_t bTimerActive;					//0x85
	uint8_t bDrehyaActivated;				//0x86
	uint8_t bNeedsToOpenPortal;				//0x87
	uint8_t bPortalCreated;					//0x88
	uint8_t bWaypointNotActivated;			//0x89
	uint8_t pad0x8A[2];						//0x8A
	D2ActiveRoomStrc* pRoom;						//0x8C
};

#pragma pack()
