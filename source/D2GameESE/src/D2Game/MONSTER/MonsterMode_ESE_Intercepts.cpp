#include "D2Game/MONSTER/MonsterMode_ESE_Intercepts.h"

sub_6FC627B0_t sub_6FC627B0_Original = nullptr;
sub_6FC62D90_t sub_6FC62D90_Original = nullptr;
sub_6FC62DF0_t sub_6FC62DF0_Original = nullptr;
D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70_t D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70_Original = nullptr;
D2GAME_ApplyPeriodicStatDamage_6FC63440_t D2GAME_ApplyPeriodicStatDamage_6FC63440_Original = nullptr;
sub_6FC63B30_t sub_6FC63B30_Original = nullptr;
sub_6FC63FD0_t sub_6FC63FD0_Original = nullptr;
sub_6FC64090_t sub_6FC64090_Original = nullptr;
sub_6FC641D0_t sub_6FC641D0_Original = nullptr;
sub_6FC64790_t sub_6FC64790_Original = nullptr;


void __fastcall ESE_INTERCEPT_sub_6FC627B0(D2UnitStrc* pUnit, int32_t nMode)
{
    ESE_sub_6FC627B0(pUnit, nMode);
}

void __fastcall ESE_INTERCEPT_sub_6FC62D90(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    ESE_sub_6FC62D90(pUnit, pGame);
}

void __stdcall ESE_INTERCEPT_sub_6FC62DF0(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    ESE_sub_6FC62DF0(pUnit, pDamage);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    ESE_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(pAttacker, pDefender, pDamage);
}

void __fastcall ESE_INTERCEPT_D2GAME_ApplyPeriodicStatDamage_6FC63440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4)
{
    ESE_D2GAME_ApplyPeriodicStatDamage_6FC63440(pGame, pUnit, a3, a4);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC63B30(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC63B30(pGame, pModeChange);
}

void __fastcall ESE_INTERCEPT_sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    ESE_sub_6FC63FD0(pGame, pAttacker);
}

void __fastcall ESE_INTERCEPT_sub_6FC64090(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FC64090(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FC641D0(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    ESE_sub_6FC641D0(pGame, pAttacker);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64790(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FC64790(pGame, pUnit);
}
