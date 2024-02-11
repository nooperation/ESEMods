#include <DetoursPatch.h>
#include <chrono>
#include <thread>

#include <GAME/Game.h>
#include <D2Skills.h>

#include "ESEDamageCalc.h"

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

    static const int D2GameImageBase = 0x6FC30000;
    static const int D2CommonImageBase = 0x6FD40000;

    static ExtraPatchAction extraPatchActions[] =
    {
         { 0x6FDB25D0 - D2CommonImageBase, &SKILLS_GetMaxPhysDamage_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetMaxPhysDamage_Original},
         { 0x6FDB2390 - D2CommonImageBase, &SKILLS_GetMinPhysDamage_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetMinPhysDamage_Original},
         { 0x6FDB2810 - D2CommonImageBase, &SKILLS_GetMinElemDamage_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetMinElemDamage_Original},
         { 0x6FDB2B00 - D2CommonImageBase, &SKILLS_GetMaxElemDamage_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &SKILLS_GetMaxElemDamage_Original},
        
         { 0x6FD14EC0 - D2GameImageBase, &D2GAME_RollPhysicalDamage_6FD14EC0_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &D2GAME_RollPhysicalDamage_6FD14EC0_Original},
         { 0x6FD14DD0 - D2GameImageBase, &D2GAME_RollElementalDamage_6FD14DD0_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &D2GAME_RollElementalDamage_6FD14DD0_Original},
         { 0x6FCBE420 - D2GameImageBase, &SUNITDMG_ApplyDamageBonuses_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &SUNITDMG_ApplyDamageBonuses_Original},
         { 0x6FCBF450 - D2GameImageBase, &SUNITDMG_RollDamageValueInRange_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &SUNITDMG_RollDamageValueInRange_Original},
         { 0x6FC56290 - D2GameImageBase, &MISSMODE_RollDamageValue_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &MISSMODE_RollDamageValue_Original},
         { 0x6FCC2420 - D2GameImageBase, &SUNITDMG_AllocCombat_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &SUNITDMG_AllocCombat_Original},
         { 0x6FC6AF70 - D2GameImageBase, &MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &MONSTERUNIQUE_CalculatePercentage_Original},
         { 0x6FCBFE90 - D2GameImageBase, &SUNITDMG_ExecuteEvents_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &SUNITDMG_ExecuteEvents_Original},
         { 0x6FCBF620 - D2GameImageBase, &SUNITDMG_CalculateTotalDamage_ESEDamageCalc, PatchAction::FunctionReplaceOriginalByPatch, &SUNITDMG_CalculateTotalDamage_Original},
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

decltype(&MONSTERUNIQUE_CalculatePercentage) MONSTERUNIQUE_CalculatePercentage_Original = nullptr;
decltype(&SUNITDMG_AllocCombat) SUNITDMG_AllocCombat_Original = nullptr;
decltype(&SUNITDMG_CalculateTotalDamage) SUNITDMG_CalculateTotalDamage_Original = nullptr;
decltype(&SUNITDMG_ExecuteEvents) SUNITDMG_ExecuteEvents_Original = nullptr;
decltype(&MISSMODE_RollDamageValue) MISSMODE_RollDamageValue_Original = nullptr;
decltype(&SUNITDMG_RollDamageValueInRange) SUNITDMG_RollDamageValueInRange_Original = nullptr;
decltype(&SUNITDMG_ApplyDamageBonuses) SUNITDMG_ApplyDamageBonuses_Original = nullptr;
decltype(&D2GAME_RollElementalDamage_6FD14DD0) D2GAME_RollElementalDamage_6FD14DD0_Original = nullptr;
decltype(&D2GAME_RollPhysicalDamage_6FD14EC0) D2GAME_RollPhysicalDamage_6FD14EC0_Original = nullptr;

decltype(&SKILLS_GetMinElemDamage) SKILLS_GetMinElemDamage_Original = nullptr;
decltype(&SKILLS_GetMaxElemDamage) SKILLS_GetMaxElemDamage_Original = nullptr;
decltype(&SKILLS_GetMaxPhysDamage) SKILLS_GetMaxPhysDamage_Original = nullptr;
decltype(&SKILLS_GetMinPhysDamage) SKILLS_GetMinPhysDamage_Original = nullptr;
