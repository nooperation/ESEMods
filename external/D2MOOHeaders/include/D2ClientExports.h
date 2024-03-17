#pragma once

#include <Windows.h>
#include <cstdint>

#include <Drlg/D2DrlgDrlg.h>
#include <D2StatList.h>
#include <D2Inventory.h>
#include <Units/UnitFinds.h>

struct Unicode;
struct D2SkillStrc;

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
extern D2Client_IsLod_6FAAC080_t D2Client_IsLod_6FAAC080; //                                                       | 6FAAC080
extern D2Client_sub_6FB0A950_t D2Client_sub_6FB0A950; //                                                                       | 6FB0A950
extern D2Client_sub_6FB0AA00_t D2Client_sub_6FB0AA00; //                                                                       | 6FB0AA00
extern D2Client_sub_6FB0B580_t D2Client_sub_6FB0B580; //                                                                       | 6FB0B580


// UI-Inv
typedef D2UnitStrc* (__fastcall* D2Client_GetCurrentPlayer_6FB283D0_t)();
typedef bool (__fastcall* D2Client_sub_6FAFE9E0_t)();
typedef int32_t (__fastcall* D2Client_sub_6FB23230_t)(unsigned int a1);
typedef int32_t (__fastcall* D2Client_GetMouseYPos_t)();
typedef int32_t (__fastcall* D2Client_GetMouseXPos_t)();
typedef bool (__fastcall* D2Client_sub_6FAFC0E0_t)();
typedef int16_t (__fastcall* D2Client_GetHotkeyCharCode_6FAD4B60_t)(int32_t a1, int32_t a2);
typedef Unicode* (__fastcall* D2Client_GetHotkeyString_6FAD56B0_t)(int32_t hotkeyId, int32_t useAlternativeHotkey);
typedef int32_t (__fastcall* D2Client_sub_6FAFC130_t)();
typedef Unicode* (__fastcall* D2Client_ColorizeLine_6FB20430_t)(const struct Unicode* sourceStr, char colorCode);
typedef void (__fastcall* D2Client_BuildItemName_6FADD360_t)(D2UnitStrc* pItem, struct Unicode* buff, int maxLen);
typedef Unicode* (__fastcall* D2Client_AddExtraTradeStatLines_6FAE5A40_t)(const struct Unicode* sourceStr, struct Unicode* newOutput);
typedef int32_t (__fastcall* D2Client_sub_6FB57CC0_t)();
typedef void (__fastcall* D2Client_sub_6FAE54B0_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
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
typedef void (__stdcall* D2Client_sub_6FADCFE0_t)(struct Unicode* outBuff, const struct Unicode* format, ...);
typedef D2UnitStrc* (__fastcall* D2Client_sub_6FAE5990_t)(D2InventoryStrc* pInventory, int nSetItemId);
typedef bool (__fastcall* D2Client_GetItemTextPriceMaybe_6FAFB200_t)(D2UnitStrc* pItem, int a2, int* hasChargedSkills, struct Unicode* outBuff, int maxLength);

// UI-Inv-Mod
typedef __int16(__fastcall* D2Client_GetSkillStringId_6FB0A440_t)(int nSkillsTxtIndex, int offset);
typedef void(__fastcall* D2Client_sub_6FAF12C0_t)(D2UnitStrc* pUnit, struct Unicode* outBuff, int outBuffLen);
typedef int(__fastcall* D2Client_sub_6FAF3460_t)(int* statValues, D2C_ItemStats nStatId, struct Unicode* outBuff);
typedef int(__fastcall* D2Client_GetItemPropertyLine_6FAF21C0_t)(D2UnitStrc* pUnit, D2StatListStrc* pStatListEx, int nStatId, int charStatsTxtRecordIndex, int statValueModifier, Unicode* outputBuffer256);

extern D2Client_GetCurrentPlayer_6FB283D0_t D2Client_GetCurrentPlayer_6FB283D0; // 883D0                                       | 6FB283D0
extern D2Client_sub_6FAFE9E0_t D2Client_sub_6FAFE9E0; // 5E9E0                                                                 | 6FAFE9E0
extern D2Client_sub_6FB23230_t D2Client_sub_6FB23230; // 83230                                                                 | 6FB23230
extern D2Client_GetMouseXPos_t D2Client_GetMouseXPos; // B7BC0                                                                 | 6FB57BC0
extern D2Client_GetMouseYPos_t D2Client_GetMouseYPos; // B7BD0                                                                 | 6FB57BD0
extern D2Client_sub_6FAFC0E0_t D2Client_sub_6FAFC0E0; // 5C0E0                                                                 | 6FAFC0E0
extern D2Client_GetHotkeyCharCode_6FAD4B60_t D2Client_GetHotkeyCharCode_6FAD4B60; // 34B60                                     | 6FAD4B60
extern D2Client_GetHotkeyString_6FAD56B0_t D2Client_GetHotkeyString_6FAD56B0; // 356B0                                         | 6FAD56B0
extern D2Client_sub_6FAFC130_t D2Client_sub_6FAFC130; // 5C130                                                                 | 6FAFC130
extern D2Client_ColorizeLine_6FB20430_t D2Client_ColorizeLine_6FB20430; // 80430                                               | 6FB20430
extern D2Client_AddExtraTradeStatLines_6FAE5A40_t D2Client_AddExtraTradeStatLines_6FAE5A40; // 45A40                           | 6FAE5A40
extern D2Client_BuildItemName_6FADD360_t D2Client_BuildItemName_6FADD360; // 3D360                                             | 6FADD360
extern D2Client_sub_6FB57CC0_t D2Client_sub_6FB57CC0; // B7CC0                                                                 | 6FB57CC0
extern D2Client_sub_6FAE54B0_t D2Client_sub_6FAE54B0; // 454B0                                                                 | 6FAE54B0
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
extern D2Client_sub_6FADCFE0_t D2Client_sub_6FADCFE0; // 3CFE0                                                                 | 6FADCFE0
extern D2Client_sub_6FAE5990_t D2Client_sub_6FAE5990; // 45990                                                                 | 6FAE5990
extern D2Client_GetItemTextPriceMaybe_6FAFB200_t D2Client_GetItemTextPriceMaybe_6FAFB200; // 5B200                             | 6FAFB200

extern int32_t* D2Client_pScreenXOffset; // 11A748                                                                             | 6FBBA748
extern int32_t* D2Client_pScreenYOffset; // 11A74C                                                                             | 6FBBA74C
extern int32_t* D2Client_pScreenWidthUI; // D40EC                                                                              | 6FB740EC
extern int32_t* D2Client_pScreenHeightUI; // D40F0                                                                             | 6FB740F0
extern int32_t* D2Client_pDWORD_6FB8CCF8; // ECCF8                                                                             | 6FB8CCF8

extern int32_t* D2Client_pDWORD_6FBB58E0; // 1158E0                                                                            | 6FBB58E0
extern int32_t* D2Client_pDWORD_6FBB58E4; // 1158E4                                                                            | 6FBB58E4
extern int32_t* D2Client_pDWORD_6FBB58EC; // 1158EC                                                                            | 6FBB58EC
extern int32_t* D2Client_pDWORD_6FB7928C; // D928C                                                                             | 6FB7928C
extern int32_t* D2Client_pDWORD_6FB79290; // D9290                                                                             | 6FB79290
extern int32_t* D2Client_pDWORD_6FB79294; // D9294                                                                             | 6FB79294
extern int32_t* D2Client_pDWORD_6FB79298; // D9298                                                                             | 6FB79298
extern int32_t* D2Client_pDWORD_6FB7929C; // D929C                                                                             | 6FB7929C

extern int32_t* D2Client_pLeftSwapWeaponButtonXLeft_6FBB59A8; // 1159A8                                                        | 6FBB59A8
extern int32_t* D2Client_pLeftSwapWeaponButtonXRight_6FBB59AC; // 1159AC                                                       | 6FBB59AC
extern int32_t* D2Client_pLeftSwapWeaponButtonYTop_6FBB59B0; // 1159B0                                                         | 6FBB59B0
extern int32_t* D2Client_pRightSwapWeaponButtonXLeft_6FBB59BC; // 1159BC                                                       | 6FBB59BC
extern int32_t* D2Client_pRightSwapWeaponButtonXRight_6FBB59C0; // 1159C0                                                      | 6FBB59C0
extern int32_t* D2Client_pRightSwapWeaponButtonYTop_6FBB59C4; // 1159C4                                                        | 6FBB59C4

extern D2UnitStrc** D2Client_pItemUnderCursor; // 1158F0                                                                       | 6FBB58F0
                                                                                                                                 
// UI-Inv-Mod
extern D2Client_GetSkillStringId_6FB0A440_t D2Client_GetSkillStringId_6FB0A440; //6A440                                        | 6FB0A440
extern D2Client_sub_6FAF12C0_t D2Client_sub_6FAF12C0; //512C0                                                                  | 6FAF12C0
extern D2Client_sub_6FAF3460_t D2Client_sub_6FAF3460; //53460                                                                  | 6FAF3460
extern D2Client_GetItemPropertyLine_6FAF21C0_t D2Client_GetItemPropertyLine_6FAF21C0; //521C0                                  | 6FAF21C0
                                                                                                                                 
extern int32_t* D2Client_pDWORD_6FB7A438; // DA438                                                                             | 6FB7A438
extern int32_t* D2Client_pDWORD_6FB79B48; // D9B48                                                                             | 6FB79B48
extern int32_t* D2Client_pDWORD_6FB7A4A0; // DA4A0                                                                             | 6FB7A4A0
extern int32_t* D2Client_pDWORD_6FB7A440; // DA440                                                                             | 6FB7A440
extern D2DrlgActStrc** D2Client_pDWORD_6FBA7984; // 6A440                                                                      | 6FBA7984
extern uint16_t* D2Client_pWORD_6FB6FA30; // CFA30                                                                             | 6FB6FA30
