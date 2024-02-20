#pragma once

#include "../D2MooHeaders.h"
#include <UNIT/SUnitEvent.h>

//D2Game.0x6FCC3610
void __fastcall ESE_SUNITEVENT_FreeTimerList(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCC3650
D2UnitEventStrc* __fastcall ESE_SUNITEVENT_AllocTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nTimerType, int32_t nGUID1, int32_t nGUID2, D2UnitEventCallbackFunction pCallback, uint32_t nQueueNo, int32_t a8);
//D2Game.0x6FCC36D0
void __fastcall ESE_SUNITEVENT_FreeTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4);
//D2Game.0x6FCC3750
D2UnitEventStrc* __fastcall ESE_SUNITEVENT_GetTimer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nTimerQueueNo, int32_t a4, int32_t nGUID1);
//D2Game.0x6FCC3790
int32_t __fastcall ESE_SUNITEVENT_EventFunc_Handler(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage);
