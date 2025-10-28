#include <DetoursPatch.h>
#include <chrono>
#include <thread>

#include <GAME/Game.h>

#include "D2Client/CHARSCREENDMG_ESE_Intercepts.h"
#include "D2Client/UI_Inv_ESE_Intercepts.h"
#include "D2Client/UI_GroundItem_ESE_Intercepts.h"
#include "D2Client/Map_ESE_Intercepts.h"
#include "D2Client/Render_UI_ESE_Intercepts.h"

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
       
       {0x6FB21B70 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_RenderUI_6FB21B70, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_RenderUI_6FB21B70_Original},
       
       {0x6FB26C90 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_Unit_FindRoomContainingSubtile_6FB26C90, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_Unit_FindRoomContainingSubtile_6FB26C90_Original},
       {0x6FAA5E10 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_Light_pActCallbackFunction_6FAA5E10, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_Light_pActCallbackFunction_6FAA5E10_Original},
       
       {0x6FB09F60 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_DrawAllGroundItemTexts_6FB09F60, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_DrawAllGroundItemTexts_6FB09F60_Original},

       {0x6FB20740 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_DrawGroundItemText_sub_6FB20740, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_DrawGroundItemMouseOverText_6FB20A30_Original},
       {0x6FB20A30 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_DrawGroundItemMouseOverText_6FB20A30, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_DrawGroundItemMouseOverText_6FB20A30_Original},
       
       {0x6FAE1890 - D2ClientImageBase, &ESE_INTERCEPT_UI_INV_DrawMouseOverItemFrame_6FAE1890, PatchAction::FunctionReplaceOriginalByPatch, &UI_INV_DrawMouseOverItemFrame_Original},

       {0x6FB0C270 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam1_6FB0C270, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam1_6FB0C270_Original},
       {0x6FB0CD40 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam2_6FB0CD40, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam2_6FB0CD40_Original},
       {0x6FB0D330 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam3_6FB0D330, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam3_6FB0D330_Original},
       {0x6FB0D920 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam4_6FB0D920, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam4_6FB0D920_Original},
       {0x6FB0DEC0 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam5_6FB0DEC0, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam5_6FB0DEC0_Original},
       {0x6FB0ACE0 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam6_6FB0ACE0, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam6_6FB0ACE0_Original},
       {0x6FB0BEC0 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam7_6FB0BEC0, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam7_6FB0BEC0_Original},
       {0x6FB0E800 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam8_6FB0E800, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam8_6FB0E800_Original},
       {0x6FB0EAB0 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam9_6FB0EAB0, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam9_6FB0EAB0_Original},
       {0x6FB0ED40 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam10_6FB0ED40, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam10_6FB0ED40_Original},
       {0x6FB0F080 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam11_6FB0F080, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam11_6FB0F080_Original},
       {0x6FB0F700 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam12_6FB0F700, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam12_6FB0F700_Original},
       {0x6FB0E7B0 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam13_6FB0E7B0, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam13_6FB0E7B0_Original},
       {0x6FB0FA50 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam14_6FB0FA50, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam14_6FB0FA50_Original},
       {0x6FB0FC60 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam15_6FB0FC60, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam15_6FB0FC60_Original},
       {0x6FB10010 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam16_6FB10010, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam16_6FB10010_Original},
       {0x6FB10540 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam17_6FB10540, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam17_6FB10540_Original},
       {0x6FB108F0 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam18_6FB108F0, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam18_6FB108F0_Original},
       {0x6FB0CA60 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam19_6FB0CA60, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam19_6FB0CA60_Original},
       {0x6FB0C930 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam20_6FB0C930, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam20_6FB0C930_Original},
       {0x6FB0CE90 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam21_6FB0CE90, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam21_6FB0CE90_Original},
       {0x6FB0DAB0 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam22_6FB0DAB0, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam22_6FB0DAB0_Original},
       {0x6FB0E440 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam23_6FB0E440, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam23_6FB0E440_Original},
       {0x6FB0E180 - D2ClientImageBase, &ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam24_6FB0E180, PatchAction::FunctionReplaceOriginalByPatch, &D2Client_UI_CHARSCREENDMG_DrawDescDam24_6FB0E180_Original},

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
