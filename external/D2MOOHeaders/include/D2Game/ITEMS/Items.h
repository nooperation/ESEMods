#pragma once

#include <Units/Units.h>

#include <DataTbls/ItemsTbls.h>
#include <DataTbls/MonsterTbls.h>
#include <D2Items.h>

#pragma pack(1)

struct D2ItemDropStrc
{
	D2UnitStrc* pUnit;						//0x00
	D2SeedStrc* pSeed;						//0x04
	D2GameStrc* pGame;						//0x08
	int32_t nItemLvl;						//0x0C
	uint32_t unk0x10;						//0x10
	int32_t nId;							//0x14
	int32_t nSpawnType;						//0x18 [3 for ground spawn, 4 for inv spawn]
	int32_t nX;								//0x1C
	int32_t nY;								//0x20
	D2ActiveRoomStrc* pRoom;						//0x24
	uint16_t wUnitInitFlags;				//0x28
	uint16_t wItemFormat;					//0x2A [ptGame0x0x78]
	BOOL bForce;							//0x2C
	int32_t nQuality;						//0x30
	int32_t nQuantity;						//0x34
	int32_t nMinDur;						//0x38
	int32_t nMaxDur;						//0x3C
	int32_t nItemIndex;						//0x40
	uint32_t dwFlags1;						//0x44 - itemflag override (used when force is true)
	uint32_t dwSeed;						//0x48 - overrides the seed, used when force is true
	uint32_t dwItemSeed;					//0x4C - overrides the item seed when force is true
	int32_t eEarLvl;						//0x50
	int32_t nQtyOverride;					//0x54
	char szName[16];						//0x58
	int32_t nPrefix[3];						//0x68
	int32_t nSuffix[3];						//0x74
	uint32_t dwFlags2;						//0x80
};

#pragma pack()
