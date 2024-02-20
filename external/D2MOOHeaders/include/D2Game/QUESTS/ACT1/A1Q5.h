#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Countess
struct D2Act1Quest5Strc						//sizeof 0x120
{
	int nUnitGUIDs1[12];					//0x00 TODO: Which UnitGUIDs?
	short nUnitCount1;						//0x30
	uint8_t pad0x32[2];						//0x32
	int nUnitGUIDs2[12];					//0x34 TODO: Which UnitGUIDs?
	short nUnitCount2;						//0x64
	uint8_t pad0x66[2];						//0x66
	int nObjectGUIDs[8];					//0x68 TODO: Which objects?
	uint16_t nObjectCount;					//0x88
	uint8_t pad0x8A[2];						//0x8A
	D2QuestGUIDStrc tPlayerGUIDs;					//0x8C
	D2CoordStrc pCoord;						//0x110
	uint8_t bCountessKilled;				//0x118
	uint8_t bDeathMissilesCreated;			//0x119
	uint8_t bTriggerSeqFilter;				//0x11A
	uint8_t bTowerTomeActivated;			//0x11B
	uint8_t unk0x11C;						//0x11C TODO
	uint8_t pad0x11D[3];					//0x11D
};

#pragma pack()
