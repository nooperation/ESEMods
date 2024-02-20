#include "D2Game/SKILLS/SkillPal_ESE_Intercepts.h"

decltype(&SKILLS_SrvSt29_Sacrifice) SKILLS_SrvSt29_Sacrifice_Original = nullptr;
decltype(&SKILLS_SrvDo064_Sacrifice) SKILLS_SrvDo064_Sacrifice_Original = nullptr;
decltype(&SKILLS_SrvDo150_Smite) SKILLS_SrvDo150_Smite_Original = nullptr;
decltype(&SKILLS_SrvDo065_BasicAura) SKILLS_SrvDo065_BasicAura_Original = nullptr;
decltype(&SKILLS_AuraCallback_BasicAura) SKILLS_AuraCallback_BasicAura_Original = nullptr;
decltype(&SKILLS_CurseStateCallback_BasicAura) SKILLS_CurseStateCallback_BasicAura_Original = nullptr;
decltype(&SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction) SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction_Original = nullptr;
decltype(&SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction) SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction_Original = nullptr;
decltype(&SKILLS_SrvSt31_Charge) SKILLS_SrvSt31_Charge_Original = nullptr;
decltype(&SKILLS_SrvDo067_Charge) SKILLS_SrvDo067_Charge_Original = nullptr;
decltype(&SKILLS_SrvSt35_Vengeance) SKILLS_SrvSt35_Vengeance_Original = nullptr;
decltype(&SKILLS_SrvDo073_BlessedHammer) SKILLS_SrvDo073_BlessedHammer_Original = nullptr;
decltype(&SKILLS_SrvSt36_HolyShield) SKILLS_SrvSt36_HolyShield_Original = nullptr;
decltype(&SKILLS_SrvDo079_Conversion) SKILLS_SrvDo079_Conversion_Original = nullptr;
decltype(&SKILLS_StatRemoveCallback_Conversion) SKILLS_StatRemoveCallback_Conversion_Original = nullptr;
decltype(&SKILLS_SrvDo080_FistOfTheHeavens) SKILLS_SrvDo080_FistOfTheHeavens_Original = nullptr;
decltype(&SKILLS_SrvDo081_HolyFreeze) SKILLS_SrvDo081_HolyFreeze_Original = nullptr;
decltype(&SKILLS_CurseStateCallback_HolyFreeze) SKILLS_CurseStateCallback_HolyFreeze_Original = nullptr;
decltype(&SKILLS_AuraCallback_HolyFreeze) SKILLS_AuraCallback_HolyFreeze_Original = nullptr;
decltype(&SKILLS_ApplyRedemptionEffect) SKILLS_ApplyRedemptionEffect_Original = nullptr;
decltype(&SKILLS_SrvDo082_Redemption) SKILLS_SrvDo082_Redemption_Original = nullptr;
decltype(&SKILLS_AuraCallback_Redemption) SKILLS_AuraCallback_Redemption_Original = nullptr;
decltype(&SKILLS_ApplyThornsDamage) SKILLS_ApplyThornsDamage_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt29_Sacrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt29_Sacrifice(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo064_Sacrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo064_Sacrifice(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo150_Smite(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo150_Smite(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo065_BasicAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo065_BasicAura(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_AuraCallback_BasicAura(pAuraCallback, pUnit);
}

void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_BasicAura(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_SKILLS_CurseStateCallback_BasicAura(pUnit, nState, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt31_Charge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt31_Charge(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo067_Charge(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo067_Charge(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt35_Vengeance(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt35_Vengeance(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo073_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo073_BlessedHammer(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt36_HolyShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt36_HolyShield(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo079_Conversion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo079_Conversion(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_StatRemoveCallback_Conversion(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_SKILLS_StatRemoveCallback_Conversion(pUnit, nState, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo080_FistOfTheHeavens(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo080_FistOfTheHeavens(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo081_HolyFreeze(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo081_HolyFreeze(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_HolyFreeze(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_SKILLS_CurseStateCallback_HolyFreeze(pUnit, nState, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_HolyFreeze(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_AuraCallback_HolyFreeze(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_ApplyRedemptionEffect(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int32_t nSkillId, int32_t nSkillLevel, int32_t bSkipChanceRoll)
{
    return ESE_SKILLS_ApplyRedemptionEffect(pGame, pUnit, pCorpse, nSkillId, nSkillLevel, bSkipChanceRoll);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo082_Redemption(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo082_Redemption(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_AuraCallback_Redemption(pAuraCallback, pUnit);
}

void __fastcall ESE_INTERCEPT_SKILLS_ApplyThornsDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    ESE_SKILLS_ApplyThornsDamage(pGame, pAttacker, pDefender, pDamage);
}


