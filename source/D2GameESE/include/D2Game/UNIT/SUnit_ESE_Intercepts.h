#pragma once

#include "D2Game/UNIT/SUnit_ESE.h"

#include <Units/Units.h>
#include <Drlg/D2DrlgPreset.h>
#include <GAME/Event.h>

#include <cstdlib>

//D2Game.0x6FCBDE90
void __fastcall ESE_INTERCEPT_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable);

extern sub_6FCBDE90_t sub_6FCBDE90_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable);
