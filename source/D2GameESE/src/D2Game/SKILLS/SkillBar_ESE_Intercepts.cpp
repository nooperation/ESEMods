#include "D2Game/SKILLS/SkillBar_ESE_Intercepts.h"

SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite_t SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite_Original = nullptr;
SKILLS_SrvSt33_FindPotion_GrimWard_t SKILLS_SrvSt33_FindPotion_GrimWard_Original = nullptr;
SKILLS_SrvDo069_FindPotion_t SKILLS_SrvDo069_FindPotion_Original = nullptr;
SKILLS_ApplyWarcryStats_t SKILLS_ApplyWarcryStats_Original = nullptr;
SKILLS_SrvDo068_BasicShout_t SKILLS_SrvDo068_BasicShout_Original = nullptr;
SKILLS_SrvDo070_DoubleSwing_t SKILLS_SrvDo070_DoubleSwing_Original = nullptr;
SKILLS_Callback_FindTargetForTaunt_t SKILLS_Callback_FindTargetForTaunt_Original = nullptr;
SKILLS_SrvDo071_Taunt_t SKILLS_SrvDo071_Taunt_Original = nullptr;
SKILLS_SrvSt34_FindItem_t SKILLS_SrvSt34_FindItem_Original = nullptr;
SKILLS_SrvDo072_FindItem_t SKILLS_SrvDo072_FindItem_Original = nullptr;
SKILLS_SrvDo074_DoubleThrow_t SKILLS_SrvDo074_DoubleThrow_Original = nullptr;
SKILLS_SrvDo075_GrimWard_t SKILLS_SrvDo075_GrimWard_Original = nullptr;
SKILLS_RollFrenzyDamage_t SKILLS_RollFrenzyDamage_Original = nullptr;
SKILLS_ApplyFrenzyStats_t SKILLS_ApplyFrenzyStats_Original = nullptr;
SKILLS_SrvDo009_Frenzy_t SKILLS_SrvDo009_Frenzy_Original = nullptr;
SKILLS_CurseStateCallback_Whirlwind_t SKILLS_CurseStateCallback_Whirlwind_Original = nullptr;
SKILLS_SrvSt38_Whirlwind_t SKILLS_SrvSt38_Whirlwind_Original = nullptr;
SKILLS_RemoveWhirlwindStats_t SKILLS_RemoveWhirlwindStats_Original = nullptr;
SKILLS_SrvDo076_Whirlwind_t SKILLS_SrvDo076_Whirlwind_Original = nullptr;
SKILLS_SrvSt39_Berserk_t SKILLS_SrvSt39_Berserk_Original = nullptr;
SKILLS_SrvSt40_Leap_t SKILLS_SrvSt40_Leap_Original = nullptr;
SKILLS_FindLeapTargetPosition_t SKILLS_FindLeapTargetPosition_Original = nullptr;
SKILLS_SrvDo077_Leap_t SKILLS_SrvDo077_Leap_Original = nullptr;
SKILLS_SetVelocityForLeap_t SKILLS_SetVelocityForLeap_Original = nullptr;
SKILLS_Leap_t SKILLS_Leap_Original = nullptr;
SKILLS_SrvSt41_LeapAttack_t SKILLS_SrvSt41_LeapAttack_Original = nullptr;
SKILLS_SrvDo078_LeapAttack_t SKILLS_SrvDo078_LeapAttack_Original = nullptr;
SKILLS_FindLeapAttackTarget_t SKILLS_FindLeapAttackTarget_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt33_FindPotion_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt33_FindPotion_GrimWard(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo069_FindPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo069_FindPotion(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_ApplyWarcryStats(pGame, a2, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo068_BasicShout(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo068_BasicShout(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo070_DoubleSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo070_DoubleSwing(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_Callback_FindTargetForTaunt(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo071_Taunt(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo071_Taunt(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt34_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt34_FindItem(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo072_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo072_FindItem(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo074_DoubleThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo074_DoubleThrow(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo075_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo075_GrimWard(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_RollFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_RollFrenzyDamage(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_ApplyFrenzyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_SKILLS_ApplyFrenzyStats(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo009_Frenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo009_Frenzy(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_Whirlwind(D2UnitStrc* pUnit, int32_t nState, struct D2StatListStrc* pStatList)
{
    ESE_SKILLS_CurseStateCallback_Whirlwind(pUnit, nState, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt38_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt38_Whirlwind(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_RemoveWhirlwindStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int32_t a4, int32_t nX, int32_t nY)
{
    return ESE_SKILLS_RemoveWhirlwindStats(pGame, pUnit, pSkill, a4, nX, nY);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo076_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo076_Whirlwind(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt39_Berserk(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt39_Berserk(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt40_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt40_Leap(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_FindLeapTargetPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t* pX, int32_t* pY)
{
    return ESE_SKILLS_FindLeapTargetPosition(pUnit, nSkillId, nSkillLevel, pX, pY);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo077_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo077_Leap(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SetVelocityForLeap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    return ESE_SKILLS_SetVelocityForLeap(pGame, pUnit, pSkill);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    return ESE_SKILLS_Leap(pGame, pUnit, pSkill);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt41_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt41_LeapAttack(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo078_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo078_LeapAttack(pGame, pUnit, nSkillId, nSkillLevel);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindLeapAttackTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    return ESE_SKILLS_FindLeapAttackTarget(pGame, pUnit, pSkill);
}


