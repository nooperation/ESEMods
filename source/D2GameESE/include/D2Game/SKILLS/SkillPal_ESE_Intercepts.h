#pragma once

#include "D2Game/UNIT/SUnitDmg_ESE.h"
#include "D2Game/SKILLS/SkillPal_ESE.h"

#include <D2StatList.h>
#include <Units/Units.h>

#include <type_traits>
#include <cstdlib>

//D2Game.0x6FD18330
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt29_Sacrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD184B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo064_Sacrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD18650
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo150_Smite(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD18900
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo065_BasicAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD18BC0
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD18FE0
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_BasicAura(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);
//D2Game.0x6FD19020
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD19390
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD19460
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt31_Charge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD19780
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo067_Charge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD19C80
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt35_Vengeance(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD1A200
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo073_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD1A480
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt36_HolyShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD1A4A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo079_Conversion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD1A900
void __fastcall ESE_INTERCEPT_SKILLS_StatRemoveCallback_Conversion(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);
//D2Game.0x6FD1AA50
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo080_FistOfTheHeavens(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD1ABC0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo081_HolyFreeze(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD1AF40
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_HolyFreeze(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);
//D2Game.0x6FD1AF90
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_HolyFreeze(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD1B100
int32_t __fastcall ESE_INTERCEPT_SKILLS_ApplyRedemptionEffect(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int32_t nSkillId, int32_t nSkillLevel, int32_t bSkipChanceRoll);
//D2Game.0x6FD1B260
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo082_Redemption(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD1B490
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD1B4C0
void __fastcall ESE_INTERCEPT_SKILLS_ApplyThornsDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);

extern SKILLS_SrvSt29_Sacrifice_t SKILLS_SrvSt29_Sacrifice_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt29_Sacrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo064_Sacrifice_t SKILLS_SrvDo064_Sacrifice_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo064_Sacrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo150_Smite_t SKILLS_SrvDo150_Smite_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo150_Smite(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo065_BasicAura_t SKILLS_SrvDo065_BasicAura_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo065_BasicAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_AuraCallback_BasicAura_t SKILLS_AuraCallback_BasicAura_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern SKILLS_CurseStateCallback_BasicAura_t SKILLS_CurseStateCallback_BasicAura_Original;
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_BasicAura(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);

extern SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction_t SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction_t SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern SKILLS_SrvSt31_Charge_t SKILLS_SrvSt31_Charge_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt31_Charge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo067_Charge_t SKILLS_SrvDo067_Charge_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo067_Charge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt35_Vengeance_t SKILLS_SrvSt35_Vengeance_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt35_Vengeance(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo073_BlessedHammer_t SKILLS_SrvDo073_BlessedHammer_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo073_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt36_HolyShield_t SKILLS_SrvSt36_HolyShield_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt36_HolyShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo079_Conversion_t SKILLS_SrvDo079_Conversion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo079_Conversion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_StatRemoveCallback_Conversion_t SKILLS_StatRemoveCallback_Conversion_Original;
void __fastcall ESE_INTERCEPT_SKILLS_StatRemoveCallback_Conversion(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);

extern SKILLS_SrvDo080_FistOfTheHeavens_t SKILLS_SrvDo080_FistOfTheHeavens_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo080_FistOfTheHeavens(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo081_HolyFreeze_t SKILLS_SrvDo081_HolyFreeze_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo081_HolyFreeze(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_CurseStateCallback_HolyFreeze_t SKILLS_CurseStateCallback_HolyFreeze_Original;
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_HolyFreeze(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);

extern SKILLS_AuraCallback_HolyFreeze_t SKILLS_AuraCallback_HolyFreeze_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_HolyFreeze(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern SKILLS_ApplyRedemptionEffect_t SKILLS_ApplyRedemptionEffect_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_ApplyRedemptionEffect(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int32_t nSkillId, int32_t nSkillLevel, int32_t bSkipChanceRoll);

extern SKILLS_SrvDo082_Redemption_t SKILLS_SrvDo082_Redemption_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo082_Redemption(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_AuraCallback_Redemption_t SKILLS_AuraCallback_Redemption_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern SKILLS_ApplyThornsDamage_t SKILLS_ApplyThornsDamage_Original;
void __fastcall ESE_INTERCEPT_SKILLS_ApplyThornsDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);

