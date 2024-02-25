#pragma once

#include "D2Game/SKILLS/SkillBar_ESE.h"

#include <Units/Units.h>

#include <type_traits>
#include <cstdlib>

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

extern SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite_t SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt33_FindPotion_GrimWard_t SKILLS_SrvSt33_FindPotion_GrimWard_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt33_FindPotion_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo069_FindPotion_t SKILLS_SrvDo069_FindPotion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo069_FindPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_ApplyWarcryStats_t SKILLS_ApplyWarcryStats_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo068_BasicShout_t SKILLS_SrvDo068_BasicShout_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo068_BasicShout(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo070_DoubleSwing_t SKILLS_SrvDo070_DoubleSwing_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo070_DoubleSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_Callback_FindTargetForTaunt_t SKILLS_Callback_FindTargetForTaunt_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern SKILLS_SrvDo071_Taunt_t SKILLS_SrvDo071_Taunt_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo071_Taunt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt34_FindItem_t SKILLS_SrvSt34_FindItem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt34_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo072_FindItem_t SKILLS_SrvDo072_FindItem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo072_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo074_DoubleThrow_t SKILLS_SrvDo074_DoubleThrow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo074_DoubleThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo075_GrimWard_t SKILLS_SrvDo075_GrimWard_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo075_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_RollFrenzyDamage_t SKILLS_RollFrenzyDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_RollFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_ApplyFrenzyStats_t SKILLS_ApplyFrenzyStats_Original;
void __fastcall ESE_INTERCEPT_SKILLS_ApplyFrenzyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo009_Frenzy_t SKILLS_SrvDo009_Frenzy_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo009_Frenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_CurseStateCallback_Whirlwind_t SKILLS_CurseStateCallback_Whirlwind_Original;
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_Whirlwind(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);

extern SKILLS_SrvSt38_Whirlwind_t SKILLS_SrvSt38_Whirlwind_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt38_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_RemoveWhirlwindStats_t SKILLS_RemoveWhirlwindStats_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_RemoveWhirlwindStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int32_t a4, int32_t nX, int32_t nY);

extern SKILLS_SrvDo076_Whirlwind_t SKILLS_SrvDo076_Whirlwind_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo076_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt39_Berserk_t SKILLS_SrvSt39_Berserk_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt39_Berserk(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt40_Leap_t SKILLS_SrvSt40_Leap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt40_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_FindLeapTargetPosition_t SKILLS_FindLeapTargetPosition_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_FindLeapTargetPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t* pX, int32_t* pY);

extern SKILLS_SrvDo077_Leap_t SKILLS_SrvDo077_Leap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo077_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SetVelocityForLeap_t SKILLS_SetVelocityForLeap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SetVelocityForLeap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

extern SKILLS_Leap_t SKILLS_Leap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

extern SKILLS_SrvSt41_LeapAttack_t SKILLS_SrvSt41_LeapAttack_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt41_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo078_LeapAttack_t SKILLS_SrvDo078_LeapAttack_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo078_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_FindLeapAttackTarget_t SKILLS_FindLeapAttackTarget_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindLeapAttackTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

