#include "D2Game/SKILLS/SkillMonst_ESE_Intercepts.h"

SKILLS_SrvSt42_FireHit_t SKILLS_SrvSt42_FireHit_Original = nullptr;
SKILLS_SrvDo083_FireHit_t SKILLS_SrvDo083_FireHit_Original = nullptr;
SKILLS_SrvSt43_MaggotEgg_t SKILLS_SrvSt43_MaggotEgg_Original = nullptr;
SKILLS_SrvDo084_MaggotEgg_t SKILLS_SrvDo084_MaggotEgg_Original = nullptr;
SKILLS_SrvDo085_UnholyBolt_ShamanFire_t SKILLS_SrvDo085_UnholyBolt_ShamanFire_Original = nullptr;
SKILLS_SrvSt44_MaggotUp_t SKILLS_SrvSt44_MaggotUp_Original = nullptr;
SKILLS_SrvSt45_MaggotDown_t SKILLS_SrvSt45_MaggotDown_Original = nullptr;
SKILLS_SrvDo086_MaggotDown_t SKILLS_SrvDo086_MaggotDown_Original = nullptr;
SKILLS_SrvDo087_MaggotLay_t SKILLS_SrvDo087_MaggotLay_Original = nullptr;
SKILLS_SrvSt46_AndrialSpray_t SKILLS_SrvSt46_AndrialSpray_Original = nullptr;
SKILLS_SrvDo088_AndrialSpray_t SKILLS_SrvDo088_AndrialSpray_Original = nullptr;
SKILLS_SrvSt47_Jump_t SKILLS_SrvSt47_Jump_Original = nullptr;
SKILLS_SrvDo089_Jump_t SKILLS_SrvDo089_Jump_Original = nullptr;
SKILLS_SrvSt48_SwarmMove_t SKILLS_SrvSt48_SwarmMove_Original = nullptr;
SKILLS_SrvDo090_SwarmMove_t SKILLS_SrvDo090_SwarmMove_Original = nullptr;
SKILLS_SrvSt49_Nest_EvilHutSpawner_t SKILLS_SrvSt49_Nest_EvilHutSpawner_Original = nullptr;
SKILLS_SrvDo091_Nest_EvilHutSpawner_t SKILLS_SrvDo091_Nest_EvilHutSpawner_Original = nullptr;
SKILLS_SrvSt50_QuickStrike_t SKILLS_SrvSt50_QuickStrike_Original = nullptr;
SKILLS_SrvDo092_QuickStrike_t SKILLS_SrvDo092_QuickStrike_Original = nullptr;
SKILLS_SrvDo093_GargoyleTrap_t SKILLS_SrvDo093_GargoyleTrap_Original = nullptr;
SKILLS_SrvSt51_Submerge_t SKILLS_SrvSt51_Submerge_Original = nullptr;
SKILLS_SrvDo094_Submerge_t SKILLS_SrvDo094_Submerge_Original = nullptr;
SKILLS_SrvSt52_Emerge_t SKILLS_SrvSt52_Emerge_Original = nullptr;
SKILLS_SrvSt53_MonInferno_t SKILLS_SrvSt53_MonInferno_Original = nullptr;
SKILLS_SetInfernoFrame_t SKILLS_SetInfernoFrame_Original = nullptr;
SKILLS_SrvDo095_MonInferno_t SKILLS_SrvDo095_MonInferno_Original = nullptr;
SKILLS_UpdateInfernoAnimationParameters_t SKILLS_UpdateInfernoAnimationParameters_Original = nullptr;
SKILLS_SrvDo152_DiabLight_t SKILLS_SrvDo152_DiabLight_Original = nullptr;
SKILLS_SrvDo096_ZakarumHeal_Bestow_t SKILLS_SrvDo096_ZakarumHeal_Bestow_Original = nullptr;
SKILLS_ResurrectUnit_t SKILLS_ResurrectUnit_Original = nullptr;
SKILLS_SrvDo097_Resurrect_t SKILLS_SrvDo097_Resurrect_Original = nullptr;
SKILLS_SrvDo098_MonTeleport_t SKILLS_SrvDo098_MonTeleport_Original = nullptr;
SKILLS_SrvDo099_PrimePoisonNova_t SKILLS_SrvDo099_PrimePoisonNova_Original = nullptr;
SKILLS_SrvDo100_DiabCold_t SKILLS_SrvDo100_DiabCold_Original = nullptr;
SKILLS_SrvDo101_FingerMageSpider_t SKILLS_SrvDo101_FingerMageSpider_Original = nullptr;
SKILLS_SrvDo102_DiabWall_t SKILLS_SrvDo102_DiabWall_Original = nullptr;
SKILLS_MissileInit_DiabWall_t SKILLS_MissileInit_DiabWall_Original = nullptr;
SKILLS_SrvSt54_DiabRun_t SKILLS_SrvSt54_DiabRun_Original = nullptr;
SKILLS_SrvDo103_DiabRun_t SKILLS_SrvDo103_DiabRun_Original = nullptr;
SKILLS_SrvDo104_DiabPrison_t SKILLS_SrvDo104_DiabPrison_Original = nullptr;
SKILLS_SrvDo105_DesertTurret_t SKILLS_SrvDo105_DesertTurret_Original = nullptr;
SKILLS_SrvDo106_ArcaneTower_t SKILLS_SrvDo106_ArcaneTower_Original = nullptr;
SKILLS_SrvSt55_Mosquito_t SKILLS_SrvSt55_Mosquito_Original = nullptr;
SKILLS_SrvDo107_Mosquito_t SKILLS_SrvDo107_Mosquito_Original = nullptr;
SKILLS_SrvDo108_RegurgitatorEat_t SKILLS_SrvDo108_RegurgitatorEat_Original = nullptr;
SKILLS_GetMonFrenzySequenceFrame_t SKILLS_GetMonFrenzySequenceFrame_Original = nullptr;
SKILLS_RollMonFrenzyDamage_t SKILLS_RollMonFrenzyDamage_Original = nullptr;
SKILLS_SrvSt25_64_DragonClaw_MonFrenzy_t SKILLS_SrvSt25_64_DragonClaw_MonFrenzy_Original = nullptr;
SKILLS_SrvDo109_MonFrenzy_t SKILLS_SrvDo109_MonFrenzy_Original = nullptr;
SKILLS_SrvDo148_DoomKnightMissile_t SKILLS_SrvDo148_DoomKnightMissile_Original = nullptr;
SKILLS_SrvDo149_NecromageMissile_t SKILLS_SrvDo149_NecromageMissile_Original = nullptr;
SKILLS_SrvDo110_Hireable_RogueMissile_t SKILLS_SrvDo110_Hireable_RogueMissile_Original = nullptr;
SKILLS_SrvDo112_MonCurseCast_t SKILLS_SrvDo112_MonCurseCast_Original = nullptr;
SKILLS_CreateSpiderLayMissile_t SKILLS_CreateSpiderLayMissile_Original = nullptr;
SKILLS_SrvDo111_FetishAura_t SKILLS_SrvDo111_FetishAura_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt42_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt42_FireHit(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo083_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo083_FireHit(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt43_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt43_MaggotEgg(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo084_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo084_MaggotEgg(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo085_UnholyBolt_ShamanFire(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo085_UnholyBolt_ShamanFire(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt44_MaggotUp(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt44_MaggotUp(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt45_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt45_MaggotDown(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo086_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo086_MaggotDown(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo087_MaggotLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo087_MaggotLay(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt46_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt46_AndrialSpray(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo088_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo088_AndrialSpray(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt47_Jump(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt47_Jump(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo089_Jump(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo089_Jump(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt48_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt48_SwarmMove(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo090_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo090_SwarmMove(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt49_Nest_EvilHutSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt49_Nest_EvilHutSpawner(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo091_Nest_EvilHutSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo091_Nest_EvilHutSpawner(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt50_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt50_QuickStrike(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo092_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo092_QuickStrike(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo093_GargoyleTrap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo093_GargoyleTrap(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt51_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt51_Submerge(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo094_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo094_Submerge(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt52_Emerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt52_Emerge(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt53_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt53_MonInferno(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit)
{
    ESE_SKILLS_SetInfernoFrame(pSkillsTxtRecord, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo095_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo095_MonInferno(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_UpdateInfernoAnimationParameters(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_UpdateInfernoAnimationParameters(pUnit, pMissile, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo152_DiabLight(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo152_DiabLight(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo096_ZakarumHeal_Bestow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo096_ZakarumHeal_Bestow(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_ResurrectUnit(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo097_Resurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo097_Resurrect(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo098_MonTeleport(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo099_PrimePoisonNova(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo099_PrimePoisonNova(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo100_DiabCold(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo100_DiabCold(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo101_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo101_FingerMageSpider(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo102_DiabWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo102_DiabWall(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_MissileInit_DiabWall(D2UnitStrc* pMissile, int32_t nInitSeed)
{
    ESE_SKILLS_MissileInit_DiabWall(pMissile, nInitSeed);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt54_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt54_DiabRun(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo103_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo103_DiabRun(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo104_DiabPrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo104_DiabPrison(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo105_DesertTurret(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo105_DesertTurret(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo106_ArcaneTower(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo106_ArcaneTower(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt55_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt55_Mosquito(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo107_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo107_Mosquito(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo108_RegurgitatorEat(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo108_RegurgitatorEat(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_GetMonFrenzySequenceFrame(D2UnitStrc* pUnit)
{
    return ESE_SKILLS_GetMonFrenzySequenceFrame(pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_RollMonFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_RollMonFrenzyDamage(pGame, pUnit, pTargetUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt25_64_DragonClaw_MonFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt25_64_DragonClaw_MonFrenzy(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo109_MonFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo109_MonFrenzy(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo148_DoomKnightMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo148_DoomKnightMissile(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo149_NecromageMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo149_NecromageMissile(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo110_Hireable_RogueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo110_Hireable_RogueMissile(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo112_MonCurseCast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo112_MonCurseCast(pGame, pUnit, nSkillId, nSkillLevel);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_CreateSpiderLayMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_CreateSpiderLayMissile(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo111_FetishAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo111_FetishAura(pGame, pUnit, nSkillId, nSkillLevel);
}


