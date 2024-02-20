#pragma once

#include "D2WinControlHeader.h"


#pragma pack(push, 1)
struct D2WinTimerStrc
{
	D2WinControlStrc controlHeader;					//0x00
	uint32_t nTimeout;								//0x40
	uint32_t dwTickCount;							//0x44
};
#pragma pack(pop)
