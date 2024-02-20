#include <DetoursPatch.h>
#include <chrono>
#include <thread>

#include <GAME/Game.h>

#include "ESEDamageCalc.h"

#include "D2Common/D2Skills_ESE_Intercepts.h"
#include "D2Common/Units/Missile_ESE_Intercepts.h"

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wmicrosoft-cast"
#endif

extern "C"
{
    __declspec(dllexport) constexpr int __cdecl GetBaseOrdinal() { return 0; }
    __declspec(dllexport) constexpr int __cdecl GetLastOrdinal() { return -1; }
    constexpr int GetOrdinalCount() { return GetLastOrdinal() - GetBaseOrdinal() + 1; }

    __declspec(dllexport) PatchAction __cdecl GetPatchAction(int ordinal)
    {
        return PatchAction::Ignore;
    }

    static const int D2CommonImageBase = 0x6FD40000;

    static ExtraPatchAction extraPatchActions[] =
    {
       // Missile
       {0x6FDBA5B0 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_CalculateDamageData, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_CalculateDamageData_Original},
       {0x6FDBAED0 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_AddStatsToDamage, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_AddStatsToDamage_Original},
       {0x6FDBB060 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_CalculateFinalDamage, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_CalculateFinalDamage_Original},
       {0x6FDBB1B0 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_CalculateMasteryBonus, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_CalculateMasteryBonus_Original},
       {0x6FDBB2E0 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_SetDamageStats, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_SetDamageStats_Original},
       {0x6FDBB5A0 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetMinDamage, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetMinDamage_Original},
       {0x6FDBB710 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetMaxDamage, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetMaxDamage_Original},
       {0x6FDBB8C0 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetMinElemDamage, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetMinElemDamage_Original},
       {0x6FDBBA30 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetMaxElemDamage, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetMaxElemDamage_Original},
       {0x6FDBBBA0 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetElementalLength, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetElementalLength_Original},
       {0x6FDBBC50 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetSpecialParamValue, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetSpecialParamValue_Original},
       {0x6FDBC060 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetCalcParamValue, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetCalcParamValue_Original},
       {0x6FDBC080 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetMinimum, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetMinimum_Original},
       {0x6FDBC090 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetMaximum, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetMaximum_Original},
       {0x6FDBC0A0 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetRandomNumberInRange, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetRandomNumberInRange_Original},
       {0x6FDBC120 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_GetSpecialParamValueForSkillMissile, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_GetSpecialParamValueForSkillMissile_Original},
       {0x6FDBC170 - D2CommonImageBase, &ESE_INTERCEPT_MISSILE_EvaluateMissileFormula, PatchAction::FunctionReplaceOriginalByPatch, &MISSILE_EvaluateMissileFormula_Original},
       
       // D2Skills
       {0x6FDAEB60 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_GetSpecialParamValue, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetSpecialParamValue_Original},
       {0x6FDB2280 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_GetManaCosts, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetManaCosts_Original},
       {0x6FDB22E0 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_CalculateDamageBonusByLevel, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_CalculateDamageBonusByLevel_Original},
       {0x6FDB2390 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_GetMinPhysDamage, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetMinPhysDamage_Original},
       {0x6FDB25D0 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_GetMaxPhysDamage, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetMaxPhysDamage_Original},
       {0x6FDB2810 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_GetMinElemDamage, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetMinElemDamage_Original},
       {0x6FDB29D0 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_CalculateMasteryBonus, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_CalculateMasteryBonus_Original},
       {0x6FDB2B00 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_GetMaxElemDamage, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetMaxElemDamage_Original},
       {0x6FDB2CA0 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_GetElementalLength, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetElementalLength_Original},
       {0x6FDB3A90 - D2CommonImageBase, &ESE_INTERCEPT_D2Common_11028, PatchAction::FunctionReplaceOriginalByPatch, &D2Common_11028_Original},
       {0x6FDB3AB0 - D2CommonImageBase, &ESE_INTERCEPT_D2Common_11033, PatchAction::FunctionReplaceOriginalByPatch, &D2Common_11033_Original},
       {0x6FDB41D0 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_GetConcentrationDamageBonus, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetConcentrationDamageBonus_Original},
       {0x6FDB4260 - D2CommonImageBase, &ESE_INTERCEPT_SKILLS_CalculateKickDamage, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_CalculateKickDamage_Original},

        { 0, 0, PatchAction::Ignore}, // Here because we need at least one element in the array
    };

    __declspec(dllexport) constexpr int __cdecl GetExtraPatchActionsCount() { return sizeof(extraPatchActions) / sizeof(ExtraPatchAction); }

    __declspec(dllexport) ExtraPatchAction* __cdecl GetExtraPatchAction(int index)
    {
        return &extraPatchActions[index];
    }
}

#include <type_traits>
static_assert(std::is_same<decltype(GetBaseOrdinal)*, GetIntegerFunctionType>::value, "Ensure calling convention doesn't change");
static_assert(std::is_same<decltype(GetLastOrdinal)*, GetIntegerFunctionType>::value, "Ensure calling convention doesn't change");
static_assert(std::is_same<decltype(GetPatchAction)*, GetPatchActionType>::value, "Ensure calling convention doesn't change");

static_assert(std::is_same<decltype(GetExtraPatchActionsCount)*, GetIntegerFunctionType>::value, "Ensure calling convention doesn't change");
static_assert(std::is_same<decltype(GetExtraPatchAction)*, GetExtraPatchActionType>::value, "Ensure calling convention doesn't change");
