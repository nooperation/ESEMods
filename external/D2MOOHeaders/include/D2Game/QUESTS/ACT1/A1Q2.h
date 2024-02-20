#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//BloodRaven
struct D2Act1Quest2Strc						//sizeof 0x0C
{
	uint8_t unk0x00;								//0x00 TODO
	uint8_t unk0x01;								//0x01 TODO
	uint8_t bBloodravenKilled;						//0x02
	uint8_t bKashyaActivated;						//0x03
	int unk0x04;								//0x04 TODO
	int nBloodravenGUID;						//0x08
};

#pragma pack()
