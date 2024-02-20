#pragma once

#include <Units/Units.h>
#include <Units/UnitFinds.h>

#pragma pack(1)

using ObeliskPowerUpFunction = int32_t(__fastcall*)(D2GameStrc*, D2UnitStrc*, int32_t);

struct D2ObeliskPowerUpStrc
{
	ObeliskPowerUpFunction pPowerUpCallback;//0x00
	uint32_t nChance;						//0x04
	int32_t nValue;							//0x08
};


struct D2ObjOperateFnStrc
{
	D2GameStrc* pGame;						//0x00
	D2UnitStrc* pObject;					//0x04
	D2UnitStrc* pPlayer;					//0x08
	D2ObjectControlStrc* pObjectregion;		//0x0C
	int32_t nObjectIdx;						//0x10
};
using ObjOperateFunction = int32_t(__fastcall*)(D2ObjOperateFnStrc*, int32_t);

using ObjShrineFunction = void(__fastcall* )(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);
struct D2ShrineTableStrc
{
	ObjShrineFunction pfShrineCallback;		//0x00
	int32_t unk0x04;						//0x04
	int32_t unk0x08;						//0x08
};

#pragma pack()
