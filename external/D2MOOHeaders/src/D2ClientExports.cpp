#include "../D2ClientExports.h"
#include "D2Roster.h"
#include "DataTbls/MonsterTbls.h"

D2Client_DrawTextCentered_6FACFCD0_t D2Client_DrawTextCentered_6FACFCD0 = nullptr;
D2Client_sub_6FB0B2C0_t D2Client_sub_6FB0B2C0 = nullptr;
D2Client_sub_6FB0B6F0_t D2Client_sub_6FB0B6F0 = nullptr;
D2Client_sub_6FB0BB10_t D2Client_sub_6FB0BB10 = nullptr;

D2Client_sub_6FB0A950_t D2Client_sub_6FB0A950 = nullptr;
D2Client_sub_6FB0AA00_t D2Client_sub_6FB0AA00 = nullptr;
D2Client_sub_6FB0B580_t D2Client_sub_6FB0B580 = nullptr;
D2Client_IsLod_6FAAC080_t D2Client_IsLod_6FAAC080 = nullptr;

// UI-INV stuff
D2Client_GetCurrentPlayer_6FB283D0_t D2Client_GetCurrentPlayer_6FB283D0 = nullptr; // 883D0
D2Client_IsBeltOpen_6FAFE9E0_t D2Client_IsBeltOpen_6FAFE9E0 = nullptr; // 5E9E0
D2Client_IsUiOpen_6FB23230_t D2Client_IsUiOpen_6FB23230 = nullptr; // 83230
D2Client_GetMouseXPos_t D2Client_GetMouseXPos = nullptr; // B7BC0
D2Client_GetMouseYPos_t D2Client_GetMouseYPos = nullptr; // B7BD0
D2Client_sub_6FAFC0E0_t D2Client_sub_6FAFC0E0 = nullptr; // 5C0E0
D2Client_GetHotkeyCharCode_6FAD4B60_t D2Client_GetHotkeyCharCode_6FAD4B60 = nullptr; // 34B60
D2Client_GetHotkeyString_6FAD56B0_t D2Client_GetHotkeyString_6FAD56B0 = nullptr; // 356B0
D2Client_IsGambling_6FAFC130_t D2Client_IsGambling_6FAFC130 = nullptr; // 5C130
D2Client_ColorizeLine_6FB20430_t D2Client_ColorizeLine_6FB20430 = nullptr; // 80430
D2Client_AddExtraTradeStatLines_6FAE5A40_t D2Client_AddExtraTradeStatLines_6FAE5A40 = nullptr; // 45A40
D2Client_BuildItemName_6FADD360_t D2Client_BuildItemName_6FADD360 = nullptr; // 3D360
D2Client_sub_6FB57CC0_t D2Client_sub_6FB57CC0 = nullptr; // B7CC0
D2Client_GetItemTextLineBookQuantity_6FAE54B0_t D2Client_GetItemTextLineBookQuantity_6FAE54B0 = nullptr; // 454B0
D2Client_GetItemTextLineDurability_6FAE4060_t D2Client_GetItemTextLineDurability_6FAE4060 = nullptr; // 44060
D2Client_GetItemTextLineRuneGemStats_6FAF1480_t D2Client_GetItemTextLineRuneGemStats_6FAF1480 = nullptr; // 51480
D2Client_GetItemTextLineDamage_6FAE43D0_t D2Client_GetItemTextLineDamage_6FAE43D0 = nullptr; // 443D0
D2Client_GetItemTextLineAttackSpeed_6FAE5570_t D2Client_GetItemTextLineAttackSpeed_6FAE5570 = nullptr; // 45570
D2Client_GetItemTextLineUnknownA_6FAE5040_t D2Client_GetItemTextLineUnknownA_6FAE5040 = nullptr; // 45040
D2Client_GetItemTextLineBlockChance_6FAE4EE0_t D2Client_GetItemTextLineBlockChance_6FAE4EE0 = nullptr; // 44EE0
D2Client_GetItemTextLineDefense_6FAE51D0_t D2Client_GetItemTextLineDefense_6FAE51D0 = nullptr; // 451D0
D2Client_GetItemTextLineProperties_6FAF3160_t D2Client_GetItemTextLineProperties_6FAF3160 = nullptr; // 53160
D2Client_GetItemTextLinePropertiesInternal_6FAF19C0_t D2Client_GetItemTextLinePropertiesInternal_6FAF19C0 = nullptr; // 519C0
D2Client_GetItemTextLineQuantity_6FAE5710_t D2Client_GetItemTextLineQuantity_6FAE5710 = nullptr; // 45710
D2Client_sub_6FAE5C50_t D2Client_sub_6FAE5C50 = nullptr; // 45C50
D2Client_GetSetItemsTxt_6FAE5C80_t D2Client_GetSetItemsTxt_6FAE5C80 = nullptr; // 45C80
D2Client_GetItemTextLineLevelRequirement_6FAE41B0_t D2Client_GetItemTextLineLevelRequirement_6FAE41B0 = nullptr; // 441B0
D2Client_GetItemTextStrRequirement_6FAE4250_t D2Client_GetItemTextStrRequirement_6FAE4250 = nullptr; // 44250
D2Client_GetItemTextDexRequirement_6FAE4310_t D2Client_GetItemTextDexRequirement_6FAE4310 = nullptr; // 44310
D2Client_GetItemTextSocketed_6FAE3EE0_t D2Client_GetItemTextSocketed_6FAE3EE0 = nullptr; // 43EE0
D2Client_GetItemTextSet_6FAF32B0_t D2Client_GetItemTextSet_6FAF32B0 = nullptr; // 532B0
D2Client_GetItemTextSetB_6FAF33C0_t D2Client_GetItemTextSetB_6FAF33C0 = nullptr; // 533C0
D2Client_FormatName_6FADCFE0_t D2Client_FormatName_6FADCFE0 = nullptr; // 3CFE0
D2Client_ReplaceNameFormatToken_6FADCF10_t D2Client_ReplaceNameFormatToken_6FADCF10 = nullptr; // 3CF10
D2Client_sub_6FAE5990_t D2Client_sub_6FAE5990 = nullptr; // 45990
D2Client_GetItemTextLinePrice_6FAFB200_t D2Client_GetItemTextLinePrice_6FAFB200 = nullptr; // 5B200
D2Client_GetItemDamage_6FAE4C60_t D2Client_GetItemDamage_6FAE4C60 = nullptr; // 44C60
D2Client_sub_6FAF13C0_t D2Client_sub_6FAF13C0 = nullptr; // 513C0

D2Client_FindUnit_6FB269F0_t D2Client_FindUnit_6FB269F0 = nullptr; // 869F0
D2Client_GetCurrentDifficulty_6FAAC090_t D2Client_GetCurrentDifficulty_6FAAC090 = nullptr; // C090
D2Client_IsVendorRepairActive_6FAEB930_t D2Client_IsVendorRepairActive_6FAEB930 = nullptr; // 4B930

// UI-INV-MOD stuff
D2Client_GetSkillStringId_6FB0A440_t D2Client_GetSkillStringId_6FB0A440 = nullptr; //6A440
D2Client_GetItemTextLineDamageToUndead_6FAF12C0_t D2Client_GetItemTextLineDamageToUndead_6FAF12C0 = nullptr; //512C0
D2Client_sub_6FAF3460_t D2Client_sub_6FAF3460 = nullptr; //53460
D2Client_GetItemPropertyLine_6FAF21C0_t D2Client_GetItemPropertyLine_6FAF21C0 = nullptr; //521C0

// UI_GroundItem functions
D2Client_GetOpenUiPanelMask_6FAB5750_t D2Client_GetOpenUiPanelMask_6FAB5750 = nullptr; // 15750
D2Client_GetViewXOffset_6FAB5890_t D2Client_GetViewXOffset_6FAB5890 = nullptr; // 15890
D2Client_GetViewYOffset_6FAB58A0_t D2Client_GetViewYOffset_6FAB58A0 = nullptr; // 158A0
D2Client_GetMonsterLifeColor_6FB20670_t D2Client_GetMonsterLifeColor_6FB20670 = nullptr; // 80670
D2Client_GetUnitName_6FB297F0_t D2Client_GetUnitName_6FB297F0 = nullptr; // 897F0
D2Client_GetRosterPlayerNameAndColor_6FB21680_t D2Client_GetRosterPlayerNameAndColor_6FB21680 = nullptr; // 81680
D2Client_GetRosterPortalOwnerName_6FAB0D00_t D2Client_GetRosterPortalOwnerName_6FAB0D00 = nullptr; // 10D00
D2Client_GetRosterPetOwnerId_6FAB1B00_t D2Client_GetRosterPetOwnerId_6FAB1B00 = nullptr; // 11B00
D2Client_GetRosterUnitName_6FAB0BC0_t D2Client_GetRosterUnitName_6FAB0BC0 = nullptr; // 10BC0
D2Client_GetRosterUnitLife_6FAB1460_t D2Client_GetRosterUnitLife_6FAB1460 = nullptr; // 11460
D2Client_GetRosterUnitRosterInfo_6FAB0D80_t D2Client_GetRosterUnitRosterInfo_6FAB0D80 = nullptr; // 10D80
D2Client_CheckPartyMemberFlags_6FB4B900_t D2Client_CheckPartyMemberFlags_6FB4B900 = nullptr; // AB900
D2Client_AreUnitsHostile_6FAB07D0_t D2Client_AreUnitsHostile_6FAB07D0 = nullptr; // 107D0
D2Client_GetMonStats2TxtFromClassId_6FB247F0_t D2Client_GetMonStats2TxtFromClassId_6FB247F0 = nullptr; // 847F0
D2Client_GetMonStatsTxtFromClassId_6FAAE570_t D2Client_GetMonStatsTxtFromClassId_6FAAE570 = nullptr; // E570 
D2Client_GetObjectOwnerName_6FB48550_t D2Client_GetObjectOwnerName_6FB48550 = nullptr; // A8550
D2Client_CheckMonsterTypeFlag_6FB449D0_t D2Client_CheckMonsterTypeFlag_6FB449D0 = nullptr; // A49D0
D2Client_IsMonsterUnique_6FB40D00_t D2Client_IsMonsterUnique_6FB40D00 = nullptr; // A0D00
D2Client_IsMonsterChampion_6FB40CC0_t D2Client_IsMonsterChampion_6FB40CC0 = nullptr; // A0CC0
D2Client_IsMonsterGhostly_6FB40CE0_t D2Client_IsMonsterGhostly_6FB40CE0 = nullptr; // A0CE0
D2Client_IsMonsterMinion_6FB40D20_t D2Client_IsMonsterMinion_6FB40D20 = nullptr; // A0D20
D2Client_IsMonsterSuperUnique_6FB40D40_t D2Client_IsMonsterSuperUnique_6FB40D40 = nullptr; // A0D40
D2Client_GetScreenOffsetDimensionsTBD_6FB24690_t D2Client_GetScreenOffsetDimensionsTBD_6FB24690 = nullptr; // 84690
D2Client_UpdateUniqueMonsterInfoString_6FB20600_t D2Client_UpdateUniqueMonsterInfoString_6FB20600 = nullptr; // 80600
D2Client_UpdateNormalMonsterInfoString_6FB205D0_t D2Client_UpdateNormalMonsterInfoString_6FB205D0 = nullptr; // 805D0
D2Client_MonsterResistancesInfoString_6FB21570_t D2Client_MonsterResistancesInfoString_6FB21570 = nullptr; // 81570
D2Client_IsActiveNpcDialogOpen_6FAFBB50_t D2Client_IsActiveNpcDialogOpen_6FAFBB50 = nullptr; // 5BB50
D2Client_IsActiveNpcTalking_6FB1EE90_t D2Client_IsActiveNpcTalking_6FB1EE90 = nullptr; // 7EE90
D2Client_10002_t D2Client_10002 = nullptr; // 18EF0
D2Client_GetSelectedUnit_6FAB5A20_t D2Client_GetSelectedUnit_6FAB5A20 = nullptr; // 15A20
D2Client_sub_6FB09D80_t D2Client_sub_6FB09D80 = nullptr; // 69D80
D2Client_sub_6FAB5A90_t D2Client_sub_6FAB5A90 = nullptr; // 15A90
D2Client_ClearUnitSelection_6FAB5D40_t D2Client_ClearUnitSelection_6FAB5D40 = nullptr; // 15D40


int32_t* D2Client_pScreenXOffset_6FBBA748 = nullptr;
int32_t* D2Client_pScreenYOffset_6FBBA74C = nullptr;
int32_t* D2Client_pScreenWidthUI_6FB740EC = nullptr;
int32_t* D2Client_pScreenHeightUI_6FB740F0 = nullptr;
int32_t* D2Client_pDWORD_6FB8CCF8 = nullptr;

int32_t* D2Client_pIsItemUnderCursorInInventory_6FBB58E0 = nullptr;
int32_t* D2Client_pIsItemUnderCursorEquipped_6FBB58E4 = nullptr;
D2C_VendorInventoryModes* D2Client_pVendorMode_6FBB58EC = nullptr;
int32_t* D2Client_pDWORD_6FB7928C = nullptr;
int32_t* D2Client_pItemUnderCursorPosXb_6FB79290 = nullptr;
int32_t* D2Client_pItemUnderCursorPosYb_6FB79294 = nullptr;
int32_t* D2Client_pItemUnderCursorPosX_6FB79298 = nullptr;
int32_t* D2Client_pItemUnderCursorPosY_6FB7929C = nullptr;

int32_t* D2Client_pLeftSwapWeaponButtonXLeft_6FBB59A8 = nullptr;
int32_t* D2Client_pLeftSwapWeaponButtonXRight_6FBB59AC = nullptr;
int32_t* D2Client_pLeftSwapWeaponButtonYTop_6FBB59B0 = nullptr;
int32_t* D2Client_pRightSwapWeaponButtonXLeft_6FBB59BC = nullptr;
int32_t* D2Client_pRightSwapWeaponButtonXRight_6FBB59C0 = nullptr;
int32_t* D2Client_pRightSwapWeaponButtonYTop_6FBB59C4 = nullptr;

D2UnitStrc** D2Client_pItemUnderCursor_6FBB58F0 = nullptr; // 1158F0

GroundItemText* D2Client_pGroundItemsToShow_6FBB7028 = nullptr; // 117028
int32_t* D2Client_pNumGroundItemsToShow_6FBB9428 = nullptr; // 119428
int32_t* D2Client_pSelectedUnitId_6FBAB9D0 = nullptr; // 10B9D0
int32_t* D2Client_pSelectedUnitType_6FBAB9CC = nullptr; // 10B9CC
int32_t* D2Client_pSelectedUnitIsSelected_6FBAB9E8 = nullptr; // 10B9E8
int32_t* D2Client_pIsUnitSelectionDisabled_6FBAB9EC = nullptr; // 10B9EC


// UI-INV-MOD stuff

int32_t* D2Client_pDWORD_6FB7A438 = nullptr; // DA438
int32_t* D2Client_pDWORD_6FB79B48 = nullptr; // D9B48
int32_t* D2Client_pElixirDescCount_6FB7A4A0 = nullptr; // DA4A0
ElixirDesc_6FB7A440* D2Client_pElixirDescs_6FB7A440 = nullptr; // DA440
D2DrlgActStrc** D2Client_pCurrentDrlgAct_6FBA7984 = nullptr; // 6A440
uint16_t* D2Client_pWORD_6FB6FA30 = nullptr; // CFA30

int32_t* D2Client_pWeaponSpeedStringIndexLookupTable_6FB79360 = nullptr; // D9360
int32_t* D2Client_pDWORD_6FB794C8 = nullptr; // D94C8
IdToStringIndexPair* D2Client_pAttackSpeedStringIndices_6FB79334 = nullptr; // D9334
IdToStringIndexPair* D2Client_pWeaponClassStringIndices_6FB792D8 = nullptr; // D92D8
const char* D2Client_pUnknownStr_6FB9A828 = nullptr; // FA828

D2BitBufferStrc** D2Client_pQuestFlags_6FBB5D13 = nullptr; // 115D13
int32_t* D2Client_pIsNpcDialogOpen_6FBB5CF9 = nullptr; // 115CF9
int32_t* D2Client_pActiveNpcId_6FBB5CF5 = nullptr; // 115CF5
int32_t* D2Client_pIsGamblingSession_6FBB5D7C = nullptr; // 115D7C
D2UnitStrc** D2Client_pGameUnits_6FBBAA00 = nullptr; // 11AA00

// UI_GroundItem variables 
int32_t* D2Client_pGameType_6FBA7960 = nullptr; // 107960
int16_t* D2Client_pJoinId_6FBA7748 = nullptr; // 107748
char* D2Client_pServerIp_6FB75468 = nullptr; // D5468
char* D2Client_pGameName_6FBA7898 = nullptr; // 107898
int32_t* D2Client_pUnitMouseOverTextPosX_6FB8EA28 = nullptr; // EEA28
int32_t* D2Client_pUnitMouseOverTextPosY_6FB8EA2C = nullptr; // EEA2C
int32_t* D2Client_pOpenUIPanelMask_6FBAB9C4 = nullptr; // 10B9C4  
int32_t* D2Client_pViewYOffset_6FBAB9B8 = nullptr; // 10B9B8
int32_t* D2Client_pViewXOffset_6FBAB9BC = nullptr; // 10B9BC
int32_t* D2Client_pViewXOffsetUnits_6FBAB9C8 = nullptr; // 10B9C8 
D2RosterPetStrc* D2Client_pRosterPetRoot_6FBAB9A0 = nullptr; // 10B9A0
D2RosterUnitStrc* D2Client_pRosterUnitRoot_6FBAB994 = nullptr; // 10B994
int32_t* D2Client_pShowAllGroundItemTexts_6FBBA6DC = nullptr; // 11A6DC
wchar_t** D2Client_pNormalMonsterInfoString_6FBB9FE0 = nullptr; // 119FE0
wchar_t** D2Client_pMonsterImmunitiesInfoString_6FBBA4A0 = nullptr; // 11A4A0
wchar_t** D2Client_pUniqueMonsterInfoString_6FBBA2A0 = nullptr; // 11A2A0
int32_t* D2Client_UIStates_6FBBA6A8 = nullptr; // 11A6A8

void InitD2ClientExports()
{
    auto d2ClientModule = GetModuleHandle("D2Client");

    D2Client_DrawTextCentered_6FACFCD0 = (D2Client_DrawTextCentered_6FACFCD0_t)((char*)d2ClientModule + 0x2FCD0);
    D2Client_sub_6FB0B2C0 = (D2Client_sub_6FB0B2C0_t)((char*)d2ClientModule + 0x6B2C0);
    D2Client_sub_6FB0B6F0 = (D2Client_sub_6FB0B6F0_t)((char*)d2ClientModule + 0x6B6F0);
    D2Client_sub_6FB0BB10 = (D2Client_sub_6FB0BB10_t)((char*)d2ClientModule + 0x6BB10);

    D2Client_sub_6FB0A950 = (D2Client_sub_6FB0A950_t)((char*)d2ClientModule + 0x6A950);
    D2Client_sub_6FB0AA00 = (D2Client_sub_6FB0AA00_t)((char*)d2ClientModule + 0x6AA00);
    D2Client_sub_6FB0B580 = (D2Client_sub_6FB0B580_t)((char*)d2ClientModule + 0x6B580);
    D2Client_IsLod_6FAAC080 = (D2Client_IsLod_6FAAC080_t)((char*)d2ClientModule + 0xC080);

    D2Client_GetCurrentPlayer_6FB283D0 = (D2Client_GetCurrentPlayer_6FB283D0_t)((char*)d2ClientModule + 0x883D0);
    D2Client_IsBeltOpen_6FAFE9E0 = (D2Client_IsBeltOpen_6FAFE9E0_t)((char*)d2ClientModule + 0x5E9E0);
    D2Client_IsUiOpen_6FB23230 = (D2Client_IsUiOpen_6FB23230_t)((char*)d2ClientModule + 0x83230);
    D2Client_GetMouseXPos = (D2Client_GetMouseXPos_t)((char*)d2ClientModule + 0xB7BC0);
    D2Client_GetMouseYPos = (D2Client_GetMouseYPos_t)((char*)d2ClientModule + 0xB7BD0);
    D2Client_sub_6FAFC0E0 = (D2Client_sub_6FAFC0E0_t)((char*)d2ClientModule + 0x5C0E0);
    D2Client_GetHotkeyCharCode_6FAD4B60 = (D2Client_GetHotkeyCharCode_6FAD4B60_t)((char*)d2ClientModule + 0x34B60);
    D2Client_GetHotkeyString_6FAD56B0 = (D2Client_GetHotkeyString_6FAD56B0_t)((char*)d2ClientModule + 0x356B0);
    D2Client_IsGambling_6FAFC130 = (D2Client_IsGambling_6FAFC130_t)((char*)d2ClientModule + 0x5C130);
    D2Client_ColorizeLine_6FB20430 = (D2Client_ColorizeLine_6FB20430_t)((char*)d2ClientModule + 0x80430);
    D2Client_AddExtraTradeStatLines_6FAE5A40 = (D2Client_AddExtraTradeStatLines_6FAE5A40_t)((char*)d2ClientModule + 0x45A40);
    D2Client_BuildItemName_6FADD360 = (D2Client_BuildItemName_6FADD360_t)((char*)d2ClientModule + 0x3D360);
    D2Client_sub_6FB57CC0 = (D2Client_sub_6FB57CC0_t)((char*)d2ClientModule + 0xB7CC0);
    D2Client_GetItemTextLineBookQuantity_6FAE54B0 = (D2Client_GetItemTextLineBookQuantity_6FAE54B0_t)((char*)d2ClientModule + 0x454B0);
    D2Client_GetItemTextLineDurability_6FAE4060 = (D2Client_GetItemTextLineDurability_6FAE4060_t)((char*)d2ClientModule + 0x44060);
    D2Client_GetItemTextLineRuneGemStats_6FAF1480 = (D2Client_GetItemTextLineRuneGemStats_6FAF1480_t)((char*)d2ClientModule + 0x51480);
    D2Client_GetItemTextLineDamage_6FAE43D0 = (D2Client_GetItemTextLineDamage_6FAE43D0_t)((char*)d2ClientModule + 0x443D0);
    D2Client_GetItemTextLineAttackSpeed_6FAE5570 = (D2Client_GetItemTextLineAttackSpeed_6FAE5570_t)((char*)d2ClientModule + 0x45570);
    D2Client_GetItemTextLineUnknownA_6FAE5040 = (D2Client_GetItemTextLineUnknownA_6FAE5040_t)((char*)d2ClientModule + 0x45040);
    D2Client_GetItemTextLineBlockChance_6FAE4EE0 = (D2Client_GetItemTextLineBlockChance_6FAE4EE0_t)((char*)d2ClientModule + 0x44EE0);
    D2Client_GetItemTextLineDefense_6FAE51D0 = (D2Client_GetItemTextLineDefense_6FAE51D0_t)((char*)d2ClientModule + 0x451D0);
    D2Client_GetItemTextLineProperties_6FAF3160 = (D2Client_GetItemTextLineProperties_6FAF3160_t)((char*)d2ClientModule + 0x53160);
    D2Client_GetItemTextLinePropertiesInternal_6FAF19C0 = (D2Client_GetItemTextLinePropertiesInternal_6FAF19C0_t)((char*)d2ClientModule + 0x519C0);
    D2Client_GetItemTextLineQuantity_6FAE5710 = (D2Client_GetItemTextLineQuantity_6FAE5710_t)((char*)d2ClientModule + 0x45710);
    D2Client_sub_6FAE5C50 = (D2Client_sub_6FAE5C50_t)((char*)d2ClientModule + 0x45C50);
    D2Client_GetSetItemsTxt_6FAE5C80 = (D2Client_GetSetItemsTxt_6FAE5C80_t)((char*)d2ClientModule + 0x45C80);
    D2Client_GetItemTextLineLevelRequirement_6FAE41B0 = (D2Client_GetItemTextLineLevelRequirement_6FAE41B0_t)((char*)d2ClientModule + 0x441B0);
    D2Client_GetItemTextStrRequirement_6FAE4250 = (D2Client_GetItemTextStrRequirement_6FAE4250_t)((char*)d2ClientModule + 0x44250);
    D2Client_GetItemTextDexRequirement_6FAE4310 = (D2Client_GetItemTextDexRequirement_6FAE4310_t)((char*)d2ClientModule + 0x44310);
    D2Client_GetItemTextSocketed_6FAE3EE0 = (D2Client_GetItemTextSocketed_6FAE3EE0_t)((char*)d2ClientModule + 0x43EE0);
    D2Client_GetItemTextSet_6FAF32B0 = (D2Client_GetItemTextSet_6FAF32B0_t)((char*)d2ClientModule + 0x532B0);
    D2Client_GetItemTextSetB_6FAF33C0 = (D2Client_GetItemTextSetB_6FAF33C0_t)((char*)d2ClientModule + 0x533C0);
    D2Client_FormatName_6FADCFE0 = (D2Client_FormatName_6FADCFE0_t)((char*)d2ClientModule + 0x3CFE0);
    D2Client_ReplaceNameFormatToken_6FADCF10 = (D2Client_ReplaceNameFormatToken_6FADCF10_t)((char*)d2ClientModule + 0x3CF10);
    D2Client_sub_6FAE5990 = (D2Client_sub_6FAE5990_t)((char*)d2ClientModule + 0x45990);
    D2Client_GetItemTextLinePrice_6FAFB200 = (D2Client_GetItemTextLinePrice_6FAFB200_t)((char*)d2ClientModule + 0x5B200);

    D2Client_GetSkillStringId_6FB0A440 = (D2Client_GetSkillStringId_6FB0A440_t)((char*)d2ClientModule + 0x6A440);
    D2Client_GetItemTextLineDamageToUndead_6FAF12C0 = (D2Client_GetItemTextLineDamageToUndead_6FAF12C0_t)((char*)d2ClientModule + 0x512C0);
    D2Client_sub_6FAF3460 = (D2Client_sub_6FAF3460_t)((char*)d2ClientModule + 0x53460);
    D2Client_GetItemPropertyLine_6FAF21C0 = (D2Client_GetItemPropertyLine_6FAF21C0_t)((char*)d2ClientModule + 0x521C0);
    D2Client_GetItemDamage_6FAE4C60 = (D2Client_GetItemDamage_6FAE4C60_t)((char*)d2ClientModule + 0x44C60);
    D2Client_sub_6FAF13C0 = (D2Client_sub_6FAF13C0_t)((char*)d2ClientModule + 0x513C0);

    D2Client_FindUnit_6FB269F0 = (D2Client_FindUnit_6FB269F0_t)((char*)d2ClientModule + 0x869F0);
    D2Client_GetCurrentDifficulty_6FAAC090 = (D2Client_GetCurrentDifficulty_6FAAC090_t)((char*)d2ClientModule + 0xC090);
    D2Client_IsVendorRepairActive_6FAEB930 = (D2Client_IsVendorRepairActive_6FAEB930_t)((char*)d2ClientModule + 0x4B930);

    D2Client_pScreenXOffset_6FBBA748 = (int32_t*)((char*)d2ClientModule + 0x11A748);
    D2Client_pScreenYOffset_6FBBA74C = (int32_t*)((char*)d2ClientModule + 0x11A74C);
    D2Client_pScreenWidthUI_6FB740EC = (int32_t*)((char*)d2ClientModule + 0xD40EC);
    D2Client_pScreenHeightUI_6FB740F0 = (int32_t*)((char*)d2ClientModule + 0xD40F0);
    D2Client_pDWORD_6FB8CCF8 = (int32_t*)((char*)d2ClientModule + 0xECCF8);

    D2Client_pIsItemUnderCursorInInventory_6FBB58E0 = (int32_t*)((char*)d2ClientModule + 0x1158E0);
    D2Client_pIsItemUnderCursorEquipped_6FBB58E4 = (int32_t*)((char*)d2ClientModule + 0x1158E4);
    D2Client_pVendorMode_6FBB58EC = (D2C_VendorInventoryModes*)((char*)d2ClientModule + 0x1158EC);
    D2Client_pDWORD_6FB7928C = (int32_t*)((char*)d2ClientModule + 0xD928C);
    D2Client_pItemUnderCursorPosXb_6FB79290 = (int32_t*)((char*)d2ClientModule + 0xD9290);
    D2Client_pItemUnderCursorPosYb_6FB79294 = (int32_t*)((char*)d2ClientModule + 0xD9294);
    D2Client_pItemUnderCursorPosX_6FB79298 = (int32_t*)((char*)d2ClientModule + 0xD9298);
    D2Client_pItemUnderCursorPosY_6FB7929C = (int32_t*)((char*)d2ClientModule + 0xD929C);

    D2Client_pLeftSwapWeaponButtonXLeft_6FBB59A8 = (int32_t*)((char*)d2ClientModule + 0x1159A8);
    D2Client_pLeftSwapWeaponButtonXRight_6FBB59AC = (int32_t*)((char*)d2ClientModule + 0x1159AC);
    D2Client_pLeftSwapWeaponButtonYTop_6FBB59B0 = (int32_t*)((char*)d2ClientModule + 0x1159B0);
    D2Client_pRightSwapWeaponButtonXLeft_6FBB59BC = (int32_t*)((char*)d2ClientModule + 0x1159BC);
    D2Client_pRightSwapWeaponButtonXRight_6FBB59C0 = (int32_t*)((char*)d2ClientModule + 0x1159C0);
    D2Client_pRightSwapWeaponButtonYTop_6FBB59C4 = (int32_t*)((char*)d2ClientModule + 0x1159C4);

    D2Client_pItemUnderCursor_6FBB58F0 = (D2UnitStrc**)((char*)d2ClientModule + 0x1158F0);

    D2Client_pDWORD_6FB7A438 = (int32_t*)((char*)d2ClientModule + 0xDA438);
    D2Client_pDWORD_6FB79B48 = (int32_t*)((char*)d2ClientModule + 0xD9B48);
    D2Client_pElixirDescCount_6FB7A4A0 = (int32_t*)((char*)d2ClientModule + 0xDA4A0);
    D2Client_pElixirDescs_6FB7A440 = (ElixirDesc_6FB7A440*)((char*)d2ClientModule + 0xDA440);
    D2Client_pCurrentDrlgAct_6FBA7984 = (D2DrlgActStrc**)((char*)d2ClientModule + 0x107984);
    D2Client_pWORD_6FB6FA30 = (uint16_t*)((char*)d2ClientModule + 0xCFA30);

    D2Client_pWeaponSpeedStringIndexLookupTable_6FB79360 = (int32_t*)((char*)d2ClientModule + 0xD9360);
    D2Client_pDWORD_6FB794C8 = (int32_t*)((char*)d2ClientModule + 0xD94C8);
    D2Client_pAttackSpeedStringIndices_6FB79334 = (IdToStringIndexPair*)((char*)d2ClientModule + 0xD9334);
    D2Client_pWeaponClassStringIndices_6FB792D8 = (IdToStringIndexPair*)((char*)d2ClientModule + 0xD92D8);

    D2Client_pUnknownStr_6FB9A828 = (const char*)((char*)d2ClientModule + 0xFA828);

    D2Client_pQuestFlags_6FBB5D13 = (D2BitBufferStrc**)((char*)d2ClientModule + 0x115D13);
    D2Client_pIsNpcDialogOpen_6FBB5CF9 = (int32_t*)((char*)d2ClientModule + 0x115CF9);
    D2Client_pActiveNpcId_6FBB5CF5 = (int32_t*)((char*)d2ClientModule + 0x115CF5);
    D2Client_pIsGamblingSession_6FBB5D7C = (int32_t*)((char*)d2ClientModule + 0x115D7C);
    D2Client_pGameUnits_6FBBAA00 = (D2UnitStrc**)((char*)d2ClientModule + 0x11AA00);

    D2Client_pGroundItemsToShow_6FBB7028 = (GroundItemText*)((char*)d2ClientModule + 0x117028);
    D2Client_pNumGroundItemsToShow_6FBB9428 = (int32_t*)((char*)d2ClientModule + 0x119428);
    D2Client_pSelectedUnitId_6FBAB9D0 = (int32_t*)((char*)d2ClientModule + 0x10B9D0);
    D2Client_pSelectedUnitType_6FBAB9CC = (int32_t*)((char*)d2ClientModule + 0x10B9CC);
    D2Client_pSelectedUnitIsSelected_6FBAB9E8 = (int32_t*)((char*)d2ClientModule + 0x10B9E8);
    D2Client_pIsUnitSelectionDisabled_6FBAB9EC = (int32_t*)((char*)d2ClientModule + 0x10B9EC);

    // UI_GroundItem stuff 
    D2Client_GetOpenUiPanelMask_6FAB5750 = (D2Client_GetOpenUiPanelMask_6FAB5750_t)((char*)d2ClientModule + 0x15750);
    D2Client_GetViewXOffset_6FAB5890 = (D2Client_GetViewXOffset_6FAB5890_t)((char*)d2ClientModule + 0x15890);
    D2Client_GetViewYOffset_6FAB58A0 = (D2Client_GetViewYOffset_6FAB58A0_t)((char*)d2ClientModule + 0x158A0);
    D2Client_GetMonsterLifeColor_6FB20670 = (D2Client_GetMonsterLifeColor_6FB20670_t)((char*)d2ClientModule + 0x80670);
    D2Client_GetUnitName_6FB297F0 = (D2Client_GetUnitName_6FB297F0_t)((char*)d2ClientModule + 0x897F0);
    D2Client_GetRosterPlayerNameAndColor_6FB21680 = (D2Client_GetRosterPlayerNameAndColor_6FB21680_t)((char*)d2ClientModule + 0x81680);
    D2Client_GetRosterPortalOwnerName_6FAB0D00 = (D2Client_GetRosterPortalOwnerName_6FAB0D00_t)((char*)d2ClientModule + 0x10D00);
    D2Client_GetRosterPetOwnerId_6FAB1B00 = (D2Client_GetRosterPetOwnerId_6FAB1B00_t)((char*)d2ClientModule + 0x11B00);
    D2Client_GetRosterUnitName_6FAB0BC0 = (D2Client_GetRosterUnitName_6FAB0BC0_t)((char*)d2ClientModule + 0x10BC0);
    D2Client_GetRosterUnitLife_6FAB1460 = (D2Client_GetRosterUnitLife_6FAB1460_t)((char*)d2ClientModule + 0x11460);
    D2Client_GetRosterUnitRosterInfo_6FAB0D80 = (D2Client_GetRosterUnitRosterInfo_6FAB0D80_t)((char*)d2ClientModule + 0x10D80);
    D2Client_CheckPartyMemberFlags_6FB4B900 = (D2Client_CheckPartyMemberFlags_6FB4B900_t)((char*)d2ClientModule + 0xAB900);
    D2Client_AreUnitsHostile_6FAB07D0 = (D2Client_AreUnitsHostile_6FAB07D0_t)((char*)d2ClientModule + 0x107D0);
    D2Client_GetMonStats2TxtFromClassId_6FB247F0 = (D2Client_GetMonStats2TxtFromClassId_6FB247F0_t)((char*)d2ClientModule + 0x847F0);
    D2Client_GetMonStatsTxtFromClassId_6FAAE570 = (D2Client_GetMonStatsTxtFromClassId_6FAAE570_t)((char*)d2ClientModule + 0xE570);
    D2Client_GetObjectOwnerName_6FB48550 = (D2Client_GetObjectOwnerName_6FB48550_t)((char*)d2ClientModule + 0xA8550);
    D2Client_CheckMonsterTypeFlag_6FB449D0 = (D2Client_CheckMonsterTypeFlag_6FB449D0_t)((char*)d2ClientModule + 0xA49D0);
    D2Client_IsMonsterUnique_6FB40D00 = (D2Client_IsMonsterUnique_6FB40D00_t)((char*)d2ClientModule + 0xA0D00);
    D2Client_IsMonsterChampion_6FB40CC0 = (D2Client_IsMonsterChampion_6FB40CC0_t)((char*)d2ClientModule + 0xA0CC0);
    D2Client_IsMonsterGhostly_6FB40CE0 = (D2Client_IsMonsterGhostly_6FB40CE0_t)((char*)d2ClientModule + 0xA0CE0);
    D2Client_IsMonsterMinion_6FB40D20 = (D2Client_IsMonsterMinion_6FB40D20_t)((char*)d2ClientModule + 0xA0D20);
    D2Client_IsMonsterSuperUnique_6FB40D40 = (D2Client_IsMonsterSuperUnique_6FB40D40_t)((char*)d2ClientModule + 0xA0D40);
    D2Client_GetScreenOffsetDimensionsTBD_6FB24690 = (D2Client_GetScreenOffsetDimensionsTBD_6FB24690_t)((char*)d2ClientModule + 0x84690);
    D2Client_UpdateUniqueMonsterInfoString_6FB20600 = (D2Client_UpdateUniqueMonsterInfoString_6FB20600_t)((char*)d2ClientModule + 0x80600);
    D2Client_UpdateNormalMonsterInfoString_6FB205D0 = (D2Client_UpdateNormalMonsterInfoString_6FB205D0_t)((char*)d2ClientModule + 0x805D0);
    D2Client_MonsterResistancesInfoString_6FB21570 = (D2Client_MonsterResistancesInfoString_6FB21570_t)((char*)d2ClientModule + 0x81570);
    D2Client_IsActiveNpcDialogOpen_6FAFBB50 = (D2Client_IsActiveNpcDialogOpen_6FAFBB50_t)((char*)d2ClientModule + 0x5BB50);
    D2Client_IsActiveNpcTalking_6FB1EE90 = (D2Client_IsActiveNpcTalking_6FB1EE90_t)((char*)d2ClientModule + 0x7EE90);
    D2Client_10002 = (D2Client_10002_t)((char*)d2ClientModule + 0x18EF0);
    D2Client_GetSelectedUnit_6FAB5A20 = (D2Client_GetSelectedUnit_6FAB5A20_t)((char *)d2ClientModule + 0x15A20);
    D2Client_sub_6FB09D80 = (D2Client_sub_6FB09D80_t)((char *)d2ClientModule + 0x69D80);
    D2Client_sub_6FAB5A90 = (D2Client_sub_6FAB5A90_t)((char *)d2ClientModule + 0x15A90);
    D2Client_ClearUnitSelection_6FAB5D40 = (D2Client_ClearUnitSelection_6FAB5D40_t)((char*)d2ClientModule + 0x15D40);

    D2Client_pGameType_6FBA7960 = (int32_t*)((char*)d2ClientModule + 0x107960);
    D2Client_pJoinId_6FBA7748 = (int16_t*)((char*)d2ClientModule + 0x107748);
    D2Client_pServerIp_6FB75468 = (char*)((char*)d2ClientModule + 0xD5468);
    D2Client_pGameName_6FBA7898 = (char*)((char*)d2ClientModule + 0x107898);
    D2Client_pUnitMouseOverTextPosX_6FB8EA28 = (int32_t*)((char*)d2ClientModule + 0xEEA28);
    D2Client_pUnitMouseOverTextPosY_6FB8EA2C = (int32_t*)((char*)d2ClientModule + 0xEEA2C);
    D2Client_pOpenUIPanelMask_6FBAB9C4 = (int32_t*)((char*)d2ClientModule + 0x10B9C4);
    D2Client_pViewYOffset_6FBAB9B8 = (int32_t*)((char*)d2ClientModule + 0x10B9B8);
    D2Client_pViewXOffset_6FBAB9BC = (int32_t*)((char*)d2ClientModule + 0x10B9BC);
    D2Client_pViewXOffsetUnits_6FBAB9C8 = (int32_t*)((char*)d2ClientModule + 0x10B9C8);
    D2Client_pRosterPetRoot_6FBAB9A0 = (D2RosterPetStrc*)((char*)d2ClientModule + 0x10B9A0);
    D2Client_pRosterUnitRoot_6FBAB994 = (D2RosterUnitStrc*)((char*)d2ClientModule + 0x10B994);
    D2Client_pShowAllGroundItemTexts_6FBBA6DC = (int32_t*)((char*)d2ClientModule + 0x11A6DC);
    D2Client_pNormalMonsterInfoString_6FBB9FE0 = (wchar_t**)((char*)d2ClientModule + 0x119FE0);
    D2Client_pMonsterImmunitiesInfoString_6FBBA4A0 = (wchar_t**)((char*)d2ClientModule + 0x11A4A0);
    D2Client_pUniqueMonsterInfoString_6FBBA2A0 = (wchar_t**)((char*)d2ClientModule + 0x11A2A0);
    D2Client_UIStates_6FBBA6A8 = (int32_t*)((char*)d2ClientModule + 0x11A6A8);
}
