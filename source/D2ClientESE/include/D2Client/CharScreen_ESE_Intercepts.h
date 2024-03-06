#pragma once

#include <D2Client/CharScreen_ESE.h>
#include <../D2MooHeaders.h>
#include <cstdlib>

typedef void(__fastcall* CHARSCREEN_DrawDescDam1_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam2_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam3_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam4_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam5_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam6_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam7_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam8_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam9_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam10_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam11_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam12_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam13_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam14_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam15_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam16_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam17_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam18_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam19_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam20_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam21_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam22_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam23_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void(__fastcall* CHARSCREEN_DrawDescDam24_t)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

extern CHARSCREEN_DrawDescDam1_t CHARSCREEN_DrawDescDam1_Original;
extern CHARSCREEN_DrawDescDam2_t CHARSCREEN_DrawDescDam2_Original;
extern CHARSCREEN_DrawDescDam3_t CHARSCREEN_DrawDescDam3_Original;
extern CHARSCREEN_DrawDescDam4_t CHARSCREEN_DrawDescDam4_Original;
extern CHARSCREEN_DrawDescDam5_t CHARSCREEN_DrawDescDam5_Original;
extern CHARSCREEN_DrawDescDam6_t CHARSCREEN_DrawDescDam6_Original;
extern CHARSCREEN_DrawDescDam7_t CHARSCREEN_DrawDescDam7_Original;
extern CHARSCREEN_DrawDescDam8_t CHARSCREEN_DrawDescDam8_Original;
extern CHARSCREEN_DrawDescDam9_t CHARSCREEN_DrawDescDam9_Original;
extern CHARSCREEN_DrawDescDam10_t CHARSCREEN_DrawDescDam10_Original;
extern CHARSCREEN_DrawDescDam11_t CHARSCREEN_DrawDescDam11_Original;
extern CHARSCREEN_DrawDescDam12_t CHARSCREEN_DrawDescDam12_Original;
extern CHARSCREEN_DrawDescDam13_t CHARSCREEN_DrawDescDam13_Original;
extern CHARSCREEN_DrawDescDam14_t CHARSCREEN_DrawDescDam14_Original;
extern CHARSCREEN_DrawDescDam15_t CHARSCREEN_DrawDescDam15_Original;
extern CHARSCREEN_DrawDescDam16_t CHARSCREEN_DrawDescDam16_Original;
extern CHARSCREEN_DrawDescDam17_t CHARSCREEN_DrawDescDam17_Original;
extern CHARSCREEN_DrawDescDam18_t CHARSCREEN_DrawDescDam18_Original;
extern CHARSCREEN_DrawDescDam19_t CHARSCREEN_DrawDescDam19_Original;
extern CHARSCREEN_DrawDescDam20_t CHARSCREEN_DrawDescDam20_Original;
extern CHARSCREEN_DrawDescDam21_t CHARSCREEN_DrawDescDam21_Original;
extern CHARSCREEN_DrawDescDam22_t CHARSCREEN_DrawDescDam22_Original;
extern CHARSCREEN_DrawDescDam23_t CHARSCREEN_DrawDescDam23_Original;
extern CHARSCREEN_DrawDescDam24_t CHARSCREEN_DrawDescDam24_Original;

//D2Client.0x6FB0C270 (6C270)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam1(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0CD40 (6CD40)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam2(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0D330 (6D330)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam3(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0D920 (6D920)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam4(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0DEC0 (6DEC0)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam5(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0ACE0 (6ACE0)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam6(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0BEC0 (6BEC0)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam7(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0E800 (6E800)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam8(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0EAB0 (6EAB0)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam9(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0ED40 (6ED40)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam10(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0F080 (6F080)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam11(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0F700 (6F700)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam12(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0E7B0 (6E7B0)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam13(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0FA50 (6FA50)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam14(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0FC60 (6FC60)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam15(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB10010 (70010)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam16(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB10540 (70540)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam17(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB108F0 (708F0)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam18(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0CA60 (6CA60)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam19(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0C930 (6C930)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam20(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0CE90 (6CE90)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam21(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0DAB0 (6DAB0)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam22(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0E440 (6E440)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam23(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0E180 (6E180)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawDescDam24(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);









//D2Client.0x6FB0B140 (6B140)
// struct Unicode *__fastcall PrintRangeString(struct Unicode *pText, int minDamage, int maxDamage, int isAdditonRange, int allowThousandsSuffix)

//D2Client.0x6FACFCD0 (2FCD0)
// void __fastcall DrawTextCentered(int nX, int nY, int maxWidthMaybe, const Unicode *text, int nColor)

