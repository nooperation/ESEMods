#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Malus
struct D2Act1Quest3Strc						//sizeof 0xA4
{
	uint8_t unk0x00;						//0x00 TODO
	uint8_t bMalusInitialized;				//0x01
	uint8_t bCharsiIntroActivated;			//0x02
	uint8_t bCharsiEndActivated;			//0x03
	int nMalusGUID;							//0x04
	uint8_t unk0x08;						//0x08 TODO
	uint8_t unused0x09[9];					//0x09
	uint16_t unk0x12;						//0x12
	D2QuestGUIDStrc tPlayerGUIDs;					//0x14
	int nMalusObjectMode;					//0x98
	int nMalusItemsInGame;					//0x9C
	uint8_t bMalusAcquired;					//0xA0
	uint8_t bStartingPlayerHasMalus;		//0xA1
	uint8_t pad0xA2[2];						//0xA2
};

#pragma pack()
