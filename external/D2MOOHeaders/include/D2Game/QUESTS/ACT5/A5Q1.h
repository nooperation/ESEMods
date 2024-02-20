#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Siege
struct D2Act5Quest1Strc						//sizeof 0x18
{
	D2MapAIStrc* pLarzukMapAI;					//0x00
	D2ActiveRoomStrc* pRoom;							//0x04
	uint8_t bLarzukStartActivated;					//0x08
	uint8_t unused0x09[7];							//0x09
	int nLarzukGUID;							//0x10
	uint8_t unused0x14;							//0x14
	uint8_t bLarzukSpawned;						//0x15
	uint8_t bLarzukEndActivated;					//0x16
	uint8_t bLarzukMapAIChanged;					//0x17
};

#pragma pack()
