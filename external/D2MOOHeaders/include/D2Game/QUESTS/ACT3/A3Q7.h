#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//DarkWanderer
struct D2Act3Quest7Strc						//sizeof 0x14
{
	uint8_t bDarkWandererInitialized;		//0x00
	uint8_t bPrimaryGoalOpen;				//0x01
	uint8_t bWandererCoordsCalculated;		//0x02
	uint8_t pad0x03;						//0x03
	int nDarkWandererX;						//0x04
	int nDarkWandererY;						//0x08
	uint8_t bVileDogsSpawned;				//0x0C
	uint8_t bVileDogSpawnTimerCreated;		//0x0D
	uint8_t pad0x0E[2];						//0x0E
	int nDarkWandererGUID;					//0x10
};

#pragma pack()
