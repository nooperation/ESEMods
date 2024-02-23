#include "D2Game/UNIT/SUnitEvent_ESE_Intercepts.h"

decltype(&SUNITEVENT_FreeTimerList) SUNITEVENT_FreeTimerList_Original = nullptr;
decltype(&SUNITEVENT_AllocTimer) SUNITEVENT_AllocTimer_Original = nullptr;
decltype(&SUNITEVENT_FreeTimer) SUNITEVENT_FreeTimer_Original = nullptr;
decltype(&SUNITEVENT_GetTimer) SUNITEVENT_GetTimer_Original = nullptr;
decltype(&SUNITEVENT_EventFunc_Handler) SUNITEVENT_EventFunc_Handler_Original = nullptr;

void __fastcall ESE_INTERCEPT_SUNITEVENT_FreeTimerList(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_SUNITEVENT_FreeTimerList(pGame, pUnit);
}

D2UnitEventStrc* __fastcall ESE_INTERCEPT_SUNITEVENT_AllocTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nTimerType, int32_t nGUID1, int32_t nGUID2, D2UnitEventCallbackFunction pCallback, uint32_t nQueueNo, int32_t a8)
{
    return ESE_SUNITEVENT_AllocTimer(pGame, pUnit, nTimerType, nGUID1, nGUID2, pCallback, nQueueNo, a8);
}

void __fastcall ESE_INTERCEPT_SUNITEVENT_FreeTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4)
{
    ESE_SUNITEVENT_FreeTimer(pGame, pUnit, nTimerQueueNo, a4);
}

D2UnitEventStrc* __fastcall ESE_INTERCEPT_SUNITEVENT_GetTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4, int32_t nGUID1)
{
    return ESE_SUNITEVENT_GetTimer(pGame, pUnit, nTimerQueueNo, a4, nGUID1);
}

int32_t __fastcall ESE_INTERCEPT_SUNITEVENT_EventFunc_Handler(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    return ESE_SUNITEVENT_EventFunc_Handler(pGame, nEvent, pAttacker, pUnit, pDamage);
}

