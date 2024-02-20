#pragma once

#include "D2WinControlHeader.h"


#pragma pack(push, 1)
struct D2WinSmackStrc
{
	D2WinControlStrc controlHeader;					//0x00
	char szFileName[256];							//0x40
	int32_t field_140;								//0x140
	int32_t field_144;								//0x144
	int32_t field_148;								//0x148
	int32_t field_14C;								//0x14C
};
#pragma pack(pop)
