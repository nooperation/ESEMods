#include "D2Game/SKILLS/SkillAma_ESE_Intercepts.h"

decltype(&D2Game_10049_Return1) D2Game_10049_Return1_Original = nullptr;
decltype(&SKILLS_SrvSt04_Arrow_Bolt) SKILLS_SrvSt04_Arrow_Bolt_Original = nullptr;
decltype(&SKILLS_SrvSt05_Jab) SKILLS_SrvSt05_Jab_Original = nullptr;
decltype(&SKILLS_SrvSt06_PowerStrike_ChargedStrike) SKILLS_SrvSt06_PowerStrike_ChargedStrike_Original = nullptr;
decltype(&SKILLS_SrvSt07_Impale) SKILLS_SrvSt07_Impale_Original = nullptr;
decltype(&SKILLS_SrvSt08_Strafe) SKILLS_SrvSt08_Strafe_Original = nullptr;
decltype(&SKILLS_SrvSt09_Fend) SKILLS_SrvSt09_Fend_Original = nullptr;
decltype(&SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy) SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy_Original = nullptr;
decltype(&SKILLS_SrvSt10_LightningStrike) SKILLS_SrvSt10_LightningStrike_Original = nullptr;
decltype(&SKILLS_SrvDo006_InnerSight_SlowMissiles) SKILLS_SrvDo006_InnerSight_SlowMissiles_Original = nullptr;
decltype(&SKILLS_AuraCallback_InnerSight_SlowMissiles) SKILLS_AuraCallback_InnerSight_SlowMissiles_Original = nullptr;
decltype(&SKILLS_SrvDo007_Jab) SKILLS_SrvDo007_Jab_Original = nullptr;
decltype(&SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave) SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave_Original = nullptr;
decltype(&SKILLS_SrvDo010_GuidedArrow_BoneSpirit) SKILLS_SrvDo010_GuidedArrow_BoneSpirit_Original = nullptr;
decltype(&SKILLS_AddDamagePercentBonus) SKILLS_AddDamagePercentBonus_Original = nullptr;
decltype(&SKILLS_SrvDo011_ChargedStrike) SKILLS_SrvDo011_ChargedStrike_Original = nullptr;
decltype(&SKILLS_SrvDo012_Strafe) SKILLS_SrvDo012_Strafe_Original = nullptr;
decltype(&SKILLS_SrvDo013_Fend_Zeal_Fury) SKILLS_SrvDo013_Fend_Zeal_Fury_Original = nullptr;
decltype(&SKILLS_SrvDo014_LightningStrike) SKILLS_SrvDo014_LightningStrike_Original = nullptr;
decltype(&SKILLS_SrvDo015_Dopplezon) SKILLS_SrvDo015_Dopplezon_Original = nullptr;
decltype(&SKILLS_SrvDo016_Valkyrie) SKILLS_SrvDo016_Valkyrie_Original = nullptr;

int32_t __stdcall ESE_INTERCEPT_D2Game_10049_Return1(int32_t a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6)
{
    return ESE_D2Game_10049_Return1(a1, a2, a3, a4, a5, a6);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt04_Arrow_Bolt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt04_Arrow_Bolt(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt05_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt05_Jab(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt06_PowerStrike_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt06_PowerStrike_ChargedStrike(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt07_Impale(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt07_Impale(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt08_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt08_Strafe(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt09_Fend(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt09_Fend(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt10_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt10_LightningStrike(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo006_InnerSight_SlowMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo006_InnerSight_SlowMissiles(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_InnerSight_SlowMissiles(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_AuraCallback_InnerSight_SlowMissiles(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo007_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo007_Jab(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo010_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo010_GuidedArrow_BoneSpirit(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int32_t nBonus)
{
    ESE_SKILLS_AddDamagePercentBonus(pUnit, nBonus);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo011_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo011_ChargedStrike(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo012_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo012_Strafe(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo013_Fend_Zeal_Fury(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo013_Fend_Zeal_Fury(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo014_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo014_LightningStrike(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo015_Dopplezon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo015_Dopplezon(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo016_Valkyrie(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo016_Valkyrie(pGame, pUnit, nSkillId, nSkillLevel);
}


