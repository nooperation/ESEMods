#pragma once

#include "D2WinControlHeader.h"


#pragma pack(push, 1)
struct D2WinCommandRegisterStrc
{
	int32_t nType;									//0x00
	int32_t nId;									//0x04
	void(__stdcall* pCallback)(SMSGHANDLER_PARAMS*);		//0x08
};
#pragma pack(pop)
