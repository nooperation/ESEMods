#pragma once

#include <Units/Units.h>
#include "SUnitProxy.h"

#pragma pack(1)

struct D2NpcTradeStrc
{
	struct
	{
		bool bVendorInit;		//0x00
		bool bHireInit;			//0x01
		uint8_t nAct;			//0x02
		bool bTrader;			//0x03
		bool bLevelRefresh;		//0x04
		bool bInited;			//0x05
		bool bForceVendor;		//0x06
		bool bRefreshInventory;	//0x07
	};

	uint32_t dwTicks;				//0x08
	D2UnitProxyStrc pProxy;			//0x0C
	uint32_t dwUnk;					//0x1C
	D2UnitGUID dwNPCGUID;			//0x20
};

struct D2NpcControlStrc
{
	int32_t nArraySize;							//0x00
	D2NpcRecordStrc* pFirstRecord;			//0x04
	D2SeedStrc pSeed;						//0x08
	int32_t unk0x10;							//0x10
};

struct D2NpcGambleStrc
{
	D2InventoryStrc* pInventory;			//0x00
	D2UnitGUID dwGUID;							//0x04
	D2NpcGambleStrc* pNext;					//0x08
};

struct D2NPCMessageListStrc
{
	uint16_t nMessageIndexes[8];				//0x00
};

struct D2NpcVendorChainStrc
{
	int dwGUID;
	uint8_t field_4;
	uint8_t unk0x05[3];
	D2NpcVendorChainStrc* pNext;
};

struct D2NpcEventStrc
{
	D2UnitStrc* pUnit;
	int32_t field_4;
	int32_t field_8;
	int32_t field_C;
	D2NpcEventStrc* pNext;
};

struct D2MercDataStrc
{
	int16_t nMercName;						//0x00
	int16_t nPad;								//0x02
	uint32_t dwSeed;							//0x04
	BOOL bHired;							//0x08
	BOOL bAvailable;						//0x0C
};

struct D2NpcRecordStrc
{
	int32_t nNPC;							//0x00
	D2InventoryStrc* pInventory;			//0x04
	D2NpcGambleStrc* pGamble;				//0x08
	BOOL bGambleInit;						//0x0C
	D2MercDataStrc* pMercData;				//0x10
	D2NpcEventStrc* pEvent;					//0x14
	D2NpcVendorChainStrc* pVendorChain;		//0x18
	BOOL bTrading;							//0x1C
	D2NpcTradeStrc npcTrade;				//0x20
};

#pragma pack()
