#pragma once

#include <UNIT/SUnitDmg.h>
#include <MONSTER/MonsterMode.h>
#include <Units/Units.h>

//D2Game.0x6FC62770
int32_t __fastcall ESE_D2GAME_IsMonster_6FC62770(D2UnitStrc* pUnit);
//D2Game.0x6FC62780
void __fastcall ESE_sub_6FC62780(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2GameStrc* pGame);
//D2Game.0x6FC627B0
void __fastcall ESE_sub_6FC627B0(D2UnitStrc* pUnit, int32_t nMode);
//D2Game.0x6FC62D90
void __fastcall ESE_sub_6FC62D90(D2UnitStrc* pUnit, D2GameStrc* pGame);
//D2Game.0x6FC62DF0
void __stdcall ESE_sub_6FC62DF0(D2UnitStrc* pUnit, D2DamageStrc* pDamage);
//D2Game.0x6FC62E70
void __fastcall ESE_D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
//D2Game.0x6FC62F50
uint8_t __fastcall ESE_sub_6FC62F50(D2UnitStrc* pUnit);
//D2Game.0x6FC62F90
void __fastcall ESE_D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(D2UnitStrc* pUnit);
//D2Game.0x6FC62FC0
void __fastcall ESE_D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(D2AiParamStrc* pAiParam, int32_t a2, int32_t nVel, uint8_t a4);
//D2Game.0x6FC62FF0
D2AiParamStrc* __fastcall ESE_D2GAME_MONSTERMODE_AllocParams_6FC62FF0(D2GameStrc* pGame);
//D2Game.0x6FC63020
void __fastcall ESE_D2GAME_MONSTERMODE_FreeParams_6FC63020(D2GameStrc* pGame, D2AiParamStrc* pAiParam);
//D2Game.0x6FC63040
void __fastcall ESE_D2GAME_MONSTERMODE_Unk_6FC63040(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int32_t a3);
//D2Game.0x6FC631B0
void __fastcall ESE_sub_6FC631B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a7, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC63440
void __fastcall ESE_D2GAME_ApplyPeriodicStatDamage_6FC63440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC63650
D2MonStatsTxt* __fastcall ESE_MONSTERMODE_GetMonStatsTxtRecord(int32_t nMonsterId);
//D2Game.0x6FC63680
void __fastcall ESE_sub_6FC63680(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC63940
void __fastcall ESE_sub_6FC63940(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC63A30
void __fastcall ESE_sub_6FC63A30(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC63B20
int32_t __fastcall ESE_D2GAME_RemoveModeChangeEventCallback_6FC63B20(D2GameStrc* pGame, D2UnitStrc* pMonster);
//D2Game.0x6FC63B30
int32_t __fastcall ESE_sub_6FC63B30(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC63E80
void __fastcall ESE_sub_6FC63E80(D2GameStrc* pGame, D2UnitStrc* pUnit, DWORD dwDir);
//D2Game.0x6FC63FD0
void __fastcall ESE_sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pAttacker);
//D2Game.0x6FC64090
void __fastcall ESE_sub_6FC64090(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC641D0
void __fastcall ESE_sub_6FC641D0(D2GameStrc* pGame, D2UnitStrc* pAttacker);
//D2Game.0x6FC64280
int32_t __fastcall ESE_sub_6FC64280(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC642C0
int32_t __fastcall ESE_sub_6FC642C0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64310
int32_t __fastcall ESE_sub_6FC64310(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC643D0
int32_t __fastcall ESE_sub_6FC643D0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC643E0
int32_t __fastcall ESE_sub_6FC643E0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64410
int32_t __fastcall ESE_sub_6FC64410(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64450
int32_t __fastcall ESE_sub_6FC64450(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64480
int32_t __fastcall ESE_sub_6FC64480(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC644E0
int32_t __fastcall ESE_sub_6FC644E0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64510
int32_t __fastcall ESE_sub_6FC64510(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64540
int32_t __fastcall ESE_sub_6FC64540(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC645E0
int32_t __fastcall ESE_sub_6FC645E0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64790
int32_t __fastcall ESE_sub_6FC64790(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64B10
int32_t __fastcall ESE_D2GAME_GetMonsterBaseId_6FC64B10(D2UnitStrc* pUnit);
//D2Game.0x6FC64B50
int32_t __fastcall ESE_sub_6FC64B50(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64B60
int32_t __fastcall ESE_sub_6FC64B60(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64CD0
void __fastcall ESE_sub_6FC64CD0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64E20
int32_t __fastcall ESE_sub_6FC64E20(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64E60
int32_t __fastcall ESE_sub_6FC64E60(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC64E90
int32_t __fastcall ESE_sub_6FC64E90(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC64F50
const D2MonModeCallbackTableStrc* __fastcall ESE_MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int32_t nMode);
//D2Game.0x6FC65080
void __fastcall ESE_D2GAME_MONSTERS_AiFunction01_6FC65080(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC65150
void __fastcall ESE_D2GAME_MONSTERS_AiFunction02_6FC65150(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC65220
int32_t __stdcall ESE_D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int32_t a3);
//D2Game.0x6FC65680
int32_t __fastcall ESE_sub_6FC65680(D2UnitStrc* pUnit, int32_t nPathType, D2AiParamStrc* pAiParam, int32_t dwNewDist);
//D2Game.0x6FC65780
void __stdcall ESE_MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int32_t nMode, D2ModeChangeStrc* pModeChange);
//D2Game.0x6FC65890
void __fastcall ESE_D2GAME_MONSTERS_AiFunction13_6FC65890(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC658B0
void __fastcall ESE_D2GAME_MONSTERS_AiFunction07_6FC658B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC65920
void __fastcall ESE_D2GAME_MONSTERS_AiFunction11_6FC65920(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC65930
void __fastcall ESE_MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nEvent, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FC659B0
void __fastcall ESE_sub_6FC659B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t a4);
