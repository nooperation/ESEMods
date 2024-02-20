#pragma once

#include <Units/Units.h>
#include <Drlg/D2DrlgPreset.h>

#include <GAME/Event.h>

#pragma pack(push, 1)
struct D2UnitInfoStrc		// sizeof(0x34)
{
	int32_t nUnitType;		// 0x00
	int32_t nClassId;		// 0x04
	int32_t nUnitGUID;		// 0x08
	int32_t nAnimMode;		// 0x0C
	int32_t nX;				// 0x10
	int32_t nY;				// 0x14
	int32_t nOwnerType;		// 0x18
	int32_t nOwnerGUID;		// 0x1C
	int32_t unk0x20;		// 0x20
	char szDescription[16];	// 0x24
};

struct D2UnitDescriptionListStrc
{
	uint32_t nClassId;					//0x00
	uint32_t nCount;					//0x04
	uint32_t nDefaultCount;				//0x08 Always 0 in 1.10f. Used to be added to nCount for display on the server
	char szDescription[128];			//0x0C
	D2UnitDescriptionListStrc* pNext;	//0x8C
}; // Size=0x90
#pragma pack(pop)
