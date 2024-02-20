#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Hratli Gossip
struct D2Act3Quest0Strc						//sizeof 0x1C
{
	uint8_t bHratliStartCreated;			//0x00
	uint8_t bHratliEndCreated;				//0x01
	uint8_t bHratliEndObjectInitialized;	//0x02
	uint8_t bHratliStartIsPresent;			//0x03
	int nHratliX;							//0x04
	int nHratliY;							//0x08
	int nHratliGUID;						//0x0C
	uint8_t bHratliMapAIChanged;			//0x10
	uint8_t pad0x11[7];						//0x11
	D2MapAIStrc* pHratliMapAI;				//0x18
};

#pragma pack()
