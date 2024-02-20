#pragma once

#include "D2WinControlHeader.h"

#include <DrawMode.h>


#pragma pack(push, 1)
struct D2WinImageClickRectStrc
{
	int32_t nX;										//0x00
	int32_t nY;										//0x04
	int32_t nWidth;									//0x08
	int32_t nHeight;								//0x0C
	int32_t(__stdcall* pCallback)(SMSGHANDLER_PARAMS*);	//0x14
};

struct D2WinImageStrc
{
	D2WinControlStrc controlHeader;					//0x00
	int32_t nFrame;									//0x40
	DrawMode eDrawMode;								//0x44
	D2WinImageClickRectStrc* pClickRect;			//0x48
	int32_t field_4C;								//0x4C
	int32_t field_50;								//0x50
};

struct D2WinImage2Strc
{
	D2WinControlStrc controlHeader;					//0x00
	int32_t nFrame;									//0x40
	DrawMode eDrawMode;								//0x44
	D2WinImageClickRectStrc* pClickRect;			//0x48
};
#pragma pack(pop)

