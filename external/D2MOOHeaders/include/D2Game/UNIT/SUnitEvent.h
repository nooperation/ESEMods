#pragma once

#include <Units/Units.h>
#include "GAME/Event.h"
#include "SUnitDmg.h"

using D2UnitEventCallbackFunction = int32_t(__fastcall*)(D2GameStrc*, int32_t, D2UnitStrc*, D2UnitStrc*, D2DamageStrc*, int32_t, int32_t);

struct D2UnitEventStrc
{
	uint8_t nTimerType;						//0x00 D2C_UnitEventCallbackTypes
	uint8_t unk0x01;						//0x01
	uint16_t nTimerFlags;					//0x02
	uint32_t nQueueNo;						//0x04
	int32_t unk0x08;						//0x08
	int32_t nGUID1;							//0x0C First identifier
	int32_t nGUID2;							//0x10 Second identifier
	D2UnitEventCallbackFunction pCallback;	//0x14
	D2UnitEventStrc* pPrevious;				//0x18  Seems to be any kind of id, not necessariyl the prevtimer ?
	D2UnitEventStrc* pNext;					//0x1C
};
