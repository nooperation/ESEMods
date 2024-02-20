#pragma once

#include <UNIT/SUnitEvent_ESE.h>
#include <UNIT/SUnitDmg_ESE.h>
#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include "GAME/Event.h"

//D2Game.0x6FCC3610
void __fastcall ESE_INTERCEPT_SUNITEVENT_FreeTimerList(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCC3650
D2UnitEventStrc* __fastcall ESE_INTERCEPT_SUNITEVENT_AllocTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nTimerType, int32_t nGUID1, int32_t nGUID2, D2UnitEventCallbackFunction pCallback, uint32_t nQueueNo, int32_t a8);
//D2Game.0x6FCC36D0
void __fastcall ESE_INTERCEPT_SUNITEVENT_FreeTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4);
//D2Game.0x6FCC3750
D2UnitEventStrc* __fastcall ESE_INTERCEPT_SUNITEVENT_GetTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4, int32_t nGUID1);
//D2Game.0x6FCC3790
int32_t __fastcall ESE_INTERCEPT_SUNITEVENT_EventFunc_Handler(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage);

extern decltype(&SUNITEVENT_FreeTimerList) SUNITEVENT_FreeTimerList_Original;
void __fastcall ESE_INTERCEPT_SUNITEVENT_FreeTimerList(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern decltype(&SUNITEVENT_AllocTimer) SUNITEVENT_AllocTimer_Original;
D2UnitEventStrc* __fastcall ESE_INTERCEPT_SUNITEVENT_AllocTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nTimerType, int32_t nGUID1, int32_t nGUID2, D2UnitEventCallbackFunction pCallback, uint32_t nQueueNo, int32_t a8);

extern decltype(&SUNITEVENT_FreeTimer) SUNITEVENT_FreeTimer_Original;
void __fastcall ESE_INTERCEPT_SUNITEVENT_FreeTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4);

extern decltype(&SUNITEVENT_GetTimer) SUNITEVENT_GetTimer_Original;
D2UnitEventStrc* __fastcall ESE_INTERCEPT_SUNITEVENT_GetTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4, int32_t nGUID1);

extern decltype(&SUNITEVENT_EventFunc_Handler) SUNITEVENT_EventFunc_Handler_Original;
int32_t __fastcall ESE_INTERCEPT_SUNITEVENT_EventFunc_Handler(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage);

