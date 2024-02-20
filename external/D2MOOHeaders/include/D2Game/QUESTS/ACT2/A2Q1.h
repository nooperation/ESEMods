#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Radament
struct D2Act2Quest1Strc						//sizeof 0x14
{
	uint8_t bRadamentKilled;				//0x00
	uint8_t pad0x01[3];						//0x01
	D2ActiveRoomStrc* pRoom;						//0x04
	uint8_t bAtmaActivated;					//0x08
	uint8_t unk0x09;						//0x09 TODO
	uint8_t bStatusTimerStarted;			//0x0A
	uint8_t pad0x0B;						//0x0B
	int nSkillBookDropCount;				//0x0C
	uint8_t bRewardPending;					//0x10
	uint8_t pad0x11[3];						//0x11
};

#pragma pack()
