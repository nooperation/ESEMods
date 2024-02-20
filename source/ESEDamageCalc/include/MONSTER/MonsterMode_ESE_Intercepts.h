#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <UNIT/SUnitDmg_ESE.h>

#include <MONSTER/MonsterMode_ESE.h>

//D2Game.0x6FC627B0
void __fastcall ESE_INTERCEPT_sub_6FC627B0(D2UnitStrc* pUnit, int32_t nMode);
//D2Game.0x6FC62D90
void __fastcall ESE_INTERCEPT_sub_6FC62D90(D2UnitStrc* pUnit, D2GameStrc* pGame);
//D2Game.0x6FC62DF0
void __stdcall ESE_INTERCEPT_sub_6FC62DF0(D2UnitStrc* pUnit, D2DamageStrc* pDamage);
//D2Game.0x6FC62E70
void __fastcall ESE_INTERCEPT_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
//D2Game.0x6FC63440
void __fastcall ESE_INTERCEPT_D2GAME_ApplyPeriodicStatDamage_6FC63440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC63B30
int32_t __fastcall ESE_INTERCEPT_sub_6FC63B30(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC63FD0
void __fastcall ESE_INTERCEPT_sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pAttacker);
//D2Game.0x6FC64090
void __fastcall ESE_INTERCEPT_sub_6FC64090(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC641D0
void __fastcall ESE_INTERCEPT_sub_6FC641D0(D2GameStrc* pGame, D2UnitStrc* pAttacker);
//D2Game.0x6FC64790
int32_t __fastcall ESE_INTERCEPT_sub_6FC64790(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern decltype(&sub_6FC627B0) sub_6FC627B0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC627B0(D2UnitStrc* pUnit, int32_t nMode);

extern decltype(&sub_6FC62D90) sub_6FC62D90_Original;
void __fastcall ESE_INTERCEPT_sub_6FC62D90(D2UnitStrc* pUnit, D2GameStrc* pGame);

extern decltype(&sub_6FC62DF0) sub_6FC62DF0_Original;
void __stdcall ESE_INTERCEPT_sub_6FC62DF0(D2UnitStrc* pUnit, D2DamageStrc* pDamage);

extern decltype(&D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70) D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);

extern decltype(&D2GAME_ApplyPeriodicStatDamage_6FC63440) D2GAME_ApplyPeriodicStatDamage_6FC63440_Original;
void __fastcall ESE_INTERCEPT_D2GAME_ApplyPeriodicStatDamage_6FC63440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);

extern decltype(&sub_6FC63B30) sub_6FC63B30_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC63B30(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);

extern decltype(&sub_6FC63FD0) sub_6FC63FD0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pAttacker);

extern decltype(&sub_6FC64090) sub_6FC64090_Original;
void __fastcall ESE_INTERCEPT_sub_6FC64090(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern decltype(&sub_6FC641D0) sub_6FC641D0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC641D0(D2GameStrc* pGame, D2UnitStrc* pAttacker);

extern decltype(&sub_6FC64790) sub_6FC64790_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64790(D2GameStrc* pGame, D2UnitStrc* pUnit);
