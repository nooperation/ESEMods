#include "D2Game/UNIT/SUnitEvent_ESE_Intercepts.h"

SUNITEVENT_FreeTimerList_t SUNITEVENT_FreeTimerList_Original = nullptr;
SUNITEVENT_AllocTimer_t SUNITEVENT_AllocTimer_Original = nullptr;
SUNITEVENT_FreeTimer_t SUNITEVENT_FreeTimer_Original = nullptr;
SUNITEVENT_GetTimer_t SUNITEVENT_GetTimer_Original = nullptr;
SUNITEVENT_EventFunc_Handler_t SUNITEVENT_EventFunc_Handler_Original = nullptr;

void __fastcall ESE_INTERCEPT_SUNITEVENT_FreeTimerList(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_SUNITEVENT_FreeTimerList(pGame, pUnit);
}

D2UnitEventStrc* __fastcall ESE_INTERCEPT_SUNITEVENT_AllocTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nTimerType, int32_t nGUID1, int32_t nGUID2, D2UnitEventCallbackFunction pCallback, uint32_t nQueueNo, int32_t a8)
{
    throw "This shouldn't happen";
}

void __fastcall ESE_INTERCEPT_SUNITEVENT_FreeTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4)
{
    ESE_SUNITEVENT_FreeTimer(pGame, pUnit, nTimerQueueNo, a4);
}

D2UnitEventStrc* __fastcall ESE_INTERCEPT_SUNITEVENT_GetTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4, int32_t nGUID1)
{
    // Return value really doesn't matter asides from null or not null for this function
    return (D2UnitEventStrc * )ESE_SUNITEVENT_GetTimer(pGame, pUnit, nTimerQueueNo, a4, nGUID1);
}

int32_t __fastcall ESE_INTERCEPT_SUNITEVENT_EventFunc_Handler(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    throw "This shouldn't happen";
}
