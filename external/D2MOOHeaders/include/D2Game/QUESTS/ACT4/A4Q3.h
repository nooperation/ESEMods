#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Hellforge
struct D2Act4Quest3Strc						//sizeof 0x20
{
	short nHellforgeObjectMode;				//0x00
	uint8_t bCainActivated;					//0x02
	uint8_t bRewardDropsPending;			//0x03
	uint8_t bSoulstoneSmashed;				//0x04
	uint8_t pad0x05[3];						//0x05
	int nGemDropTier;						//0x08
	int nHits;								//0x0C
	int nHellforgeHammersInGame;			//0x10
	int nPlayersInAct;						//0x14
	int unused0x18;							//0x18
	uint8_t bSoulstoneAcquired;				//0x1C
	uint8_t pad0x1D[3];						//0x1D
};

#pragma pack()
