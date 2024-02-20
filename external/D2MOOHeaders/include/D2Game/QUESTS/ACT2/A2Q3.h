#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//TaintedSun
struct D2Act2Quest3Strc						//sizeof 0xA0
{
	uint8_t unused0x00;						//0x00
	uint8_t bDarkenTimerCreated;			//0x01
	uint8_t bRewarded;						//0x02
	uint8_t bBlackened;						//0x03
	uint8_t bAltarDestroyed;				//0x04
	uint8_t bAltarInitialized;				//0x05
	uint8_t unk0x06;						//0x06 TODO
	uint8_t pad0x07;						//0x07
	int nAltarMode;							//0x08
	int nAltarGUID;							//0x0C
	D2ActiveRoomStrc* pRoom;						//0x10
	D2QuestGUIDStrc tPlayerGUIDs;					//0x14
	int nAltarLevelId;						//0x98
	int nViperAmuletDropCount;				//0x9C
};

#pragma pack()
