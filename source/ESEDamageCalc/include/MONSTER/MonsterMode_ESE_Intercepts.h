#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <UNIT/SUnitDmg_ESE.h>

#include <MONSTER/MonsterMode_ESE.h>

//D2Game.0x6FC62770
int32_t __fastcall ESE_INTERCEPT_D2GAME_IsMonster_6FC62770(D2UnitStrc* pUnit);
//D2Game.0x6FC62780
void __fastcall ESE_INTERCEPT_sub_6FC62780(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2GameStrc* pGame);
//D2Game.0x6FC627B0
void __fastcall ESE_INTERCEPT_sub_6FC627B0(D2UnitStrc* pUnit, int32_t nMode);
//D2Game.0x6FC62D90
void __fastcall ESE_INTERCEPT_sub_6FC62D90(D2UnitStrc* pUnit, D2GameStrc* pGame);
//D2Game.0x6FC62DF0
void __stdcall ESE_INTERCEPT_sub_6FC62DF0(D2UnitStrc* pUnit, D2DamageStrc* pDamage);
//D2Game.0x6FC62E70
void __fastcall ESE_INTERCEPT_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
//D2Game.0x6FC62F50
uint8_t __fastcall ESE_INTERCEPT_sub_6FC62F50(D2UnitStrc* pUnit);
//D2Game.0x6FC62F90
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(D2UnitStrc* pUnit);
//D2Game.0x6FC62FC0
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(D2AiParamStrc* pAiParam, int32_t a2, int32_t nVel, uint8_t a4);
//D2Game.0x6FC62FF0
D2AiParamStrc* __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_AllocParams_6FC62FF0(D2GameStrc* pGame);
//D2Game.0x6FC63020
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_FreeParams_6FC63020(D2GameStrc* pGame, D2AiParamStrc* pAiParam);
//D2Game.0x6FC63040
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_Unk_6FC63040(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int32_t a3);
//D2Game.0x6FC631B0
void __fastcall ESE_INTERCEPT_sub_6FC631B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a7, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC63440
void __fastcall ESE_INTERCEPT_D2GAME_ApplyPeriodicStatDamage_6FC63440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC63650
D2MonStatsTxt* __fastcall ESE_INTERCEPT_MONSTERMODE_GetMonStatsTxtRecord(int32_t nMonsterId);
//D2Game.0x6FC63680
void __fastcall ESE_INTERCEPT_sub_6FC63680(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC63940
void __fastcall ESE_INTERCEPT_sub_6FC63940(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC63A30
void __fastcall ESE_INTERCEPT_sub_6FC63A30(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC63B20
int32_t __fastcall ESE_INTERCEPT_D2GAME_RemoveModeChangeEventCallback_6FC63B20(D2GameStrc* pGame, D2UnitStrc* pMonster);
//D2Game.0x6FC63B30
int32_t __fastcall ESE_INTERCEPT_sub_6FC63B30(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC63E80
void __fastcall ESE_INTERCEPT_sub_6FC63E80(D2GameStrc* pGame, D2UnitStrc* pUnit, DWORD dwDir);
//D2Game.0x6FC63FD0
void __fastcall ESE_INTERCEPT_sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pAttacker);
//D2Game.0x6FC64090
void __fastcall ESE_INTERCEPT_sub_6FC64090(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC641D0
void __fastcall ESE_INTERCEPT_sub_6FC641D0(D2GameStrc* pGame, D2UnitStrc* pAttacker);
//D2Game.0x6FC64280
int32_t __fastcall ESE_INTERCEPT_sub_6FC64280(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC642C0
int32_t __fastcall ESE_INTERCEPT_sub_6FC642C0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64310
int32_t __fastcall ESE_INTERCEPT_sub_6FC64310(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC643D0
int32_t __fastcall ESE_INTERCEPT_sub_6FC643D0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC643E0
int32_t __fastcall ESE_INTERCEPT_sub_6FC643E0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64410
int32_t __fastcall ESE_INTERCEPT_sub_6FC64410(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64450
int32_t __fastcall ESE_INTERCEPT_sub_6FC64450(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64480
int32_t __fastcall ESE_INTERCEPT_sub_6FC64480(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC644E0
int32_t __fastcall ESE_INTERCEPT_sub_6FC644E0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64510
int32_t __fastcall ESE_INTERCEPT_sub_6FC64510(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64540
int32_t __fastcall ESE_INTERCEPT_sub_6FC64540(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC645E0
int32_t __fastcall ESE_INTERCEPT_sub_6FC645E0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64790
int32_t __fastcall ESE_INTERCEPT_sub_6FC64790(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64B10
int32_t __fastcall ESE_INTERCEPT_D2GAME_GetMonsterBaseId_6FC64B10(D2UnitStrc* pUnit);
//D2Game.0x6FC64B50
int32_t __fastcall ESE_INTERCEPT_sub_6FC64B50(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64B60
int32_t __fastcall ESE_INTERCEPT_sub_6FC64B60(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64CD0
void __fastcall ESE_INTERCEPT_sub_6FC64CD0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64E20
int32_t __fastcall ESE_INTERCEPT_sub_6FC64E20(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64E60
int32_t __fastcall ESE_INTERCEPT_sub_6FC64E60(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64E90
int32_t __fastcall ESE_INTERCEPT_sub_6FC64E90(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64F50
const D2MonModeCallbackTableStrc* __fastcall ESE_INTERCEPT_MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int32_t nMode);
//D2Game.0x6FC65080
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction01_6FC65080(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC65150
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction02_6FC65150(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC65220
int32_t __stdcall ESE_INTERCEPT_D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int32_t a3);
//D2Game.0x6FC65680
int32_t __fastcall ESE_INTERCEPT_sub_6FC65680(D2UnitStrc* pUnit, int32_t nPathType, D2AiParamStrc* pAiParam, int32_t dwNewDist);
//D2Game.0x6FC65780
void __stdcall ESE_INTERCEPT_MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int32_t nMode, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC65890
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction13_6FC65890(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC658B0
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction07_6FC658B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC65920
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction11_6FC65920(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC65930
void __fastcall ESE_INTERCEPT_MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nEvent, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FC659B0
void __fastcall ESE_INTERCEPT_sub_6FC659B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t a4);

extern decltype(&D2GAME_IsMonster_6FC62770) D2GAME_IsMonster_6FC62770_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_IsMonster_6FC62770(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&D2GAME_IsMonster_6FC62770), decltype(&ESE_INTERCEPT_D2GAME_IsMonster_6FC62770)>, "ESE_INTERCEPT_D2GAME_IsMonster_6FC62770 has a different type than previously known.");

extern decltype(&sub_6FC62780) sub_6FC62780_Original;
void __fastcall ESE_INTERCEPT_sub_6FC62780(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2GameStrc* pGame);
static_assert(std::is_same_v<decltype(&sub_6FC62780), decltype(&ESE_INTERCEPT_sub_6FC62780)>, "ESE_INTERCEPT_sub_6FC62780 has a different type than previously known.");

extern decltype(&sub_6FC627B0) sub_6FC627B0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC627B0(D2UnitStrc* pUnit, int32_t nMode);
static_assert(std::is_same_v<decltype(&sub_6FC627B0), decltype(&ESE_INTERCEPT_sub_6FC627B0)>, "ESE_INTERCEPT_sub_6FC627B0 has a different type than previously known.");

extern decltype(&sub_6FC62D90) sub_6FC62D90_Original;
void __fastcall ESE_INTERCEPT_sub_6FC62D90(D2UnitStrc* pUnit, D2GameStrc* pGame);
static_assert(std::is_same_v<decltype(&sub_6FC62D90), decltype(&ESE_INTERCEPT_sub_6FC62D90)>, "ESE_INTERCEPT_sub_6FC62D90 has a different type than previously known.");

extern decltype(&sub_6FC62DF0) sub_6FC62DF0_Original;
void __stdcall ESE_INTERCEPT_sub_6FC62DF0(D2UnitStrc* pUnit, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&sub_6FC62DF0), decltype(&ESE_INTERCEPT_sub_6FC62DF0)>, "ESE_INTERCEPT_sub_6FC62DF0 has a different type than previously known.");

extern decltype(&D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70) D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70), decltype(&ESE_INTERCEPT_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70)>, "ESE_INTERCEPT_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70 has a different type than previously known.");

extern decltype(&sub_6FC62F50) sub_6FC62F50_Original;
uint8_t __fastcall ESE_INTERCEPT_sub_6FC62F50(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC62F50), decltype(&ESE_INTERCEPT_sub_6FC62F50)>, "ESE_INTERCEPT_sub_6FC62F50 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90) D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90), decltype(&ESE_INTERCEPT_D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90)>, "ESE_INTERCEPT_D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0) D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(D2AiParamStrc* pAiParam, int32_t a2, int32_t nVel, uint8_t a4);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0), decltype(&ESE_INTERCEPT_D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0)>, "ESE_INTERCEPT_D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERMODE_AllocParams_6FC62FF0) D2GAME_MONSTERMODE_AllocParams_6FC62FF0_Original;
D2AiParamStrc* __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_AllocParams_6FC62FF0(D2GameStrc* pGame);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERMODE_AllocParams_6FC62FF0), decltype(&ESE_INTERCEPT_D2GAME_MONSTERMODE_AllocParams_6FC62FF0)>, "ESE_INTERCEPT_D2GAME_MONSTERMODE_AllocParams_6FC62FF0 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERMODE_FreeParams_6FC63020) D2GAME_MONSTERMODE_FreeParams_6FC63020_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_FreeParams_6FC63020(D2GameStrc* pGame, D2AiParamStrc* pAiParam);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERMODE_FreeParams_6FC63020), decltype(&ESE_INTERCEPT_D2GAME_MONSTERMODE_FreeParams_6FC63020)>, "ESE_INTERCEPT_D2GAME_MONSTERMODE_FreeParams_6FC63020 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERMODE_Unk_6FC63040) D2GAME_MONSTERMODE_Unk_6FC63040_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_Unk_6FC63040(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int32_t a3);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERMODE_Unk_6FC63040), decltype(&ESE_INTERCEPT_D2GAME_MONSTERMODE_Unk_6FC63040)>, "ESE_INTERCEPT_D2GAME_MONSTERMODE_Unk_6FC63040 has a different type than previously known.");

extern decltype(&sub_6FC631B0) sub_6FC631B0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC631B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a7, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC631B0), decltype(&ESE_INTERCEPT_sub_6FC631B0)>, "ESE_INTERCEPT_sub_6FC631B0 has a different type than previously known.");

extern decltype(&D2GAME_ApplyPeriodicStatDamage_6FC63440) D2GAME_ApplyPeriodicStatDamage_6FC63440_Original;
void __fastcall ESE_INTERCEPT_D2GAME_ApplyPeriodicStatDamage_6FC63440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
static_assert(std::is_same_v<decltype(&D2GAME_ApplyPeriodicStatDamage_6FC63440), decltype(&ESE_INTERCEPT_D2GAME_ApplyPeriodicStatDamage_6FC63440)>, "ESE_INTERCEPT_D2GAME_ApplyPeriodicStatDamage_6FC63440 has a different type than previously known.");

extern decltype(&MONSTERMODE_GetMonStatsTxtRecord) MONSTERMODE_GetMonStatsTxtRecord_Original;
D2MonStatsTxt* __fastcall ESE_INTERCEPT_MONSTERMODE_GetMonStatsTxtRecord(int32_t nMonsterId);
static_assert(std::is_same_v<decltype(&MONSTERMODE_GetMonStatsTxtRecord), decltype(&ESE_INTERCEPT_MONSTERMODE_GetMonStatsTxtRecord)>, "ESE_INTERCEPT_MONSTERMODE_GetMonStatsTxtRecord has a different type than previously known.");

extern decltype(&sub_6FC63680) sub_6FC63680_Original;
void __fastcall ESE_INTERCEPT_sub_6FC63680(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC63680), decltype(&ESE_INTERCEPT_sub_6FC63680)>, "ESE_INTERCEPT_sub_6FC63680 has a different type than previously known.");

extern decltype(&sub_6FC63940) sub_6FC63940_Original;
void __fastcall ESE_INTERCEPT_sub_6FC63940(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC63940), decltype(&ESE_INTERCEPT_sub_6FC63940)>, "ESE_INTERCEPT_sub_6FC63940 has a different type than previously known.");

extern decltype(&sub_6FC63A30) sub_6FC63A30_Original;
void __fastcall ESE_INTERCEPT_sub_6FC63A30(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC63A30), decltype(&ESE_INTERCEPT_sub_6FC63A30)>, "ESE_INTERCEPT_sub_6FC63A30 has a different type than previously known.");

extern decltype(&D2GAME_RemoveModeChangeEventCallback_6FC63B20) D2GAME_RemoveModeChangeEventCallback_6FC63B20_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_RemoveModeChangeEventCallback_6FC63B20(D2GameStrc* pGame, D2UnitStrc* pMonster);
static_assert(std::is_same_v<decltype(&D2GAME_RemoveModeChangeEventCallback_6FC63B20), decltype(&ESE_INTERCEPT_D2GAME_RemoveModeChangeEventCallback_6FC63B20)>, "ESE_INTERCEPT_D2GAME_RemoveModeChangeEventCallback_6FC63B20 has a different type than previously known.");

extern decltype(&sub_6FC63B30) sub_6FC63B30_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC63B30(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC63B30), decltype(&ESE_INTERCEPT_sub_6FC63B30)>, "ESE_INTERCEPT_sub_6FC63B30 has a different type than previously known.");

extern decltype(&sub_6FC63E80) sub_6FC63E80_Original;
void __fastcall ESE_INTERCEPT_sub_6FC63E80(D2GameStrc* pGame, D2UnitStrc* pUnit, DWORD dwDir);
static_assert(std::is_same_v<decltype(&sub_6FC63E80), decltype(&ESE_INTERCEPT_sub_6FC63E80)>, "ESE_INTERCEPT_sub_6FC63E80 has a different type than previously known.");

extern decltype(&sub_6FC63FD0) sub_6FC63FD0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pAttacker);
static_assert(std::is_same_v<decltype(&sub_6FC63FD0), decltype(&ESE_INTERCEPT_sub_6FC63FD0)>, "ESE_INTERCEPT_sub_6FC63FD0 has a different type than previously known.");

extern decltype(&sub_6FC64090) sub_6FC64090_Original;
void __fastcall ESE_INTERCEPT_sub_6FC64090(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC64090), decltype(&ESE_INTERCEPT_sub_6FC64090)>, "ESE_INTERCEPT_sub_6FC64090 has a different type than previously known.");

extern decltype(&sub_6FC641D0) sub_6FC641D0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC641D0(D2GameStrc* pGame, D2UnitStrc* pAttacker);
static_assert(std::is_same_v<decltype(&sub_6FC641D0), decltype(&ESE_INTERCEPT_sub_6FC641D0)>, "ESE_INTERCEPT_sub_6FC641D0 has a different type than previously known.");

extern decltype(&sub_6FC64280) sub_6FC64280_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64280(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC64280), decltype(&ESE_INTERCEPT_sub_6FC64280)>, "ESE_INTERCEPT_sub_6FC64280 has a different type than previously known.");

extern decltype(&sub_6FC642C0) sub_6FC642C0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC642C0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC642C0), decltype(&ESE_INTERCEPT_sub_6FC642C0)>, "ESE_INTERCEPT_sub_6FC642C0 has a different type than previously known.");

extern decltype(&sub_6FC64310) sub_6FC64310_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64310(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC64310), decltype(&ESE_INTERCEPT_sub_6FC64310)>, "ESE_INTERCEPT_sub_6FC64310 has a different type than previously known.");

extern decltype(&sub_6FC643D0) sub_6FC643D0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC643D0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC643D0), decltype(&ESE_INTERCEPT_sub_6FC643D0)>, "ESE_INTERCEPT_sub_6FC643D0 has a different type than previously known.");

extern decltype(&sub_6FC643E0) sub_6FC643E0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC643E0(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC643E0), decltype(&ESE_INTERCEPT_sub_6FC643E0)>, "ESE_INTERCEPT_sub_6FC643E0 has a different type than previously known.");

extern decltype(&sub_6FC64410) sub_6FC64410_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64410(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC64410), decltype(&ESE_INTERCEPT_sub_6FC64410)>, "ESE_INTERCEPT_sub_6FC64410 has a different type than previously known.");

extern decltype(&sub_6FC64450) sub_6FC64450_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64450(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC64450), decltype(&ESE_INTERCEPT_sub_6FC64450)>, "ESE_INTERCEPT_sub_6FC64450 has a different type than previously known.");

extern decltype(&sub_6FC64480) sub_6FC64480_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64480(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC64480), decltype(&ESE_INTERCEPT_sub_6FC64480)>, "ESE_INTERCEPT_sub_6FC64480 has a different type than previously known.");

extern decltype(&sub_6FC644E0) sub_6FC644E0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC644E0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC644E0), decltype(&ESE_INTERCEPT_sub_6FC644E0)>, "ESE_INTERCEPT_sub_6FC644E0 has a different type than previously known.");

extern decltype(&sub_6FC64510) sub_6FC64510_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64510(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC64510), decltype(&ESE_INTERCEPT_sub_6FC64510)>, "ESE_INTERCEPT_sub_6FC64510 has a different type than previously known.");

extern decltype(&sub_6FC64540) sub_6FC64540_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64540(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC64540), decltype(&ESE_INTERCEPT_sub_6FC64540)>, "ESE_INTERCEPT_sub_6FC64540 has a different type than previously known.");

extern decltype(&sub_6FC645E0) sub_6FC645E0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC645E0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC645E0), decltype(&ESE_INTERCEPT_sub_6FC645E0)>, "ESE_INTERCEPT_sub_6FC645E0 has a different type than previously known.");

extern decltype(&sub_6FC64790) sub_6FC64790_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64790(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC64790), decltype(&ESE_INTERCEPT_sub_6FC64790)>, "ESE_INTERCEPT_sub_6FC64790 has a different type than previously known.");

extern decltype(&D2GAME_GetMonsterBaseId_6FC64B10) D2GAME_GetMonsterBaseId_6FC64B10_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_GetMonsterBaseId_6FC64B10(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&D2GAME_GetMonsterBaseId_6FC64B10), decltype(&ESE_INTERCEPT_D2GAME_GetMonsterBaseId_6FC64B10)>, "ESE_INTERCEPT_D2GAME_GetMonsterBaseId_6FC64B10 has a different type than previously known.");

extern decltype(&sub_6FC64B50) sub_6FC64B50_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64B50(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC64B50), decltype(&ESE_INTERCEPT_sub_6FC64B50)>, "ESE_INTERCEPT_sub_6FC64B50 has a different type than previously known.");

extern decltype(&sub_6FC64B60) sub_6FC64B60_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64B60(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC64B60), decltype(&ESE_INTERCEPT_sub_6FC64B60)>, "ESE_INTERCEPT_sub_6FC64B60 has a different type than previously known.");

extern decltype(&sub_6FC64CD0) sub_6FC64CD0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC64CD0(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC64CD0), decltype(&ESE_INTERCEPT_sub_6FC64CD0)>, "ESE_INTERCEPT_sub_6FC64CD0 has a different type than previously known.");

extern decltype(&sub_6FC64E20) sub_6FC64E20_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64E20(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC64E20), decltype(&ESE_INTERCEPT_sub_6FC64E20)>, "ESE_INTERCEPT_sub_6FC64E20 has a different type than previously known.");

extern decltype(&sub_6FC64E60) sub_6FC64E60_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64E60(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&sub_6FC64E60), decltype(&ESE_INTERCEPT_sub_6FC64E60)>, "ESE_INTERCEPT_sub_6FC64E60 has a different type than previously known.");

extern decltype(&sub_6FC64E90) sub_6FC64E90_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC64E90(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC64E90), decltype(&ESE_INTERCEPT_sub_6FC64E90)>, "ESE_INTERCEPT_sub_6FC64E90 has a different type than previously known.");

extern decltype(&MONSTERMODE_GetCallbackTableRecord) __fastcall MONSTERMODE_GetCallbackTableRecord_Original;
const D2MonModeCallbackTableStrc* __fastcall ESE_INTERCEPT_MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int32_t nMode);
static_assert(std::is_same_v<decltype(&MONSTERMODE_GetCallbackTableRecord), decltype(&ESE_INTERCEPT_MONSTERMODE_GetCallbackTableRecord)>, "ESE_INTERCEPT_MONSTERMODE_GetCallbackTableRecord has a different type than previously known.");

extern decltype(&D2GAME_MONSTERS_AiFunction01_6FC65080) D2GAME_MONSTERS_AiFunction01_6FC65080_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction01_6FC65080(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERS_AiFunction01_6FC65080), decltype(&ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction01_6FC65080)>, "ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction01_6FC65080 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERS_AiFunction02_6FC65150) D2GAME_MONSTERS_AiFunction02_6FC65150_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction02_6FC65150(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERS_AiFunction02_6FC65150), decltype(&ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction02_6FC65150)>, "ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction02_6FC65150 has a different type than previously known.");

extern decltype(&D2GAME_ModeChange_6FC65220) D2GAME_ModeChange_6FC65220_Original;
int32_t __stdcall ESE_INTERCEPT_D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int32_t a3);
static_assert(std::is_same_v<decltype(&D2GAME_ModeChange_6FC65220), decltype(&ESE_INTERCEPT_D2GAME_ModeChange_6FC65220)>, "ESE_INTERCEPT_D2GAME_ModeChange_6FC65220 has a different type than previously known.");

extern decltype(&sub_6FC65680) sub_6FC65680_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC65680(D2UnitStrc* pUnit, int32_t nPathType, D2AiParamStrc* pAiParam, int32_t dwNewDist);
static_assert(std::is_same_v<decltype(&sub_6FC65680), decltype(&ESE_INTERCEPT_sub_6FC65680)>, "ESE_INTERCEPT_sub_6FC65680 has a different type than previously known.");

extern decltype(&MONSTERMODE_GetModeChangeInfo) MONSTERMODE_GetModeChangeInfo_Original;
void __stdcall ESE_INTERCEPT_MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int32_t nMode, D2ModeChangeStrc* pModeChange);
static_assert(std::is_same_v<decltype(&MONSTERMODE_GetModeChangeInfo), decltype(&ESE_INTERCEPT_MONSTERMODE_GetModeChangeInfo)>, "ESE_INTERCEPT_MONSTERMODE_GetModeChangeInfo has a different type than previously known.");

extern decltype(&D2GAME_MONSTERS_AiFunction13_6FC65890) D2GAME_MONSTERS_AiFunction13_6FC65890_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction13_6FC65890(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERS_AiFunction13_6FC65890), decltype(&ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction13_6FC65890)>, "ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction13_6FC65890 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERS_AiFunction07_6FC658B0) D2GAME_MONSTERS_AiFunction07_6FC658B0_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction07_6FC658B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERS_AiFunction07_6FC658B0), decltype(&ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction07_6FC658B0)>, "ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction07_6FC658B0 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERS_AiFunction11_6FC65920) D2GAME_MONSTERS_AiFunction11_6FC65920_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction11_6FC65920(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERS_AiFunction11_6FC65920), decltype(&ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction11_6FC65920)>, "ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction11_6FC65920 has a different type than previously known.");

extern decltype(&MONSTERMODE_EventHandler) MONSTERMODE_EventHandler_Original;
void __fastcall ESE_INTERCEPT_MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nEvent, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&MONSTERMODE_EventHandler), decltype(&ESE_INTERCEPT_MONSTERMODE_EventHandler)>, "ESE_INTERCEPT_MONSTERMODE_EventHandler has a different type than previously known.");

extern decltype(&sub_6FC659B0) sub_6FC659B0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC659B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t a4);
static_assert(std::is_same_v<decltype(&sub_6FC659B0), decltype(&ESE_INTERCEPT_sub_6FC659B0)>, "ESE_INTERCEPT_sub_6FC659B0 has a different type than previously known.");

