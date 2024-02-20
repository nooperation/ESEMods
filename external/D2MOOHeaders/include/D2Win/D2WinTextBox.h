#pragma once

#include "D2WinControlHeader.h"

#include <D2Unicode.h>
#include "Font.h"


struct D2WinScrollBarStrc;

#pragma pack(push, 1)
struct D2WinTextBoxLineStrc
{
	Unicode* pColumns[5];							//0x00
	int32_t field_14;								//0x14
	char field_18;									//0x18
	char field_19;									//0x19
	char field_1A;									//0x1A
	char field_1B;									//0x1B
	D2WinTextBoxLineStrc* pNext;					//0x1C
};

struct D2WinTextBoxStrc
{
	D2WinControlStrc controlHeader;					//0x00
	int32_t field_40;								//0x40
	int32_t field_44;								//0x44
	D2WinTextBoxLineStrc* pFirstLine;				//0x48
	D2WinTextBoxLineStrc* pLastLine;				//0x4C
	D2WinTextBoxLineStrc* pCurrentLine;				//0x50
	int32_t nNumLines;								//0x54
	int32_t nLine;									//0x58
	int32_t dwTextBoxFlags;							//0x5C
	int32_t nCurrentLine;							//0x60
	int32_t nNumColumns;							//0x64
	int32_t unk0x68[5];								//0x68
	int32_t unk0x7C[5];								//0x7C
	D2WinScrollBarStrc* pScrollBar;					//0x90
	Font eFont;										//0x94
	int32_t field_98;								//0x98
	int32_t field_9C;								//0x9C
	int32_t field_A0;								//0xA0
	int32_t field_A4;								//0xA4
	int32_t field_A8;								//0xA8
};
#pragma pack(pop)
