#pragma once

#include <Units/Units.h>
#include <UNIT/SUnitDmg.h>

#pragma pack(1)

typedef BOOL(__fastcall* SPELLPREPARE)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2UnitStrc*, int32_t, int32_t, int32_t);
typedef BOOL(__fastcall* SPELLDO)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2UnitStrc*, int32_t, int32_t, int32_t);

struct D2pSpellTblStrc
{
	SPELLPREPARE pfSpellPrepare;			//0x00
	SPELLDO pfSpellDo;						//0x04
};

#pragma pack()
