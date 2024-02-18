#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>

#include <SKILLS/SkillAma_ESE.h>

//D2Game.0x6FCF30D0
int32_t __stdcall ESE_INTERCEPT_D2Game_10049_Return1(int32_t a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6);
//D2Game.0x6FCF30E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt04_Arrow_Bolt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF3120
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt05_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF3170
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt06_PowerStrike_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF3280
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt07_Impale(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF3510
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt08_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF3690
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt09_Fend(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF37B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF38C0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt10_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF3A70
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo006_InnerSight_SlowMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF3B90
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_InnerSight_SlowMissiles(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FCF3C00
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo007_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF3D70
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF4080
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo010_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF4280
void __fastcall ESE_INTERCEPT_SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int32_t nBonus);
//D2Game.0x6FCF42B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo011_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF44D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo012_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF47D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo013_Fend_Zeal_Fury(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF4A20
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo014_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF4C50
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo015_Dopplezon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCF4EE0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo016_Valkyrie(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&D2Game_10049_Return1) D2Game_10049_Return1_Original;
int32_t __stdcall ESE_INTERCEPT_D2Game_10049_Return1(int32_t a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6);
static_assert(std::is_same_v<decltype(&D2Game_10049_Return1), decltype(&ESE_INTERCEPT_D2Game_10049_Return1)>, "ESE_INTERCEPT_D2Game_10049_Return1 has a different type than previously known.");

extern decltype(&SKILLS_SrvSt04_Arrow_Bolt) SKILLS_SrvSt04_Arrow_Bolt_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt04_Arrow_Bolt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt04_Arrow_Bolt), decltype(&ESE_INTERCEPT_SKILLS_SrvSt04_Arrow_Bolt)>, "ESE_INTERCEPT_SKILLS_SrvSt04_Arrow_Bolt has a different type than previously known.");

extern decltype(&SKILLS_SrvSt05_Jab) SKILLS_SrvSt05_Jab_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt05_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt05_Jab), decltype(&ESE_INTERCEPT_SKILLS_SrvSt05_Jab)>, "ESE_INTERCEPT_SKILLS_SrvSt05_Jab has a different type than previously known.");

extern decltype(&SKILLS_SrvSt06_PowerStrike_ChargedStrike) SKILLS_SrvSt06_PowerStrike_ChargedStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt06_PowerStrike_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt06_PowerStrike_ChargedStrike), decltype(&ESE_INTERCEPT_SKILLS_SrvSt06_PowerStrike_ChargedStrike)>, "ESE_INTERCEPT_SKILLS_SrvSt06_PowerStrike_ChargedStrike has a different type than previously known.");

extern decltype(&SKILLS_SrvSt07_Impale) SKILLS_SrvSt07_Impale_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt07_Impale(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt07_Impale), decltype(&ESE_INTERCEPT_SKILLS_SrvSt07_Impale)>, "ESE_INTERCEPT_SKILLS_SrvSt07_Impale has a different type than previously known.");

extern decltype(&SKILLS_SrvSt08_Strafe) SKILLS_SrvSt08_Strafe_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt08_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt08_Strafe), decltype(&ESE_INTERCEPT_SKILLS_SrvSt08_Strafe)>, "ESE_INTERCEPT_SKILLS_SrvSt08_Strafe has a different type than previously known.");

extern decltype(&SKILLS_SrvSt09_Fend) SKILLS_SrvSt09_Fend_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt09_Fend(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt09_Fend), decltype(&ESE_INTERCEPT_SKILLS_SrvSt09_Fend)>, "ESE_INTERCEPT_SKILLS_SrvSt09_Fend has a different type than previously known.");

extern decltype(&SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy) SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy), decltype(&ESE_INTERCEPT_SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy)>, "ESE_INTERCEPT_SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy has a different type than previously known.");

extern decltype(&SKILLS_SrvSt10_LightningStrike) SKILLS_SrvSt10_LightningStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt10_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt10_LightningStrike), decltype(&ESE_INTERCEPT_SKILLS_SrvSt10_LightningStrike)>, "ESE_INTERCEPT_SKILLS_SrvSt10_LightningStrike has a different type than previously known.");

extern decltype(&SKILLS_SrvDo006_InnerSight_SlowMissiles) SKILLS_SrvDo006_InnerSight_SlowMissiles_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo006_InnerSight_SlowMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo006_InnerSight_SlowMissiles), decltype(&ESE_INTERCEPT_SKILLS_SrvDo006_InnerSight_SlowMissiles)>, "ESE_INTERCEPT_SKILLS_SrvDo006_InnerSight_SlowMissiles has a different type than previously known.");

extern decltype(&SKILLS_AuraCallback_InnerSight_SlowMissiles) SKILLS_AuraCallback_InnerSight_SlowMissiles_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_InnerSight_SlowMissiles(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SKILLS_AuraCallback_InnerSight_SlowMissiles), decltype(&ESE_INTERCEPT_SKILLS_AuraCallback_InnerSight_SlowMissiles)>, "ESE_INTERCEPT_SKILLS_AuraCallback_InnerSight_SlowMissiles has a different type than previously known.");

extern decltype(&SKILLS_SrvDo007_Jab) SKILLS_SrvDo007_Jab_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo007_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo007_Jab), decltype(&ESE_INTERCEPT_SKILLS_SrvDo007_Jab)>, "ESE_INTERCEPT_SKILLS_SrvDo007_Jab has a different type than previously known.");

extern decltype(&SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave) SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave), decltype(&ESE_INTERCEPT_SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave)>, "ESE_INTERCEPT_SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave has a different type than previously known.");

extern decltype(&SKILLS_SrvDo010_GuidedArrow_BoneSpirit) SKILLS_SrvDo010_GuidedArrow_BoneSpirit_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo010_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo010_GuidedArrow_BoneSpirit), decltype(&ESE_INTERCEPT_SKILLS_SrvDo010_GuidedArrow_BoneSpirit)>, "ESE_INTERCEPT_SKILLS_SrvDo010_GuidedArrow_BoneSpirit has a different type than previously known.");

extern decltype(&SKILLS_AddDamagePercentBonus) SKILLS_AddDamagePercentBonus_Original;
void __fastcall ESE_INTERCEPT_SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int32_t nBonus);
static_assert(std::is_same_v<decltype(&SKILLS_AddDamagePercentBonus), decltype(&ESE_INTERCEPT_SKILLS_AddDamagePercentBonus)>, "ESE_INTERCEPT_SKILLS_AddDamagePercentBonus has a different type than previously known.");

extern decltype(&SKILLS_SrvDo011_ChargedStrike) SKILLS_SrvDo011_ChargedStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo011_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo011_ChargedStrike), decltype(&ESE_INTERCEPT_SKILLS_SrvDo011_ChargedStrike)>, "ESE_INTERCEPT_SKILLS_SrvDo011_ChargedStrike has a different type than previously known.");

extern decltype(&SKILLS_SrvDo012_Strafe) SKILLS_SrvDo012_Strafe_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo012_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo012_Strafe), decltype(&ESE_INTERCEPT_SKILLS_SrvDo012_Strafe)>, "ESE_INTERCEPT_SKILLS_SrvDo012_Strafe has a different type than previously known.");

extern decltype(&SKILLS_SrvDo013_Fend_Zeal_Fury) SKILLS_SrvDo013_Fend_Zeal_Fury_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo013_Fend_Zeal_Fury(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo013_Fend_Zeal_Fury), decltype(&ESE_INTERCEPT_SKILLS_SrvDo013_Fend_Zeal_Fury)>, "ESE_INTERCEPT_SKILLS_SrvDo013_Fend_Zeal_Fury has a different type than previously known.");

extern decltype(&SKILLS_SrvDo014_LightningStrike) SKILLS_SrvDo014_LightningStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo014_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo014_LightningStrike), decltype(&ESE_INTERCEPT_SKILLS_SrvDo014_LightningStrike)>, "ESE_INTERCEPT_SKILLS_SrvDo014_LightningStrike has a different type than previously known.");

extern decltype(&SKILLS_SrvDo015_Dopplezon) SKILLS_SrvDo015_Dopplezon_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo015_Dopplezon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo015_Dopplezon), decltype(&ESE_INTERCEPT_SKILLS_SrvDo015_Dopplezon)>, "ESE_INTERCEPT_SKILLS_SrvDo015_Dopplezon has a different type than previously known.");

extern decltype(&SKILLS_SrvDo016_Valkyrie) SKILLS_SrvDo016_Valkyrie_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo016_Valkyrie(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo016_Valkyrie), decltype(&ESE_INTERCEPT_SKILLS_SrvDo016_Valkyrie)>, "ESE_INTERCEPT_SKILLS_SrvDo016_Valkyrie has a different type than previously known.");

