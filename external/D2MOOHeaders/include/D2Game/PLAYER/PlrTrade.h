#pragma once

#include <Units/Units.h>
#include <OBJECTS/ObjMode.h>
#include <D2DataTbls.h>

#pragma pack(1)

struct D2CubeItemStrc
{
	D2UnitStrc* pItem;						//0x00
	int32_t nClassId;						//0x04
	int32_t nItemLevel;						//0x08
};

typedef BOOL(__fastcall* SPECIALCUBEFN)(D2GameStrc*, D2UnitStrc*);

struct D2CubeTableStrc
{
	SPECIALCUBEFN pFunc;					//0x00
};

#pragma pack()
