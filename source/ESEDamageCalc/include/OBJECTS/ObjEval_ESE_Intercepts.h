#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>

#include <OBJECTS/ObjEval_ESE.h>

//D2Game.0x6FC745D0
void __fastcall ESE_INTERCEPT_OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int32_t nDamageType);

extern decltype(&OBJEVAL_ApplyTrapObjectDamage) OBJEVAL_ApplyTrapObjectDamage_Original;
void __fastcall ESE_INTERCEPT_OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int32_t nDamageType);

