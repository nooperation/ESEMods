#include "D2Game/OBJECTS/ObjEval_ESE_Intercepts.h"

OBJEVAL_ApplyTrapObjectDamage_t OBJEVAL_ApplyTrapObjectDamage_Original = nullptr;

void __fastcall ESE_INTERCEPT_OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int32_t nDamageType)
{
    ESE_OBJEVAL_ApplyTrapObjectDamage(pGame, pSrcUnit, pTargetUnit, nDamageType);
}


