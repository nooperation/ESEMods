#pragma once

#include "D2WinControlHeader.h"
#include <D2Unicode.h>

#pragma pack(push, 1)
struct D2WinPopUpLineStrc
{
	wchar_t wszText[64];							//0x00
	void(__stdcall* pfHandleMouseInput)();			//0x80
};

struct D2WinPopUpStrc
{
	D2WinControlStrc controlHeader;					//0x00
	int32_t nLines;									//0x40
	D2WinPopUpLineStrc lines[8];					//0x44
	int32_t nCurrentLine;							//0x464
};
#pragma pack(pop)
