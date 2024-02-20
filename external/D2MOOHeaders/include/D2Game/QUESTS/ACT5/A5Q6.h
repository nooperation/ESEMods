#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Baal
struct D2Act5Quest6Strc						//sizeof 0xA8
{
	D2QuestGUIDStrc tPlayerGUIDs;					//0x00
	uint8_t unused0x84;						//0x84
	uint8_t unused0x85;						//0x85
	uint8_t bWorldStoneChamberOpen;			//0x86
	uint8_t pad0x87;						//0x87
	int nPlayersInWorldStoneChamber;		//0x88
	D2ActiveRoomStrc* pRoom;						//0x8C
	uint8_t bQuestStarted;					//0x90
	uint8_t pad0x91[3];						//0x91
	int nBaalPortalObjectMode;				//0x94
	uint8_t bLastPortalOpened;				//0x98
	uint8_t pad0x99[3];						//0x99
	int nLastPortalObjectMode;				//0x9C
	uint8_t bZooInitialized;				//0xA0
	uint8_t pad0xA1[3];						//0xA1
	uint16_t nZooMonsterId;					//0xA4
	uint8_t pad0xA6[2];						//0xA6
};

#pragma pack()
