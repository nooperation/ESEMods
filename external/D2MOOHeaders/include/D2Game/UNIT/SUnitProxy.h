#pragma once

#include <Units/Units.h>
#include "GAME/Game.h"

#pragma pack(1)

struct D2NpcRecordStrc;
struct D2NpcVendorChainStrc;

struct D2ItemCacheStrc
{
	char nMin;								//0x00
	char nMax;								//0x01
	char nMagicMin;							//0x02
	char nMagicMax;							//0x03
	uint32_t dwCode;							//0x04
	int32_t nMagicLevel;						//0x08
};

struct D2UnitProxyStrc
{
	D2ItemCacheStrc* pItemCache;			//0x00
	int32_t nItems;								//0x04
	uint32_t* pPermCache;						//0x08
	int32_t nPerms;								//0x0C
};

#pragma pack()
