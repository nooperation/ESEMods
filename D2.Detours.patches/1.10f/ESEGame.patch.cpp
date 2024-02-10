#include <DetoursPatch.h>
#include <chrono>
#include <thread>

#include <GAME/Game.h>
#include "ESEGame.h"

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

    //void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, uint8_t nSrcDam)
   //void __fastcall SUNITDMG_ApplyResistancesAndAbsorb(D2DamageInfoStrc* pDamageInfo, const D2DamageStatTableStrc* pDamageStatTableRecord, int32_t bDontAbsorb);
    static ExtraPatchAction extraPatchActions[] =
    {
         //{ 0x6FC63FD0 - D2GameImageBase, &sub_6FC63FD0_ESEGame, PatchAction::FunctionReplaceOriginalByPatch, &sub_6FC63FD0_Original},
         //{ 0x6FCC2420 - D2GameImageBase, &SUNITDMG_AllocCombat_ESEGame, PatchAction::FunctionReplaceOriginalByPatch, &SUNITDMG_AllocCombat_Original},
         { 0x6FCBFB40 - D2GameImageBase, &SUNITDMG_ApplyResistancesAndAbsorb_ESEGame, PatchAction::FunctionReplaceOriginalByPatch, &SUNITDMG_ApplyResistancesAndAbsorb_Original},
         { 0x6FC6AF70 - D2GameImageBase, &MONSTERUNIQUE_CalculatePercentage_ESEGame, PatchAction::FunctionReplaceOriginalByPatch, &MONSTERUNIQUE_CalculatePercentage_Original},
         { 0x6FCBFE90 - D2GameImageBase, &SUNITDMG_ExecuteEvents_ESEGame, PatchAction::FunctionReplaceOriginalByPatch, &SUNITDMG_ExecuteEvents_Original},
         { 0x6FCBF620 - D2GameImageBase, &SUNITDMG_CalculateTotalDamage_ESEGame, PatchAction::FunctionReplaceOriginalByPatch, &SUNITDMG_CalculateTotalDamage_Original},
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
