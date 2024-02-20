#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Khalim
struct D2Act3Quest2Strc						//sizeof 0xB0
{
	uint8_t bSewerStairsInitialized;		//0x00
	uint8_t bInitiallyTalkedToCain;			//0x01
	uint8_t pad0x02[2];						//0x02
	int nSewerStairsObjectGUID;				//0x04
	int nSewerStairsObjectMode;				//0x08
	int nItemDropCount;						//0x0C
	int nEyesDropped;						//0x10
	int nBrainsDropped;						//0x14
	int nHeartsDropped;						//0x18
	int nFlailsDropped;						//0x1C
	int nCubedFlails;						//0x20
	bool bEyeDropped;						//0x24
	bool bBrainDropped;						//0x25
	bool bHeartDropped;						//0x26
	bool bFlailDropped;						//0x27
	int unused0x28;							//0x28
	D2QuestGUIDStrc tPlayerGUIDs;					//0x2C
};

#pragma pack()
