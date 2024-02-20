#pragma once

#include "D2WinControlHeader.h"


#pragma pack(push, 1)
struct D2WinProgressBarStrc
{
	D2WinControlStrc controlHeader;					//0x00
	float fProgress;								//0x40
};
#pragma pack(pop)
