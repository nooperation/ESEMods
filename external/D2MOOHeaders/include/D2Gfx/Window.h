#pragma once

#include <cstdint>

#include <D2Constants.h>
#include <Windows.h>


#pragma pack(push, 1)
struct D2WindowPlacementStrc
{
	HWND hWnd;								//0x00
	WINDOWPLACEMENT windowPlacement;		//0x04
};
#pragma pack(pop)

