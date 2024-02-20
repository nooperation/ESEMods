#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>

#include <SKILLS/SkillBar_ESE.h>

//D2Game.0x6FCFABF0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFAE50
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt33_FindPotion_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFAE90
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo069_FindPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFB070
int32_t __fastcall ESE_INTERCEPT_SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFB1D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo068_BasicShout(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFB270
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo070_DoubleSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFB320
int32_t __fastcall ESE_INTERCEPT_SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCFB390
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo071_Taunt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFB610
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt34_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFB630
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo072_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFB7A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo074_DoubleThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFB8A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo075_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFBB40
int32_t __fastcall ESE_INTERCEPT_SKILLS_RollFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFBCE0
void __fastcall ESE_INTERCEPT_SKILLS_ApplyFrenzyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFBE80
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo009_Frenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFBF80
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_Whirlwind(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);
//D2Game.0x6FCFBFE0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt38_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFC3A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_RemoveWhirlwindStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int32_t a4, int32_t nX, int32_t nY);
//D2Game.0x6FCFC4C0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo076_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFC8E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt39_Berserk(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFCB30
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt40_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFCF60
int32_t __fastcall ESE_INTERCEPT_SKILLS_FindLeapTargetPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t* pX, int32_t* pY);
//D2Game.0x6FCFD280
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo077_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFD3C0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SetVelocityForLeap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);
//D2Game.0x6FCFD4C0
int32_t __fastcall ESE_INTERCEPT_SKILLS_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);
//D2Game.0x6FCFD880
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt41_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFD9B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo078_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFDC40
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindLeapAttackTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

extern decltype(&SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite) SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt33_FindPotion_GrimWard) SKILLS_SrvSt33_FindPotion_GrimWard_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt33_FindPotion_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo069_FindPotion) SKILLS_SrvDo069_FindPotion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo069_FindPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_ApplyWarcryStats) SKILLS_ApplyWarcryStats_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo068_BasicShout) SKILLS_SrvDo068_BasicShout_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo068_BasicShout(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo070_DoubleSwing) SKILLS_SrvDo070_DoubleSwing_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo070_DoubleSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_Callback_FindTargetForTaunt) SKILLS_Callback_FindTargetForTaunt_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern decltype(&SKILLS_SrvDo071_Taunt) SKILLS_SrvDo071_Taunt_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo071_Taunt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt34_FindItem) SKILLS_SrvSt34_FindItem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt34_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo072_FindItem) SKILLS_SrvDo072_FindItem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo072_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo074_DoubleThrow) SKILLS_SrvDo074_DoubleThrow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo074_DoubleThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo075_GrimWard) SKILLS_SrvDo075_GrimWard_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo075_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_RollFrenzyDamage) SKILLS_RollFrenzyDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_RollFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_ApplyFrenzyStats) SKILLS_ApplyFrenzyStats_Original;
void __fastcall ESE_INTERCEPT_SKILLS_ApplyFrenzyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo009_Frenzy) SKILLS_SrvDo009_Frenzy_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo009_Frenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_CurseStateCallback_Whirlwind) SKILLS_CurseStateCallback_Whirlwind_Original;
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_Whirlwind(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);

extern decltype(&SKILLS_SrvSt38_Whirlwind) SKILLS_SrvSt38_Whirlwind_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt38_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_RemoveWhirlwindStats) SKILLS_RemoveWhirlwindStats_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_RemoveWhirlwindStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int32_t a4, int32_t nX, int32_t nY);

extern decltype(&SKILLS_SrvDo076_Whirlwind) SKILLS_SrvDo076_Whirlwind_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo076_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt39_Berserk) SKILLS_SrvSt39_Berserk_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt39_Berserk(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt40_Leap) SKILLS_SrvSt40_Leap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt40_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_FindLeapTargetPosition) SKILLS_FindLeapTargetPosition_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_FindLeapTargetPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t* pX, int32_t* pY);

extern decltype(&SKILLS_SrvDo077_Leap) SKILLS_SrvDo077_Leap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo077_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SetVelocityForLeap) SKILLS_SetVelocityForLeap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SetVelocityForLeap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

extern decltype(&SKILLS_Leap) SKILLS_Leap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

extern decltype(&SKILLS_SrvSt41_LeapAttack) SKILLS_SrvSt41_LeapAttack_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt41_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo078_LeapAttack) SKILLS_SrvDo078_LeapAttack_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo078_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_FindLeapAttackTarget) SKILLS_FindLeapAttackTarget_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindLeapAttackTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

