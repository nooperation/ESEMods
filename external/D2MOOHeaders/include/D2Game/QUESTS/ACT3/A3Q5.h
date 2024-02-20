#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Council
struct D2Act3Quest5Strc						//sizeof 0x50
{
	int nLastKilledMonsterGUID;				//0x00
	uint8_t bOrmusActivated;				//0x04
	uint8_t bMonstersSpawned;				//0x05
	uint8_t pad0x06[2];						//0x06
	int bQuest1RewardGranted;				//0x08
	uint8_t bOrbSmashed;					//0x0C
	uint8_t bFlailDropped;					//0x0D
	uint8_t bCubeDropped;					//0x0E
	uint8_t pad0x0F;						//0x0F
	int nMonsterGUIDs[6];					//0x10
	uint8_t bCompellingOrbSpawned;			//0x28
	uint8_t pad0x29[3];						//0x29
	int nCompellingOrbGUID;					//0x2C
	int nSpawnCount;						//0x30
	int nMonstersLeftToKill;				//0x34
	int nHits;								//0x38
	int nFlailsMissing;						//0x3C
	int nHoradricCubesMissing;				//0x40
	uint8_t unused0x44[12];					//0x44
};

#pragma pack()
