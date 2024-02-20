#pragma once

#include <D2BasicTypes.h>

#include <Fog.h>

#pragma pack(1)

struct D2BitBufferStrc
{
	uint8_t* pBuffer;							//0x00
	int32_t nBits;								//0x04
	int32_t nPos;								//0x08
	int32_t nPosBits;							//0x0C
	BOOL bFull;									//0x10
};

#pragma pack()
