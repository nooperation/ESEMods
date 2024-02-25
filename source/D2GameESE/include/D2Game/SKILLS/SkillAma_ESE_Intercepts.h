#pragma once

#include "D2Game/SKILLS/SkillAma_ESE.h"

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>

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

extern D2Game_10049_Return1_t D2Game_10049_Return1_Original;
int32_t __stdcall ESE_INTERCEPT_D2Game_10049_Return1(int32_t a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6);

extern SKILLS_SrvSt04_Arrow_Bolt_t SKILLS_SrvSt04_Arrow_Bolt_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt04_Arrow_Bolt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt05_Jab_t SKILLS_SrvSt05_Jab_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt05_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt06_PowerStrike_ChargedStrike_t SKILLS_SrvSt06_PowerStrike_ChargedStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt06_PowerStrike_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt07_Impale_t SKILLS_SrvSt07_Impale_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt07_Impale(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt08_Strafe_t SKILLS_SrvSt08_Strafe_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt08_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt09_Fend_t SKILLS_SrvSt09_Fend_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt09_Fend(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy_t SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt10_LightningStrike_t SKILLS_SrvSt10_LightningStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt10_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo006_InnerSight_SlowMissiles_t SKILLS_SrvDo006_InnerSight_SlowMissiles_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo006_InnerSight_SlowMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_AuraCallback_InnerSight_SlowMissiles_t SKILLS_AuraCallback_InnerSight_SlowMissiles_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_InnerSight_SlowMissiles(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern SKILLS_SrvDo007_Jab_t SKILLS_SrvDo007_Jab_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo007_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave_t SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo010_GuidedArrow_BoneSpirit_t SKILLS_SrvDo010_GuidedArrow_BoneSpirit_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo010_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_AddDamagePercentBonus_t SKILLS_AddDamagePercentBonus_Original;
void __fastcall ESE_INTERCEPT_SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int32_t nBonus);

extern SKILLS_SrvDo011_ChargedStrike_t SKILLS_SrvDo011_ChargedStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo011_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo012_Strafe_t SKILLS_SrvDo012_Strafe_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo012_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo013_Fend_Zeal_Fury_t SKILLS_SrvDo013_Fend_Zeal_Fury_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo013_Fend_Zeal_Fury(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo014_LightningStrike_t SKILLS_SrvDo014_LightningStrike_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo014_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo015_Dopplezon_t SKILLS_SrvDo015_Dopplezon_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo015_Dopplezon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo016_Valkyrie_t SKILLS_SrvDo016_Valkyrie_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo016_Valkyrie(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

