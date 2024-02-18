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
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite), decltype(&ESE_INTERCEPT_SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite)>, "ESE_INTERCEPT_SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite has a different type than previously known.");

extern decltype(&SKILLS_SrvSt33_FindPotion_GrimWard) SKILLS_SrvSt33_FindPotion_GrimWard_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt33_FindPotion_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt33_FindPotion_GrimWard), decltype(&ESE_INTERCEPT_SKILLS_SrvSt33_FindPotion_GrimWard)>, "ESE_INTERCEPT_SKILLS_SrvSt33_FindPotion_GrimWard has a different type than previously known.");

extern decltype(&SKILLS_SrvDo069_FindPotion) SKILLS_SrvDo069_FindPotion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo069_FindPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo069_FindPotion), decltype(&ESE_INTERCEPT_SKILLS_SrvDo069_FindPotion)>, "ESE_INTERCEPT_SKILLS_SrvDo069_FindPotion has a different type than previously known.");

extern decltype(&SKILLS_ApplyWarcryStats) SKILLS_ApplyWarcryStats_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_ApplyWarcryStats), decltype(&ESE_INTERCEPT_SKILLS_ApplyWarcryStats)>, "ESE_INTERCEPT_SKILLS_ApplyWarcryStats has a different type than previously known.");

extern decltype(&SKILLS_SrvDo068_BasicShout) SKILLS_SrvDo068_BasicShout_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo068_BasicShout(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo068_BasicShout), decltype(&ESE_INTERCEPT_SKILLS_SrvDo068_BasicShout)>, "ESE_INTERCEPT_SKILLS_SrvDo068_BasicShout has a different type than previously known.");

extern decltype(&SKILLS_SrvDo070_DoubleSwing) SKILLS_SrvDo070_DoubleSwing_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo070_DoubleSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo070_DoubleSwing), decltype(&ESE_INTERCEPT_SKILLS_SrvDo070_DoubleSwing)>, "ESE_INTERCEPT_SKILLS_SrvDo070_DoubleSwing has a different type than previously known.");

extern decltype(&SKILLS_Callback_FindTargetForTaunt) SKILLS_Callback_FindTargetForTaunt_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SKILLS_Callback_FindTargetForTaunt), decltype(&ESE_INTERCEPT_SKILLS_Callback_FindTargetForTaunt)>, "ESE_INTERCEPT_SKILLS_Callback_FindTargetForTaunt has a different type than previously known.");

extern decltype(&SKILLS_SrvDo071_Taunt) SKILLS_SrvDo071_Taunt_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo071_Taunt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo071_Taunt), decltype(&ESE_INTERCEPT_SKILLS_SrvDo071_Taunt)>, "ESE_INTERCEPT_SKILLS_SrvDo071_Taunt has a different type than previously known.");

extern decltype(&SKILLS_SrvSt34_FindItem) SKILLS_SrvSt34_FindItem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt34_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt34_FindItem), decltype(&ESE_INTERCEPT_SKILLS_SrvSt34_FindItem)>, "ESE_INTERCEPT_SKILLS_SrvSt34_FindItem has a different type than previously known.");

extern decltype(&SKILLS_SrvDo072_FindItem) SKILLS_SrvDo072_FindItem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo072_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo072_FindItem), decltype(&ESE_INTERCEPT_SKILLS_SrvDo072_FindItem)>, "ESE_INTERCEPT_SKILLS_SrvDo072_FindItem has a different type than previously known.");

extern decltype(&SKILLS_SrvDo074_DoubleThrow) SKILLS_SrvDo074_DoubleThrow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo074_DoubleThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo074_DoubleThrow), decltype(&ESE_INTERCEPT_SKILLS_SrvDo074_DoubleThrow)>, "ESE_INTERCEPT_SKILLS_SrvDo074_DoubleThrow has a different type than previously known.");

extern decltype(&SKILLS_SrvDo075_GrimWard) SKILLS_SrvDo075_GrimWard_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo075_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo075_GrimWard), decltype(&ESE_INTERCEPT_SKILLS_SrvDo075_GrimWard)>, "ESE_INTERCEPT_SKILLS_SrvDo075_GrimWard has a different type than previously known.");

extern decltype(&SKILLS_RollFrenzyDamage) SKILLS_RollFrenzyDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_RollFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_RollFrenzyDamage), decltype(&ESE_INTERCEPT_SKILLS_RollFrenzyDamage)>, "ESE_INTERCEPT_SKILLS_RollFrenzyDamage has a different type than previously known.");

extern decltype(&SKILLS_ApplyFrenzyStats) SKILLS_ApplyFrenzyStats_Original;
void __fastcall ESE_INTERCEPT_SKILLS_ApplyFrenzyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_ApplyFrenzyStats), decltype(&ESE_INTERCEPT_SKILLS_ApplyFrenzyStats)>, "ESE_INTERCEPT_SKILLS_ApplyFrenzyStats has a different type than previously known.");

extern decltype(&SKILLS_SrvDo009_Frenzy) SKILLS_SrvDo009_Frenzy_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo009_Frenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo009_Frenzy), decltype(&ESE_INTERCEPT_SKILLS_SrvDo009_Frenzy)>, "ESE_INTERCEPT_SKILLS_SrvDo009_Frenzy has a different type than previously known.");

extern decltype(&SKILLS_CurseStateCallback_Whirlwind) SKILLS_CurseStateCallback_Whirlwind_Original;
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_Whirlwind(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList);
static_assert(std::is_same_v<decltype(&SKILLS_CurseStateCallback_Whirlwind), decltype(&ESE_INTERCEPT_SKILLS_CurseStateCallback_Whirlwind)>, "ESE_INTERCEPT_SKILLS_CurseStateCallback_Whirlwind has a different type than previously known.");

extern decltype(&SKILLS_SrvSt38_Whirlwind) SKILLS_SrvSt38_Whirlwind_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt38_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt38_Whirlwind), decltype(&ESE_INTERCEPT_SKILLS_SrvSt38_Whirlwind)>, "ESE_INTERCEPT_SKILLS_SrvSt38_Whirlwind has a different type than previously known.");

extern decltype(&SKILLS_RemoveWhirlwindStats) SKILLS_RemoveWhirlwindStats_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_RemoveWhirlwindStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int32_t a4, int32_t nX, int32_t nY);
static_assert(std::is_same_v<decltype(&SKILLS_RemoveWhirlwindStats), decltype(&ESE_INTERCEPT_SKILLS_RemoveWhirlwindStats)>, "ESE_INTERCEPT_SKILLS_RemoveWhirlwindStats has a different type than previously known.");

extern decltype(&SKILLS_SrvDo076_Whirlwind) SKILLS_SrvDo076_Whirlwind_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo076_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo076_Whirlwind), decltype(&ESE_INTERCEPT_SKILLS_SrvDo076_Whirlwind)>, "ESE_INTERCEPT_SKILLS_SrvDo076_Whirlwind has a different type than previously known.");

extern decltype(&SKILLS_SrvSt39_Berserk) SKILLS_SrvSt39_Berserk_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt39_Berserk(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt39_Berserk), decltype(&ESE_INTERCEPT_SKILLS_SrvSt39_Berserk)>, "ESE_INTERCEPT_SKILLS_SrvSt39_Berserk has a different type than previously known.");

extern decltype(&SKILLS_SrvSt40_Leap) SKILLS_SrvSt40_Leap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt40_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt40_Leap), decltype(&ESE_INTERCEPT_SKILLS_SrvSt40_Leap)>, "ESE_INTERCEPT_SKILLS_SrvSt40_Leap has a different type than previously known.");

extern decltype(&SKILLS_FindLeapTargetPosition) SKILLS_FindLeapTargetPosition_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_FindLeapTargetPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t* pX, int32_t* pY);
static_assert(std::is_same_v<decltype(&SKILLS_FindLeapTargetPosition), decltype(&ESE_INTERCEPT_SKILLS_FindLeapTargetPosition)>, "ESE_INTERCEPT_SKILLS_FindLeapTargetPosition has a different type than previously known.");

extern decltype(&SKILLS_SrvDo077_Leap) SKILLS_SrvDo077_Leap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo077_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo077_Leap), decltype(&ESE_INTERCEPT_SKILLS_SrvDo077_Leap)>, "ESE_INTERCEPT_SKILLS_SrvDo077_Leap has a different type than previously known.");

extern decltype(&SKILLS_SetVelocityForLeap) SKILLS_SetVelocityForLeap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SetVelocityForLeap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);
static_assert(std::is_same_v<decltype(&SKILLS_SetVelocityForLeap), decltype(&ESE_INTERCEPT_SKILLS_SetVelocityForLeap)>, "ESE_INTERCEPT_SKILLS_SetVelocityForLeap has a different type than previously known.");

extern decltype(&SKILLS_Leap) SKILLS_Leap_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);
static_assert(std::is_same_v<decltype(&SKILLS_Leap), decltype(&ESE_INTERCEPT_SKILLS_Leap)>, "ESE_INTERCEPT_SKILLS_Leap has a different type than previously known.");

extern decltype(&SKILLS_SrvSt41_LeapAttack) SKILLS_SrvSt41_LeapAttack_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt41_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvSt41_LeapAttack), decltype(&ESE_INTERCEPT_SKILLS_SrvSt41_LeapAttack)>, "ESE_INTERCEPT_SKILLS_SrvSt41_LeapAttack has a different type than previously known.");

extern decltype(&SKILLS_SrvDo078_LeapAttack) SKILLS_SrvDo078_LeapAttack_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo078_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo078_LeapAttack), decltype(&ESE_INTERCEPT_SKILLS_SrvDo078_LeapAttack)>, "ESE_INTERCEPT_SKILLS_SrvDo078_LeapAttack has a different type than previously known.");

extern decltype(&SKILLS_FindLeapAttackTarget) SKILLS_FindLeapAttackTarget_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindLeapAttackTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);
static_assert(std::is_same_v<decltype(&SKILLS_FindLeapAttackTarget), decltype(&ESE_INTERCEPT_SKILLS_FindLeapAttackTarget)>, "ESE_INTERCEPT_SKILLS_FindLeapAttackTarget has a different type than previously known.");

