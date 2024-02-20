#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Mephisto/BlackTemple
struct D2Act3Quest6Strc						//sizeof 0x34
{
	uint8_t bTimerStarted;					//0x00
	uint8_t bHellGatePortalInitialized;		//0x01
	uint8_t bMephistoBridgeInitialized;		//0x02
	uint8_t bOrmusActivated;				//0x03
	int nHellGatePortalGUID;				//0x04
	int nMephistoBridgeGUID;				//0x08
	int nHellGatePortalObjectMode;			//0x0C
	int nMephistoBridgeObjectMode;			//0x10
	int nSoulStonesDropped;					//0x14
	uint8_t bSoulStoneDropped;				//0x18
	uint8_t pad0x19[3];						//0x19
	int nSoulstonesToDrop;					//0x1C
	uint8_t bNatalyaSpawned;				//0x20
	uint8_t pad0x21[3];						//0x21
	D2MapAIStrc* pNatalyaMapAI;				//0x24
	uint8_t unused0x28[4];					//0x28
	int nNatalyaGUID;						//0x2C
	uint8_t bNatalyaMapAIChanged;			//0x30
	uint8_t pad0x31[3];						//0x31
};

#pragma pack()
