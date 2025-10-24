#pragma once 

#include <cstdint>

#pragma pack(1)

struct D2PacketDataStrc					//sizeof 0x208
{
	int32_t nPacketSize;				//0x00
	uint8_t packetData[512];			//0x04
	D2PacketDataStrc* pNext;			//0x204
};

struct D2PacketListStrc
{
	int32_t nTotal;						//0x00 Total capacity of unitPacketList
	int32_t nUsed;						//0x04 Number of packets in unitPacketList
	int32_t unk0x08;					//0x08
	uint8_t* unitPacketList;			//0x0C List of packets to be processed for this unit. Each packet has the same size, determined by the largest packet in D2PacketTable, plus 5
};

using ProcessServerMessageCallback = void(__fastcall*)(uint8_t* packetData);
using ProcessServerUnitMessageCallback = void(__fastcall*)(D2UnitStrc* pUnit, uint8_t* packetData);

struct D2PacketTableStrc
{
	ProcessServerMessageCallback pfProcessCmd;			//0x00 Callback for processing the server packet
	int32_t nCmdSize;									//0x04 Size of the server packet
	ProcessServerUnitMessageCallback pfProcessUnit;		//0x08 Callback
};

#pragma pack()
