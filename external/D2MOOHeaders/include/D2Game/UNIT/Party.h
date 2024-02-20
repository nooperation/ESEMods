#pragma once

#include <Units/Units.h>
#include "GAME/Game.h"

#pragma pack(1)

struct D2PartyNodeStrc
{
	int nUnitGUID;
	D2PartyNodeStrc* pNext;
};

struct D2PartyStrc
{
	int16_t nPartyId;
	int16_t field_2;
	D2PartyNodeStrc* pPartyNodes;
	D2PartyStrc* pNext;
};

struct D2PartyControlStrc
{
	int16_t field_0;
	int16_t field_2;
	D2PartyStrc* pParties;
};

using PartyCallbackFunction = void(__fastcall*)(D2GameStrc*, D2UnitStrc*, void*);

#pragma pack()
