#pragma once

#include <Windows.h>
#include <cstdint>

#include <Drlg/D2DrlgDrlg.h>
#include <D2StatList.h>
#include <D2Inventory.h>
#include <Units/UnitFinds.h>
#include <D2BitManip.h>

struct Unicode;
struct D2SkillStrc;

struct D2RosterInfoStrc;
struct D2MonStats2Txt;
struct D2MonStatsTxt;
struct D2RosterPetStrc;
struct D2RosterUnitStrc;

#pragma pack(push, 1)
struct ElixirDesc_6FB7A440
{
    int32_t StatId;
    int32_t UnknownMustBeOne;
    int16_t NegativeStatStringIndex;
    int16_t PositiveStatStringIndex;
    int32_t UnknownMustBeTwo;
};
#pragma pack(pop)

void InitD2ClientExports();

typedef void(__fastcall* D2Client_DrawTextCentered_6FACFCD0_t)(int nX, int nY, int maxWidthMaybe, const Unicode* text, int nColor);

typedef D2UnitStrc* (__fastcall* D2Client_sub_6FB0A950_t)(D2UnitStrc* pTarget);
typedef D2UnitStrc* (__fastcall* D2Client_sub_6FB0AA00_t)(D2UnitStrc* pTarget);
typedef int32_t(__fastcall* D2Client_sub_6FB0B580_t)();
typedef void(__fastcall* D2Client_sub_6FB0B2C0_t)(D2UnitStrc* pUnit, int32_t* pUnknown1, int32_t* pUnknown2, int32_t* pColor, int32_t unknown3, int32_t unknown4, D2SkillStrc* pSkill, int32_t unknown5, D2UnitStrc* unknown6, int32_t unknown7);
typedef void(__fastcall* D2Client_sub_6FB0B6F0_t)(D2UnitStrc* pUnit, int32_t* pUnknown1, int32_t* pUnknown2, int32_t* pColor, D2UnitStrc* unknown3, D2SkillStrc* pSkill);
typedef void(__fastcall* D2Client_sub_6FB0BB10_t)(D2UnitStrc* pUnit, int32_t* pUnknown1, int32_t* pUnknown2, int32_t* pColor);
typedef int32_t(__fastcall* D2Client_IsLod_6FAAC080_t)();

extern D2Client_DrawTextCentered_6FACFCD0_t D2Client_DrawTextCentered_6FACFCD0; //                                             | 6FACFCD0
extern D2Client_sub_6FB0B2C0_t D2Client_sub_6FB0B2C0; //                                                                       | 6FB0B2C0
extern D2Client_sub_6FB0B6F0_t D2Client_sub_6FB0B6F0; //                                                                       | 6FB0B6F0
extern D2Client_sub_6FB0BB10_t D2Client_sub_6FB0BB10; //                                                                       | 6FB0BB10
extern D2Client_IsLod_6FAAC080_t D2Client_IsLod_6FAAC080; //                                                                   | 6FAAC080
extern D2Client_sub_6FB0A950_t D2Client_sub_6FB0A950; //                                                                       | 6FB0A950
extern D2Client_sub_6FB0AA00_t D2Client_sub_6FB0AA00; //                                                                       | 6FB0AA00
extern D2Client_sub_6FB0B580_t D2Client_sub_6FB0B580; //                                                                       | 6FB0B580


// UI-Inv
typedef D2UnitStrc* (__fastcall* D2Client_GetCurrentPlayer_6FB283D0_t)();
typedef bool (__fastcall* D2Client_IsBeltOpen_6FAFE9E0_t)();
typedef int32_t (__fastcall* D2Client_IsUiOpen_6FB23230_t)(D2C_UIvars uiId);
typedef int32_t (__fastcall* D2Client_GetMouseYPos_t)();
typedef int32_t (__fastcall* D2Client_GetMouseXPos_t)();
typedef bool (__fastcall* D2Client_sub_6FAFC0E0_t)();
typedef int16_t (__fastcall* D2Client_GetHotkeyCharCode_6FAD4B60_t)(int32_t a1, int32_t a2);
typedef Unicode* (__fastcall* D2Client_GetHotkeyString_6FAD56B0_t)(int32_t hotkeyId, int32_t useAlternativeHotkey);
typedef int32_t (__fastcall* D2Client_IsGambling_6FAFC130_t)();
typedef Unicode* (__fastcall* D2Client_ColorizeLine_6FB20430_t)(const struct Unicode* sourceStr, char colorCode);
typedef void (__fastcall* D2Client_BuildItemName_6FADD360_t)(D2UnitStrc* pItem, struct Unicode* buff, int maxLen);
typedef Unicode* (__fastcall* D2Client_AddExtraTradeStatLines_6FAE5A40_t)(const struct Unicode* sourceStr, struct Unicode* newOutput);
typedef int32_t (__fastcall* D2Client_sub_6FB57CC0_t)();
typedef void (__fastcall* D2Client_GetItemTextLineBookQuantity_6FAE54B0_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void (__fastcall* D2Client_GetItemTextLineDurability_6FAE4060_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void (__fastcall* D2Client_GetItemTextLineRuneGemStats_6FAF1480_t)(D2UnitStrc* pItem, struct Unicode* outBuff, int maxLen);
typedef void (__fastcall* D2Client_GetItemTextLineDamage_6FAE43D0_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void (__fastcall* D2Client_GetItemTextLineAttackSpeed_6FAE5570_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void (__fastcall* D2Client_GetItemTextLineUnknownA_6FAE5040_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void (__fastcall* D2Client_GetItemTextLineBlockChance_6FAE4EE0_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void (__fastcall* D2Client_GetItemTextLineDefense_6FAE51D0_t)(D2UnitStrc* pUnit, D2UnitStrc* pItem, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void (__fastcall* D2Client_GetItemTextLineProperties_6FAF3160_t)(D2UnitStrc* pItem, struct Unicode* outBuff, int maxLen, int bFlag, const struct Unicode* existingContents);
typedef void (__fastcall* D2Client_GetItemTextLinePropertiesInternal_6FAF19C0_t)(D2UnitStrc* pUnit, struct Unicode* outBuff, int outBuffMaxLen, int bUnknownFlag1, int unitState, int nUnitState, int nUnitFlags, int bUnknownFlag2);
typedef void (__fastcall* D2Client_GetItemTextLineQuantity_6FAE5710_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef D2SetsTxt* (__fastcall* D2Client_sub_6FAE5C50_t)(int32_t setsTxtIndex);
typedef D2SetItemsTxt* (__fastcall* D2Client_GetSetItemsTxt_6FAE5C80_t)(int32_t setsTxtIndex);
typedef void (__fastcall* D2Client_GetItemTextLineLevelRequirement_6FAE41B0_t)(struct Unicode* outBuff, int levelRequirement);
typedef void (__fastcall* D2Client_GetItemTextStrRequirement_6FAE4250_t)(struct Unicode* outBuff, D2ItemsTxt* pItemTxtRecord, int requiredStr);
typedef void (__fastcall* D2Client_GetItemTextDexRequirement_6FAE4310_t)(struct Unicode* outBuff, D2ItemsTxt* pItemTxtRecord, int requiredDex);
typedef void (__fastcall* D2Client_GetItemTextSocketed_6FAE3EE0_t)(D2UnitStrc* pItem, struct Unicode* outBuff);
typedef void (__fastcall* D2Client_GetItemTextSet_6FAF32B0_t)(D2UnitStrc* pUnit, D2UnitStrc* pItem, struct Unicode* outBuff, int maxLength);
typedef void (__fastcall* D2Client_GetItemTextSetB_6FAF33C0_t)(D2UnitStrc* pUnit, D2UnitStrc* pItem, struct Unicode* outBuff, int maxLength);
typedef void (__stdcall* D2Client_FormatName_6FADCFE0_t)(struct Unicode* outBuff, const struct Unicode* format, ...);
typedef void (__stdcall* D2Client_ReplaceNameFormatToken_6FADCF10_t)(struct Unicode* format, int32_t tokenIndex, const struct Unicode* replacement);
typedef D2UnitStrc* (__fastcall* D2Client_sub_6FAE5990_t)(D2InventoryStrc* pInventory, int nSetItemId);
typedef bool (__fastcall* D2Client_GetItemTextLinePrice_6FAFB200_t)(D2UnitStrc* pItem, int a2, int* pTransactionCost, struct Unicode* outBuff, int maxLength);

// UI-Inv-Mod
typedef __int16(__fastcall* D2Client_GetSkillStringId_6FB0A440_t)(int nSkillsTxtIndex, int offset);
typedef void(__fastcall* D2Client_GetItemTextLineDamageToUndead_6FAF12C0_t)(D2UnitStrc* pUnit, struct Unicode* outBuff, int outBuffLen);
typedef int(__fastcall* D2Client_sub_6FAF3460_t)(int* statValues, D2C_ItemStats nStatId, struct Unicode* outBuff);
typedef int(__fastcall* D2Client_GetItemPropertyLine_6FAF21C0_t)(D2UnitStrc* pUnit, D2StatListStrc* pStatListEx, int nStatId, int charStatsTxtRecordIndex, int statValueModifier, Unicode* outputBuffer256);
typedef void(__fastcall* D2Client_GetItemDamage_6FAE4C60_t)(D2UnitStrc* pCurrentPlayer, D2UnitStrc* pItem, D2C_ItemStats minDamageStat, D2C_ItemStats maxDamageStat, int32_t* outMinDamage, int32_t* outMaxDamage, int32_t* isDamageModified); // 44C60
typedef void(__fastcall* D2Client_sub_6FAF13C0_t)(D2UnitStrc* pItem, D2GemsTxt* pMods, int32_t nPropSet, struct Unicode* outBuff, int maxLen, struct Unicode* existingContents);

typedef D2UnitStrc* (__fastcall* D2Client_FindUnit_6FB269F0_t)(int32_t unitId, int32_t unitType); // 869F0
typedef int8_t (__fastcall* D2Client_GetCurrentDifficulty_6FAAC090_t)(); // C090
typedef int32_t (__fastcall* D2Client_IsVendorRepairActive_6FAEB930_t)(); // 4B930

// UI_GroundItem stuff
typedef int32_t (__fastcall* D2Client_GetOpenSidePanels_6FAB5750_t)(); // 15750
typedef int32_t (__fastcall* D2Client_GetViewXOffset_6FAB5890_t)(); // 15890
typedef int32_t (__fastcall* D2Client_GetViewYOffset_6FAB58A0_t)(); // 158A0
typedef int32_t (__fastcall* D2Client_GetMonsterLifeColor_6FB20670_t)(D2UnitStrc* pUnit); // 80670
typedef const Unicode* (__fastcall* D2Client_GetUnitName_6FB297F0_t)(D2UnitStrc* pUnit); // 897F0
typedef int32_t (__fastcall* D2Client_GetRosterPlayerNameAndColor_6FB21680_t)(D2UnitStrc* pUnit, int32_t* pOutColorBg, int32_t* pOutColor, struct Unicode* outBuff, int32_t outBuffLen); // 81680
typedef char* (__fastcall* D2Client_GetRosterPortalOwnerName_6FAB0D00_t)(int32_t unitId); // 10D00
typedef int32_t (__fastcall* D2Client_GetRosterPetOwnerId_6FAB1B00_t)(int32_t unitId); // 11B00
typedef char* (__fastcall* D2Client_GetRosterUnitName_6FAB0BC0_t)(int32_t unitId); // 10BC0
typedef int32_t (__fastcall* D2Client_GetRosterUnitLife_6FAB1460_t)(int32_t unitId); // 11460
typedef D2RosterInfoStrc** (__fastcall* D2Client_GetRosterUnitRosterInfo_6FAB0D80_t)(int32_t unitId); // 10D80
typedef int32_t (__fastcall* D2Client_CheckPartyMemberFlags_6FB4B900_t)(int unitIdA, int unitIdB, int32_t partyFlag); // AB900
typedef int32_t (__fastcall* D2Client_AreUnitsHostile_6FAB07D0_t)(int unitIdA, int unitIdB); // 107D0
typedef D2MonStats2Txt* (__fastcall* D2Client_GetMonStats2TxtFromClassId_6FB247F0_t)(int classId); // 847F0
typedef D2MonStatsTxt* (__fastcall* D2Client_GetMonStatsTxtFromClassId_6FAAE570_t)(int classId); // E570
typedef char* (__fastcall* D2Client_GetObjectOwnerName_6FB48550_t)(D2UnitStrc* pUnit); // A8550
typedef BOOL (__fastcall* D2Client_CheckMonsterTypeFlag_6FB449D0_t)(D2UnitStrc* pUnit, unsigned __int16 monsterTypeFlag); // A49D0
typedef BOOL (__fastcall* D2Client_IsMonsterUnique_6FB40D00_t)(D2UnitStrc* pUnit); // A0D00
typedef BOOL (__fastcall* D2Client_IsMonsterChampion_6FB40CC0_t)(D2UnitStrc* pUnit); // A0CC0
typedef BOOL (__fastcall* D2Client_IsMonsterGhostly_6FB40CE0_t)(D2UnitStrc* pUnit); // A0CE0
typedef BOOL (__fastcall* D2Client_IsMonsterMinion_6FB40D20_t)(D2UnitStrc* pUnit); // A0D20
typedef BOOL (__fastcall* D2Client_IsMonsterSuperUnique_6FB40D40_t)(D2UnitStrc* pUnit); // A0D40
typedef BOOL (__fastcall* D2Client_GetScreenOffsetDimensionsTBD_6FB24690_t)(int* dimensionsOrSomething); // 84690
typedef BOOL (__fastcall* D2Client_UpdateUniqueMonsterInfoString_6FB20600_t)(D2UnitStrc* pUnit, int32_t stringIndex); // 80600
typedef void (__fastcall* D2Client_UpdateNormalMonsterInfoString_6FB205D0_t)(const  Unicode* newMonsterInfo, int xAdjust); // 805D0
typedef void (__fastcall* D2Client_MonsterResistancesInfoString_6FB21570_t)(const D2UnitStrc* pUnit); // 81570
typedef int (__fastcall* D2Client_IsActiveNpcDialogOpen_6FAFBB50_t)(int32_t** pActiveNpcId); // 5BB50
typedef BOOL (__fastcall* D2Client_IsActiveNpcTalking_6FB1EE90_t)(); // 7EE90
typedef int (__stdcall* D2Client_10002_t)(int32_t unused, int32_t questIndex); // 18EF0

extern D2Client_GetCurrentPlayer_6FB283D0_t D2Client_GetCurrentPlayer_6FB283D0; // 883D0                                       | 6FB283D0
extern D2Client_IsBeltOpen_6FAFE9E0_t D2Client_IsBeltOpen_6FAFE9E0; // 5E9E0                                                   | 6FAFE9E0
extern D2Client_IsUiOpen_6FB23230_t D2Client_IsUiOpen_6FB23230; // 83230                                                       | 6FB23230
extern D2Client_GetMouseXPos_t D2Client_GetMouseXPos; // B7BC0                                                                 | 6FB57BC0
extern D2Client_GetMouseYPos_t D2Client_GetMouseYPos; // B7BD0                                                                 | 6FB57BD0
extern D2Client_sub_6FAFC0E0_t D2Client_sub_6FAFC0E0; // 5C0E0                                                                 | 6FAFC0E0
extern D2Client_GetHotkeyCharCode_6FAD4B60_t D2Client_GetHotkeyCharCode_6FAD4B60; // 34B60                                     | 6FAD4B60
extern D2Client_GetHotkeyString_6FAD56B0_t D2Client_GetHotkeyString_6FAD56B0; // 356B0                                         | 6FAD56B0
extern D2Client_IsGambling_6FAFC130_t D2Client_IsGambling_6FAFC130; // 5C130                                                   | 6FAFC130
extern D2Client_ColorizeLine_6FB20430_t D2Client_ColorizeLine_6FB20430; // 80430                                               | 6FB20430
extern D2Client_AddExtraTradeStatLines_6FAE5A40_t D2Client_AddExtraTradeStatLines_6FAE5A40; // 45A40                           | 6FAE5A40
extern D2Client_BuildItemName_6FADD360_t D2Client_BuildItemName_6FADD360; // 3D360                                             | 6FADD360
extern D2Client_sub_6FB57CC0_t D2Client_sub_6FB57CC0; // B7CC0                                                                 | 6FB57CC0
extern D2Client_GetItemTextLineBookQuantity_6FAE54B0_t D2Client_GetItemTextLineBookQuantity_6FAE54B0; // 454B0                 | 6FAE54B0
extern D2Client_GetItemTextLineDurability_6FAE4060_t D2Client_GetItemTextLineDurability_6FAE4060; // 44060                     | 6FAE4060
extern D2Client_GetItemTextLineRuneGemStats_6FAF1480_t D2Client_GetItemTextLineRuneGemStats_6FAF1480; // 51480                 | 6FAF1480
extern D2Client_GetItemTextLineDamage_6FAE43D0_t D2Client_GetItemTextLineDamage_6FAE43D0; // 443D0                             | 6FAE43D0
extern D2Client_GetItemTextLineAttackSpeed_6FAE5570_t D2Client_GetItemTextLineAttackSpeed_6FAE5570; // 45570                   | 6FAE5570
extern D2Client_GetItemTextLineUnknownA_6FAE5040_t D2Client_GetItemTextLineUnknownA_6FAE5040; // 45040                         | 6FAE5040
extern D2Client_GetItemTextLineBlockChance_6FAE4EE0_t D2Client_GetItemTextLineBlockChance_6FAE4EE0; // 44EE0                   | 6FAE4EE0
extern D2Client_GetItemTextLineDefense_6FAE51D0_t D2Client_GetItemTextLineDefense_6FAE51D0; // 451D0                           | 6FAE51D0
extern D2Client_GetItemTextLineProperties_6FAF3160_t D2Client_GetItemTextLineProperties_6FAF3160; // 53160                     | 6FAF3160
extern D2Client_GetItemTextLinePropertiesInternal_6FAF19C0_t D2Client_GetItemTextLinePropertiesInternal_6FAF19C0; // 519C0     | 6FAF19C0
extern D2Client_GetItemTextLineQuantity_6FAE5710_t D2Client_GetItemTextLineQuantity_6FAE5710; // 45710                         | 6FAE5710
extern D2Client_sub_6FAE5C50_t D2Client_sub_6FAE5C50; // 45C50                                                                 | 6FAE5C50
extern D2Client_GetSetItemsTxt_6FAE5C80_t D2Client_GetSetItemsTxt_6FAE5C80; // 45C80                                           | 6FAE5C80
extern D2Client_GetItemTextLineLevelRequirement_6FAE41B0_t D2Client_GetItemTextLineLevelRequirement_6FAE41B0; // 441B0         | 6FAE41B0
extern D2Client_GetItemTextStrRequirement_6FAE4250_t D2Client_GetItemTextStrRequirement_6FAE4250; // 44250                     | 6FAE4250
extern D2Client_GetItemTextDexRequirement_6FAE4310_t D2Client_GetItemTextDexRequirement_6FAE4310; // 44310                     | 6FAE4310
extern D2Client_GetItemTextSocketed_6FAE3EE0_t D2Client_GetItemTextSocketed_6FAE3EE0; // 43EE0                                 | 6FAE3EE0
extern D2Client_GetItemTextSet_6FAF32B0_t D2Client_GetItemTextSet_6FAF32B0; // 532B0                                           | 6FAF32B0
extern D2Client_GetItemTextSetB_6FAF33C0_t D2Client_GetItemTextSetB_6FAF33C0; // 533C0                                         | 6FAF33C0
extern D2Client_FormatName_6FADCFE0_t D2Client_FormatName_6FADCFE0; // 3CFE0                                                   | 6FADCFE0
extern D2Client_ReplaceNameFormatToken_6FADCF10_t D2Client_ReplaceNameFormatToken_6FADCF10; // 3CF10                           | 6FADCF10
extern D2Client_sub_6FAE5990_t D2Client_sub_6FAE5990; // 45990                                                                 | 6FAE5990
extern D2Client_GetItemTextLinePrice_6FAFB200_t D2Client_GetItemTextLinePrice_6FAFB200; // 5B200                               | 6FAFB200

// UI_GroundItem stuff 
extern D2Client_GetOpenSidePanels_6FAB5750_t D2Client_GetOpenSidePanels_6FAB5750; // 15750                                     | 6FAB5750
extern D2Client_GetViewXOffset_6FAB5890_t D2Client_GetViewXOffset_6FAB5890; // 15890                                           | 6FAB5890
extern D2Client_GetViewYOffset_6FAB58A0_t D2Client_GetViewYOffset_6FAB58A0; // 158A0                                           | 6FAB58A0
extern D2Client_GetMonsterLifeColor_6FB20670_t D2Client_GetMonsterLifeColor_6FB20670; // 80670                                 | 6FB20670
extern D2Client_GetUnitName_6FB297F0_t D2Client_GetUnitName_6FB297F0; // 897F0                                                 | 6FB297F0
extern D2Client_GetRosterPlayerNameAndColor_6FB21680_t D2Client_GetRosterPlayerNameAndColor_6FB21680; // 81680                 | 6FB21680
extern D2Client_GetRosterPortalOwnerName_6FAB0D00_t D2Client_GetRosterPortalOwnerName_6FAB0D00; // 10D00                       | 6FAB0D00
extern D2Client_GetRosterPetOwnerId_6FAB1B00_t D2Client_GetRosterPetOwnerId_6FAB1B00; // 11B00                                 | 6FAB1B00
extern D2Client_GetRosterUnitName_6FAB0BC0_t D2Client_GetRosterUnitName_6FAB0BC0; // 10BC0                                     | 6FAB0BC0
extern D2Client_GetRosterUnitLife_6FAB1460_t D2Client_GetRosterUnitLife_6FAB1460; // 11460                                     | 6FAB1460
extern D2Client_GetRosterUnitRosterInfo_6FAB0D80_t D2Client_GetRosterUnitRosterInfo_6FAB0D80; // 10D80                         | 6FAB0D80
extern D2Client_CheckPartyMemberFlags_6FB4B900_t D2Client_CheckPartyMemberFlags_6FB4B900; // AB900                             | 6FB4B900
extern D2Client_AreUnitsHostile_6FAB07D0_t D2Client_AreUnitsHostile_6FAB07D0; // 107D0                                         | 6FAB07D0
extern D2Client_GetMonStats2TxtFromClassId_6FB247F0_t D2Client_GetMonStats2TxtFromClassId_6FB247F0; // 847F0                   | 6FB247F0
extern D2Client_GetMonStatsTxtFromClassId_6FAAE570_t D2Client_GetMonStatsTxtFromClassId_6FAAE570; // E570                      | 6FAAE570
extern D2Client_GetObjectOwnerName_6FB48550_t D2Client_GetObjectOwnerName_6FB48550; // A8550                                   | 6FB48550
extern D2Client_CheckMonsterTypeFlag_6FB449D0_t D2Client_CheckMonsterTypeFlag_6FB449D0; // A49D0                               | 6FB449D0
extern D2Client_IsMonsterUnique_6FB40D00_t D2Client_IsMonsterUnique_6FB40D00; // A0D00                                         | 6FB40D00
extern D2Client_IsMonsterChampion_6FB40CC0_t D2Client_IsMonsterChampion_6FB40CC0; // A0CC0                                     | 6FB40CC0
extern D2Client_IsMonsterGhostly_6FB40CE0_t D2Client_IsMonsterGhostly_6FB40CE0; // A0CE0                                       | 6FB40CE0
extern D2Client_IsMonsterMinion_6FB40D20_t D2Client_IsMonsterMinion_6FB40D20; // A0D20                                         | 6FB40D20
extern D2Client_IsMonsterSuperUnique_6FB40D40_t D2Client_IsMonsterSuperUnique_6FB40D40; // A0D40                               | 6FB40D40
extern D2Client_GetScreenOffsetDimensionsTBD_6FB24690_t D2Client_GetScreenOffsetDimensionsTBD_6FB24690; // 84690               | 6FB24690
extern D2Client_UpdateUniqueMonsterInfoString_6FB20600_t D2Client_UpdateUniqueMonsterInfoString_6FB20600; // 80600             | 6FB20600
extern D2Client_UpdateNormalMonsterInfoString_6FB205D0_t D2Client_UpdateNormalMonsterInfoString_6FB205D0; // 805D0             | 6FB205D0
extern D2Client_MonsterResistancesInfoString_6FB21570_t D2Client_MonsterResistancesInfoString_6FB21570; // 81570               | 6FB21570
extern D2Client_IsActiveNpcDialogOpen_6FAFBB50_t D2Client_IsActiveNpcDialogOpen_6FAFBB50; // 5BB50                             | 6FAFBB50
extern D2Client_IsActiveNpcTalking_6FB1EE90_t D2Client_IsActiveNpcTalking_6FB1EE90; // 7EE90                                   | 6FB1EE90
extern D2Client_10002_t D2Client_10002; // 18EF0                                                                               | 6FAB8EF0

extern int32_t* D2Client_pScreenXOffset_6FBBA748; // 11A748                                                                    | 6FBBA748
extern int32_t* D2Client_pScreenYOffset_6FBBA74C; // 11A74C                                                                    | 6FBBA74C
extern int32_t* D2Client_pScreenWidthUI_6FB740EC; // D40EC                                                                     | 6FB740EC
extern int32_t* D2Client_pScreenHeightUI_6FB740F0; // D40F0                                                                    | 6FB740F0
extern int32_t* D2Client_pDWORD_6FB8CCF8; // ECCF8                                                                             | 6FB8CCF8

extern int32_t* D2Client_pIsItemUnderCursorInInventory_6FBB58E0; // 1158E0                                                     | 6FBB58E0
extern int32_t* D2Client_pIsItemUnderCursorEquipped_6FBB58E4; // 1158E4                                                        | 6FBB58E4
extern D2C_VendorInventoryModes* D2Client_pVendorMode_6FBB58EC; // 1158EC                                                      | 6FBB58EC
extern int32_t* D2Client_pDWORD_6FB7928C; // D928C                                                                             | 6FB7928C
extern int32_t* D2Client_pItemUnderCursorPosXb_6FB79290; // D9290                                                              | 6FB79290
extern int32_t* D2Client_pItemUnderCursorPosYb_6FB79294; // D9294                                                              | 6FB79294
extern int32_t* D2Client_pItemUnderCursorPosX_6FB79298; // D9298                                                               | 6FB79298
extern int32_t* D2Client_pItemUnderCursorPosY_6FB7929C; // D929C                                                               | 6FB7929C

extern int32_t* D2Client_pLeftSwapWeaponButtonXLeft_6FBB59A8; // 1159A8                                                        | 6FBB59A8
extern int32_t* D2Client_pLeftSwapWeaponButtonXRight_6FBB59AC; // 1159AC                                                       | 6FBB59AC
extern int32_t* D2Client_pLeftSwapWeaponButtonYTop_6FBB59B0; // 1159B0                                                         | 6FBB59B0
extern int32_t* D2Client_pRightSwapWeaponButtonXLeft_6FBB59BC; // 1159BC                                                       | 6FBB59BC
extern int32_t* D2Client_pRightSwapWeaponButtonXRight_6FBB59C0; // 1159C0                                                      | 6FBB59C0
extern int32_t* D2Client_pRightSwapWeaponButtonYTop_6FBB59C4; // 1159C4                                                        | 6FBB59C4

extern D2UnitStrc** D2Client_pItemUnderCursor_6FBB58F0; // 1158F0                                                              | 6FBB58F0
                                                                                                                                 
// UI-Inv-Mod
extern D2Client_GetSkillStringId_6FB0A440_t D2Client_GetSkillStringId_6FB0A440; //6A440                                        | 6FB0A440
extern D2Client_GetItemTextLineDamageToUndead_6FAF12C0_t D2Client_GetItemTextLineDamageToUndead_6FAF12C0; //512C0                                                                  | 6FAF12C0
extern D2Client_sub_6FAF3460_t D2Client_sub_6FAF3460; //53460                                                                  | 6FAF3460
extern D2Client_GetItemPropertyLine_6FAF21C0_t D2Client_GetItemPropertyLine_6FAF21C0; //521C0                                  | 6FAF21C0
extern D2Client_GetItemDamage_6FAE4C60_t D2Client_GetItemDamage_6FAE4C60; // 44C60
extern D2Client_sub_6FAF13C0_t D2Client_sub_6FAF13C0; // 513C0

extern D2Client_FindUnit_6FB269F0_t D2Client_FindUnit_6FB269F0; // 869F0
extern D2Client_GetCurrentDifficulty_6FAAC090_t D2Client_GetCurrentDifficulty_6FAAC090; // C090
extern D2Client_IsVendorRepairActive_6FAEB930_t D2Client_IsVendorRepairActive_6FAEB930; // 4B930

extern int32_t* D2Client_pDWORD_6FB7A438; // DA438                                                                             | 6FB7A438
extern int32_t* D2Client_pDWORD_6FB79B48; // D9B48                                                                             | 6FB79B48
extern int32_t* D2Client_pElixirDescCount_6FB7A4A0; // DA4A0                                                                             | 6FB7A4A0
extern ElixirDesc_6FB7A440* D2Client_pElixirDescs_6FB7A440; // DA440                                                              | 6FB7A440
extern D2DrlgActStrc** D2Client_pCurrentDrlgAct_6FBA7984; // current act? // 6A440                                                                      | 6FBA7984
extern uint16_t* D2Client_pWORD_6FB6FA30; // CFA30                                                                             | 6FB6FA30

#pragma pack(push, 1)
struct IdToStringIndexPair
{
    int32_t id;
    int16_t stringIndex;
};
#pragma pack(pop)

extern int32_t* D2Client_pWeaponSpeedStringIndexLookupTable_6FB79360; // D9360
extern int32_t* D2Client_pDWORD_6FB794C8; // D94C8
extern IdToStringIndexPair* D2Client_pAttackSpeedStringIndices_6FB79334; // D9334
extern IdToStringIndexPair* D2Client_pWeaponClassStringIndices_6FB792D8; // D92D8

extern const char* D2Client_pUnknownStr_6FB9A828; // FA828

extern D2BitBufferStrc** D2Client_pQuestFlags_6FBB5D13; // 115D13
extern int32_t* D2Client_pIsNpcDialogOpen_6FBB5CF9; // 115CF9
extern int32_t* D2Client_pActiveNpcId_6FBB5CF5; // 115CF5
extern int32_t* D2Client_pIsGamblingSession_6FBB5D7C; // 115D7C
extern D2UnitStrc** D2Client_pGameUnits_6FBBAA00; // 11AA00

// UI_GroundItem stuff 
extern int32_t* D2Client_pGameType_6FBA7960; // 107960
extern int16_t* D2Client_pJoinId_6FBA7748; // 107748
extern char* D2Client_pServerIp_6FB75468; // D5468
extern char* D2Client_pGameName_6FBA7898; // 107898

extern int32_t* D2Client_pUnitMouseOverTextPosX_6FB8EA28; // EEA28
extern int32_t* D2Client_pUnitMouseOverTextPosY_6FB8EA2C; // EEA2C

// 1 = right panel, 2 = left panel, 3 = left and right panels
extern int32_t* D2Client_pOpenUIPanelMask_6FBAB9C4; // 10B9C4  

extern int32_t* D2Client_pViewYOffset_6FBAB9B8; // 10B9B8
extern int32_t* D2Client_pViewXOffset_6FBAB9BC; // 10B9BC

// drawn units are offset by this amount. +320 when left ui panel is open, -320 when right ui panel is open, 0 when both or none are open
extern int32_t* D2Client_pViewXOffsetUnits_6FBAB9C8; // 10B9C8 

// not used here, but kept because it could be useful later
extern D2RosterPetStrc* D2Client_pRosterPetRoot_6FBAB9A0; // 10B9A0
extern D2RosterUnitStrc* D2Client_pRosterUnitRoot_6FBAB994; // 10B994

extern int32_t* D2Client_pShowAllGroundItemTexts_6FBBA6DC; // 11A6DC

extern wchar_t** D2Client_pNormalMonsterInfoString_6FBB9FE0; // 119FE0
extern wchar_t** D2Client_pMonsterImmunitiesInfoString_6FBBA4A0; // 11A4A0
extern wchar_t** D2Client_pUniqueMonsterInfoString_6FBBA2A0; // 11A2A0

// UiStates[38]
extern int32_t* D2Client_UIStates_6FBBA6A8; // 11A6A8