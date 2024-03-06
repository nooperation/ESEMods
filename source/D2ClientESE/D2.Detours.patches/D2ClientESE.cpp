#include <DetoursPatch.h>
#include <chrono>
#include <thread>

#include <GAME/Game.h>

#include "D2Client/CharScreen_ESE_Intercepts.h"

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

    static const int D2ClientImageBase = 0x6FAA0000;

    static ExtraPatchAction extraPatchActions[] =
    {
       {0x6FB0C270 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam1, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam1_Original},
       {0x6FB0CD40 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam2, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam2_Original},
       {0x6FB0D330 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam3, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam3_Original},
       {0x6FB0D920 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam4, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam4_Original},
       {0x6FB0DEC0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam5, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam5_Original},
       {0x6FB0ACE0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam6, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam6_Original},
       {0x6FB0BEC0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam7, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam7_Original},
       {0x6FB0E800 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam8, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam8_Original},
       {0x6FB0EAB0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam9, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam9_Original},
       {0x6FB0ED40 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam10, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam10_Original},
       {0x6FB0F080 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam11, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam11_Original},
       {0x6FB0F700 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam12, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam12_Original},
       {0x6FB0E7B0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam13, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam13_Original},
       {0x6FB0FA50 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam14, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam14_Original},
       {0x6FB0FC60 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam15, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam15_Original},
       {0x6FB10010 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam16, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam16_Original},
       {0x6FB10540 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam17, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam17_Original},
       {0x6FB108F0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam18, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam18_Original},
       {0x6FB0CA60 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam19, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam19_Original},
       {0x6FB0C930 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam20, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam20_Original},
       {0x6FB0CE90 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam21, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam21_Original},
       {0x6FB0DAB0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam22, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam22_Original},
       {0x6FB0E440 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam23, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam23_Original},
       {0x6FB0E180 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREEN_DrawDescDam24, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREEN_DrawDescDam24_Original},

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
