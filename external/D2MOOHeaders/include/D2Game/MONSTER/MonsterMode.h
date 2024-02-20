#pragma once

#include <Units/Units.h>
#include <UNIT/SUnitDmg.h>

#pragma pack(push, 1)

struct D2ModeChangeStrc
{
	int32_t nMode;								//0x00
	D2UnitStrc* pUnit;						//0x04
	D2UnitStrc* pTargetUnit;				//0x08
	int32_t nX;									//0x0C
	int32_t nY;									//0x10
	uint8_t unk0x14[4];						//0x14
	int32_t unk0x18;							//0x18
	uint8_t unk0x1C;							//0x1C
	uint8_t unk0x1D[3];							//0x1D
};

// TODO: Better names
using MonModeCallback1 = int32_t(__fastcall*)(D2GameStrc*, D2ModeChangeStrc*);
using MonModeCallback2 = int32_t(__fastcall*)(D2GameStrc*, D2UnitStrc*);
using MonModeCallback3 = void(__fastcall*)(D2GameStrc*, D2UnitStrc*);
struct D2MonModeCallbackTableStrc
{
	MonModeCallback1 unk0x00;
	MonModeCallback2 unk0x04;
	MonModeCallback3 unk0x08;
	int32_t unk0x0C;
};

#pragma pack(pop)
