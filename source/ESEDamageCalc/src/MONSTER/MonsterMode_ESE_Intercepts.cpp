#include <MONSTER/MonsterMode_ESE_Intercepts.h>

decltype(&D2GAME_IsMonster_6FC62770) D2GAME_IsMonster_6FC62770_Original = nullptr;
decltype(&sub_6FC62780) sub_6FC62780_Original = nullptr;
decltype(&sub_6FC627B0) sub_6FC627B0_Original = nullptr;
decltype(&sub_6FC62D90) sub_6FC62D90_Original = nullptr;
decltype(&sub_6FC62DF0) sub_6FC62DF0_Original = nullptr;
decltype(&D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70) D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70_Original = nullptr;
decltype(&sub_6FC62F50) sub_6FC62F50_Original = nullptr;
decltype(&D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90) D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90_Original = nullptr;
decltype(&D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0) D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0_Original = nullptr;
decltype(&D2GAME_MONSTERMODE_AllocParams_6FC62FF0) D2GAME_MONSTERMODE_AllocParams_6FC62FF0_Original = nullptr;
decltype(&D2GAME_MONSTERMODE_FreeParams_6FC63020) D2GAME_MONSTERMODE_FreeParams_6FC63020_Original = nullptr;
decltype(&D2GAME_MONSTERMODE_Unk_6FC63040) D2GAME_MONSTERMODE_Unk_6FC63040_Original = nullptr;
decltype(&sub_6FC631B0) sub_6FC631B0_Original = nullptr;
decltype(&D2GAME_ApplyPeriodicStatDamage_6FC63440) D2GAME_ApplyPeriodicStatDamage_6FC63440_Original = nullptr;
decltype(&MONSTERMODE_GetMonStatsTxtRecord) MONSTERMODE_GetMonStatsTxtRecord_Original = nullptr;
decltype(&sub_6FC63680) sub_6FC63680_Original = nullptr;
decltype(&sub_6FC63940) sub_6FC63940_Original = nullptr;
decltype(&sub_6FC63A30) sub_6FC63A30_Original = nullptr;
decltype(&D2GAME_RemoveModeChangeEventCallback_6FC63B20) D2GAME_RemoveModeChangeEventCallback_6FC63B20_Original = nullptr;
decltype(&sub_6FC63B30) sub_6FC63B30_Original = nullptr;
decltype(&sub_6FC63E80) sub_6FC63E80_Original = nullptr;
decltype(&sub_6FC63FD0) sub_6FC63FD0_Original = nullptr;
decltype(&sub_6FC64090) sub_6FC64090_Original = nullptr;
decltype(&sub_6FC641D0) sub_6FC641D0_Original = nullptr;
decltype(&sub_6FC64280) sub_6FC64280_Original = nullptr;
decltype(&sub_6FC642C0) sub_6FC642C0_Original = nullptr;
decltype(&sub_6FC64310) sub_6FC64310_Original = nullptr;
decltype(&sub_6FC643D0) sub_6FC643D0_Original = nullptr;
decltype(&sub_6FC643E0) sub_6FC643E0_Original = nullptr;
decltype(&sub_6FC64410) sub_6FC64410_Original = nullptr;
decltype(&sub_6FC64450) sub_6FC64450_Original = nullptr;
decltype(&sub_6FC64480) sub_6FC64480_Original = nullptr;
decltype(&sub_6FC644E0) sub_6FC644E0_Original = nullptr;
decltype(&sub_6FC64510) sub_6FC64510_Original = nullptr;
decltype(&sub_6FC64540) sub_6FC64540_Original = nullptr;
decltype(&sub_6FC645E0) sub_6FC645E0_Original = nullptr;
decltype(&sub_6FC64790) sub_6FC64790_Original = nullptr;
decltype(&D2GAME_GetMonsterBaseId_6FC64B10) D2GAME_GetMonsterBaseId_6FC64B10_Original = nullptr;
decltype(&sub_6FC64B50) sub_6FC64B50_Original = nullptr;
decltype(&sub_6FC64B60) sub_6FC64B60_Original = nullptr;
decltype(&sub_6FC64CD0) sub_6FC64CD0_Original = nullptr;
decltype(&sub_6FC64E20) sub_6FC64E20_Original = nullptr;
decltype(&sub_6FC64E60) sub_6FC64E60_Original = nullptr;
decltype(&sub_6FC64E90) sub_6FC64E90_Original = nullptr;
decltype(&MONSTERMODE_GetCallbackTableRecord) MONSTERMODE_GetCallbackTableRecord_Original = nullptr;
decltype(&D2GAME_MONSTERS_AiFunction01_6FC65080) D2GAME_MONSTERS_AiFunction01_6FC65080_Original = nullptr;
decltype(&D2GAME_MONSTERS_AiFunction02_6FC65150) D2GAME_MONSTERS_AiFunction02_6FC65150_Original = nullptr;
decltype(&D2GAME_ModeChange_6FC65220) D2GAME_ModeChange_6FC65220_Original = nullptr;
decltype(&sub_6FC65680) sub_6FC65680_Original = nullptr;
decltype(&MONSTERMODE_GetModeChangeInfo) MONSTERMODE_GetModeChangeInfo_Original = nullptr;
decltype(&D2GAME_MONSTERS_AiFunction13_6FC65890) D2GAME_MONSTERS_AiFunction13_6FC65890_Original = nullptr;
decltype(&D2GAME_MONSTERS_AiFunction07_6FC658B0) D2GAME_MONSTERS_AiFunction07_6FC658B0_Original = nullptr;
decltype(&D2GAME_MONSTERS_AiFunction11_6FC65920) D2GAME_MONSTERS_AiFunction11_6FC65920_Original = nullptr;
decltype(&MONSTERMODE_EventHandler) MONSTERMODE_EventHandler_Original = nullptr;
decltype(&sub_6FC659B0) sub_6FC659B0_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_D2GAME_IsMonster_6FC62770(D2UnitStrc* pUnit)
{
    return ESE_D2GAME_IsMonster_6FC62770(pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FC62780(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2GameStrc* pGame)
{
    ESE_sub_6FC62780(pAttacker, pDefender, pGame);
}

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

uint8_t __fastcall ESE_INTERCEPT_sub_6FC62F50(D2UnitStrc* pUnit)
{
    return ESE_sub_6FC62F50(pUnit);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(D2UnitStrc* pUnit)
{
    ESE_D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(pUnit);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(D2AiParamStrc* pAiParam, int32_t a2, int32_t nVel, uint8_t a4)
{
    ESE_D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(pAiParam, a2, nVel, a4);
}

D2AiParamStrc* __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_AllocParams_6FC62FF0(D2GameStrc* pGame)
{
    return ESE_D2GAME_MONSTERMODE_AllocParams_6FC62FF0(pGame);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_FreeParams_6FC63020(D2GameStrc* pGame, D2AiParamStrc* pAiParam)
{
    ESE_D2GAME_MONSTERMODE_FreeParams_6FC63020(pGame, pAiParam);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERMODE_Unk_6FC63040(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int32_t a3)
{
    ESE_D2GAME_MONSTERMODE_Unk_6FC63040(pGame, pModeChange, a3);
}

void __fastcall ESE_INTERCEPT_sub_6FC631B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a7, D2ModeChangeStrc* pModeChange)
{
    ESE_sub_6FC631B0(pGame, pUnit, a7, pModeChange);
}

void __fastcall ESE_INTERCEPT_D2GAME_ApplyPeriodicStatDamage_6FC63440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4)
{
    ESE_D2GAME_ApplyPeriodicStatDamage_6FC63440(pGame, pUnit, a3, a4);
}

D2MonStatsTxt* __fastcall ESE_INTERCEPT_MONSTERMODE_GetMonStatsTxtRecord(int32_t nMonsterId)
{
    return ESE_MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
}

void __fastcall ESE_INTERCEPT_sub_6FC63680(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FC63680(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FC63940(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FC63940(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FC63A30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FC63A30(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_RemoveModeChangeEventCallback_6FC63B20(D2GameStrc* pGame, D2UnitStrc* pMonster)
{
    return ESE_D2GAME_RemoveModeChangeEventCallback_6FC63B20(pGame, pMonster);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC63B30(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC63B30(pGame, pModeChange);
}

void __fastcall ESE_INTERCEPT_sub_6FC63E80(D2GameStrc* pGame, D2UnitStrc* pUnit, DWORD dwDir)
{
    ESE_sub_6FC63E80(pGame, pUnit, dwDir);
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

int32_t __fastcall ESE_INTERCEPT_sub_6FC64280(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FC64280(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC642C0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC642C0(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64310(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC64310(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC643D0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC643D0(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC643E0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FC643E0(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64410(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC64410(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64450(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC64450(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64480(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FC64480(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC644E0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC644E0(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64510(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FC64510(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64540(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC64540(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC645E0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC645E0(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64790(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FC64790(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_GetMonsterBaseId_6FC64B10(D2UnitStrc* pUnit)
{
    return ESE_D2GAME_GetMonsterBaseId_6FC64B10(pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64B50(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC64B50(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64B60(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC64B60(pGame, pModeChange);
}

void __fastcall ESE_INTERCEPT_sub_6FC64CD0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FC64CD0(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64E20(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FC64E20(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64E60(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    return ESE_sub_6FC64E60(pGame, pModeChange);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC64E90(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FC64E90(pGame, pUnit);
}

const D2MonModeCallbackTableStrc* __fastcall ESE_INTERCEPT_MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int32_t nMode)
{
    return ESE_MONSTERMODE_GetCallbackTableRecord(pUnit, nMode);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction01_6FC65080(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4)
{
    ESE_D2GAME_MONSTERS_AiFunction01_6FC65080(pGame, pUnit, a3, a4);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction02_6FC65150(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4)
{
    ESE_D2GAME_MONSTERS_AiFunction02_6FC65150(pGame, pUnit, a3, a4);
}

int32_t __stdcall ESE_INTERCEPT_D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int32_t a3)
{
    return ESE_D2GAME_ModeChange_6FC65220(pGame, pModeChange, a3);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FC65680(D2UnitStrc* pUnit, int32_t nPathType, D2AiParamStrc* pAiParam, int32_t dwNewDist)
{
    return ESE_sub_6FC65680(pUnit, nPathType, pAiParam, dwNewDist);
}

void __stdcall ESE_INTERCEPT_MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int32_t nMode, D2ModeChangeStrc* pModeChange)
{
    ESE_MONSTERMODE_GetModeChangeInfo(pUnit, nMode, pModeChange);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction13_6FC65890(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4)
{
    ESE_D2GAME_MONSTERS_AiFunction13_6FC65890(pGame, pUnit, a3, a4);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction07_6FC658B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4)
{
    ESE_D2GAME_MONSTERS_AiFunction07_6FC658B0(pGame, pUnit, a3, a4);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction11_6FC65920(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4)
{
    ESE_D2GAME_MONSTERS_AiFunction11_6FC65920(pGame, pUnit, a3, a4);
}

void __fastcall ESE_INTERCEPT_MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nEvent, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_MONSTERMODE_EventHandler(pGame, pUnit, nEvent, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FC659B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t a4)
{
    ESE_sub_6FC659B0(pGame, pUnit, pTarget, a4);
}


