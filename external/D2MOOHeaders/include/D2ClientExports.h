#pragma once

#include <Windows.h>
#include <cstdint>

#include <Drlg/D2DrlgDrlg.h>
#include <D2StatList.h>
#include <D2Inventory.h>
#include <Units/UnitFinds.h>
#include <D2BitManip.h>
#include <PLAYER/PlayerPets.h>
#include <Font.h>

enum D2C_UnitTypes;
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

// 288 bytes
struct GroundItemText
{
    int32_t nLeft;         		// 0x0
    int32_t nTop;               // 0x4
    int32_t nRight;             // 0x8
    int32_t nBottom;          	// 0xC
    D2UnitStrc* pUnit;          // 0x10
    wchar_t wszText[128];       // 0x14
    int colorRgb;               // 0x114
    int nDrawMode;              // 0x118
    int nColor;                 // 0x11C
};


// Unknown stuff, not in use
struct D2WallUnknown2
{
	int32_t xPos;                               // 0
	int32_t yPos;                               // 4
	int32_t unknown8;                           // 8
	int32_t unknown12;                          // 12
	int32_t unknown16;                          // 16
	int32_t unknown20;                          // 20
	D2TileLibraryEntryStrc** tileLibraryEntry;   // 24
};

struct D2WallUnknown
{
	int32_t flags;                       // 0
	int32_t xPos;                        // 4
	int32_t yPos;                        // 8
	union {
		D2UnitStrc* pUnit;
		D2DrlgTileDataStrc* pTileData;
	};
	D2WallUnknown* pNext;                // 16
};

struct D2Wall
{
	int32_t* pSquares;						// 0 | 0
	int32_t unknown4;						// 1 | 4
	int32_t unknown8;						// 2 | 8
	int32_t unknown12;						// 3 | 12
	D2WallUnknown* pWallUnknownShadows;		// 4 | 16
	D2WallUnknown* pWallUnknownBackground;  // 5 | 20
	int32_t unknown24;						// 6 | 24
	D2WallUnknown* pWallUnknownRoofs;		// 7 | 28
	D2WallUnknown* pWallEdgeOfWorldLedges;  // 8 | 32
};

struct D2ViewElement
{
	int32_t xPos;		// 0 | 0
	int32_t yPos;		// 1 | 4
	int32_t unknown8;	// 2 | 8
	D2UnitStrc* unit;	// 3 | 12
	D2DrlgActStrc* pAct; // 4 | 16 UNKNOWN
};

struct D2ViewStruct
{
	int32_t flags;                       //     0 | 0
	int32_t xLeft;                       //     1 | 4
	int32_t yTop;                        //     2 | 8
	int32_t xRight;                      //     3 | 12
	int32_t yBottom;                     //     4 | 16
	int32_t xLeft2;                      //     5 | 20
	int32_t yTop2;                       //     6 | 24
	int32_t xRight2;                     //     7 | 28
	int32_t yBottom2;                    //     8 | 32
	int32_t tileDrawPosX;                //     9 | 36
	int32_t tileDrawPosY;                //    10 | 40
	int32_t gouraudTblX;                 //    11 | 44--
	int32_t gouraudTbly;                 //    12 | 48
	int32_t gouraudTblXVal;              //    13 | 52
	int32_t unknownFlags;                //    14 | 56
	D2ViewElement elements[3000];        //    15 | 60 pEntries? 
	int32_t numElements;                 // 15015 |    0 someCounter  (pRenderer[56 + 20*(someCounter + 1)]
	int32_t gameCoordsPosX;              // 15016 |    tileDrawPosXToGameCoords - 3
	int32_t gameCoordsPosY;              // 15017 |    tileDrawPosYToGameCoords - [15021](widh)
	D2Wall* pWall;                       // 15018 |    pWall[pWallSize]
	int32_t numWallElements;                   // 15019 |    (height+width-1)*(height+width-1)
	int32_t wallWidthPlusHeightMinusOne; // 15020 |    (height+width-1)
	int32_t wallWidth;                   // 15021 |    width
	int32_t wallHeight;                  // 15022 |    height
};


struct D2UnitLightSource
{
	D2C_UnitTypes dwUnitType;  // 0x00
	uint32_t dwUnitId;         // 0x04
	int32_t unknown08;         // 0x08
	int32_t unknownArg2;       // 0x0C
	int32_t posX;              // 0x10
	int32_t posY;              // 0x14
	int32_t unknown18;         // 0x18
	int32_t nLightRadiusMult8; // 0x1C = nLight * 8
	int32_t unknown20;         // 0x20

	int8_t nAlphaMaybe;        // 0x24
	int8_t nRed;               // 0x25
	int8_t nGreen;             // 0x26
	int8_t nBlue;              // 0x27

	D2UnitLightSource* pNext;  // 0x28
	int32_t Zero2C;            // 0x2C
	int32_t* pLightMapData;    // 0x30
};



typedef struct D2DialogChildNode
{
	void* pObj;                  // +0x00 pointer to object with vtable at [pObj]
	struct D2DialogChildNode* pNext; // +0x04 forward link
} D2DialogChildNode;

typedef struct D2DialogLine
{
	wchar_t wszText[120];   // +0x000 text buffer, used as Unicode* in DrawText (see v9 - 256) (120 wchar = 240 bytes)

	int32_t  nLineStep;      // +0x0F0 per-line vertical advance (used as y accumulator) (v9 - 16)
	int32_t  nXPad;          // +0x0F4 horizontal pad/offset within dialog, computed during autosize (v9 - 12)
	int32_t  nTextWidth;     // +0x0F8 pixel width of text (v9 - 8)
	int32_t  unk0FC;         // +0x0FC reserved/unknown (v14[2])

	Font     nFont;          // +0x100 font for this line (v9)
	int32_t  nColor;         // +0x104 color used in draw (v9 + 4)
	int32_t  unk108;         // +0x108 reserved/unknown (v14[5])
	int32_t  bSelectable;    // +0x10C selectable flag (checked in 6FAD7090/6FAD7320, at pDialog+93 + k*68)
} D2DialogLine;

#define D2_UIDIALOG_MAX_LINES 10

struct D2CellFileStrc;

typedef struct D2Dialog
{
	// header
	uint32_t dwCreateTick;       // +0x000 GetTickCount() at creation
	uint32_t unk004;             // +0x004 reserved/unknown (cleared)
	D2CellFileStrc* pCel;        // +0x008 background cel file (menu .cel)
	uint32_t bUseBackground;     // +0x00C if nonzero, draw cel background, else draw solid rect
	uint32_t unk010;             // +0x010 reserved/unknown (cleared)
	uint32_t bAltYMode;          // +0x014 affects Y origin computation in autosize (6FAD7320)
	uint32_t nInitParamA6;       // +0x018 init parameter a6
	uint32_t unk01C;             // +0x01C reserved/unknown
	uint32_t unk020;             // +0x020 reserved/unknown

	int32_t  nCenterX;           // +0x024 used by autosize as horizontal center
	int32_t  nCenterY;           // +0x028 used by autosize as vertical anchor
	int32_t  nLeft;              // +0x02C dialog left X (used in draw; updated by autosize)
	int32_t  nTop;               // +0x030 dialog top Y (used in draw; updated by autosize)
	int32_t  nWidth;             // +0x034 dialog width (cel size or autosize result)
	int32_t  nHeight;            // +0x038 dialog height (cel size or autosize result)

	uint32_t unk03C;             // +0x03C reserved/unknown
	uint32_t unk040;             // +0x040 reserved/unknown
	int32_t  nSelectedIndex;     // +0x044 selected line index (default -1)
	int32_t  nHoverIndex;        // +0x048 reserved/unknown (default -1)
	uint32_t unk04C;             // +0x04C reserved/unknown

	int32_t  nNumLines;          // +0x050 number of line entries
	uint32_t nDrawCounter;       // +0x054 increments each draw (6FAD6EB0)
	uint32_t bAutoSize;          // +0x058 must be TRUE for autosize routine (6FAD7320)
	uint32_t nHighlightMode;     // +0x05C 1=color highlight, 2=animated arrows (6FAD6EB0)

	uint32_t nInitParamA3;       // +0x060 init parameter a3
	uint32_t nInitParamA4;       // +0x064 init parameter a4

	D2DialogLine Lines[D2_UIDIALOG_MAX_LINES]; // +0x068 .. +0xB07

	// tail
	D2DialogChildNode* pDrawChain;	// +0xB08 list of child draw nodes (each node: [0]=pObj, [1]=pNext)
	struct D2Dialog* pNext;			// +0xB0C next dialog in global list (set to previous head on creation)
} D2Dialog;

#pragma pack(pop)

void InitD2ClientExports();

typedef void(__fastcall* D2Client_DrawTextCentered_6FACFCD0_t)(int nX, int nY, int maxWidthMaybe, const Unicode* text, int nColor);

typedef D2UnitStrc* (__fastcall* D2Client_sub_6FB0A950_t)(D2UnitStrc* pTarget);
typedef D2UnitStrc* (__fastcall* D2Client_sub_6FB0AA00_t)(D2UnitStrc* pTarget);
typedef int32_t(__fastcall* D2Client_sub_6FB0B580_t)();
typedef void(__fastcall* D2Client_sub_6FB0B2C0_t)(D2UnitStrc* pUnit, int32_t* pUnknown1, int32_t* pUnknown2, int32_t* pColor, int32_t unknown3, int32_t unknown4, D2SkillStrc* pSkill, int32_t unknown5, D2UnitStrc* unknown6, int32_t unknown7);
typedef void(__fastcall* D2Client_sub_6FB0B6F0_t)(D2UnitStrc* pUnit, int32_t* pUnknown1, int32_t* pUnknown2, int32_t* pColor, D2UnitStrc* unknown3, D2SkillStrc* pSkill);
typedef void(__fastcall* D2Client_sub_6FB0BB10_t)(D2UnitStrc* pUnit, int32_t* pUnknown1, int32_t* pUnknown2, int32_t* pColor);
typedef int32_t(__fastcall* D2Client_IsExpansion_6FAAC080_t)();

extern D2Client_DrawTextCentered_6FACFCD0_t D2Client_DrawTextCentered_6FACFCD0; //                                             | 6FACFCD0
extern D2Client_sub_6FB0B2C0_t D2Client_sub_6FB0B2C0; //                                                                       | 6FB0B2C0
extern D2Client_sub_6FB0B6F0_t D2Client_sub_6FB0B6F0; //                                                                       | 6FB0B6F0
extern D2Client_sub_6FB0BB10_t D2Client_sub_6FB0BB10; //                                                                       | 6FB0BB10
extern D2Client_IsExpansion_6FAAC080_t D2Client_IsExpansion_6FAAC080; //                                                                   | 6FAAC080
extern D2Client_sub_6FB0A950_t D2Client_sub_6FB0A950; //                                                                       | 6FB0A950
extern D2Client_sub_6FB0AA00_t D2Client_sub_6FB0AA00; //                                                                       | 6FB0AA00
extern D2Client_sub_6FB0B580_t D2Client_sub_6FB0B580; //                                                                       | 6FB0B580


// UI-Inv
typedef D2ActiveRoomStrc* (__fastcall* D2Client_GetCurrentRoom_6FB29370_t)();
typedef D2UnitStrc* (__fastcall* D2Client_GetCurrentPlayer_6FB283D0_t)();
typedef bool(__fastcall* D2Client_IsBeltOpen_6FAFE9E0_t)();
typedef int32_t(__fastcall* D2Client_IsUiOpen_6FB23230_t)(D2C_UIvars uiId);
typedef int32_t(__fastcall* D2Client_UI_GetMouseYPos_6FB57BD0_t)();
typedef int32_t(__fastcall* D2Client_UI_GetMouseXPos_6FB57BC0_t)();
typedef bool(__fastcall* D2Client_sub_6FAFC0E0_t)();
typedef int16_t(__fastcall* D2Client_GetHotkeyCharCode_6FAD4B60_t)(int32_t a1, int32_t a2);
typedef Unicode* (__fastcall* D2Client_GetHotkeyString_6FAD56B0_t)(int32_t hotkeyId, int32_t useAlternativeHotkey);
typedef int32_t(__fastcall* D2Client_IsGambling_6FAFC130_t)();
typedef Unicode* (__fastcall* D2Client_ColorizeLine_6FB20430_t)(const struct Unicode* sourceStr, char colorCode);
typedef void(__fastcall* D2Client_BuildItemName_6FADD360_t)(D2UnitStrc* pItem, struct Unicode* buff, int maxLen);
typedef Unicode* (__fastcall* D2Client_AddExtraTradeStatLines_6FAE5A40_t)(const struct Unicode* sourceStr, struct Unicode* newOutput);
typedef int32_t(__fastcall* D2Client_sub_6FB57CC0_t)();
typedef void(__fastcall* D2Client_GetItemTextLineBookQuantity_6FAE54B0_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void(__fastcall* D2Client_GetItemTextLineDurability_6FAE4060_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void(__fastcall* D2Client_GetItemTextLineRuneGemStats_6FAF1480_t)(D2UnitStrc* pItem, struct Unicode* outBuff, int maxLen);
typedef void(__fastcall* D2Client_GetItemTextLineDamage_6FAE43D0_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void(__fastcall* D2Client_GetItemTextLineAttackSpeed_6FAE5570_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void(__fastcall* D2Client_GetItemTextLineUnknownA_6FAE5040_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void(__fastcall* D2Client_GetItemTextLineBlockChance_6FAE4EE0_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void(__fastcall* D2Client_GetItemTextLineDefense_6FAE51D0_t)(D2UnitStrc* pUnit, D2UnitStrc* pItem, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef void(__fastcall* D2Client_GetItemTextLineProperties_6FAF3160_t)(D2UnitStrc* pItem, struct Unicode* outBuff, int maxLen, int bFlag, const struct Unicode* existingContents);
typedef void(__fastcall* D2Client_GetItemTextLinePropertiesInternal_6FAF19C0_t)(D2UnitStrc* pUnit, struct Unicode* outBuff, int outBuffMaxLen, int bUnknownFlag1, int unitState, int nUnitState, int nUnitFlags, int bUnknownFlag2);
typedef void(__fastcall* D2Client_GetItemTextLineQuantity_6FAE5710_t)(D2UnitStrc* pUnit, struct Unicode* pBuffer, D2ItemsTxt* pItemTxtRecord);
typedef D2SetsTxt* (__fastcall* D2Client_sub_6FAE5C50_t)(int32_t setsTxtIndex);
typedef D2SetItemsTxt* (__fastcall* D2Client_GetSetItemsTxt_6FAE5C80_t)(int32_t setsTxtIndex);
typedef void(__fastcall* D2Client_GetItemTextLineLevelRequirement_6FAE41B0_t)(struct Unicode* outBuff, int levelRequirement);
typedef void(__fastcall* D2Client_GetItemTextStrRequirement_6FAE4250_t)(struct Unicode* outBuff, D2ItemsTxt* pItemTxtRecord, int requiredStr);
typedef void(__fastcall* D2Client_GetItemTextDexRequirement_6FAE4310_t)(struct Unicode* outBuff, D2ItemsTxt* pItemTxtRecord, int requiredDex);
typedef void(__fastcall* D2Client_GetItemTextSocketed_6FAE3EE0_t)(D2UnitStrc* pItem, struct Unicode* outBuff);
typedef void(__fastcall* D2Client_GetItemTextSet_6FAF32B0_t)(D2UnitStrc* pUnit, D2UnitStrc* pItem, struct Unicode* outBuff, int maxLength);
typedef void(__fastcall* D2Client_GetItemTextSetB_6FAF33C0_t)(D2UnitStrc* pUnit, D2UnitStrc* pItem, struct Unicode* outBuff, int maxLength);
typedef void(__stdcall* D2Client_FormatName_6FADCFE0_t)(struct Unicode* outBuff, const struct Unicode* format, ...);
typedef void(__stdcall* D2Client_ReplaceNameFormatToken_6FADCF10_t)(struct Unicode* format, int32_t tokenIndex, const struct Unicode* replacement);
typedef D2UnitStrc* (__fastcall* D2Client_sub_6FAE5990_t)(D2InventoryStrc* pInventory, int nSetItemId);
typedef bool(__fastcall* D2Client_GetItemTextLinePrice_6FAFB200_t)(D2UnitStrc* pItem, int a2, int* pTransactionCost, struct Unicode* outBuff, int maxLength);

// UI-Inv-Mod
typedef __int16(__fastcall* D2Client_GetSkillStringId_6FB0A440_t)(int nSkillsTxtIndex, int offset);
typedef void(__fastcall* D2Client_GetItemTextLineDamageToUndead_6FAF12C0_t)(D2UnitStrc* pUnit, struct Unicode* outBuff, int outBuffLen);
typedef int(__fastcall* D2Client_sub_6FAF3460_t)(int* statValues, D2C_ItemStats nStatId, struct Unicode* outBuff);
typedef int(__fastcall* D2Client_GetItemPropertyLine_6FAF21C0_t)(D2UnitStrc* pUnit, D2StatListStrc* pStatListEx, int nStatId, int charStatsTxtRecordIndex, int statValueModifier, Unicode* outputBuffer256);
typedef void(__fastcall* D2Client_GetItemDamage_6FAE4C60_t)(D2UnitStrc* pCurrentPlayer, D2UnitStrc* pItem, D2C_ItemStats minDamageStat, D2C_ItemStats maxDamageStat, int32_t* outMinDamage, int32_t* outMaxDamage, int32_t* isDamageModified); // 44C60
typedef void(__fastcall* D2Client_sub_6FAF13C0_t)(D2UnitStrc* pItem, D2GemsTxt* pMods, int32_t nPropSet, struct Unicode* outBuff, int maxLen, struct Unicode* existingContents);

typedef D2UnitStrc* (__fastcall* D2Client_FindUnit_6FB269F0_t)(int32_t unitId, int32_t unitType); // 869F0
typedef int8_t(__fastcall* D2Client_GetCurrentDifficulty_6FAAC090_t)(); // C090
typedef int32_t(__fastcall* D2Client_IsVendorRepairActive_6FAEB930_t)(); // 4B930

// UI_GroundItem stuff
typedef D2C_GlobalUiStates(__fastcall* D2Client_UI_GetGlobalUiState_6FAB5750_t)(); // 15750
typedef int32_t(__fastcall* D2Client_GetAdjustedViewOffsetX_6FAB5890_t)(); // 15890
typedef int32_t(__fastcall* D2Client_GetAdjustedViewOffsetY_6FAB58A0_t)(); // 158A0
typedef int32_t(__fastcall* D2Client_GetMonsterLifeColor_6FB20670_t)(D2UnitStrc* pUnit); // 80670
typedef const Unicode* (__fastcall* D2Client_GetUnitName_6FB297F0_t)(D2UnitStrc* pUnit); // 897F0
typedef int32_t(__fastcall* D2Client_GetPlayerNameAndColor_6FB21680_t)(D2UnitStrc* pUnit, int32_t* pOutColorBg, int32_t* pOutColor, struct Unicode* outBuff, int32_t outBuffLen); // 81680
typedef char* (__fastcall* D2Client_Roster_GetPortalOwnerName_6FAB0D00_t)(int32_t unitId); // 10D00
typedef void* (__fastcall* D2Client_Roster_GetPetUNK24_6FAB18D0_t)(uint32_t dwUnitId); // 118D0
typedef int32_t(__fastcall* D2Client_Roster_GetPetByUnitIdType_6FAB1920_t)(D2UnitStrc* pOwner, D2PetTypes petType, int bIgnoreDrawnIcon); // 11920
typedef int32_t(__fastcall* D2Client_Roster_GetPetOwnerId_6FAB1B00_t)(int32_t unitId); // 11B00
typedef char* (__fastcall* D2Client_Roster_GetUnitNameFromId_6FAB0BC0_t)(int32_t unitId); // 10BC0
typedef int32_t(__fastcall* D2Client_Roster_GetUnitLife_6FAB1460_t)(int32_t unitId); // 11460
typedef D2RosterInfoStrc** (__fastcall* D2Client_Roster_GetUnitRosterInfoFromId_6FAB0D80_t)(int32_t unitId); // 10D80
typedef int32_t(__fastcall* D2Client_CheckPartyMemberFlags_6FB4B900_t)(int unitIdA, int unitIdB, int32_t partyFlag); // AB900
typedef int32_t(__fastcall* D2Client_AreUnitsHostile_6FAB07D0_t)(int unitIdA, int unitIdB); // 107D0
typedef D2MonStats2Txt* (__fastcall* D2Client_GetMonStats2TxtFromClassId_6FB247F0_t)(int classId); // 847F0
typedef D2MonStatsTxt* (__fastcall* D2Client_GetMonStatsTxtFromClassId_6FAAE570_t)(int classId); // E570
typedef char* (__fastcall* D2Client_GetObjectOwnerName_6FB48550_t)(D2UnitStrc* pUnit); // A8550
typedef BOOL(__fastcall* D2Client_CheckMonsterTypeFlag_6FB449D0_t)(D2UnitStrc* pUnit, unsigned __int16 monsterTypeFlag); // A49D0
typedef BOOL(__fastcall* D2Client_IsMonsterUnique_6FB40D00_t)(D2UnitStrc* pUnit); // A0D00
typedef BOOL(__fastcall* D2Client_IsMonsterChampion_6FB40CC0_t)(D2UnitStrc* pUnit); // A0CC0
typedef BOOL(__fastcall* D2Client_IsMonsterGhostly_6FB40CE0_t)(D2UnitStrc* pUnit); // A0CE0
typedef BOOL(__fastcall* D2Client_IsMonsterMinion_6FB40D20_t)(D2UnitStrc* pUnit); // A0D20
typedef BOOL(__fastcall* D2Client_IsMonsterSuperUnique_6FB40D40_t)(D2UnitStrc* pUnit); // A0D40
typedef BOOL(__fastcall* D2Client_GetScreenOffsetDimensionsTBD_6FB24690_t)(int* dimensionsOrSomething); // 84690
typedef BOOL(__fastcall* D2Client_UpdateUniqueMonsterInfoString_6FB20600_t)(D2UnitStrc* pUnit, int32_t stringIndex); // 80600
typedef void(__fastcall* D2Client_UpdateNormalMonsterInfoString_6FB205D0_t)(const  Unicode* newMonsterInfo, int xAdjust); // 805D0
typedef void(__fastcall* D2Client_MonsterResistancesInfoString_6FB21570_t)(const D2UnitStrc* pUnit); // 81570
typedef int(__fastcall* D2Client_IsActiveNpcDialogOpen_6FAFBB50_t)(int32_t** pActiveNpcId); // 5BB50
typedef BOOL(__fastcall* D2Client_IsActiveNpcTalking_6FB1EE90_t)(); // 7EE90
typedef int(__stdcall* D2Client_10002_t)(int32_t unused, int32_t questIndex); // 18EF0

typedef D2UnitStrc* (__fastcall* D2Client_GetSelectedUnit_6FAB5A20_t)(); // 15A20
typedef int(__fastcall* D2Client_sub_6FB09D80_t)(int* drawModeMaybe, int* xPosSomething, int* yPosSomething, int* a4, int a5, int a6, int a7); // 69D80
typedef void(__fastcall* D2Client_sub_6FAB5A90_t)(D2UnitStrc* pUnit); // 15A90
typedef void(__fastcall* D2Client_ClearUnitSelection_6FAB5D40_t)(); // 15D40

extern D2Client_GetCurrentRoom_6FB29370_t D2Client_GetCurrentRoom_6FB29370; // 89370                                       | 6FB29370
extern D2Client_GetCurrentPlayer_6FB283D0_t D2Client_GetCurrentPlayer_6FB283D0; // 883D0                                       | 6FB283D0
extern D2Client_IsBeltOpen_6FAFE9E0_t D2Client_IsBeltOpen_6FAFE9E0; // 5E9E0                                                   | 6FAFE9E0
extern D2Client_IsUiOpen_6FB23230_t D2Client_IsUiOpen_6FB23230; // 83230                                                       | 6FB23230
extern D2Client_UI_GetMouseXPos_6FB57BC0_t D2Client_UI_GetMouseXPos_6FB57BC0; // B7BC0                                                                 | 6FB57BC0
extern D2Client_UI_GetMouseYPos_6FB57BD0_t D2Client_UI_GetMouseYPos_6FB57BD0; // B7BD0                                                                 | 6FB57BD0
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
extern D2Client_UI_GetGlobalUiState_6FAB5750_t D2Client_UI_GetGlobalUiState_6FAB5750; // 15750                                   | 6FAB5750
extern D2Client_GetAdjustedViewOffsetX_6FAB5890_t D2Client_GetAdjustedViewOffsetX_6FAB5890; // 15890                                           | 6FAB5890
extern D2Client_GetAdjustedViewOffsetY_6FAB58A0_t D2Client_GetAdjustedViewOffsetY_6FAB58A0; // 158A0                                           | 6FAB58A0
extern D2Client_GetMonsterLifeColor_6FB20670_t D2Client_GetMonsterLifeColor_6FB20670; // 80670                                 | 6FB20670
extern D2Client_GetUnitName_6FB297F0_t D2Client_GetUnitName_6FB297F0; // 897F0                                                 | 6FB297F0
extern D2Client_GetPlayerNameAndColor_6FB21680_t D2Client_GetPlayerNameAndColor_6FB21680; // 81680                             | 6FB21680
extern D2Client_Roster_GetPortalOwnerName_6FAB0D00_t D2Client_Roster_GetPortalOwnerName_6FAB0D00; // 10D00                     | 6FAB0D00
extern D2Client_Roster_GetPetUNK24_6FAB18D0_t D2Client_Roster_GetPetUNK24_6FAB18D0; // 118D0                     | 6FAB18D0
extern D2Client_Roster_GetPetByUnitIdType_6FAB1920_t D2Client_Roster_GetPetByUnitIdType_6FAB1920; // 11920                     | 6FAB1920
extern D2Client_Roster_GetPetOwnerId_6FAB1B00_t D2Client_Roster_GetPetOwnerId_6FAB1B00; // 11B00                               | 6FAB1B00
extern D2Client_Roster_GetUnitNameFromId_6FAB0BC0_t D2Client_Roster_GetUnitNameFromId_6FAB0BC0; // 10BC0                       | 6FAB0BC0
extern D2Client_Roster_GetUnitLife_6FAB1460_t D2Client_Roster_GetUnitLife_6FAB1460; // 11460                                   | 6FAB1460
extern D2Client_Roster_GetUnitRosterInfoFromId_6FAB0D80_t D2Client_Roster_GetUnitRosterInfoFromId_6FAB0D80; // 10D80           | 6FAB0D80
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
extern D2Client_GetSelectedUnit_6FAB5A20_t D2Client_GetSelectedUnit_6FAB5A20; // 15A20                                         | 6FAB5A20
extern D2Client_sub_6FB09D80_t D2Client_sub_6FB09D80; // 69D80                                                                 | 6FB09D80
extern D2Client_sub_6FAB5A90_t D2Client_sub_6FAB5A90; // 15A90                                                                 | 6FAB5A90
extern D2Client_ClearUnitSelection_6FAB5D40_t D2Client_ClearUnitSelection_6FAB5D40; // 15D40                                   | 6FAB5D40

extern int32_t* D2Client_pScreenXOffset_6FBBA748; // 11A748                                                                    | 6FBBA748
extern int32_t* D2Client_pScreenYOffset_6FBBA74C; // 11A74C                                                                    | 6FBBA74C
extern int32_t* D2Client_pResolutionWidth_6FB740EC; // D40EC                                                                     | 6FB740EC
extern int32_t* D2Client_pResolutionHeight_6FB740F0; // D40F0                                                                    | 6FB740F0
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

extern GroundItemText* D2Client_pGroundItemsToShow_6FBB7028; // 117028                                                        | 6FBB7028
extern int32_t* D2Client_pNumGroundItemsToShow_6FBB9428; // 119428                                                             | 6FBB9428
extern int32_t* D2Client_pSelectedUnitId_6FBAB9D0; // 10B9D0                                                                   | 6FBAB9D0
extern int32_t* D2Client_pSelectedUnitType_6FBAB9CC; // 10B9CC                                                                 | 6FBAB9CC
extern int32_t* D2Client_pSelectedUnitIsSelected_6FBAB9E8; // 10B9E8                                                           | 6FBAB9E8
extern int32_t* D2Client_pIsUnitSelectionDisabled_6FBAB9EC; // 10B9EC                                                          | 6FBAB9EC

// MAP stuff
extern D2UnitStrc** D2Client_pOwner_6FBBC200; //	11C200																	   | 6FBBC200

// UI-Inv-Mod
extern D2Client_GetSkillStringId_6FB0A440_t D2Client_GetSkillStringId_6FB0A440; //6A440                                        | 6FB0A440
extern D2Client_GetItemTextLineDamageToUndead_6FAF12C0_t D2Client_GetItemTextLineDamageToUndead_6FAF12C0; //512C0              | 6FAF12C0
extern D2Client_sub_6FAF3460_t D2Client_sub_6FAF3460; //53460                                                                  | 6FAF3460
extern D2Client_GetItemPropertyLine_6FAF21C0_t D2Client_GetItemPropertyLine_6FAF21C0; //521C0                                  | 6FAF21C0
extern D2Client_GetItemDamage_6FAE4C60_t D2Client_GetItemDamage_6FAE4C60; // 44C60                                             | 6FAE4C60
extern D2Client_sub_6FAF13C0_t D2Client_sub_6FAF13C0; // 513C0                                                                 | 6FAF13C0
extern D2Client_FindUnit_6FB269F0_t D2Client_FindUnit_6FB269F0; // 869F0                                                       | 6FB269F0
extern D2Client_GetCurrentDifficulty_6FAAC090_t D2Client_GetCurrentDifficulty_6FAAC090; // C090                                | 6FAAC090
extern D2Client_IsVendorRepairActive_6FAEB930_t D2Client_IsVendorRepairActive_6FAEB930; // 4B930                               | 6FAEB930

extern int32_t* D2Client_pDWORD_6FB7A438; // DA438                                                                             | 6FB7A438
extern int32_t* D2Client_pDWORD_6FB79B48; // D9B48                                                                             | 6FB79B48
extern int32_t* D2Client_pElixirDescCount_6FB7A4A0; // DA4A0                                                                   | 6FB7A4A0
extern ElixirDesc_6FB7A440* D2Client_pElixirDescs_6FB7A440; // DA440                                                           | 6FB7A440
extern D2DrlgActStrc** D2Client_pCurrentDrlgAct_6FBA7984; // current act? // 6A440                                             | 6FBA7984
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
extern D2C_GlobalUiStates* D2Client_UI_pGlobalUiState_6FBAB9C4; // 10B9C4  

extern int32_t* D2Client_pViewYOffset_6FBAB9B8; // 10B9B8
extern int32_t* D2Client_pViewXOffset_6FBAB9BC; // 10B9BC

// drawn units are offset by this amount. +320 when left ui panel is open, -320 when right ui panel is open, 0 when both or none are open
extern int32_t* D2Client_pViewXOffsetUnits_6FBAB9C8; // 10B9C8 

extern int32_t* D2Client_pShowAllGroundItemTexts_6FBBA6DC; // 11A6DC

extern wchar_t* D2Client_pNormalMonsterInfoString256_6FBB9FE0; // 119FE0
extern wchar_t* D2Client_pMonsterImmunitiesInfoString256_6FBBA4A0; // 11A4A0
extern wchar_t* D2Client_pUniqueMonsterInfoString256_6FBBA2A0; // 11A2A0

// UiStates[38]
extern int32_t* D2Client_UI_pUIStates_6FBBA6A8; // 11A6A8



// Belt Stuff
typedef void(__fastcall* D2Client_OpenBeltUi_6FB01C20_t)(); // 61C20

extern D2Client_OpenBeltUi_6FB01C20_t D2Client_OpenBeltUi_6FB01C20; // 61C20                                   | 6FB01C20

extern BOOL* D2Client_pIsBeltUiOpen_6FBB5EA4; // 115EA4
extern int32_t* D2Client_pBeltType_6FB7CD70; // DCD70


//////////////////////
// Roster stuff
//////////////////////

#pragma pack(push, 1)
struct D2RosterParty
{
	int32_t partyId;
	D2RosterUnitStrc* pRoster;
	D2RosterParty* pNext;
};
#pragma pack(pop)

extern D2RosterPetStrc* D2Client_pRosterPetRoot_6FBAB9A0; // 10B9A0
extern D2RosterUnitStrc* D2Client_pRosterUnitRoot_6FBAB994; // 10B994
extern D2RosterParty* D2Client_pRosterPartyRoot_6FBAB99C; //

// extern uint32_t D2Client_Msg_pNumBytesSentViaClientSend_6FBC1AF4;
// extern uint32_t D2Client_Msg_pNumGameMessagesSentViaClientSend_6FBC1AFC;
// extern uint32_t D2Client_Msg_pLastSendGameMessageTickCount_6FBA7BF8;
// extern uint32_t* D2Client_Msg_pLastSentGameMessage512_6FBA79F8;

// Forward declarations for UI stuff
struct D2CellFileStrc;
struct QuestNameOverride;
enum D2C_UIvars;
enum D2C_UiStates;
enum Font;

// UI stuff - Data types
typedef D2CellFileStrc** D2Client_UI_pCellFileLevelTitle_6FBBA1E8_t;
typedef uint32_t* D2Client_UI_pCurrentLevelId_6FBBA784_t;
typedef uint32_t* D2Client_UI_pNewLevelTickCount120_6FBBA788_t;
typedef QuestNameOverride* D2Client_Quest_pQuestNameOverrides_6FB8EC54_t;
typedef int32_t* D2Client_Quest_pQuestNameOverridesCount_6FB8EC70_t;
typedef int32_t* D2Client_pMonsterImmunitiesInfoStringColor_6FBBA6A0_t;
typedef int32_t* D2Client_pNormalMonsterInfoStringColor_6FBBA1E0_t;
typedef void* D2Client_UI_pGoldTransferDialog_6FBB9FC4_t;
typedef int32_t* D2Client_UI_pUIStatesIncompatibleWithHelpScreen_6FBBA6A8_t;

// UI stuff - Function types
typedef void(__fastcall* D2Client_UI_DrawEscapeMenu_6FB088B0_t)();
typedef void(__fastcall* D2Client_UI_DrawConfigMenu_6FAFC620_t)();
typedef void(__fastcall* D2Client_UI_DrawDurabilityWarning_6FAFEE70_t)();
typedef void(__fastcall* D2Client_UI_DrawAmmoDurability_6FAFEA40_t)();
typedef void(__fastcall* D2Client_UI_DrawAutomap_6FACDCB0_t)();
typedef void(__fastcall* D2Client_UI_UpdateHirePartyIconsVisibility_6FADB890_t)();
typedef void(__fastcall* D2Client_UI_DrawPartyMemberIcons_6FADAB00_t)();
typedef void(__fastcall* D2Client_UI_DrawMercInventoryScreen_6FAED5D0_t)();
typedef void(__fastcall* D2Client_UI_DrawRecipeScrollScreen_6FAEE9C0_t)();
typedef void(__fastcall* D2Client_UI_DrawQuestScreen_6FB042D0_t)();
typedef void(__fastcall* D2Client_UI_DrawInventoryScreen_6FADEAC0_t)();
typedef void(__fastcall* D2Client_UI_DrawPlayerTradeButtonHoverText_6FB1F390_t)();
typedef void(__fastcall* D2Client_UI_DrawProgressiveStates_6FB21A00_t)();
typedef void(__fastcall* D2Client_UI_DrawSkillsTree_6FB16C00_t)();
typedef void(__fastcall* D2Client_UI_DrawCharacterStatsScreen_6FACFD60_t)();
typedef void(__fastcall* D2Client_UI_DrawPartyScreen_6FB01F10_t)();
typedef void(__fastcall* D2Client_UI_DrawDialog_6FAD6EB0_t)(D2Dialog* pDialog);
typedef void(__fastcall* D2Client_UI_DrawInifussScrollPanel_6FB1E990_t)();
typedef void(__fastcall* D2Client_UI_DrawWaypointScreen_6FB25C70_t)();
typedef void(__fastcall* D2Client_UI_DrawHelpScreenBorder_6FAD81F0_t)();
typedef void(__fastcall* D2Client_UI_DrawHelpScreenBackground_6FAD82E0_t)();
typedef void(__fastcall* D2Client_UI_DrawBackground_6FAFF480_t)();
typedef void(__fastcall* D2Client_UI_DrawMiniSkills_6FB19660_t)();
typedef void(__fastcall* D2Client_UI_DrawBeltRows_6FB01C20_t)();
typedef void(__fastcall* D2Client_UI_RefreshUIState_6FAEEC00_t)();
typedef void(__fastcall* D2Client_UI_DrawHelpButton_6FADA350_t)();
typedef void(__fastcall* D2Client_UI_DrawNewStatsButton_6FAEF360_t)();
typedef void(__fastcall* D2Client_UI_DrawStatsButton_6FAEF2A0_t)();
typedef void(__fastcall* D2Client_UI_DrawNewSkillsButton_6FAEF730_t)();
typedef void(__fastcall* D2Client_UI_DrawSkillsButton_6FAEF670_t)();
typedef void(__fastcall* D2Client_UI_DrawQuestLogButton_6FB065F0_t)();
typedef void(__fastcall* D2Client_UI_DrawLifeAndManaOrbText_6FAFF0B0_t)();
typedef void(__fastcall* D2Client_UI_DrawMiniPanel_6FB08DE0_t)();
typedef void(__fastcall* D2Client_UI_DrawChatBox_6FAD2100_t)();
typedef void(__fastcall* D2Client_ClearItemUnderCursorInfo_6FAE8F10_t)();
typedef void(__fastcall* D2Client_UI_DrawHelpScreen_6FAD8310_t)();
typedef int(__fastcall* D2Client_GetGameType_6FAABFF0_t)();
typedef void(__fastcall* D2Client_UI_DrawNpcMenu_6FAF6070_t)();
typedef void(__fastcall* D2Client_UI_DrawAnvilScreen_6FB25320_t)();
typedef void(__fastcall* D2Client_UI_DrawHostilePlayerIndicator_6FAFE650_t)();
typedef void(__fastcall* D2Client_UI_DrawMercFloatingText_6FB21970_t)();
typedef bool(__fastcall* D2Client_Roster_IsSortingByKillCount_6FAA6990_t)();
typedef void(__fastcall* D2Client_UI_DrawDeathScreen_6FB22320_t)();
typedef void(__fastcall* D2Client_UI_DrawLordOfTerrorDiedMessage_6FABA4A0_t)();
typedef int(__fastcall* D2Client_UI_UpdateMercFloatingText_6FB20590_t)(const Unicode* text, int textPosX, int textPosY, int a4);
typedef void(__fastcall* D2Client_UI_UpdateRosterHealthColors_6FADA970_t)(bool bForceUpdate);
typedef void(__fastcall* D2Client_Archive_FreeCellFile_6FAA1140_t)(D2CellFileStrc* pCellFile);
typedef void(__fastcall* D2Client_UI_SetUIState_6FB23260_t)(D2C_UIvars nUIId, D2C_UiStates nUIState, int bAdjustCursor);
typedef void(__fastcall* D2Client_Unit_EnumUnits_6FB29700_t)(void(__fastcall* callback)(D2UnitStrc* pUnit));
typedef void(__fastcall* D2Client_UI_EnumUnitsCallback_6FB22560_t)(D2UnitStrc* pUnit);
typedef void(__fastcall* D2Client_UI_DrawNPCScrollingDialog_6FB1BA00_t)(D2ViewStruct* pRenderer);
typedef void(__fastcall* D2Client_UI_DrawText_6FB22280_t)(const Unicode* text, Font font, int nY, int nColor);
typedef D2RosterUnitStrc* (__fastcall* D2Client_Roster_FindUnitByIdOrCorpseId_6FAAFD60_t)(int32_t dwUnitId);
typedef uint32_t(__fastcall* D2Client_Roster_GetKillCount_6FAAFD30_t)(D2RosterUnitStrc* pRosterUnit);
typedef D2CellFileStrc* (__fastcall* D2Client_LoadCelFile_6FAA1000_t)(char* a1, int bAllowCompressed);

// UI stuff - Data extern declarations
extern D2CellFileStrc** D2Client_UI_pCellFileLevelTitle_6FBBA1E8; // 11A1E8                                    | 6FBBA1E8
extern uint32_t* D2Client_UI_pCurrentLevelId_6FBBA784; // 11A784                                                | 6FBBA784
extern uint32_t* D2Client_UI_pNewLevelTickCount120_6FBBA788; // 11A788                                         | 6FBBA788
extern QuestNameOverride* D2Client_Quest_pQuestNameOverrides_6FB8EC54; // EEC54                                | 6FB8EC54
extern int32_t* D2Client_Quest_pQuestNameOverridesCount_6FB8EC70; // EEC70                                     | 6FB8EC70
extern int32_t* D2Client_pMonsterImmunitiesInfoStringColor_6FBBA6A0; // 11A6A0                                 | 6FBBA6A0
extern int32_t* D2Client_pNormalMonsterInfoStringColor_6FBBA1E0; // 11A1E0                                     | 6FBBA1E0
extern D2Dialog** D2Client_UI_pGoldTransferDialog_6FBB9FC4; // 119FC4                                          | 6FBB9FC4
extern int32_t* D2Client_UI_pUIStatesIncompatibleWithHelpScreen_6FBBA6A8; // 11A6A8                            | 6FBBA6A8

// UI stuff - Function extern declarations
extern D2Client_UI_DrawEscapeMenu_6FB088B0_t D2Client_UI_DrawEscapeMenu_6FB088B0; // 688B0                     | 6FB088B0
extern D2Client_UI_DrawConfigMenu_6FAFC620_t D2Client_UI_DrawConfigMenu_6FAFC620; // 5C620                     | 6FAFC620
extern D2Client_UI_DrawDurabilityWarning_6FAFEE70_t D2Client_UI_DrawDurabilityWarning_6FAFEE70; // 5EE70       | 6FAFEE70
extern D2Client_UI_DrawAmmoDurability_6FAFEA40_t D2Client_UI_DrawAmmoDurability_6FAFEA40; // 5EA40             | 6FAFEA40
extern D2Client_UI_DrawAutomap_6FACDCB0_t D2Client_UI_DrawAutomap_6FACDCB0; // 2DCB0                           | 6FACDCB0
extern D2Client_UI_UpdateHirePartyIconsVisibility_6FADB890_t D2Client_UI_UpdateHirePartyIconsVisibility_6FADB890; // 3B890 | 6FADB890
extern D2Client_UI_DrawPartyMemberIcons_6FADAB00_t D2Client_UI_DrawPartyMemberIcons_6FADAB00; // 3AB00         | 6FADAB00
extern D2Client_UI_DrawMercInventoryScreen_6FAED5D0_t D2Client_UI_DrawMercInventoryScreen_6FAED5D0; // 4D5D0   | 6FAED5D0
extern D2Client_UI_DrawRecipeScrollScreen_6FAEE9C0_t D2Client_UI_DrawRecipeScrollScreen_6FAEE9C0; // 4E9C0     | 6FAEE9C0
extern D2Client_UI_DrawQuestScreen_6FB042D0_t D2Client_UI_DrawQuestScreen_6FB042D0; // 642D0                   | 6FB042D0
extern D2Client_UI_DrawInventoryScreen_6FADEAC0_t D2Client_UI_DrawInventoryScreen_6FADEAC0; // 3EAC0           | 6FADEAC0
extern D2Client_UI_DrawPlayerTradeButtonHoverText_6FB1F390_t D2Client_UI_DrawPlayerTradeButtonHoverText_6FB1F390; // 7F390 | 6FB1F390
extern D2Client_UI_DrawProgressiveStates_6FB21A00_t D2Client_UI_DrawProgressiveStates_6FB21A00; // 81A00       | 6FB21A00
extern D2Client_UI_DrawSkillsTree_6FB16C00_t D2Client_UI_DrawSkillsTree_6FB16C00; // 76C00                     | 6FB16C00
extern D2Client_UI_DrawCharacterStatsScreen_6FACFD60_t D2Client_UI_DrawCharacterStatsScreen_6FACFD60; // 2FD60 | 6FACFD60
extern D2Client_UI_DrawPartyScreen_6FB01F10_t D2Client_UI_DrawPartyScreen_6FB01F10; // 61F10                   | 6FB01F10
extern D2Client_UI_DrawDialog_6FAD6EB0_t D2Client_UI_DrawDialog_6FAD6EB0; // 36EB0     | 6FAD6EB0
extern D2Client_UI_DrawInifussScrollPanel_6FB1E990_t D2Client_UI_DrawInifussScrollPanel_6FB1E990; // 7E990     | 6FB1E990
extern D2Client_UI_DrawWaypointScreen_6FB25C70_t D2Client_UI_DrawWaypointScreen_6FB25C70; // 85C70             | 6FB25C70
extern D2Client_UI_DrawHelpScreenBorder_6FAD81F0_t D2Client_UI_DrawHelpScreenBorder_6FAD81F0; // 381F0                     | 6FAD81F0
extern D2Client_UI_DrawHelpScreenBackground_6FAD82E0_t D2Client_UI_DrawHelpScreenBackground_6FAD82E0; // 382E0 | 6FAD82E0
extern D2Client_UI_DrawBackground_6FAFF480_t D2Client_UI_DrawBackground_6FAFF480; // 5F480                     | 6FAFF480
extern D2Client_UI_DrawMiniSkills_6FB19660_t D2Client_UI_DrawMiniSkills_6FB19660; // 79660                     | 6FB19660
extern D2Client_UI_DrawBeltRows_6FB01C20_t D2Client_UI_DrawBeltRows_6FB01C20; // 61C20                         | 6FB01C20
extern D2Client_UI_RefreshUIState_6FAEEC00_t D2Client_UI_RefreshUIState_6FAEEC00; // 4EC00                     | 6FAEEC00
extern D2Client_UI_DrawHelpButton_6FADA350_t D2Client_UI_DrawHelpButton_6FADA350; // 3A350                     | 6FADA350
extern D2Client_UI_DrawNewStatsButton_6FAEF360_t D2Client_UI_DrawNewStatsButton_6FAEF360; // 4F360             | 6FAEF360
extern D2Client_UI_DrawStatsButton_6FAEF2A0_t D2Client_UI_DrawStatsButton_6FAEF2A0; // 4F2A0                   | 6FAEF2A0
extern D2Client_UI_DrawNewSkillsButton_6FAEF730_t D2Client_UI_DrawNewSkillsButton_6FAEF730; // 4F730           | 6FAEF730
extern D2Client_UI_DrawSkillsButton_6FAEF670_t D2Client_UI_DrawSkillsButton_6FAEF670; // 4F670                 | 6FAEF670
extern D2Client_UI_DrawQuestLogButton_6FB065F0_t D2Client_UI_DrawQuestLogButton_6FB065F0; // 665F0             | 6FB065F0
extern D2Client_UI_DrawLifeAndManaOrbText_6FAFF0B0_t D2Client_UI_DrawLifeAndManaOrbText_6FAFF0B0; // 5F0B0     | 6FAFF0B0
extern D2Client_UI_DrawMiniPanel_6FB08DE0_t D2Client_UI_DrawMiniPanel_6FB08DE0; // 68DE0                       | 6FB08DE0
extern D2Client_UI_DrawChatBox_6FAD2100_t D2Client_UI_DrawChatBox_6FAD2100; // 32100                           | 6FAD2100
extern D2Client_ClearItemUnderCursorInfo_6FAE8F10_t D2Client_ClearItemUnderCursorInfo_6FAE8F10; // 48F10       | 6FAE8F10
extern D2Client_UI_DrawHelpScreen_6FAD8310_t D2Client_UI_DrawHelpScreen_6FAD8310; // 38310                     | 6FAD8310
extern D2Client_GetGameType_6FAABFF0_t D2Client_GetGameType_6FAABFF0; // BFF0                                  | 6FAABFF0
extern D2Client_UI_DrawNpcMenu_6FAF6070_t D2Client_UI_DrawNpcMenu_6FAF6070; // 56070                           | 6FAF6070
extern D2Client_UI_DrawAnvilScreen_6FB25320_t D2Client_UI_DrawAnvilScreen_6FB25320; // 85320                   | 6FB25320
extern D2Client_UI_DrawHostilePlayerIndicator_6FAFE650_t D2Client_UI_DrawHostilePlayerIndicator_6FAFE650; // 5E650 | 6FAFE650
extern D2Client_UI_DrawMercFloatingText_6FB21970_t D2Client_UI_DrawMercFloatingText_6FB21970; // 81970         | 6FB21970
extern D2Client_Roster_IsSortingByKillCount_6FAA6990_t D2Client_Roster_IsSortingByKillCount_6FAA6990; // 6990 | 6FAA6990
extern D2Client_UI_DrawDeathScreen_6FB22320_t D2Client_UI_DrawDeathScreen_6FB22320; // 82320                   | 6FB22320
extern D2Client_UI_DrawLordOfTerrorDiedMessage_6FABA4A0_t D2Client_UI_DrawLordOfTerrorDiedMessage_6FABA4A0; // 1A4A0 | 6FABA4A0
extern D2Client_UI_UpdateMercFloatingText_6FB20590_t D2Client_UI_UpdateMercFloatingText_6FB20590; // 80590     | 6FB20590
extern D2Client_UI_UpdateRosterHealthColors_6FADA970_t D2Client_UI_UpdateRosterHealthColors_6FADA970; // 3A970 | 6FADA970
extern D2Client_Archive_FreeCellFile_6FAA1140_t D2Client_Archive_FreeCellFile_6FAA1140; // 1140                | 6FAA1140
extern D2Client_UI_SetUIState_6FB23260_t D2Client_UI_SetUIState_6FB23260; // 83260                             | 6FB23260
extern D2Client_Unit_EnumUnits_6FB29700_t D2Client_Unit_EnumUnits_6FB29700; // 89700                           | 6FB29700
extern D2Client_UI_EnumUnitsCallback_6FB22560_t D2Client_UI_EnumUnitsCallback_6FB22560; // 82560               | 6FB22560
extern D2Client_UI_DrawNPCScrollingDialog_6FB1BA00_t D2Client_UI_DrawNPCScrollingDialog_6FB1BA00; // 7BA00     | 6FB1BA00
extern D2Client_UI_DrawText_6FB22280_t D2Client_UI_DrawText_6FB22280; // 82280                                 | 6FB22280
extern D2Client_Roster_FindUnitByIdOrCorpseId_6FAAFD60_t D2Client_Roster_FindUnitByIdOrCorpseId_6FAAFD60; // FD60 | 6FAAFD60
extern D2Client_Roster_GetKillCount_6FAAFD30_t D2Client_Roster_GetKillCount_6FAAFD30; // FD30                  | 6FAAFD30
extern D2Client_LoadCelFile_6FAA1000_t D2Client_LoadCelFile_6FAA1000; // 1000                  | 6FAA1000

// Character Stats Screen - Data structures
struct D2CharSheetButtonLocations;
struct D2CharSheetStatRow;
struct D2CharSheetTextEntry;
struct D2CharSheetToHitTextLocation;

// Character Stats Screen - Function types

typedef char* (__fastcall* D2Client_Roster_GetUnitNameFromD2UnitStrc_6FAB0C00_t)(D2UnitStrc* pUnit); // 68608
typedef D2CellFileStrc* (__cdecl* D2Client_UI_GetBuySellBtnCellFile_6FB24110_t)(); // 540944
typedef int(__fastcall* D2Client_UI_GetPassiveWeaponBlock_6FAD1010_t)(D2UnitStrc* pUnit); // 200720
typedef int(__fastcall* D2Client_Unit_GetLastSelectedMonsterClassId_6FAB5A70_t)(); // 88688
typedef void (*D2Client_UI_SetUnknownColorToBlack_6FB01C50_t)(); // 400464
typedef int (*D2Client_GetGameTypeButModified_6FAAC060_t)(); // 49248
typedef int(__fastcall* D2Client_Unit_GetLastSelectedEvilMonsterClassId_6FAB5A80_t)(); // 88704
typedef int(__fastcall* D2Client_GetSkillDescAtt_6FB16200_t)(D2UnitStrc* pUnit, int bIsLeftSkill); // 483840
typedef int(__fastcall* D2Client_UI_GetChanceToHitMonster_6FAD10D0_t)(int baseToHit); // 200912
typedef void(__fastcall* D2Client_UI_DrawLeftRightSkillDescs_6FB16190_t)(D2UnitStrc* pUnit); // 483728

extern D2Client_Roster_GetUnitNameFromD2UnitStrc_6FAB0C00_t D2Client_Roster_GetUnitNameFromD2UnitStrc_6FAB0C00; // 10C00| 6FAB0C00
extern D2Client_UI_GetBuySellBtnCellFile_6FB24110_t D2Client_UI_GetBuySellBtnCellFile_6FB24110; // 84110| 6FB24110
extern D2Client_UI_GetPassiveWeaponBlock_6FAD1010_t D2Client_UI_GetPassiveWeaponBlock_6FAD1010; // 31010| 6FAD1010
extern D2Client_Unit_GetLastSelectedMonsterClassId_6FAB5A70_t D2Client_Unit_GetLastSelectedMonsterClassId_6FAB5A70; // 15A70| 6FAB5A70
extern D2Client_UI_SetUnknownColorToBlack_6FB01C50_t D2Client_UI_SetUnknownColorToBlack_6FB01C50; // 61C50| 6FB01C50
extern D2Client_GetGameTypeButModified_6FAAC060_t D2Client_GetGameTypeButModified_6FAAC060; // C060| 6FAAC060
extern D2Client_Unit_GetLastSelectedEvilMonsterClassId_6FAB5A80_t D2Client_Unit_GetLastSelectedEvilMonsterClassId_6FAB5A80; // 15A80| 6FAB5A80
extern D2Client_GetSkillDescAtt_6FB16200_t D2Client_GetSkillDescAtt_6FB16200; // 76200| 6FB16200
extern D2Client_UI_GetChanceToHitMonster_6FAD10D0_t D2Client_UI_GetChanceToHitMonster_6FAD10D0; // 310D0| 6FAD10D0
extern D2Client_UI_DrawLeftRightSkillDescs_6FB16190_t D2Client_UI_DrawLeftRightSkillDescs_6FB16190; // 76190| 6FB16190

extern int32_t* D2Client_UI_pUnknownColor2_6FBB1A50; // 111A50 | 6FBB1A50
extern int32_t* D2Client_UI_pUnknownFlag_6FBB1A4C; // 111A4C | 6FBB1A4C
extern D2CharSheetStatRow** D2Client_UI_pD2CharSheetStatRows_6FB78120; // D8120 | 6FB78120
extern D2CharSheetTextEntry** D2Client_UI_pCharSheetTextEntries_6FB78010; // D8010 | 6FB78010
extern D2CharSheetButtonLocations** D2Client_UI_pD2CharSheetButtonLocations_6FB78240; // D8240 | 6FB78240
extern D2CellFileStrc** D2Client_UI_pCelFile_PanelSkillPoints_6FBB5E50; // 115E50 | 6FBB5E50
extern D2CellFileStrc** D2Client_UI_pCelFile_UiInvChar_6FBB5E24; // 115E24 | 6FBB5E24
extern D2CellFileStrc** D2Client_UI_pCelFilePanelLevelSocket_6FBB5BB8; // 115BB8 | 6FBB5BB8
extern D2CellFileStrc** D2Client_UI_pCelFilePanelLevel_6FBB5BB4; // 115BB4 | 6FBB5BB4
extern D2CharSheetToHitTextLocation** D2Client_UI_pCharSheetToHitTextLocation_6FB6EF00; // CEF00 | 6FB6EF00
