#pragma once

#include <Units/Units.h>
#include <Drlg/D2DrlgDrlg.h>


#pragma pack(push, 1)
struct D2UnkMonCreateStrc
{
	D2GameStrc* pGame;						//0x00
	D2ActiveRoomStrc* pRoom;						//0x04
	D2RoomCoordListStrc* pRoomCoordList;	//0x08
	int32_t nMonsterId;						//0x0C
	int32_t nAnimMode;						//0x10
	int32_t nUnitGUID;						//0x14
	int32_t nX;								//0x18
	int32_t nY;								//0x1C
	int32_t field_20;						//0x20
	int16_t nFlags;							//0x24
};

struct D2UnkMonCreateStrc3
{
	int32_t nXOffset;						//0x00
	int32_t nYOffset;						//0x04
	int32_t nSpawnType;						//0x08
};

struct D2UnkMonCreateStrc2
{
	int32_t nRecordCount;					//0x00
	int32_t unk0x04;						//0x04
	uint8_t unk0x08;						//0x08
	uint8_t pad0x09[3];						//0x09
	D2UnkMonCreateStrc3 records[4];			//0x0C - Could be variable length, but at both locations where it's used, it's 4
};
#pragma pack(pop)
