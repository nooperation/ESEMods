#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//HoradricStaff
struct D2Act2Quest2Strc						//sizeof 0x30
{
	int unused0x00[5];						//0x00
	int nItemDropCount;						//0x14
	int nBaseStaffs;						//0x18
	int nCubedStaffs;						//0x1C
	int nHoradricCubes;						//0x20
	int nAmulets;							//0x24
	uint8_t bHoradricScrollDropped;			//0x28
	uint8_t bCubeDropped;					//0x29
	uint8_t bStaffCubed;					//0x2A
	uint8_t unk0x2B;						//0x2B TODO
	int nPlayerGUID;						//0x2C
};

#pragma pack()
