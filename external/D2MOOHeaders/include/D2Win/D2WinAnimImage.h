#pragma once

#include "D2WinControlHeader.h"

#include <DrawMode.h>


#pragma pack(push, 1)
struct D2AnimatedImageDescriptor
{
	D2CellFileStrc** ppCellFile1;							//0x00
	D2CellFileStrc** ppCellFile2;							//0x04
	DrawMode eDrawMode;										//0x08
	uint32_t nAnimSpeed;									//0x0C
};

struct D2WinAnimImageStrc
{
	D2WinControlStrc controlHeader;							//0x00
	D2AnimatedImageDescriptor* pAnimatedImageDescriptor;	//0x40
	uint32_t nAnimSpeed;									//0x44
	uint32_t dwStartTickCount;								//0x48
	uint32_t nFrame;										//0x4C
	int32_t nAnimType;										//0x50
	DrawMode eDrawMode;										//0x54
	void(__stdcall* field_58)(SMSGHANDLER_PARAMS*);				//0x58
	int32_t bIsRunning;										//0x5C
};
#pragma pack(pop)
