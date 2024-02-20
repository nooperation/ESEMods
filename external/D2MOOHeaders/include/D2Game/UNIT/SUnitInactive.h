#pragma once

#include <Units/Units.h>

#pragma pack(1)

struct D2MinionListStrc
{
	D2UnitGUID dwMinionGUID;						//0x00
	D2MinionListStrc* pNext;				//0x04
};

struct D2InactiveItemNodeStrc
{
	D2InactiveItemNodeStrc* pNext;			//0x00
	int32_t nFrame;								//0x04
	int32_t nOwnerId;							//0x08
	uint16_t nBitstreamSize;					//0x0C
	uint8_t pBitstream;						//0x0E - dynamic size dependent on item serialization
};

struct D2InactiveMonsterNodeStrc
{
	int32_t nX;									//0x00
	int32_t nY;									//0x04
	int32_t nClassId;							//0x08
	int32_t nUnitId;							//0x0C
	int32_t nUnitFlags;							//0x10
	int32_t nUnitFlagsEx;						//0x14
	int32_t nTypeFlags;							//0x18
	int32_t unk0x1C;							//0x1C
	D2MinionListStrc* pMinionList;			//0x20
	D2MapAIStrc* pMapAI;					//0x24
	int32_t nSpecialAiState;					//0x28
	int32_t nLevelId;							//0x2C
	uint16_t nNameSeed;							//0x30
	uint8_t nMonUMods[9];						//0x32
	uint8_t unk0x3B;							//0x3B
	uint16_t nBossHcIdx;						//0x3C
	uint16_t unk0x3E;							//0x3E
	int32_t nExperience;						//0x40
	int32_t nMaxHitpoints;						//0x44
	int32_t nHitpoints;							//0x48
	int32_t nCmdParam1;							//0x4C
	int32_t nCmdParam2;							//0x50
	int32_t nGameFrame;							//0x54
	D2InactiveMonsterNodeStrc* pNext;		//0x58
};

struct D2InactiveUnitNodeStrc
{
	int32_t nX;									//0x00
	int32_t nY;									//0x04
	int32_t nUnitType;							//0x08
	int32_t nClassId;							//0x0C
	int32_t nAnimMode;							//0x10
	int32_t nGameFrame;							//0x14
	int32_t nUnitFlags;							//0x18
	int32_t nUnitFlagsEx;						//0x1C
	int32_t nUnitId;							//0x20
	int32_t nFrame;								//0x24
	uint8_t nInteractType;						//0x28
	uint8_t unk0x29;							//0x29
	uint16_t unk0x2A;							//0x2A
	int32_t nDropItemCode;						//0x2C
	D2InactiveUnitNodeStrc* pNext;			//0x30
};

struct D2InactiveUnitListStrc
{
	int32_t nX;											//0x00
	int32_t nY;											//0x04
	D2InactiveItemNodeStrc* pInactiveItems;			//0x08
	D2InactiveMonsterNodeStrc* pInactiveMonsters;	//0x0C
	D2InactiveUnitNodeStrc* pInactiveUnits;			//0x10
	D2InactiveUnitListStrc* pNext;					//0x14
};

#pragma pack()
