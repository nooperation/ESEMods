#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Andariel
struct D2Act1Quest6Strc			//sizeof 0x198
{
	D2QuestGUIDStrc pGUID1;		//0x00
	D2QuestGUIDStrc pGUID2;		//0x84
	D2QuestGUIDStrc pGUID3;		//0x108
	int nAndarielGUID;			//0x18C
	short unk0x190;				//0x190 TODO
	short nTimerInvocations;	//0x192
	uint8_t bAndarielKilled;	//0x194
	uint8_t bCainActivated;		//0x195
	short pad0x196;				//0x196
};

#pragma pack()
