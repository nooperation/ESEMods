#include "D2Game/SKILLS/SkillMonst_ESE_Intercepts.h"

decltype(&SKILLS_SrvSt42_FireHit) SKILLS_SrvSt42_FireHit_Original = nullptr;
decltype(&SKILLS_SrvDo083_FireHit) SKILLS_SrvDo083_FireHit_Original = nullptr;
decltype(&SKILLS_SrvSt43_MaggotEgg) SKILLS_SrvSt43_MaggotEgg_Original = nullptr;
decltype(&SKILLS_SrvDo084_MaggotEgg) SKILLS_SrvDo084_MaggotEgg_Original = nullptr;
decltype(&SKILLS_SrvDo085_UnholyBolt_ShamanFire) SKILLS_SrvDo085_UnholyBolt_ShamanFire_Original = nullptr;
decltype(&SKILLS_SrvSt44_MaggotUp) SKILLS_SrvSt44_MaggotUp_Original = nullptr;
decltype(&SKILLS_SrvSt45_MaggotDown) SKILLS_SrvSt45_MaggotDown_Original = nullptr;
decltype(&SKILLS_SrvDo086_MaggotDown) SKILLS_SrvDo086_MaggotDown_Original = nullptr;
decltype(&SKILLS_SrvDo087_MaggotLay) SKILLS_SrvDo087_MaggotLay_Original = nullptr;
decltype(&SKILLS_SrvSt46_AndrialSpray) SKILLS_SrvSt46_AndrialSpray_Original = nullptr;
decltype(&SKILLS_SrvDo088_AndrialSpray) SKILLS_SrvDo088_AndrialSpray_Original = nullptr;
decltype(&SKILLS_SrvSt47_Jump) SKILLS_SrvSt47_Jump_Original = nullptr;
decltype(&SKILLS_SrvDo089_Jump) SKILLS_SrvDo089_Jump_Original = nullptr;
decltype(&SKILLS_SrvSt48_SwarmMove) SKILLS_SrvSt48_SwarmMove_Original = nullptr;
decltype(&SKILLS_SrvDo090_SwarmMove) SKILLS_SrvDo090_SwarmMove_Original = nullptr;
decltype(&SKILLS_SrvSt49_Nest_EvilHutSpawner) SKILLS_SrvSt49_Nest_EvilHutSpawner_Original = nullptr;
decltype(&SKILLS_SrvDo091_Nest_EvilHutSpawner) SKILLS_SrvDo091_Nest_EvilHutSpawner_Original = nullptr;
decltype(&SKILLS_SrvSt50_QuickStrike) SKILLS_SrvSt50_QuickStrike_Original = nullptr;
decltype(&SKILLS_SrvDo092_QuickStrike) SKILLS_SrvDo092_QuickStrike_Original = nullptr;
decltype(&SKILLS_SrvDo093_GargoyleTrap) SKILLS_SrvDo093_GargoyleTrap_Original = nullptr;
decltype(&SKILLS_SrvSt51_Submerge) SKILLS_SrvSt51_Submerge_Original = nullptr;
decltype(&SKILLS_SrvDo094_Submerge) SKILLS_SrvDo094_Submerge_Original = nullptr;
decltype(&SKILLS_SrvSt52_Emerge) SKILLS_SrvSt52_Emerge_Original = nullptr;
decltype(&SKILLS_SrvSt53_MonInferno) SKILLS_SrvSt53_MonInferno_Original = nullptr;
decltype(&SKILLS_SetInfernoFrame) SKILLS_SetInfernoFrame_Original = nullptr;
decltype(&SKILLS_SrvDo095_MonInferno) SKILLS_SrvDo095_MonInferno_Original = nullptr;
decltype(&SKILLS_UpdateInfernoAnimationParameters) SKILLS_UpdateInfernoAnimationParameters_Original = nullptr;
decltype(&SKILLS_SrvDo152_DiabLight) SKILLS_SrvDo152_DiabLight_Original = nullptr;
decltype(&SKILLS_SrvDo096_ZakarumHeal_Bestow) SKILLS_SrvDo096_ZakarumHeal_Bestow_Original = nullptr;
decltype(&SKILLS_ResurrectUnit) SKILLS_ResurrectUnit_Original = nullptr;
decltype(&SKILLS_SrvDo097_Resurrect) SKILLS_SrvDo097_Resurrect_Original = nullptr;
decltype(&SKILLS_SrvDo098_MonTeleport) SKILLS_SrvDo098_MonTeleport_Original = nullptr;
decltype(&SKILLS_SrvDo099_PrimePoisonNova) SKILLS_SrvDo099_PrimePoisonNova_Original = nullptr;
decltype(&SKILLS_SrvDo100_DiabCold) SKILLS_SrvDo100_DiabCold_Original = nullptr;
decltype(&SKILLS_SrvDo101_FingerMageSpider) SKILLS_SrvDo101_FingerMageSpider_Original = nullptr;
decltype(&SKILLS_SrvDo102_DiabWall) SKILLS_SrvDo102_DiabWall_Original = nullptr;
decltype(&SKILLS_MissileInit_DiabWall) SKILLS_MissileInit_DiabWall_Original = nullptr;
decltype(&SKILLS_SrvSt54_DiabRun) SKILLS_SrvSt54_DiabRun_Original = nullptr;
decltype(&SKILLS_SrvDo103_DiabRun) SKILLS_SrvDo103_DiabRun_Original = nullptr;
decltype(&SKILLS_SrvDo104_DiabPrison) SKILLS_SrvDo104_DiabPrison_Original = nullptr;
decltype(&SKILLS_SrvDo105_DesertTurret) SKILLS_SrvDo105_DesertTurret_Original = nullptr;
decltype(&SKILLS_SrvDo106_ArcaneTower) SKILLS_SrvDo106_ArcaneTower_Original = nullptr;
decltype(&SKILLS_SrvSt55_Mosquito) SKILLS_SrvSt55_Mosquito_Original = nullptr;
decltype(&SKILLS_SrvDo107_Mosquito) SKILLS_SrvDo107_Mosquito_Original = nullptr;
decltype(&SKILLS_SrvDo108_RegurgitatorEat) SKILLS_SrvDo108_RegurgitatorEat_Original = nullptr;
decltype(&SKILLS_GetMonFrenzySequenceFrame) SKILLS_GetMonFrenzySequenceFrame_Original = nullptr;
decltype(&SKILLS_RollMonFrenzyDamage) SKILLS_RollMonFrenzyDamage_Original = nullptr;
decltype(&SKILLS_SrvSt25_64_DragonClaw_MonFrenzy) SKILLS_SrvSt25_64_DragonClaw_MonFrenzy_Original = nullptr;
decltype(&SKILLS_SrvDo109_MonFrenzy) SKILLS_SrvDo109_MonFrenzy_Original = nullptr;
decltype(&SKILLS_SrvDo148_DoomKnightMissile) SKILLS_SrvDo148_DoomKnightMissile_Original = nullptr;
decltype(&SKILLS_SrvDo149_NecromageMissile) SKILLS_SrvDo149_NecromageMissile_Original = nullptr;
decltype(&SKILLS_SrvDo110_Hireable_RogueMissile) SKILLS_SrvDo110_Hireable_RogueMissile_Original = nullptr;
decltype(&SKILLS_SrvDo112_MonCurseCast) SKILLS_SrvDo112_MonCurseCast_Original = nullptr;
decltype(&SKILLS_CreateSpiderLayMissile) SKILLS_CreateSpiderLayMissile_Original = nullptr;
decltype(&SKILLS_SrvDo111_FetishAura) SKILLS_SrvDo111_FetishAura_Original = nullptr;

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


