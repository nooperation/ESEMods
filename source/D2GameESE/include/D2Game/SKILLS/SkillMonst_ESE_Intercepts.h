#pragma once

#include "D2Game/SKILLS/SkillMonst_ESE.h"

#include <Units/Units.h>
#include <DataTbls/SkillsTbls.h>

#include <type_traits>
#include <cstdlib>

//D2Game.0x6FD061C0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt42_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD062E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo083_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD06330
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt43_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD06360
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo084_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD064D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo085_UnholyBolt_ShamanFire(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD06590
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt44_MaggotUp(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD066A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt45_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD06730
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo086_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD06880
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo087_MaggotLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD06A60
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt46_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD06B20
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo088_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD06D60
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt47_Jump(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD070F0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo089_Jump(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD074B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt48_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07540
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo090_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD075E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt49_Nest_EvilHutSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07770
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo091_Nest_EvilHutSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07920
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt50_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07970
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo092_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07A30
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo093_GargoyleTrap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07C50
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt51_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07C70
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo094_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07CB0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt52_Emerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07CD0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt53_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD07D80
void __fastcall ESE_INTERCEPT_SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit);
//D2Game.0x6FD07E30
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo095_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD081E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_UpdateInfernoAnimationParameters(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD082D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo152_DiabLight(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD08680
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo096_ZakarumHeal_Bestow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD08850
int32_t __fastcall ESE_INTERCEPT_SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FD089E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo097_Resurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD08BB0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD08CD0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo099_PrimePoisonNova(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD08EB0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo100_DiabCold(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD09000
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo101_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD092B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo102_DiabWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD09410
void __fastcall ESE_INTERCEPT_SKILLS_MissileInit_DiabWall(D2UnitStrc* pMissile, int32_t nInitSeed);
//D2Game.0x6FD094B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt54_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD09570
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo103_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD09890
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo104_DiabPrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD09970
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo105_DesertTurret(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD09BF0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo106_ArcaneTower(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD09C90
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt55_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD09DE0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo107_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0A190
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo108_RegurgitatorEat(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0A340
int32_t __fastcall ESE_INTERCEPT_SKILLS_GetMonFrenzySequenceFrame(D2UnitStrc* pUnit);
//D2Game.0x6FD0A3D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_RollMonFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0A520
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt25_64_DragonClaw_MonFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0A530
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo109_MonFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0A5E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo148_DoomKnightMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0A720
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo149_NecromageMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0A860
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo110_Hireable_RogueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0A9B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo112_MonCurseCast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0AC20
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_CreateSpiderLayMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FD0AE10
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo111_FetishAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt42_FireHit_t SKILLS_SrvSt42_FireHit_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt42_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo083_FireHit_t SKILLS_SrvDo083_FireHit_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo083_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt43_MaggotEgg_t SKILLS_SrvSt43_MaggotEgg_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt43_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo084_MaggotEgg_t SKILLS_SrvDo084_MaggotEgg_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo084_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo085_UnholyBolt_ShamanFire_t SKILLS_SrvDo085_UnholyBolt_ShamanFire_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo085_UnholyBolt_ShamanFire(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt44_MaggotUp_t SKILLS_SrvSt44_MaggotUp_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt44_MaggotUp(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt45_MaggotDown_t SKILLS_SrvSt45_MaggotDown_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt45_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo086_MaggotDown_t SKILLS_SrvDo086_MaggotDown_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo086_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo087_MaggotLay_t SKILLS_SrvDo087_MaggotLay_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo087_MaggotLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt46_AndrialSpray_t SKILLS_SrvSt46_AndrialSpray_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt46_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo088_AndrialSpray_t SKILLS_SrvDo088_AndrialSpray_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo088_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt47_Jump_t SKILLS_SrvSt47_Jump_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt47_Jump(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo089_Jump_t SKILLS_SrvDo089_Jump_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo089_Jump(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt48_SwarmMove_t SKILLS_SrvSt48_SwarmMove_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt48_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo090_SwarmMove_t SKILLS_SrvDo090_SwarmMove_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo090_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt49_Nest_EvilHutSpawner_t SKILLS_SrvSt49_Nest_EvilHutSpawner_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt49_Nest_EvilHutSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo091_Nest_EvilHutSpawner_t SKILLS_SrvDo091_Nest_EvilHutSpawner_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo091_Nest_EvilHutSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt50_QuickStrike_t SKILLS_SrvSt50_QuickStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt50_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo092_QuickStrike_t SKILLS_SrvDo092_QuickStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo092_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo093_GargoyleTrap_t SKILLS_SrvDo093_GargoyleTrap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo093_GargoyleTrap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt51_Submerge_t SKILLS_SrvSt51_Submerge_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt51_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo094_Submerge_t SKILLS_SrvDo094_Submerge_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo094_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt52_Emerge_t SKILLS_SrvSt52_Emerge_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt52_Emerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt53_MonInferno_t SKILLS_SrvSt53_MonInferno_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt53_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SetInfernoFrame_t SKILLS_SetInfernoFrame_Original;
void __fastcall ESE_INTERCEPT_SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit);

extern SKILLS_SrvDo095_MonInferno_t SKILLS_SrvDo095_MonInferno_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo095_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_UpdateInfernoAnimationParameters_t SKILLS_UpdateInfernoAnimationParameters_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_UpdateInfernoAnimationParameters(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo152_DiabLight_t SKILLS_SrvDo152_DiabLight_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo152_DiabLight(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo096_ZakarumHeal_Bestow_t SKILLS_SrvDo096_ZakarumHeal_Bestow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo096_ZakarumHeal_Bestow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_ResurrectUnit_t SKILLS_ResurrectUnit_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern SKILLS_SrvDo097_Resurrect_t SKILLS_SrvDo097_Resurrect_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo097_Resurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo098_MonTeleport_t SKILLS_SrvDo098_MonTeleport_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo099_PrimePoisonNova_t SKILLS_SrvDo099_PrimePoisonNova_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo099_PrimePoisonNova(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo100_DiabCold_t SKILLS_SrvDo100_DiabCold_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo100_DiabCold(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo101_FingerMageSpider_t SKILLS_SrvDo101_FingerMageSpider_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo101_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo102_DiabWall_t SKILLS_SrvDo102_DiabWall_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo102_DiabWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_MissileInit_DiabWall_t SKILLS_MissileInit_DiabWall_Original;
void __fastcall ESE_INTERCEPT_SKILLS_MissileInit_DiabWall(D2UnitStrc* pMissile, int32_t nInitSeed);

extern SKILLS_SrvSt54_DiabRun_t SKILLS_SrvSt54_DiabRun_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt54_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo103_DiabRun_t SKILLS_SrvDo103_DiabRun_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo103_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo104_DiabPrison_t SKILLS_SrvDo104_DiabPrison_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo104_DiabPrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo105_DesertTurret_t SKILLS_SrvDo105_DesertTurret_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo105_DesertTurret(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo106_ArcaneTower_t SKILLS_SrvDo106_ArcaneTower_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo106_ArcaneTower(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt55_Mosquito_t SKILLS_SrvSt55_Mosquito_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt55_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo107_Mosquito_t SKILLS_SrvDo107_Mosquito_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo107_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo108_RegurgitatorEat_t SKILLS_SrvDo108_RegurgitatorEat_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo108_RegurgitatorEat(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_GetMonFrenzySequenceFrame_t SKILLS_GetMonFrenzySequenceFrame_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_GetMonFrenzySequenceFrame(D2UnitStrc* pUnit);

extern SKILLS_RollMonFrenzyDamage_t SKILLS_RollMonFrenzyDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_RollMonFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt25_64_DragonClaw_MonFrenzy_t SKILLS_SrvSt25_64_DragonClaw_MonFrenzy_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt25_64_DragonClaw_MonFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo109_MonFrenzy_t SKILLS_SrvDo109_MonFrenzy_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo109_MonFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo148_DoomKnightMissile_t SKILLS_SrvDo148_DoomKnightMissile_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo148_DoomKnightMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo149_NecromageMissile_t SKILLS_SrvDo149_NecromageMissile_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo149_NecromageMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo110_Hireable_RogueMissile_t SKILLS_SrvDo110_Hireable_RogueMissile_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo110_Hireable_RogueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo112_MonCurseCast_t SKILLS_SrvDo112_MonCurseCast_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo112_MonCurseCast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_CreateSpiderLayMissile_t SKILLS_CreateSpiderLayMissile_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_CreateSpiderLayMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern SKILLS_SrvDo111_FetishAura_t SKILLS_SrvDo111_FetishAura_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo111_FetishAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

