#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Summoner
struct D2Act2Quest5Strc						//sizeof 0x0C
{
	uint8_t bSummonerKilled;				//0x00
	uint8_t unk0x01;						//0x01 TODO
	uint8_t pad0x02[2];						//0x02
	D2ActiveRoomStrc* pRoom;						//0x04
	uint8_t bStatusTimerStarted;			//0x08
	uint8_t unk0x09;						//0x09 TODO
	uint8_t pad0x0A[2];						//0x0A
};

#pragma pack()
