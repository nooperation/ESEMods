#include <DetoursPatch.h>
#include <chrono>
#include <thread>

#include <GAME/Game.h>

#include "D2Client/CHARSCREENDMG_ESE_Intercepts.h"
#include "D2Client/UI_Inv_ESE_Intercepts.h"

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
       {0x6FAE1890 - D2ClientImageBase, &ESE_INTERCEPT_UI_INV_DrawMouseOverItemFrame, PatchAction::FunctionReplaceOriginalByPatch, &UI_INV_DrawMouseOverItemFrame_Original},

       {0x6FB0C270 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam1, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam1_Original},
       {0x6FB0CD40 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam2, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam2_Original},
       {0x6FB0D330 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam3, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam3_Original},
       {0x6FB0D920 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam4, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam4_Original},
       {0x6FB0DEC0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam5, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam5_Original},
       {0x6FB0ACE0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam6, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam6_Original},
       {0x6FB0BEC0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam7, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam7_Original},
       {0x6FB0E800 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam8, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam8_Original},
       {0x6FB0EAB0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam9, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam9_Original},
       {0x6FB0ED40 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam10, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam10_Original},
       {0x6FB0F080 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam11, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam11_Original},
       {0x6FB0F700 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam12, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam12_Original},
       {0x6FB0E7B0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam13, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam13_Original},
       {0x6FB0FA50 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam14, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam14_Original},
       {0x6FB0FC60 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam15, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam15_Original},
       {0x6FB10010 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam16, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam16_Original},
       {0x6FB10540 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam17, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam17_Original},
       {0x6FB108F0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam18, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam18_Original},
       {0x6FB0CA60 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam19, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam19_Original},
       {0x6FB0C930 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam20, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam20_Original},
       {0x6FB0CE90 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam21, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam21_Original},
       {0x6FB0DAB0 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam22, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam22_Original},
       {0x6FB0E440 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam23, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam23_Original},
       {0x6FB0E180 - D2ClientImageBase, &ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam24, PatchAction::FunctionReplaceOriginalByPatch, &CHARSCREENDMG_DrawDescDam24_Original},

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
