#pragma once

#include "D2WinControlHeader.h"

#include <D2Unicode.h>
#include "Font.h"


#pragma pack(push, 1)
struct D2WinListDataStrc
{
	Unicode wszText[256];							//0x00
	int32_t field_200;								//0x200
	int32_t(__stdcall* field_204)(SMSGHANDLER_PARAMS*);	//0x204
	int32_t field_208;								//0x208
	int32_t field_20C;								//0x20C
	int32_t field_210;								//0x210
	int32_t field_214;								//0x214
	char field_218;									//0x218
	char field_219;									//0x219
	char field_21A;									//0x21A
	char field_21B;									//0x21B
	int32_t field_21C;								//0x21C
	D2WinListDataStrc* pNext;						//0x220
};

struct D2WinListStrc
{
	D2WinControlStrc controlHeader;					//0x00
	Font eFont;										//0x40
	int32_t field_44;								//0x44
	int32_t field_48;								//0x48
	int32_t field_4C;								//0x4C
	int32_t field_50;								//0x50
	int32_t field_54;								//0x54
	int32_t field_58;								//0x58
	int32_t field_5C;								//0x5C
	int32_t field_60;								//0x60
	D2WinListDataStrc* pDataList;					//0x64
	D2WinListDataStrc* pSelectedDataEntry;			//0x68
};
#pragma pack(pop)
