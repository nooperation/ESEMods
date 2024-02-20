#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//DenOfEvil
struct D2Act1Quest1Strc						//sizeof 0x8C
{
	D2QuestGUIDStrc pQuestGUID;					//0x00
	uint8_t bFinished;								//0x84
	uint8_t bEnteredDen;							//0x85
	uint8_t bAkaraActivated;						//0x86
	uint8_t bTimerActive;							//0x87
	int nMonstersLeft;							//0x88
};

#pragma pack()
