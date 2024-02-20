#pragma once

#include "D2WinControlHeader.h"

#include <D2Unicode.h>
#include "Font.h"


enum D2EditBoxFlags
{
	EDITBOX_PASSWORD = 0x00000001,
};


#pragma pack(push, 1)
struct D2WinEditBoxStrc
{
	D2WinControlStrc controlHeader;					//0x00
	int32_t field_40;								//0x40
	int32_t field_44;								//0x44	
	int32_t field_48;								//0x48
	int32_t field_4C;								//0x4C
	int32_t field_50;								//0x50
	int32_t field_54;								//0x54
	int32_t nTextLength;							//0x58
	Unicode wszText[256];							//0x258
	int32_t field_25C;								//0x25C
	uint32_t dwEditBoxFlags;						//0x260
	int32_t field_264;								//0x264
	int32_t field_268;								//0x268
	void(__stdcall* field_26C)(int32_t);			//0x26C
	Font eFont;										//0x270
	int32_t nTextColor;								//0x274
	D2WinEditBoxStrc* pNext;						//0x278
	D2WinEditBoxStrc* pPrevious;					//0x27C
	int32_t field_280;								//0x280
};
#pragma pack(pop)
