#pragma once

#include <UNIT/SUnit_ESE.h>
#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <Drlg/D2DrlgPreset.h>
#include <GAME/Event.h>

//D2Game.0x6FCBDE90
void __fastcall ESE_INTERCEPT_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable);

extern decltype(&sub_6FCBDE90) sub_6FCBDE90_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable);
static_assert(std::is_same_v<decltype(&sub_6FCBDE90), decltype(&ESE_INTERCEPT_sub_6FCBDE90)>, "ESE_INTERCEPT_sub_6FCBDE90 has a different type than previously known.");
