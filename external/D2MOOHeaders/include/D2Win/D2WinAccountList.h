#pragma once

#include "D2WinControlHeader.h"

#include "Font.h"


#pragma pack(push, 1)
struct D2WinAccountListDataStrc
{
	char szText[50];								//0x00
	int16_t field_32;								//0x32
	D2WinAccountListDataStrc* pNext;				//0x34
};

struct D2WinAccountListStrc
{
	D2WinControlStrc controlHeader;					//0x00
	D2WinAccountListDataStrc* pDataList;			//0x40
	D2WinAccountListDataStrc* pSelectedDataEntry;	//0x44
	int32_t field_48;								//0x48
	int32_t field_4C;								//0x4C
	Font eFont;										//0x50
	int32_t field_54;								//0x54
};
#pragma pack(pop)

