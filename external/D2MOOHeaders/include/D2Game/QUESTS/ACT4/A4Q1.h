#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Izual
struct D2Act4Quest1Strc				//sizeof 0x1C
{
	int unused0x00;					//0x00
	D2CoordStrc pCoords;			//0x04
	uint8_t unk0x0C;				//0x0C TODO
	uint8_t bIzualGhostIsSpawning;	//0x0D
	uint8_t unused0x0E;				//0x0E
	uint8_t unk0x0F;				//0x0F TODO
	uint8_t bNeedToSpawnIzualGhost;	//0x10
	uint8_t bTyraelActivated;		//0x11
	uint8_t bIzualGhostActivated;	//0x12
	uint8_t pad0x13;				//0x13
	D2UnitStrc* pTargetUnit;		//0x14
	uint8_t bCloseToIzualGhost;		//0x18
	uint8_t pad0x19[3];				//0x19
};

#pragma pack()
