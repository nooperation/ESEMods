#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//RescueBarbarians
struct D2Act5Quest2Strc						//sizeof 0x160
{
	D2QuestGUIDStrc tPlayerGUIDs;					//0x00
	uint8_t bQualKehkActivated;				//0x84
	uint8_t unused0x85;						//0x85
	uint8_t bWussiesSpawned[3];				//0x86
	uint8_t pad0x89[3];						//0x89
	D2CoordStrc pWussieCoords[3];			//0x8C
	int nSpawnedWussies;					//0xA4
	int nKilledWussies;						//0xA8
	int nFreedWussies;						//0xAC
	int unk0xB0[15];						//0xB0 TODO: Some UnitGUIDs
	int nPortalGUIDs[3];					//0xEC
	uint8_t bPortalSpawned[3];				//0xF8
	uint8_t pad0xFB;						//0xFB
	int nPortalUpdateInvocations[3];		//0xFC
	uint8_t unk0x108[3];					//0x108 TODO: Some boolean
	uint8_t bChangeToSpecialObjectMode[3];	//0x10C
	uint8_t unk0x10E[3];					//0x10E TODO: Some boolean
	uint8_t pad0x111[3];					//0x111
	int unk0x114[3];						//0x114 TODO: Some Counter
	int nFreedWussieUnitGUIDs[15];			//0x120
	int nWussiesInRangeToDoor;				//0x15C
};

#pragma pack()
