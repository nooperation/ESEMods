#include "D2Game/UNIT/SUnit_ESE_Intercepts.h"

decltype(&sub_6FCBDE90) sub_6FCBDE90_Original = nullptr;

void __fastcall ESE_INTERCEPT_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable)
{
    ESE_sub_6FCBDE90(pUnit, bSetUninterruptable);
}
