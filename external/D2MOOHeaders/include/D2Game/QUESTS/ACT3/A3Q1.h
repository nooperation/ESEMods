#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//LamEsen
struct D2Act3Quest1Strc						//sizeof 0xA0
{
	uint8_t bCanGetReward;					//0x00
	uint8_t bTomeDropped;					//0x01
	uint8_t bTomeActive;					//0x02
	uint8_t unused0x03;						//0x03
	uint8_t bTomeAcquired;					//0x04
	uint8_t bPlayerWithTomeDropped;			//0x05
	uint8_t pad0x06[2];						//0x06
	int nTomesInGame;						//0x08
	uint8_t bTomeBroughtToAlkor;			//0x0C
	uint8_t pad0x0D[3];						//0x0D
	int nPlayerWithTomeGUID;				//0x10
	int nTomeGUID;							//0x14
	int nTomeObjectMode;					//0x18
	D2QuestGUIDStrc tPlayerGUIDs;					//0x1C
};

#pragma pack()
