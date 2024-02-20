#pragma once

#include <Units/Units.h>

struct D2DrlgCoordsStrc;

#pragma pack(1)

struct D2ObjInitFnStrc
{
	D2GameStrc* pGame;						//0x00
	D2UnitStrc* pObject;					//0x04
	D2ActiveRoomStrc* pRoom;						//0x08
	D2ObjectControlStrc* pObjectregion;		//0x0C
	D2ObjectsTxt* pObjectTxt;				//0x10
	int32_t nX;								//0x14
	int32_t nY;								//0x18
};
using ObjInitFunction = void(__fastcall*)(D2ObjInitFnStrc*);

#pragma pack()
